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

  tuple<string, string> startkey = seq.randkey();
  string 

  int nchars = curword.length();
  do {
    std::cout << curword << " ";
    curword = seq.nextword(
    nchars += curword.length();
  } while (nchars < 280);
  ouf.close();


  return 0;
}
