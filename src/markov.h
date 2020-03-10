#include <unordered_map>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <sstream>
#include <iterator>
#include <cassert>

namespace markov {
  class sequences;
}

class markov::sequences {
  public:
    void insert(std::vector<std::string>, std::string);
    std::string nextword(std::vector<std::string>);
    std::vector<std::string> randkey(void);
    sequences(int);
  private:
    std::unordered_map<std::string, std::vector<std::string> > table;
    int key_size;
};
