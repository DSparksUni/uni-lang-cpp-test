#include "uni_lexer.hpp"

namespace uni {
    Token::Token() noexcept: type(TOKEN_NULL) {}
    Token::Token(TokenType t, Pos p) noexcept: type(t), pos(p) {}
    Token::Token(TokenType t, Pos p, const std::string& s) noexcept: type(t), pos(p), strval(s) {}
    Token::Token(TokenType t, Pos p, int i) noexcept: type(t), pos(p), intval(i) {}

    void Token::print() const noexcept {
        const char* type_str = TokenType_toString[type];

        std::cout << "Token{type='" << type_str << '\'';
        if(type == TOKEN_WORD) std::cout << ", value='" << strval << '\'';
        else if(type == TOKEN_STR) std::cout << ", value=" << strval << '\"';
        else if(type == TOKEN_INT) std::cout << ", value=" << intval;

        std::cout << ", pos=(" << pos.line+1 << ", " << pos.col+1 << ", " << pos.serial << ")}\n";
    }

    [[nodiscard]] Token get_token(FileIterator* fiter) noexcept {
        Token token(TOKEN_NULL, fiter->pos());

        while(isspace(fiter->getchar())) fiter->advance();

        if(isalpha(fiter->getchar())) {
            token.strval = fiter->getchar();
            fiter->advance();
            while(isalnum(fiter->getchar())) {
                token.strval += fiter->getchar();
                fiter->advance();
            }

            if(token.strval == "puts") token.type = TOKEN_PUTS;
            else if(token.strval == "puti") token.type = TOKEN_PUTI;
            else token.type = TOKEN_WORD;
        } else if(fiter->getchar() == '+') token.type = TOKEN_ADD;
        else if(fiter->getchar() == '-') token.type = TOKEN_SUB;
        else if(fiter->getchar() == '*') token.type = TOKEN_MULT;
        else if(fiter->getchar() == '/') token.type = TOKEN_DIV;
        else if(isdigit(fiter->getchar())) {
            std::string num_str;
            do {
                num_str += fiter->getchar();
                fiter->advance();
            } while(isdigit(fiter->getchar()));

            token.intval = std::stoi(num_str.c_str(), 0);
            token.type = TOKEN_INT;
        } else if(fiter->getchar() == '\"') {
            do {
                token.strval += fiter->getchar();
                fiter->advance();
            } while(fiter->getchar() != '\"');

            token.type = TOKEN_STR;
        } else if(fiter->getchar() == EOF)
            token.type = TOKEN_EOF;

        return token;
    }
}
