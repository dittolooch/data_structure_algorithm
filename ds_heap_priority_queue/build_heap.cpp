#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }
  bool isHeap(int i, int n) {
  // If a leaf node
  if (i > (n - 2)/2)
      return true;

  // If an internal node and is greater than its children, and
  // same is recursively true for the children
  if (data_[i] <= data_[2*i + 1] && data_[i] <= data_[2*i + 2] &&
      isHeap( 2*i + 1, n) && isHeap(2*i + 2, n))

      return true;

  return false;
  }
  void ReadData() {
    long long n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  void bubble_down(int running){
    int left_child_index = running*2+1;
    int right_child_index = running*2+2;
    bool has_left_child = false;
    bool has_right_child = false;
    if (left_child_index < data_.size()){
      has_left_child= true;
    }
    if (right_child_index < data_.size()){
      has_right_child = true;
    }
    while (has_left_child || has_right_child){
      int smaller_child_index;
      bool swapped = false;
      if (has_left_child && has_right_child){
        smaller_child_index = data_[left_child_index] < data_[right_child_index]?left_child_index:right_child_index;
        if (data_[smaller_child_index] < data_[running]){
          swap(data_[running], data_[smaller_child_index]);
          pair<int,int> answer (running, smaller_child_index);
          swaps_.push_back(answer);
          swapped = true;
        }
      } else if (has_left_child) {
        smaller_child_index = left_child_index;

        if (data_[smaller_child_index] < data_[running]){
          swap(data_[running], data_[smaller_child_index]);
          pair<int,int> answer (running, smaller_child_index);
          swaps_.push_back(answer);
          swapped = true;
        }
      }
      if (swapped){
        running = smaller_child_index;
        left_child_index = running*2+1;
        right_child_index = running*2+2;
        has_left_child = left_child_index < data_.size();
        has_right_child = right_child_index < data_.size();

      } else {
        return;
      }
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for (int running = data_.size()-1; running >= 0; running--){
      bubble_down(running);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
