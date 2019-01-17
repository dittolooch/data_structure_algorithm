#include <iostream>
#include <vector>

using std::vector;

int get_max_unit_value_item_index(vector<double> weights, vector<double> values){
  int max_index;
  double max_unit_value = 0.0;
  for (size_t i = 0; i < weights.size(); i++){
    if (weights[i] == 0 ) continue;
    double unit_value = values[i] / weights[i];
    if (unit_value > max_unit_value) {
      max_unit_value = unit_value;
      max_index = i;
    }
  }
  //if weights and values are depleted
  if (!max_unit_value) return -1;
  return max_index;
}

double min(double a, double b){
  if (a>b){
    return b;
  } else {return a;}
}

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  int max_index;
  double value_to_take;
  double units_to_take;
  double units_available;
  while (capacity){
    max_index = get_max_unit_value_item_index(weights, values);
    //when there's no max index, inventory depleted
    if (max_index==-1) break;
    units_available = weights[max_index];
    units_to_take = min(units_available, capacity);
    value_to_take = units_to_take * values[max_index] / weights[max_index];
    value += value_to_take;

    weights[max_index] -= units_to_take;
    values[max_index] -= value_to_take;
    capacity -= units_to_take;
  }



  return value;
}

int main() {
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
