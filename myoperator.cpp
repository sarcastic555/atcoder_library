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

struct point {
  int i;
  int x;
  int y;
};

bool SortXMin (const point &p1, const point &p2){
  return p1.x < p2.x;
}

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

  // Case #3
  // 構造体を要素にもつvectorに対してxが小さい順にソートする
  std::vector<point> data;
  data.push_back((point){0, 3, 5}); // {i, x, y}
  data.push_back((point){1, 7, 6}); // {i, x, y}
  data.push_back((point){2, 1, 3}); // {i, x, y}
  data.push_back((point){3, 2, 5}); // {i, x, y}
  std::sort(data.begin(), data.end(), SortXMin);
  printf("=========\n");
  for (auto &entry : data) {
    printf("#%d, (%d, %d)\n", entry.i, entry.x, entry.y);
  }

  return 0;
}
