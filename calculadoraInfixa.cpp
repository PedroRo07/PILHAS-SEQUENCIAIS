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
    std::vector<char> pilha_operadores;

    int tam = expressao.length();

    for (int i=0; i<tam; i++){
        char c = expressao[i];

        if(c == '(' || c == ' '){
            continue;
        }

        else if (c >= '0' && c <= '9'){
            pilha_valores.push_back(c - '0');
        }

        else if(c == '+' || c == '*'){
            pilha_operadores.push_back(c);
        }

        else if(c == ')'){
            int val2 = pilha_valores.back();
            pilha_valores.pop_back();

            int val1 = pilha_valores.back();
            pilha_valores.pop_back();

            char op = pilha_operadores.back();
            pilha_operadores.pop_back();

            int resultado = 0;

            if (op == '+'){
                resultado = val1+val2;
            }else if( op == '*'){
                resultado = val1 * val2;
            }
            pilha_valores.push_back(resultado);
        }
    }

    std::cout << "Resultado final: " << pilha_valores.back() << "\n";

    return 0;
}