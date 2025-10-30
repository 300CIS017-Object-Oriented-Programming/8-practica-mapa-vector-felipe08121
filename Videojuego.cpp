//
// Created by felip on 29/10/2025.
//

#include "Videojuego.h"

// Contructores:

Videojuego::Videojuego() {
    this-> nombre = "Sin nombre.";
    this-> codigo = "Sin genero";
    this-> genero = "Sin genero";
    this-> nivelDificultad = 0 ; // 0 es igual a no tener nivel de dificultad.
}

Videojuego::Videojuego( string codigo, string nombre, string genero, int nivelDificultad) {
    this-> codigo = codigo;
    this-> nombre = nombre;
    this-> genero = genero;
    this-> nivelDificultad = nivelDificultad;
}

// gets y sets:

string Videojuego::getCodigo() {
    return codigo;
}

void Videojuego::setCodigo( string codigo) {
    this-> codigo = codigo;
}


string Videojuego::getNombre() {
    return nombre;
}

void Videojuego::setNombre(string nombre) {
    this-> nombre =nombre;
}

string Videojuego::getGenero() {
    return genero;
}

void Videojuego::setGenero( string genero) {
    this-> genero = genero;
}

int Videojuego::getNivelDificultad() {
    return nivelDificultad;
}

void Videojuego::setNivelDificultad( int nivelDificultad) {
    this-> nivelDificultad = nivelDificultad;
}

//Metodos

void Videojuego::mostrar() {
    cout << endl  << "====== Informacion del videojuego =====" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Nivel de dificultad: " << nivelDificultad << endl;
    cout << "===== ================== =====" << endl;
}