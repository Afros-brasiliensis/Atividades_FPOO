#include "Retangulo.h"

Retangulo::Retangulo(void) {
	base = 0;
	altura = 0;
}

Retangulo::~Retangulo() {
}
// Implementação dos métodos da classe Retangulo
void Retangulo::setBase(float base) {
	this->base = base;
}
// Método para definir a altura do retângulo
void Retangulo::setAltura(float altura) {
	this->altura = altura;
}
// Método para calcular a área do retângulo
double Retangulo::calculaArea() {
	area = base * altura;
	return area;
}
// Métodos para obter os valores de base e altura
float Retangulo::getBase() {
	return base;
}
// Método para obter a altura do retângulo
float Retangulo::getAltura() {
	return altura;
}
