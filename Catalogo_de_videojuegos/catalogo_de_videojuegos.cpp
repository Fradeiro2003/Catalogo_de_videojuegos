#include <iostream>
#include <string>
using namespace std;

//Clase componente de Rendimiento (le da las caracteristicas de una computadora a rendimiento)
class Computadora{
    private:
        string procesador, tarjetaGrafica, tipoAlmacenamiento;
        int gbRam;


    public:
        Computadora();
        Computadora(string, string, int, string);


};

//Clase componente de videojuego (sirve para mostrar el rendimiento del juego)
class Rendimiento{
    private:
        string motorGrafico, API, resolucion;
        int mediaFps;
        Computadora computadora;

    public:
        Rendimiento();
        Rendimiento(int, string, string, string, Computadora);

};


//Clase componente de videjuego (sirve para presentar la critica y reseña del videjuego)
class Critica{
    private:
        int cantidadCriticos;
        int puntajeMultiple[10];
        string reseña;
    
    public:
        Critica();
        Critica(int, string);
        void setPuntajeMultiple(int);
        string puntajePromedio();

};



//Clase padre y compositor
class Videojuego{
    private:
        int precioLanzamiento;
        string nombreVideojuego, fechaLanzamiento, compania, disponibilidadPlataformas;
        Rendimiento rendimiento;
        Critica critica;

    public:
        Videojuego();
        Videojuego(string, string, string, int, Rendimiento, Critica);
        string getnombreVideojuego();
        string getFechaLanzamiento();
        int getPrecioLanzamiento();
        string getCompania();
        Rendimiento getRendimiento();
        Critica getCritica();
        string getDatos();

};


//Clase hija de videjuego para los juegos de accion
class Accion : public Videojuego{
    private:
        string subgeneros[4]={"Arcade", "Plataformas", "Disparos", "Peleas"};
        int nivelDificultad, seleccionSubgenero, nivelAccion;

    public:
        Accion();
        Accion(int, int, int);
        string getDatos();
        string getSubgeneros();

};


//Clase hija de videjuego para los juegos de exploracion
class Exploracion : public Videojuego{
    private:
        string subgeneros[5]={"Juego de rol", "Aventura de acción", "Video interactivo", "Aventura gráfica", "Aventura conversacional"};
        int nivelDificultad, seleccionSubgenero, nivelExploracion;

    public:
        Exploracion();
        Exploracion(int, int, int);
        string getDatos();
        string getSubgeneros();

};


//Clase hija de videjuego para los juegos de ingenio
class Ingenio : public Videojuego{
    private:
        string subgeneros[5]={"Puzzle", "Didáctico", "Preguntas", "Musical", "Ejercicio"};
        int nivelDificultad, seleccionSubgenero, nivelIngenio;

    public:
        Ingenio();
        Ingenio(int, int, int);
        string getDatos();
        string getSubgeneros();

};


//Clase hija de videjuego para los juegos de deportes y juegos de mesa
class Deportes : public Videojuego{
    private:
        string subgeneros[4]={"Deportes", "Carreras", "Juegos de mesa", "Juegos mecánicos"};
        int nivelDificultad, seleccionSubgenero, nivelParecidoRealidad;

    public:
        Deportes();
        Deportes(int, int, int);
        string getDatos();
        string getSubgeneros();

};


//Clase hija de videjuego para los juegos de estrategia
class Estrategia : public Videojuego{
    private:
        string subgeneros[2]={"Estrategia", "Simulación"};
        int nivelDificultad, seleccionSubgenero, nivelConcentracion;

    public:
        Estrategia();
        Estrategia(int, int, int);
        string getDatos();
        string getSubgeneros();

};