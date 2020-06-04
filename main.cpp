#include <iostream>
#include "main.h"
#include <chrono>

int n;
int* w; // pesos
int* v; //valores
int capacity; //capacidade
int best = 0; //o maior valor encontrado
int totalWeight = 0; //peso total
int* bestData; // pointer para melhor
int bestR;

void combine(int* arr, int n, int r)
{
    int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}


//funcao recursiva que faz combinacoes nCr
void combinationUtil(int* arr, int* data, int start, int end, int index, int r){
    //Se for subconjunto de tamanho r
    if (index == r){
        checkVW(data, r);
    }
    //
    for (int i = start; i <= end && end - i + 1 >= r - index; i++){
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}


//verifica se o conjunto de items tem demasiado peso, e se tem maior valor que o atual melhor candidato. Guarda os dados.
void checkVW(int* indexCombination, int& r){
    int wSum = 0;
    int vSum = 0;
    for (int i = 0; i < r; ++i) {
        wSum += w[indexCombination[i]];
        if(wSum > capacity){
            return;
        }
        vSum += v[indexCombination[i]];
    }
    if(vSum > best){
        best = vSum;
        bestData = new int[r]; //guarda os elementos
        for (int i = 0; i < r; ++i) {
            bestData[i] = indexCombination[i];
        }
        totalWeight = wSum;
        bestR = r; //e quantos ha
    }
    return;
}


int main(){
    //Ler de standard input de acordo com a especificacao
    std::cin >> n;
    std::cin >> capacity;
    w = new int[n];
    v = new int[n];

    for (int k = 0; k <n; ++k) {
        std::cin >> w[k];
    }

    for (int k = 0; k <n; ++k) {
        std::cin >> v[k];
    }

    //start timer

    auto start = std::chrono::steady_clock::now();

    int* arr = new int[n]; // array de indices
    for (int j = 0; j < n; ++j) {arr[j] = j;}

    for(int i = 0; i<=n; i++){
        combine(arr, n , i);
    }
    std::cout << totalWeight << std::endl;
    std::cout << best << std::endl;
    for (int i = 0; i < bestR; ++i) {
        std::cout << bestData[i] << " ";
    };

    //end timer
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << std::endl << "Took " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;



}

