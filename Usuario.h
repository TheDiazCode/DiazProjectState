/*
 * Usuario.h
 *
 *  Created on: 21 nov. 2022
 *      Author: Usuario
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include<iostream>
using namespace std;
#include "Fecha.h"

class Usuario {
private:
	static int cuentasCreadas;
	int id;
	string nombre;
	string apellido;
	string pais;
	string email;
	string password;

public:
	Usuario();
	Usuario(string nombre,string apellido,string pais,string email,string password);
	virtual ~Usuario();
	Usuario(const Usuario &other);
	//getters y setters
	int GetId();
	string GetNombre();
	string GetApellido();
	string GetPais();
	string GetEmail();
	string GetPassword();
	void MostrarUsuario();bool CrearPregunta(string nombreUsuario,string titulo,string descripcion,string imagen,Fecha fechaPublicacion);
};
ostream & operator<<(ostream& salida, Usuario &usuario);
#endif /* USUARIO_H_ */
