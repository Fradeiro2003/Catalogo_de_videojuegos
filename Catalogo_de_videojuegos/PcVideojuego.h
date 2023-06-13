#ifndef PCVIDEOJUEGO_H
#define PCVIDEOJUEGO_H
#include "Videjuego.h"
#include "Rendimiento.h"
#include "Critica.h"

class PcVideojuego : public Videojuego{
    private:
        Rendimiento rendimientoPc;
        vector<string> opcionesMods = {"Sí", "No", "No info"};
        int seleccionOpcionMod;
        string consolaAlternativa;

    public:
        PcVideojuego();
        PcVideojuego(string, string, int, float, Rendimiento, int);
        void setSeleccionSubgeneros(vector<int>) override;
        vector<string> getSubgeneros() override;
        void setPrecioActual(float) override;
        void setconsolaAlternativa(string) override;
        string getDatos() override;
};

PcVideojuego::PcVideojuego() : Videojuego(){
    seleccionOpcionMod = 2;
}

PcVideojuego::PcVideojuego(string nombreVideojuego, string compania, int fechaLanzamiento, float precioLanzamiento, Rendimiento rendimientoPc, int seleccionOpcionMod) : Videojuego(nombreVideojuego, compania, fechaLanzamiento, precioLanzamiento){
    this->rendimientoPc = rendimientoPc;
    this->seleccionOpcionMod = seleccionOpcionMod;
}

void PcVideojuego::setSeleccionSubgeneros(vector<int> seleccionSubgeneros){
    this->seleccionSubgeneros = seleccionSubgeneros;
}

vector<string> PcVideojuego::getSubgeneros(){
    vector<string> subgenerosSpecific;
    for (int i = 0; i < seleccionSubgeneros.size(); i++)
    {
        subgenerosSpecific.push_back(subgeneros[seleccionSubgeneros[i]-1]);
    }

    return subgenerosSpecific;
}

void PcVideojuego::setPrecioActual(float precioActual){
    this->precioActual = precioActual;
}

void PcVideojuego::setconsolaAlternativa(string consolaAlternativa){
    this->consolaAlternativa = consolaAlternativa;
}

string PcVideojuego::getDatos(){
    string text = nombreVideojuego + "\n";
    text = text + "------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    if (critica.size() > 0){
        text = text + to_string(getPunatajePromedio()) + "\n";
    }
    text = text + "Fecha de lanzamiento: " + fechaIntAString() + "\n";
    text = text + "Desarrolladora: " + compania + "\n";
    text = text + "Precio de lanzamiento: " + to_string(precioLanzamiento) + "\n";
    text = text + "Precio actual: " + to_string(precioActual) + "\n";
    text = text + "Subgéneros: ";
    for (int i = 0; i < getSubgeneros().size()-1; i++)
    {
        text = text + getSubgeneros()[i] + ", ";
    }
    if (getSubgeneros().size() > 0){
        int ultimoSub = getSubgeneros().size() - 1;
        text = text + getSubgeneros()[ultimoSub] + "\n";
    }
    text = text + rendimientoPc.getDatosRendimientoPc() + "\n";
    text = text + "Critica" + "\n-----------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < critica.size(); i++)
    {
        text = text + critica[i].getDatos();

    }
    text = text + "------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

    return text;
}



#endif