//Carlos Andres Martinez - Cliente Servidor
#include <iostream>
#include <string>
#include <cassert>
#include <zmqpp/zmqpp.hpp>
using namespace std;
using namespace zmqpp;
int main(int argc, char **argv)
{
	cout << "running client" << endl;			
	context ctx;
	socket s(ctx, socket_type::xreq);
	s.connect("tcp://localhost:5555");
	string comparar;
	int c=0;
	comparar = argv[1];
	if (comparar == "suma"){                                 // suma  1
		c = 1;
		cout << "suma" << endl;
	}else if(comparar == "resta"){                           // resta  2
		c = 2;
		cout << "resta" << endl;
	}else if(comparar == "multiplicacion"){                  // multiplicacion  3
		c = 3;
		cout << "multiplicacion" << endl;
	}else if(comparar == "division"){                        // division  4
		c = 4;
		cout << "division" << endl;
	}else if(comparar == "factorial"){                       // factorial  5
		c = 5;
		cout << "factorial" << endl;
	}else{
		cout << "Fatal Error" << endl;
	}

	message m;		
	while(true)
	{
		switch(c)
		{
			case 1: 
				int s1,s2;
				cout << "Ingrese N1: ";
				cin >> s1;
				cout << "Ingrese N2: ";
				cin >> s2;			
				m << argv[1];
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
				m << argv[1];
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
				m << argv[1];
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
				m << argv[1];
				m << d1;
				m << d2;
				s.send(m);				
				break;

			case 5:
				int f;
				cout << "Ingrese # a calcular el factorial: ";
				cin >> f;
				m << argv[1];
				m << f;
				s.send(m);				
				break;
			default:
				cout << "saliendo... \n" << endl;
		}
		message r;
		s.receive(r);	 
		int result;
		r >> result;
		cout << "El resultado es :" << result << endl;		
	}
	return 0;
}