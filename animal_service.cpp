#include "animal_service.h"

AnimalService::AnimalService() {}

AnimalService::AnimalService(Repo_file<Animal>& repo) {
	this->repo = repo;
}

void AnimalService::updateAnimal(const char* name, int new_cod, const char* new_name, float new_pret, struct data new_data, int new_varsta, int new_nr_exemplare) {
	Animal up(new_cod, new_name, new_pret, new_data, new_varsta, new_nr_exemplare);
	std::deque<Animal> elem = this->getAll();
	for (int i = 0; i < this->getSize(); i++) {
		if (strcmp(name, elem[i].getName()) == 0) {
			repo.updateItem(elem[i], up);
			i = this->getSize() + 10;
		}
	}
	repo.saveToFile();
}

std::deque<Animal> AnimalService::getAll() {
	return repo.getAll();
}

int AnimalService::findAnimalPos(Animal& animal) {
	return repo.findElemPos(animal);
}

Animal AnimalService::findAnimalByName(const char* name) {
	return repo.findElemByName(name);
}

int AnimalService::getSize() {
	return repo.getSize();
}