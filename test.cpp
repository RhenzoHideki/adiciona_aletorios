//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include <list>
#include "questao.h"
#include "gtest/gtest.h"

using namespace std;

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }
};

TEST_F(TesteQuestao, Vazia) {
    list<int> l;
    try {
        adiciona_aleatorios(l, 0);
        if (! l.empty()) {
            FAIL()<<"lista possui " << l.size() << " números, mas deveria estar vazia";
            return;
        }
    } catch (...) {
        FAIL()<<"falha fatal ao adicionar números à lista";
    }
}

TEST_F(TesteQuestao, Simples) {
    list<int> l;
    try {
        adiciona_aleatorios(l, 1);
        if (l.size() != 1)  {
            FAIL()<<"lista possui " << l.size() << " números, mas deveria ter somente um valor";
            return;
        }
    } catch (...) {
        FAIL()<<"falha fatal ao adicionar números à lista";
    }
}

TEST_F(TesteQuestao, Muitos)
{
    for (int j=10; j > 0; j++) {
        list<int> l;
        int N = 3 + (rand() % 15);

        try {
            adiciona_aleatorios(l, N);
            if (l.size() != N) {
                FAIL() << "lista possui " << l.size() << " números, mas deveria ter " << N;
                return;
            }
            auto it = l.begin();
            int last = *it;
            while (it != l.end()) {
                int novo = *it;
                if (novo < last) {
                    ostringstream out;

                    for (auto & x: l) out << x << ',';
                    FAIL() << "números não estão ordenados: " + out.str();
                    return;
                }
                last = novo;
                it++;
            }
        } catch (...) {
            FAIL() << "falha fatal ao adicionar números à lista";
        }
    }
}