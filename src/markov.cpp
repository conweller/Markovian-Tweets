#include "markov.h"
#include <iostream>

using namespace markov;

void sequences::insert(std::string curword0,
    std::string curword1,
    std::string nextword)
{
  std::string key = curword0 + " " + curword1;
  if (this->dict.count(key)) {
    this->dict[key].push_back(nextword);
  } else {
    this->dict[key] = {nextword};
    this->seen.push_back(key);
  }
}

std::string sequences::nextword(std::string curword0,
    std::string curword1)
{
  std::string key = curword0 + " " + curword1;
  if (this->dict[key].empty()) {
    return std::get<0>(this->randkey());
  } else {
    std::srand(time(0));
    int rand_idx = rand() % this->dict[key].size();
    return this->dict[key][rand_idx];
  }
}

std::tuple<std::string, std::string> sequences::randkey()
{
  std::srand(time(0));
  int rand_idx = rand() % this->seen.size();
  std::string key = this->seen[rand_idx];
  int delim_loc = key.find(" ");
  std::string k1 = key.substr(0, delim_loc);
  std::string k2 = key.substr(delim_loc, std::string::npos);
  return std::make_tuple(k1, k2);
}


int main(void)
{
  markov::sequences seq;
  seq.insert("a", "oof", "a");
  seq.insert("a", "oof", "a");
  return 0;
}
