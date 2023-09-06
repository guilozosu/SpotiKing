#ifndef ARTISTA
#define ARTISTA
#include <iostream>
using namespace std;

#define RESTORE "\033[1;0m"
#define DEFAULT "\033[1;0m"
#define DEBUG "\033[1;31m"
#define OK "\033[1;32m"
#define GREEN "\033[1;32m"      /* Green */
#define YELLOW "\033[1;33m"      /* Yellow */
#define USER "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define WHITE "\033[1;37m"      /* White */

bool debug=false;

class Artista{
    private:
        unsigned int id;
        string nombre;  
    public:
        // Constructores y destructores
        Artista();
        ~Artista();
        Artista(const Artista &artista_a_copiar); 
        Artista(const int &id_nueva, const string &nombre_nuevo);
        // Setters
        void setId(const unsigned int &nueva_id);
        void setNombre(const string &nombre_nuevo);
        // Getters
        unsigned int getId() const;
        string getNombre() const;
        // Sobrecargas
        Artista& operator=(const Artista &artista_recibido);
        //ostream& operator<<(ostream &flujo, const Artista &artista_recibido) Incluido aqui para saber aunque no corresponda
        //istream& operator>>(istream&, const Artista &artista_recibido); ???? De momento no es necesario
};
Artista::Artista(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un Artista, direccion: " << DEFAULT << this << endl; }
    // Inicializamos todas las variables a 0 o NULL
    this->setId(0);
    this->setNombre("NULL");
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el Artista: " << DEFAULT << this << endl; }
}
Artista::~Artista(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION del Artista, direccion: " << DEFAULT << this << endl; }
    this->setId(0);
    this->setNombre("NULL");
    if(debug==true){ cout << DEBUG << "Se ha DESTRUIDO el Artista con direccion: " << DEFAULT << this << endl; }
}
Artista::Artista(const Artista &artista_a_copiar){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un Artista por COPIA, direccion: " << DEFAULT << this << endl; }
    // Copiamos...
    this->setId(artista_a_copiar.id);
    this->setNombre(artista_a_copiar.nombre);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el Artista por COPIA: " << DEFAULT << this << endl; }
}
Artista::Artista(const int &id_nueva, const string &nombre_nuevo){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un Artista por PARAMETROS, direccion: " << DEFAULT << this << endl; }
    this->setId(id_nueva);
    this->setNombre(nombre_nuevo);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el Artista por PARAMETROS: " << DEFAULT << this << endl; }
}
void Artista::setId(const unsigned int &nueva_id){
    this->id = nueva_id;
}
void Artista::setNombre(const string &nombre_nuevo){
    this->nombre = nombre_nuevo;
}
unsigned int Artista::getId() const{
    return this->id;
}
string Artista::getNombre() const{
    return this->nombre;
}
Artista& Artista::operator=(const Artista &artista_recibido){
    if(&artista_recibido!=this){
        this->setId(artista_recibido.getId());
        this->setNombre(artista_recibido.getNombre());
    }
    return *this;
}
ostream& operator<<(ostream &flujo, const Artista &artista_recibido){
/*    flujo << "ID : " << artista_recibido.getId() << endl;
    flujo << "Nombre : " << artista_recibido.getNombre() << endl;
    return flujo;
*/
    flujo << artista_recibido.getNombre();
    return flujo;
}

#else
class Artista;
#endif