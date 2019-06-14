/**


Gabriel Teixeira Lacerda
Matrícula: 2016026302
Richard Wagner Abras Ribeiro Sobrinho
Matrícula: 2013030244


**/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

std::string removePunctuation(std::string word){
    word.erase(std::remove_if(word.begin(), word.end(),
                  [](char ch){ return !::iswalnum(ch); }), word.end());
    return word;
}

int main() {

    cout << "\n \n \t\t MAQUINA DE BUSCA \n\n";
    cout << "Digite os nomes dos arquivos para a busca e tecle enter " << endl;
    cout << "Apos o ultimo, digite \"fim\"" << endl;

    string nomeArquivo;
    vector <string> nomesArquivos;

    while(nomeArquivo != "fim"){
    	cin >> nomeArquivo;
    	nomesArquivos.push_back(nomeArquivo);
    }

    ifstream file;
    map <string, set<string>> indexAoContrario;

    for (int i = 0; i < (int)nomesArquivos.size() - 1; i++){

	    string p = "";
	    file.open(nomesArquivos[i]);

	    if(file.is_open()) {

            while (file >> p){
                for(auto& c : p)
                    c = tolower(c);
                    p = removePunctuation(p);
                    indexAoContrario[p].insert(nomesArquivos[i]);
            }
            file.close();

	    }else{
            cout << "\n Arquivo " << nomesArquivos[i] << " nao encontrado. \n";
        }
	}


   	cout << "\n\n -Qual palavra deseja buscar? ";

   	string search;
   	cin >> search;

   	set<string>::iterator set_it;
	map<string, set<string>>::iterator map_it;

   	map_it = indexAoContrario.find(search);

   	if (map_it != indexAoContrario.end())
        for(set_it = map_it->second.begin(); set_it != map_it->second.end(); set_it++)
            cout << " " << *set_it << " \n";

   	else
        cout << "\n Palavra nao encontrada!\n";


    return 0;
}
