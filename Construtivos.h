#ifndef CONSTRUTIVOS_H_
#define CONSTRUTIVOS_H_

#include "Estrutura.h"
#include "Util/printable.h"

#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

vector<int> constroiSolucaoAleatoria(Dados& dados);

int retornaMenorDist(int cidadeAtual, vector<int>& LCC, Dados& dados);

vector<int> constroiSolucaoVMPGuloso(Dados& dados);

vector<int> retornaMenor3Dist(int cidadeAtual, vector<int>& LCC, Dados& dados);

vector<int> constroiSolucaoVMPParcialmenteGuloso(Dados& dados);

#endif
