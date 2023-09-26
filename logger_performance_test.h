// Simple performance test to see how many message our logger can process
//
// Copyright HOLM, 2023

#pragma once

// ========================================================================================

#include "logger.h"
#include "time_utils.h"

#include <string>

namespace chaos
{
    namespace performance_tests
    {
        // ====================================================================================
        void logger_performance_debug_test(int iterations = 1000000)
        {
            std::string start = chaos::time_as_string("%H:%M:%S.%f");
            for(int i=0; i<iterations; ++i)
            {
                LOG( DEB_MSG, "Blah" );
            }
            std::string stop = chaos::time_as_string("%H:%M:%S.%f");
            std::stringstream ss;
            ss << "DEBUG Performance Test, Start: " << start << ", Stop: " << stop;
            LOG( PUB_MSG, ss.str() );
        }

        // ====================================================================================
        void logger_performance_public_test(int iterations = 1000000)
        {
            std::string start = chaos::time_as_string("%H:%M:%S.%f");
            for(int i=0; i<iterations; ++i)
            {
                LOG( PUB_MSG, "Blah" );
            }
            std::string stop = chaos::time_as_string("%H:%M:%S.%f");
            std::stringstream ss;
            ss << "PUBLIC Performance Test, Start: " << start << ", Stop: " << stop;
            LOG( PUB_MSG, ss.str() );
        }
    }

} // End of namespace
