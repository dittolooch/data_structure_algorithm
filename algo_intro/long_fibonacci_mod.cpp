// Problem Description
// Task: Given two integers 𝑛 and 𝑚, output 𝐹𝑛 mod 𝑚
//
// (that is, the remainder of 𝐹𝑛 when divided by 𝑚).
//
// Input Format:
//
// The input consists of two integers 𝑛 and 𝑚 given on the same line (separated by a space).
//
// Constraints: 1≤𝑛≤1018,2≤𝑚≤105.
//
// Output Format: Output 𝐹𝑛 mod 𝑚.

#include <iostream>

long long fibonacci_fast(int n) {
    int fib_list[n];
    fib_list[0] = 0; fib_list[1] = 1;
    for (size_t i = 2; i <= n; i++) {
      fib_list[i] = fib_list[i-1] + fib_list[i-2];
    }

    return fib_list[n];
}

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;



    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
