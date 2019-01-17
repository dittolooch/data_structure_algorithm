#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

int get_max_height(Node* root){
  if (root->children.size()==0){
    return 1;
  } else {
    int temp_max = INT_MIN;

    for(size_t i =0 ; i < root->children.size(); i++ ){
      Node *child = root->children[i];
      int height = get_max_height(child);
      if (height > temp_max) {
        temp_max = height;
      }
    }
    return temp_max+1;
  }


}
int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  Node *root;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0){
      nodes[child_index].setParent(&nodes[parent_index]);
    } else {
      root = &nodes[child_index];
    }

    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  int max_height = get_max_height(root);

  std::cout << max_height << std::endl;
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
