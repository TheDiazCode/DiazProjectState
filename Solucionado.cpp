/*
 * Solucionado.cpp
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */
#include<iostream>
#include "Pregunta.h"
#include "Solucionado.h"

Solucionado::Solucionado(Pregunta* _preg): Estado(_preg) {
	cout<<"constructor de clase solucionado"<<endl;
}

Solucionado::~Solucionado() {
	cout<<"destructor de clase solucionado"<<endl;
}

bool Solucionado::Responder(string usuario,string descripcion,string imagen,Fecha fecharResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	return true;
}

bool Solucionado::Responder(string usuario,string descripcion,Fecha fecharResp){
	//aqui deberia crear una respuesta y agregarlo a mi lista de respuestas y enviar notificacion a mi vector de notificaciones
	return true;
}

