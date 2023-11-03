#include <iostream>
#include <fstream>

#include "lexer.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Please enter a file to lex" << endl;
    return -1;
  }

  std::ifstream infile(argv[1]);
  if (!infile) {
    std::cerr << "Error: Could not open file." << endl;
    return 1;
  }

  std::string contents(
      (std::istreambuf_iterator<char>(infile)),
      std::istreambuf_iterator<char>());
  infile.close();

  auto lexer_engine = lexer::Engine(contents.c_str());
  lexer_engine.run();
}
