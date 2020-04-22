#include <iostream>
#include "animal.h"

#include "teste_animal.h"
#include "teste_repo_file.h"

void all_test() {
    teste_animal();
    teste_add_and_del_repo_file();
    teste_update_repo_file();
    teste_find_repo_file();
    std::cout << "testele au trecut cu succes" << std::endl;
}

int main()
{
    all_test();
    std::cout << "succes\n";
}

