#ifndef POP
#define POP
#include "Tiempo.h"
#include "Artista.h"
#include "Cancion.h"
#include <iostream>
using namespace std;
class Pop: public Cancion{
    private:
        
    public:
        Pop();
        ~Pop();
};
Pop::Pop(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Cancion POP, direccion: " << DEFAULT << this << endl; }
};
Pop::~Pop(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de una Cancion POP, direccion: " << DEFAULT << this << endl; }
}
#else
class Pop;
#endif