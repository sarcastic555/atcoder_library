#include <assert.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <mutex>
#include <thread>
#include <vector>

bool sortcol(std::vector<long long>& v1, std::vector<long long>& v2, int columnnum){
  return v1[columnnum] < v2[columnnum];
}

// 小さいもの順
bool sortcol3(std::vector<long long>& v1, std::vector<long long>& v2 ) {
  return sortcol(v1, v2, 3);
}

// 大きいもの順
bool sortcol3_inv(std::vector<long long>& v1, std::vector<long long>& v2){
  return sortcol(v2, v1, 3);
}

bool isprime(int n){
  bool prime = true;
  for (int i=2; i*i<=n; i++){
    if (n%i==0){
      prime=false;
      break;
    }
  }
  return prime;
}
