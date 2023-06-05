#ifndef VIDEJUEGO_H
#define VIDEJUEGO_H
#include <string>
#include <vector>
using namespace std;
#include "Critica.h"
#include "Rendimiento.h"

//Clase padre y compositor
class Videojuego{
    protected:
        int precioLanzamiento, nivelDificultad;
        string nombreVideojuego, fechaLanzamiento, compania;
        Rendimiento rendimiento;
        Critica critica;
        string subgeneros[21]={"Arcade", "Plataformas", "Disparos", "Peleas", "Juego de rol", "Aventura de acción", "Video interactivo", "Aventura gráfica", "Aventura conversacional", "Puzzle", "Didáctico", "Preguntas", "Musical", "Ejercicio", "Deportes", "Carreras", "Juegos de mesa", "Juegos mecánicos", "Estrategia", "Simulación"};

    public:
        Videojuego();
        Videojuego(string, string, string, int, int, Rendimiento, Critica);
        string getnombreVideojuego();
        string getFechaLanzamiento();
        int getPrecioLanzamiento();
        int getNivelDficultad();
        string getCompania();
        Rendimiento getRendimiento();
        Critica getCritica();
        virtual string getDatos();
        virtual string getSubgeneros();
        virtual vector<int> nivelSubgenerosSeleccion() = 0;

};

#endif