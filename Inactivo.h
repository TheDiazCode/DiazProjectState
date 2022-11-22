/*
 * Inactivo.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */

#ifndef INACTIVO_H_
#define INACTIVO_H_
#include "Estado.h"

class Inactivo : public Estado{
	string nombre="inactivo";
public:
	Inactivo(Pregunta* _preg);
	virtual ~Inactivo();
	virtual bool Responder(string usuario,string descripcion,string imagen,Fecha fechaResp) override;
	virtual bool Responder(string usuario,string descripcion,Fecha fechaResp) override;
};

#endif /* INACTIVO_H_ */
