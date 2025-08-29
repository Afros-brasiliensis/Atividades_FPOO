#include "Retangulo.h"

int main() {
	float base, altura;
	//Entrada de dados desse float logo acima
	cout << "Digite a base em metros: " << endl;
	cin >> base;
	cout << "Digite a altura em metros: " << endl;
	cin >> altura;
	//Cria um objeto do tipo Retangulo e chama os m�todos setBase e setAltura
	Retangulo retangulo;
	//Seta os valores de base e altura
	retangulo.setBase(base);
	retangulo.setAltura(altura);
	//Calcula a area do retangulo e imprime o resultado
	cout << "A area do retangulo e " << retangulo.calculaArea() << " m2" << endl;

}