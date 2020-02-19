#include <unordered_map>
#include <string>
#include <vector>
#include <random>

namespace markov {
  class sequences;
}

class markov::sequences {
  public:
    void insert(std::string, std::string, std::string);
    std::string nextword(std::string, std::string);
    std::vector<std::string> randkey(void);
  private:
    std::unordered_map<std::string, std::vector<std::string> > table;
};
