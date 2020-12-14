#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

int par[100005];
int rank[100005];

// グループのサイズを短時間で取得したい場合は、
// 親のparにマイナスをつけてサイズを保存して置くとよい
void Init(){
  for (int i=0; i<100005; i++){
    par[i] = i;
    rank[i] = 0;
  }
  return;
}

int GetRoot(int x){
  //printf("checking par[%d]==%d\n",x,par[x]);
  if (par[x]==x){
    return x;
  } else {
    return GetRoot(par[x]);
  }
}

int IsSameGroup(int x, int y){
  //printf("root of %d=%d\n",x,GetRoot(x));
  //printf("root of %d=%d\n",y,GetRoot(y));
  if (GetRoot(x)==GetRoot(y)){
    return true;
  } else {
    return false;
  }
}

bool Union(int x, int y){
  if (IsSameGroup(x, y)){
    return false;
  } else {
    int rootx=GetRoot(x);
    int rooty=GetRoot(y);
    if (rank[rootx]>rank[rooty]){
      par[rooty] = rootx;
      //printf("par[%d]=%d\n",y,x);
    } else {
      par[rootx] = rooty;
      //printf("par[%d]=%d\n",x,y);
      if (rank[rootx]==rank[rooty]){
        rank[rooty]++;
      }
    }
    return true;
  }
}
