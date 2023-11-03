#include <iostream>
#include "lexer.hpp"

using namespace std;

namespace lexer {
	std::string stateToString(States state) {
		switch (state) {
			case States::START:
				return "START";
			case States::CONSUME_CHAR:
				return "CONSUME_CHAR";
			case States::DONE:
				return "DONE";
			case States::CHECK_STR:
				return "CHECK_STR";
			case States::CHECK_NEXT:
				return "CHECK_NEXT"; // Placeholder for TODO
			case States::BUFFER_ADD:
				return "BUFFER_ADD";
			case States::STR_RISING_EDGE:
				return "STR_RISING_EDGE";
			case States::STR_FALLING_EDGE:
				return "STR_FALLING_EDGE";
			case States::START_TOKEN_FROM_BUFFER:
				return "START_TOKEN_FROM_BUFFER";
			case States::FINISH_TOKEN_FROM_BUFFER:
				return "FINISH_TOKEN_FROM_BUFFER";
			default:
				return "UNKNOWN_STATE";
		}
	}

  void Engine::run() {
    while (curr_state_ != States::DONE) {
      cout << stateToString(curr_state_) << endl;
      this->tick();
    }
  }

  void Engine::tick() {
    switch (curr_state_) {
      case States::START: {
        curr_state_ = States::CONSUME_CHAR;
        break;
      }
      case States::CONSUME_CHAR: {
        if (char_idx_ > 100) { // TODO: expand this state
          curr_state_ = States::DONE;
        }
        else {
          this->c_ = char_stream_[char_idx_];
          char_idx_++;
          curr_state_ = States::CHECK_STR;
        }
        break;
      }
      case States::CHECK_STR: {
        if (c_ == '"' && str_flag_) curr_state_ = States::STR_FALLING_EDGE;
        if (c_ == '"' && !str_flag_) curr_state_ = States::STR_RISING_EDGE;
        if (c_ != '"' && str_flag_) curr_state_ = States::BUFFER_ADD;
        if (c_ != '"' && !str_flag_) curr_state_ = States::CHECK_NEXT;
        break;
      }
      case States::STR_RISING_EDGE: {
        str_flag_ = true;
        curr_state_ = States::CHECK_NEXT;
        break;
      }
      case States::STR_FALLING_EDGE: {
        str_flag_ = false;
        production_type_ = types::Tokens::STR;
        curr_state_ = States::START_TOKEN_FROM_BUFFER;
        // produce token with buffer
        break;
      }
      case States::BUFFER_ADD: {
        buffer_[buffer_idx_] = c_;
        buffer_idx_++;
        curr_state_ = States::CONSUME_CHAR;
        break;
      }
      case States::CHECK_NEXT: {
        curr_state_ = States::CONSUME_CHAR;
        break;
      }
      case States::START_TOKEN_FROM_BUFFER: { // TODO
        for (size_t i = 0; i < buffer_idx_; i++) {
          std::cout << buffer_[i];
        }
        std::cout << std::endl;
        buffer_idx_ = 0;
        curr_state_ = States::CONSUME_CHAR;
        break;
      }
      case States::DONE: {
        break;
      }
    }
  }
};
