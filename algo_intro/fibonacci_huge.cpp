#include <iostream>



unsigned long long get_pisano_period(unsigned long long m) {
    if (m == 1) return 1;
    unsigned long long previous = 0;
    unsigned long long current  = 1;
    unsigned long long pisano_period;
    unsigned long long counter = 0;

    while (true) {
      unsigned long long tmp_previous = previous;
      previous = current % m;
      current = (tmp_previous + current) % m;
      if (current == 1 && previous == 0) {
        pisano_period = counter + 1;
        break;
      }
      counter ++;
    }
    return pisano_period;
}

unsigned long long get_fibonacci_modulo(unsigned long long n, unsigned long long m) {
  if (n <= 1){
    return n;
  }

  unsigned long long pisano_period = get_pisano_period(m);
  // std::cout << "pisano priod=" << pisano_period << '\n';
  unsigned long long needed_fibonacci_index = n % pisano_period;
  // std::cout << "needed index=" << n % pisano_period  << '\n';

  unsigned long long previous = 0;
  unsigned long long current  = 1;

  for (unsigned long long i = 2; i <= needed_fibonacci_index; i++){
    unsigned long long tmp_previous = previous;
    previous = current % m;
    current = (tmp_previous + current) % m;
    // std::cout << "i = " << i << "; current modulo = " << current  << '\n';
  }
  if (needed_fibonacci_index <= 1){
    return needed_fibonacci_index % m;
  }
  return current;

}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_modulo(n, m) << '\n';
}
