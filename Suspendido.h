/*
 * Suspendido.h
 *
 *  Created on: 20 nov. 2022
 *      Author: Usuario
 */

#ifndef SUSPENDIDO_H_
#define SUSPENDIDO_H_
#include "Estado.h"
class Suspendido : public Estado{
	string nombre = "suspendido";
public:
	Suspendido(Pregunta* _preg);
	virtual ~Suspendido();
	virtual bool Responder(string usuario,string descripcion,string imagen,Fecha fecharResp) override;
	virtual bool Responder(string usuario,string descripcion,Fecha fecharResp) override;
};

#endif /* SUSPENDIDO_H_ */
