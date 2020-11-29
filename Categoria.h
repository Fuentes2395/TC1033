/*
Clase hecha por:
Aleksandr Morozov A00824394
*/

#include <iostream>
using namespace std;

class Categoria
{
    public:
        Categoria();
        Categoria(string nNombre);
        string getNombre();
        void setNombre(string nNombre);

    private:
        string nombre;
};

//constructores
Categoria::Categoria()
{
    nombre = "N/A";
}

Categoria::Categoria(string nNombre)
{
    nombre = nNombre;
}

//getters
string Categoria::getNombre()
{
    return nombre;
}

//setters
void Categoria::setNombre(string nNombre)
{
    nombre = nNombre;
}


