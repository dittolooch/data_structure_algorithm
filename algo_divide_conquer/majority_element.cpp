
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
int getFrequency(vector<int> &a, int left, int right, int elem){
  int counter = 0;
  for (int i = left; i <=right; i++){
    if (a[i] == elem) {counter++;}
  }

  return counter;
}
int get_majority_element(vector<int> &a, int left, int right) {

  if (left == right) {
      return a[left];
  }

  int n = right-left+1;
  int k = n/2;
  int mid = (left+right)/2;
  int elemL = get_majority_element(a, left, mid);
  int elemR = get_majority_element(a, mid+1, right);
  if (elemL == elemR) {
    return elemL;
  }
  int lcount = getFrequency(a, left, right, elemL);
  int rcount = getFrequency(a, left, right, elemR);
  if (lcount > k){
    return elemL;
  } else if (rcount > k){
    return elemR;
  } else {
    return -1;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size()-1)!=-1) << '\n';

}
