#include <iostream>

#include "uni_error.hpp"
#include "uni_util.hpp"
#include "uni_iter.hpp"
#include "uni_lexer.hpp"

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cerr << "[ERROR] No input file supplied...\n";
        return -1;
    }

    const std::string input_content = uni::read_file(argv[1]);
    if(uni::error_flag != uni::UNI_SUCCESS) {
        std::cerr << "[ERROR] " << uni::error_msg << "...\n";
        return -1;
    }

    uni::FileIterator input_iter(input_content);
    while(!input_iter.done()) {
        uni::Token token = uni::get_token(&input_iter);
        token.print();
        input_iter.advance();
    }

    return 0;
}
