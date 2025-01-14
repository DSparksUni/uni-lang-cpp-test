#pragma once

#include <iostream>

#include "uni_error.hpp"
#include "uni_util.hpp"
#include "uni_iter.hpp"

namespace uni {
    enum TokenType {
        TOKEN_NULL,
        TOKEN_EOF,

        // Commands
        TOKEN_PUTS,
        TOKEN_PUTI,
        TOKEN_ADD,
        TOKEN_SUB,
        TOKEN_MULT,
        TOKEN_DIV,

        // Primary
        TOKEN_WORD,
        TOKEN_STR,
        TOKEN_INT
    };
    static const char* TokenType_toString[] = {
        "NULL", "EOF",
        "PUTS", "PUTI", "ADD", "SUB", "MULT", "DIV",
        "WORD", "STR", "INT"
    };

    struct Token {
        TokenType type;
        Pos pos;
        std::string strval;
        int intval;

        Token() noexcept;
        Token(TokenType, Pos) noexcept;
        Token(TokenType, Pos, const std::string&) noexcept;
        Token(TokenType, Pos, int) noexcept;

        void print() const noexcept;
    };

    [[nodiscard]] Token get_token(FileIterator*) noexcept;
}
