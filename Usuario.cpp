/*
 * Usuario.cpp
 *
 *  Created on: 21 nov. 2022
 *      Author: Usuario
 */

#include "Usuario.h"
#include<iostream>
using namespace std;

int Usuario::cuentasCreadas = 0;
Usuario::Usuario(string nombre,string apellido,string pais,string email,string password){
	//cout<<"constructor de usuario"<<endl;
	this->id = ++Usuario::cuentasCreadas;
	this->nombre = nombre;
	this->apellido = apellido;
	this->pais = pais;
	this->email = email;
	this->password = password;
}

Usuario::Usuario(){
	//cout<<"constructor de usuario"<<endl;
};
Usuario::~Usuario() {
	//cout<<"destructor de usuario"<<endl;
}

Usuario::Usuario(const Usuario &other) {
	// TODO Auto-generated constructor stub

}

int Usuario::GetId(){return this->id;}
string Usuario::GetNombre(){return this->nombre;}
string Usuario::GetApellido(){return this->apellido;}
string Usuario::GetPais(){return this->pais;}
string Usuario::GetEmail(){return this->email;}
string Usuario::GetPassword(){return this->password;}

void Usuario::MostrarUsuario(){
	cout<<"------Usuario----------"<<endl;
	cout<<"nombre: "<< this->nombre<<endl;
	cout<<"apellido: "<<this->apellido<<endl;
	cout<<"pais: "<<this->pais<<endl;
	cout<<"emaill: "<<this->email<<endl;
}

ostream & operator<<(ostream& salida, Usuario &usuario) {
	salida<< "Usuarios "<<endl;
	salida<< "id: "<< usuario.GetId()<<endl;
	salida<< "nombre:  "<<usuario.GetNombre()<<endl;
	salida<< "apellido: "<<usuario.GetApellido()<<endl;
	salida<< "pais: " <<usuario.GetPais()<<endl;
	salida<< "Email: " <<usuario.GetEmail()<<endl;
	salida<< "password: " <<usuario.GetPassword()<<endl;
	return salida;
}

