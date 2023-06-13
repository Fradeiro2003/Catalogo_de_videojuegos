#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <fstream>
#include "Videjuego.h"
#include "PcVideojuego.h"
#include "ConsolaVideojuego.h"
#include "Rendimiento.h"
#include "Critica.h"
using namespace std;


int main(){
    //Vector videojuegos que recibe punteros de tipo Videojuego para polimorfismo
    vector<Videojuego*> videojuegos;
    string variableSaltar; //Variable que se usa para no saltar cin importantes en el código
    int opcion1;
    int opcion2;
    int opcionGral1;
    int opcionGral2;
    //Parámetros para el constructor
    int fechaLanzamiento = 0;
    float precioLanzamiento;
    string nombreVideojuego, compania;
    float precioActual;
    string presetGrafico, resolucion;
    int mediaFps;
    string procesador;
    int gbRam;
    int seleccionAlmacenamiento;
    string tarjetaGrafica;
    int seleccionOpcionMod;
    int seleccionConsola;
    string edicionConsola;
    vector<int> seleccionSubgeneros;
    int subgenero = 1;
    float puntaje;
    string reseña;
    string consolaAlternativa;

    int dia = fechaLanzamiento/1000000;
    int mes = (fechaLanzamiento%1000000)/10000;
    int año = (fechaLanzamiento%1000000)%10000;

    cout << "Bienvenido al catálogo de videojuegos" << endl << "Por favor, ingrese su nombre: ";
    string nombreUsuario;
    getline(cin, nombreUsuario);
    cout << endl << "Muchas gracias " << nombreUsuario << endl << endl;
    //Menu
    do{
        cout << "Menú" << endl << "------------------------------------------" << endl;
        cout << "1. Agregar videojuego" << endl;
        cout << "2. Visualizar o modificar videojuego" << endl;

        cout << "3. Salir del catálogo" << endl << "------------------------------------------" << endl;
        cout << "Seleccione la opción deseada: " << endl;
        cin >> opcion1;
        switch (opcion1) {
            case 1: {
                cout << "----------" << endl << "Desea agregar un videojuego de: " << endl << endl;
                cout << "1. Pc" << endl;
                cout << "2. Consola" << endl;
                cout << "3. Si desea salir al menu principal" << endl << "----------" <<endl;
                cout << "Seleccione la opción deseada: " << endl;
                cin >> opcion2;
                switch (opcion2){
                    //videojuego de Pc
                    case 1: {
                        getline(cin, variableSaltar);
                        cout << "---Ingrese los siguientes datos---" << endl;
                        cout << "Datos generales del juego: " << endl;
                        cout << "Nombre del videojuego: ";
                        getline(cin, nombreVideojuego);
                        cout << endl;
                        cout << "Empresa desarrolladora del videojuego: ";
                        getline(cin, compania);
                        cout << endl;
                        cout << "Fecha de lanzamiento del videojuego (Escribe la fecha como un solo entero en formato ddmmaaaa): ";
                        cin >> fechaLanzamiento;
                        while (((dia > 31)&&(dia < 1)) || ((mes > 12)&&(dia < 1)) || ((año > 9999)&&(dia < 0)))
                        {
                            cout << "Fecha no válida, intenta de nuevo: ";
                            cin >> fechaLanzamiento;
                        }
                        cout << endl;
                        cout << "Precio de lanzamiento del videojuego: ";
                        cin >> precioLanzamiento;
                        cout << endl;
                        cout << "¿El videojuego admite mods?" << endl;
                        cout << "1. Sí" << endl << "2. No" << endl <<"3. Se desconoce" <<endl << "Selección: ";
                        cin >> seleccionOpcionMod;
                        cout << endl << endl;
                        cout << "Datos de rendimiento del juego: " << endl;
                        cout << "Media de FPS: ";
                        cin >> mediaFps;
                        cout << endl;
                        cout << "Configuración gráfica predeterminada del juego: ";
                        getline(cin, variableSaltar);
                        getline(cin, presetGrafico);
                        cout << endl;
                        cout << "Resolución del juego: ";
                        getline(cin, resolucion);
                        cout << endl;
                        cout << "Procesador de la Pc: ";
                        getline(cin, procesador);
                        cout << endl;
                        cout << "Cantidad de Gb de RAM de la Pc: ";
                        cin >> gbRam;
                        cout << endl;
                        cout << "¿Qué tipo de almacenamiento tiene la Pc: ";
                        cout << "1. SSD" << endl << "2. HDD" << endl << "Selección: ";
                        cin >> seleccionAlmacenamiento;
                        cout << endl;
                        cout << "Tarjeta gráfica de la Pc: ";
                        getline(cin, tarjetaGrafica);
                        getline(cin, variableSaltar);
                        cout << endl;

                        //Agregamos objeto a vector de videojuegos
                        videojuegos.push_back(new PcVideojuego(nombreVideojuego, compania, fechaLanzamiento, precioLanzamiento, Rendimiento(mediaFps, presetGrafico, resolucion, procesador, gbRam, seleccionAlmacenamiento, tarjetaGrafica), seleccionOpcionMod));

                        //Se crea vector con subgenero para llamar al método setSeleccionSubgeneros que recibe un vector con subgeneros tipo string 
                        cout << "Selecciona los subgéneros del videojuego (teclee 0 para dejar de almacenar subgeneros): " << endl;
                        for(int i=0; i < 20; i++){
                            cout << "  " << i+1 << ". " << videojuegos[videojuegos.size()-1]->Videojuego::getSubgeneros()[i] << endl;

                        }
                        
                        int contador = 0;
                        while (true){
                            int valor = 0;
                            contador++;
                            cout << "Subgénero " << contador << ": ";
                            cin >> valor;
                            if((valor < 21)&&(valor > 0)){
                            seleccionSubgeneros.push_back(valor);
                            }
                            else if(valor == 0){
                                break;
                            }

                            else{
                                cout << "Elección no válida" << endl;
                                seleccionSubgeneros.push_back(20);
                            }
                        }

                        videojuegos[videojuegos.size()-1]->setSeleccionSubgeneros(seleccionSubgeneros);

                        break;
                    }

                    //videojuego de Consola
                    case 2: {
                        getline(cin, variableSaltar);
                        cout << "---Ingrese los siguientes datos---" << endl;
                        cout << "Datos generales del juego: " << endl;
                        cout << "Nombre del videojuego: ";
                        getline(cin, nombreVideojuego);
                        cout << endl;
                        cout << "Empresa desarrolladora del videojuego: ";
                        getline(cin, compania);
                        cout << endl;
                        cout << "Fecha de lanzamiento del videojuego (Escribe la fecha como un solo entero en formato ddmmaaaa): ";
                        cin >> fechaLanzamiento;
                        while (((dia > 31)&&(dia < 1)) || ((mes > 12)&&(dia < 1)) || ((año > 9999)&&(dia < 0)))
                        {
                            cout << "Fecha no válida, intenta de nuevo: ";
                            cin >> fechaLanzamiento;
                        }
                        cout << endl;
                        cout << "Precio de lanzamiento del videojuego: ";
                        cin >> precioLanzamiento;
                        cout << endl;
                        cout << "¿Ha cambiado el precio del juego?" << endl;
                            cout << "1. Sí" << endl << "2. No" << endl << "Selección: ";
                            cin >> opcionGral2;
                            if (opcionGral2 == 1)
                            {
                                cout << "Precio actual del juego: ";
                                cin >> precioActual;
                                cout << endl;
                            }

                            else{
                                precioActual = precioLanzamiento;
                                cout << endl;
                            }
                        cout << "¿Para qué consola es el juego?" << endl;
                        cout << "1. PlayStation 4" << endl << "2. PlayStation 5" << endl << "3. Xbox One" << endl << "4. Xbox Series S" << endl << "5. Xbox Series X" << endl << "6. Nintendo Switch" << endl << "7. Otra" << endl << "Selección: ";
                        cin >> seleccionConsola;
                        if(seleccionConsola == 7){
                            getline(cin, variableSaltar);
                            cout << "Nombre de la consola: ";
                            getline(cin, consolaAlternativa);
                        }
                        else{
                            getline(cin, variableSaltar);
                        }
                        cout << endl;
                        cout << "Edición de la consola: ";
                        getline(cin, edicionConsola);
                        cout << endl;
                        cout << "Datos de rendimiento del juego: " << endl;
                        cout << "Media de FPS: ";
                        cin >> mediaFps;
                        cout << endl;
                        cout << "Configuración gráfica predeterminada del juego: ";
                        getline(cin, variableSaltar);
                        getline(cin, presetGrafico);
                        cout << endl;
                        cout << "Resolución del juego: ";
                        getline(cin, resolucion);
                        cout << endl;

                        //Agregamos objeto a vector de videojuegos Rendimiento rendimientoConsola(mediaFps, presetGrafico, resolucion);
                        videojuegos.push_back(new ConsolaVideojuego(nombreVideojuego, compania, fechaLanzamiento, precioLanzamiento, Rendimiento(mediaFps, presetGrafico, resolucion), seleccionConsola, edicionConsola));
                        videojuegos[videojuegos.size()-1]->setconsolaAlternativa(consolaAlternativa);

                        //llamamos metodo setPrecioActual para setear un precio actual
                        videojuegos[videojuegos.size()-1]->setPrecioActual(precioActual);


                        //Se crea vector con subgenero para llamar al método setSeleccionSubgeneros que recibe un vector con subgeneros tipo string 
                        cout << "Selecciona los subgéneros del videojuego (teclee 0 para dejar de almacenar subgeneros): " << endl;
                        for(int i=0; i < 20; i++){
                            cout << "  " << i+1 << ". " << videojuegos[videojuegos.size()-1]->Videojuego::getSubgeneros()[i] << endl;

                        }
                        
                        
                        int contador = 0;
                        while (true){
                            int valor = 0;
                            contador++;
                            cout << "Subgénero " << contador << ": ";
                            cin >> valor;
                            if((valor < 21)&&(valor > 0)){
                            seleccionSubgeneros.push_back(valor);
                            }
                            else if(valor == 0){
                                break;
                            }

                            else{
                                cout << "Elección no válida" << endl;
                                seleccionSubgeneros.push_back(20);
                            }
                        }

                        videojuegos[videojuegos.size()-1]->setSeleccionSubgeneros(seleccionSubgeneros);




                        break;
                    }

                    case 3: {
                        cout << "Saliendo al menú principal..." << endl;
                        break;
                    }

                    default: {
                        cout << "Opción inválida, solo puede escribir los números 1, 2 y 3" << endl;
                        break;
                    }
                }
                
                
                break;
            }

            case 2: {
                cout << "----------" << endl << "Desea: " << endl << endl;
                cout << "1. Ver lista de videojuegos" << endl;
                cout << "2. Modificar datos de videojuego" << endl;
                cout << "3. Si desea salir al menu principal" << endl << "----------" <<endl;
                cout << "Seleccione la opción deseada: " << endl;
                cin >> opcion2;
                switch(opcion2){

                    case 1:{
                        for (int i = 0; i < videojuegos.size(); i++){
                            cout << videojuegos[i]->getDatos() << endl;
                        }

                        break;
                    }

                    case 2:{
                        cout << "Lista de videojuegos:" << endl << endl;
                        for (int i = 0; i < videojuegos.size(); i++){
                            cout << i+1 << ". " << videojuegos[i]->getNombreVideojuego() << endl;
                        }
                        cout << "Ingresa el número del videojuego que deseas modificar: ";
                        cin >> opcionGral1;
                        if (opcionGral1 <= videojuegos.size()){
                            cout << "¿Ha cambiado el precio del juego: " << videojuegos[opcionGral1-1]->getNombreVideojuego() << "?" << endl;
                            cout << "1. Sí" << endl << "2. No" << endl << "Selección: ";
                            cin >> opcionGral2;
                            if (opcionGral2 == 1)
                            {
                                cout << "Precio actual del juego: ";
                                cin >> precioActual;
                                cout << endl;
                                videojuegos[opcionGral1-1];
                            }

                            else{
                                cout << endl;
                            }

                            cout << "¿Quieres agregar una crítica al juego: " << videojuegos[opcionGral1-1]->getNombreVideojuego() << "?" << endl;
                            cout << "1. Sí" << endl << "2. No" << endl << "Selección: ";
                            cin >> opcionGral2;
                            if (opcionGral2 == 1)
                            {
                                getline(cin, variableSaltar);
                                cout << "Puntaje de la crítica: ";
                                cin >> puntaje;
                                cout << endl;
                                cout << "Reseña: ";
                                getline(cin, variableSaltar);
                                getline(cin, reseña);
                                Critica critica(puntaje, reseña, nombreUsuario);
                                videojuegos[opcionGral1-1]->agregarCritica(critica);

                            }

                            else{
                                cout << endl;
                            }

                        }

                        else{
                            cout << "Opción no válida" << endl;
                        }

                        break;
                    } 

                    case 3: {
                        cout << "Saliendo al menú principal..." << endl;
                        break;
                    }

                    default:{
                        cout << "Opción inválida, solo puede escribir los números 1, 2 y 3" << endl;
                        break;
                    }
                }

                break;
            }

            case 3: {
                cout << "Saliendo..." << endl;
                break;
            }

            default: {
                cout << "Opción inválida, solo puede escribir los números 1, 2 y 3" << endl;
                break;
            }


        }


    }while(opcion1 != 3);

    return 0;
};