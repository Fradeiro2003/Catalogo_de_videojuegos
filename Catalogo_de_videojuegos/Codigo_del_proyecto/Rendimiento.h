#ifndef RENDIMIENTO_H
#define RENDIMIENTO_H
#include "Computadora.h"
//Clase componente de videojuego (sirve para mostrar el rendimiento del juego)
class Rendimiento{
    private:
        string motorGrafico, API, resolucion;
        int mediaFps;
        Computadora computadora;

    public:
        Rendimiento();
        Rendimiento(int, string, string, string, string, int, int, string);
        string getDatosRendimiento();

};

Rendimiento::Rendimiento(){
    motorGrafico = "No info";
    API = "No info";
    resolucion = "No info";
    mediaFps = 0;
}

Rendimiento::Rendimiento(int mediaFps, string motorGrafico, string API, string resolucion, string procesador, int gbRam, int seleccionAlmacenamiento, string tarjetaGrafica){
    this->mediaFps = mediaFps;
    this->motorGrafico = motorGrafico;
    this->API = API;
    this->resolucion = resolucion;
    Computadora computadoraPersonalizada(procesador, gbRam, seleccionAlmacenamiento, tarjetaGrafica);
    computadora = computadoraPersonalizada;

}

string Rendimiento::getDatosRendimiento(){
    string texto = "Rendimiento\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";
    texto = texto + "Resolución del juego: " + resolucion + "\n";
    texto = texto + "Motor gráfico del juego: " + motorGrafico + "\n";
    texto = texto + "APi en la que se corre el juego: " + API + "\n";
    texto = texto + "Media de FPS: " + to_string(mediaFps) + "\n";
    texto = texto + "\n" + computadora.getDatosComputadora() + "\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";

    return texto;
}



#endif