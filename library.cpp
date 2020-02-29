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

// nCk @mod を計算する
long long nCk(long long n, long k, long long mod){
  long long retval = 1;
  for (int i=0; i<k; i++){
    retval *= (n-i);
    retval %= mod;
  }
  for (int i=1; i<=k; i++){
    retval *= modinv(i, mod);
    retval %= mod;
  }
  return retval;
}
