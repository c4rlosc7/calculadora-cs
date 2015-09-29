//Carlos Andres Martinez - Cliente Servidor
#include <iostream>
#include <string>
#include <cassert>
#include <zmqpp/zmqpp.hpp>

using namespace std;
using namespace zmqpp;

// FACTORIAL 
int factorial(int op1){
	if(op1 < 2)return 1;
	return op1 * factorial(op1-1);
}
int main()
{	
	cout << "running server" << endl;
	context ctx;
	socket s(ctx, socket_type::xrep);
	s.bind("tcp://*:5555");

	while (true){
		message m;	
		s.receive(m);	
		string id;
		m >> id;
		//cout << id << endl;
		string tipo;
		m >> tipo;
		//cout << tipo << endl;
		int op1;
		int op2;	

		message r;
		int resultado;

		if (tipo == "suma"){
			cout << "hola" << endl;
			m >> op1;
			m >> op2;			
			resultado = op1 + op2;
			r << id;
			r << resultado;
			cout << "La suma de " << op1 << " + " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if(tipo == "resta"){
			m >> op1;
			m >> op2;			
			resultado= op1 - op2;
			r << id;
			r << resultado;
			cout << "La resta de " << op1 << " - " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if(tipo == "multiplicacion"){
			m >> op1;
			m >> op2;			
			resultado= op1 * op2;
			r << id;
			r << resultado;
			cout << "La multiplicacion de " << op1 << " * " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if(tipo == "division"){
			m >> op1;
			m >> op2;			
			resultado = op1 / op2;
			r << id;
			r << resultado;
			cout << "La division de " << op1 << " / " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if (tipo == "factorial"){
			m >> op1;			
			resultado = factorial(op1);	
			r << id;
			r << resultado;
			cout << "El factorial de " << op1 << " = " << resultado << endl;
			s.send(r);
		}									
	}		
	return 0;
}