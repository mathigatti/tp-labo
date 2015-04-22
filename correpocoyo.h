#ifndef CORREPOCOYO_H_
#define CORREPOCOYO_H_

#include <iostream>
#include <cassert>
using namespace std;

/* 
 * Se puede asumir que el tipo T tiene constructor por copia y operator==
 * No se puede asumir que el tipo T tenga operator=
 */
template<typename T>
class CorrePocoyo{

  public:

	/*
	 * Crea una nueva carrera
	 */	
	CorrePocoyo();
	
	/*
	 * Una vez copiada, ambas CorrePocoyos deben ser independientes, 
	 * es decir, cuando se borre una no debe borrar la otra.
	 */	
	CorrePocoyo(const CorrePocoyo<T>&);
		
	/*
	 * Acordarse de liberar toda la memoria!
	 */	
	~CorrePocoyo();

	/*
	 * Agrega un nuevo corredor al CorrePocoyo. Lo agregará al final 
	 */
	void nuevoCorredor(const T&);

	/*
	 * Agrega un nuevo corredor al CorrePocoyo. El primer T es el corredor a agregar y lo hace delante del segundo
	 *
	 * PRE: Existe el segundo corredor 
	 */
	void nuevoCorredor(const T&, const T&);
	
	/*
	 * Elimina del pocoyo al que se envía
	 *
	 * PRE: Existe el corredor
	 */
	void seCansa(const T&);
	/*
	 * El corredor pasa al que está adelante 
	 *
	 * PRE: Existe un corredor delante de él y T es un corredor 
	 */
	void sobrepasar(const T&);
	
	/*
	 * Devuelve el corredor que está siendo filmado.
	 *
	 * PRE: Hay adeptos en la CorrePocoyo.
	 */
	const T& corredorFilmado() const;
	
    /*
	 * Devuelve el próximo elemento según el orden dado.
	 * Pasa a filmar al corredor de atás 
	 *
	 * PRE: Hay corredore en la CorrePocoyo.
	 */
	void filmarProxPerdedor();
	    /*
	 * Devuelve el próximo elemento según el orden dado.
	 * Pasa a filmar al corredor de adelante 
	 *
	 * PRE: Hay corredore en la CorrePocoyo.
	 */
	void filmarProxExitoso();
	
	/*
	 * Devuelve al Primero. 
	 *
	 * PRE: Hay elementos 
	 */
	const T& damePrimero() const;	

	/*
	 * Devuelve la posición del elemento pasado por parámetro. 
	 *
	 * PRE: Existe ese corredor 
	 */
	int damePosicion(const T& ) const;	

	/*
	 * Devuelve el corredor de la posición. 
	 *
	 * PRE: Existe al menos esa cantidad de corredores en la carrera
	 */
	const T& dameCorredorEnPos(int) const;	

	/*
	 * Dice si la CorrePocoyo tiene o no corredores.
	 */
	bool esVacia() const;

	
	/*
	 * Devuelve la cantidad de corredores de la CorrePocoyo.
	 */
	int tamanio() const;	

	/*
	 * Devuelve true si las CorrePocoyos son iguales.
	 */
	bool operator==(const CorrePocoyo<T>&) const;	
	
	/*
	 * Debe mostrar la carrera por el ostream (y retornar el mismo).
	 * CorrePocoyo vacio: []
	 */
	ostream& mostrarCorrePocoyo(ostream&) const;
	
	
  private:
	/*
	 * No se puede modificar esta funcion.
	 */
	CorrePocoyo<T>& operator=(const CorrePocoyo<T>& otra) {
		assert(false);
		return *this;
	}

	/*
	 * Aca va la implementación del nodo.
	 */
	struct Nodo {
		T elem;
		Nodo* prev;
		Nodo* sig;
		
		
	};
	Nodo* cam;
	Nodo* primero;
	Nodo* ultimo;
	int tam;
};

template<class T>
ostream& operator<<(ostream& out, const CorrePocoyo<T>& a) {
	return a.mostrarCorrePocoyo(out);
}

// Implementación a hacer por los alumnos.
template <typename T>
CorrePocoyo<T>::CorrePocoyo()
{
		primero = NULL;
		ultimo = NULL;
		tam = 0;
		cam = NULL;
}

template <typename T>
CorrePocoyo<T>::CorrePocoyo(const CorrePocoyo<T>& aCopiar){
	primero = NULL;
	ultimo = NULL;
	tam = 0;
	cam = NULL;
			
	for(int i = 1; i <= aCopiar.tamanio(); i++){
		nuevoCorredor(aCopiar.dameCorredorEnPos(i));
	}
	
	if(!(aCopiar.esVacia())) {
		int posCamara = damePosicion(aCopiar.corredorFilmado());
		Nodo* temp = primero;
		while(posCamara > 1) {
			temp = temp->sig;
			posCamara--;
		}
		cam = temp;
	}
}

template <typename T>
CorrePocoyo<T>::~CorrePocoyo(){
	if(tam == 0){
	}
	else if(tam == 1){
		delete primero;
	}else{
		Nodo * temp = primero;
		Nodo * temp_sig = temp->sig;
		
		
	  while(temp->sig != NULL) {
		    delete temp;
		    temp = temp_sig;
		    temp_sig = temp_sig->sig;
		
	  }
	  delete temp;
  }
	
}

template <typename T>
void CorrePocoyo<T>::seCansa(const T& cansado) {
	int pos = damePosicion(cansado);
	int i = 1;
	Nodo* temp = primero;
	while (i < pos){
		temp = temp->sig;
		i = i + 1;
	} 
	if (cam == temp)	{cam = NULL;}
	if (temp->prev != NULL){
		(temp->prev)->sig = temp->sig;
		if (cam == temp)	{cam = temp->sig;}
		} 
	else { 
		primero = temp->sig;
	}
	if (temp->sig != NULL){
		if (cam == temp)	{cam = temp->prev;}
		(temp->sig)->prev = temp->prev;
		} 
	else { 
		ultimo = temp->prev;
	}
	delete temp;
	tam = tam - 1;
}

template <typename T>
void CorrePocoyo<T>::sobrepasar(const T& pasador){
	int pos = damePosicion(pasador);
	int i = 1;
	Nodo* rapido = primero;
	while (i < pos){
		rapido = rapido->sig;
		i = i + 1;
	} 
	Nodo* lento = rapido->prev;
	
	rapido->prev = lento->prev;
	lento->sig = rapido->sig;
	rapido->sig = lento;
	lento->prev = rapido;
	if(lento->sig == NULL){ // es el ultimo
		ultimo =lento;
	}else{
		(lento->sig)->prev = lento;
	}
	if(rapido->prev == NULL){//Es el primero
		primero = rapido;
	}else{
		(rapido->prev)->sig = rapido;
	}
	/*if (lento != primero){
		(rapido->sig)->prev = rapido->prev;//guarda que rapido no sea ultimo
		
		
		
	}else{
		rapido->prev = NULL;
		rapido->sig = lento;
		primero = rapido;
	}
	else{
		ultimo = lento;
		lento->sig = NULL;
	}
	
	if (lento->prev = NULL){
		primero = rapido;
	}
	else{
		lento->prev = rapido;
	}
	
	lento = lento->prev;
*/	
	}

template <typename T>
void CorrePocoyo<T>::nuevoCorredor(const T& nuevo, const T& delante){
	/*int pos = damePosicion(delante);
	int i = 1;
	Nodo* temp = primero;
	while (i < pos){
		temp = temp->sig;
		i = i + 1;
	}*/
	
	Nodo * temp = primero;
	
	while(temp->elem != delante){
		temp = temp->sig;
	}
	
	
	Nodo* pnuevo = new Nodo; 
	pnuevo->elem = T(nuevo);  
	//pnuevo->prev = temp->prev;
	//pnuevo->sig = temp;
	//temp->prev = pnuevo;
	
	if (temp->prev != NULL){
		(temp->prev)->sig = pnuevo;
		pnuevo->prev = temp->prev;
		temp->prev = pnuevo;
		pnuevo->sig = temp;
		//(pnuevo->prev)->sig = pnuevo;	
	} else {//==NULL
		temp->prev = pnuevo;
		pnuevo->sig = temp;	
		primero = pnuevo;
		pnuevo->prev = NULL;
	}
	tam++;
}

template <typename T>
void CorrePocoyo<T>::nuevoCorredor(const T& nuevo) {
		Nodo* temp = new Nodo;
		temp->sig = NULL;
		temp->prev = ultimo;
		temp->elem = T(nuevo);
		if (primero == NULL){
			primero = temp;
			cam = temp;
		}
		else{
			ultimo->sig = temp;
		}
		ultimo = temp;		
		tam++; 
}

template<typename T>
const T& CorrePocoyo<T>::dameCorredorEnPos(int n) const {
	if(n <= (tam/2)){
		Nodo* buscador = primero;
		for(int i = 1; i < n; i++) {
			buscador = buscador->sig;
		}
		return buscador->elem;
	}else{
		Nodo* buscador = ultimo;
		for(int i = tam; i > n; i--) {
			buscador = buscador->prev;
		}
		return buscador->elem;
	}
}

template<typename T>
bool CorrePocoyo<T>::esVacia() const{
	return tam==0;
}

template<typename T>
int CorrePocoyo<T>::tamanio() const{
	return tam;	
}

template<typename T>
int CorrePocoyo<T>::damePosicion(const T& cosa) const{	
	int i = 1;	
	Nodo* buscador = primero;
	while (buscador != NULL){
			if (buscador->elem == cosa){
				return i; 		
			}		
			else{
				buscador = buscador->sig;
				i++;
			}
			
	}
	return 0;	
}

template<typename T>
const T& CorrePocoyo<T>::damePrimero() const {
	return primero->elem;
}

template<typename T>
const T& CorrePocoyo<T>::corredorFilmado() const {
	return (cam->elem);
}

template<typename T>
void CorrePocoyo<T>::filmarProxPerdedor(){
	if(cam->sig != NULL) cam = cam->sig;
}

template<typename T>
void CorrePocoyo<T>::filmarProxExitoso(){
	if(cam->prev != NULL) cam = cam->prev;
}

template<typename T>
bool CorrePocoyo<T>::operator==(const CorrePocoyo<T>& otro) const {
	if(tamanio() != otro.tamanio()){
		return false;
	}else{
		int i = 1;
		while(i < tam && dameCorredorEnPos(i) == otro.dameCorredorEnPos(i)) i++;
		return i == tam;
	}
}

template<typename T>
ostream& CorrePocoyo<T>::mostrarCorrePocoyo(ostream& out) const{
	out << "[";
	for(int i = 1; i <= tam; i++) {
		out << dameCorredorEnPos(i);
		if(i < tam) out << ", ";
	}
			
	out << "]";
	
	return out;
}

#endif //CORREPOCOYO_H_
