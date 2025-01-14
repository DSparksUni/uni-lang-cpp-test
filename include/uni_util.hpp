#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "uni_error.hpp"

namespace uni {
    struct Pos {
        size_t line, col, serial;

        Pos() noexcept;
        Pos(size_t, size_t, size_t) noexcept;
    };

    std::string read_file(const char*) noexcept;
}
