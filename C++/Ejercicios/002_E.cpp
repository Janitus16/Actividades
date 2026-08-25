#include <iostream>

int main() {
  short n1;
  short n2;

  std::cout << "Introduzca dos numeros:\n> ";
  std::cin >> n1;
  std::cout << "> ";
  std::cin >> n2;

  std::cout << "La suma de sus numeros es: " << n1 + n2 << std::endl;
}
