#include <stdio.h>
#include "Menus.h"


/* Menu principal */
int menu_principal(void)
{
  int escolha;

  do {
    printf("\n*******************Menu Principal************************* \n");
    printf("ATENCAO: Necessario gerar solucao inicial antes de refinar\n");
    printf("                1. Gere solucao inicial \n");
    printf("                2. Descida \n");
    printf("                3. Descida randomica \n");
    printf("                4. Descida com Primeiro de Melhora \n");
    printf("                5. GRASP \n");
    printf("                6. SA \n");
    printf("                0. Sair \n");
    printf("                Escolha: ");
    scanf("%d",&escolha);
  } while (escolha < 0 || escolha > 6);
  return escolha;
}



/* Menu de geracao de uma solucao inicial */
int menu_solucao_inicial(void)
{
  int escolha;

  do {
    printf("\n------------Geracao da Solucao Inicial---------------- \n");
    printf("                1. Gulosa (Vizinho mais proximo) \n");
    printf("                2. Parcialmente gulosa (Vizinho mais proximo) \n");
    printf("                3. Gulosa (Insercao Mais Barata) \n");
    printf("                4. Parcialmente gulosa (Insercao Mais Barata) \n");
    printf("                5. Aleatoria \n");
    printf("                escolha: ");
    scanf("%d",&escolha);
  } while (escolha < 1 || escolha > 5);
  return escolha;
}
