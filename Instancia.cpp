#include "Instancia.h"

void lerDados(Scanner& scanner, Dados& dados)
{
    // Lendo o número de cidades
	dados.N = scanner.nextInt();

    // Lendo o id e as coordenadas de cada cidade
	for (int i = 0; i < dados.N; i++)
	{
        int id = scanner.nextInt();		
        int x = scanner.nextInt();
		int y = scanner.nextInt();

        Par coord;
        coord.x = x;
        coord.y = y;
        // Adicionando os valores das coordenadas no vetor de coordenadas
		dados.coords.push_back(coord);
	}

    // Declarando minha matriz de distâncias
    // Declarando matriz quadrada -> Matrix<tipo>(tam); declaro uma matriz tam x tam
    // Declarando matriz comum    -> Matrix<tipo>(lin,col); declaro uma matriz lin x col
	dados.dist = Matrix<double>(dados.N);

    // calculando a distância
	for(int i = 0; i < dados.N; i++)
	{
		for(int j = 0; j < dados.N; j++)
		{
			dados.dist(i,j) = sqrt( pow(dados.coords[i].x - dados.coords[j].x,2) + pow(dados.coords[i].y - dados.coords[j].y,2) );
		}
	}

}
















