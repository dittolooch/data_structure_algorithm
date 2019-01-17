#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int get_change(int m, vector<int> &coins) {
  vector<int> MinNumCoins(m + 1);
  MinNumCoins[0] = 0;
  for (size_t coin_index = 0; coin_index<coins.size(); coin_index++){
    MinNumCoins[coins[coin_index]] = 1;
  }

  int remainder;
  vector<int> legit_remainders(3);
  for (int i = 1; i<=m; i++){

    for (size_t coin_index = 0; coin_index<coins.size(); coin_index++){
      remainder = i - coins[coin_index];

      if (remainder>=0){
        int combination = MinNumCoins[remainder]+1;
        if (MinNumCoins[i] == 0 || combination < MinNumCoins[i]){
          MinNumCoins[i] = combination;
        }
      }
    }
  }

  return MinNumCoins[m];
}

int main() {
  vector<int> coins;
  coins.push_back(3);coins.push_back(1);coins.push_back(4);
  int m;
  std::cin >> m;
  std::cout << get_change(m, coins) << '\n';
}
