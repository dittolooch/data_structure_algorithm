#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

typedef struct {
  int low;
  int high;
} partition_result;


partition_result partition2(vector<int> &a, int l, int r) {
  int pivot = a[l];
  int low_holder = l-1;
  int high_holder = r +1;
  for (int i = l; i < high_holder; i++) {
    if (a[i] < pivot) {
      low_holder++;
      swap(a[i], a[low_holder]);

    } else if (a[i]> pivot){
      high_holder--;
      swap(a[i],a[high_holder]);

      i--;
    }
  }
  partition_result result;
  result.low = low_holder;
  result.high = high_holder;
  return result;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  partition_result result = partition2(a, l, r);
  // std::cout <<"after partition..."<<std::endl;
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cout << a[i] << ' ';
  // }



  randomized_quick_sort(a, l, result.low);
  randomized_quick_sort(a, result.high, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
