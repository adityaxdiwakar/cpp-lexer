#pragma once

#include <stddef.h>
#include <algorithm>

namespace types {

enum class Tokens {
  INT_WORD,
  FLOAT_WORD,
  INT,
  FLOAT,
  STR,
  IDENT,
  WHILE,
  NEQ,
  MINEQ,
  PLUSEQ,
  LBRACK,
  RBRACK,
  LPAREN,
  RPAREN,
  RETURN,
  SEMI,
  IF,
  PLUS,
  SUB,
  MINUS,
  MULT,
  DIV,
  EQUALS,
  NOT,
  COMMA,
  GT,
  LT,
  DIRECTIVE,
  ANDREF
};

class Token {
  private:
    Tokens token_;
    size_t param_len_;
    char param_[100];

  public:
    Token(Tokens token, size_t param_len, char* param)
      : token_{token}
      , param_len_{param_len}
    {
      std::strncpy(
        param_, 
        param, 
        std::min(static_cast<int>(param_len), 100));
    }
};

} // namespace types
