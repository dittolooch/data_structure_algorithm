#include <iostream>

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

int main() {
    // std::cout << sizeof(unsigned long long) << std::endl;
    // std::cout << sizeof(long) << std::endl;
    // std::cout << sizeof(unsigned long) << std::endl;
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
