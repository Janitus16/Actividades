#include <iostream>

void main() {
    int x, y;
    std::cout << "Introduzca el tamaño de mapa que espera generar, (x,y): ";
    std::cin >> x >> y;
    x--;
    y--;
    std::cout << "\n";

    for (int i = 0; i <= y; i++) {
        for (int j = 0; j <= x; j++) {
            if ( i == 0 || i == y || j == 0 || j == x) {
                std::cout << "#";
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}