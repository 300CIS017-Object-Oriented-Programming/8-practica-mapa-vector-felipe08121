#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;


void menu() {

cout << endl;
cout << "1. Mostrar video juegos del jugador. " << endl;
cout << "" << endl;
cout << "" << endl;
cout << "Elija la opcion que desea escoger: ";



}




void menuSwitch() {
int opcion;



    do {
        menu();
        cin >> opcion;

        switch (opcion) {

            case -1: {
                cout << "Saliendo..... " << endl;
                break;
            }

            case 1:{
                break;

            }

            case 2: {
                break;
            }

            default: {
                cout<< "Ingrese una opcion correcta." << endl ;
            }
        }
    }
while (opcion != -1);
}


int main() {

    menuSwitch();
    cout << endl << "Ha salido del menu del torneo. " << endl;

    return 0;
}

