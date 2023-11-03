#include <array>
#include <string_view>

namespace lexer {
  enum class States {
    START,
    DONE,
  };

  class Engine {
    private:
      States curr_state_;
      std::string_view input_;

    public:
      void run();
      void tick();
      Engine(std::string_view contents)
        : curr_state_(States::START)
        , input_(contents)
      {}
  };
};
