/*
Clase hecha por:
Andrés Fuentes A01177466
*/

#ifndef ORDEN_H
#define ORDEN_H

#include "Producto.h"
#include "Fecha.h"

class Orden
{
    public:
        //Constructores
        Orden();
        Orden(Producto nProducto, Fecha nFecha, string nNombre, string nDireccion, string nColonia, string nMunicipio, int nCantidad);

        //getters
        Producto getProducto();
        Fecha getFecha();
        string getNombre();
        string getDireccion();
        string getColonia();
        string getMunicipio();
        int getCantidad();

        //setters
        void setProducto(Producto nProducto);
        void setFecha(Fecha nFecha);
        void setNombre(string nNombre);
        void setDireccion(string nDireccion);
        void setColonia(string nColonia);
        void setMunicipio(string nMunicipio);
        void setCantidad(int nCantidad);

    private:
        Producto producto;
        Fecha fecha;
        string nombre;
        string direccion;
        string colonia;
        string municipio;
        int cantidad;
};

//Constructores
Orden::Orden()
{
    Producto nProducto;
    producto = nProducto;
    Fecha nFecha;
    fecha = nFecha;
    nombre = "N/A";
    direccion = "N/A";
    colonia = "N/A";
    municipio = "N/A";
    cantidad = 0;
}

Orden::Orden(Producto nProducto, Fecha nFecha, string nNombre, string nDireccion, string nColonia, string nMunicipio, int nCantidad)
{
    producto = nProducto;
    fecha = nFecha;
    nombre = nNombre;
    direccion = nDireccion;
    colonia = nColonia;
    municipio = nMunicipio;
    cantidad = nCantidad;
}

//Getters
Producto Orden::getProducto()
{
    return producto;
}

Fecha Orden::getFecha()
{
    return fecha;
}

string Orden::getNombre()
{
    return nombre;
}

string Orden::getDireccion()
{
    return direccion;
}

string Orden::getColonia()
{
    return colonia;
}

string Orden::getMunicipio()
{
    return municipio;
}

int Orden::getCantidad()
{
    return cantidad;
}

//Setters
void Orden::setProducto(Producto nProducto)
{
    producto = nProducto;
}

void Orden::setFecha(Fecha nFecha)
{
    fecha = nFecha;
}

void Orden::setNombre(string nNombre)
{
    nombre = nNombre;
}

void Orden::setDireccion(string nDireccion)
{
    direccion = nDireccion;
}

void Orden::setColonia(string nColonia)
{
    colonia = nColonia;
}

void Orden::setMunicipio(string nMunicipio)
{
    municipio = nMunicipio;
}

void Orden::setCantidad(int nCantidad)
{
    cantidad = nCantidad;
}

#endif // ORDEN_H

