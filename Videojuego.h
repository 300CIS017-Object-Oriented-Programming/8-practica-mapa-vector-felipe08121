//
// Created by felip on 29/10/2025.
//

#ifndef INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_VIDEOJUEGO_H
#define INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_VIDEOJUEGO_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Videojuego {

private:

    string codigo;
    string nombre;
    string genero;
    int nivelDificultad;


public:

//Contructores

    Videojuego( string codigo, string nombre, string genero, int nivelDificultad);
    Videojuego();

// Gets y sets

    string getNombre();
    void setNombre( string nombre);

    string getCodigo();
    void setCodigo( string nombre);

    string getGenero();
    void setGenero(string Genero);

    int getNivelDificultad();
    void setNivelDificultad( int nivelDificultad);

    //Metodos:

    void mostrar();



};



#endif //INC_8_PRACTICA_MAPA_VECTOR_FELIPE08121_VIDEOJUEGO_H