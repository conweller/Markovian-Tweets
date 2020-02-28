#include "markov.h"

void markov::sequences::insert(std::vector<std::string> curwords,
    std::string nextword)
{
  std::string curword0, curword1;
  curword0 = curwords[0];
  curword1 = curwords[1];
  std::string key = curword0 + " " + curword1;
  this->table[key].push_back(nextword);
}

std::string markov::sequences::nextword(std::vector<std::string> curwords)
{
  std::string curword0, curword1;
  curword0 = curwords[0];
  curword1 = curwords[1];
  std::string key = curword0 + " " + curword1;
  std::string ret;
  if (this->table[key].empty()) {
    ret = this->randkey()[0];
  } else {
    int rand_idx = rand() % this->table[key].size();
    ret = this->table[key][rand_idx];
  }
  return ret.empty() ? "" : ret + " ";
}

std::vector<std::string> markov::sequences::randkey()
{
  int rand_idx = rand() % this->table.size();
  auto random_it =  std::next(std::begin(this->table), rand_idx);
  std::string key = random_it->first;
  int delim_loc = key.find(" ");
  std::vector<std::string> ret;
  ret.push_back(key.substr(0, delim_loc));
  ret.push_back(key.substr(delim_loc, std::string::npos));
  return ret;
}
