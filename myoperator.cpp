#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

struct pos{
  int i;
  int j;
};

class CompareFirst {
public:
  bool operator()(std::pair<long long, pos> n1, std::pair<long long, pos> n2) {
    return n1.first>n2.first;
  }
};

class CompareFirst2 {
public:
  bool operator()(std::pair<int, int> n1, std::pair<int, int> n2) {
    return (n1.first!=n2.first)?(n1.first>n2.first):(n1.second>n2.second);
  }
};

int main(){
  // Case #1
  // priority_queueに(距離(long long型)，座標(int, int))を配置するときに，距離が小さい順に取り出したい
  std::priority_queue<std::pair<long long, pos>, std::vector<std::pair<long long, pos> >, CompareFirst> queue;
  queue.push(std::make_pair(0, (pos){3, 4}));
  queue.push(std::make_pair(3, (pos){5, 1}));
  queue.push(std::make_pair(2, (pos){1, 1}));
  queue.push(std::make_pair(2, (pos){2, 2}));

  while(queue.size()>0){
    auto entry = queue.top();
    queue.pop();
    printf("(%lld, (%d, %d))\n", entry.first, entry.second.i, entry.second.j);
  }

  // Case #2
  // priority_queueにintのペアを入れて，第一要素が小さい順（第一要素が同じ値の場合は第二要素が小さい順）で取り出す
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, CompareFirst2> queue2;
  queue2.push(std::make_pair(2, 3));
  queue2.push(std::make_pair(2, 5));
  queue2.push(std::make_pair(1, 3));
  queue2.push(std::make_pair(4, 3));
  queue2.push(std::make_pair(4, 1));
  
  while(queue2.size()>0){
    auto entry = queue2.top();
    queue2.pop();
    printf("(%d, %d)\n", entry.first, entry.second);
  }

  return 0;
}
