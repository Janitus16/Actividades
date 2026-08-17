#include <iostream>

int main() {
  int num;

  std::cout << "Escriba un numero cualquiera: ";
  std::cin >> num;
  std::cout << "\n";
  if (num != 0) {
    if (num < 0) {
      std::cout << "Su numero es negativo, ";
    }
    else {
      std::cout << "Su numero es positivo, ";
    }
  }
  if((num%2)==0) {
    if (num == 0) {
      std::cout << "Su numero es el cero, asi que no puede ser par/impar." << std::endl;
    }

    

    if (num != 0) {
      std::cout << "y es par.";
    }
  }

  else {
    std::cout << "y es impar.";
  }
}
