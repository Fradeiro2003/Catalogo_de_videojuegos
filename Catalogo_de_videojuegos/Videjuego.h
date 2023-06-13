#ifndef VIDEJUEGO_H
#define VIDEJUEGO_H
#include <string>
#include <vector>
using namespace std;
#include "Critica.h"

//Clase padre y compositor
class Videojuego{
    protected:
        //Parámetros modificables con el constructor
        int fechaLanzamiento;
        float precioLanzamiento;
        string nombreVideojuego, compania;
        vector<Critica> critica;
        //Parámetros no modificables con el constructor
        float precioActual;
        const vector<string> subgeneros={"Arcade", "Plataformas", "Disparos", "Peleas", "Juego de rol", "Aventura de acción", "Video interactivo", "Aventura gráfica", "Aventura conversacional", "Puzzle", "Didáctico", "Preguntas", "Musical", "Ejercicio", "Deportes", "Carreras", "Juegos de mesa", "Juegos mecánicos", "Estrategia", "Simulación", "No info"};
        vector<int> seleccionSubgeneros;


    public:
        Videojuego();
        Videojuego(string, string, int, float);
        string getNombreVideojuego();
        int getFechaLanzamiento();
        float getPrecioLanzamiento();
        float getPunatajePromedio();
        virtual void setSeleccionSubgeneros(vector<int>) = 0; 
        virtual vector<string> getSubgeneros();
        virtual void setPrecioActual(float) = 0;
        virtual void setconsolaAlternativa(string) = 0;
        virtual string getDatos() = 0;
        string fechaIntAString();
        void agregarCritica(Critica);

};

Videojuego::Videojuego(){
    fechaLanzamiento = 0;
    precioLanzamiento = 2;
    nombreVideojuego = "No info";
    compania = "No info";
    Critica criticaDefault;
    critica.push_back(criticaDefault);
    seleccionSubgeneros.push_back(20);
}

Videojuego::Videojuego(string nombreVideojuego, string compania, int fechaLanzamiento, float precioLanzamiento){
    this->nombreVideojuego = nombreVideojuego;
    this->compania = compania;
    this->fechaLanzamiento = fechaLanzamiento;
    this->precioLanzamiento = precioLanzamiento;
}

string Videojuego::getNombreVideojuego(){
    return nombreVideojuego;
}

int Videojuego::getFechaLanzamiento(){
    return fechaLanzamiento;
}

float Videojuego::getPrecioLanzamiento(){
    return precioLanzamiento;
}

float Videojuego::getPunatajePromedio(){
    Critica c1;
    for(int i = 0; i < critica.size(); i++){
        c1 = c1 + critica[i];
        
    }

    float promedio = c1.getPuntaje()/critica.size();
    return promedio;
} 

vector<string> Videojuego::getSubgeneros(){
    return subgeneros;
}



string Videojuego::fechaIntAString(){
    string fechaString;
    fechaString = to_string(fechaLanzamiento/1000000) + "/" + to_string((fechaLanzamiento%1000000)/10000) + "/" + to_string((fechaLanzamiento%1000000)%10000);
    return fechaString;
}

void Videojuego::agregarCritica(Critica _critica){
    critica.push_back(_critica);
}




#endif