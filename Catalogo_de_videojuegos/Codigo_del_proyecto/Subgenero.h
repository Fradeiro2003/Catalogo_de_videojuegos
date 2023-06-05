#ifndef SUBGENERO_H
#define SUBGENERO_H
#include "Videjuego.h"
#include <vector>


//Clase hija de videjuego para los subgeneros
class Subgenero : public Videojuego{
    private:
        vector<int> seleccionSubgeneros;
        int nivelAccion, nivelIngenio, nivelExploración;


    public:
        Subgenero();
        Subgenero(vector<int>, int, int, int);
        string getDatos() override;
        string getSubgeneros(int);
        vector<int> nivelSubgenerosSeleccion() override;

};

#endif