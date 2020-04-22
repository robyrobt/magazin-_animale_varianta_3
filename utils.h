#pragma once
#include <iostream>
#include <deque>
#include <vector>

struct data {
	int an, luna, zi;
};

struct data convert_string_to_data(const std::string, char delim);

template<typename T>
void showAll(std::deque<T> elem) {
	for (auto obj : elem) {
		std::cout << obj;
	}
}