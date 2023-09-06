#ifndef RAP
#define RAP
#include "Tiempo.h"
#include "Artista.h"
#include "Cancion.h"
#include <iostream>
using namespace std;
class Rap: public Cancion{
    private:
        
    public:
        Rap();
        ~Rap();
};
Rap::Rap(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Cancion RAP, direccion: " << DEFAULT << this << endl; }
};
Rap::~Rap(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de una Cancion RAP, direccion: " << DEFAULT << this << endl; }
}
#else
class Rap;
#endif