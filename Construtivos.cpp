#include "Construtivos.h"

// Retorno é a representação da solução
vector<int> constroiSolucaoAleatoria(Dados& dados)
{
    vector<int> solucao;

    for(int i = 1; i < dados.N; i++)
    {
        solucao.push_back(i);
    }

    random_shuffle(solucao.begin(), solucao.end());

    return solucao;

}

int retornaMenorDist(int cidadeAtual, vector<int>& LCC, Dados& dados)
{
    int menorPos = 0;
    double menorDist = dados.dist(cidadeAtual, LCC[0]);

    for(int pos = 1; pos < LCC.size(); pos++)
    {
        if( dados.dist(cidadeAtual, LCC[pos]) < menorDist )
        {
            menorPos = pos;
            menorDist = dados.dist(cidadeAtual, LCC[pos]);
        }
    }

    return menorPos;
}

vector<int> constroiSolucaoVMPGuloso(Dados& dados)
{
    int cidadeAtual = 0;

    // solucao vazia
    vector<int> solucao;

    // construindo a lista de cidades candidatas
    vector<int> LCC;
    for(int i = 1 ; i < dados.N; i++)
    {
        LCC.push_back(i);
    }

    // verificando qual a proxima cidade devo adicionar

    while( LCC.size() != 0 ) // enquanto tiver cidades para adicionar    
    {
        // retorna a posicao em LCC, da cidade mais próxima da cidadeAtual
        int pos = retornaMenorDist(cidadeAtual, LCC, dados);

        // adicionando essa cidade a solucao
        solucao.push_back( LCC[pos] );

        // atualizar a minha cidade atual
        cidadeAtual = LCC[pos];

        // remover essa cidade de LCC
        LCC.erase(LCC.begin() + pos);

    }

    return solucao;
}


vector<int> retornaMenor3Dist(int cidadeAtual, vector<int>& LCC, Dados& dados)
{
    vector<int> menor3pos;
    menor3pos.push_back(0);
    menor3pos.push_back(-1);
    menor3pos.push_back(-1);

    vector<double> menor3Dist;
    menor3Dist.push_back(dados.dist(cidadeAtual, LCC[0]));
    menor3Dist.push_back(9999999);
    menor3Dist.push_back(9999999);

    double distAtual = 0;

    for(int pos = 1; pos < LCC.size(); pos++)
    {
        distAtual = dados.dist(cidadeAtual, LCC[pos]);
        if( distAtual < menor3Dist[0] )
        {
            menor3pos[2] = menor3pos[1];
            menor3pos[1] = menor3pos[0];
            menor3pos[0] = pos;
            
            menor3Dist[2] = menor3Dist[1];
            menor3Dist[1] = menor3Dist[0];
            menor3Dist[0] = distAtual;
        }
        else
        {
            if( distAtual < menor3Dist[1] )
            {
                menor3pos[2] = menor3pos[1];
                menor3pos[1] = pos;
                
                menor3Dist[2] = menor3Dist[1];
                menor3Dist[1] = distAtual;

            }
            else
            {
                if ( distAtual < menor3Dist[2])
                {
                    menor3pos[2] = pos;

                    menor3Dist[2] = distAtual;
                }
            }
        }
    }

#ifdef DEBUG
    cout << "teste: " << menor3pos << endl;
    getchar();
#endif
    return menor3pos;
}

vector<int> constroiSolucaoVMPParcialmenteGuloso(Dados& dados)
{
    int cidadeAtual = 0;

    // solucao vazia
    vector<int> solucao;

    // construindo a lista de cidades candidatas
    vector<int> LCC;
    for(int i = 1 ; i < dados.N; i++)
    {
        LCC.push_back(i);
    }

    // verificando qual a proxima cidade devo adicionar

    while( LCC.size() != 0 ) // enquanto tiver cidades para adicionar    
    {
        // retorna as 3 posicões em LCC, de cidades mais próximas da cidadeAtual na Lista Restrita de candidatos (LRC)
        vector<int> LRC = retornaMenor3Dist(cidadeAtual, LCC, dados);
    
        // selecionando aleatoriamente uma das posições
        int posLRC;        
        if ( LCC.size() >= 3 )
        {
            posLRC = rand() % 3;
        }
        else
        {
            posLRC = rand() % LCC.size();
        }    
        


        int pos = LRC[posLRC];        

        // adicionando essa cidade a solucao
        solucao.push_back( LCC[pos] );

        // atualizar a minha cidade atual
        cidadeAtual = LCC[pos];

        // remover essa cidade de LCC
        LCC.erase(LCC.begin() + pos);

    }

    return solucao;
}











