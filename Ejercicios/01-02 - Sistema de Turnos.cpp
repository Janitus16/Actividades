#include <iostream>

int main() {

    short vida_1 = 100;
    short vida_2 = 100;
    
    do {
        //turno j1
        vida_2 -= 5;
        std::cout << "\nJugador 1 ataca a jugador 2, vida jugador 2: " << vida_2 << std::endl;

        //turno j2
        vida_1 -= 10;
        std::cout << "\nJugador 2 ataca a jugador 1, vida jugador 1: " << vida_1 << std::endl;
    } while (vida_1 > 0 && vida_2 > 0);

    if (vida_1 <= 0) {
        std::cout << "\nJugador 2 ha ganado la partida." << std::endl;
    }
    
    else {
        std::cout << "\nJugador 1 ha ganado la partida." << std::endl;
    }

    return 0;
}