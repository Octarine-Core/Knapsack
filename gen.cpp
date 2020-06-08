#include <iostream>
#include <stdlib.h>

void generateKnapsack(int n);

int main() {
    int n;
    std::cin >> n;
    srand(n);
    generateKnapsack(n);
    return 0;
}

void generateKnapsack(int n){
    std::cout << n << std::endl;
    int capacity = rand() % 1000 + 1;
    std::cout << capacity << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << rand() % capacity + 1 << " "; //entre 0 e capacidade
    }
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << rand() % 10 << " ";
    }
}