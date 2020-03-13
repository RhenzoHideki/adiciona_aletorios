// Implemente aqui a função

#include "questao.h"

void adiciona_aleatorios(list<int> & umaLista, int N){

    srand(time(NULL)); //começa o contador para o aleatório

    for (int i = 0; i < N ; ++i)
    {
        umaLista.push_back(rand()%70);
    }

    umaLista.sort();
}