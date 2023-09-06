#ifndef USUARIO
#define USUARIO
#include <iostream>
using namespace std;

class Usuario{
    private:
        // Atributos
        unsigned int id;
        string login;
        string password;

    public:
        // Métodos
        /**
         * @brief Constructor del objeto Usuario: ******************reserva por defecto un vector de coeficientes de dimensión 10, de
         * tal manera que el máximo grado permitido será 9. Todos los coeficientes tendrán como valor 0.0. Y el grado_actual
         * será por lo tanto 0.
         * @post El objeto Polinomio estará construido con la memoria del vector reservada y los valores por defecto.
         */
        Usuario();
        Usuario(const Usuario &usuario_copiar);
        Usuario(const int &id_nuevo, const string &login_nuevo, const string &password_nuevo);
        virtual ~Usuario();
        // Setters
        void setId(const unsigned int id_nuevo);
        void setLogin(const string login_nuevo);
        void setPassword(const string password_nuevo);
        // Getters
        virtual unsigned int getId() const;
        string getLogin() const;
        string getPassword() const;
        // Otros métodos
        
};
Usuario::Usuario(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un Usuario, direccion: " << DEFAULT << this << endl; }
    this->setId(0);
    this->setLogin("NULL");
    this->setPassword("NULL");
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el Usuario: " << DEFAULT << this << endl; } 
}
Usuario::Usuario(const Usuario &usuario_copiar){
    if(debug==true){ cout << DEBUG << "Invocamos a la COPIA de un Usuario, direccion: " << DEFAULT << this << endl; }
    // Inicializamos todas las variables a 0
    this->setId(usuario_copiar.getId());
    this->setLogin(usuario_copiar.getLogin());
    this->setPassword(usuario_copiar.getPassword());
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO la COPIA del Usuario: " << DEFAULT << this << endl; } 
}
Usuario::Usuario(const int &id_nuevo, const string &login_nuevo, const string &password_nuevo){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION por PARAMETROS de un Usuario, direccion: " << DEFAULT << this << endl; }
    this->setId(id_nuevo);
    this->setLogin(login_nuevo);
    this->setPassword(password_nuevo);
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION del Usuario por PARAMETROS, direccion: " << DEFAULT << this << endl; }
}
Usuario::~Usuario(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION del Usuario por, direccion: " << DEFAULT << this << endl; }
    // Igualamos todo a Nulo para evitar que los datos queden en memoria...
    this->setId(0);
    this->setLogin("NULL");
    this->setPassword("NULL");
    if(debug==true){ cout << DEBUG << "Se ha DESTRUIDO el Usuario con direccion: " << DEFAULT << this << endl; }    
}

unsigned int Usuario::getId() const{
    return this->id;
}
void Usuario::setId(const unsigned int id_nuevo){
    this->id = id_nuevo;
}
void Usuario::setLogin(const string login_nuevo){
    this->login = login_nuevo;
}
void Usuario::setPassword(const string password_nuevo){
    this->password = password_nuevo;
}
string Usuario::getLogin() const{
    return this->login;
}
string Usuario::getPassword() const{
    return this->password;
}


#else
class Usuario;
#endif