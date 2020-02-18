#include "BuscasLocais.h"

vector<int> geraVizinhoAleatorioTroca(vector<int>& sol)
{
	vector<int> novaSol = sol;
	int i = rand() % sol.size();
	int j;
	do
	{
		j = rand() % sol.size();
	}while(i == j);

	int aux = novaSol[i];
	novaSol[i] = novaSol[j];
	novaSol[j] = aux;

	return novaSol;

}

vector<int> BLtroca(Dados& dados, vector<int>& solucao)
{
    int pos1, pos2, melhorPos1, melhorPos2; 
    // fazendo uma copia para modificacao
    vector<int> solCorrente = solucao;
    // definindo minha melhor avaliacao como a FO da solucao passada como parametro
    double melhorFO = avaliar(dados, solucao);
    int aux;
    bool melhorou = false;

    do
    {
        melhorou = false;

        for(pos1 = 0; pos1 < solCorrente.size() - 1; pos1++)
        {
            for(pos2 = pos1 + 1; pos2 < solCorrente.size(); pos2++)
            {
                // aplicando o movimento troca(pos1, pos2)
                aux = solCorrente[pos1];
                solCorrente[pos1] = solCorrente[pos2];
                solCorrente[pos2] = aux;

                double fo = avaliar(dados, solCorrente);         
                
                if( fo < melhorFO )
                {
                    melhorPos1 = pos1;
                    melhorPos2 = pos2;
                    melhorFO = fo;
                    melhorou = true;
                }

                // destrocando as posições -> desfazendo o movimento troca(pos1,pos2)
                aux = solCorrente[pos1];
                solCorrente[pos1] = solCorrente[pos2];
                solCorrente[pos2] = aux;

            }
        }
        
        if(melhorou)
        {
            // analisei toda a vizinhança, então irei mover para o melhor vizinho
            aux = solCorrente[melhorPos1];
            solCorrente[melhorPos1] = solCorrente[melhorPos2];
            solCorrente[melhorPos2] = aux;
        }

    }while(melhorou);

    return solCorrente;

}
