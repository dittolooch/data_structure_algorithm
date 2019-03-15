#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
private:
  void _in_order(int index, vector<int> *result){
    //left(recur) root right(recur)
    if (left[index] != -1){
      //index has left child
      int left_child = left[index];
      _in_order(left_child, result);
    }

    (*result).push_back(key[index]);
    if (right[index] != -1){
      int right_child = right[index];
      _in_order(right_child, result);
    }
  }
  void _pre_order(int index, vector<int> *result){
    (*result).push_back(key[index]);
    if (left[index] != -1){
      //index has left child
      int left_child = left[index];
      _pre_order(left_child, result);
    }
    if (right[index] != -1){
      int right_child = right[index];
      _pre_order(right_child, result);
    }
  }
  void _post_order(int index, vector<int> *result){

    if (left[index] != -1){
      //index has left child
      int left_child = left[index];
      _post_order(left_child, result);
    }
    if (right[index] != -1){
      int right_child = right[index];
      _post_order(right_child, result);
    }
      (*result).push_back(key[index]);

  }
public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    _in_order(0, &result);


    return result;
  }

  vector <int> pre_order() {
    vector<int> result;
    _pre_order(0, &result);

    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    _post_order(0, &result);


    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}
