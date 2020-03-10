#include "markov.h"

std::string words2key(std::vector<std::string> words)
{
  int i, size;
  std::string ret;
  size = words.size();
  assert(size > 0);
  ret = words[0];
  for (i = 1; i < size; ++i) {
    ret += " " + words[i];
  }
  return ret;
}

std::vector<std::string> key2words(std::string key)
{
  std::istringstream iss(key);
  std::istream_iterator<std::string> first(iss), last;
  std::vector<std::string> parts;
  std::copy(first, last, std::back_inserter(parts));
  return parts;
}

markov::sequences::sequences(int key_size)
{
  this->key_size = key_size;
}

void markov::sequences::insert(std::vector<std::string> curwords,
    std::string nextword)
{
  assert(curwords.size() == this->key_size);
  std::string key = words2key(curwords);
  this->table[key].push_back(nextword);
}

std::string markov::sequences::nextword(std::vector<std::string> curwords)
{
  std::string key = words2key(curwords);
  std::string ret;
  if (this->table[key].empty()) {
    return this->randkey()[0];
  } else {
    int rand_idx = rand() % this->table[key].size();
    return this->table[key][rand_idx];
  }
  
}

std::vector<std::string> markov::sequences::randkey()
{
  int rand_idx = rand() % this->table.size();
  auto random_it =  std::next(std::begin(this->table), rand_idx);
  std::string key = random_it->first;
  std::vector<std::string> ret = key2words(key);
  return ret;
}
