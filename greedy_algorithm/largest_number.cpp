#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::stoi;
bool isGreaterOrEqual(string a, string b){
  string a_in_the_front;
  a_in_the_front.append(a).append(b);
  string b_in_the_front;
  b_in_the_front.append(b).append(a);
  int a_front = stoi(a_in_the_front);
  int b_front = stoi(b_in_the_front);
  return a_front>=b_front;

}

int partition(vector<string> &data, int lo, int hi){
  string pivot = data[hi];
  int border_index = lo-1;
  for (int i=lo; i < hi; i++){
    if (isGreaterOrEqual(data[i],pivot)){
      border_index ++;
      string temp = data[i];
      data[i] = data[border_index];
      data[border_index] = temp;
    }
  }
  border_index ++;
  data[hi] = data[border_index];
  data[border_index] = pivot;
  return border_index;
}

void quicksort(vector<string> &data, int lo, int hi){
  if (hi-lo >= 1){
    int pivot_index = partition(data, lo, hi);
    quicksort(data, lo, pivot_index-1);
    quicksort(data,pivot_index+1, hi);
  }
}


string largest_number(vector<string> a) {
  quicksort(a, 0, a.size()-1);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {

  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
