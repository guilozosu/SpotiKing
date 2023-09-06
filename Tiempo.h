#ifndef TIEMPO
#define TIEMPO
#include <iostream>
using namespace std;

class Tiempo{
    private:
        int minutos;
        int segundos;
    public:
        Tiempo();
        ~Tiempo();
        Tiempo(const Tiempo &t);
        Tiempo(const int minutos, const int segundos);
        // Setters
        void setMinutos(const int minutos);
        void setSegundos(const int segundos);
        // Getters
        int getMinutos() const;
        int getSegundos() const;
        // Overloads
        Tiempo operator+(const Tiempo& t);
        Tiempo operator-(const Tiempo& t);
        Tiempo& operator=(const Tiempo& t);
        // ostream& operator<<(ostream &flujo, const Tiempo& t) // incluido aqui para saber aunque no corresponda
        // Métodos adicionales
        int convertirASegundos();
        Tiempo convertirATiempo(const int total_segundos);

};
Tiempo::Tiempo(){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un Tiempo, direccion: " << DEFAULT << this << endl; }
    // Inicializamos todas las variables a 0
    this->setMinutos(0);
    this->setSegundos(0);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el Tiempo: " << DEFAULT << this << endl; } 
}
Tiempo::~Tiempo(){

    if(debug==true){ cout << DEBUG << "Invocamos a la DESTRUCCION del Tiempo, direccion: " << DEFAULT << this << endl; }
    this->setMinutos(0);
    this->setSegundos(0);
    if(debug==true){ cout << DEBUG << "Se ha DESTRUIDO el Tiempo con direccion: " << DEFAULT << this << endl; }
}
Tiempo::Tiempo(const Tiempo &t){
    if(debug==true){ cout << DEBUG << "Invocamos a la CREACION de un Tiempo por COPIA, direccion: " << DEFAULT << this << endl; }
    this->setMinutos(t.minutos);
    this->setSegundos(t.segundos);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO el Tiempo por COPIA: " << DEFAULT << this << endl; } 
}
Tiempo::Tiempo(const int minutos, const int segundos){
    if(debug==true){ cout << DEBUG << "Invocando a la CREACION de un Tiempo por PARAMETROS, direccion: " << DEFAULT << this << endl; }
    this->setMinutos(minutos);
    this->setSegundos(segundos);
    if(debug==true){ cout << DEBUG << "Se ha generado con EXITO un Tiempo por PARAMETROS, direccion: " << DEFAULT << this << endl; }
}
void Tiempo::setMinutos(const int minutos){
    this->minutos = minutos;
}
void Tiempo::setSegundos(const int segundos){
    this->segundos = segundos;
}
int Tiempo::getMinutos() const{
    return this->minutos;
}
int Tiempo::getSegundos() const{
    return this->segundos;
}
Tiempo Tiempo::operator+(const Tiempo& t){
    int res_minutos = 0, res_segundos = 0;
    res_minutos = this->getMinutos() + t.getMinutos();
    res_segundos = this->getSegundos() + t.getSegundos();
    Tiempo res = res.convertirATiempo( (res_minutos*60) + res_segundos );
    return res;
}
Tiempo Tiempo::operator-(const Tiempo& t){
    int res_minutos = 0, res_segundos = 0;
    res_minutos = this->getMinutos() - t.getMinutos();
    res_segundos = this->getSegundos() - t.getSegundos();
    Tiempo res = res.convertirATiempo( (res_minutos*60) + res_segundos );
    return res;
}
Tiempo& Tiempo::operator=(const Tiempo& t){
    if(&t!=this){
        this->minutos = t.getMinutos();
        this->segundos = t.getSegundos();
    }
    return *this;
}

ostream& operator<<(ostream &flujo, const Tiempo& t){
    flujo << t.getMinutos() << ":" << t.getSegundos();
    return flujo;
}
int Tiempo::convertirASegundos(){
    int total_segundos = 0;
    total_segundos = total_segundos + this->getSegundos() + ( this->getMinutos() * 60 );
    return total_segundos;
}
Tiempo Tiempo::convertirATiempo(const int total_segundos){
    int segundos = 0;
    int minutos = 0;
    minutos = total_segundos / 60;
    segundos = total_segundos % 60;
    Tiempo t(minutos, segundos);
    return t;
}
#else
class Tiempo;
#endif