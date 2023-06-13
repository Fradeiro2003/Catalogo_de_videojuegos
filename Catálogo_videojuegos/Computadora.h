#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include <string>
using namespace std;
//Clase componente de Rendimiento (le da las caracteristicas de una computadora a rendimiento)
class Computadora{
    private:
        string procesador, tarjetaGrafica;
        int gbRam, seleccionAlmacenamiento;
        string tiposAlmacenamiento[2] = {"SSD", "HDD"};


    public:
        Computadora();
        Computadora(string, int, int, string);
        string getDatosComputadora();

};

Computadora::Computadora(){
    procesador = "AMD Ryzen 5 5600";
    tarjetaGrafica = "AMD Radeon RX 6600 XT";
    seleccionAlmacenamiento = 1;
    gbRam = 16;

}

Computadora::Computadora(string procesador, int gbRam, int seleccionAlmacenamiento, string tarjetaGrafica){
    this->procesador = procesador; 
    this->gbRam = gbRam;
    this->seleccionAlmacenamiento = seleccionAlmacenamiento;
    this->tarjetaGrafica = tarjetaGrafica;

}

string Computadora::getDatosComputadora(){
    string texto = "Especificaciones de la computadora en la que se corre el juego\n";
    texto = texto + "----------------------------------------------------\n";
    texto = texto + "Procesador: " + procesador + "\n";
    texto = texto + "Tarjeta Gráfica: " + tarjetaGrafica + "\n";
    texto = texto + "Gb de RAM: " + to_string(gbRam) + "\n";
    texto = texto + "Tipo de almacenamiento: " + tiposAlmacenamiento[seleccionAlmacenamiento] + "\n";
    texto = texto + "----------------------------------------------------\n";

    return texto;
}
#endif