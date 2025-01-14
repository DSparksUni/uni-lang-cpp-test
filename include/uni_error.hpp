#pragma once

#include <iostream>

namespace uni {
    enum ErrorCode {
        UNI_SUCCESS,
        UNI_INTERNAL_ERROR,
        UNI_RUNTIME_ERROR
    };

    extern ErrorCode error_flag;
    extern std::string error_msg;
}
