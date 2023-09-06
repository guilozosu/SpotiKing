#ifndef PLAYLIST
#define PLAYLIST
#include <iostream>
#include "Cancion.h"
using namespace std;

class Playlist{
    private:
        unsigned int id;
        string nombre;
        Cancion** v_canciones;
        int util_v_canciones;
        Tiempo duracion_total;
    public:
        Playlist();
        Playlist(const Playlist &p);
        ~Playlist();
        // Setters
        void setId(const unsigned int &id_nueva);
        void setNombre(const string &nombre_nuevo);
        void setCancion(Cancion* cancion_nueva);
        void setUtil(const int &util_nueva);
        void setDuracion(const Tiempo &duracion_total_nueva);
        // Getters
        unsigned int getId() const;
        string getNombre() const;
        Cancion* getCancion(const int &posicion) const;
        int getUtil() const;
        Tiempo getDuracion() const;
        // Sobrecargas
        Playlist& operator=(const Playlist &playlist_recibida);
        // ostream& operator<<(ostream &flujo, const Playlist &playlist_recibida) aunque no corresponda aqui el metodo
        // Otros métodos
        void resize(const int &nueva_dim);
        void eliminarCancion(const int &posicion); // REVISAR QUE ESTA CORRECTO
};
Playlist::Playlist(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Playlist, direccion: " << DEFAULT << this << endl; }
    // Inicializamos todas las variables a 0
    this->setId(0);
    this->setNombre("NULL");
    this->setUtil(0);
    Tiempo nulo;
    this->setDuracion(nulo);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO la Playlist: " << DEFAULT << this << endl; } 
}
Playlist::Playlist(const Playlist &p){
   
    this->setId(p.getId());
    this->setNombre(p.getNombre());

    // Reservo memoria dinamica
    Cancion** copia_canciones = new Cancion*[p.getUtil()];
    // Copio en el vector creado
    for(int i = 0; i < p.getUtil(); i++){
        copia_canciones[i] = p.getCancion(i);
    }
    // Por seguridad, vacio el vector anterior
    for(int i = 0; i < this->getUtil(); i++){
        this->v_canciones[i] = NULL;
    }
    // Indico al SO que la memoria anterior queda liberada
    delete [] this->v_canciones;
    // Copio la nueva direccion del vector que contiene los artistas
    this->v_canciones = copia_canciones;
    this->setUtil(p.getUtil());
    this->setDuracion(p.getDuracion());

}
Playlist::~Playlist(){
    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION de la Playlist, direccion: " << DEFAULT << this << endl; }

    // Limpiamos el vector por seguridad...
    for(int i=0; i < this->getUtil(); i++){
        this->v_canciones[i] = NULL;
    }
    // Inicializamos la util a 0 también...
    this->setUtil(0);
    // Indicamos al SO que la memoria esta disponible para ser sobreescrita...
    delete [] this->v_canciones;
    // Eliminamos la dirección también....
    this->v_canciones = 0;

    if(debug==true){ cout << DEBUG << "Se ha DESTRUIDO la Playlist con direccion: " << DEFAULT << this << endl; }    
}
Cancion* Playlist::getCancion(const int &posicion) const{
    return this->v_canciones[posicion];
}
int Playlist::getUtil() const{
    return this->util_v_canciones;
}
void Playlist::setCancion(Cancion* cancion_nueva){

    this->resize(this->util_v_canciones + 1);
    Tiempo t_actual(this->getDuracion());
    Tiempo t_nuevo(cancion_nueva->getDuracion());
    Tiempo t_total = t_actual + t_nuevo;
    this->setDuracion(t_total);
    this->v_canciones[this->util_v_canciones - 1] = cancion_nueva;
}
void Playlist::setUtil(const int &util_nueva){
    this->util_v_canciones = util_nueva;
}
void Playlist::setDuracion(const Tiempo &duracion_total_nueva){
    this->duracion_total = duracion_total_nueva;
}
Tiempo Playlist::getDuracion() const{
    return this->duracion_total;
}
void Playlist::setId(const unsigned int &id_nueva){
    this->id = id_nueva;
}
unsigned int Playlist::getId() const{
    return this->id;
}
string Playlist::getNombre() const{
    return this->nombre;
}
void Playlist::setNombre(const string &nombre_nuevo){
    this->nombre = nombre_nuevo;
}
Playlist& Playlist::operator=(const Playlist &playlist_recibida){
    if(&playlist_recibida!=this){
        this->id = playlist_recibida.getId();
        this->nombre = playlist_recibida.getNombre();
        if(playlist_recibida.getUtil() > 0){
            Cancion **vector_auxiliar = new Cancion*[playlist_recibida.getUtil()];
            // Copiamos la playlist_recibida en el auxiliar
            for(int i = 0; i < playlist_recibida.getUtil(); i++){
                vector_auxiliar[i] = playlist_recibida.getCancion(i);
            }
            // Borramos el anterior por seguridad
            for(int i=0; i<this->util_v_canciones; i++){
                this->v_canciones[i] = NULL;
            }
            delete [] v_canciones;
            // Asignamos la direccion de memoria del nuevo vector generado
            this->v_canciones = vector_auxiliar;
        }else{
            // Borramos el anterior por seguridad
            for(int i=0; i<this->util_v_canciones; i++){
                this->v_canciones[i] = NULL;
            }
            delete [] this->v_canciones;
            this->v_canciones = NULL;
        }
        this->util_v_canciones = playlist_recibida.getUtil();
        this->duracion_total = playlist_recibida.getDuracion();
    }
    return *this;
}
ostream& operator<<(ostream &flujo, const Playlist &playlist_recibida){
    flujo << MAGENTA << "Playlist ID: " << YELLOW << playlist_recibida.getId() << DEFAULT << endl;
    flujo << MAGENTA << "Nombre: " << YELLOW << playlist_recibida.getNombre() << DEFAULT << endl;
    flujo << MAGENTA << "Canciones: " << DEFAULT << endl;
    if(playlist_recibida.getUtil() > 0){
        for(int i=0; i<playlist_recibida.getUtil(); i++){
            flujo << MAGENTA << "======" << DEFAULT << endl;
            flujo << *playlist_recibida.getCancion(i) << endl;
            flujo << MAGENTA << "======" << DEFAULT << endl;
      }
    }
    flujo << MAGENTA << "Duracion Total: " << YELLOW << playlist_recibida.getDuracion() << DEFAULT << endl;
    return flujo;
}
void Playlist::resize(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "resize: Clase Playlist: v_canciones - Inicio" << DEFAULT << endl; }
    if(this->getUtil() > 0){
        // Reservamos el nuevo tamaño
        Cancion** copia = 0;
        copia = new Cancion*[nueva_dim];

        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        if(nueva_dim > this->util_v_canciones){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtil(); i++){
                copia[i] = this->getCancion(i);
            }

        }else if(nueva_dim < this->util_v_canciones){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getCancion(i);
            }
        }else if(nueva_dim == this->util_v_canciones){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->util_v_canciones; i++){
            this->v_canciones[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] v_canciones;
        // Copiamos la nueva direccion
        this->v_canciones = copia;
        // Actualizamos la util...
        this->setUtil(nueva_dim);
    }else{
        if(debug==true){ cout << DEBUG << "resize: Clase Cancion: v_artistas - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->v_canciones = new Cancion*[nueva_dim];
        this->setUtil(nueva_dim);
    }
    if(debug==true){ cout << DEBUG << "resize: Clase Playlist: v_canciones - Fin ejecucion" << DEFAULT << endl; }
}
void Playlist::eliminarCancion(const int &posicion){
    if(debug==true){ cout << DEBUG << "Playlist::eliminarCancion - Inicio" << DEFAULT << endl; }
    Tiempo t_actual(this->getDuracion());
    Tiempo t_nuevo(this->getCancion(posicion)->getDuracion());
    Tiempo t_total = t_actual - t_nuevo;
    this->setDuracion(t_total);
    for(int i = posicion; i < this->getUtil() - 1; i++){
        this->v_canciones[i] = this->v_canciones[i+1];
    }
    this->resize(this->getUtil() - 1);
    if(debug==true){ cout << DEBUG << "Playlist::eliminarCancion - Fin ejecucion" << DEFAULT << endl; }
}




#else
class Playlist;
#endif