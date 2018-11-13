#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
unsigned int euclidGCD(unsigned int a, unsigned int b){
  if (b==0){
    return a;
  } else {
    unsigned int a_prime = a%b;
    return euclidGCD(b, a_prime);
  }
}
int main() {
  unsigned int a, b;
  std::cin >> a >> b;
  std::cout << euclidGCD(a, b) << std::endl;
  return 0;
}
