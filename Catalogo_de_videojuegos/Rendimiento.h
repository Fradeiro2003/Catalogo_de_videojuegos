#ifndef RENDIMIENTO_H
#define RENDIMIENTO_H
#include <vector>
#include "Computadora.h"
//Clase componente de videojuego (sirve para mostrar el rendimiento del juego)
class Rendimiento{
    private:
        string presetGrafico, resolucion;
        int mediaFps;
        Computadora computadora;


    public:
        Rendimiento();
        Rendimiento(int, string, string);
        Rendimiento(int, string, string, string, int, int, string);
        string getDatosRendimientoConsola();
        string getDatosRendimientoPc();

};

Rendimiento::Rendimiento(){
    presetGrafico = "No info";
    resolucion = "No info";
    mediaFps = 0;

}

Rendimiento::Rendimiento(int mediaFps, string presetGrafico, string resolucion){
    this->mediaFps = mediaFps;
    this->presetGrafico = presetGrafico;
    this->resolucion = resolucion;
}

Rendimiento::Rendimiento(int mediaFps, string presetGrafico, string resolucion, string procesador, int gbRam, int seleccionAlmacenamiento, string tarjetaGrafica){
    this->mediaFps = mediaFps;
    this->presetGrafico = presetGrafico;
    this->resolucion = resolucion;
    Computadora computadoraPersonalizada(procesador, gbRam, seleccionAlmacenamiento, tarjetaGrafica);
    computadora = computadoraPersonalizada;

}

//Despliegue de datos para objetos de consola
string Rendimiento::getDatosRendimientoConsola(){
    setlocale(LC_CTYPE, "Spanish");
    string texto = "Rendimiento\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";
    texto = texto + "Resolución del juego: " + resolucion + "\n";
    texto = texto + "Configuración gráfica predeterminada del juego: " + presetGrafico + "\n";
    texto = texto + "Media de FPS: " + to_string(mediaFps) + "\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";
    return texto;
}

//Despliegue de datos para objetos de Pc
string Rendimiento::getDatosRendimientoPc(){
    string texto = "Rendimiento\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";
    texto = texto + "Resolución del juego: " + resolucion + "\n";
    texto = texto + "Configuración gráfica predeterminada del juego: " + presetGrafico + "\n";
    texto = texto + "Media de FPS: " + to_string(mediaFps) + "\n";
    texto = texto + "\n" + computadora.getDatosComputadora() + "\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";

    return texto;
}


#endif