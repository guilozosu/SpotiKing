#ifndef VISTA
#define VISTA
#include <iostream>
#include "Playlist.h"
#include "Usuario.h"
#include "UsuarioComun.h"
#include "UsuarioAdministrador.h"
#include "Cancion.h"
#include "Metal.h"
#include "Rap.h"
#include "Pop.h"
#include "Faraon.h"
#include "Artista.h"
#include "Valoracion.h"

using namespace std;

class Vista{
    private:
        Usuario** usuarios_sistema;
        int util_usuarios_sistema;
        Cancion** canciones_sistema;
        int util_canciones_sistema;
        Artista** artistas_sistema;
        int util_artista_sistema;
        Playlist** playlists_sistema;
        int util_playlists_sistema;
        Usuario* usuario_activo;
        Artista** resultado_busqueda_artista;
        Playlist** resultado_busqueda_playlist;
        int util_resultado_busqueda_playlist;
        Cancion** resultado_busqueda_cancion;
    public:
        Vista();
        ~Vista();
        // Setters
        /**
         * @brief Set the Usuario object recibiendo un Usuario por puntero
         * 
         * @param usuario_nuevo Corresponde al puntero del Usuario que se agregará al vector de usuarios
         * @post se actualiza la útil y se hace un resize del vector
         */
        void setUsuario(Usuario *usuario_nuevo);
        /**
         * @brief Set the Util Usuario object
         * @pre No puede ser menor que 0
         * @param nueva_util_usuario 
         */
        void setUtilUsuario(const int &nueva_util_usuario);
        /**
         * @brief Set the Cancion object recibiendo una Cancion por puntero
         * 
         * @param nueva_cancionn Corresponde al puntero de la Cancion que se agregará al vector de usuarios
         * @post se actualiza la útil y se hace un resize del vector
         */
        void setCancion(Cancion *nueva_cancion);
        void setUtilCancion(const int &nueva_util_cancion);
        void setArtista(Artista *nuevo_artista);
        void setUtilArtista(const int &nueva_util_artista);
        void setPlaylist(Playlist *nueva_playlist);
        void setUtilPlaylist(const int &nueva_util_playlist);
        void setPlaylistUsuario(Playlist *nueva_playlist);
        /**
         * @brief Set the Util Playlist Usuario object
         * @pre Debe estar filtrado que la útil sea mayor que 0
         * @param nueva_util_playlist 
         */
        void setUtilPlaylistUsuario(const int &nueva_util_playlist);
        void setUsuarioActivo(Usuario *usuario_activo_nuevo);
        void setResultadoBusquedaArtista(Artista* resultado_artista); ///// VER
        //void setUtilResultadoBusquedaPlaylist(const int &nueva_util_resultado_busqueda_playlist):
        //void setResultadoBusquedaPlaylist(Playlist* resultado_playlist); ////// VER
        void setResultadoBusquedaCancion(Cancion* resultado_cancion); ///// VER
        // Getters
        /**
         * @brief Get the Usuario object
         * @pre Debemos de tener en cuenta que no sea menor que 0 ni que supere la útil
         * @param posicion Se corresponde con la posición del vector que devolveremos
         * @return Usuario* Es el puntero al objeto Usuario que devolveremos
         */
        Usuario* getUsuario(const int &posicion) const;
        int getUtilUsuario() const;
        Cancion* getCancion(const int &posicion) const;
        int getUtilCancion() const;
        Artista* getArtista(const int &posicion) const;
        int getUtilArtista() const;
        Playlist* getPlaylist(const int &posicion) const;
        int getUtilPlaylist() const;
        /**
         * @brief Get the Usuario Activo object: Méotodo que nos devolverá el Usuario en activo en el login
         * 
         * @return Usuario* nos servirá para compararlo con quién corresponde mostrar sus datos
         */
        Usuario* getUsuarioActivo() const;
        Artista* getResultadoBusquedaArtista() const; //// VER
        Playlist* getResultadoBusquedaPlaylist(const int &posicion) const; 
        void resizeResultadoBusquedaPlaylist(const int &nueva_dim);
        //int getUtilResultadoBusquedaPlaylist() const;
        Cancion* getResultadoBusquedaCancion() const; ///// VER
        // Otros métodos
        /**
         * @brief elimina una canción del vector mediante la posición recibida.
         * @pre debe tenerse en cuenta que la posición es mayor que 0 y que está comprendida dentro del útil
         * @param posicion corresponde a la posición en el vector que eliminaremos
         * @post se actualiza la útil y se hace un resize automáticamente
         */
        void eliminarCancionSistema(const int &posicion);
        void eliminarUsuarioSistema(const int &posicion);
        void eliminarPlaylistSistema(const int &posicion);
        /**
         * @brief Método que hace un resize del vector de usuarios_sistema
         * @param nueva_dim corresponde al nuevo tamaño que tendrá el vector de usuarios_sistema
         * @post se deben actualizar las útiles de los usuarios_sistema
         */
        void resizeUsuariosSistema(const int &nueva_dim);
        void resizeCancionesSistema(const int &nueva_dim);
        void resizeArtistasSistema(const int &nueva_dim);
        void resizePlaylistsSistema(const int &nueva_dim);
        /**
         * @brief Menú de inicio del login para acceder al sistema según el tipo de usuario
         * @post El Usuario debe de acceder a un menu Administrador o a un menú UsuarioComun 
         */
        void menuSistemaLogin();
        /**
         * @brief Menú del Administrador del sistema con las funciones únicas propias asginadas
         * 
         */
        void menuSistemaAdministrador();
        void menuSistemaUsuario();
        void loginAlSistema();
        void menuSistema();
        /**
         * @brief Método que realiza la carga de todos los datos del XML: Artistas, Canciones, Playlists, Usuarios
         */
        void cargaInicial();
        void imprimirDatos();
        void busquedaCancion();
        void busquedaCancionArtista();
        void catalogoCancionesSistema();
        void agregarCancionCatalogoSistema();
        /**
         * @brief Método simple para parar el flujo de ejecución del sistema
         */
        void pausa();
        void ModificarCancionSistema();
        void menuUsuariosAdministrador();
        void menuUsuariosAdministradorAgregarNuevoUsuario();
        void menuUsuariosAdministradorEliminarUsuario();
        void menuUsuariosAdministradorBuscarUsuario();
        void menuUsuariosAdministradorModificarUsuario();
        void menuUsuarioComunCancionesYPlaylists();
        void menuUsuarioComunAgregarCancionAPlaylist();
        void menuUsuarioComunEliminarCancionDePlaylist();
        void menuUsuarioAdministradorEliminarCancionDelSistema();
        void menuUsuarioAdministradorEliminarUsuarioDelSistema();
        void menuUsuarioAdministradorEliminarPlaylistDelSistema();
        void menuUsuarioAdministradorPlaylists();
        void busquedaPlaylist();
        void busquedaPlaylistPorNombre();
        void menuSistemaUsuarioValorarUnaCancion();
        void menuSistemaUsuarioReproducirUnaCancion();
        void testingCanciones();
        void testingValoraciones();
        
};
Vista::Vista(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de una Vista, direccion: " << DEFAULT << this << endl; }
        this->setUtilUsuario(0);
        this->setUtilCancion(0);
        this->setUtilArtista(0);
        this->setUtilPlaylist(0);
        //this->setUtilResultadoBusquedaPlaylist(0);
        
    if(debug==true){ cout << DEBUG << "Fin CREACION de una Vista, direccion: " << DEFAULT << this << endl; }
}
Vista::~Vista(){
    if(debug==true){ cout << DEBUG << "Inicio DESTRUCTOR de Vista, direccion: " << DEFAULT << this << endl; }
        for(int i = 0; i < this->getUtilArtista(); i++){

        }
        delete [] artistas_sistema;
        //cout << "destruidos artistas_sistema" << endl;
        delete [] canciones_sistema;
        //cout << "destruidos canciones_sistema" << endl;
        //delete [] playlists_sistema;
        //cout << "destruidos canciones_sistema" << endl;
        delete [] usuarios_sistema;
        //cout << "destruidos usuarios_sistema" << endl;
        //delete usuario_activo;
        //delete [] resultado_busqueda_artista;
        //cout << "destruidos resultado_busqueda_artista" << endl;
        //delete [] resultado_busqueda_playlist;
        //delete [] resultado_busqueda_cancion;
        this->setUtilArtista(0);
        //cout << "setUtilArtista(0)" << endl;
        this->setUtilCancion(0);
        this->setUtilPlaylist(0);
        this->setUtilUsuario(0);
    if(debug==true){ cout << DEBUG << "Fin DESTRUCTOR de Vista, direccion: " << DEFAULT << this << endl; }
}
void Vista::setUsuario(Usuario *usuario_nuevo){
    this->resizeUsuariosSistema(this->getUtilUsuario() + 1);
    this->usuarios_sistema[this->getUtilUsuario() - 1] = usuario_nuevo;
}
void Vista::setUtilUsuario(const int &nueva_util_usuario){
    this->util_usuarios_sistema = nueva_util_usuario;
}
void Vista::setCancion(Cancion *nueva_cancion){
    this->resizeCancionesSistema(this->getUtilCancion() + 1);
    this->canciones_sistema[this->getUtilCancion() - 1] = nueva_cancion;
    /*cout << "La cancion insertada (setCancion) direccion: " << nueva_cancion << endl;
    cout << "imprimo la cancion del setCancion:" << endl;
    cout << *nueva_cancion << endl;
    cout << "============fin setCancion==================" << endl;*/
}
void Vista::setUtilCancion(const int &nueva_util_cancion){
    this->util_canciones_sistema = nueva_util_cancion;
}
void Vista::setArtista(Artista *nuevo_artista){
    this->resizeArtistasSistema(this->getUtilArtista() + 1);
    this->artistas_sistema[this->getUtilArtista() - 1] = nuevo_artista;
}
void Vista::setUtilArtista(const int &nueva_util_artista){
    this->util_artista_sistema = nueva_util_artista;
}
void Vista::setPlaylist(Playlist *nueva_playlist){
    this->resizePlaylistsSistema(this->getUtilPlaylist() + 1);
    this->playlists_sistema[this->getUtilPlaylist() - 1] = nueva_playlist;
}
void Vista::setUtilPlaylist(const int &nueva_util_playlist){
    this->util_playlists_sistema = nueva_util_playlist;
}
void Vista::setUsuarioActivo(Usuario *usuario_activo_nuevo){
    this->usuario_activo = usuario_activo_nuevo;
}
//void Vista::setResultadoBusquedaArtista(Artista* resultado_artista){}
void Vista::resizeResultadoBusquedaPlaylist(const int &nueva_dim){
/*
    if(debug==true){ cout << DEBUG << "Vista::resizeResultadoBusquedaPlaylist **resultado_busqueda_playlist - Inicio" << DEFAULT << endl; }
    if(this->getUtilResultadoBusquedaPlaylist() > 0){
        // Reservamos el nuevo tamaño
        Playlist** copia = 0;
        copia = new Playlist*[nueva_dim];

        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        if(nueva_dim > this->getUtilResultadoBusquedaPlaylist()){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtilResultadoBusquedaPlaylist(); i++){
                copia[i] = this->getResultadoBusquedaPlaylist(i);
            }

        }else if(nueva_dim < this->getUtilResultadoBusquedaPlaylist()){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getResultadoBusquedaArtista(i);
            }
        }else if(nueva_dim == this->getUtilResultadoBusquedaPlaylist()){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->getUtilResultadoBusquedaPlaylist(); i++){
            this->resultado_busqueda_playlist[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] resultado_busqueda_playlist;
        // Copiamos la nueva direccion
        this->resultado_busqueda_playlist = copia;
        // Actualizamos la util...
        this->setUtilResultadoBusquedaPlaylist(nueva_dim);
    }else{
        if(debug==true){ cout << DEBUG << "Vista::resizeResultadoBusquedaPlaylist - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->resultado_busqueda_playlist = new Playlist*[nueva_dim];
        this->setUtilResultadoBusquedaPlaylist(nueva_dim);
    }
    if(debug==true){ cout << DEBUG << "Vista::resizeResultadoBusquedaPlaylist **resultado_busqueda_playlist - Fin ejecucion" << DEFAULT << endl; }
*/
}
/*
void Vista::setResultadoBusquedaPlaylist(Playlist* resultado_playlist){
    this->resizeResultadoBusquedaPlaylist(this->getUtilResultadoBusquedaPlaylist() + 1);
    this->resultado_busqueda_playlist[this->getUtilResultadoBusquedaPlaylist() - 1] = resultado_playlist;
}
*/
Playlist* Vista::getResultadoBusquedaPlaylist(const int &posicion) const{
    return resultado_busqueda_playlist[posicion];
}
/*
void Vista::setUtilResultadoBusquedaPlaylist(const int &nueva_util_resultado_busqueda_playlist){
    this->util_resultado_busqueda_playlist = nueva_util_resultado_busqueda_playlist;
}
int Vista::getUtilResultadoBusquedaPlaylist() const{
    return this->util_resultado_busqueda_playlist;
}
*/
//void Vista::setResultadoBusquedaCancion(Cancion* resultado_cancion){}
Usuario* Vista::getUsuario(const int &posicion) const{
    return this->usuarios_sistema[posicion];
}
int Vista::getUtilUsuario() const{
    return this->util_usuarios_sistema;
}
Cancion* Vista::getCancion(const int &posicion) const{
    /*cout << "La cancion que devuelvo (getCancion) direccion: " << canciones_sistema[posicion] << endl;
    cout << "Imprimo la cancion en getCancion:" << endl;
    cout << *canciones_sistema[posicion] << endl;
    cout << "========Fin impresion getCancion================" << endl;*/
    return this->canciones_sistema[posicion];
}
int Vista::getUtilCancion() const{
    return util_canciones_sistema;
}
Artista* Vista::getArtista(const int &posicion) const{
    return this->artistas_sistema[posicion];
}
int Vista::getUtilArtista() const{
    return this->util_artista_sistema;
}
Playlist* Vista::getPlaylist(const int &posicion) const{
    return this->playlists_sistema[posicion];
}
int Vista::getUtilPlaylist() const{
    return this->util_playlists_sistema;
}
Usuario* Vista::getUsuarioActivo() const{
    return this->usuario_activo;
}
void Vista::eliminarCancionSistema(const int &posicion){
    if(debug==true){ cout << DEBUG << "Vista::eliminarCancionSistema - Inicio" << DEFAULT << endl; }
    for(int i = posicion; i < this->getUtilCancion() - 1; i++){
        this->canciones_sistema[i] = this->canciones_sistema[i+1];
    }
    this->resizeCancionesSistema(this->getUtilCancion() - 1);
    if(debug==true){ cout << DEBUG << "Vista::eliminarCancionSistema - Fin ejecucion" << DEFAULT << endl; }
}
void Vista::eliminarUsuarioSistema(const int &posicion){
    if(debug==true){ cout << DEBUG << "Vista::eliminarUsuarioSistema - Inicio" << DEFAULT << endl; }
    for(int i = posicion; i < this->getUtilUsuario() - 1; i++){
        this->usuarios_sistema[i] = this->usuarios_sistema[i+1];
    }
    this->resizeUsuariosSistema(this->getUtilUsuario() - 1);
    if(debug==true){ cout << DEBUG << "Vista::eliminarUsuarioSistema - Fin ejecucion" << DEFAULT << endl; }
}
void Vista::eliminarPlaylistSistema(const int &posicion){
    if(debug==true){ cout << DEBUG << "Vista::eliminarPlaylistSistema - Inicio" << DEFAULT << endl; }
    for(int i = posicion; i < this->getUtilPlaylist() - 1; i++){
        this->playlists_sistema[i] = this->playlists_sistema[i+1];
    }
    this->resizePlaylistsSistema(this->getUtilPlaylist() - 1);
    if(debug==true){ cout << DEBUG << "Vista::eliminarPlaylistSistema - Fin ejecucion" << DEFAULT << endl; }
}
void Vista::resizeUsuariosSistema(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "Vista::resizeUsuariosSistema **usuarios_sistema - Inicio" << DEFAULT << endl; }
    if(this->getUtilUsuario() > 0){
        // Reservamos el nuevo tamaño
        Usuario** copia = 0;
        copia = new Usuario*[nueva_dim];

        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        if(nueva_dim > this->getUtilUsuario()){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtilUsuario(); i++){
                copia[i] = this->getUsuario(i);
            }

        }else if(nueva_dim < this->getUtilUsuario()){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getUsuario(i);
            }
        }else if(nueva_dim == this->getUtilUsuario()){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->getUtilUsuario(); i++){
            this->usuarios_sistema[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] usuarios_sistema;
        // Copiamos la nueva direccion
        this->usuarios_sistema = copia;
        // Actualizamos la util...
        this->setUtilUsuario(nueva_dim);
    }else{
        if(debug==true){ cout << DEBUG << "resize: Clase Vista: **usuarios_sistema - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->usuarios_sistema = new Usuario*[nueva_dim];
        this->setUtilUsuario(nueva_dim);
    }
    if(debug==true){ cout << DEBUG << "Vista::resizeUsuariosSistema **usuarios_sistema - Fin ejecucion" << DEFAULT << endl; }
}
void Vista::resizeCancionesSistema(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "Vista::resizeCancionesSistema **canciones_sistema - Inicio" << DEFAULT << endl; }
    if(this->getUtilCancion() > 0){
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
        if(nueva_dim > this->getUtilCancion()){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtilCancion(); i++){
                copia[i] = this->getCancion(i);
            }

        }else if(nueva_dim < this->getUtilCancion()){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getCancion(i);
            }
        }else if(nueva_dim == this->getUtilCancion()){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->getUtilCancion(); i++){
            this->canciones_sistema[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] canciones_sistema;
        // Copiamos la nueva direccion
        this->canciones_sistema = copia;
        // Actualizamos la util...
        this->setUtilCancion(nueva_dim);
    }else{
        if(debug==true){ cout << DEBUG << "Vista::resizeCancionesSistema **canciones_sistema - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->canciones_sistema = new Cancion*[nueva_dim];
        this->setUtilCancion(nueva_dim);
    }
    if(debug==true){ cout << DEBUG << "Vista::resizeCancionesSistema **canciones_sistema - Fin ejecucion" << DEFAULT << endl; }
}
void Vista::resizePlaylistsSistema(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "Vista::resizePlaylistsSistema **playlists_sistema - Inicio" << DEFAULT << endl; }
    
    if(this->getUtilPlaylist() > 0){
        // Reservamos el nuevo tamaño
        Playlist** copia = 0;
        copia = new Playlist*[nueva_dim];

        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        if(nueva_dim > this->getUtilPlaylist()){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtilPlaylist(); i++){
                copia[i] = this->getPlaylist(i);
            }

        }else if(nueva_dim < this->getUtilPlaylist()){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getPlaylist(i);
            }
        }else if(nueva_dim == this->getUtilPlaylist()){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->getUtilPlaylist(); i++){
            this->playlists_sistema[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] playlists_sistema;
        // Copiamos la nueva direccion
        this->playlists_sistema = copia;
        // Actualizamos la util...
        this->setUtilPlaylist(nueva_dim);
    }else{
        if(debug==true){ cout << DEBUG << "Vista::resizeCancionesSistema **canciones_sistema - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->playlists_sistema = new Playlist*[nueva_dim];
        this->setUtilPlaylist(nueva_dim);
    }
    if(debug==true){ cout << DEBUG << "Vista::resizePlaylistsSistema **playlists_sistema - Fin ejecucion" << DEFAULT << endl; }
}
void Vista::resizeArtistasSistema(const int &nueva_dim){
    if(debug==true){ cout << DEBUG << "Vista::resizeArtistasSistema **artistas_sistema - Inicio" << DEFAULT << endl; }

    if(this->getUtilArtista() > 0){
        // Reservamos el nuevo tamaño
        Artista** copia = 0;
        copia = new Artista*[nueva_dim];

        if(copia == 0){
            cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1); 
        }
        // Limpiamos el vector creado
        for(int i=0; i < nueva_dim; i++){
            copia[i] = NULL;
        }
        if(nueva_dim > this->getUtilArtista()){
            if(debug==true){ cout << DEBUG << "AUMENTAR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < this->getUtilArtista(); i++){
                copia[i] = this->getArtista(i);
            }

        }else if(nueva_dim < this->getUtilArtista()){
            if(debug==true){ cout << DEBUG << "DISMINUIR TAMAÑO" << DEFAULT << endl; }
            for(int i=0; i < nueva_dim; i++){
                copia[i] = this->getArtista(i);
            }
        }else if(nueva_dim == this->getUtilArtista()){
            if(debug==true){ cout << DEBUG << "No hay que hacer resize !" << DEFAULT << endl; }
        }
        // por seguridad, vacio el anterior
        for(int i=0; i<this->getUtilArtista(); i++){
            this->artistas_sistema[i] = NULL;
        }
        // Indicamos que la memoria vuelve a estar disponible
        delete [] artistas_sistema;
        // Copiamos la nueva direccion
        this->artistas_sistema = copia;
        // Actualizamos la util...
        this->setUtilArtista(nueva_dim);
    }else{
        if(debug==true){ cout << DEBUG << "Vista::resizeCancionesSistema **canciones_sistema - La lista estaba vacia, no hay que redimensionar" << DEFAULT << endl; }
        this->artistas_sistema = new Artista*[nueva_dim];
        this->setUtilArtista(nueva_dim);
    }
    if(debug==true){ cout << DEBUG << "Vista::resizeArtistasSistema **artistas_sistema - Fin ejecucion" << DEFAULT << endl; }
}
void Vista::menuSistemaLogin(){
    cout << GREEN << "BIENVENIDO AL SISTEMA SPOTY-KING" << DEFAULT << endl;
}
void Vista::menuSistemaAdministrador(){
    int opcion_panel = -1;
    do{
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                         PANEL DE ADMINISTRADOR                             =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << endl;
        cout << GREEN << "Sesión iniciada con Login: " << YELLOW << this->getUsuarioActivo()->getLogin() << DEFAULT << endl;
        cout << endl;
        cout << "1. Cerrar Sesión" << endl;
        cout << "2. Generar Datos Basicos del Sistema" << endl;
        cout << "3. Imprimir Datos Generales del Sistema" << endl;
        cout << "4. Rankings" << endl;
        cout << "\t4.1. Ranking Top3 General Canciones" << endl;
        cout << "\t4.2. Ranking Top3 por Tipo de Cancion" << endl;
        cout << "\t4.3. Ranking Artistas" << endl;
        cout << "5. Catalogo de Canciones del Sistema" << endl;
        cout << "\t5.1. Agregar Cancion al Catalogo del Sistema" << endl;
        cout << "\t5.2. Eliminar Cancion del Catalogo del Sistema" << endl;
        cout << "\t5.3. Buscar Canciones en el Catalogo del Sistema" << endl;
        cout << "\t5.4. Modificar Datos de la Cancion en el Catalogo del Sistema" << endl;
        cout << "\t5.5. Consultar Valoracion General de las Canciones del Sistema (en tiempo real)" << endl;
        cout << "6. Usuarios" << endl;
        cout << "\t6.1. Agregar Nuevo Usuario al Sistema" << endl;
        cout << "\t6.2. Eliminar Usuario del Sistema" << endl;
        cout << "\t6.3. Buscar Usuario en el Sistema" << endl;
        cout << "\t6.4. Modificar Datos Usuario del Sistema" << endl;
        cout << "7. Playlists" << endl;
        cout << "\t7.1. Buscar y Consultar Playlist (y sus detalles)" << endl;
        cout << "\t7.2. Eliminar Playlist" << endl;
        cout << "8. Destruir y Salir" << endl;
        cout << "9. EXTRAS REALIZADOS" << endl;
        cout << endl;
        
        do{
            cout << WHITE << "Introduzca el número correspondiente a la opción deseada: ";
            cin >> opcion_panel;
            cout << DEFAULT;
        }while(opcion_panel < 1 || opcion_panel > 7);
        if(opcion_panel == 1){
            cout << DEBUG << "Ha elegido Cerrar Sesión..." << DEFAULT << endl;
            pausa();
            loginAlSistema();
        }else if(opcion_panel == 2){
            cout << DEBUG << "Los datos fueron generados al ejecutarse la vista..." << DEFAULT << endl;
            pausa(); 
        }else if (opcion_panel == 3){
            imprimirDatos();
            pausa();
        }else if(opcion_panel == 4){
            cout << "Rankings" << endl;
            pausa();
        }else if(opcion_panel == 5){
            catalogoCancionesSistema();
        }else if(opcion_panel == 6){
            menuUsuariosAdministrador();
        }else if(opcion_panel == 7){
            menuUsuarioAdministradorPlaylists();
        }
    }while(opcion_panel != 1);
}
void Vista::menuSistemaUsuario(){
    int opcion_panel = -1;
    do{
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                            PANEL DE USUARIO                                =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << endl;
        cout << GREEN << "Sesión iniciada con Login: " << YELLOW << this->getUsuarioActivo()->getLogin() << DEFAULT << endl;
        cout << endl;
        cout << "1. Cerrar Sesión" << endl;
        cout << "2. Consultar Playlists del Usuario y Ver Canciones de Playlist" << endl;
        cout << "3. Agregar Cancion del Sistema a Playlist" << endl;
        cout << "4. Eliminar Cancion de una Playlist" << endl;
        cout << "5. Valorar una Cancion" << endl;
        cout << "6. Reproducir Cancion" << endl;
        cout << endl;
        
        int opcion_panel = -1;
        do{
            cout << "Introduzca el número correspondiente a la opción deseada: ";
            cin >> opcion_panel;
        }while(opcion_panel < 1 || opcion_panel > 6);
        if(opcion_panel == 1){
            cout << DEBUG << "Ha elegido Cerrar Sesión..." << DEFAULT << endl;
            pausa();
            loginAlSistema();
        }else if(opcion_panel == 2){
            menuUsuarioComunCancionesYPlaylists();
            pausa();
        }else if(opcion_panel == 3){
            menuUsuarioComunAgregarCancionAPlaylist();
            pausa();
        }else if(opcion_panel == 4){
            menuUsuarioComunEliminarCancionDePlaylist();
            pausa();
        }else if(opcion_panel == 5){
            menuSistemaUsuarioValorarUnaCancion();
        }else if(opcion_panel == 6){
            menuSistemaUsuarioReproducirUnaCancion();
            pausa();
        }
    }while(opcion_panel != 1);
}
void Vista::cargaInicial(){

    cout << DEBUG << "==== GENERAR LOS DATOS PREDEFINIDOS DEL SISTEMA =====" << DEFAULT << endl;
    // GENERANDO LOS ARTISTAS ESTÁTICOS Y TRABAJANDO CON SUS PUNTEROS
    cout << OK << "\nGENERANDO LOS ARTISTAS..." << DEFAULT << endl;

    // Artista Id 0
    Artista* ptr_five_finger = new Artista();
    ptr_five_finger->setId(0);
    ptr_five_finger->setNombre("Five_Finger_Death_Punch");
    this->setArtista(ptr_five_finger);
    //cout << "Generado el artista: " << OK << this->getArtista(0)->getNombre() << DEFAULT << endl;
    //cout << "Direccion: " << ptr_five_finger << endl;

    // Artista Id 1
    Artista* ptr_faraon_love_s = new Artista();
    ptr_faraon_love_s->setId(1);
    ptr_faraon_love_s->setNombre("Faraon_Love_Shady");
    this->setArtista(ptr_faraon_love_s);
    cout << "Generado el artista: " << OK << this->getArtista(1)->getNombre() << DEFAULT << endl;

    // Artista Id 2
    Artista* ptr_eminem = new Artista();
    ptr_eminem->setId(2);
    ptr_eminem->setNombre("Eminem");
    this->setArtista(ptr_eminem);
    cout << "Generado el artista: " << OK << this->getArtista(2)->getNombre() << DEFAULT << endl;
    
    // Artista Id 3
    Artista* ptr_juice = new Artista();
    ptr_juice->setId(3);
    ptr_juice->setNombre("Juice_WRLD");
    this->setArtista(ptr_juice);
    cout << "Generado el artista: " << OK << this->getArtista(3)->getNombre() << DEFAULT << endl;

    // Artista Id 4
    Artista* ptr_michael = new Artista();
    ptr_michael->setId(4);
    ptr_michael->setNombre("Michael_Jackson");
    this->setArtista(ptr_michael);
    cout << "Generado el artista: " << OK << this->getArtista(4)->getNombre() << DEFAULT << endl;

    // Artista Id 5
    Artista* ptr_twenty = new Artista();
    ptr_twenty->setId(5);
    ptr_twenty->setNombre("Twenty_One_Pilots");
    this->setArtista(ptr_twenty);
    cout << "Generado el artista: " << OK << this->getArtista(5)->getNombre() << DEFAULT << endl;

    // Artista Id 6
    Artista* ptr_coolio = new Artista();
    ptr_coolio->setId(6);
    ptr_coolio->setNombre("Coolio");
    this->setArtista(ptr_coolio);
    cout << "Generado el artista: " << OK << this->getArtista(6)->getNombre() << DEFAULT << endl;
	

    // GENERANDO LAS CANCIONES ESTÁTITAS Y TRABAJANDO CON SUS PUNTEROS
    cout << OK << "\nGENERANDO LAS CANCIONES..." << DEFAULT << endl;

    // Cancion Id 0
    Metal* ptr_inside_out = new Metal();
    ptr_inside_out->setIdCancion(0);
    ptr_inside_out->setTitulo("Inside_Out");
    ptr_inside_out->setRuta("../canciones/metal/InsideOut.mp3");
    ptr_inside_out->setArtista(ptr_five_finger);
    Tiempo t_inside_out(3, 46);
    ptr_inside_out->setDuracion(t_inside_out);
    ptr_inside_out->setReproducciones(3897);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    //cout << "Direccion del puntero Cancion ID 0: " << ptr_inside_out << endl;
    this->setCancion(ptr_inside_out);
    //cout << "Generada la cancion ID 0 en Carga: " << OK << this->getCancion(0) << DEFAULT << endl;
    
	
    // Cancion Id 1
    Metal* ptr_house_of = new Metal();
    ptr_house_of->setIdCancion(1);
    ptr_house_of->setTitulo("House_of_the_Rising_Sun");
    ptr_house_of->setRuta("canciones/metal/HouseOfTheRisingSun.mp3");
    ptr_house_of->setArtista(ptr_five_finger);
    Tiempo t_house_of(4, 7);
    ptr_house_of->setDuracion(t_house_of);
    ptr_house_of->setReproducciones(5213);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_house_of);
    cout << "Generada la cancion: " << OK << this->getCancion(1)->getTitulo() << DEFAULT << endl;

    // Cancion Id 2
    Rap* ptr_the_real_slim = new Rap();
    ptr_the_real_slim->setIdCancion(2);
    ptr_the_real_slim->setTitulo("The_Real_Slim_Shady");
    ptr_the_real_slim->setRuta("canciones/rap/TheRealSlimShady.mp3");
    ptr_the_real_slim->setArtista(ptr_eminem);
    Tiempo t_the_real_slim(4, 44);
    ptr_the_real_slim->setDuracion(t_the_real_slim);
    ptr_the_real_slim->setReproducciones(9172);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_the_real_slim);
    cout << "Generada la cancion: " << OK << this->getCancion(2)->getTitulo() << DEFAULT << endl;

    // Cancion Id 3
    Faraon* ptr_i_am_happy = new Faraon();
    ptr_i_am_happy->setIdCancion(3);
    ptr_i_am_happy->setTitulo("I_Am_Happy");
    ptr_i_am_happy->setRuta("canciones/faraon/IAmHappy.mp3");
    ptr_i_am_happy->setArtista(ptr_faraon_love_s);
    Tiempo t_i_am_happy(2, 15);
    ptr_i_am_happy->setDuracion(t_i_am_happy);
    ptr_i_am_happy->setReproducciones(9028);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_i_am_happy);
    cout << "Generada la cancion: " << OK << this->getCancion(3)->getTitulo() << DEFAULT << endl;

    // Cancion Id 4
    Rap* ptr_godzilla = new Rap();
    ptr_godzilla->setIdCancion(4);
    ptr_godzilla->setTitulo("Godzilla");
    ptr_godzilla->setRuta("canciones/rap/Godzilla.mp3");
    ptr_godzilla->setArtista(ptr_eminem);
    ptr_godzilla->setArtista(ptr_juice);
    Tiempo t_godzilla(3, 31);
    ptr_godzilla->setDuracion(t_godzilla);
    ptr_godzilla->setReproducciones(6523);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_godzilla);
    cout << "Generada la cancion: " << OK << this->getCancion(4)->getTitulo() << DEFAULT << endl;

    // Cancion Id 5
    Pop* ptr_billie = new Pop();
    ptr_billie->setIdCancion(5);
    ptr_billie->setTitulo("Billie_Jean");
    ptr_billie->setRuta("canciones/pop/BillieJean.mp3");
    ptr_billie->setArtista(ptr_michael);
    Tiempo t_billie(4, 53);
    ptr_billie->setDuracion(t_billie);
    ptr_billie->setReproducciones(12559);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_billie);
    cout << "Generada la cancion: " << OK << this->getCancion(5)->getTitulo() << DEFAULT << endl;

    // Cancion Id 6
    Pop* ptr_beat = new Pop();
    ptr_beat->setIdCancion(6);
    ptr_beat->setTitulo("Beat_It");
    ptr_beat->setRuta("canciones/pop/BeatIt.mp3");
    ptr_beat->setArtista(ptr_michael);
    Tiempo t_beat(4, 18);
    ptr_beat->setDuracion(t_beat);
    ptr_beat->setReproducciones(12559);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_beat);
    cout << "Generada la cancion: " << OK << this->getCancion(6)->getTitulo() << DEFAULT << endl;

    // Cancion Id 7
    Pop* ptr_stressed = new Pop();
    ptr_stressed->setIdCancion(7);
    ptr_stressed->setTitulo("Stressed_Out");
    ptr_stressed->setRuta("canciones/pop/StressedOut.mp3");
    ptr_stressed->setArtista(ptr_twenty);
    Tiempo t_stressed(3, 22);
    ptr_stressed->setDuracion(t_stressed);
    ptr_stressed->setReproducciones(4982);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_stressed);
    cout << "Generada la cancion: " << OK << this->getCancion(7)->getTitulo() << DEFAULT << endl;

    // Cancion Id 8
    Rap* ptr_gangstas = new Rap();
    ptr_gangstas->setIdCancion(8);
    ptr_gangstas->setTitulo("Gangstas_Paradise");
    ptr_gangstas->setRuta("canciones/rap/GangstasParadise.mp3");
    ptr_gangstas->setArtista(ptr_coolio);
    Tiempo t_gangstas(4, 0);
    ptr_gangstas->setDuracion(t_gangstas);
    ptr_gangstas->setReproducciones(6543);
    // falta por CREAR el total_inclusiones_en_playlist_en_sistema
    this->setCancion(ptr_gangstas);
    cout << "Generada la cancion: " << OK << this->getCancion(8)->getTitulo() << DEFAULT << endl;


    // GENERANDO PLAYLISTS ESTÁTICAS Y TRABAJANDO CON SUS PUNTEROS
    cout << OK << "\nGENERANDO LAS PLAYLISTS..." << DEFAULT << endl;

    // Playlist 0 delegado
    Playlist* ptr_metal_ffdp = new Playlist();
    ptr_metal_ffdp->setId(0);
    ptr_metal_ffdp->setNombre("Metal-FFDP");
    ptr_metal_ffdp->setCancion(ptr_inside_out);
    ptr_metal_ffdp->setCancion(ptr_house_of);
	ptr_metal_ffdp->setCancion(ptr_gangstas);
    //cout << "imprimo la playlist 0 delegado" << endl;
    //cout << *ptr_metal_ffdp;
    cout << "Generada la Playlist: " << OK << ptr_metal_ffdp->getNombre() << DEFAULT << endl;
    //cout << "termina la playlist" << endl;
    //this->usuarios_sistema[1]->
    //cout << "agregada" << endl;
    // cout << "Generada la Playlist: " << this->...
    // La inserto en las Playlists del Sistema
    this->setPlaylist(ptr_metal_ffdp);

    // Playlist 1 delegado
    Playlist* ptr_pl_rap = new Playlist();
    ptr_pl_rap->setId(1);
    ptr_pl_rap->setNombre("Rap");
    ptr_pl_rap->setCancion(ptr_the_real_slim);
    ptr_pl_rap->setCancion(ptr_gangstas);
    cout << "Generada la Playlist: " << OK << ptr_pl_rap->getNombre() << DEFAULT << endl;
    // La inserto en las Playlists del Sistema
    this->setPlaylist(ptr_pl_rap);

    // Playlist 2 delegado
    Playlist* ptr_pl_twenty = new Playlist();
    ptr_pl_twenty->setId(2);
    ptr_pl_twenty->setNombre("Twenty_One_Pilots");
    ptr_pl_twenty->setCancion(ptr_stressed);
    ptr_pl_twenty->setCancion(ptr_gangstas);
    cout << "Generada la Playlist: " << OK << ptr_pl_twenty->getNombre() << DEFAULT << endl;
    // La inserto en las Playlists del Sistema
    this->setPlaylist(ptr_pl_twenty);

    // Playlist 0 tifurz
    Playlist* ptr_pl_pop = new Playlist();
    ptr_pl_pop->setId(3);
    ptr_pl_pop->setNombre("Pop");
    ptr_pl_pop->setCancion(ptr_billie);
    ptr_pl_pop->setCancion(ptr_beat);
    ptr_pl_pop->setCancion(ptr_stressed);
    ptr_pl_pop->setCancion(ptr_gangstas);
    cout << "Generada la Playlist: " << OK << ptr_pl_pop->getNombre() << DEFAULT << endl;
    // La inserto en las Playlists del Sistema
    this->setPlaylist(ptr_pl_pop);


    // GENERANDO LOS USUARIOS
    cout << OK << "\nGENERANDO LOS USUARIOS..." << DEFAULT << endl;

    // ID 0 : delegado
    UsuarioComun* ptr_uc_delegado = new UsuarioComun();
    ptr_uc_delegado->setId(0);
    ptr_uc_delegado->setLogin("delegado");
    ptr_uc_delegado->setPassword("quecaloh12");
    ptr_uc_delegado->agregarCancionAUsuario(ptr_inside_out);
    ptr_uc_delegado->agregarCancionAUsuario(ptr_house_of);
    ptr_uc_delegado->agregarCancionAUsuario(ptr_the_real_slim);
    ptr_uc_delegado->agregarCancionAUsuario(ptr_stressed);
    ptr_uc_delegado->agregarCancionAUsuario(ptr_gangstas);
    ptr_uc_delegado->agregarPlaylistAUsuario(ptr_metal_ffdp);
    ptr_uc_delegado->agregarPlaylistAUsuario(ptr_pl_rap);
    ptr_uc_delegado->agregarPlaylistAUsuario(ptr_pl_twenty);
    // Lo añadimos al Sistema
    this->setUsuario(ptr_uc_delegado);
    cout << "Generado el Usuario: " << OK << this->getUsuario(0)->getLogin() << DEFAULT << endl;
    // cout << "imprimo el usuario Delegado" << endl;
    // cout << this->getUsuario(0) << endl;
    // cout << "fin imprimo Delegado" << endl;
    

    // ID 1 : tifurz
    UsuarioComun* ptr_uc_tifurz = new UsuarioComun();
    ptr_uc_tifurz->setId(1);
    ptr_uc_tifurz->setLogin("tifurz");
    ptr_uc_tifurz->setPassword("elyayo");
    ptr_uc_tifurz->agregarCancionAUsuario(ptr_i_am_happy);
    ptr_uc_tifurz->agregarCancionAUsuario(ptr_billie);
    ptr_uc_tifurz->agregarCancionAUsuario(ptr_beat);
    ptr_uc_tifurz->agregarCancionAUsuario(ptr_stressed);
    ptr_uc_tifurz->agregarCancionAUsuario(ptr_gangstas);
    ptr_uc_tifurz->agregarPlaylistAUsuario(ptr_pl_pop);
    // Lo añadimos al Sistema
    this->setUsuario(ptr_uc_tifurz);
    cout << "Generado el Usuario: " << OK << this->getUsuario(1)->getLogin() << DEFAULT << endl;

    // ID 2 : neozizou
    UsuarioAdministrador* ptr_ua_neozizou = new UsuarioAdministrador();
    ptr_ua_neozizou->setId(2);
    ptr_ua_neozizou->setLogin("neozizou");
    ptr_ua_neozizou->setPassword("zizougod");
    // Lo añadimos al Sistema
    this->setUsuario(ptr_ua_neozizou);
    cout << "Generado el UsuarioAdministrador: " << OK << this->getUsuario(2)->getLogin() << DEFAULT << endl;

}
void Vista::imprimirDatos(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                 TODOS LOS DATOS CARGADOS EN EL SISTEMA                     =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << endl << endl;
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    cout << GREEN << "=                                ARTISTAS                                    =" << DEFAULT << endl;
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    cout << endl;
    for(int i = 0; i < this->getUtilArtista(); i++){
        cout << *this->artistas_sistema[i] << endl;
    }
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    cout << GREEN << "=                                CANCIONES                                   =" << DEFAULT << endl;
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    cout << endl;
    for(int i = 0; i < this->getUtilCancion(); i++){
        cout << *this->getCancion(i) << endl;
    }
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    cout << GREEN << "=                                USUARIOS                                    =" << DEFAULT << endl;
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    cout << endl;
    for(int i = 0; i < this->getUtilUsuario(); i++){
        cout << endl;
        cout << DEBUG << "================================================================================================" << DEFAULT << endl;
        cout << WHITE << this->getUsuario(i)->getLogin() << DEFAULT << endl;
        cout << DEBUG << "================================================================================================" << DEFAULT << endl;
        cout << endl;
        UsuarioComun* ptr_imprime = dynamic_cast<UsuarioComun*>(this->getUsuario(i));
        if(ptr_imprime != nullptr){
            cout << GREEN << "==============================================================================" << DEFAULT << endl;
            cout << OK << "=                            PLAYLISTS DEL USUARIO                           =" << DEFAULT << endl;
            cout << GREEN << "==============================================================================" << DEFAULT << endl;
            for(int i = 0; i < ptr_imprime->getUtilPlaylistUsuario(); i++){
            cout << "PLAYLIST " << i << endl;
            cout << *ptr_imprime->getPlaylistUsuario(i);
            cout << endl;
            }
            cout << GREEN << "==============================================================================" << DEFAULT << endl;
            cout << OK << "=                            CANCIONES DEL USUARIO                           =" << DEFAULT << endl;
            cout << GREEN << "==============================================================================" << DEFAULT << endl;
            for(int i = 0; i < ptr_imprime->getUtilCancionesUsuario(); i++){
            cout << "CANCION " << i << endl;
            cout << *ptr_imprime->getCancionUsuario(i);
            cout << endl;
            }
        }
    }
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    cout << OK << "=                            PLAYLISTS DEL SISTEMA                            =" << DEFAULT << endl;
    cout << GREEN << "==============================================================================" << DEFAULT << endl;
    for(int i = 0; i < this->getUtilPlaylist(); i++){
    cout << "PLAYLIST DEL SISTEMA " << this->getPlaylist(i)->getId() << endl;
    cout << *this->getPlaylist(i);
    cout << endl;
    }
    cout << endl;
    cout << OK << "========== ESTADÍSTICAS ==========" << DEFAULT << endl;
    cout << WHITE << "Artistas Totales = " << MAGENTA << this->getUtilArtista() << DEFAULT << endl;
    cout << WHITE << "Canciones Totales = " << MAGENTA << this->getUtilCancion() << DEFAULT << endl;
    cout << WHITE << "Playlists Totales = " << MAGENTA << this->getUtilPlaylist() << DEFAULT << endl;
    cout << WHITE << "Usuarios Totales = " << MAGENTA << this->getUtilUsuario() << DEFAULT << endl;
    Tiempo total_t_pl;
    for(int i = 0; i < this->getUtilPlaylist(); i++){
        total_t_pl = total_t_pl + this->getPlaylist(i)->getDuracion();
    }
    cout << WHITE << "Duración Total de Playlist = " << MAGENTA << total_t_pl << DEFAULT << endl;
    Tiempo total_t_canciones;
    for(int i = 0; i < this->getUtilCancion(); i++){
        total_t_canciones = total_t_canciones + this->getCancion(i)->getDuracion();
    }
    cout << WHITE << "Duración Total de Canciones = " << MAGENTA << total_t_canciones << DEFAULT << endl;
    cout << endl;

}
void Vista::loginAlSistema(){
    this->setUsuarioActivo(this->getUsuario(-1));
    bool login_correcto = false;
    bool password_correcto = false;
    do{
        login_correcto = false;
        password_correcto = false;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                            INICIO DE SESIÓN                                =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << endl;
        string login_a = "NULL";
        cout << USER << "Introduzca el login: " << YELLOW;
        cin >> login_a;
        cout << DEFAULT;
        // Comprobación del login
        // Usuario* el_activo = new Usuario*();
        for(int i = 0; i < this->getUtilUsuario() && login_correcto == false; i++){
            if(login_a == this->getUsuario(i)->getLogin()){
                string password_a = "NULL";
                cout << USER << "Introduzca el password: " << YELLOW;
                cin >> password_a;
                cout << DEFAULT;
                login_correcto = true;
                if(password_a == this->getUsuario(i)->getPassword()){
                    password_correcto = true;
                    //cout << "entra_login:correcto" << endl;
                    cout << endl;
                    UsuarioComun* juan = dynamic_cast<UsuarioComun*>(this->getUsuario(i));
                    if(juan != nullptr){
                        //cout << "222entra_login:correcto" << endl;
                        this->setUsuarioActivo(this->getUsuario(i));
                        menuSistemaUsuario();
                    }else if(dynamic_cast<UsuarioAdministrador*>(this->getUsuario(i)) != nullptr){
                        //cout << "4444entra_login:correcto" << endl;
                        this->setUsuarioActivo(this->getUsuario(i));
                        menuSistemaAdministrador();
                    }
                    //cout << "sale_login:correcto" << endl;
                }
            }
        }
        if(login_correcto == true && password_correcto == false){
            cout << DEBUG << "Password erróneo :(" << DEFAULT << endl;
            cout << endl;
        }else if(login_correcto == false){
            cout << DEBUG << "Usuario no encontrado :(" << DEFAULT << endl;
            cout << endl;
        }
    }while(login_correcto == false || (login_correcto == true && password_correcto == false));
}
void Vista::busquedaCancion(){
    int opcion_busqueda = -1;
    do{
        opcion_busqueda = -1;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                             BÚSQUEDA DE CANCIÓN                            =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Artistas en la Base de Datos: " << this->getUtilArtista() << DEFAULT << endl;
        cout << WHITE << "Total de Canciones en la Base de Datos: " << this->getUtilCancion() << DEFAULT << endl;
        cout << endl;
        cout << "\t0. Salir" << DEFAULT << endl;
        cout << "\t1. Buscar por " << GREEN << "Nombre de Artista" << DEFAULT << endl;
        //cout << "\t2. Buscar por " << GREEN << "Título de Canción" << DEFAULT << endl;
        cout << endl;
        
        while(opcion_busqueda != 1 && opcion_busqueda != 2 && opcion_busqueda != 0){
            cout << "Introduzca el número correspondiente al criterio de búsqueda: ";
            cin >> opcion_busqueda;
        }
        cout << endl;
        if(opcion_busqueda == 0){
            cout << DEBUG << "Ha decidido Salir..." << DEFAULT << endl;
            pausa();
        }else if(opcion_busqueda == 1){
            busquedaCancionArtista();
        }else if(opcion_busqueda == 2){

        }
    }while(opcion_busqueda != 0);
}
void Vista::busquedaPlaylist(){
    int opcion_busqueda = -1;
    do{
        opcion_busqueda = -1;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                              BÚSQUEDA PLAYLIST                             =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Artistas en la Base de Datos: " << this->getUtilArtista() << DEFAULT << endl;
        cout << WHITE << "Total de Canciones en la Base de Datos: " << this->getUtilCancion() << DEFAULT << endl;
        cout << endl;
        cout << "\t0. Salir" << DEFAULT << endl;
        cout << "\t1. Buscar por " << GREEN << "Nombre de Playlist" << DEFAULT << endl;
        //cout << "\t2. Buscar por " << GREEN << "Título de Canción" << DEFAULT << endl;
        cout << endl;
        
        while(opcion_busqueda != 1 && opcion_busqueda != 0){
            cout << "Introduzca el número correspondiente a la opción: ";
            cin >> opcion_busqueda;
        }
        cout << endl;
        if(opcion_busqueda == 0){
            cout << DEBUG << "Ha decidido Salir..." << DEFAULT << endl;
            pausa();
        }else if(opcion_busqueda == 1){
            busquedaPlaylistPorNombre();
        }else if(opcion_busqueda == 2){

        }
    }while(opcion_busqueda != 0);
}
void Vista::busquedaPlaylistPorNombre(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                       BÚSQUEDA PLAYLIST POR NOMBRE                         =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << endl;
    string nombre_playlist_buscar = "NULL";
    cout << "Introduzca el " << GREEN << "Nombre de Playlist" << DEFAULT << " que desea Buscar: " << YELLOW;
    cin >> nombre_playlist_buscar;
    cout << DEFAULT;
    //Playlist** resultados_pl;
    bool nombre_encontrado = false;
    int posicion_pl_encontrada = -1;
    for(int i = 0; i < this->getUtilPlaylist() && nombre_encontrado == false; i++){
        if(nombre_playlist_buscar == this->getPlaylist(i)->getNombre()){
            nombre_encontrado = true;
            posicion_pl_encontrada = i;
            cout << GREEN << "\nPlaylist encontrada :)\n" << DEFAULT << endl;

        }
    }
    if(nombre_encontrado == false){
        cout << DEBUG << "\nLo sentimos :(" << DEFAULT << endl;
        cout << DEBUG << "El Nombre de Playlist " << YELLOW << nombre_playlist_buscar << DEBUG << " no se encuentra en la Base de Datos..." << DEFAULT << endl;
    }else if(nombre_encontrado == true){
        cout << "¿Desea ver todas las Canciones que contiene la Playlist? [s/n]: ";
        char ver_canciones_pl = 'a';
        while(ver_canciones_pl != 's' && ver_canciones_pl!='n'){
            cin >> ver_canciones_pl;
        }
        if(ver_canciones_pl == 's'){
            cout << endl;
            cout << "Canciones de la Playlist " << YELLOW << this->getPlaylist(posicion_pl_encontrada)->getNombre() << DEFAULT << endl;
            //cout << this->getCancion(4)->getTitulo() << endl;
            for(int i = 0; i < this->getPlaylist(posicion_pl_encontrada)->getUtil(); i++){                
                cout << GREEN << i+1 << " " << YELLOW << this->getPlaylist(posicion_pl_encontrada)->getCancion(i)->getTitulo() << DEFAULT;
                for(int j = 0; j < this->getPlaylist(posicion_pl_encontrada)->getCancion(i)->getUtil(); j++){
                    cout << " " << MAGENTA << *this->getPlaylist(posicion_pl_encontrada)->getCancion(i)->getArtista(j) << DEFAULT;
                }
            cout << endl;
            }
        }
    }
    cout << endl;
    pausa();
}
void Vista::busquedaCancionArtista(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                            BÚSQUEDA POR ARTISTA                            =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << endl;
    string nombre_artista_buscar = "NULL";
    cout << "Introduzca el " << GREEN << "Nombre de Artista" << DEFAULT << " que desea Buscar: " << YELLOW;
    cin >> nombre_artista_buscar;
    DEFAULT;
    bool artista_encontrado = false;
    int posicion_artista_encontrado = -1;
    for(int i = 0; i < this->getUtilArtista() && artista_encontrado == false; i++){
        if(nombre_artista_buscar == this->getArtista(i)->getNombre()){
            artista_encontrado = true;
            posicion_artista_encontrado = i;
            cout << GREEN << "\nArtista encontrado :)\n" << DEFAULT << endl;
        }
    }
    if(artista_encontrado == false){
        cout << DEBUG << "\nLo sentimos :(" << DEFAULT << endl;
        cout << DEBUG << "El Artista " << YELLOW << nombre_artista_buscar << DEBUG << " no se encuentra en la Base de Datos..." << DEFAULT << endl;
    }else if(artista_encontrado == true){
        cout << "¿Desea ver todas las Canciones del Artista que contiene la Base de Datos? [s/n]: ";
        char ver_canciones_artista = 'a';
        while(ver_canciones_artista != 's' && ver_canciones_artista!='n'){
            cin >> ver_canciones_artista;
        }
        if(ver_canciones_artista == 's'){
            cout << endl;
            cout << "Canciones de " << YELLOW << this->getArtista(posicion_artista_encontrado)->getNombre() << DEFAULT << endl;
            //cout << this->getCancion(4)->getTitulo() << endl;
            for(int i = 0; i < this->getUtilCancion(); i++){
                if(this->getCancion(i)->getArtista(0)->getNombre() == this->getArtista(posicion_artista_encontrado)->getNombre()){
                    cout << GREEN << "ID: " << YELLOW << this->getCancion(i)->getId() << GREEN << "\tTítulo: " << YELLOW << this->getCancion(i)->getTitulo() << DEFAULT << endl;
                }
            }
        }
    }
    cout << endl;
    pausa();
}
void Vista::catalogoCancionesSistema(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                      CATÁLOGO DE CANCIONES DEL SISTEMA                     =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << WHITE << "Total de Artistas en la Base de Datos: " << this->getUtilArtista() << DEFAULT << endl;
    cout << WHITE << "Total de Canciones en la Base de Datos: " << this->getUtilCancion() << DEFAULT << endl;
    cout << endl;
    cout << "\t0. Salir" << endl;
    cout << "\t1. Agregar Canción al Catalogo del Sistema" << endl;
    cout << "\t2. Eliminar Canción del Catalogo del Sistema" << endl;
    cout << "\t3. Buscar Canciones en el Catalogo del Sistema" << endl;
    cout << "\t4. Modificar Datos de la Cancion en el Catalogo del Sistema" << endl;
    cout << "\t5. Consultar Valoracion General de las Canciones del Sistema (en tiempo real)" << endl;
    cout << endl;
    int opcion_canciones_catalogo_sistema = -1;
    while(opcion_canciones_catalogo_sistema < 0 || opcion_canciones_catalogo_sistema > 5){
        cout << WHITE << "Introduzca el número correspondiente a la opción deseada: " << DEFAULT;
        cin >> opcion_canciones_catalogo_sistema;
    }
    if(opcion_canciones_catalogo_sistema == 0){
        cout << DEBUG << "Ha decidido abandonar..." << DEFAULT << endl;
        pausa();
        cout << "pausa1" << endl;
    }else if(opcion_canciones_catalogo_sistema == 1){
        agregarCancionCatalogoSistema();
    }else if(opcion_canciones_catalogo_sistema == 2){
        menuUsuarioAdministradorEliminarCancionDelSistema();
    }else if(opcion_canciones_catalogo_sistema == 3){
        busquedaCancion();
    }else if(opcion_canciones_catalogo_sistema == 4){
        ModificarCancionSistema();
    }else if(opcion_canciones_catalogo_sistema == 5){
        cout << "En construccion" << endl;
    }

}
void Vista::agregarCancionCatalogoSistema(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                  AGREGAR CANCIÓN AL CATÁLOGO DEL SISTEMA                   =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << WHITE << "Total de Artistas en la Base de Datos: " << this->getUtilArtista() << DEFAULT << endl;
    cout << WHITE << "Total de Canciones en la Base de Datos: " << this->getUtilCancion() << DEFAULT << endl;
    cout << endl;
    cout << "Nuevos parámetros de la Canción:" << endl;
    // Pedimos el Género
    cout << GREEN <<"Géneros disponibles:" << DEFAULT << endl;
    cout << YELLOW << "\t1. " << GREEN << "Metal" << DEFAULT << endl;
    cout << YELLOW << "\t2. " << GREEN << "Pop" << DEFAULT << endl;
    cout << YELLOW << "\t3. " << GREEN << "Rap" << DEFAULT << endl;
    cout << YELLOW << "\t4. " << GREEN << "Faraon" << DEFAULT << endl;
    int genero_elegido = -1;
    while(genero_elegido <= 0 || genero_elegido > 4){
        cout << "Introduzca el número correspondiente al Género de la Canción: " << YELLOW;
        cin >> genero_elegido;
        cout << DEFAULT;
    }
    // Creamos la subclase e insertamos en vector
    if(genero_elegido == 1){
        // Generamos espacio para el puntero según el género elegido
        Metal* nueva_metal = new Metal();
        // Pedimos los parámetros...
        int nuevo_id = this->getUtilCancion();
        cout << GREEN << "ID (generado automáticamente): " << YELLOW << nuevo_id << DEFAULT << endl;
        nueva_metal->setIdCancion(nuevo_id);
        // Pedimos nuevo título
        string nuevo_titulo = "NULL";
        cout << GREEN << "Titulo: " << YELLOW ;
        cin >> nuevo_titulo;
        nueva_metal->setTitulo(nuevo_titulo);
        // Pedimos nueva ruta
        string nueva_ruta = "NULL";
        cout << GREEN << "Ruta: " << YELLOW;
        cin >> nueva_ruta;
        nueva_metal->setRuta(nueva_ruta);
        // Pedimos nuevo Artista
        int id_artista_elegido = -1;
            char opcion_agregar_mas_artistas = 'a';
            while(opcion_agregar_mas_artistas != 'n'){

                cout << GREEN << "Artistas disponibles:" << DEFAULT << endl;
                for(int i = 0; i < this->getUtilArtista(); i++){
                    cout << YELLOW << "\t" << this->getArtista(i)->getId() << " " << *this->getArtista(i) << DEFAULT << endl;
                }
                id_artista_elegido = -1;
                while(id_artista_elegido < 0 || id_artista_elegido >= this->getUtilArtista()){
                    cout << GREEN << "Introduzca el ID del Artista al que desea añadir a la Canción: " << YELLOW;
                    cin >> id_artista_elegido;
                    DEFAULT;
                }
                // Insertamos el Artista
                nueva_metal->setArtista(this->getArtista(id_artista_elegido));
                // Damos la opción de añadir más Artistas
                cout << WHITE << "¿Desea introducir un Artista más? [s/n]: " << DEFAULT;
                cin >> opcion_agregar_mas_artistas;
            }
        // Pedimos nueva Duración
        int minutos = -1, segundos = -1;
        cout << GREEN << "Duración: " << DEFAULT << endl;
        while(minutos < 0 || minutos > 59){
            cout << GREEN << "\tMinutos: " << YELLOW;
            cin >> minutos;
            cout << DEFAULT;
        }
        while(segundos < 0 || segundos >59){
            cout << GREEN << "\tSegundos: " << YELLOW;
            cin >> segundos;
            cout << DEFAULT;
        }
        Tiempo nuevo_tiempo(minutos, segundos);
        nueva_metal->setDuracion(nuevo_tiempo);
        // Pedimos nuevo Total Reproducciones
        int nuevo_total_reproducciones = -1;
            while(nuevo_total_reproducciones < 0 || nuevo_total_reproducciones > 32000){
                cout << GREEN << "Nuevo Total Reproducciones: " << YELLOW;
                cin >> nuevo_total_reproducciones;
        }
        nueva_metal->setReproducciones(nuevo_total_reproducciones);
        // Insertamos la nueva canción
        this->setCancion(nueva_metal);
        cout << MAGENTA <<  "Nueva canción Metal generada:" << DEFAULT << endl;
        cout << *nueva_metal << endl;
        cout << MAGENTA << "Canción Metal añadida!!" << DEFAULT << endl;
    }else if(genero_elegido == 2){
        // Generamos espacio para el puntero según el género elegido
        Pop* nueva_pop = new Pop();
        // Pedimos los parámetros...
        int nuevo_id = this->getUtilCancion();
        cout << GREEN << "ID (generado automáticamente): " << YELLOW << nuevo_id << DEFAULT << endl;
        nueva_pop->setIdCancion(nuevo_id);
        // Pedimos nuevo título
        string nuevo_titulo = "NULL";
        cout << GREEN << "Titulo: " << YELLOW ;
        cin >> nuevo_titulo;
        nueva_pop->setTitulo(nuevo_titulo);
        // Pedimos nueva ruta
        string nueva_ruta = "NULL";
        cout << GREEN << "Ruta: " << YELLOW;
        cin >> nueva_ruta;
        nueva_pop->setRuta(nueva_ruta);
        // Pedimos nuevo Artista
        int id_artista_elegido = -1;
            char opcion_agregar_mas_artistas = 'a';
            while(opcion_agregar_mas_artistas != 'n'){

                cout << GREEN << "Artistas disponibles:" << DEFAULT << endl;
                for(int i = 0; i < this->getUtilArtista(); i++){
                    cout << YELLOW << "\t" << this->getArtista(i)->getId() << " " << *this->getArtista(i) << DEFAULT << endl;
                }
                id_artista_elegido = -1;
                while(id_artista_elegido < 0 || id_artista_elegido >= this->getUtilArtista()){
                    cout << GREEN << "Introduzca el ID del Artista al que desea añadir a la Canción: " << YELLOW;
                    cin >> id_artista_elegido;
                    DEFAULT;
                }
                // Insertamos el Artista
                nueva_pop->setArtista(this->getArtista(id_artista_elegido));
                // Damos la opción de añadir más Artistas
                cout << WHITE << "¿Desea introducir un Artista más? [s/n]: " << DEFAULT;
                cin >> opcion_agregar_mas_artistas;
            }
        // Pedimos nueva Duración
        int minutos = -1, segundos = -1;
        cout << GREEN << "Duración: " << DEFAULT << endl;
        while(minutos < 0 || minutos > 59){
            cout << GREEN << "\tMinutos: " << YELLOW;
            cin >> minutos;
            cout << DEFAULT;
        }
        while(segundos < 0 || segundos >59){
            cout << GREEN << "\tSegundos: " << YELLOW;
            cin >> segundos;
            cout << DEFAULT;
        }
        Tiempo nuevo_tiempo(minutos, segundos);
        nueva_pop->setDuracion(nuevo_tiempo);
        // Pedimos nuevo Total Reproducciones
        int nuevo_total_reproducciones = -1;
            while(nuevo_total_reproducciones < 0 || nuevo_total_reproducciones > 32000){
                cout << GREEN << "Nuevo Total Reproducciones: " << YELLOW;
                cin >> nuevo_total_reproducciones;
        }
        nueva_pop->setReproducciones(nuevo_total_reproducciones);
        // Insertamos la nueva canción
        this->setCancion(nueva_pop);
        cout << MAGENTA <<  "Nueva canción Pop generada:" << DEFAULT << endl;
        cout << *nueva_pop << endl;
        cout << MAGENTA << "Canción Pop añadida!!" << DEFAULT << endl;
    }else if(genero_elegido == 3){
        // Generamos espacio para el puntero según el género elegido
        Rap* nueva_rap = new Rap();
        // Pedimos los parámetros...
        int nuevo_id = this->getUtilCancion();
        cout << GREEN << "ID (generado automáticamente): " << YELLOW << nuevo_id << DEFAULT << endl;
        nueva_rap->setIdCancion(nuevo_id);
        // Pedimos nuevo título
        string nuevo_titulo = "NULL";
        cout << GREEN << "Titulo: " << YELLOW ;
        cin >> nuevo_titulo;
        nueva_rap->setTitulo(nuevo_titulo);
        // Pedimos nueva ruta
        string nueva_ruta = "NULL";
        cout << GREEN << "Ruta: " << YELLOW;
        cin >> nueva_ruta;
        nueva_rap->setRuta(nueva_ruta);
        // Pedimos nuevo Artista
        int id_artista_elegido = -1;
            char opcion_agregar_mas_artistas = 'a';
            while(opcion_agregar_mas_artistas != 'n'){

                cout << GREEN << "Artistas disponibles:" << DEFAULT << endl;
                for(int i = 0; i < this->getUtilArtista(); i++){
                    cout << YELLOW << "\t" << this->getArtista(i)->getId() << " " << *this->getArtista(i) << DEFAULT << endl;
                }
                id_artista_elegido = -1;
                while(id_artista_elegido < 0 || id_artista_elegido >= this->getUtilArtista()){
                    cout << GREEN << "Introduzca el ID del Artista al que desea añadir a la Canción: " << YELLOW;
                    cin >> id_artista_elegido;
                    DEFAULT;
                }
                // Insertamos el Artista
                nueva_rap->setArtista(this->getArtista(id_artista_elegido));
                // Damos la opción de añadir más Artistas
                cout << WHITE << "¿Desea introducir un Artista más? [s/n]: " << DEFAULT;
                cin >> opcion_agregar_mas_artistas;
            }
        // Pedimos nueva Duración
        int minutos = -1, segundos = -1;
        cout << GREEN << "Duración: " << DEFAULT << endl;
        while(minutos < 0 || minutos > 59){
            cout << GREEN << "\tMinutos: " << YELLOW;
            cin >> minutos;
            cout << DEFAULT;
        }
        while(segundos < 0 || segundos >59){
            cout << GREEN << "\tSegundos: " << YELLOW;
            cin >> segundos;
            cout << DEFAULT;
        }
        Tiempo nuevo_tiempo(minutos, segundos);
        nueva_rap->setDuracion(nuevo_tiempo);
        // Pedimos nuevo Total Reproducciones
        int nuevo_total_reproducciones = -1;
            while(nuevo_total_reproducciones < 0 || nuevo_total_reproducciones > 32000){
                cout << GREEN << "Nuevo Total Reproducciones: " << YELLOW;
                cin >> nuevo_total_reproducciones;
        }
        nueva_rap->setReproducciones(nuevo_total_reproducciones);
        // Insertamos la nueva canción
        this->setCancion(nueva_rap);
        cout << MAGENTA <<  "Nueva canción Rap generada:" << DEFAULT << endl;
        cout << *nueva_rap << endl;
        cout << MAGENTA << "Canción Rap añadida!!" << DEFAULT << endl;
    }else if(genero_elegido == 4){
        // Generamos espacio para el puntero según el género elegido
        Faraon* nueva_faraon = new Faraon();
        // Pedimos los parámetros...
        int nuevo_id = this->getUtilCancion();
        cout << GREEN << "ID (generado automáticamente): " << YELLOW << nuevo_id << DEFAULT << endl;
        nueva_faraon->setIdCancion(nuevo_id);
        // Pedimos nuevo título
        string nuevo_titulo = "NULL";
        cout << GREEN << "Titulo: " << YELLOW ;
        cin >> nuevo_titulo;
        nueva_faraon->setTitulo(nuevo_titulo);
        // Pedimos nueva ruta
        string nueva_ruta = "NULL";
        cout << GREEN << "Ruta: " << YELLOW;
        cin >> nueva_ruta;
        nueva_faraon->setRuta(nueva_ruta);
        // Pedimos nuevo Artista
        int id_artista_elegido = -1;
            char opcion_agregar_mas_artistas = 'a';
            while(opcion_agregar_mas_artistas != 'n'){

                cout << GREEN << "Artistas disponibles:" << DEFAULT << endl;
                for(int i = 0; i < this->getUtilArtista(); i++){
                    cout << YELLOW << "\t" << this->getArtista(i)->getId() << " " << *this->getArtista(i) << DEFAULT << endl;
                }
                id_artista_elegido = -1;
                while(id_artista_elegido < 0 || id_artista_elegido >= this->getUtilArtista()){
                    cout << GREEN << "Introduzca el ID del Artista al que desea añadir a la Canción: " << YELLOW;
                    cin >> id_artista_elegido;
                    DEFAULT;
                }
                // Insertamos el Artista
                nueva_faraon->setArtista(this->getArtista(id_artista_elegido));
                // Damos la opción de añadir más Artistas
                cout << WHITE << "¿Desea introducir un Artista más? [s/n]: " << DEFAULT;
                cin >> opcion_agregar_mas_artistas;
            }
        // Pedimos nueva Duración
        int minutos = -1, segundos = -1;
        cout << GREEN << "Duración: " << DEFAULT << endl;
        while(minutos < 0 || minutos > 59){
            cout << GREEN << "\tMinutos: " << YELLOW;
            cin >> minutos;
            cout << DEFAULT;
        }
        while(segundos < 0 || segundos >59){
            cout << GREEN << "\tSegundos: " << YELLOW;
            cin >> segundos;
            cout << DEFAULT;
        }
        Tiempo nuevo_tiempo(minutos, segundos);
        nueva_faraon->setDuracion(nuevo_tiempo);
        // Pedimos nuevo Total Reproducciones
        int nuevo_total_reproducciones = -1;
            while(nuevo_total_reproducciones < 0 || nuevo_total_reproducciones > 32000){
                cout << GREEN << "Nuevo Total Reproducciones: " << YELLOW;
                cin >> nuevo_total_reproducciones;
        }
        nueva_faraon->setReproducciones(nuevo_total_reproducciones);
        // Insertamos la nueva canción
        this->setCancion(nueva_faraon);
        cout << MAGENTA <<  "Nueva canción Faraon generada:" << DEFAULT << endl;
        cout << *nueva_faraon << endl;
        cout << MAGENTA << "Canción Faraon añadida!!" << DEFAULT << endl;
    }
    pausa();

}
void Vista::pausa(){
    char caracter_continuar = '0';
    cout << WHITE << "Introduza un carácter para continuar... " << DEFAULT;
    cin >> caracter_continuar;
}
void Vista::ModificarCancionSistema(){

    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                 MODIFICAR CANCIÓN DEL CATÁLOGO DEL SISTEMA                 =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << WHITE << "Total de Artistas en la Base de Datos: " << this->getUtilArtista() << DEFAULT << endl;
    cout << WHITE << "Total de Canciones en la Base de Datos: " << this->getUtilCancion() << DEFAULT << endl;
    cout << endl;
    cout << "\t0. Salir" << endl;
    cout << "\t1. Modificar Datos de la Cancion en el Catalogo del Sistema" << endl;
    cout << endl;
    int opcion_canciones_catalogo_sistema = -1;
    while(opcion_canciones_catalogo_sistema < 0 || opcion_canciones_catalogo_sistema > 1){
        cout << "Introduzca el número correspondiente a la opción deseada: ";
        cin >> opcion_canciones_catalogo_sistema;
    }
    if(opcion_canciones_catalogo_sistema == 0){
        cout << DEBUG << "Ha decidido Salir..." << DEFAULT << endl;
        pausa();
    }else if(opcion_canciones_catalogo_sistema == 1){
        cout << WHITE << "\nEstas son las canciones disponibles en la base de datos:" << DEFAULT << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        for(int i = 0; i < this->getUtilCancion(); i++){
            cout << *this->getCancion(i) << endl;
            cout << MAGENTA << "================================================" << DEFAULT << endl;
        }

        int opcion_id_cancion = -1;
        while(opcion_id_cancion < 0 || opcion_id_cancion >= this->getUtilCancion()){
            cout << DEFAULT << "\nIntroduzca el número correspondiente al ID de la Canción que desea modificar: " << YELLOW;
            cin >> opcion_id_cancion;
            DEFAULT;
        }
        cout << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        cout << MAGENTA << "     VAMOS A MODIFICAR LA SIGUIENTE CANCIÓN     " << DEFAULT << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        cout << *this->getCancion(opcion_id_cancion) << endl;
        cout << WHITE << "\nNuevos parámetros de la Canción:" << DEFAULT << endl;
        string nuevo_titulo = "NULL";
        cout << GREEN << "Nuevo Título: " << YELLOW;
        cin >> nuevo_titulo;
        // Insertamos el nuevo título
        this->getCancion(opcion_id_cancion)->setTitulo(nuevo_titulo);
        string nueva_ruta = "NULL";
        cout << GREEN << "Nueva Ruta: " << YELLOW;
        cin >> nueva_ruta;
        // Insertamos la nueva ruta
        this->getCancion(opcion_id_cancion)->setRuta(nueva_ruta);
        // Eliminamos todos los artistas contenidos antes de insertar...
        for(int i = 0; i < this->getCancion(opcion_id_cancion)->getUtil(); i++){
            this->getCancion(opcion_id_cancion)->eliminarArtista(i);
        }
        int id_artista_elegido = -1;
        char opcion_agregar_mas_artistas = 'a';
        while(opcion_agregar_mas_artistas != 'n'){

            cout << GREEN << "Artistas disponibles:" << DEFAULT << endl;
            for(int i = 0; i < this->getUtilArtista(); i++){
                cout << YELLOW << "\t" << this->getArtista(i)->getId() << " " << *this->getArtista(i) << DEFAULT << endl;
            }
            id_artista_elegido = -1;
            while(id_artista_elegido < 0 || id_artista_elegido >= this->getUtilArtista()){
                cout << GREEN << "Introduzca el ID del Artista al que desea añadir a la Canción: " << YELLOW;
                cin >> id_artista_elegido;
                DEFAULT;
            }
            // Insertamos el Artista
            this->getCancion(opcion_id_cancion)->setArtista(this->getArtista(id_artista_elegido));
            // Damos la opción de añadir más Artistas
            cout << WHITE << "¿Desea introducir un Artista más? [s/n]: " << DEFAULT;
            cin >> opcion_agregar_mas_artistas;
        }

        int minutos = -1, segundos = -1;
        cout << GREEN << "Duración: " << YELLOW << endl;
        while(minutos < 0 || minutos > 59){
            cout << GREEN << "\tMinutos: " << YELLOW;
            cin >> minutos;
            cout << DEFAULT;
        }
        while(segundos < 0 || segundos > 59){
            cout << GREEN  << "\tSegundos: " << YELLOW;
            cin >> segundos;
            cout << DEFAULT;
        }
        Tiempo nuevo_tiempo(minutos, segundos);
        // Insertamos el nuevo Tiempo
        this->getCancion(opcion_id_cancion)->setDuracion(nuevo_tiempo);

        int nuevo_total_reproducciones = -1;
        while(nuevo_total_reproducciones < 0 || nuevo_total_reproducciones > 32000){
            cout << GREEN << "Nuevo Total Reproducciones: " << YELLOW;
            cin >> nuevo_total_reproducciones;
        }
        // Insertamos el nuevo Total de reproducciones
        this->getCancion(opcion_id_cancion)->setReproducciones(nuevo_total_reproducciones);
        cout << endl;
        
        cout << GREEN << "La canción ha sido modificada con Éxito!" << DEFAULT << endl;
        cout << *this->getCancion(opcion_id_cancion) << endl;

        pausa();


    }
    
}
void Vista::menuUsuariosAdministrador(){

    int opcion_usuarios_sistema = -1;
    while(opcion_usuarios_sistema != 0){
        opcion_usuarios_sistema = -1;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                                  USUARIOS                                  =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Usuarios en la Base de Datos: " << this->getUtilUsuario() << DEFAULT << endl;
        cout << endl;
        cout << "\t0. Salir" << endl;
        cout << "\t1. Agregar Nuevo Usuario al Sistema" << endl;
        cout << "\t2. Eliminar Usuario del Sistema" << endl;
        cout << "\t3. Buscar Usuario en el Sistema" << endl;
        cout << "\t4. Modificar Datos Usuario del Sistema" << endl;
        cout << endl;
        
        while(opcion_usuarios_sistema < 0 || opcion_usuarios_sistema > 4){
            cout << WHITE << "Introduzca el número correspondiente a la opción deseada: " << DEFAULT;
            cin >> opcion_usuarios_sistema;
            cout << endl;
        }
        if(opcion_usuarios_sistema == 0){
            cout << DEBUG << "Ha decidido Salir..." << DEFAULT << endl;
            pausa();
        }else if(opcion_usuarios_sistema == 1){
            menuUsuariosAdministradorAgregarNuevoUsuario();
        }else if(opcion_usuarios_sistema == 2){
            menuUsuarioAdministradorEliminarUsuarioDelSistema();
        }else if(opcion_usuarios_sistema == 3){
            menuUsuariosAdministradorBuscarUsuario();
        }else if(opcion_usuarios_sistema == 4){
            menuUsuariosAdministradorModificarUsuario();
        }

    }

}
void Vista::menuUsuariosAdministradorAgregarNuevoUsuario(){

    char opcion_nueva_usuario = 's';
    while(opcion_nueva_usuario == 's'){

        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                        AGREGAR NUEVO USUARIO AL SISTEMA                    =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Usuarios en la Base de Datos: " << this->getUtilUsuario() << DEFAULT << endl;
        cout << endl;
        cout << WHITE << "Introduzca los datos del Nuevo Usuario:" << DEFAULT << endl;
        cout << GREEN << "ID (generado automáticamente): " << DEFAULT;
        unsigned int nuevo_id = this->getUsuario(this->getUtilUsuario() - 1)->getId() + 1;
        cout << YELLOW << nuevo_id << DEFAULT << endl;
        cout << GREEN << "Login: " << YELLOW;
        string nuevo_login = "NULL";
        cin >> nuevo_login;
        cout << DEFAULT;
        cout << GREEN << "Password: " << YELLOW;
        string nuevo_password = "NULL";
        cin >> nuevo_password;
        cout << DEFAULT;
        //cout << DEFAULT << "debug antes de crear UsuarioComun" << endl;
        UsuarioComun* ptr_nuevo_usuario = new UsuarioComun();
        //cout << DEFAULT << "debug después de crear UsuarioComun" << endl;
        ptr_nuevo_usuario->setId(nuevo_id);
        //cout << DEFAULT << "debug después de asignar ID" << endl;
        ptr_nuevo_usuario->setLogin(nuevo_login);
        //cout << DEFAULT << "debug después de asignar Login" << endl;
        ptr_nuevo_usuario->setPassword(nuevo_password);
        //cout << DEFAULT << "debug después de asignar Password" << endl;
        this->setUsuario(ptr_nuevo_usuario);
        cout << MAGENTA << "Generado el Usuario: " << OK << this->getUsuario(nuevo_id)->getLogin() << DEFAULT << endl;
        // cout << "imprimo el usuario nuevo" << endl;
        // cout << this->getUsuario(nuevo_id) << endl;
        // cout << "fin imprimo usuario nuevo" << endl;
        cout << "Usuarios totales en la BD: " << this->getUtilUsuario() << endl;


        cout << "¿Desea Agregar un Nuevo Usuario? [s/n]: ";
        cin >> opcion_nueva_usuario;
        cout << endl;

    }
}
void Vista::menuUsuariosAdministradorEliminarUsuario(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                          ELIMINAR USUARIO DEL SISTEMA                      =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << WHITE << "Total de Usuarios en la Base de Datos: " << this->getUtilUsuario() << DEFAULT << endl;
    cout << endl;
    cout << "Usuarios en la Base de Datos:" << endl;
    for(int i = 0; i < this->getUtilUsuario(); i++){
        cout << "Imprime la dirección en vez del usuario mediante la sobrecarga: " << this->getUsuario(i) << endl;
        cout << "Aquí se imprime mediante llamada a cada método: " << endl;
        cout << GREEN << "ID: " << YELLOW << this->getUsuario(i)->getId() << DEFAULT << endl;
        cout << GREEN << "Login: " << YELLOW << this->getUsuario(i)->getLogin() << DEFAULT << endl;
    }
    cout << endl;
    
    int opcion_id_eliminar = -1;
    while(opcion_id_eliminar < 0 || opcion_id_eliminar > this->getUtilUsuario()){
        cout << WHITE << "Introduzca el ID del Usuario que desea Eliminar: " << YELLOW << endl;
        cin >> opcion_id_eliminar;
    }
    // controlar que no se pueda eliminar si es UsuarioAdministrador
    this->usuarios_sistema[opcion_id_eliminar]->setId(-1);
    this->usuarios_sistema[opcion_id_eliminar]->setLogin("NULL");
    this->usuarios_sistema[opcion_id_eliminar]->setPassword("NULL");
    //for(int i = 0; i < this->usuarios_sistema[opcion_id_eliminar]->eliminarplaylist....)
    //for anidado eliminar canciones de la playlist

    //eliminar canciones del usuario (me gusta)


}
void Vista::menuUsuariosAdministradorBuscarUsuario(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                                BUSCAR USUARIO                              =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << WHITE << "Total de Usuarios en la Base de Datos: " << this->getUtilUsuario() << DEFAULT << endl;
    cout << endl;
    
    char opcion_nueva_busqueda = 's';
    while(opcion_nueva_busqueda == 's'){

        string login_buscado = "NULL";
        cout << "Introduzca el " << GREEN << "Login" << DEFAULT << " que desea Buscar: " << YELLOW;
        cin >> login_buscado;

        bool login_encontrado = false;
        int posicion_login_encontrado = -1;
        for(int i = 0; i < this->getUtilUsuario() && login_encontrado == false; i++){
            if(login_buscado == this->getUsuario(i)->getLogin()){
                login_encontrado = true;
                posicion_login_encontrado = i;
                cout << GREEN << "\nUsuario encontrado :)" << DEFAULT << endl;
            }
        }
        if(login_encontrado == false){
            cout << DEBUG << "\nLo sentimos :(\nEl Usuario buscado no se encuentra en la Base de Datos..." << DEFAULT << endl;
        }else if(login_encontrado == true){
            cout << MAGENTA << "\nDetalles del Usuario:" << DEFAULT << endl;
            cout << GREEN << "ID: " << YELLOW << this->getUsuario(posicion_login_encontrado)->getId() << DEFAULT << endl;
            cout << GREEN << "Login: " << YELLOW << this->getUsuario(posicion_login_encontrado)->getLogin() << DEFAULT << endl;
            cout << GREEN << "Password: " << YELLOW << this->getUsuario(posicion_login_encontrado)->getPassword() << DEFAULT << endl;
        }
        cout << endl;
    
        cout << "¿Desea realizar una nueva búsqueda? [s/n]: ";
        cin >> opcion_nueva_busqueda;
        cout << endl;
    }
}
void Vista::menuUsuariosAdministradorModificarUsuario(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                              MODIFICAR USUARIO                             =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << WHITE << "Total de Usuarios en la Base de Datos: " << this->getUtilUsuario() << DEFAULT << endl;
    cout << endl;
    char opcion_nueva_modificacion = 's';
    while(opcion_nueva_modificacion == 's'){

        cout << "Usuarios en la Base de Datos:" << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        int j = 0;
        for(int i = 0; i < this->getUtilUsuario(); i++){
            // cout << "Imprime la dirección en vez del usuario: " << this->getUsuario(i) << endl;
            // cout << "Aquí se imprime mediante llamada a cada método: " << endl;
            cout << GREEN << "Posición : " << YELLOW << i << DEFAULT << endl;
            cout << GREEN << "Login: " << YELLOW << this->getUsuario(i)->getLogin() << DEFAULT << endl;
            cout << MAGENTA << "================================================" << DEFAULT << endl;
            j++;
        }
        cout << endl;
        int id_usuario_modificar = -1;
        while(id_usuario_modificar < 0 || id_usuario_modificar > j){
            cout << "Introduzca la Posición del Usuario que desea Modificar: " << YELLOW;
            cin >> id_usuario_modificar;
            cout << DEFAULT << endl;
        }
        cout << "Ha elegido Modificar el siguiente Usuario:" << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        cout << GREEN << "ID: " << YELLOW << this->getUsuario(id_usuario_modificar)->getId() << DEFAULT << endl;
        cout << GREEN << "Login: " << YELLOW << this->getUsuario(id_usuario_modificar)->getLogin() << DEFAULT << endl;
        cout << GREEN << "Password: " << YELLOW << this->getUsuario(id_usuario_modificar)->getPassword() << DEFAULT << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        cout << "Introduzca los nuevos parámetros:" << endl;
        string nuevo_login = "NULL";
        cout << GREEN << "Login: " << YELLOW;
        cin >> nuevo_login;
        string nuevo_password = "NULL";
        cout << GREEN << "Password: " << YELLOW;
        cin >> nuevo_password;
        this->getUsuario(id_usuario_modificar)->setLogin(nuevo_login);
        this->getUsuario(id_usuario_modificar)->setPassword(nuevo_password);
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        cout << "Así ha quedado el Usuario Modificado:" << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
        cout << GREEN << "ID: " << YELLOW << this->getUsuario(id_usuario_modificar)->getId() << DEFAULT << endl;
        cout << GREEN << "Login: " << YELLOW << this->getUsuario(id_usuario_modificar)->getLogin() << DEFAULT << endl;
        cout << GREEN << "Password: " << YELLOW << this->getUsuario(id_usuario_modificar)->getPassword() << DEFAULT << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;

        cout << "¿Desea realizar una nueva modificación? [s/n]: ";
        cin >> opcion_nueva_modificacion;
        cout << endl;

    }
}
void Vista::menuUsuarioComunCancionesYPlaylists(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                            PLAYLISTS Y CANCIONES                           =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << GREEN << "Usuario Activo: " << YELLOW << this->getUsuarioActivo()->getLogin() << DEFAULT << endl;
    cout << endl;
    cout << WHITE << "Playlists: " << DEFAULT << endl;
    UsuarioComun* ptr_imprime = dynamic_cast<UsuarioComun*>(this->getUsuarioActivo());
    for(int i = 0; i < ptr_imprime->getUtilPlaylistUsuario(); i++){
        cout << *ptr_imprime->getPlaylistUsuario(i) << endl;
    }
    cout << WHITE << "Canciones: " << DEFAULT << endl;
    for(int i = 0; i < ptr_imprime->getUtilCancionesUsuario(); i++){
        cout << *ptr_imprime->getCancionUsuario(i) << endl;
    }
}
void Vista::menuUsuarioComunAgregarCancionAPlaylist(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                      AGREGAR UNA CANCIÓN A UNA PLAYLIST                    =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << GREEN << "Usuario Activo: " << YELLOW << this->getUsuarioActivo()->getLogin() << DEFAULT << endl;
    cout << endl;
    cout << WHITE << "Playlists: " << DEFAULT << endl;
    UsuarioComun* ptr_imprime = dynamic_cast<UsuarioComun*>(this->getUsuarioActivo());
    // Mostramos las Playlists del Usuario
    for(int i = 0; i < ptr_imprime->getUtilPlaylistUsuario(); i++){
        cout << GREEN << "ID: " << YELLOW << ptr_imprime->getPlaylistUsuario(i)->getId() << GREEN << "  Nombre: " << YELLOW << ptr_imprime->getPlaylistUsuario(i)->getNombre() << DEFAULT << endl;
    }
    // Pedimos que elija una Playlist
    cout << WHITE << "Introduzca el ID de la Playlist a la que desea agregar una Canción: " << YELLOW;
    int id_pl_deseada = -1;
    cin >> id_pl_deseada;
    // Mostramos las Canciones del Sistema
    for(int i = 0; i < this->getUtilCancion(); i++){
        cout << GREEN << "ID: " << YELLOW << this->getCancion(i)->getId() << GREEN << "  Titulo: " << YELLOW << this->getCancion(i)->getTitulo() << DEFAULT << endl;
    }
    // Pedimos que elija una Canción
    cout << WHITE << "Introduzca el ID de la Canción del Sistema que desea agregar la Playlist: " << YELLOW;
    int id_cancion_deseada = -1;
    cin >> id_cancion_deseada;
    ptr_imprime->getPlaylistUsuario(id_pl_deseada)->setCancion(this->getCancion(id_cancion_deseada));
    cout << "La Canción ha sido agregada a la Playlist" << endl;
    cout << "Así ha quedado la Playlist: " << endl;
    cout << *ptr_imprime->getPlaylistUsuario(id_pl_deseada) << endl;
}
void Vista::menuUsuarioComunEliminarCancionDePlaylist(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                     ELIMINAR UNA CANCIÓN DE UNA PLAYLIST                   =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << GREEN << "Usuario Activo: " << YELLOW << this->getUsuarioActivo()->getLogin() << DEFAULT << endl;
    cout << endl;
    cout << WHITE << "Playlists: " << DEFAULT << endl;
    UsuarioComun* ptr_imprime = dynamic_cast<UsuarioComun*>(this->getUsuarioActivo());
    // Mostramos las Playlists del Usuario
    for(int i = 0; i < ptr_imprime->getUtilPlaylistUsuario(); i++){
        cout << GREEN << "ID: " << YELLOW << ptr_imprime->getPlaylistUsuario(i)->getId() << GREEN << "  Nombre: " << YELLOW << ptr_imprime->getPlaylistUsuario(i)->getNombre() << DEFAULT << endl;
    }
    // Pedimos que elija una Playlist
    cout << WHITE << "Introduzca el ID de la Playlist de la que desea eliminar una Canción: " << YELLOW;
    int id_pl_deseada = -1;
    cin >> id_pl_deseada;
    // Mostramos la Playlist de la que se eliminará una canción
    for(int i = 0; i < ptr_imprime->getPlaylistUsuario(id_pl_deseada)->getUtil(); i++){
        cout << GREEN << "Posicion: " << YELLOW << i << GREEN << "  Titulo: " << YELLOW << ptr_imprime->getPlaylistUsuario(id_pl_deseada)->getCancion(i)->getTitulo() << DEFAULT << endl;
    }
    // Pedimos que elija una Canción a eliminar
    cout << WHITE << "Introduzca la Posición de la Canción que desea Eliminar de la Playlist: " << YELLOW;
    int id_cancion_deseada = -1;
    cin >> id_cancion_deseada;
    ptr_imprime->getPlaylistUsuario(id_pl_deseada)->eliminarCancion(id_cancion_deseada);
    cout << "La Canción ha sido Eliminada de la Playlist" << endl;
    cout << "Así ha quedado la Playlist: " << endl;
    cout << *ptr_imprime->getPlaylistUsuario(id_pl_deseada) << endl;
}
void Vista::menuUsuarioAdministradorEliminarCancionDelSistema(){
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << MAGENTA << "=                  ELIMINAR CANCIÓN DEL CATÁLOGO DEL SISTEMA                 =" << DEFAULT << endl;
    cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
    cout << WHITE << "Total de Artistas en la Base de Datos: " << this->getUtilArtista() << DEFAULT << endl;
    cout << WHITE << "Total de Canciones en la Base de Datos: " << this->getUtilCancion() << DEFAULT << endl;
    cout << endl;
    cout << WHITE << "\nEstas son las canciones disponibles en la base de datos:" << DEFAULT << endl;
    cout << MAGENTA << "================================================" << DEFAULT << endl;
    for(int i = 0; i < this->getUtilCancion(); i++){
        cout << *this->getCancion(i) << endl;
        cout << MAGENTA << "================================================" << DEFAULT << endl;
    }

    int opcion_id_cancion = -1;
    while(opcion_id_cancion < 0 || opcion_id_cancion >= this->getUtilCancion()){
        cout << DEFAULT << "\nIntroduzca el número correspondiente al ID de la Canción que desea Eliminar: " << YELLOW;
        cin >> opcion_id_cancion;
        DEFAULT;
    }
    // 1 buscar en todas las playlists y actualizarlas
    // 1.1 Encuentro todos los usuarios
    for(int i = 0; i < this->getUtilUsuario(); i++){
        // 1.2 Compruebo que sean UsuarioComun (que contiene Playlists)
        UsuarioComun* pepe = dynamic_cast<UsuarioComun*>(this->getUsuario(i));
        if(pepe != nullptr){
            // 1.3 Recorro todas las Playlists que tiene el UsuarioComun
            for(int j = 0; j < pepe->getUtilPlaylistUsuario(); j++){
                // 1.4 Elimino Canción a Canción de la Playlist(i)
                for(int k=0; k < pepe->getPlaylistUsuario(j)->getUtil(); k++){
                    // 1.5 Compruebo Canción a Canción que corresponda con la deseada a eliminar
                    if(opcion_id_cancion == pepe->getPlaylistUsuario(j)->getCancion(k)->getId()){
                        pepe->getPlaylistUsuario(j)->eliminarCancion(k);
                    }
                }
                
            }
        } 
    }
    // 2 buscar en todas las canciones del usuario
    // 2.1 Encuentro todos los Usuarios
    for(int i = 0; i < this->getUtilUsuario(); i++){
        // 1.2 Compruebo que sean UsuarioComun (que contiene las Canciones de UsuarioComun)
        UsuarioComun* pepe = dynamic_cast<UsuarioComun*>(this->getUsuario(i));
        if(pepe != nullptr){
            // 1.3 Recorro todas las Canciones que tiene almacenadas el Usuario
            for(int j = 0; j < pepe->getUtilCancionesUsuario(); j++){
                if(opcion_id_cancion == pepe->getCancionUsuario(j)->getId()){
                    pepe->eliminarCancionDeUsuario(j);
                }
            }
        }
    }
    // 3 eliminar cancion del catalogo
    // 3.1 Encuentro todas las Canciones
    for(int i = 0; i < this->getUtilCancion(); i++){
        if(opcion_id_cancion == this->getCancion(i)->getId()){
            this->eliminarCancionSistema(i);
        }
    }
    pausa();
}
void Vista::menuUsuarioAdministradorEliminarUsuarioDelSistema(){
    char opcion_nueva_usuario = 's';
    while(opcion_nueva_usuario == 's'){

        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                          ELIMINAR USUARIO DEL SISTEMA                      =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Usuarios en la Base de Datos: " << this->getUtilUsuario() << DEFAULT << endl;
        cout << endl;
        // Mostramos los Usuarios
        int j = 0;
        for(int i = 0; i < this->getUtilUsuario(); i++){
            cout << GREEN << "ID: " << YELLOW << this->getUsuario(i)->getId() << GREEN <<  "  Login: " << YELLOW << this->getUsuario(i)->getLogin() << DEFAULT << endl;
            j++;
        }
        int opcion_id_usuario = -1;
        int id_max = this->getUsuario(this->getUtilUsuario() - 1)->getId();
        while(opcion_id_usuario < 0 || opcion_id_usuario > id_max){
            opcion_id_usuario = -1;
            cout << WHITE << "Introduzca la ID a eliminar: " << YELLOW;
            cin >> opcion_id_usuario;
            cout << DEFAULT;
        }

        // Eliminamos las canciones del Usuario
        for(int i = 0; i < this->getUtilUsuario(); i++){
            if(opcion_id_usuario == this->getUsuario(i)->getId()){
                UsuarioComun* juan = dynamic_cast<UsuarioComun*>(this->getUsuario(i));
                for(int j = 0; j < juan->getUtilCancionesUsuario(); j++){
                    juan->eliminarCancionDeUsuario(j);
                }
            }
        }
        // Eliminamos las Playlist
        for(int i = 0; i < this->getUtilUsuario(); i++){
            if(opcion_id_usuario == this->getUsuario(i)->getId()){
                UsuarioComun* juan = dynamic_cast<UsuarioComun*>(this->getUsuario(i));
                for(int j = 0; j < juan->getUtilPlaylistUsuario(); j++){
                    juan->eliminarPlaylistDeUsuario(j);
                }
            }
        }
        bool usuario_eliminado = false;
        // Eliminamos el Usuario
        for(int i = 0; i < this->getUtilUsuario(); i++){
            if(opcion_id_usuario == this->getUsuario(i)->getId()){
                this->eliminarUsuarioSistema(i);
                usuario_eliminado = true;
            }
        }
        if(usuario_eliminado == false){
            cout << DEBUG << "El ID de Usuario que desea Eliminar no se encuentra en la Base de Datos" << DEFAULT << endl;
        }else{
            cout << WHITE << "Usuarios totales en la BD tras la Eliminación: " << YELLOW << this->getUtilUsuario() << DEFAULT << endl;
        }

        cout << "¿Desea Eliminar Otro Usuario? [s/n]: ";
        cin >> opcion_nueva_usuario;
        cout << endl;

    }



}
void Vista::menuUsuarioAdministradorEliminarPlaylistDelSistema(){

    char opcion_nueva_usuario = 's';
    while(opcion_nueva_usuario == 's'){

        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                         ELIMINAR PLAYLIST DEL SISTEMA                      =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Playlists en la Base de Datos: " << this->getUtilPlaylist() << DEFAULT << endl;
        cout << endl;
        // Mostramos las Playlist
        int j = 0;
        for(int i = 0; i < this->getUtilPlaylist(); i++){
            cout << GREEN << "ID: " << YELLOW << this->getPlaylist(i)->getId() << GREEN <<  "  Nombre: " << YELLOW << this->getPlaylist(i)->getNombre() << DEFAULT << endl;
            j++;
        }
        int opcion_id_pl = -1;
        int id_max = this->getPlaylist(this->getUtilPlaylist() - 1)->getId();
        while(opcion_id_pl < 0 || opcion_id_pl > id_max){
            opcion_id_pl = -1;
            cout << WHITE << "Introduzca la ID a eliminar: " << YELLOW;
            cin >> opcion_id_pl;
            cout << DEFAULT;
        }

        Playlist* ptr_pl_eliminar = 0;
        for(int i = 0; i < this->getUtilPlaylist(); i++){
            if(this->getPlaylist(i)->getId() == opcion_id_pl){
                ptr_pl_eliminar = this->getPlaylist(i);
            }
        }

        // Recorro todos los usuarios...
        for(int i = 0; i < this->getUtilUsuario(); i++){
            // Compruebo que sea UsuarioComun (que contiene Playlists)
            UsuarioComun* juanito = dynamic_cast<UsuarioComun*>(this->getUsuario(i));
            if(juanito != nullptr){
                for(int j = 0; j < juanito->getUtilPlaylistUsuario(); j++){
                    if(ptr_pl_eliminar == juanito->getPlaylistUsuario(j)){
                        juanito->eliminarPlaylistDeUsuario(j);
                    }
                }
            }
        }
        bool pl_eliminada = false;
        // Una vez eliminadas de los UsuarioComun, las eliminamos el Sistema...
        for(int i = 0; i < this->getUtilPlaylist(); i++){
            if(opcion_id_pl == this->getPlaylist(i)->getId()){
                this->eliminarPlaylistSistema(i);
                pl_eliminada = true;
            }
        }

        if(pl_eliminada == false){
            cout << DEBUG << "El ID de Playlist que desea Eliminar no se encuentra en la Base de Datos" << DEFAULT << endl;
        }else{
            cout << WHITE << "Playlists totales en la BD tras la Eliminación: " << YELLOW << this->getUtilPlaylist() << DEFAULT << endl;
        }

        cout << "¿Desea Eliminar Otra Playlist? [s/n]: ";
        cin >> opcion_nueva_usuario;
        cout << endl;

    }



}
void Vista::menuUsuarioAdministradorPlaylists(){

    int opcion_usuarios_sistema = -1;
    while(opcion_usuarios_sistema != 0){
        opcion_usuarios_sistema = -1;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                                 PLAYLISTS                                  =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Playlists en la Base de Datos: " << this->getUtilPlaylist() << DEFAULT << endl;
        cout << endl;
        cout << "\t0. Salir" << endl;
        cout << "\t1. Buscar y Consultar Playlist (y sus detalles)" << endl;
        cout << "\t2. Eliminar Playlist" << endl;
        cout << endl;
        // Pedimos la opción...
        while(opcion_usuarios_sistema < 0 || opcion_usuarios_sistema > 4){
            cout << WHITE << "Introduzca el número correspondiente a la opción deseada: " << DEFAULT;
            cin >> opcion_usuarios_sistema;
            cout << endl;
        }
        // Ejecutamos método según la elección...
        if(opcion_usuarios_sistema == 0){
            cout << DEBUG << "Ha decidido Salir..." << DEFAULT << endl;
            pausa();
        }else if(opcion_usuarios_sistema == 1){
            busquedaPlaylist();
        }else if(opcion_usuarios_sistema == 2){
            menuUsuarioAdministradorEliminarPlaylistDelSistema();
        }

    }

}
void Vista::menuSistemaUsuarioValorarUnaCancion(){
    UsuarioComun* juan = dynamic_cast<UsuarioComun*>(this->getUsuarioActivo());
    int opcion_usuarios_sistema = -1;
    while(opcion_usuarios_sistema != 0){
        opcion_usuarios_sistema = -1;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                            VALORAR UNA CANCIÓN                             =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Canciones de " << YELLOW << this->getUsuarioActivo()->getLogin() << WHITE << "ya valoradas: " << juan->getUtilValoracion() << DEFAULT << endl;
        cout << endl;
        for(int i = 0; i < juan->getUtilValoracion(); i++){
            cout << juan->getValoracion(i)->getCancionValorada()->getTitulo() << " = " << juan->getValoracion(i)->getPuntuacion() << endl;
        }
        cout << endl;
        cout << "\t0. Salir" << endl;
        cout << "\t1. Valorar una Canción" << endl;
        cout << endl;
        
        while(opcion_usuarios_sistema < 0 || opcion_usuarios_sistema > 1){
            cout << WHITE << "Introduzca el número correspondiente a la opción deseada: " << DEFAULT;
            cin >> opcion_usuarios_sistema;
            cout << endl;
        }
        if(opcion_usuarios_sistema == 0){
            cout << DEBUG << "Ha decidido Salir..." << DEFAULT << endl;
            pausa();
        }else if(opcion_usuarios_sistema == 1){
            cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
            cout << MAGENTA << "=                         ** VALORAR UNA CANCIÓN **                          =" << DEFAULT << endl;
            cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
            cout << endl;
            for(int i = 0; i < this->getUtilCancion(); i++){
                cout << GREEN << i << YELLOW << " " << this->getCancion(i)->getTitulo() << DEFAULT << endl;
            }
            int posicion_cancion_en_el_vector = -1;
            cout << endl;

            do{
                cout << WHITE << "Introduzca el número de la canción que desea Valorar: ";
                cout << GREEN;
                cin >> posicion_cancion_en_el_vector;
                
            }while(posicion_cancion_en_el_vector < 0 || posicion_cancion_en_el_vector >= this->getUtilCancion());
            // HAY QUE FILTRAR QUE NO SE PUEDA VALORAR LA MISMA CANCION 2 VECES !!!!
            cout << endl;
            cout << WHITE << "Va a valorar: " << GREEN << posicion_cancion_en_el_vector << YELLOW << " " << this->getCancion(posicion_cancion_en_el_vector)->getTitulo() << endl;
            int valoracion = -1;
            while(valoracion < 0 || valoracion > 5){
                cout << WHITE << "Introduzca un valor 0-5: ";
                cout << YELLOW;
                cin >> valoracion;
                cout << DEFAULT;
            }
            Valoracion* nueva_valoracion = new Valoracion();
            nueva_valoracion->setPuntuacion(valoracion);
            nueva_valoracion->setCancionValorada(this->getCancion(posicion_cancion_en_el_vector));
            if(juan != nullptr){
                juan->setValoracion(nueva_valoracion);
            }

            cout << endl;
            cout << WHITE << "Canción: " << YELLOW << this->getCancion(posicion_cancion_en_el_vector)->getTitulo() << WHITE << "  Valoración asignada: " << YELLOW << juan->getValoracion(juan->getUtilValoracion() - 1)->getPuntuacion() << DEFAULT << endl;
            pausa();
        }
    }
}
void Vista::menuSistemaUsuarioReproducirUnaCancion(){
    int opcion_usuarios_sistema = -1;
    while(opcion_usuarios_sistema != 0){
        opcion_usuarios_sistema = -1;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << MAGENTA << "=                           REPRODUCIR UNA CANCIÓN                           =" << DEFAULT << endl;
        cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
        cout << WHITE << "Total de Canciones en la Base de Datos: " << this->getUtilCancion() << DEFAULT << endl;
        cout << endl;
        cout << "\t0. Salir" << endl;
        cout << "\t1. Reproducir una Canción" << endl;
        cout << endl;
        
        while(opcion_usuarios_sistema < 0 || opcion_usuarios_sistema > 1){
            cout << WHITE << "Introduzca el número correspondiente a la opción deseada: " << DEFAULT;
            cin >> opcion_usuarios_sistema;
            cout << endl;
        }
        if(opcion_usuarios_sistema == 0){
            cout << DEBUG << "Ha decidido Salir..." << DEFAULT << endl;
            pausa();
        }else if(opcion_usuarios_sistema == 1){
            cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
            cout << MAGENTA << "=                           REPRODUCIR UNA CANCIÓN                           =" << DEFAULT << endl;
            cout << MAGENTA << "==============================================================================" << DEFAULT << endl;
            cout << endl;
            for(int i = 0; i < this->getUtilCancion(); i++){
                cout << GREEN << i << YELLOW << " " << this->getCancion(i)->getTitulo() << MAGENTA << " (" << this->getCancion(i)->getReproducciones() << " reproducciones)" << DEFAULT << endl;
            }
            int posicion_cancion_en_el_vector = -1;
            cout << endl;
            while(posicion_cancion_en_el_vector < 0 || posicion_cancion_en_el_vector >= this->getUtilCancion()){
                cout << WHITE << "Introduzca el número de la canción que desea Reproducir: ";
                cout << GREEN;
                cin >> posicion_cancion_en_el_vector;
            }
            cout << endl;
            this->getCancion(posicion_cancion_en_el_vector)->setReproducciones(this->getCancion(posicion_cancion_en_el_vector)->getReproducciones() + 1);
            cout << MAGENTA << "Reproduciendo... " << YELLOW << " " << this->getCancion(posicion_cancion_en_el_vector)->getTitulo() << GREEN << " ("<< this->getCancion(posicion_cancion_en_el_vector)->getReproducciones() << " reproducciones)" << DEFAULT << endl;
            cout << endl;
            string vlc = "vlc ";
	        string ruta_archivo = this->getCancion(posicion_cancion_en_el_vector)->getRuta(); //Ruta absoluta con el archivo, tambien se puede usar ruta relativa
	        vlc += ruta_archivo + " --play-and-exit"; //Se junta todos los strings en uno para formar el comando. El --play and exit hace que la cancion se cierra al terminar
	        system(vlc.c_str()); //c_str es un metodo de string que transforma el string a char, necesario para usar bien el comando
            pausa();
        }

    }

}
void Vista::testingCanciones(){
    cout << endl << "======================" << endl;
    cout << "Testing de canciones:" << endl;
    cout << "======================" << endl;

    cout << WHITE << "Agregar 3 canciones..." << DEFAULT << endl;
    cout << "Util Canciones: " << this->getUtilCancion() << endl;
    for(int i = 0; i < 3; i++){
        this->setCancion(this->getCancion(i));
        cout << "Agregada la canción: " << this->getCancion(i)->getTitulo() << endl;
    }
    cout << "Util Canciones: " << this->getUtilCancion() << endl;


    cout << WHITE << "Eliminar la posición 0, posición 3 y última Canción..." << DEFAULT << endl;
    cout << "Util Canciones: " << this->getUtilCancion() << endl;
    this->eliminarCancionSistema(0);
    cout << "Eliminada la posición 0" << endl;
    this->eliminarCancionSistema(3);
    cout << "Eliminada la posición 3" << endl;
    this->eliminarCancionSistema(this->getUtilCancion() - 1);
    cout << "Eliminada la posición " << this->getUtilCancion() - 2 << endl;
    cout << "Util Canciones: " << this->getUtilCancion() << endl;

    cout << WHITE << "Modificar la canción de la Posición 2:" << DEFAULT << endl;
    cout << "Antes de la modificación:" << endl;
    cout << *this->getCancion(2) << endl;
    this->getCancion(2)->setArtista(this->getArtista(0));
    this->getCancion(2)->setArtista(this->getArtista(4));
    this->getCancion(2)->setTitulo("Nuevo_Titulo");
    this->getCancion(2)->setRuta("Nueva-Ruta-En-El-Sistema");
    Tiempo tiempo_nuevo(33, 12);
    this->getCancion(2)->setDuracion(tiempo_nuevo);
    this->getCancion(2)->setReproducciones(12);
    cout << "Después de la modificación:" << endl;
    cout << *this->getCancion(2) << endl;

    cout << WHITE << "Eliminar 2 artistas de la canción de la Posición 2:" << DEFAULT << endl;
    this->getCancion(2)->eliminarArtista(0);
    this->getCancion(2)->eliminarArtista(1);
    cout << "Después de la eliminación:" << endl;
    cout << *this->getCancion(2) << endl;

}
void Vista::testingValoraciones(){
    cout << "Testing de las Valoraciones" << endl;
    UsuarioComun* ptr_usuario1 = new UsuarioComun();
    cout << "Introduzco una valoracion..." << endl;
    Valoracion* ptr_valoracion1 = new Valoracion();
    ptr_valoracion1->setCancionValorada(this->getCancion(0));
    ptr_valoracion1->setPuntuacion(2);
    cout << "Util Valoraciones: " << ptr_usuario1->getUtilValoracion() << endl;
    ptr_usuario1->setValoracion(ptr_valoracion1);
    cout << "Util Valoraciones: " << ptr_usuario1->getUtilValoracion() << endl;
    cout << "Veo la valoracion introducida:" << endl;
    cout << *ptr_usuario1->getValoracion(0)->getCancionValorada() << endl;
    cout << "Puntuacion: " << ptr_usuario1->getValoracion(0)->getPuntuacion() << endl;
    
    cout << "Introduzco otra valoracion..." << endl;
    Valoracion* ptr_valoracion2 = new Valoracion();
    ptr_valoracion2->setCancionValorada(this->getCancion(1));
    ptr_valoracion2->setPuntuacion(5);
    cout << "Util Valoraciones: " << ptr_usuario1->getUtilValoracion() << endl;
    ptr_usuario1->setValoracion(ptr_valoracion2);
    cout << "Util Valoraciones: " << ptr_usuario1->getUtilValoracion() << endl;
    cout << "Veo la valoracion introducida:" << endl;
    cout << *ptr_usuario1->getValoracion(1)->getCancionValorada() << endl;
    cout << "Puntuacion: " << ptr_usuario1->getValoracion(1)->getPuntuacion() << endl;


    

}
void Vista::menuSistema(){

    cargaInicial();
    //imprimirDatos();
    //imprimirDatos();
    loginAlSistema();
    //menuSistemaAdministrador();
    //busquedaCancion();
    //catalogoCancionesSistema();
    //agregarCancionCatalogoSistema();
    //ModificarCancionSistema();
    //menuUsuariosAdministrador();
    //menuUsuariosAdministradorAgregarNuevoUsuario();
    //menuUsuariosAdministradorEliminarUsuario();
    //menuUsuarioAdministradorEliminarPlaylistDelSistema();
    
    //testingCanciones();
    //testingValoraciones();
    //imprimirDatos();
}
#else
class Vista;
#endif