#include <sstream>
#include "animal.h"

Animal::Animal() {
	this->cod = 0;
	this->varsta = 0;
	this->nr_exemplare = 0;
	this->pret = 0;
	this->name = NULL;
	this->data.an = 0;
	this->data.luna = 0;
	this->data.zi = 0;
}

Animal::Animal(int cod, const char* name, float pret, struct data data, int varsta, int nr_exemplare) {
	this->cod = cod;
	this->varsta = varsta;
	this->nr_exemplare = nr_exemplare;
	this->pret = pret;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->data.an = data.an;
	this->data.luna = data.luna;
	this->data.zi = data.zi;
}

Animal::Animal(const Animal& animal) {
	this->cod = animal.cod;
	this->varsta = animal.varsta;
	this->nr_exemplare = animal.nr_exemplare;
	this->pret = animal.pret;
	this->name = new char[strlen(animal.name) + 1];
	strcpy_s(this->name, strlen(animal.name) + 1, animal.name);
	this->data.an = animal.data.an;
	this->data.luna = animal.data.luna;
	this->data.zi = animal.data.zi;
}

Animal::Animal(std::string linie) {
	std::istringstream iss(linie);
	std::string cod, varsta, nr_exemplare, name, pret, data;
	iss >> cod >> name >> pret >> data >> varsta >> nr_exemplare;
	this->cod = std::stoi(cod);
	this->name = new char[sizeof(name) + 1];
	strcpy_s(this->name, sizeof(name) + 1, name.c_str());
	this->pret = strtof((pret).c_str(), 0);
	this->varsta = std::stoi(varsta);
	this->nr_exemplare = std::stoi(nr_exemplare);
	struct data data_a = convert_string_to_data(data, '/');
	this->data.zi = data_a.zi;
	this->data.luna = data_a.luna;
	this->data.an = data_a.an;
}

Animal::~Animal() {
	this->cod = 0;
	this->varsta = 0;
	this->nr_exemplare = 0;
	this->pret = 0;
	this->name = NULL;
	this->data.an = 0;
	this->data.luna = 0;
	this->data.zi = 0;
}

int Animal::getVarsta() {
	return this->varsta;
}

int Animal::getNrExemplare() {
	return this->nr_exemplare;
}

struct data Animal::getData() {
	return this->data;
}

char* Animal::getName() {
	return this->name;
}

float Animal::getPret() {
	return this->pret;
}

int Animal::getCod() {
	return this->cod;
}

void Animal::setCod(int new_cod) {
	this->cod = new_cod;
}

void Animal::setVarsta(int new_age) {
	this->varsta = new_age;
}

void Animal::setNrExemplare(int new_nr) {
	this->nr_exemplare = new_nr;
}

void Animal::setName(const char* new_name) {
	if (this->name) {
		delete[] name;
	}
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, strlen(new_name) + 1, new_name);
}

void Animal::setPret(float new_pret) {
	this->pret = new_pret;
}

void Animal::setData(struct data new_data) {
	this->data.an = new_data.an;
	this->data.luna = new_data.luna;
	this->data.zi = new_data.zi;
}

bool Animal::operator == (const Animal& animal) {
	return this->cod == animal.cod;
}

Animal Animal::operator = (const Animal& animal) {
	if (this == &animal) {
		return *this;
	}
	this->setCod(animal.cod);
	this->setVarsta(animal.varsta);
	this->setNrExemplare(animal.nr_exemplare);
	this->setName(animal.name);
	this->setPret(animal.pret);
	this->setData(animal.data);
	return *this;
}

std::ostream& operator << (std::ostream& os, Animal animal) {
	os << animal.cod << " " << animal.name << " " << animal.pret << " " << animal.data.zi << "/" << animal.data.luna << "/" << animal.data.an << " " << animal.varsta << " " << animal.nr_exemplare << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Animal& animal) {
	int cod, varsta, nr_exemplare;
	char* name = new char[30];
	float pret;
	struct data data;
	std::cout << "cod: "; is >> cod;
	std::cout << "name: "; is >> name;
	std::cout << "pret: "; is >> pret;
	std::cout << "data introducerii in magazin" << std::endl;
	std::cout << "zi: "; is >> data.zi;
	std::cout << "luna: "; is >> data.luna;
	std::cout << "anul: "; is >> data.an;
	std::cout << "varsta: "; is >> varsta;
	std::cout << "numar exemplare: "; is >> nr_exemplare;
	animal.setCod(cod);
	animal.setName(name);
	animal.setPret(pret);
	animal.setData(data);
	animal.setVarsta(varsta);
	animal.setNrExemplare(nr_exemplare);
	return is;
}