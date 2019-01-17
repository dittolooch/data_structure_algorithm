#include <iostream>

// Task
//
// The goal in this problem is to find the minimum number of coins needed to change
// the input value (an integer) into coins with denominations 1, 5, and 10.
//
// Input Format
//
// The input consists of a single integer 𝑚.
//
// Constraints
//
// 1 ≤ 𝑚 ≤ 103
//
// Output Format.
//
// Output the minimum number of coins with denominations 1, 5, 10 that changes 𝑚.
#define COIN_ARRAY_SIZE 3


int get_highest_value_coin_for(int target_value){
  int coins[COIN_ARRAY_SIZE] = {10, 5, 1};
  int index_of_highest_value_coin;
  for (size_t i = 0; i < COIN_ARRAY_SIZE ; i++){
    if (coins[i] <= target_value){
      index_of_highest_value_coin = i;
      break;

    }
  }
  return coins[index_of_highest_value_coin];
}

int get_change(int target_value) {
  int coin_value_to_use;
  int number_coins_to_take;
  int total_number_coins = 0;
  while (target_value) {
    coin_value_to_use = get_highest_value_coin_for(target_value);
    number_coins_to_take = target_value / coin_value_to_use;
    target_value -= number_coins_to_take * coin_value_to_use;
    total_number_coins += number_coins_to_take;
  }
  return total_number_coins;
}

int main() {
  int target_value;
  std::cin >> target_value;
  std::cout << get_change(target_value) << '\n';
}
