#pragma once
#include "repo_file.h"
#include "animal.h"

class AnimalService {
	private:
		Repo_file<Animal> repo;
	public:
		AnimalService();
		AnimalService(Repo_file<Animal>&);
		~AnimalService();
		void updateAnimal(const char*, int, const char*, float, struct data, int, int);
		int findAnimalPos(Animal&);
		Animal findAnimalByName(const char*);
		std::deque<Animal> getAll();
		int getSize();
};

