#include <iostream>
#include "lexer.hpp"

using namespace std;

namespace lexer {
  std::string stateToString(States state) {
    switch (state) {
      case States::START:
        return "START";
      case States::DONE:
        return "DONE";
      default:
        return "UNKNOWN";
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
        curr_state_ = States::DONE;
        break;
      }
      case States::DONE: {
        break;
      }
    }
  }
};
