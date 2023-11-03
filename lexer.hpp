#pragma once

#include <array>
#include <string>
#include <string_view>
#include <iostream>

namespace lexer {
  enum class States {
    START,
    DONE,
  };

	std::string stateToString(States state);

  class Engine {
    private:
      States curr_state_;
      size_t char_idx_ = 0;

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
