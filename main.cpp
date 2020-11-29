/*
Main desarollado por ambos:
Aleksandr Morozov A00824394
Andrés Fuentes A01177466
*/

#include <iostream>
#include <fstream>
using namespace std;

#include "Orden.h"

//funciones del programa
void cargaProductos(Producto productosARR[], int &productCount);  // Aleksandr Morozov A00824394
void muestraProductos(Producto productosARR[], int productCount); // Aleksadnr Morozov A00824394
void restock(Producto productosARR[], int productCount);  //Andrés Fuentes A01177466
void agregarOrden(Orden ordenARR[], Producto productosARR[], int productCount, int &orderCount); //Realizando por ambos
int buscaProducto(Producto productosARR, int productCount); //Andrés Fuentes A01177466
void muestraOrdenes(Orden ordenARR[], Producto productosARR[], int productCount, int orderCount); //Realizando por ambos

int main(void)
{
    char opcion;
    Producto productoARR[20];
    Orden ordenARR[20];
    int cantidadProductos;
    int cantidadOrden = 0;
    cargaProductos(productoARR, cantidadProductos);

    

    
 
    //while loop condition variable
    bool run;
    run = true;

    cout << "************************" << endl; 
    cout << "BIENVENIDO A BEBIDAS.COM" << endl;
    cout << "************************" << endl; 
    cout << endl;

    while (run)
    {
        cout << "Seleccione de la siguiente lista: " << endl;
        cout << "a) Mostrar productos" << endl;
        cout << "b) Cargar productos" << endl;
        cout << "c) Agregar orden" << endl;
        cout << "d) Ver ordenes" << endl;
        cout << "t) Terminar programa" << endl;
        cout << "--> ";
        cin >> opcion;
        switch(opcion)
        {
            case 'a':
                cout << endl;
                muestraProductos(productoARR, cantidadProductos);
                break;

            case 'b':
                cout << endl;
                restock(productoARR, cantidadProductos);
                break;

            case 'c':
                cout << endl;
                
                agregarOrden(ordenARR, productoARR, cantidadProductos, cantidadOrden);
                break;

            case 'd':
                cout << endl;
                muestraOrdenes(ordenARR, productoARR, cantidadProductos, cantidadOrden);
                break;
		
            case 't':
                cout << endl;
                cout << "***** SESSIÓN TERMINADA *****" << endl;
                cout << endl;
                run = false;
                break;

            default:
                cout << endl;
                cout << "***** Favor de ingresar un valor valido: *****" << endl;
                cout << endl;
                break;
        }
        
    }

    // Successful return
    return 0;
};


//funcion carga datos del archivo, almanece en arreglo indicado.
void cargaProductos(Producto productosARR[], int &productCount)
{
    //definir variables
    string nombreProducto;
    string nombreCatergoria;
    double precio;
    int cantidad;
    string SKU;

    ifstream file;
    file.open("Productos.txt");

    productCount = 0;
    while (file >> nombreProducto >> nombreCatergoria >> precio >> cantidad >> SKU)
    {
        productosARR[productCount].setNombre(nombreProducto);
        productosARR[productCount].setCategoria(nombreCatergoria);
        productosARR[productCount].setPrecio(precio);
        productosARR[productCount].setCantidad(cantidad);
        productosARR[productCount].setSKU(SKU);
        productCount++;
    }

    file.close();
};

void muestraProductos(Producto productosARR[], int productCount)
{
    for(int i=0; i < productCount; i++)
    {
        cout << "Catergoria del producto: " << productosARR[i].getCategoria().getNombre() << endl;
        cout << "Nombre del producto: " << productosARR[i].getNombre() << "  // Precio: " << productosARR[i].getPrecio() << endl;
        cout << "Disponible a la venta: " << productosARR[i].getCantidad() << endl;
        cout << "SKU: " << productosARR[i].getSKU() << endl;
        cout << "  " << endl;
    }  
};

int buscaProducto(Producto productosARR[], int productCount)
{
    string producto;
    int posicionProducto;

    bool verdadero = true;
    while (verdadero)
    {
        cout << endl;
        cout << "Productos Disponibles: " << endl;
        for(int i = 0; i < productCount; i++)
        {
            cout << productosARR[i].getNombre() << endl;
        }

        cout << "Favor de ingresar nombre de producto:" << endl;
        cout << "--> ";
        cin >> producto;

        for(int i=0; i < productCount; i++)
        {
            if (productosARR[i].getNombre() == producto)
            {
                verdadero = false;
                posicionProducto = i;
                break;
            }
            else if (productCount == i+1)
            {
                cout << endl;
                cout << "***** No hay un producto que se llame: " << producto << ". Favor de ingresar el nombre exacto. *****";
                cout << endl;
            }
        }
    }
    return posicionProducto;
};

void restock(Producto productosARR[], int productCount)
{   
    int cantidad;
    //buscar el index del producto
    int posicionProducto;
    posicionProducto = buscaProducto(productosARR, productCount);

    cout << "¿Cuántos productos quieres agregar al invertario de:  " << productosARR[posicionProducto].getNombre() << "?" << endl;
    cout << "--> ";
    cin >> cantidad;
    productosARR[posicionProducto].addCantidad(cantidad);
    cout << endl;
    cout << "***** ¡Movimiento Exitoso! *****"<< endl;
    cout << endl;
}

void agregarOrden(Orden ordenARR[], Producto productosARR[], int productCount, int &orderCount) 
{
    int cantidad;
    int posicionProducto;

    string nombre;
    string direccion;
    string colonia;
    string municipio;
    int dd;
    int mm;
    int aaaa;

    posicionProducto = buscaProducto(productosARR, productCount);
    
    cout << "¿Cuántos " << productosARR[posicionProducto].getNombre() << " se ordenaron?" << endl;
    cout << "--> ";
    cin >> cantidad;
    cin.ignore();

    bool revisar = productosARR[posicionProducto].subCantidad(cantidad);

    if (revisar == false)
	{
        return;
	}	

    ordenARR[orderCount].setCantidad(cantidad);

    cout << "Nombre del cliente: ";
    getline(cin,nombre);
    ordenARR[orderCount].setNombre(nombre);

    cout << "Dirección: ";
    getline(cin,direccion);
    ordenARR[orderCount].setDireccion(direccion);
    cout << "Colonia: ";
    getline(cin,colonia);
    ordenARR[orderCount].setColonia(colonia);
    cout << "Municipio: ";
    getline(cin,municipio);
    ordenARR[orderCount].setMunicipio(municipio);
    cout << "Día en el que se ordenó el producto: ";
    cin >> dd;
    cin.ignore();
    cout << "Mes en el que se ordenó el producto: ";
    cin >> mm;
    cout << "Año en el que se ordenó el producto: ";
    cin >> aaaa;

    Fecha nFecha(dd,mm,aaaa);
    cout<<orderCount<<endl; 
    ordenARR[orderCount].setFecha(nFecha);
    
  
    Producto nProducto;
    ordenARR[orderCount].setProducto(productosARR[posicionProducto]);
    

    orderCount++;
    cout << endl;
    cout << "***** ¡Movimiento Exitoso! *****" << endl;
    cout << endl;
}

void muestraOrdenes(Orden ordenARR[], Producto productosARR[], int productCount, int orderCount)
{
    if (orderCount - 1 == -1)
    {
        cout << endl;
        cout << "***** No hay ninguna orden registrada en el sistema. *****" << endl;
        cout << endl;
        return;
    }
    
    for(int i = 0; i < orderCount; i++)
    {  
        cout << "ORDEN #" << i+1 << endl;
        cout << "Nombre del cliente: " << ordenARR[i].getNombre() << " || " << "Producto ordenado: " << ordenARR[i].getProducto().getNombre() << " || Cantidad: " << ordenARR[i].getCantidad() << endl;
        cout << "Dirección del cliente: " << endl;
        cout << ordenARR[i].getDireccion() << ", " << ordenARR[i].getColonia() << ", " << ordenARR[i].getMunicipio() << endl;
        ordenARR[i].getFecha().imprime();
        cout << endl;
            
    } 

}

