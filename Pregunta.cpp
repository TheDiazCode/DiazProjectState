/*
 * Pregunta.cpp
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */

#include "Pregunta.h"
#include "Respuesta.h"
#include "Activo.h"
#include <vector>
#include <algorithm>


int Pregunta::preguntasCreadas= 100;
Pregunta::Pregunta(string nombreUsuario,string titulo,string descripcion,string imagen,Fecha fechaPublicacion)
:estadoActual(new Activo(this))
{
	this->id = ++preguntasCreadas;
	this->nombreUsuario = nombreUsuario;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->imagen = imagen;
	this->fechaPublicacion = fechaPublicacion;
}

Pregunta::Pregunta(string nombreUsuario,string titulo,string descripcion,Fecha fechaPublicacion)
:estadoActual(new Activo(this))
{
	this->id = ++preguntasCreadas;
	this->nombreUsuario = nombreUsuario;
	this->titulo = titulo;
	this->descripcion = descripcion;

	this->fechaPublicacion = fechaPublicacion;
}

Pregunta::~Pregunta() {
	//cout<<"destructor de pregunta"<<endl;
	vector<Respuesta*>::iterator it2;
	for (it2=listaRespuestas.begin(); it2!=listaRespuestas.end(); ++it2){
		delete (*it2);
	}
	listaRespuestas.clear();
}

Pregunta::Pregunta(const Pregunta &other) {
	cout<<"se copia la pregunta"<<endl;
}
/***********GETTERS**************/
int Pregunta::GetId(){return this->id;}
string Pregunta::GetNombreUsuario(){return this->nombreUsuario;}
string Pregunta::GetTitulo(){return this->titulo;}
string Pregunta::GetDescripcion(){return this->descripcion;}
string Pregunta::GetImagen(){return this->imagen;}
Fecha Pregunta::GetFechaPublicacion(){return this->fechaPublicacion;}

//setters


/*********fUNCIONES DE LA CLASE************/
void Pregunta::MostrarPregunta(){

	cout<<"------Pregunta----------"<<endl;
	cout<<"id: "<< this->id<<endl;
	cout<<"autor/a: "<<this->GetNombreUsuario()<<endl;
	cout<<"Titulo: "<<this->GetTitulo()<<endl;
	cout<<"Descripcion: "<<this->GetDescripcion()<<endl;
	cout<<"imagen: "<<this->GetImagen()<<endl;
	cout<<"Fecha: "<<this->GetFechaPublicacion()<<endl;
}

template <typename T>
void Pregunta::CambiarEstadoActual(){
	std::cout<<"actualizar estado"<<std::endl;
	delete estadoActual;
	estadoActual = new T(this);
}

bool Pregunta::responder(string usuario,string descripcion,string imagen,Fecha fecharResp){
	estadoActual->Responder(usuario,descripcion,imagen,fecharResp);
	return true;
}

bool Pregunta::responder(string usuario,string descripcion,Fecha fecharResp){
	estadoActual->Responder(usuario,descripcion,fecharResp);
	return true;
}

