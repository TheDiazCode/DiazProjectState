/*
 * Estado.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */

#ifndef ESTADO_H_
#define ESTADO_H_
#include "Fecha.h"
#include "Respuesta.h"

class Pregunta;

class Estado {
protected:
	Pregunta *Preg;

public:

	Estado(Pregunta* _preg);//le mando una referencia de la pregunta a la cual el estado pertenece
	virtual ~Estado();
	virtual bool Responder(string usuario,string descripcion,string imagen,Fecha fechaResp)=0;
	virtual bool Responder(string usuario,string descripcion,Fecha fechaResp)=0;

};

#endif /* ESTADO_H_ */
