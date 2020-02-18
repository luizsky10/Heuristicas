#ifndef ESTRUTURA_H_
#define ESTRUTURA_H_

#include "Util/Matrix.hpp"


typedef struct sPar{
    int x;
    int y;
} Par;

typedef struct sDados{
	int N;
	vector<Par> coords;
	Matrix<double> dist;
} Dados;

#endif // ESTRUTURA_H_
