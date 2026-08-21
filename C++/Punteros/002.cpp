/*
2. Calculadora simple: pide dos números y una operación (+, -, *, /), gestiona la división por cero.
*/

#include <iostream>

void SUMA(int n1, int n2) {
  std::cout << "Resultado: " << n1 << " + " << n2 << " = " << n1 + n2;
}

void RESTA(int n1, int n2) {
  std::cout << "Resultado: " << n1 << " - " << n2 << " = " << n1 - n2;
}

void MULTIPLICACIÓN(int n1, int n2) {
  std::cout << "Resultado: " << n1 << " * " << n2 << " = " << n1 * n2;
}

void DIVISIÓN(int n1, int n2) {
  do {
    if (n2 <= 0) {
      std::cout << "El divisor escojido no puede calcularse, porque no es valido, porfabor pruebe con otro numero o escriba 0 para salir del programa: \n> ";
      std::cin >> n2;
    }
    else {
      std::cout << "Resultado: " << n1 << " / " << n2 << " = " << n1 / n2;
      n2 = 0;
    }
  } while (n2 != 0);
}

int main() {
  int num1;
  int num2;
  short selecc;
 
  std::cout << "Introduce 2 numeros: \n> ";
  std::cin >> num1;
  std::cout << "> ";
  std::cin >> num2;

  do {
    std::cout << "\nIntroduce que tipo de operación quiere realizar:\n· 1 - SUMA\n· 2 - RESTA\n· 3 - MULTIPLICACIÓN\n· 4 - DIVISIÓN\n> ";
    std::cin >> selecc;

    system("clear");

    if (selecc == 1) {
      SUMA(num1, num2);
      selecc = 0;
    }
    else if (selecc == 2) {
      RESTA(num1, num2);
      selecc = 0;
    }
    else if (selecc == 3) {
      MULTIPLICACIÓN(num1, num2);
      selecc = 0;
    }
    else if (selecc == 4) {
      DIVISIÓN(num1, num2);
      selecc = 0;
    }
    else {
      std::cout << "Usted no ha introducido un numero de operación correcto, porfabor, vuelva a seleccionar.\n";
    }
  } while (selecc >= 1 && selecc >= 4);
}
