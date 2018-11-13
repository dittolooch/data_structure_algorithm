#include <iostream>


unsigned int euclidGCD(unsigned int a, unsigned int b){
  if (b==0){
    return a;
  } else {
    unsigned int a_prime = a%b;
    return euclidGCD(b, a_prime);
  }
}

long long lcm(unsigned int a, unsigned int b){
	unsigned int gcd =  euclidGCD(a,b);
  return (long long) a*b/gcd;
}

int main() {
  unsigned int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
