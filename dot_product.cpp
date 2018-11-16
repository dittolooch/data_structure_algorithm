#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <time.h>
using std::vector;
int partition(vector<long> &data, int lo, int hi){
  int pivot = data[hi];
  int border_index = lo-1;
  for (int i=lo; i < hi; i++){
    if (data[i] < pivot){
      border_index ++;
      int temp = data[i];
      data[i] = data[border_index];
      data[border_index] = temp;
    }
  }
  border_index ++;
  data[hi] = data[border_index];
  data[border_index] = pivot;
  return border_index;
}
void quicksort(vector<long> &data, int lo, int hi){
  if (hi-lo >= 1){
    int pivot_index = partition(data, lo, hi);
    quicksort(data, lo, pivot_index-1);
    quicksort(data,pivot_index+1, hi);
  }
}


long long max_dot_product(vector<long> a, vector<long> b) {
  // write your code here

  quicksort(a, 0, a.size()-1);
  quicksort(b, 0, b.size()-1);
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++){
    result += a[i] * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
