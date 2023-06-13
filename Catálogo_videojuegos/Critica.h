#ifndef CRITICA_H
#define CRITICA_H
#include <vector>
#include <string>
using namespace std;
//Clase componente de videjuego (sirve para presentar la critica y reseña del videjuego)
class Critica{
    private:
        float puntaje;
        string reseña; 
        string nombre;
    
    public:
        Critica();
        Critica(float, string, string);
        Critica operator+ (Critica);
        float getPuntaje();
        string getDatos();

};

Critica::Critica(){
    puntaje = 0;
    reseña = "No info";
    nombre = "Desconocido";
}

Critica::Critica(float puntaje, string reseña, string nombre){
    this->puntaje = puntaje;
    this->reseña = reseña;
    this->nombre = nombre;
}

Critica Critica::operator+(Critica c){
    Critica sumaPuntaje;
    sumaPuntaje.puntaje = this->puntaje + c.puntaje;
    return sumaPuntaje;
} 


float Critica::getPuntaje(){
    return puntaje;
}

string Critica::getDatos(){
    string texto = "\nCritica de " + nombre + "\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";
    texto = texto + "Valoración: " + to_string(puntaje) + "\n";
    texto = texto + "Reseña\n" + "----------------------------------------------------\n" + reseña + "\n----------------------------------------------------\n";
    texto = texto + "--------------------------------------------------------------------------------------------------------\n";

    return texto;
}



#endif

