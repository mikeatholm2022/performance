// Main function for performance_test
//
// Copyright HOLM, 2023

#include "logger.h"
#include "utils.h"

#include "application_details.h"
#include "logger_performance_test.h"

#include <fstream>

// =============================================================================================
int main()
{
    chaos::ApplicationDetails::instance()->set_details("performace_test", "Testing", "TEST", 0, 0);
    if (!chaos::ApplicationDetails::instance()->is_configuration_okay())
    {
        // We are missing configuration details
        std::cerr << "ERROR - We are missing configuration details, please investigate" << std::endl;
        LOG(PUB_MSG, "We are missing configuration details");
        return -1;
    }

    chaos::set_thread_name("Main");
    LOG(PUB_MSG, "PerformanceTest is starting");

    std::stringstream ss;
    ss << "Main Thread = " << boost::this_thread::get_id();
    LOG(PUB_MSG, ss.str().c_str());

    // Add all of the tests here ...............................................................
    chaos::performance_tests::logger_performance_debug_test(100000);
    chaos::performance_tests::logger_performance_public_test(100000);







    // .........................................................................................

    LOG(PUB_MSG, "Application is shutting down");

    // Clean-up time
    sleep(10);
    chaos::Logger::instance()->stop();
    chaos::Logger::instance()->join();

    return 0;
}

// =============================================================================================
