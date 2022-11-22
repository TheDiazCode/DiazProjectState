/*
 * Solucionado.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */

#ifndef SOLUCIONADO_H_
#define SOLUCIONADO_H_
#include "Estado.h"

class Solucionado : public Estado{
	string nombre = "solucionado";
public:
	Solucionado(Pregunta* _preg);
	virtual ~Solucionado();
	virtual bool Responder(string usuario,string descripcion,string imagen,Fecha fechaResp) override;
	virtual bool Responder(string usuario,string descripcion,Fecha fechaResp) override;
};

#endif /* SOLUCIONADO_H_ */
