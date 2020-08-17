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

// modを取らないnCkの計算
// 全体としてはオーバーフローしないはずでも、先に分子だけ計算したときに
// オーバーフローする可能性があることに注意
long long nCk(long long n, long long k)	{
  if (k>n) return -1;
  if (2*k>n) return nCk(n, n-k);
  long long retval = 1;
  for (int i=0; i<k; i++) {
    retval *= (n-i);
  }
  for (int i=0; i<k; i++) {
    retval /= (i+1);
  }
  return retval;
}

// パスカルの三角形によるnCkの計算
// n<=N, k<=nを満たす全てのnCkを前計算する
long long NCK[54][54];
void init(int N=54)	{
  for (int i=0; i<N; i++) {
    for (int j=0; j<=i; j++) {
      if (j==0 || j==i) {
        NCK[i][j] = 1;
      } else {
        // パスカルの三角形の性質 nCk = (n-1)C(k-1) + (n-1)Ck を利用
        NCK[i][j] = NCK[i-1][j-1] + NCK[i-1][j];
      }
    }
  }
  return;
}
