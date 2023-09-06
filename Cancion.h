#ifndef CANCION
#define CANCION
#include "Tiempo.h"
#include "Artista.h"
#include <iostream>
using namespace std;

class Cancion{
    private:
        unsigned int id;
        string titulo;
        string ruta_archivo;
        Artista** v_artistas;
        int util_v_artistas;
        Tiempo duracion;
        int reproducciones;
    public:
        // Constructores y destructor
        Cancion();
        Cancion(const Cancion &c);
        ~Cancion();
        // Setters
        void setIdCancion(const int &id_nueva);
        void setRuta(const string &ruta_archivo_nueva);
        void setTitulo(const string &titulo_nuevo);
        void setArtista(Artista* artista_nuevo);
        void setUtil(const int &util_nueva);
        void setDuracion(const Tiempo &duracion_nueva);
        void setReproducciones(const int &reproducciones_nueva);
        // Getters
        unsigned int getId() const;
        string getTitulo() const;
        string getRuta() const;
        Artista* getArtista(const int &posicion) const;
        int getUtil() const;
        Tiempo getDuracion() const;
        int getReproducciones() const;
        // Sobrecargas
        Cancion& operator=(const Cancion &cancion_a_copiar);  
        // ostream& operator<<(ostream &flujo, const Cancion &c); HECHO!! (se incluye aquí aunque no corresponda para saber que está)
        // Otros métodos
        void resize(const int &nuevo_tamanio);
        void eliminarArtista(const int &posicion);
        // void escucharCancion(); // FALTA ????
        
};
Cancion::Cancion(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Cancion, direccion: " << DEFAULT << this << endl; }
    // Inicializamos todas las variables a 0
    this->setIdCancion(0);
    this->setRuta("NULL");
    this->setTitulo("NULL");
    // Artista** v_artistas;   NO ESTÁ CREADO PORQUE PARA QUÉ HACER UN new v_artistas[0]...
    this->setUtil(0);
    Tiempo duracion(0, 0);
    this->setDuracion(duracion);
    this->setReproducciones(0);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO la Cancion: " << DEFAULT << this << endl; } 
}
Cancion::Cancion(const Cancion &cancion_a_copiar){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Cancion por COPIA, direccion: " << DEFAULT << this << endl; }
    this->setIdCancion(cancion_a_copiar.getId());
    this->setRuta(cancion_a_copiar.getRuta());
    this->setTitulo(cancion_a_copiar.getRuta());
    // Reservo memoria dinamica
    Artista** copia_artistas = new Artista*[cancion_a_copiar.getUtil()];
    // Copio en el vector creado
    for(int i = 0; i < cancion_a_copiar.getUtil(); i++){
        copia_artistas[i] = cancion_a_copiar.getArtista(i);
    }
    // Por seguridad, vacio el vector anterior
    for(int i = 0; i < this->getUtil(); i++){
        this->v_artistas[i] = NULL;
    }
    // Indico al SO que la memoria anterior queda liberada
    delete [] this->v_artistas;
    // Copio la nueva direccion del vector que contiene los artistas
    this->v_artistas = copia_artistas;
    this->setUtil(cancion_a_copiar.getUtil());
    this->setDuracion(cancion_a_copiar.getDuracion());
    this->setReproducciones(cancion_a_copiar.getReproducciones());
    if(debug==true){ cout << DEBUG << "Generada con Exito una Cancion por COPIA, direccion: " << DEFAULT << this << endl; }
}
Cancion::~Cancion(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de la Cancion, direccion: " << DEFAULT << this << endl; }
    // Inicializamos todas las variables a 0
    this->setIdCancion(0);
    this->setRuta("NULL");
    this->setTitulo("NULL");
    // Limpiamos el vector de direcciones por seguridad...
    for(int i=0; i<this->getUtil(); i++){
        this->v_artistas[i] = NULL;
    }
    // Indicamos que la memoria queda liberada
    delete [] v_artistas;
    // Eliminamos la direccion de memoria que contenía
    this->v_artistas = 0;
    this->setUtil(0);
    Tiempo duracion(0, 0);
    this->setDuracion(duracion);
    this->setReproducciones(0);

    if(debug==true){ cout << DEBUG << "Se ha DESTRUIDO la Cancion con direccion: " << DEFAULT << this << endl; }    
}
void Cancion::setIdCancion(const int &id_nueva){
    this->id = id_nueva;
}
void Cancion::setRuta(const string &ruta_archivo_nueva){
    this->ruta_archivo = ruta_archivo_nueva;
}
void Cancion::setTitulo(const string &titulo_nuevo){
    this->titulo = titulo_nuevo;
}
void Cancion::setArtista(Artista* artista_nuevo){
    if(debug==true){ cout << DEBUG << "setArtista: Inicio " << DEFAULT << endl; }
    // Ajustamos el tamaño
    this->resize(this->util_v_artistas + 1);
    // Lo incluimos
    this->v_artistas[util_v_artistas - 1] = artista_nuevo;
    // La util la actualiza el resize automaticamente
    if(debug==true){ cout << DEBUG << "setArtista: Fin ejecucion " << DEFAULT << endl; }
}
void Cancion::setUtil(const int &util_nueva){
    this->util_v_artistas = util_nueva;
}
void Cancion::setDuracion(const Tiempo &duracion_nueva){
    this->duracion = duracion_nueva;
}
void Cancion::setReproducciones(const int &reproducciones_nueva){
    this->reproducciones = reproducciones_nueva;
}
unsigned int Cancion::getId() const{
    return this->id;
}
string Cancion::getTitulo() const{
    return this->titulo;
}
string Cancion::getRuta() const{
    return this->ruta_archivo;
}
Artista* Cancion::getArtista(const int &posicion) const{
    return this->v_artistas[posicion];
}
int Cancion::getUtil() const{
    return this->util_v_artistas;
}
Tiempo Cancion::getDuracion() const{
    return this->duracion;
}
int Cancion::getReproducciones() const{
    return this->reproducciones;
}
Cancion& Cancion::operator=(const Cancion& cancion_a_copiar){
    if(&cancion_a_copiar!=this){
        this->id = cancion_a_copiar.getId();
        this->titulo = cancion_a_copiar.getTitulo();
        this->ruta_archivo = cancion_a_copiar.getRuta();
        if(cancion_a_copiar.getUtil() > 0){
            // Eliminamos primero
            for(int i=0; i<this->getUtil(); i++){
                this->v_artistas[i] = 0;
            }
            delete [] this->v_artistas;
            // Copiamos en el nuevo...
            Artista** copia = new Artista*[cancion_a_copiar.getUtil()];
            for(int i = 0; i < cancion_a_copiar.getUtil(); i++){
                copia[i] = cancion_a_copiar.getArtista(i);
            }
            // Asignamos la nueva direccion
            this->v_artistas = copia;
        }else{
            // Borramos el anterior por seguridad
            for(int i=0; i< this->util_v_artistas; i++){
                this->v_artistas[i] = NULL;
            }
            delete [] this->v_artistas;
            this->v_artistas = NULL;
        }
        this->util_v_artistas = cancion_a_copiar.getUtil();
        this->duracion = cancion_a_copiar.getDuracion();
        this->reproducciones = cancion_a_copiar.getReproducciones();
    }
    return *this;
}
ostream& operator<<(ostream &flujo, const Cancion &c){
    flujo << GREEN << "ID: " << YELLOW << c.getId() << DEFAULT << endl;
    flujo << GREEN << "Direccion: " << YELLOW << &c << DEFAULT << endl;
    flujo << GREEN << "Titulo: " << YELLOW << c.getTitulo() << DEFAULT << endl;
    flujo << GREEN << "Ruta: " << YELLOW << c.getRuta() << DEFAULT << endl;
    for(int i = 0; i < c.getUtil(); i++){
        flujo << GREEN << "Artista " << YELLOW << i+1 << ": " << *c.getArtista(i) << DEFAULT << endl;
    }
    flujo << GREEN << "Duracion: " << YELLOW << c.getDuracion() << DEFAULT << endl;
    flujo << GREEN << "Reproducciones totales: " << YELLOW << c.getReproducciones() << DEFAULT;

    return flujo;
}
void Cancion::resize(const int &nuevo_tamanio){
    if(debug==true){ cout << DEBUG << "resize: Clase Cancion: v_artistas - Inicio" << DEFAULT << endl; }
    if(this->getUtil() > 0){
        // Reservamos el nuevo tamaño
        Artista** copia = 0;
        copia = new Artista*[nuevo_tamanio];

        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nuevo_tamanio; i++){
            copia[i] = NULL;
        }

        if(nuevo_tamanio > this->util_v_artistas){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtil(); i++){
                copia[i] = this->getArtista(i);
            }

        }else if(nuevo_tamanio < this->util_v_artistas){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nuevo_tamanio; i++){
                copia[i] = this->getArtista(i);
            }
        }else if(nuevo_tamanio == this->util_v_artistas){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->util_v_artistas; i++){
            this->v_artistas[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] v_artistas;
        // Copiamos la nueva direccion
        this->v_artistas = copia;
        // Actualizamos la util...
        this->setUtil(nuevo_tamanio);
    }else{
        if(debug==true){ cout << DEBUG << "resize: Clase Cancion: v_artistas - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->v_artistas = new Artista*[nuevo_tamanio];
        this->setUtil(nuevo_tamanio);
    }
    if(debug==true){ cout << DEBUG << "resize: Clase Cancion: v_artistas - Fin ejecucion" << DEFAULT << endl; }
}
void Cancion::eliminarArtista(const int &posicion){
    if(debug==true){ cout << DEBUG << "Cancion::eliminarArtista - Inicio" << DEFAULT << endl; }
    if(posicion >= 0 && posicion < this->getUtil()){
        Artista** copia = new Artista*[this->getUtil()];
        copia[this->getUtil() - 1] = this->getArtista(posicion);
        for(int i = 0; i < this->getUtil() - 1; i++){
            if(i < posicion){
                copia[i] = this->getArtista(i);
            }else{
                copia[i] = this->getArtista(i+1);
            }
        }
        for(int i = 0; i < this->getUtil(); i++){
            v_artistas[i] = 0;
        }
        delete [] v_artistas;
        this->resize(this->getUtil()-1);
        this->v_artistas = copia;
    }
    if(debug==true){ cout << DEBUG << "Cancion::eliminarArtista - Fin ejecucion" << DEFAULT << endl; }
}
#else
class Cancion;
#endif