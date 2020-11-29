/*
Clase hecha por:
Aleksandr Morozov A00824394
*/

#include <iostream>
using namespace std;

#include "Categoria.h"

class Producto 
{
    public:
        Producto();
        Producto(string nNombre, Categoria nCategoria, double nPrecio, int nCantidad, bool nDisponibilidad, string nSKU);

        //getters
        string getNombre();
        Categoria getCategoria();
        double getPrecio();
        int getCantidad();
        bool getDisponibilidad();
        string getSKU();

        //getters
        void setNombre(string nNombre);
        void setCategoria(Categoria nCatergoria);
        void setPrecio(double nPrecio);
        void setCantidad(int nCantidad);
        void setDisponibilidad(bool nDisponibilidad);
        void setSKU(string nSKU);

        //otros
        void addCantidad(int nCantidad);
        bool subCantidad(int nCantidad);

    private:
        string nombre;
        Categoria categoria;
        double precio;
        int cantidad;
        bool disponibilidad;
        string SKU;
};

//constructores
Producto::Producto()
{

    Categoria nCategoria;
    nombre = "N/A";
    categoria = nCategoria;
    precio = 0;
    cantidad = 0;
    disponibilidad = false;
    SKU = "N/A";
}

Producto::Producto(string nNombre, Categoria nCategoria, double nPrecio, int nCantidad, bool nDisponibilidad, string nSKU)
{
    nombre = nNombre;
    categoria = nCategoria;
    precio = nPrecio;
    cantidad = nCantidad;
    disponibilidad = nDisponibilidad;
    SKU = nSKU;
}

//definir getters
string Producto::getNombre()
{
    return nombre;
}

Categoria Producto::getCategoria()
{
    return categoria;
}

double Producto::getPrecio()
{
    return precio;
}

int Producto::getCantidad()
{
    return cantidad;
}

bool Producto::getDisponibilidad()
{
    return disponibilidad;
}

string Producto::getSKU()
{
    return SKU;
}

//setters
void Producto::setNombre(string nNombre)
{
    nombre = nNombre;
}

void Producto::setCategoria(Categoria nCategoria)
{
    categoria = nCategoria;
}

void Producto::setPrecio(double nPrecio)
{
    precio = nPrecio;
}

void Producto::setCantidad(int nCantidad)
{
    cantidad = nCantidad;
}

void Producto::setDisponibilidad(bool nDisponibilidad)
{
    disponibilidad = nDisponibilidad;
}

void Producto::setSKU(string nSKU)
{
    SKU = nSKU;
}

//otros
void Producto::addCantidad(int nCantidad)
{
    cantidad += nCantidad;
}

bool Producto::subCantidad(int nCantidad)
{

        if(nCantidad <= cantidad)
        {
            cantidad -= nCantidad;
            return true;
        }
        else
        {
            cout << endl;
            cout << "***** El numero excede cantidad disponible. Solo hay " << cantidad << " disponbile. *****" << endl;
            cout << endl;
            return false; 
        }
    
}
