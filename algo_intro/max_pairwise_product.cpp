#include <iostream>
#include <vector>


using std::vector;
using std::cin;
using std::cout;


unsigned long long int MaxPairwiseProduct(const vector<unsigned long int>& numbers) {
  unsigned long int max_index = 0;
  unsigned long int max = 0;
  unsigned long int second_max_index = 0;
  unsigned long int second_max = 0;
  unsigned long int n = numbers.size();
  unsigned long long int result;
  for (int i = 0; i < n; ++i) {
    if (numbers[i] > max) {
      second_max = max;
      second_max_index = max_index;
      max = numbers[i];
      max_index = i;
    } else if (numbers[i]>second_max) {
      second_max = numbers[i];
      second_max_index = i;

    }
  }
  result = max * second_max;

  return result;
}

int main() {
    unsigned int n;
    cin >> n;
    vector<unsigned long int> numbers(n);
    for (unsigned int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    unsigned long long int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
