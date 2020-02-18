//============================================================================
// Universidade Federal de Viçosa - Campus Rio Paranaíba
// Disciplina SIN 492 - Inteligência Computacional para Otimização
// Aplicação de Técnicas heurísticas para o Problema do Caixeiro Viajante
// Autor: Pablo Luiz Araújo Munhoz
// Data: 19/03/2018
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "Instancia.h"
#include "Menus.h"
#include "Construtivos.h"
#include "Avaliador.h"
#include "BuscasLocais.h"
#include "Metaheuristicas.h"
#include "Util/Scanner++/Scanner.h"
#include "Util/printable.h"

using namespace std;


int main(int argc, char* argv[])
{
	Scanner sc(new File(argv[1]));

	srand(time(NULL));


	Dados dados;
    
    // leitura dos dados
	lerDados(sc, dados);

	cout << "Leitura" << endl;
	cout << "N: " << dados.N <<endl;
	cout << " Dist (0, 0) : " << dados.dist(0,0) << endl;
	cout << " Dist (2, 1) : " << dados.dist(2,1) << endl;

    
    vector<int> solucao;
     vector<int> novaSol;

	int escolha = 0;
	do {
		escolha = menu_principal();
		switch (escolha) {
    			case 1: // Geracao de uma solucao inicial 
           			switch(menu_solucao_inicial()) {
           				case 1: // Geracao gulosa de uma solucao inicial via metodo do vizinho mais proximo 
						 solucao = constroiSolucaoVMPGuloso(dados);
                         cout << "Solucao VMP: " << solucao << endl;
                         cout << "FO: " << avaliar(dados,solucao) << endl;
					break;
					case 2: // Geracao parcialmente gulosa de uma solucao inicial via metodo do vizinho mais proximo
						 solucao = constroiSolucaoVMPParcialmenteGuloso(dados);
                         cout << "Soluca Parcialmente VMP: " << solucao << endl;
                         cout << "FO: " << avaliar(dados, solucao) << endl;
					break;
					case 3: // Geracao gulosa de uma solucao inicial via metodo da insercao mais barata
						 printf("Ainda nao implementado...\n");
					break;
					case 4: // Geracao parcialmente gulosa de uma solucao inicial via insercao mais barata
						 printf("Ainda nao implementado...\n");
					break;
					case 5: // Geracao aleatória de uma solucao inicial 
						solucao = constroiSolucaoAleatoria(dados);
                        cout << "Solucao Aleatoria: " << solucao << endl;
                        cout << "FO: " << avaliar(dados, solucao) << endl;
					break;
				}
           		break;
		    	case 2: // Descida
				        novaSol = BLtroca(dados,solucao);
                        cout << "Solucao BL: " << novaSol << endl;
                        cout << "FO BL: " << avaliar(dados, novaSol) << endl;
			break;

		    	case 3: // Descida Randômica
				   printf("Nao implementado\n");
			break;

			case 4: // Descida com primeiro de melhora
				   printf("Nao implementado\n");
			break;

			case 5: // grasp
				   solucao = GRASP(dados, 50);
				   cout << "Solucao GRASP: " << solucao <<endl;
				   cout << "FO GRASP: " << avaliar(dados, solucao) << endl;
			break;

			case 6: // grasp
				   //solucao = constroiSolucaoVMPParcialmenteGuloso(dados);
					solucao = constroiSolucaoVMPGuloso(dados);
					cout<< "FO const: " << avaliar(dados, solucao)<< endl;
     				vector<int> nSol = SA(dados, 0.99, 10000, 1000000, solucao);
				   cout << "Solucao SA: " << nSol <<endl;
				   cout << "FO SA: " << avaliar(dados, nSol) << endl;
			break;
    		}
  	} while (escolha != 0);


	return 0;
}











