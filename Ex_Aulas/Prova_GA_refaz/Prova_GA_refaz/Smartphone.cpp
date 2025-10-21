#pragma once
#include "Smartphone.h"

Smartphone::Smartphone() : Produto() {
	modelo = "";
	armazenamento = 0;
}

Smartphone::Smartphone(string nome, float preco, int codigoDeBarras, string modelo, int armazenamento) {
	this->setNome(nome);
	this->setPreco(preco);
	this->setCodigoDeBarras(codigoDeBarras);
	this->modelo = modelo;
	this->armazenamento = armazenamento;
}

Smartphone::~Smartphone() {
}

string Smartphone::getModelo() {
	return modelo;
}

int Smartphone::getArmazenamento() {
	return armazenamento;
}

void Smartphone::setModelo(string modelo){
	this->modelo = modelo;
}

void Smartphone::setArmazenamento(int armazenamento) {
	this->armazenamento = armazenamento;
}

void Smartphone::imprimeSmartphone() {
	this->imprimeProduto();
	cout << "Modelo: " << this->getModelo() << endl;
	cout << "Armazenamento: " << this->getArmazenamento() << " GB" << endl;
}