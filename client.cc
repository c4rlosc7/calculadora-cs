//Carlos Andres Martinez - Cliente Servidor
#include <iostream>
#include <string>
#include <cassert>
#include <zmqpp/zmqpp.hpp>

using namespace std;
using namespace zmqpp;

int main(int argc, char **argv)   // ./client suma 1 1
{
	cout << "running client "<<endl;

	string operador1 = argv[2];         // operador 1
	int op1 = std::stoi (operador1);

	string operador2 = argv[3];        // operador 2
	int op2 = std::stoi (operador2);

	context ctx;
	socket s(ctx, socket_type::req);
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
	//while(true)
	//{
		switch(c)
		{
			case 1:
				m << comparar;
				m << op1;
				m << op2;
				s.send(m);
				break;

			case 2:
				m << comparar;
				m << op1;
				m << op2;
				s.send(m);
				break;

			case 3:
				m << comparar;
				m << op1;
				m << op2;
				s.send(m);
				break;

			case 4:
				m << comparar;
				m << op1;
				m << op2;
				s.send(m);
				break;

			case 5:
				m << comparar;
				m << op1;
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
	//}
	return 0;
}
