#include <assert.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <mutex>
#include <thread>
#include <vector>

// aとbの最大公約数を求める
long long evalmod(long long a, long long b){
  long long maxval = std::max(a, b);
  long long minval = std::min(a, b);
  if (minval==0){
    return maxval;
  }
  long long tmpval = maxval%minval;
  return evalmod(minval, tmpval);
}
