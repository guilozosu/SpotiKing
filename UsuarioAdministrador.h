#ifndef USUARIOADMINISTRADOR
#define USUARIOADMINISTRADOR
#include <iostream>
#include "Playlist.h"
#include "Usuario.h"

using namespace std;

class UsuarioAdministrador: public Usuario{
    private:

    public:
        UsuarioAdministrador();
        ~UsuarioAdministrador();

};
UsuarioAdministrador::UsuarioAdministrador(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un UsuarioAdminstrador, direccion: " << DEFAULT << this << endl; }
    if(debug==true){ cout << DEBUG << "Exito en la CREACION de un UsuarioAdminstrador, direccion: " << DEFAULT << this << endl; }
}
UsuarioAdministrador::~UsuarioAdministrador(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de un UsuarioAdminstrador, direccion: " << DEFAULT << this << endl; }
    if(debug==true){ cout << DEBUG << "Exito en la DESTRUCCIONde un UsuarioAdminstrador, direccion: " << DEFAULT << this << endl; }
}
#else
class UsuarioAdministrador;
#endif