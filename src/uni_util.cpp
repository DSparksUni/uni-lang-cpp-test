#include "uni_util.hpp"

namespace uni {
    Pos::Pos() noexcept: line(0), col(0), serial(0) {}
    Pos::Pos(size_t l, size_t c, size_t s) noexcept: line(l), col(c), serial(s) {}

    std::string read_file(const char* file_path) noexcept {
        if(!std::filesystem::exists(file_path)) {
            error_flag = UNI_INTERNAL_ERROR;
            error_msg = "File '" + std::string(file_path) + "' not found";
            return "";
        }

        std::ifstream file_stream(file_path);
        if(!file_stream.is_open()) {
            error_flag = UNI_INTERNAL_ERROR;
            error_msg = "Failed to open file '" + std::string(file_path) + '\'';
            return "";
        }

        std::ostringstream out_stream;
        out_stream << file_stream.rdbuf();

        file_stream.close();
        error_flag = UNI_SUCCESS;
        return out_stream.str();
    }
}
