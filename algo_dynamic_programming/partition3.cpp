#include <iostream>
#include <vector>
using namespace std;
using std::vector;

typedef struct {
  int value;
  bool used;
} Gift;

typedef struct {
  int max_weight;
  vector<Gift> gifts_not_used;
} OptimalWeightAnswer;

struct m1m2
{
  int m1;
  int m2;
};

m1m2 partition(vector<Gift> &a, int l, int r) {
  Gift x = a[l];
  int j = l-1;
  int k = r+1;
  for (int i = l+1; i < k; i++) {
    if (a[i].value > x.value) {
      j++;
      swap(a[i], a[j]);
    }
    else if (a[i].value< x.value){
      k--;
      swap(a[i],a[k]);
      i--;
    }
  }
  m1m2 result = {j,k};
  return result;
}
void randomized_quick_sort(vector<Gift> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  m1m2 M = partition(a, l, r);
  randomized_quick_sort(a, l, M.m1);
  randomized_quick_sort(a, M.m2, r);
}
OptimalWeightAnswer optimal_weight(int W, vector<Gift> &gifts_vector) {
  vector<vector<int>> optimal_weights(W+1, vector<int>(gifts_vector.size()+1));
  int optimal;
  int included;
  for (size_t i = 0; i <= W; i++) {
    for (size_t j = 0 ; j<=gifts_vector.size(); j++){
      if (i==0 || j==0){
        optimal_weights[i][j] = 0;
      } else {
        optimal_weights[i][j] = optimal_weights[i][j-1];
        if (gifts_vector[j-1].value<=i){
          included = optimal_weights[i-gifts_vector[j-1].value][j-1] + gifts_vector[j-1].value;
          if (included > optimal_weights[i][j]){
            optimal_weights[i][j] = included;

          }
        }
      }
    }
  }

  int remainder_knapsack = W;
  int weight_index = gifts_vector.size();
  while (remainder_knapsack){
    int temp = optimal_weights[remainder_knapsack][weight_index];
    if (temp == optimal_weights[remainder_knapsack][weight_index-1]){
      weight_index --;
    } else{
      if (weight_index-1<0){
        break;
      }
      remainder_knapsack = remainder_knapsack - gifts_vector[weight_index-1].value;
      gifts_vector[weight_index-1].used = true;
      weight_index--;
    }
  }
  vector<Gift> gifts_not_used;
  for (size_t i =0; i<gifts_vector.size(); i++){
    if (!gifts_vector[i].used){
      gifts_not_used.push_back(gifts_vector[i]);
    }
  }
  OptimalWeightAnswer answer;
  answer.gifts_not_used = gifts_not_used;
  answer.max_weight =  optimal_weights[W][gifts_vector.size()];
  return answer;
}
int get_total_value_of(vector<Gift> &gifts_vector){
  int answer = 0;
  for (size_t i = 0; i< gifts_vector.size();i++){
    answer += gifts_vector[i].value;
  }
  return answer;
}
int partition3(vector<Gift> &gifts_vector) {
  randomized_quick_sort(gifts_vector, 0, gifts_vector.size()-1);
  int answer;
  int total_value = get_total_value_of(gifts_vector);
  if (total_value % 3 != 0 || gifts_vector.size()<3){
    answer = 0;
  } else {
    int one_third = total_value /3;
    OptimalWeightAnswer optimized_result = optimal_weight(one_third, gifts_vector);
    if (optimized_result.max_weight != one_third){
      answer=0;
    } else {
      OptimalWeightAnswer second_result = optimal_weight(one_third, optimized_result.gifts_not_used);
      if (second_result.max_weight == one_third){
        answer= 1;
      } else {
        answer =0;
      }
    }
  }
  return answer;
}

int main() {
  int n;
  std::cin >> n;
  vector<Gift> gifts_vector(n);
  for (size_t i = 0; i < gifts_vector.size(); ++i) {
    Gift gift;
    std::cin >> gift.value;
    gift.used = false;
    gifts_vector[i] = gift;

  }


  std::cout << partition3(gifts_vector) << '\n';
}
