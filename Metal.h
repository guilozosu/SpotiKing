#ifndef METAL
#define METAL
#include "Tiempo.h"
#include "Artista.h"
#include "Cancion.h"
#include <iostream>
using namespace std;
class Metal: public Cancion{
    private:
        
    public:
        Metal();
        ~Metal();
};
Metal::Metal(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Cancion METAL, direccion: " << DEFAULT << this << endl; }
};
Metal::~Metal(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de una Cancion METAL, direccion: " << DEFAULT << this << endl; }
}
#else
class Metal;
#endif