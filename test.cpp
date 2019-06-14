/**


Gabriel Teixeira Lacerda
Matrícula: 2016026302
Richard Wagner Abras Ribeiro Sobrinho
Matrícula: 2013030244


**/

#include <iostream>
#include <algorithm>

std::string removePunctuation(std::string word){
    word.erase(std::remove_if(word.begin(), word.end(),
                  [](char ch){ return !::iswalnum(ch); }), word.end());
    return word;
}

void testRemovePunctuation() {
    char ch = 'A';
    bool result = iswalnum(ch);
    if (!result) {
        std::cout << "Erro #001 (testRemovePunctuation)" << std::endl;
    }
    ch = 'a';
    result = iswalnum(ch);
    if (!result) {
        std::cout << "Erro #002 (testRemovePunctuation)" << std::endl;
    }
    ch = '0';
    result = iswalnum(ch);
    if (!result) {
        std::cout << "Erro #003 (testRemovePunctuation)" << std::endl;
    }
     ch = '.';
    result = iswalnum(ch);
    if (result) {
        std::cout << "Erro #004 (testRemovePunctuation)" << std::endl;
    }
    ch = '^';
    result = iswalnum(ch);
    if (result) {
        std::cout << "Erro #005 (testRemovePunctuation)" << std::endl;
    }
}


int main(int argc, char** argv) {

    testRemovePunctuation();

    return (EXIT_SUCCESS);
}