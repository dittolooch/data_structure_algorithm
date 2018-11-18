#include <iostream>
#include <vector>
// Problem Introduction
//
// Find the last digit of a partial sum of Fibonacci numbers: 𝐹𝑚 + 𝐹𝑚+1 + · · · + 𝐹𝑛.
//
//
// Task:
//   Given two non-negative integers 𝑚 and 𝑛, where 𝑚 ≤ 𝑛, find the last digit of the sum 𝐹𝑚 + 𝐹𝑚+1 + ···+𝐹𝑛.

// Input Format:
//   The input consists of two non-negative integers 𝑚 and 𝑛 separated by a space.

// Constraints :
//   0 ≤ 𝑚 ≤ 𝑛 ≤ 1018.

// Output Format:
//   Output the last digit of 𝐹𝑚 + 𝐹𝑚+1 + · · · + 𝐹𝑛.

using std::vector;
int fibonacci_sum(long long n) {


    unsigned long long pisano_period_for_10 = 60;
    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long sum      = 1;
    unsigned long long needed_index = n % pisano_period_for_10;

    for (unsigned long long i = 2; i <= needed_index ; ++i) {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
        sum = sum % 10;
    }
    if (needed_index <= 1){
      return needed_index;
    }

    return sum;
}

int get_fibonacci_partial_sum(unsigned long long from, unsigned long long to) {
    if (from!=0) from = from -1 ;

    unsigned long long last_digit_of_sum_at_from = fibonacci_sum(from);
    // std::cout << "last digit of sum to index = " << from << "is " << last_digit_of_sum_at_from << std::endl;
    unsigned long long last_digit_of_sum_at_to = fibonacci_sum(to);
    // std::cout << "last digit of sum to index = " << to << "is " << last_digit_of_sum_at_to << std::endl;
    int answer = last_digit_of_sum_at_to - last_digit_of_sum_at_from;
    // std::cout << "answer  = " << answer << std::endl;

    if (answer < 0) answer += 10;
    // std::cout << "answe is " << answer << std::endl;

    return answer;
}

int main() {
    unsigned long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
