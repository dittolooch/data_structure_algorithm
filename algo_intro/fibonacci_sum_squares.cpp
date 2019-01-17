#include <iostream>
// Task. Compute the last digit of 𝐹0^2 +𝐹1^2 +···+𝐹𝑛^2.
// Input Format. Integer 𝑛.
// Constraints. 0 ≤ 𝑛 ≤ 1018.
// Output Format. The last digit of 𝐹02 + 𝐹12 + · · · + 𝐹𝑛2.

int fibonacci_sum_squares(unsigned long long n) {
    if (n <= 1)
        return n;
    unsigned long long pisano_period_for_10 = 60;
    unsigned long long needed_index = n % pisano_period_for_10;
    unsigned long long previous = 0;
    unsigned long long current  = 1;



    for (long long i = 2; i <= needed_index; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    int next = (current + previous) % 10;
    int answer = (next * current) % 10;
    if (needed_index <= 1){
      return needed_index;
    }


    return answer;
}

int main() {
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
