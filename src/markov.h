#include <unordered_map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

namespace markov {
  class sequences;
}

class markov::sequences {
  public:
    void insert(std::string, std::string, std::string);
    std::string nextword(std::string, std::string);
    std::vector<std::string> randkey(void);
  private:
    std::vector<std::string> seen;
    std::unordered_map<std::string, std::vector<std::string> > dict;
};
