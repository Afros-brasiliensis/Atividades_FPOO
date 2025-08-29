#include "Retangulo.h"

Retangulo::Retangulo(void) {
	base = 0;
	altura = 0;
}

Retangulo::~Retangulo() {
}
// Implementa��o dos m�todos da classe Retangulo
void Retangulo::setBase(float base) {
	this->base = base;
}
// M�todo para definir a altura do ret�ngulo
void Retangulo::setAltura(float altura) {
	this->altura = altura;
}
// M�todo para calcular a �rea do ret�ngulo
double Retangulo::calculaArea() {
	area = base * altura;
	return area;
}
// M�todos para obter os valores de base e altura
float Retangulo::getBase() {
	return base;
}
// M�todo para obter a altura do ret�ngulo
float Retangulo::getAltura() {
	return altura;
}
