#include <iostream>
#include <vector>
using std::vector;
using std::swap;
using std::max;

int optimal_weight(int W, vector<int> &w) {
  //write your code here
  // randomized_quick_sort(w, 0 , w.size()-1);

  vector<vector<int>> optimal_weights(W+1, vector<int>(w.size()+1));
  int optimal;
  int included;
  for (size_t i = 0; i <= W; i++) {
    for (size_t j = 0 ; j<=w.size(); j++){
      if (i==0 || j==0){
        optimal_weights[i][j] = 0;
      } else {
        optimal_weights[i][j] = optimal_weights[i][j-1];
        if (w[j-1]<=i){
          included = optimal_weights[i-w[j-1]][j-1] + w[j-1];
          if (included > optimal_weights[i][j]){

            optimal_weights[i][j] = included;
          }
        }
      }
    }
      
  }
  // for (int i =0; i <=W; i++){
  //   for(int j = 0;j<=w.size();j++){
  //     std::cout<<optimal_weights[i][j]<<" ";
  //   }
  //
  //   std::cout<<std::endl;
  // }
  //   std::cout<<std::endl;

  return optimal_weights[W][w.size()];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
