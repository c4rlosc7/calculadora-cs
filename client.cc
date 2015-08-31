//Carlos Andres Martinez - Cliente Servidor
#include <iostream>
#include <string>
#include <cassert>
#include <zmqpp/zmqpp.hpp>

using namespace std;
using namespace zmqpp;

int main(){
	
	cout << "CLIENT" << endl;

	context ctx;
	socket s(ctx, socket_type::req);
	s.connect("tcp://localhost:5555");

	message m;	

	int c;
	int estado = 1;

	while(estado == 1)
	{

		cout << "Escribe la operacion que desea"	<< endl;
		cout << "1.suma 2.resta 3.multi 4.division 5.factorial 0.resultado = ";
		cin >> c;

		switch(c)
		{
			case 1: 
				int s1,s2;
				cout << "Ingrese N1: ";
				cin >> s1;
				cout << "Ingrese N2: ";
				cin >> s2;			

				m << "suma";
				m << s1;
				m << s2;
				s.send(m);
				break;

			case 2:
				int r1,r2;
				cout << "Ingrese N1: ";
				cin >> r1;
				cout << "Ingrese N2: ";
				cin >> r2;			
				//r = r1 - r2;
				//cout << "La resta es: " << r <<endl;
				m << "resta";
				m << r1;
				m << r2;
				s.send(m);	
				break;		

			case 3:
				int m1,m2;
				cout << "Ingrese N1: ";
				cin >> m1;
				cout << "Ingrese N2: ";
				cin >> m2;			
				//m = m1 * m2;
				//cout << "La multiplicacion es: " << m <<endl;
				m << "multiplicacion";
				m << m1;
				m << m2;
				s.send(m);				
				break;		
	 
			case 4: 
				int d1,d2;
				cout << "Ingrese N1: ";
				cin >> d1;
				cout << "Ingrese N2: ";
				cin >> d2;			
				//d = d1 / d2;
				//cout << "La division es: " << d <<endl;
				m << "division";
				m << d1;
				m << d2;
				s.send(m);				
				break;

			case 5:
				int f;
				cout << "Ingrese # a calcular el factorial: ";
				cin >> f;
				//rf = factorial(f);
				//cout << "El factorial es: " << rf << endl;
				m << "fac";
				m << f;
				//m << s2;
				s.send(m);				
				break;

			default:
				estado = 2;
				cout << "saliendo... \n" << endl;
		}

	}
	message r;
	s.receive(r); 
	int result;
	r >> result;
	cout << "El resultado es :" << result << endl;	
	return 0;
}