/*
 * Respuesta.cpp
 *
 *  Created on: 16 nov. 2022
 *      Author: Alumno
 */

#include "Respuesta.h"

int Respuesta::respuestasCreadas= 150;
Respuesta::Respuesta(string usuario,string descripcion,string imagen,Fecha fecharResp){
	this->id = ++respuestasCreadas;
	this->usuario = usuario;
	this->descripcion = descripcion;
	this->imagen = imagen;
	this->fechaResp = fecharResp;

}

Respuesta::Respuesta(string usuario,string descripcion,Fecha fecharResp){
	this->id = ++respuestasCreadas;
	this->usuario = usuario;
	this->descripcion = descripcion;
	this->fechaResp = fecharResp;

}

Respuesta::~Respuesta() {
	//cout<<"destructor de respuesta"<<endl;
}


int Respuesta::GetId(){return this->id;}
string Respuesta::GetUsuario(){return this->usuario;}
string Respuesta::GetDescripcion(){return this->descripcion;}
string Respuesta::GetImagen(){return this->imagen;}
Fecha Respuesta::GetFechaResp(){return this->fechaResp;}


void Respuesta::MostrarRespuesta(){
	cout<<"\t------------------"<<endl;
	cout<<"\tRespuesta Nro: "<<this->GetId()<<endl;
	cout<<"\t"<<this->GetUsuario()<<" responde:"<<endl;
	cout<<"\t"<<this->descripcion<<endl;
	cout<<"\tLikes: "<< this->listaMg.size()<<endl;
	cout<<"\tFecha Publicacion:"<<this->GetFechaResp()<<endl;
}

