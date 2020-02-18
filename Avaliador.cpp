#include "Avaliador.h"


// Função que calcula a Função de Avaliação (Função Objetivo)
double avaliar(Dados& dados, vector<int>& solucao)
{   

    double fo = 0;
    
    // distancia da cidade do caixeiro até a primeira posicao
    fo += dados.dist(0, solucao[0]);

    // somar a distâncias das demais cidades na solucao
    // solucao.size() -> dados.N-1
    for( int pos = 0; pos < solucao.size() - 1; pos++)
    {
        fo += dados.dist( solucao[pos], solucao[pos+1] );
    }

    // faltou somar a distância da ultima cidade para a cidade do caixeiro

    fo += dados.dist(solucao[solucao.size()-1] , 0);

    return fo;

}
