#include <assert.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <mutex>
#include <thread>
#include <vector>

long long mod = 1000000007;

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

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
  return modpow(a, mod - 2, mod);
}
