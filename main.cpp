#include "library.cpp"

int main(){
  std::vector<std::vector<long long> > vect(3, std::vector<long long> (5));
  vect[0][0]=3;
  vect[0][1]=5;
  vect[0][2]=1;
  vect[0][3]=8;
  vect[0][4]=9;
  vect[1][0]=4;
  vect[1][1]=3;
  vect[1][2]=8;
  vect[1][3]=1;
  vect[1][4]=2;
  vect[2][0]=7;
  vect[2][1]=2;
  vect[2][2]=0;
  vect[2][3]=6;
  vect[2][4]=2;
  
  std::cout << "before sorting" << std::endl;
  for (int i=0; i<3; i++){
    for (int j=0; j<5; j++){
      std::cout << vect[i][j] << " ";
    }
    std::cout << std::endl;
  }
  // sort by [3] element
  std::cout << "after sorting" << std::endl;
  std::sort(vect.begin(), vect.end(), sortcol3);
  for (int i=0; i<3; i++){
    for (int j=0; j<5; j++){
      std::cout << vect[i][j] << " ";
    }
    std::cout << std::endl;
  }
  
  return 0;
}
