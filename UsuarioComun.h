#ifndef USUARIOCOMUN
#define USUARIOCOMUN
#include <iostream>
#include "Playlist.h"
#include "Usuario.h"
#include "Valoracion.h"

using namespace std;

class UsuarioComun: public Usuario{
    private:
        Cancion** canciones_usuario;
        int util_canciones_usuario;
        Playlist** playlist_usuario;
        int util_playlist_usuario;
        Valoracion** valoraciones_usuario;
        int util_valoraciones_usuario;
    public:
        UsuarioComun();
        UsuarioComun(const UsuarioComun &copiar);
        ~UsuarioComun();
        // Setters
        void agregarCancionAUsuario(Cancion* cancion_nueva);
        void eliminarCancionDeUsuario(const int &posicion);
        void setUtilCancionesUsuario(const int &nueva_util_canciones);
        void agregarPlaylistAUsuario(Playlist* playlist_nueva);
        void eliminarPlaylistDeUsuario(const int &posicion);
        void setUtilPlaylistUsuario(const int &nueva_util_playlist);
        // Getters
        Cancion* getCancionUsuario(const int &posicion) const;
        int getUtilCancionesUsuario() const;
        Playlist* getPlaylistUsuario(const int &posicion) const;
        int getUtilPlaylistUsuario() const;

        // Valoracion
        void setValoracion(Valoracion* nueva_valoracion);
        Valoracion* getValoracion(const int &posicion) const;
        void resizeValoracion(const int &nueva_dim);
        void setUtilValoracion(const int &nueva_util);
        int getUtilValoracion() const;


        // Sobrecargas
        UsuarioComun& operator=(const UsuarioComun &usuario_recibido);

        // Métodos adicionales
        void resizeVectorCanciones(const int &nueva_dim);
        void resizeVectorPlaylist(const int &nueva_dim);
};
UsuarioComun::UsuarioComun(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un UsuarioComun, direccion: " << DEFAULT << this << endl; }
    this->setId(-1);
    this->setLogin("NULL");
    this->setPassword("NULL");
    this->setUtilCancionesUsuario(0);
    this->setUtilPlaylistUsuario(0);
    this->setUtilValoracion(0);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el UsuarioComun: " << DEFAULT << this << endl; } 
}
UsuarioComun::~UsuarioComun(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un UsuarioComun, direccion: " << DEFAULT << this << endl; }
    if(util_canciones_usuario >0) delete [] canciones_usuario;
    if(util_playlist_usuario>0) delete [] playlist_usuario;
    if(util_valoraciones_usuario>0) delete [] valoraciones_usuario;
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el UsuarioComun: " << DEFAULT << this << endl; } 
}
void UsuarioComun::agregarCancionAUsuario(Cancion* cancion_nueva){
    this->resizeVectorCanciones(this->getUtilCancionesUsuario() + 1);
    this->canciones_usuario[this->util_canciones_usuario - 1] = cancion_nueva;
}
void UsuarioComun::eliminarCancionDeUsuario(const int &posicion){
    if(debug==true){ cout << DEBUG << "UsuarioComun::eliminarCancionDeUsuario - Inicio" << DEFAULT << endl; }
    for(int i = posicion; i < this->getUtilCancionesUsuario() - 1; i++){
        this->canciones_usuario[i] = this->canciones_usuario[i+1];
    }
    this->resizeVectorCanciones(this->getUtilCancionesUsuario() - 1);
    if(debug==true){ cout << DEBUG << "UsuarioComun::eliminarCancionDeUsuario - Fin ejecucion" << DEFAULT << endl; }    
}
void UsuarioComun::setUtilCancionesUsuario(const int &nueva_util_canciones){
    this->util_canciones_usuario = nueva_util_canciones;
}
void UsuarioComun::agregarPlaylistAUsuario(Playlist* playlist_nueva){
	// cout << "Util_playlist_usuario: " << this->util_playlist_usuario << endl;
    this->resizeVectorPlaylist(this->getUtilPlaylistUsuario() + 1);
    this->playlist_usuario[this->util_playlist_usuario -1] = playlist_nueva;
}
void UsuarioComun::eliminarPlaylistDeUsuario(const int &posicion){
    if(debug==true){ cout << DEBUG << "UsuarioComun::eliminarPlaylistDeUsuario - Inicio" << DEFAULT << endl; }
    for(int i = posicion; i < this->getUtilPlaylistUsuario() - 1; i++){
        this->playlist_usuario[i] = this->playlist_usuario[i+1];
    }
    this->resizeVectorPlaylist(this->getUtilPlaylistUsuario() - 1);
    if(debug==true){ cout << DEBUG << "UsuarioComun::eliminarPlaylistDeUsuario - Fin ejecucion" << DEFAULT << endl; }
}
void UsuarioComun::setUtilPlaylistUsuario(const int &nueva_util_playlist){
    this->util_playlist_usuario = nueva_util_playlist;
}
Cancion* UsuarioComun::getCancionUsuario(const int &posicion) const{
    return this->canciones_usuario[posicion];
}
int UsuarioComun::getUtilCancionesUsuario() const{
    return this->util_canciones_usuario;
}
Playlist* UsuarioComun::getPlaylistUsuario(const int &posicion) const{
    return this->playlist_usuario[posicion];
}
int UsuarioComun::getUtilPlaylistUsuario() const{
    return this->util_playlist_usuario;
}
UsuarioComun& UsuarioComun::operator=(const UsuarioComun &usuario_recibido){
    if(&usuario_recibido!=this){
        this->setId(usuario_recibido.getId());
        this->setLogin(usuario_recibido.getLogin());
        this->setPassword(usuario_recibido.getPassword());

        // Copiamos los punteros de las Canciones del usuario_recibido
        Cancion** canciones_aux = new Cancion*[usuario_recibido.getUtilCancionesUsuario()];
        for(int i = 0; i < usuario_recibido.getUtilCancionesUsuario(); i++){
            canciones_aux[i] = usuario_recibido.getCancionUsuario(i);
        }
        // Por seguridad, limpiamos el vector del objeto this
        for(int i = 0; i < this->getUtilCancionesUsuario(); i++){
            this->canciones_usuario[i] = 0;
        }
        delete [] this->canciones_usuario;
        // Asignamos la nueva direccion...
        this->canciones_usuario = canciones_aux;
        this->setUtilCancionesUsuario(usuario_recibido.getUtilCancionesUsuario());

        // Copiamos los punteros de las Playlists del usuario_recibido
        Playlist** playlist_auxiliar = new Playlist*[usuario_recibido.getUtilPlaylistUsuario()];
        for(int i = 0; i < usuario_recibido.getUtilPlaylistUsuario(); i++){
            playlist_auxiliar[i] = usuario_recibido.getPlaylistUsuario(i);
        }
        // Limpiamos el vector que vamos a liberar
        for(int i = 0; i < this->getUtilPlaylistUsuario(); i++){
            this->playlist_usuario[i] = 0;
        }
        delete [] this->playlist_usuario;
        // Asignando la nueva direccion...
        this->playlist_usuario = playlist_auxiliar;
        this->setUtilPlaylistUsuario(usuario_recibido.getUtilPlaylistUsuario());
    }
    return *this;
}
void UsuarioComun::resizeVectorCanciones(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "resize UsuarioComun: VECTOR CANCIONES Inicio" << DEFAULT << endl; }
    //cout << "intro resizeCanciones" << endl;
    if(nueva_dim > 0){
        Cancion** copia = 0;
        copia = new Cancion*[nueva_dim];
        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        //cout << "resizeCanciones 1" << endl;
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        //cout << "resizeCanciones 2" << endl;
        if(nueva_dim > this->util_canciones_usuario){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            //cout << "resizeCanciones 3" << endl;
            for(int i=0; i < this->getUtilCancionesUsuario(); i++){
                copia[i] = this->getCancionUsuario(i);
            }
        //cout << "resizeCanciones 4" << endl;
        }else if(nueva_dim < this->util_canciones_usuario){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            //cout << "resizeCanciones 5" << endl;
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getCancionUsuario(i);
            }
            //cout << "resizeCanciones 6" << endl;
        }else{
            if(debug==true){ cout << DEBUG << "No hay que hacer resize" << DEFAULT << endl; }
            //cout << "resizeCanciones 7" << endl;
        }
        // por seguridad, vacío el anterior
        for(int i=0; i<this->util_canciones_usuario; i++){
            this->canciones_usuario[i] = NULL;
        }
        //cout << "resizeCanciones 8" << endl;
        if(this->getUtilCancionesUsuario() > 0){
            delete [] this->canciones_usuario;
        }
        //cout << "resizeCanciones 8.1" << endl;
        this->canciones_usuario = copia;
        //cout << "resizeCanciones 8.2" << endl;
        this->setUtilCancionesUsuario(nueva_dim);
        //cout << "resizeCanciones 8.3" << endl;
    }else{
        // cout << "resizeCanciones 9" << endl;
        this->util_canciones_usuario = 0;
        delete [] this->canciones_usuario;
    }
    //cout << "resizeCanciones 10" << endl;
    if(debug==true){ cout << DEBUG << "resize UsuarioComun: VECTOR CANCIONES - Fin ejecucion" << DEFAULT << endl; } 
}
void UsuarioComun::resizeVectorPlaylist(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "resize UsuarioComun: VECTOR PLAYLIST Inicio" << DEFAULT << endl; }
    if(nueva_dim > 0){
        Playlist** copia = new Playlist*[nueva_dim];
        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        if(nueva_dim > this->util_playlist_usuario){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtilPlaylistUsuario(); i++){
                copia[i] = this->getPlaylistUsuario(i);
            }
        }else if(nueva_dim < this->util_playlist_usuario){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getPlaylistUsuario(i);
            }
        }else{
            if(debug==true){ cout << DEBUG << "No hay que hacer resize" << DEFAULT << endl; }
        }
        // por seguridad, vacío el anterior
        for(int i=0; i<this->util_playlist_usuario; i++){
            this->playlist_usuario[i] = NULL;
        }
        if(this->util_playlist_usuario>0) delete [] playlist_usuario;
        this->playlist_usuario = copia;
        this->setUtilPlaylistUsuario(nueva_dim);
		//cout << "Putil: " << util_playlist_usuario << " " << *this->playlist_usuario[0] << endl;
    }else{
        this->util_playlist_usuario = 0;
        delete [] this->playlist_usuario;
    }
    if(debug==true){ cout << DEBUG << "resize UsuarioComun: VECTOR PLAYLIST - Fin ejecucion" << DEFAULT << endl; }     
}
ostream& operator<<(ostream &flujo, const UsuarioComun &usuarioComun_recibido){

    flujo << USER << "Usuario Id: " << WHITE << usuarioComun_recibido.getId() << DEFAULT << endl;
    flujo << USER << "Login: " << WHITE << usuarioComun_recibido.getLogin() << DEFAULT << endl;
    flujo << USER << "Password: " << WHITE << usuarioComun_recibido.getPassword() << DEFAULT << endl;
    /*
    if(usuarioComun_recibido.getUtilPlaylistUsuario()>0){
        for(int i = 0; i < usuarioComun_recibido.getUtilPlaylistUsuario(); i++){
            flujo << *usuarioComun_recibido.getPlaylistUsuario(i) << endl;
            flujo << "====" << endl;
        } 
    } 
    flujo << "Canciones: " << endl;
    if(usuarioComun_recibido.getUtilCancionesUsuario()>0){
        for(int i = 0; i < usuarioComun_recibido.getUtilCancionesUsuario(); i++){
            flujo << *usuarioComun_recibido.getCancionUsuario(i) << endl;
            flujo << "====" << endl;
        } 
    } 
*/
    return flujo;
}

void UsuarioComun::setValoracion(Valoracion* nueva_valoracion){
    this->resizeValoracion(this->getUtilValoracion() + 1);
    valoraciones_usuario[this->getUtilValoracion() - 1] = nueva_valoracion;
}
Valoracion* UsuarioComun::getValoracion(const int &posicion) const{
    return this->valoraciones_usuario[posicion];
}
void UsuarioComun::setUtilValoracion(const int &nueva_util){
    this->util_valoraciones_usuario = nueva_util;
}
int UsuarioComun::getUtilValoracion() const{
    return this->util_valoraciones_usuario;
}
void UsuarioComun::resizeValoracion(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "Valoracion::resizeValoracion - Inicio" << DEFAULT << endl; }
    if(this->getUtilValoracion() > 0){
        // Reservamos el nuevo tamaño
        Valoracion** copia = 0;
        copia = new Valoracion*[nueva_dim];

        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        if(nueva_dim > this->util_valoraciones_usuario){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtilValoracion(); i++){
                copia[i] = this->getValoracion(i);
            }

        }else if(nueva_dim < this->util_valoraciones_usuario){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getValoracion(i);
            }
        }else if(nueva_dim == this->util_valoraciones_usuario){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->util_valoraciones_usuario; i++){
            this->valoraciones_usuario[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] valoraciones_usuario;
        // Copiamos la nueva direccion
        this->valoraciones_usuario = copia;
        // Actualizamos la util...
        this->setUtilValoracion(nueva_dim);
    }else{
        if(debug==true){ cout << DEBUG << "Valoracion::resizeValoracion - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->valoraciones_usuario = new Valoracion*[nueva_dim];
        this->setUtilValoracion(nueva_dim);
    }
    if(debug==true){ cout << DEBUG << "Valoracion::resizeValoracion - Fin ejecucion" << DEFAULT << endl; }
}

#else
class UsuarioComun;
#endif