#ifndef BUSCASLOCAIS_H_
#define BUSCASLOCAIS_H_

#include "Estrutura.h"
#include "Avaliador.h"

#include<vector>

using namespace std;

vector<int> BLtroca(Dados& dados, vector<int>& solucao);
vector<int> geraVizinhoAleatorioTroca(vector<int>& sol);

#endif
