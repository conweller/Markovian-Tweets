#include <fstream>
#include <iostream>
#include "markov.h"
#include <cassert>

int main(int argc, char *argv[])
{
  int i;
  srand((unsigned int)time(0));

  assert(argc == 2);

  std::ifstream inf;
  inf.open(argv[1]);
  if (!inf) {
    std::cout << "Error opening input.txt" << std::endl;
    exit(1);
  }

  int seq_size = 1;
  markov::sequences seq(seq_size);
  std::vector<std::string> curseq;
  std::string curword;

  for (i = 0; i < seq_size; ++i) {
    if (!(inf >> curword)) {
      std::cout << "Not enough source text" << std::endl;
      exit(1);
    }
    curseq.push_back(curword);
  }


  do {
    seq.insert(curseq, curword);
    curseq.erase(curseq.begin());
    curseq.push_back(curword);
  } while (inf >> curword);

  inf.close();

  curseq = seq.randkey();

  int nchars = 0;

  for (auto word: curseq) {
    std::cout << word << " ";
    nchars += word.size() + 1;
  }

  do {
    curword = seq.nextword(curseq);
    nchars += curword.length() + 1;
    std::cout << curword << " ";
    curseq.erase(curseq.begin());
    curseq.push_back(curword);
  } while (nchars < 280);

  std::cout << std::endl;

  return 0;
}
