#ifndef CRITICA_H
#define CRITICA_H
#include <vector>
//Clase componente de videjuego (sirve para presentar la critica y reseña del videjuego)
class Critica{
    private:
        vector<float> puntajes;
        vector<string> reseñas; 
    
    public:
        Critica();
        Critica(float, string);
        float puntajePromedio();

};

Critica::Critica(){
    puntajes.push_back(0);
    reseñas.push_back("No hay reseña");
}

Critica::Critica(float puntaje, string reseña){
    puntajes.push_back(puntaje);
    reseñas.push_back(reseña);
}

float Critica::puntajePromedio(){

    float suma = 0;

    for(int i=0; i<puntajes.size(); i++){
        suma = suma + puntajes[i];
    }

    return suma/puntajes.size();  
}

#endif