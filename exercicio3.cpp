#include <iostream>
#include <vector>

int main() {
    std::vector<int> pilhaUm;
    int valor;

    std::cout << "Digite numeros inteiros positivos (0 para encerrar a leitura):\n";

    while (true) {
        std::cout << "> ";
        std::cin >> valor;

        if (valor == 0) {
            break;
        }

        if (valor > 0) {
            pilhaUm.push_back(valor); 
        } else {
            std::cout << "Apenas numeros positivos sao aceitos.\n";
        }
    }

    std::cout << "\n--- Numeros Pares Desempilhados ---\n";

    if (pilhaUm.empty()) {
        std::cout << "A pilha P1 esta vazia.\n";
    } else {
        while (!pilhaUm.empty()) {
            int topo = pilhaUm.back();
            
            if (topo % 2 == 0) {
                std::cout << topo << " ";
            }
            
            pilhaUm.pop_back(); 
        }
        std::cout << "\n";
    }

    return 0;
}