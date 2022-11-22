/*
 * Respuesta.h
 *
 *  Created on: 16 nov. 2022
 *      Author: Alumno
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include<iostream>
#include<vector>
using namespace std;
#include "Fecha.h"

class Sistema;

class Respuesta {
private:
	static int respuestasCreadas;
	int id;
	string usuario;//usuario que responde
	string descripcion;//Descripcion de la respuesta
	string imagen;
	Fecha fechaResp;
	vector<int> listaMg;

public:

	Respuesta(string usuario,string descripcion,string imagen,Fecha fecharResp);
	Respuesta(string usuario,string descripcion,Fecha fecharResp);
	virtual ~Respuesta();

	int GetId();
	string GetUsuario();
	string GetDescripcion();
	string GetImagen();
	Fecha GetFechaResp();
	int GetMG();

	void MostrarRespuesta();
	void AddMg(int idUsuario){
		bool bandera = true;
		for(size_t i;i<listaMg.size();i++){
			if(listaMg[i]==idUsuario){
				bandera = false;
				break;
			}
		}

		if(bandera){
			listaMg.insert(listaMg.end(),idUsuario);
		}
	}
};

#endif /* RESPUESTA_H_ */
