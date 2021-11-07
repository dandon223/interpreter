

#ifndef TKOM_21Z_DANIEL_LEXER_H
#define TKOM_21Z_DANIEL_LEXER_H


#include <iosfwd>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../token/Token.h"
class Lexer {
private:
    int line = 1;
    int column = 0;
    std::streampos current_line_start= {};
    std::streampos last_pos_after_good_token = {};
    std::istream &handle;
    char current_char;
    std::string parsed_token;
    Token active_token;

    char peekNextChar();
    bool getIndentation();
public:
    Lexer(std::istream &my_handle);
    Token getNextToken();
    void getNextChar();
    bool endOfFile();
    void printStream();
};


#endif //TKOM_21Z_DANIEL_LEXER_H