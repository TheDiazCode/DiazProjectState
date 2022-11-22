/*
 * Sistema.h
 *
 *  Created on: 21 nov. 2022
 *      Author: Usuario
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include<iostream>
#include<vector>
#include "Usuario.h"
#include "Pregunta.h"

using namespace std;

class Sistema {
private:
	vector<Usuario*> listaUsuario;
	vector<Pregunta*> listaPreguntas;
public:
	Sistema();
	virtual ~Sistema();

	bool AgregarUsuarios(string nombre, string apellido,string pais, string email,string password);
	void ListarUsuarios();
	Usuario GetUsuario(string email,string password);//logueo

	bool AgregarPreguntas(string nombreUsuario,string titulo,string descripcion,string imagen,Fecha fechaPublicacion);
	bool AgregarPreguntas(string nombreUsuario,string titulo,string descripcion,Fecha fechaPublicacion);
	void ListarPreguntas();
	void ResponderUnaPregunta(int idPregunta,string usuario,string descripcion,string imagen,Fecha fecharResp);
	void ResponderUnaPregunta(int idPregunta,string usuario,string descripcion,Fecha fecharResp);
	void DarLikeUnaRespuesta(int idUsuario,int idResp);
};

#endif /* SISTEMA_H_ */
