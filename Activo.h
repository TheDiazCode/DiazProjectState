/*
 * Activo.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */

#ifndef ACTIVO_H_
#define ACTIVO_H_
#include "Estado.h"

class Activo : public Estado{
	string nombre = "activo";
public:
	Activo(Pregunta* _preg);
	virtual ~Activo();
	virtual bool Responder(string usuario,string descripcion,string imagen,Fecha fechaResp) override;
	virtual bool Responder(string usuario,string descripcion,Fecha fechaResp) override;
	string GetNombre(){return this->nombre;}
};

#endif /* ACTIVO_H_ */
