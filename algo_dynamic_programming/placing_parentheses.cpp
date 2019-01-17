#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

typedef struct{
  vector<int> digits;
  vector<char> symbols;
} SplitResult;
typedef struct {
  long long minimum;
  long long maximum;
} MinMax;

SplitResult split_string_into_digits_and_symbols(const string &exp){
  SplitResult answer;
  for (size_t i = 0; i<exp.length(); i++){
    if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-'){
      answer.symbols.push_back(exp[i]);
    } else {
      int digit = (int)exp[i]-48;
      answer.digits.push_back(digit);
    }
  }
  return answer;
}
MinMax get_min_max(int i, int j, vector<vector<long long>> &min_map, vector<vector<long long>> &max_map, vector<char> &symbols){
  long long min_temp = LLONG_MAX;
  long long max_temp = LLONG_MIN;
  for (size_t k = i; k<j; k++){
      long long a = eval(max_map[i][k], max_map[k+1][j], symbols[k]);
      long long b = eval(min_map[i][k], min_map[k+1][j], symbols[k]);
      long long c = eval(max_map[i][k], min_map[k+1][j], symbols[k]);
      long long d = eval(min_map[i][k], max_map[k+1][j], symbols[k]);
      if (a<min_temp){
        min_temp = a;
      }
      if (b<min_temp){
        min_temp = b;
      }
      if (c<min_temp){
        min_temp = c;
      }
      if (d<min_temp){
        min_temp = d;
      }
      //max
      if (a>max_temp){
        max_temp = a;
      }
      if (b>max_temp){
        max_temp = b;
      }
      if (c>max_temp){
        max_temp = c;
      }
      if (d>max_temp){
        max_temp = d;
      }


  }
  MinMax answer;
  answer.minimum = min_temp;
  answer.maximum = max_temp;
  return answer;
}
void print_maps(vector<vector<long long>> &min_map, vector<vector<long long>> &max_map){
  std::cout<<"heres min map of size"<<min_map.size()<<std::endl;
  for (size_t i =0; i<min_map.size();i++){
    for(size_t j =0; j<min_map.size();j++){
      std::cout<<min_map[i][j]<<" ";
    }
    std::cout<<"\n";
  }
  std::cout<<"heres max map"<<std::endl;
  for (size_t i =0; i<max_map.size();i++){
    for(size_t j =0; j<max_map.size();j++){
      std::cout<<max_map[i][j]<<" ";
    }
    std::cout<<"\n";
  }
}
long long get_maximum_value(const string &exp) {
  SplitResult split_result = split_string_into_digits_and_symbols(exp);
  vector<int> digits = split_result.digits;
  vector<char> symbols = split_result.symbols;
  vector<vector<long long>> max_map(digits.size(),vector<long long>(digits.size()));
  vector<vector<long long>> min_map(digits.size(),vector<long long>(digits.size()));
  for (size_t i =0; i <digits.size(); i++){
    max_map[i][i] = digits[i];
    min_map[i][i] = digits[i];
  }
  // print_maps(min_map, max_map);
  for (size_t s = 0; s<digits.size()-1;s++){
    for (size_t i = 0; i<digits.size()-s-1;i++){
      size_t j = s+i+1;
      MinMax result = get_min_max(i,j,min_map, max_map, symbols);
      min_map[i][j] = result.minimum;
      max_map[i][j] = result.maximum;
    }
    // print_maps(min_map, max_map);
  }


  return max_map[0][digits.size()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
