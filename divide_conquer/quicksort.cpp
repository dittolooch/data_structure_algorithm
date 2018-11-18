#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <time.h>
using std::vector;
int partition(vector<int> &data, int lo, int hi){
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
void quicksort(vector<int> &data, int lo, int hi){
  if (hi-lo >= 1){
    int pivot_index = partition(data, lo, hi);
    quicksort(data, lo, pivot_index-1);
    quicksort(data,pivot_index+1, hi);
  }
}

int main() {
  srand (time(NULL));
  size_t n = 10;
  vector<int> data(n);
  for (size_t i = 0; i < n; i++){
    data[i] = (int)(rand() % 100 + 1);
    std::cout << data[i] << " ";
  }
  quicksort(data, 0, data.size()-1);
  std::cout << std::endl << "AFTER PARTITION"<< std::endl;
  for (size_t i = 0; i < n; i++){
    std::cout << data[i] << " ";
  }
  verify(data)



}
