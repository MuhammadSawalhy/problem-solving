#include <iostream>

void handle(unsigned long n) {
  bool status = false;

  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0) {
      status = !status;
      std::cout << "yes: "<<i << std::endl;
    } else {
      std::cout << "no: "<<i << std::endl;
    }
  }

  status = !status;

  std::cout << "-------------" << std::endl;
  if (status) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
}

int main () {
  unsigned long n = 4294705156;
  handle(n);
  // while (std::cin >> n && n != 0) {
  //   handle(n);
  // }
  return 0;
}
