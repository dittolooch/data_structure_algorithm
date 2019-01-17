#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using std::vector;
// *3 *2 +1

vector<int> optimal_sequence(int n) {
  vector<int> optimal_map_steps(n+1);
  vector<int> optimal_map_previous(n+1);

  optimal_map_steps[1] = 0;
  optimal_map_previous[1] = -1;

  for (size_t i = 2; i <= n; i++){

    int legit_previous_step;
    int minimum_steps = INT_MAX;
    int minimum_steps_previous_step;

    if (i % 3 == 0) {
      legit_previous_step = i / 3;
      if (optimal_map_steps[legit_previous_step] < minimum_steps){
        minimum_steps = optimal_map_steps[legit_previous_step];
        minimum_steps_previous_step = legit_previous_step;
      }

    }
    if (i % 2 == 0) {
      legit_previous_step = i / 2;
      if (optimal_map_steps[legit_previous_step] < minimum_steps){
        minimum_steps = optimal_map_steps[legit_previous_step];
        minimum_steps_previous_step = legit_previous_step;
      }
    }

    legit_previous_step = i - 1;
    if (optimal_map_steps[legit_previous_step] <= minimum_steps){
      minimum_steps = optimal_map_steps[legit_previous_step];
      minimum_steps_previous_step = legit_previous_step;
    }
    //now we have the best legit_previous_step and the steps of it.
    optimal_map_steps[i] = minimum_steps + 1;
    optimal_map_previous[i] = minimum_steps_previous_step;

  }

  vector<int> sequence;
  sequence.push_back(n);
  while (n!=1){
    sequence.push_back(optimal_map_previous[n]);
    n = optimal_map_previous[n];
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
