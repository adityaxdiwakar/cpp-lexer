#include <iostream>
#include "lexer.hpp"

using namespace std;

namespace lexer {
  void Engine::run() {
    while (curr_state_ != States::DONE) {
      this->tick();
    }
  }

  void Engine::tick() {
    switch (curr_state_) {
      case States::START: {
        break;
      }
      case States::DONE: {
        break;
      }
    }
  }
};
