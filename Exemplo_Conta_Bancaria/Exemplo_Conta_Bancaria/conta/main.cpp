#include "ContaBancaria.h"

int main()
{
	ContaBancaria conta;

	conta.abrir(1000, 512, "Marcio Martins", "teste12", poupanca);
	cout << conta.consultarSaldo("teste") << endl;
	cout << conta.consultarSaldo("teste12") << endl;
	conta.depositar(1000);
	cout << conta.consultarSaldo("teste12") << endl;
	conta.depositar(1000);
	cout << conta.consultarSaldo("teste12") << endl;

	if(conta.alteraSenha("qualquercoisa", "teste"))
		cout << "Senha alterada" << endl;
	else
		cout << "A senha nao foi alterada" << endl;

	if(conta.alteraSenha("qualquercoisa", "teste12"))
		cout << "Senha alterada" << endl;
	else
		cout << "A senha nao foi alterada" << endl;

	if(!conta.sacar(500, "qualquercoisa"))
		cout << "O saque nao foi possivel" << endl;

	cout << conta.consultarSaldo("qualquercoisa") << endl;

	if(!conta.sacar(2000, "qualquercoisa"))
		cout << "O saque nao foi possivel" << endl;

	cout << conta.consultarSaldo("qualquercoisa") << endl;

	if(!conta.sacar(1000, "qualquercoisa"))
		cout << "O saque nao foi possivel" << endl;

	cout << conta.consultarSaldo("qualquercoisa") << endl;

	if (!conta.sacar(1000, "teste12"))
		cout << "O saque foi possível" << endl;
	else
		cout << "O saque nao foi possivel" << endl;
	

	system("pause");
	return 0;
}