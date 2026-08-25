#include <iostream>

int main() {
  short n1;
  short n2;

  std::cout << "Introduce dos numeros: \n> ";
  std::cin >> n1;
  std::cout << "> ";
  std::cin >> n2;

  std::cout << "\nThe sum of " << n1 << " and " << n2 << " is: " << n1 + n2 << std::endl;
}
