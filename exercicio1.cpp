#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

int main(){
    SetConsoleOutputCP(65001);

    std::string expressao;
    std::cout << "Digite a expressão: \n";
    std::getline(std::cin, expressao);

    std::vector<int> pilha_valores;

    int tam = expressao.length();

    for (int i=0; i<tam; i++){
        char c = expressao[i];

        if(c == ' '){
            continue;
        }

        else if (c >= '0' && c <= '9'){
            pilha_valores.push_back(c - '0');
        }

        else if(c == '+' || c == '*'){
            int val2 = pilha_valores.back();
            pilha_valores.pop_back();

            int val1 = pilha_valores.back();
            pilha_valores.pop_back();

            int resultado = 0;

            if (c == '+'){
                resultado = val1+val2;
            }else if(c == '*'){
                resultado = val1 * val2;
            }
            pilha_valores.push_back(resultado);
        }
    }

    std::cout << "Resultado final: " << pilha_valores.back() << "\n";

    return 0;
}