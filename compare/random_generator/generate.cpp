#include <random>
#include <iostream>

int main(int argc, char* argv[]) {
  std::random_device rnd;
  std::mt19937 mt(rnd());
  // rand1(0, N-1)
  // int N = rand1(mt)
  // とすることで[0, N-1] の範囲の一様の整数乱数
  std::uniform_int_distribution<> rand1(1, 3);
  std::uniform_int_distribution<> rand2(1, 32);
  int H = rand1(mt) + 1;
  int W = rand1(mt) + 1;
  int C = rand2(mt);    
  std::cout << H << std::endl;
  std::cout << W << std::endl;
  std::cout << C << std::endl;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      int A = rand2(mt);
      std::cout << A << std::endl;
    }
  }
  return 0;
}
