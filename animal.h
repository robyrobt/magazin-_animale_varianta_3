#pragma once
#include <iostream>
#include "utils.h"

class Animal {
	private:
		int cod, varsta, nr_exemplare;
		char* name;
		float pret;
		struct data data;
public:
	Animal();
	Animal(int, const char*, float, struct data, int, int);
	Animal(const Animal&);
	Animal(std::string);
	~Animal();

	int getCod();
	int getVarsta();
	int getNrExemplare();
	char* getName();
	float getPret();
	struct data getData();
	void setCod(int);
	void setVarsta(int);
	void setNrExemplare(int);
	void setName(const char*);
	void setPret(float);
	void setData(struct data);

	bool operator == (const Animal&);
	Animal operator = (const Animal&);

	friend std::ostream& operator << (std::ostream& os, Animal);
	friend std::istream& operator >> (std::istream& is, Animal&);

};