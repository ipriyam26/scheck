#ifndef INC_PARSER_H
#define INC_ERROR_H

#include <iostream>
#include <sstream>
#include <string>

class Parser {

  public:
    Parser(std::istream &stream);
    std::string NextWord();
    unsigned int LineNo() const;
    std::string Context() const;

  private:
    bool ReadLine();
    char NextChar();
    enum State{stInSpace,stInWord,stInNum};
    State mState;
    std::istream &mSubmission;
    std::string mLine;
    unsigned int mLineNo,mPos;

};

#endif