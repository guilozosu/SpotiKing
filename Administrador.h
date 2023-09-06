#ifndef ADMINISTRADOR
#define ADMINISTRADOR
#include <iostream>

#include "Usuario.h"

using namespace std;

class Administrador:Usuario{
    private:
        
    public:
        Administrador();
        Administrador(const Administrador &administrador_a_copiar);
        ~Administrador();
};

#else
class Administrador;
#endif