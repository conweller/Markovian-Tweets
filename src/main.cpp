#include <fstream>
#include <iostream>
#include "markov.h"

int main(int argc, char *argv[])
{
  srand((unsigned int)time(0));

  assert(argc == 2);

  std::ifstream inf;
  inf.open(argv[1]);
  if (!inf) {
    std::cout << "Error opening input.txt" << std::endl;
    exit(1);
  }

  markov::sequences seq(2);

  std::string curword0;
  std::string curword1;
  std::string nextword;

  do {
    seq.insert({curword0, curword1}, nextword);
    curword0 = curword1;
    curword1 = nextword;
  } while (inf >> nextword);

  inf.close();

  std::vector<std::string> startkey = seq.randkey();

  curword0 = startkey[0];
  curword1 = startkey[1];

  int nchars = curword0.length() + curword1.length() + 2;

  std::cout << curword0 << " ";
  std::cout << curword1 << " ";

  do {
    curword0 = curword1;
    curword1 = seq.nextword({curword0, curword1});
    nchars += curword1.length();
    std::cout << curword1;
  } while (nchars < 280);

  std::cout << std::endl;

  return 0;
}
