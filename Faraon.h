#ifndef FARAON
#define FARAON
#include "Tiempo.h"
#include "Artista.h"
#include "Cancion.h"
#include <iostream>
using namespace std;
class Faraon: public Cancion{
    private:
        
    public:
        Faraon();
        ~Faraon();
};
Faraon::Faraon(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Cancion FARAON, direccion: " << DEFAULT << this << endl; }
};
Faraon::~Faraon(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de una Cancion FARAON, direccion: " << DEFAULT << this << endl; }
}
#else
class Faraon;
#endif