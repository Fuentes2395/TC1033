/*
Clase hecha por:
Andrés Fuentes A01177466
*/

#include <iostream>
using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(int dd, int mm, int aaaa);

        //getters
        int getDia();
        int getMes();
        int getAnio();
        //setters
        void setDia(int nDD);
        void setMes(int nMM);
        void setAnio(int nAAAA);
        //extra
        void imprime();

    private:
        int dd, mm, aaaa;  
};

Fecha::Fecha()
{
    dd = 00;
    mm = 00;
    aaaa= 0000;
}

Fecha::Fecha(int nDD, int nMM, int nAAAA)
{
    dd = nDD;
    mm = nMM;
    aaaa = nAAAA;
}

//getters
int Fecha::getDia()
{
    return dd;
}

int Fecha::getMes()
{
    return mm;
}

int Fecha::getAnio()
{
    return aaaa;
}

//setters
void Fecha::setDia(int nDD)
{
    dd = nDD;
}

void Fecha::setMes(int nMM)
{
    mm = nMM;
}

void Fecha::setAnio(int nAAAA)
{
    aaaa = nAAAA;
}


//extra

void Fecha::imprime()
{
    cout << dd << "/" << mm << "/" << aaaa << endl;
}