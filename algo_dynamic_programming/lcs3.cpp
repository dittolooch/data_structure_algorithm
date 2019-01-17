#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b,vector<int> &c) {
  int L_matrix[a.size()+1][b.size()+1][c.size()+1];
  int i,j,k;
  for(k = 0; k <= c.size(); k++){
    for(j = 0; j <= b.size(); j++){
      for(i = 0; i <= a.size(); i++){
        if(i == 0 || j == 0 || k ==0){L_matrix[i][j][k] = 0;}
        else if(a[i-1] == b[j-1] && a[i-1] == c[k-1] && b[j-1] == c[k-1]){
          L_matrix[i][j][k] = L_matrix[i-1][j-1][k-1] + 1;
          }
        else{ L_matrix[i][j][k] = max(max( L_matrix[i-1][j][k], L_matrix[i][j-1][k]),L_matrix[i][j][k-1]); }
      }
    }
  }
  return L_matrix[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
