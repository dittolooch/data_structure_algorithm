#include <iostream>
#include <vector>

using std::vector;

vector<unsigned int> optimal_summands(unsigned int n) {
  vector<unsigned int> summands;
  unsigned int running_problem = n;
  unsigned int remainder;
  if (n==1){summands.push_back(1);return summands;}
  for (unsigned int i = 1; i < n; i++){

    running_problem = running_problem - i;
    if (running_problem <= i){
      summands.push_back(running_problem + i);
      break;
    }
    summands.push_back(i);
  }
  return summands;
}

int main() {
  unsigned int n;
  std::cin >> n;
  vector<unsigned int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
