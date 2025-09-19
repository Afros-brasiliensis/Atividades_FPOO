#include "pessoas.h"

int main() {
	Pessoa p1, p2, p3;
	Pessoa pessoas[3] = { p1, p2, p3 };
	//Entrada de dados
	for (int i = 1; i <= 3; i++) {
		string nome, endereco;
		float idade, altura, qnt_irmaos;
		cout << "Digite o nome da pessoa " << i << ": ";
		getline(cin, nome);
		cout << "Digite a idade da pessoa " << i << ": ";
		cin >> idade;
		cout << "Digite a altura da pessoa " << i << ": ";
		cin >> altura;
		cout << "Digite a quantidade de irmaos da pessoa " << i << ": ";
		cin >> qnt_irmaos;
		cin.ignore(); // Limpa o buffer do cin
		cout << "Digite o endereço da pessoa " << i << ": ";
		getline(cin, endereco);

		//Setando os valores
		pessoas[i - 1].setNome(nome);
		pessoas[i - 1].setIdade(idade);
		pessoas[i - 1].setAltura(altura);
		pessoas[i - 1].setQntIrmaos(qnt_irmaos);
		pessoas[i - 1].setEndereco(endereco);


		cout << endl;

		cout << "---------------------------------" << endl;
		cout << "Informacoes da pessoa " << i << ":" << endl;

		pessoas[i - 1].imprime_info();
		if (pessoas[i - 1].is_filho_unico()) {
			cout << "A pessoa " << i << " e filho unico." << endl;
		} else {
			cout << "A pessoa " << i << " nao e filho unico." << endl;
		}

	}
}