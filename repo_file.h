#ifndef REPO_FILE_H
#define REPO_FILE_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <deque>

template<class T>
class Repo_file {
private:
	std::deque<T> elem;
	const char* file_name;
public:
	Repo_file<T>();
	Repo_file(const char*);
	~Repo_file();
	void loadFromFile(const char*);
	void saveToFile();
	void addItem(T&);
	int removeItem(T&);
	void updateItem(T&, T);
	std::deque<T> getAll();
	int getSize();
	int findElemPos(T);
	T findElemByName(const char*);
};

template <class T>
Repo_file<T>::Repo_file() {
	file_name = NULL;
}

template<class T>
Repo_file<T>::Repo_file(const char* new_file_name) {
	this->file_name = new_file_name;
	std::ifstream f(file_name);
	std::string linie;
	while (getline(f, linie)) {
		T t(linie);
		this->addItem(t);
	}
	f.close();
}

template<class T>
void Repo_file<T>::loadFromFile(const char* new_file_name) {
	this->elem.clear();
	this->file_name = new_file_name;
	std::ifstream f(file_name);
	std::string linie;
	while (getline(f, linie)) {
		T t(linie);
		this->addItem(t);
	}
	f.close();
}

template<class T>
void Repo_file<T>::saveToFile() {
	std::ofstream f(file_name);
	std::deque<T> elem = this->getAll();
	for (int i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}

template<class T>
std::deque<T> Repo_file<T>::getAll() {
	return this->elem;
}

template <class T>
void Repo_file<T>::addItem(T& c) {
	elem.push_back(c);
}

template <class T>
int Repo_file<T>::removeItem(T& t) {
	int i = this->findElemPos(t);
	if (i != -1) {
		elem.erase(elem.begin() + i);
		return 0;
	}
	return -1;
}

template <class T>
int Repo_file<T>::getSize() {
	return this->elem.size();
}

template<class T>
void Repo_file<T>::updateItem(T& most_update, T update) {
	most_update = update;
}

template <class T>
int Repo_file<T>::findElemPos(T t) {
	for (int i = 0; i < this->getSize(); i++) {
		if (elem[i] == t) {
			return i;
		}
	}
	return -1;
}

template <class T>
T Repo_file<T>::findElemByName(const char* name) {
	for (int i = 0; i < this->getSize(); i++) {
		if (strcmp(elem[i].getName(), name) == 0) {
			return elem[i];
		}
	}
	return T();
}

template<class T>
Repo_file<T>::~Repo_file() {
	file_name = NULL;
}

#endif // !REPO_FILE_H

