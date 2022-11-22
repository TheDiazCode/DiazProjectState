/*
 * Pregunta.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */

#ifndef PREGUNTA_H_
#define PREGUNTA_H_
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include "Fecha.h"
#include "Estado.h"
#include "Respuesta.h"
#include "Activo.h"
#include "Solucionado.h"
#include "Inactivo.h"

class Pregunta {
protected:

private:
	static int preguntasCreadas;
	int id;//id de la pregunta
	string nombreUsuario;//nombre del usuario que crea la pregunta
	string titulo;
	string descripcion;
	string imagen;
	Fecha fechaPublicacion;
	vector <Respuesta*> listaRespuestas;
	vector <string*> notificaciones;
	Estado* estadoActual;

public:
	Pregunta(string nombreUsuario,string titulo,string descripcion,string imagen,Fecha fechaPublicacion);
	Pregunta(string nombreUsuario,string titulo,string descripcion,Fecha fechaPublicacion);
	virtual ~Pregunta();
	Pregunta(const Pregunta &other);
	//getters
	int GetId();
	string GetNombreUsuario();
	string GetTitulo();
	string GetDescripcion();
	string GetImagen();
	Fecha GetFechaPublicacion();
	//Setters

	//funciones de la clase
	void MostrarPregunta();
	template <typename T>
	void CambiarEstadoActual();
	bool responder(string usuario,string descripcion,string imagen,Fecha fecharResp);
	bool responder(string usuario,string descripcion,Fecha fecharResp);
	void AgregarRespuesta( Respuesta *c){
		listaRespuestas.insert(listaRespuestas.end(),c);
	}
	void VerificarPregActiva(){
		Fecha FechaP = this->GetFechaPublicacion();//fecha de publicacion de la respuesta
		if(!listaRespuestas.empty()){
			Fecha UltResp = listaRespuestas.back()->GetFechaResp();//fecha de la ultima respuesta
			if((UltResp-FechaP)>=(6*30)){
				delete estadoActual;
			    estadoActual = new Inactivo(this);
			}
		}else{
			Fecha actual;//fecha del dia de hoy
			if((actual-FechaP)>=(6*30)){
				delete estadoActual;
				estadoActual = new Inactivo(this);
			}else{
				delete estadoActual;
				estadoActual = new Activo(this);
			}
		}
	}
	void MostrarResp(){
		for(size_t i=0; i<listaRespuestas.size();i++){
			VerificarPregActiva();
			listaRespuestas[i]->MostrarRespuesta();
		}
	}
	//friend class Activo;
	bool MarcarRespSolucionada(const string &aceptada){
		if(aceptada == "aceptada"){
			delete estadoActual;
				estadoActual = new Solucionado(this);
			return true;
		}else{
			return false;
		}
	}
	void DarLike(int idUsuario,int idResp){
		for(size_t i =0; i< listaRespuestas.size();i++){
			if(listaRespuestas[i]->GetId() == idResp){
				listaRespuestas[i]->AddMg(idUsuario);
			}
		}
	}

};

#endif /* PREGUNTA_H_ */
