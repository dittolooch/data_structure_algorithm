#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int last_traverse = INT_MIN;
bool answer = true;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void _in_order(int index, const vector<Node>& tree){

  //left(recur) root right(recur)
  if (tree[index].left != -1){
    //index has left child
    int left_child = tree[index].left;
    _in_order(left_child, tree);
  }
  if (tree[index].key > last_traverse){
    last_traverse = tree[index].key;
  } else {
    answer = false;
  }

  if (tree[index].right != -1){
    int right_child = tree[index].right;
    _in_order(right_child, tree);
  }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  if (tree.size()!= 0){
      _in_order(0, tree);
  }

  return answer;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
