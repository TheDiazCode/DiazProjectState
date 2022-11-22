/*
 * Suspendido.cpp
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */
#include<iostream>
#include "Pregunta.h"
#include "Suspendido.h"
#include "Fecha.h"
#include "Respuesta.h"

Suspendido::Suspendido(Pregunta* _preg): Estado(_preg) {
	//cout<<"constructor de clase suspendida"<<endl;
}

Suspendido::~Suspendido() {
	//cout<<"destructor de clase suspendida"<<endl;
}

bool Suspendido::Responder(string usuario,string descripcion,string imagen,Fecha fechaResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	Respuesta *nuevaRespuesta = new Respuesta(usuario,descripcion,imagen,fechaResp);
			Preg->AgregarRespuesta(nuevaRespuesta);
			//cout<<"la respuesta se guardo con exito"<<endl;
	return true;
}

bool Suspendido::Responder(string usuario,string descripcion,Fecha fechaResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	Respuesta *nuevaRespuesta = new Respuesta(usuario,descripcion,fechaResp);
			Preg->AgregarRespuesta(nuevaRespuesta);
			//cout<<"la respuesta se guardo con exito"<<endl;
	return true;
}

