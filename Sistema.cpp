/*
 * Sistema.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: Usuario
 */

#include "Sistema.h"
#include "Usuario.h"
#include <vector>

Sistema::Sistema() {


}

bool Sistema::AgregarUsuarios(string nombre, string apellido,string pais, string email,string password){
	Usuario *nuevoUsuario = new Usuario(nombre,apellido,pais,email,password);
	listaUsuario.insert(listaUsuario.end(),nuevoUsuario);
	return true;
}

void Sistema::ListarUsuarios(){
	for(size_t i=0; i<listaUsuario.size();i++){

			listaUsuario[i]->MostrarUsuario();
		}
}

Usuario Sistema::GetUsuario(string email, string password){
	Usuario copia;
	for(size_t i=0; i<listaUsuario.size();i++)
	{
		bool esIgual = email == listaUsuario[i]->GetEmail();
		bool esIgual2 = password == listaUsuario[i]->GetPassword();
		if(esIgual & esIgual2){
			copia = *listaUsuario[i];
			return copia;
		}
	}
	return copia;
}

bool Sistema::AgregarPreguntas(string nombreUsuario,string titulo,string descripcion,string imagen,Fecha fechaPublicacion){
	Pregunta *nuevaPregunta = new Pregunta(nombreUsuario,titulo,descripcion,imagen,fechaPublicacion);
	listaPreguntas.insert(listaPreguntas.end(),nuevaPregunta);
	return true;
}
bool Sistema::AgregarPreguntas(string nombreUsuario,string titulo,string descripcion,Fecha fechaPublicacion){
	Pregunta *nuevaPregunta = new Pregunta(nombreUsuario,titulo,descripcion,fechaPublicacion);
	listaPreguntas.insert(listaPreguntas.end(),nuevaPregunta);
	return true;
}

void Sistema::ListarPreguntas(){
	for(size_t i=0; i<listaPreguntas.size();i++){

		listaPreguntas[i]->MostrarPregunta();
		listaPreguntas[i]->MostrarResp();
	}

}

void Sistema::ResponderUnaPregunta(int idPregunta,string usuario,string descripcion,string imagen,Fecha fecharResp){
	for(size_t i=0; i<listaPreguntas.size();i++){
			if(listaPreguntas[i]->GetId() == idPregunta){
				listaPreguntas[i]->responder(usuario, descripcion, imagen, fecharResp);
			}
		}
}

void Sistema::ResponderUnaPregunta(int idPregunta,string usuario,string descripcion,Fecha fecharResp){
	for(size_t i=0; i<listaPreguntas.size();i++){
			if(listaPreguntas[i]->GetId() == idPregunta){
				listaPreguntas[i]->responder(usuario, descripcion, fecharResp);
			}
		}
}

void Sistema::DarLikeUnaRespuesta(int idUsuario,int idResp){
	for(size_t i=0; i<listaPreguntas.size();i++){
		listaPreguntas[i]->DarLike(idUsuario,idResp);
	}
}

Sistema::~Sistema() {
	//destruyo la lista de usuarios
			vector<Usuario*>::iterator it;
				for (it=listaUsuario.begin(); it!=listaUsuario.end(); ++it){
					delete (*it);
				}
				listaUsuario.clear();
		//destruto la lista de preguntas
			vector<Pregunta*>::iterator it2;
					for (it2=listaPreguntas.begin(); it2!=listaPreguntas.end(); ++it2){
						delete (*it2);
					}
					listaPreguntas.clear();
}



