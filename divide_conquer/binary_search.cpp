#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
// binary search
// Function BinarySearch(vector a, key, lo, hi)
// If a.size()==0:
//     Return -1
// Else:
//     mid_index = (hi+lo) / 2
//     mid_element = a[mid_index]
//     If mid_element > key:
//        Return BinarySearch(a, key, lo , mid_index-1)
//     Else if mid_elelemnt<key
//        Return BinarySearch(a, key, mid_index+1,  hi)
//     Else if mid_elelemt == key
//         Return mid _index


int binary_search_helper(const vector<int> &a, int key, int lo, int hi) {
  int answer;
  if (hi<lo){
    answer = -1;
  } else {
    int mid_index = (hi+lo) / 2;
    int mid_element = a[mid_index];
    if (mid_element > key){
      answer = binary_search_helper(a, key, lo, mid_index-1);
    } else if (mid_element < key){
      answer =  binary_search_helper(a, key, mid_index+1, hi);
    } else {
      answer = mid_index;
    }
  }
  return answer;

}

int binary_search(const vector<int> &a, int key) {
  int answer = binary_search_helper(a, key, 0, a.size()-1);
  return answer;
}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
