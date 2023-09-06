#ifndef VALORACION
#define VALORACION
#include <iostream>
#include "Cancion.h"
using namespace std;

class Valoracion{
    private:
        Cancion* cancion_valorada;
        double puntuacion;
    public:
        Valoracion();
        ~Valoracion();

        void setCancionValorada(Cancion* nueva_cancion_valorada);
        Cancion* getCancionValorada() const;

        void setPuntuacion(const double &nueva_puntuacion);
        double getPuntuacion() const;
};
Valoracion::Valoracion(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Valoracion, direccion: " << DEFAULT << this << endl; }
    this->setCancionValorada(0);
    this->setPuntuacion(0);
    if(debug==true){ cout << DEBUG << "Fin de la CREACION de una Valoracion, direccion: " << DEFAULT << this << endl; }
}
Valoracion::~Valoracion(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de una Valoracion, direccion: " << DEFAULT << this << endl; }
    this->setCancionValorada(0);
    this->setPuntuacion(0);
    if(debug==true){ cout << DEBUG << "Fin de la DESTRUCCION de una Valoracion, direccion: " << DEFAULT << this << endl; }
}
void Valoracion::setCancionValorada(Cancion* nueva_cancion_valorada){
    this->cancion_valorada = nueva_cancion_valorada;
}
Cancion* Valoracion::getCancionValorada() const{
    return this->cancion_valorada;
}
void Valoracion::setPuntuacion(const double &nueva_puntuacion){
    this->puntuacion = nueva_puntuacion;
}
double Valoracion::getPuntuacion() const{
    return this->puntuacion;
}

#else
class Valoracion;
#endif