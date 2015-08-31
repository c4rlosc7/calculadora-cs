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
// SUMA
int suma(int op1, int op2){
	return op1 + op2;
}

int main(){
	
	cout << "SERVER" << endl;
	context ctx;

	socket s(ctx, socket_type::rep);
	s.bind("tcp://*:5555");

	while (true){

		//cout<<"Esperendo mensaje\n";
		message m;	
		s.receive(m);

		string tipo;
		int op1;
		int op2;

		m >> tipo;

		message r;
		int resultado;

		if (tipo == "suma"){
			m >> op1;
			m >> op2;
			resultado = suma(op1, op2);
			r << resultado;
			cout << "La suma de " << op1 << " + " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if(tipo == "resta"){
			m >> op1;
			m >> op2;			
			resultado= op1 - op2;
			r << resultado;
			cout << "La resta de " << op1 << " - " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if(tipo == "multiplicacion"){
			m >> op1;
			m >> op2;			
			resultado= op1 * op2;
			r << resultado;
			cout << "La multiplicacion de " << op1 << " * " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if(tipo == "division"){
			m >> op1;
			m >> op2;			
			resultado = op1 / op2;
			r << resultado;
			cout << "La division de " << op1 << " / " << op2 << " = " << resultado << endl;
			s.send(r);
		}else if (tipo == "fac"){
			m >> op1;			
			resultado = factorial(op1);	
			r << resultado;
			cout << "El factorial de " << op1 << " = " << resultado << endl;
			s.send(r);
		}									
	}		
	return 0;
}