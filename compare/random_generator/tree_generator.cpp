#include <iostream>
#include <random>
#include <algorithm>
#include <queue>
#include <ctime>        // time
#include <cstdlib>      // srand,rand
#include <fstream>

int main(int argc, char *argv[]) {
  if (argc!=3) {
    printf("Useage: ./tree_generator N output_filename\n");
    return -1;
  }
  int N = atoi(argv[1]);
  std::string output_filename = argv[2];
  
  std::vector<int > vec(N);
  for (int i=0; i<N; i++) {
    vec[i] = i;
  }
  std::mt19937 get_rand_mt(static_cast<unsigned int>(time(nullptr)));
  std::shuffle( vec.begin(), vec.end(), get_rand_mt);
  std::vector<int> used;
  std::queue<std::pair<int, int > > output;
  used.push_back(vec[0]);
  std::srand( time(NULL) );
  for (int i=1; i<N; i++) {
    int src = vec[i];
    int target_index = rand()%(used.size());
    int target = used[target_index];
    while(target==src) {
      target = used[rand()%(used.size())];
    }
    output.push(std::make_pair(src, target));
    used.push_back(src);
  }
  std::ofstream fileout(output_filename, std::ios::app);
  while(output.size()>0) {
    fileout << output.front().first+1 << " " << output.front().second+1 << std::endl;
    output.pop();
  }
  return 0;
}
