#include <iostream>
#ifndef CONSOLAVIDEOJUEGO_H
#define CONSOLAVIDEOJUEGO_H
#include "Videjuego.h"
#include "Rendimiento.h"
#include "Critica.h"

class ConsolaVideojuego : public Videojuego{
    private:
        Rendimiento rendimientoConsola;
        vector<string> consolas = {"PlayStation 4", "PlayStation 5", "Xbox One", "Xbox Series S", "Xbox series X", "Nintendo Switch", "Otra", "No info"};
        int seleccionConsola;
        string edicionConsola;
        string consolaAlternativa;

    public:
        ConsolaVideojuego();
        ConsolaVideojuego(string, string, int, float, Rendimiento, int, string);
        void setSeleccionSubgeneros(vector<int>) override;
        vector<string> getSubgeneros() override;
        void setPrecioActual(float) override;
        void setconsolaAlternativa(string) override;
        string getDatos() override;

};

ConsolaVideojuego::ConsolaVideojuego(){
    seleccionConsola = 8;
    edicionConsola = "No info";
}

ConsolaVideojuego::ConsolaVideojuego(string nombreVideojuego, string compania, int fechaLanzamiento, float precioLanzamiento, Rendimiento rendimientoConsola, int seleccionConsola, string edicionConsola) : Videojuego(nombreVideojuego, compania, fechaLanzamiento, precioLanzamiento){
    this->rendimientoConsola = rendimientoConsola;
    this->seleccionConsola = seleccionConsola;
    this->edicionConsola = edicionConsola;
}

void ConsolaVideojuego::setSeleccionSubgeneros(vector<int> seleccionSubgeneros){
    this->seleccionSubgeneros = seleccionSubgeneros;
}

vector<string> ConsolaVideojuego::getSubgeneros(){
    vector<string> subgenerosSpecific;
    for (int i = 0; i < seleccionSubgeneros.size(); i++)
    {
        subgenerosSpecific.push_back(subgeneros[seleccionSubgeneros[i]-1]);
    }

    return subgenerosSpecific;
}

void ConsolaVideojuego::setPrecioActual(float precioActual){
    this->precioActual = precioActual;
}

void ConsolaVideojuego::setconsolaAlternativa(string consolaAlternativa){
    this->consolaAlternativa = consolaAlternativa;
}

string ConsolaVideojuego::getDatos(){
    string text = nombreVideojuego + "\n";
    text = text + "------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    if (critica.size() > 0){

        text = text + "Puntaje promedio: " + to_string(getPunatajePromedio()) + "\n";
    }
    text = text + "Fecha de lanzamiento: " + fechaIntAString() + "\n";
    text = text + "Desarrolladora: " + compania + "\n";
    text = text + "Consola: ";
    if (seleccionConsola == 7)
    {
        text = text + consolaAlternativa;
    }
    else{
        text = text + consolas[seleccionConsola-1];
    }
    text = text + "    Edición: " + edicionConsola + "\n";
    text = text + "Precio de lanzamiento: " + to_string(precioLanzamiento) + "\n";
    text = text + "Precio actual: " + to_string(precioActual) + "\n";
    text = text + "Subgéneros: ";
    for (int i = 0; i < getSubgeneros().size()-1; i++)
    {
        text = text + getSubgeneros()[i] + ", ";
    }
    int ultimoSub = getSubgeneros().size() - 1;
    text = text + getSubgeneros()[ultimoSub] + "\n";
    text = text + rendimientoConsola.getDatosRendimientoConsola() + "\n";
    text = text + "Critica" + "\n-----------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < critica.size(); i++)
    {
        text = text + critica[i].getDatos();

    }
    text = text + "------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

    return text;
}

#endif