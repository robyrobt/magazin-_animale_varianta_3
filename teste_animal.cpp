#include <cassert>
#include "utils.h"
#include "animal.h"
#include "teste_animal.h"

void teste_animal() {
	struct data data_caine;
	data_caine.zi = 2;
	data_caine.luna = 9;
	data_caine.an = 1990;
	Animal animal, caine(1, "caine", (float)123.2, data_caine, 4, 4);
	assert(animal.getCod() == 0);
	assert(animal.getName() == NULL);
	assert(caine.getData().an == 1990);
	assert(caine.getVarsta() == 4);
}