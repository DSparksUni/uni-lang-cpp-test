#pragma once

#include <cwchar>
#include <iostream>

#include "uni_error.hpp"
#include "uni_util.hpp"

namespace uni {
    class FileIterator {
    private:
        std::string content;
        Pos m_pos;
        char c;
        bool m_done;

    public:
        FileIterator(const std::string&) noexcept;

        [[nodiscard]] char getchar() const noexcept;
        [[nodiscard]] bool done() const noexcept;
        [[nodiscard]] size_t line() const noexcept;
        [[nodiscard]] size_t col() const noexcept;
        [[nodiscard]] size_t serial() const noexcept;
        [[nodiscard]] Pos pos() const noexcept;

        void advance() noexcept;
    };
}
