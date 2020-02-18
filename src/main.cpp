#include <fstream>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include "markov.h"

using namespace std;

int main(void)
{
  srand((unsigned int)time(0));

  ifstream inf;
  inf.open("input.txt");
  if (!inf) {
    cout << "Error opening" << endl;
    exit(1);
  }

  markov::sequences seq;

  string curword0 = "";
  string curword1 = "";
  string nextword = "";

  do {
    seq.insert(curword0, curword1, nextword);
    curword0 = curword1;
    curword1 = nextword;
  } while (inf >> nextword);

  inf.close();

  ofstream ouf;
  ouf.open("output.txt");
  if (!ouf) {
    cout << "Error opening" << endl;
    exit(1);
  }

  vector<string> startkey = seq.randkey();

  curword0 = startkey[0];
  curword1 = startkey[1];

  int nchars = curword0.length() + curword1.length() + 1;

  if (curword0 != " " && curword0 != "\n") {
    ouf << curword0 << " ";
  }

  if (curword1 != " " && curword1 != "\n") {
    ouf << curword1 << " ";
  }

  do {
    curword0 = curword1;
    curword1 = seq.nextword(curword0, curword1);
    nchars += curword1.length();
    if (curword1 != " " && curword1 != "\n") {
      ouf << curword1 << " ";
    }
  } while (nchars < 280);

  ouf << std::endl;

  ouf.close();


  return 0;
}
