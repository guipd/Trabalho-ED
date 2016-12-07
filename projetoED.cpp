#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Temp
  {
    int ID; // matricula -> ID
    char nome[50];
    char endereco[50]; // curso -> esdereço
    char datnasc[30];
    float salario[9];
    int cargo[30];
    struct Temp *prox;
  }lista;
  // cria o inicio da lista
  lista *inicio;
//--------------------------------------------------------

// Funcao que define a lista como vazia.
void criaLista()
{
  inicio = NULL;
}

int cadastro()
{
	int y;
  lista *ponteiro;
  ponteiro =  (lista *) malloc(sizeof(lista));
    if (ponteiro==NULL)
    {
      printf("Erro de alocacao\n");
      return 0;
    }
  printf("Digite o ID:");
  scanf("%d",&ponteiro->ID);
  printf("Digite o nome:");
  scanf(" %[^\n]",ponteiro->nome);
  printf("Digite o endereco:");
  scanf(" %[^\n]",ponteiro->endereco);
  printf("Digite a data de nascimento:");
  scanf(" %[^\n]",ponteiro->datnasc);
  printf("Digite o salario:");
  scanf(" %[^\n]",ponteiro->salario);
  printf("Lista de cargos:");
  printf("\n 1_secretaria\n 2_seguranca\n 3_advogado\n 4_engenheiro mecanico\n 5_engenheiro civil\n 6_engenheiro cartografo\n 7_engenheiro dos materiais\n 8_arquiteto de edificacoes\n 9_arquiteto de interiores\n 10_analista de sistemas \n 11_desenhista mecanico\n 12_analista fiscal\n 13_vidraceiro\n 14_supervisor de eletrica\n 15_office boy \n 16_gerente de pintura\n 17_gerente de logistica\n 18_gerente de manutencao\n 19_gerente de marketing\n 20_gerente de obras \n   ");
  printf("\n digite a opcao escolhida: ");
  scanf("%d", &y);

  FILE *fp = fopen("CBO.txt", "r");
   char caractere;
   int linha=1;
while((caractere = fgetc(fp)) != EOF){              //percorre o arquivo caractere por caractere e checa para ver se já esta no fim do mesmo!
	if(linha==y && caractere!='\n'){                   //se estiver na linha 3 e o caractere for diferente de quebra de linha execulta
		printf("%c",caractere);                        //printa o caractere em questão
	}
	if(caractere=='\n'){     //procura quebra de linha e execulta quando encontrar
		linha++;             //incrementa linha, informando que pulou a linha
	}

}
if(linha<y){
	printf("Não existe linha no seu arquivo");
}
  scanf(" %[^\n]",ponteiro->cargo);
  ponteiro->prox = NULL;
    if (inicio==NULL)
      {
        inicio = ponteiro;
      }
    else
      {
     ponteiro->prox = inicio;
     inicio  = ponteiro;
     }
   return 1;
}

void imprime()
{
  lista *ponteirolista;
  if (inicio == NULL) // Caso a lista nao esteja vazia
  {
    printf("funcao-impressao>>lista-null--\n\n");
    return;
  }
  ponteirolista = inicio;
  while (ponteirolista !=NULL) {
    printf("ID = %d\n",ponteirolista->ID);
    printf("Nome = %s\n",ponteirolista->nome);
    printf("Curso = %s\n",ponteirolista->endereco);
    printf("Data de Nascimento = %s\n",ponteirolista->datnasc);
    printf("salario = %s\n",ponteirolista->salario);
    printf("Cargo = %s\n",ponteirolista->cargo);
    ponteirolista = ponteirolista->prox;
    getchar();
    getchar();
  }
  printf("funcao-impressao>>fim-da-lista ---\n\n");
}

void imprimeponterio(lista *ponteirolista)///para imprimir resultado da função busca
{

  if (ponteirolista == NULL) // Caso a função busca restorne null
  {
    printf("Não achou!!");
    return;
  }
    printf("funcao-impressao--ponteiro ---\n\n");
    printf("ID = %d\n",ponteirolista->ID);
    printf("Nome = %s\n",ponteirolista->nome);
    printf("Curso = %s\n",ponteirolista->endereco);
    printf("Data de Nascimento = %s\n",ponteirolista->datnasc);
    printf("salario = %s\n",ponteirolista->salario);
    printf("Cargo = %s\n",ponteirolista->cargo);
    getchar();
    getchar();
}

///-------------------------------------------------pesquisa
///pesquisa por matricula
lista *pesquisaID()
{
   int dado;
   printf("Digite o ID:");
   scanf("%d",&dado);
  lista *ponteiro;
  if (inicio == NULL)
  {
    return NULL;  // Lista Vazia
  }
  // Caso a lista nao esteja vazia
  ponteiro = inicio;
  while (ponteiro !=NULL) {
     printf("procurando %d==%d\n",dado,ponteiro->ID);///comentar parar para de mostra lixo na tela
     getchar();///comentar ai ñ pede enter
    if (ponteiro->ID == dado)  // achou !!
    {
       printf("\nACHOU %d==%d!!!\n",ponteiro->ID,dado);

   return (ponteiro);        // retorna um ponteiro para função imprimir ponteiro

                   }
    else
    {

        ponteiro = ponteiro->prox;

     }
  }
  return NULL;
}
lista *pesquisanome()
{
   char pesq[50];
   printf("Digite o nome:");
   scanf(" %[^\n]",pesq);
  lista *ponteiro;
  if (inicio == NULL)
  {
    return NULL;  // Lista Vazia
  }
  // Caso a lista nao esteja vazia
  ponteiro = inicio;
  while (ponteiro !=NULL) {
     printf("procurando %s==%s\n",pesq,ponteiro->nome);///comentar parar para de mostra lixo na tela
     getchar();///comentar ai ñ pede enter
    if (strcmp (ponteiro->nome,pesq)== 0 )  // achou !!
    {
            printf("\nACHOU %s==%s!!!\n",ponteiro->nome,pesq);
         return (ponteiro);        // retorna um ponteiro para função imprimr

                   }
    else
    {

        ponteiro = ponteiro->prox;

     }
  }
  return NULL;
}

///esvazia a fila
void  libera (lista* l)
{
   printf("\nFuncao liberar\n");
  lista* ponteiro = l;
  while (ponteiro != NULL)
      {
        lista* t = ponteiro->prox;
        free(ponteiro);
        ponteiro = t;
      }

}

///remove elemento
int removedado(int dado)
{
  lista *ptr, *antes;
  if (inicio==NULL)
  {
      return 0;  // Lista vazia !!!
  }
  else
  {  // Caso a lista nao esteja vazia
      ptr = inicio;
      antes = inicio;
      while (ptr !=NULL)
      {
    if (ptr->ID == dado) // achou !!
    {
      if (ptr == inicio) // se esta removendo o primeiro da lista
      {
        inicio = inicio->prox;
        free(ptr);
        return 1; // removeu !!
      }
      else  // esta removendo do meio da lista
      {
        antes->prox = ptr->prox;  // Refaz o encadeamento
        free(ptr);                // Libera a area do nodo
        return 1;  // removeu !!
      }
    }
    else  // continua procurando no prox. nodo
    {
      antes = ptr;
      ptr = ptr->prox;
    }
      }
      return 0; // Nao achou !!!
  }
}

main()
{
  criaLista();///iniciar a lista
  int op=1;
  
  //-------------
  voltamenu :
  	 system("cls");
  printf("\n---------------------\n|       Menu:       |\n---------------------\n|1_Pesquisa por ID  |\n---------------------\n|2_Pesquisa por Nome|\n---------------------\n|3_Remover          |\n---------------------\n|4_Imprimir         |\n---------------------\n|5_cadastrar        |\n---------------------\n|0_Sair:            |\n---------------------\n|6_salvar            |\n---------------------\n");
  scanf("%d",&op);
  switch (op)
            {
              case 1:
                    {
                      imprimeponterio(pesquisaID());///pesquisa o ID e retorna para funcao o ponterio para imprimir
                      break;
                    }
 
              case 2:
                    {
                      imprimeponterio(pesquisanome());
                      break;
                    }
              case 3:
                {
                   imprime();
                   removedado(pesquisaID()->ID);///a pesquisa retorna um ponteiro para a funcao remover
                   printf("Removido... imprimindo lista \n");
                   imprime();
                   break;
                }            
              case 4:
                    {
                      imprime();
                      break;
                    }
              case 5:
              	  {
              	  	 for(;;) //loop infinito ate condicao de parada 'break'
    {
    cadastro();
    
    printf("Menu cadastro:\n1_Novo\t0_Sair:");
    scanf("%d",&op);
      if(op==0)//caso 0 sair do loop
      {
        break;
      }
    }
    printf(">>Dados cadastrados<<\n");
  imprime();///imprimir os dados cadastrados 
              	  	break;
				  }
              case 0:
                    {
                 libera (inicio);
                      return 0;
                      break;
                    }
            }
  
  
  goto voltamenu; //simplesmente volta ao menu
  return 0;
}
