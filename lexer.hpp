#pragma once

#include <array>
#include <string>
#include <string_view>
#include <iostream>

#include "tokens.hpp"

namespace lexer {
  enum class States {
    START,
    CONSUME_CHAR,
    DONE,
    CHECK_STR,
    CHECK_NEXT, // TODO
    BUFFER_ADD,
    STR_RISING_EDGE,
    STR_FALLING_EDGE,

    START_TOKEN_FROM_BUFFER,
    FINISH_TOKEN_FROM_BUFFER,
  };

	std::string stateToString(States state);

  class Engine {
    private:
      States curr_state_;
      types::Tokens production_type_;
      size_t char_idx_ = 0;
      size_t buffer_idx_ = 0;
      char c_;

      /* nice default inits that should be done explicitly in verilog */
      bool ident_flag_  = false;
      bool num_flag_    = false;
      bool str_flag_    = false;

      char char_stream_[1000];
      char buffer_[100];

    public:
      void run();
      void tick();
      Engine(std::string_view contents)
        : curr_state_(States::START)
      {
        std::strncpy(
          char_stream_,
          std::string(contents).c_str(), 
          std::min(static_cast<int>(contents.size()), 1000)
        );
      }
  };
};
