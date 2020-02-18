#include "Metaheuristicas.h"

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

vector<int> SA(Dados& dados, double taxaResf, int SAMax, double tempIni, vector<int>& sol)
{
	vector<int> melhorSol = sol;
	vector<int> solCorrente = sol;
	double melhorFO = avaliar(dados, sol);
	double FOcorrente = melhorFO;
	int iterT = 0;
	double T = tempIni;

	while(T > 0.01)
	{
		for(iterT = 0; iterT < SAMax; iterT++)
		{
			//gerando um vizinho aleatorio com a Estrutura de Vizinhança - Troca
			vector<int> solLinha = geraVizinhoAleatorioTroca(solCorrente);
			double FOlinha = avaliar(dados, solLinha);
			double delta = FOlinha - FOcorrente;
			
			if( delta < 0) // melhorei a solucao corrente
			{
				solCorrente = solLinha;
				FOcorrente = FOlinha;
				if( FOlinha < melhorFO)
				{
					melhorSol = solLinha;
					melhorFO = FOlinha;
					cout<<"FO SA Temp: "<< T << " : " << melhorFO<<endl;
				}

			}
			else
			{
				double x = fRand(0,1);
				if( x < pow(2.718, -delta/T) )
				{
					solCorrente = solLinha;
					FOcorrente = FOlinha;
				}
			}
		}
		T = taxaResf * T;
		iterT = 0;
	}

	return melhorSol;
}


vector<int> GRASP(Dados& dados, int iterMax)
{
	// repetição até um critério de parada (tempo, iteração, iteração sem melhora)
	// construo uma solucao
	// aplico uma busca local
	// verifico se a solucao é a melhor de todas as iterações
	//   - se for melhor, atualizo a minha melhor solucao

	vector<int> melhorSol;
	vector<int> solCorrente;
	
	double melhorFO = 999999999, FOcorrente;

	for(int i = 0; i < iterMax; i++)
	{
		solCorrente = constroiSolucaoVMPParcialmenteGuloso(dados);
		vector<int> novaSol = BLtroca(dados, solCorrente);
		FOcorrente = avaliar(dados, novaSol);
		if(FOcorrente < melhorFO)
		{
			melhorFO = FOcorrente;
			melhorSol = novaSol;
			cout<<"GRASP iter " << i << ": " << melhorFO <<endl;
		}
	}

	return melhorSol;

}








