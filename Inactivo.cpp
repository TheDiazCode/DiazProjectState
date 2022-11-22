/*
 * Inactivo.cpp
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */
#include<iostream>
#include "Fecha.h"
#include "Pregunta.h"
#include "Inactivo.h"
#include "Respuesta.h"

Inactivo::Inactivo(Pregunta* _preg): Estado(_preg) {
	cout<<"constructor de clase Inactiva"<<endl;
}

Inactivo::~Inactivo() {
	cout<<"destructor de clase Inactiva"<<endl;
}

bool Inactivo::Responder(string usuario,string descripcion,string imagen,Fecha fechaResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	Respuesta *nuevaRespuesta = new Respuesta(usuario,descripcion,imagen,fechaResp);
		Preg->AgregarRespuesta(nuevaRespuesta);
		cout<<"la respuesta se guardo con exito"<<endl;
	return true;
}

bool Inactivo::Responder(string usuario,string descripcion,Fecha fechaResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	Respuesta *nuevaRespuesta = new Respuesta(usuario,descripcion,fechaResp);
		Preg->AgregarRespuesta(nuevaRespuesta);
		cout<<"la respuesta se guardo con exito"<<endl;
	return true;
}
