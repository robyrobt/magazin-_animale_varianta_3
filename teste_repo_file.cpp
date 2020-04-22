#include <cassert>
#include "animal.h"
#include "teste_repo_file.h"
#include "repo_file.h"

void teste_add_and_del_repo_file() {
	struct data data_caine, data_pisica;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	Animal a1(2, "caine", 39, data_caine, 12, 3), a2(3, "pisica", 34, data_pisica, 1, 3);
	Repo_file<Animal> repo("test_repo_file.txt");
	assert(repo.getSize() == 1);
	repo.addItem(a1);
	assert(repo.getSize() == 2);
	int i = repo.removeItem(a1);
	assert(i == 0);
}

void teste_update_repo_file() {
	struct data data_caine, data_pisica;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	Animal a1(2, "caine", 39, data_caine, 12, 3), a2(3, "pisica", 34, data_pisica, 1, 3);
	Repo_file<Animal> repo("test_repo_file.txt");
	assert(repo.getSize() == 1);
	repo.addItem(a1);
	std::deque<Animal> elem = repo.getAll();
	repo.updateItem(elem[0], a2);
	assert(strcmp(elem[0].getName(), "pisica") == 0);
}

void teste_find_repo_file() {
	struct data data_caine, data_pisica, data_cal;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	data_cal.zi = 13;
	data_cal.luna = 12;
	data_cal.an = 2000;
	Animal a(1, "cal", 123.4, data_cal, 4, 2), a1(2, "caine", 39, data_caine, 12, 3), a2(3, "pisica", 34, data_pisica, 1, 3);
	Repo_file<Animal> repo("test_repo_file.txt");
	assert(repo.getSize() == 1);
	repo.addItem(a1);
	int i = repo.findElemPos(a), j = repo.findElemPos(a2);
	assert(i == 0);
	assert(j == -1);
	Animal c = repo.findElemByName("cal"), c1 = repo.findElemByName("maimuta");
	assert(c == a);
	assert(c1 == Animal());
}