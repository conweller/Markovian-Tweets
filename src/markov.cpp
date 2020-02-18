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
    this->dict[key] = std::vector<std::string>();
    this->dict[key].push_back(nextword);
    this->seen.push_back(key);
  }
}

std::string sequences::nextword(std::string curword0,
    std::string curword1)
{
  std::string key = curword0 + " " + curword1;
  if (this->dict[key].empty()) {
    return this->randkey()[0];
  } else {
    int rand_idx = rand() % this->dict[key].size();
    std::cout << this->dict[key].size() << std::endl;
    return this->dict[key][rand_idx];
  }
}

std::vector<std::string> sequences::randkey()
{
  int rand_idx = rand() % this->seen.size();
  std::string key = this->seen[rand_idx];
  int delim_loc = key.find(" ");
  std::vector<std::string> ret;
  ret.push_back(key.substr(0, delim_loc));
  ret.push_back(key.substr(delim_loc, std::string::npos));
  return ret;
}