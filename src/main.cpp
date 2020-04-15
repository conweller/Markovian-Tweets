#include <fstream>
#include <iostream>
#include "markov.h"

const int SEQ_SIZE = 1;
const int TWEET_SIZE = 280;

int main(int argc, char *argv[])
{
  int i;
  srand((unsigned int)time(0));

  assert(argc == 2);

  std::ifstream inf;
  inf.open(argv[1]);
  if (!inf) {
    std::cerr << "Error opening input.txt" << std::endl;
    exit(1);
  }

  markov::sequences seqs(SEQ_SIZE);
  std::vector<std::string> curseq_in;
  std::string curword_in;

  for (i = 0; i < SEQ_SIZE; ++i) {
    if (!(inf >> curword_in)) {
      std::cerr << "Not enough source text" << std::endl;
      exit(1);
    }
    curseq_in.push_back(curword_in);
  }


  do {
    seqs.insert(curseq_in, curword_in);
    curseq_in.erase(curseq_in.begin());
    curseq_in.push_back(curword_in);
  } while (inf >> curword_in);

  inf.close();

  std::vector<std::string> curseq_out = seqs.randkey();
  std::string curword_out;
  int nchars = 0;

  for (auto word: curseq_out) {
    std::cout << word << " ";
    nchars += word.size() + 1;
  }

  while (nchars < TWEET_SIZE) {
    if (!curword_out.empty()) {
      std::cout << curword_out << " ";
    }
    curword_out = seqs.nextword(curseq_out);
    nchars += curword_out.length() + 1;
    curseq_out.erase(curseq_out.begin());
    curseq_out.push_back(curword_out);
  }

  std::cout << std::endl;

  return 0;
}
