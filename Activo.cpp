/*
 * Activo.cpp
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */
#include<iostream>
#include "Pregunta.h"
#include "Activo.h"
#include "Respuesta.h"
#include "Fecha.h"

Activo::Activo(Pregunta* _preg): Estado(_preg){
	cout<<"constructor de clase activa"<<endl;
}

Activo::~Activo() {
	cout<<"destructor de clase activa"<<endl;
}

bool Activo::Responder(string usuario,string descripcion,string imagen,Fecha fechaResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	Respuesta *nuevaRespuesta = new Respuesta(usuario,descripcion,imagen,fechaResp);
	Preg->AgregarRespuesta(nuevaRespuesta);
	cout<<"la respuesta se guardo con exito"<<endl;
	return true;
}

bool Activo::Responder(string usuario,string descripcion,Fecha fechaResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	Respuesta *nuevaRespuesta = new Respuesta(usuario,descripcion,fechaResp);
	Preg->AgregarRespuesta(nuevaRespuesta);
	cout<<"la respuesta se guardo con exito"<<endl;
	return true;

	/*
	 *
	 * Preg-> solamente puedo acceder a los metodos publicos de la clase Pregunta ¿como hago para acceder a los metodos privados o protegidos?


		hay metodos como el de AgregarRespuesta o cambiar estado que solamente quiero que sean accesibles por los estados y no por el usuario
		pero si los declaro como protegidos o privados el estado no puede acceder a ellos. ¿estaria bien declarar esos metodos como privados
		y, en la clase pregutna, declarar a Activo como clase amiga?¿No iria esto contra el principio solid de encapsulamiento?
	 *
	 *
	 */
}



