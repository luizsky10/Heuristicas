#ifndef METAHEURISTICAS_H_
#define METAHEURISTICAS_H_

#include "Estrutura.h"
#include "Avaliador.h"
#include "Construtivos.h"
#include "BuscasLocais.h"
#include <math.h>

#include<vector>

using namespace std;


double fRand(double fMin, double fMax);

vector<int> GRASP(Dados& dados, int iterMax);


vector<int> SA(Dados& dados, double taxaResf, int SAMax, double TempIni, vector<int>& sol);

#endif
