//============================================================================
// Name        : DiazProjectState.cpp
// Author      : Exequiel Diaz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Sistema.h"
#include "Usuario.h"
#include "Fecha.h"
#include "Pregunta.h"
#include "Inactivo.h"

int main() {
	Fecha f0(10,8,2021);
	Fecha f1(10,5,2022);
	Fecha f2(11,5,2022);
	Fecha f3(11,5,2022);
	Fecha f4(13,8,2022);

	Sistema sist;
	sist.AgregarUsuarios("Exequiel", "Diaz", "Argentina", "exe@gmail", "123");
	sist.AgregarUsuarios("Daiana", "Rueda", "Argentina", "dai@gmail", "456");
	sist.AgregarUsuarios("Gaby", "Echazu", "Korea", "gaby@gmail", "789");
	sist.AgregarUsuarios("Lilen", "Diaz", "Suiza", "li@gmail", "101");
	sist.ListarUsuarios();

	//quiero obtener un usuario para agregar preguntas desde su cuenta
	Usuario user0,user1,user2,user3;

	user0 = sist.GetUsuario("exe@gmail", "123");//obtengo una referencia de los usuarios
	user1 = sist.GetUsuario("dai@gmail", "456");//obtengo una referencia de los usuarios
	user2 = sist.GetUsuario("gaby@gmail", "789");//obtengo una referencia de los usuarios
	user3 = sist.GetUsuario("gaby@gmail", "789");//obtengo una referencia de los usuarios

	sist.AgregarPreguntas(user0.GetNombre(), "¿Que es un puntero?", "vi este tema en clases pero no entendí", f0);
	sist.AgregarPreguntas(user1.GetNombre(), "¿como recorrer un arreglo?", "no puedo recorrer este arreglo de punteros", f1);
	sist.ListarPreguntas();

	//seccion para responder preguntas
	sist.ResponderUnaPregunta(101, user1.GetNombre(), "un puntero es una variable que almacena una direccion de memoria", f1);
	sist.ResponderUnaPregunta(101, user2.GetNombre(), "un puntero es una referencia creo", f1);
	sist.ResponderUnaPregunta(101, user1.GetNombre(), "khe?", f1);
	sist.ResponderUnaPregunta(101, user0.GetNombre(), "gracias por responder", f1);
	//likeo preguntas
	sist.DarLikeUnaRespuesta(user0.GetId(), 151);
	sist.DarLikeUnaRespuesta(user0.GetId(), 151);//verifico si un mismo usuario puede dar mas de un like

	sist.ResponderUnaPregunta(102, user1.GetNombre(), "lo puedes recorrer con un for", f1);
	sist.ResponderUnaPregunta(102, user2.GetNombre(), "tambien con un while", f1);
	sist.ResponderUnaPregunta(102, user1.GetNombre(), "khe?", f1);

	cout<<"***************"<<endl;
	cout<<"***************"<<endl;
	cout<<"******ACTUALIZADO*********"<<endl;
	cout<<"***************"<<endl;
	cout<<"***************"<<endl;
	sist.ListarPreguntas();


	return 0;
}
