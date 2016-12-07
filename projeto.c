#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 //Se o sistema for Windows adiciona determinada biblioteca, e definindo comandos de limpar e esperar
#ifdef WIN32
    #include <windows.h>
    #define LIMPA_TELA system("cls")
#endif

//Máximo de bytes para uma String
#define BUFFER 64


//Estrutura da lista que será criada
typedef struct lista {
    char *nome;
    int ID;
    int idade;
    int salario;
    int cargo;
    struct lista *proximo;
} Dados;

//Funções para manusear os dados (irão retornar dados)
Dados *inicia_dados  (char *nome,int ID, int idade, int salario, int cargo);
Dados *insere_dados  (Dados *dados, char *nome,int ID, int idade, int salario, int cargo);
Dados *delbusca_dados(Dados *dados, char *chave);
Dados *deleta_dados  (Dados *dados, int nTipo);
int   checa_vazio    (Dados *dados);

//Funções para mostrar dados
void  exibe_dados    (Dados *dados);
void  exibe_tamanho  (Dados *nova);
void  busca_dados    (Dados *dados, char *chave);

//Funções do Menu
void criavazia(void);    //1
void exibe(void);        //7
void exibetam(void);     //8
void delbusca(void);     //b
void busca(void);        //c

//Inicializando os dados da lista
Dados *principal = NULL;

//---------------------------------
//     Opção '1'
//---------------------------------

//Criando uma lista vazia (cadastro)
void criavazia(void){
    char *nome;
    int ID;
    int idade;
    int salario;
    int cargo;
    //Alocando dados para uma String
    nome = (char *)malloc(BUFFER);
    //Lendo String Nome
    fprintf(stdout, "\n\nDigite o Nome: \n----> ");
    scanf("%s", nome);
    fprintf(stdout, "\n");
    //Lendo int ID
    fprintf(stdout, "Digite o ID: \n----> ");
    scanf("%d", &ID);
    fprintf(stdout, "\n");
    //Lendo int Idade
    fprintf(stdout, "Digite a Idade: \n----> ");
    scanf("%d", &idade);
    fprintf(stdout, "\n");
    //Lendo int salario
    fprintf(stdout, "Digite o salario: \n----> ");
    scanf("%d", &salario);
    fprintf(stdout, "\n");
    //Lendo int cargo
    fprintf(stdout, "Digite o cargo: \n----> ");
    scanf("%d", &cargo);
    fprintf(stdout, "\n");
    //Lançando os dados lidos na lista Principal
    free(principal);
    principal = inicia_dados(nome, ID, idade, salario, cargo);
}

//Iniciando os dados da lista vazia
Dados *inicia_dados(char *nome,int ID, int idade, int salario, int cargo) {
    Dados *novo;
    //Alocando memória para a posição atual da lista
    novo = (Dados *)malloc(sizeof(Dados));
    //Lançando os dados lidos
    novo->nome = (char *)malloc(strlen(nome)+1);
    strncpy(novo->nome, nome, strlen(nome)+1);
    novo->ID = ID;
    novo->idade = idade;
    novo->salario = salario;
    novo->cargo = cargo;
    //Apontando para a próxima posição da lista
    novo->proximo = NULL;
    return novo;
}

//---------------------------------
//     Opção '7'
//---------------------------------

//Exibindo dados da lista
void exibe(void) {
    //Se não estiver vazio, exibe os dados
    if (!checa_vazio(principal))
        exibe_dados(principal);
}

//Exibindo todos os dados do menu
void exibe_dados(Dados *dados) {
    fprintf(stdout, "Cadastro:\n\n");
    fprintf(stdout, "------------------------\n");
    //Exibindo todos os valores da lista
    for (; dados != NULL; dados = dados->proximo) {
        fprintf(stdout, "Nome: %s\n", dados->nome);
        fprintf(stdout, "ID: %d\n", dados->ID);
        fprintf(stdout, "Idade: %d\n", dados->idade);
        fprintf(stdout, "Salario: %d\n", dados->salario);
        fprintf(stdout, "Cargo: %d\n", dados->cargo);
        fprintf(stdout, "------------------------\n");
    }
    getchar();
}

//---------------------------------
//     Opção '8'
//---------------------------------

//Exibindo o tamanho da lista
void exibetam(void){
    //Se não estiver vazio, exibe os dados
    if (!checa_vazio(principal))
        exibe_tamanho(principal);
}

//Exibindo o tamanho total (bytes) e quantidade
void exibe_tamanho(Dados *nova){
  int aux=0, tamanho=0;
  fprintf(stdout, "\n------------------------\n");
  //Correndo todos os valores da Lista
  for (; nova != NULL; nova = nova->proximo) {
    aux++;
    tamanho+=sizeof(nova);
  }
  fprintf(stdout, "Total de Elementos: %d\nTamanho Total: %d bytes\n",aux,tamanho);
  fprintf(stdout, "------------------------\n");
  getchar();
}

//---------------------------------
//     Opção 'b'
//---------------------------------

//Deletando valor buscado
void delbusca(void) {
    char *chave;
    //Se não estiver vazio
    if (!checa_vazio(principal)) {
        chave = (char *)malloc(BUFFER);
        //Armazenando o valor digitado
        fprintf(stdout, "Digite o nome para buscar: \n--> ");
        scanf("%s", chave);
        //Deletando a chave buscada
        principal = delbusca_dados(principal, chave);
    }
}

//Deletando os valores buscados
Dados *delbusca_dados(Dados *dados, char *chave) {
    int achou=0,cont=0;
    Dados *juntou, *aux, *nova=dados;

    //Correndo a lista e verificando se encontrou a string buscada, se sim, aumenta o contador e seta a variável de busca
    for (; nova != NULL; nova = nova->proximo) {
        if (strcmp(chave, nova->nome) == 0) {
            achou=1;
            cont++;
        }
    }

    //Se encontrou a busca
    if(achou==1){
        int ind=0;
        //Correndo a lista
        for(ind=0;ind<cont;ind++){
            //Se encontrou na primeira casa apaga a primeira casa
            if(strcmp(chave,dados->nome)==0){
                aux=dados;
                dados=dados->proximo;
                free(aux);
            }
            //Senão, procura até encontrar
            else{
                aux=dados;
                //Posiciona na frente do encontro para exclusão
                while(strcmp(chave,aux->nome)!=0){
                    aux=aux->proximo;
                }

                juntou=dados;
                //Enquanto o auxiliar juntou for diferente do posicionado para exclusão
                while(juntou->proximo!=aux){
                    juntou=juntou->proximo;
                }
                //Aponta para o próximo valor válido
                juntou->proximo=aux->proximo;

                free(aux);
            }
        }
        fprintf(stdout, "Excluido.\n");
    }
    else
        fprintf(stdout, "Nenhum resultado encontrado.\n");

    getchar();
    return dados;
}

//---------------------------------
//     Opção 'c'
//---------------------------------

//Função que busca os dados
void busca(void) {
    char *chave;
    //Senão estiver vazio a lista
    if (!checa_vazio(principal)) {
        chave = (char *)malloc(BUFFER);
        //Lendo o nome que será buscado
        fprintf(stdout, "Digite o nome para buscar: \n--> ");
        scanf("%s", chave);
        //chamando a função que irá procurar o nome
        busca_dados(principal, chave);
    }
}

//Percorre cada ponta da lista verificando busca
void busca_dados(Dados *dados, char *chave) {
    int achou = 0;
    fprintf(stdout, "Cadastro:\n\n");
    //Percorrendo todas as posições
    for (; dados != NULL; dados = dados->proximo) {
        //Se encontrou, mostra os dados
        if (strcmp(chave, dados->nome) == 0) {
            fprintf(stdout, "------------------------\n");
            fprintf(stdout, "Nome: %s\n", dados->nome);
            fprintf(stdout, "ID: %d\n", dados->ID);
            fprintf(stdout, "Idade: %d\n", dados->idade);
            fprintf(stdout, "Salario: %d\n", dados->salario);
            fprintf(stdout, "Cargo: %d\n", dados->cargo);
            fprintf(stdout, "------------------------\n");
            achou++;
        }
    }

    //Mostrando o resultado da busca
    if (achou == 0)
        fprintf(stdout, "Nenhum resultado encontrado.\n");
    else
        fprintf(stdout, "Foram encontrado(s) %d registro(s).\n", achou);

    getchar();
}

//---------------------------------
//     Função Auxiliar
//---------------------------------

//Função que testa se a lista esta vazia
int checa_vazio(Dados *dados) {
    //Se a lista estiver vazia
    if (dados == NULL) {
            fprintf(stdout, "Lista vazia!\n");
            getchar();
            return 1;
    } else
            return 0;
}

//---------------------------------
//     Função Principal
//---------------------------------

int main(void) {
    char escolha;
    int chave=0;
    //Laço que irá mostrar o menu esperando uma opção (char)
    do {
        //Limpando a tela, e mostrando o menu lembrando que primeiramente, os itens estão bloqueados até que seja criada uma lista vazia
        LIMPA_TELA;
        fprintf(stdout, "\n\t\tCadastro de funcionarios\n\n");
        fprintf(stdout, "Escolha uma opcao: \n");
        fprintf(stdout, "1 - Cadastrar funcionario\n");
        if(chave==1){
            fprintf(stdout, "7 - Exibir todos os funcionarios\n");
            fprintf(stdout, "8 - Exibir o tamanho da Lista\n");
            fprintf(stdout, "b - Excluir funcionario\n");
            fprintf(stdout, "c - Buscar funcionario\n");
        }
        fprintf(stdout, "d - Sair\n\n");
        fprintf(stdout, "Resposta: ");
        scanf("%c", &escolha);
        //Se a chave for diferente de zero, porém a escolha for diferente de 1, 4 e d, a escolha será z (opção inválida)
        if((chave==0)&&((escolha!='1')&&(escolha!='d')))
            escolha='z';

        switch(escolha) {
            //Criando lista vazia
            case '1':
                chave=1;
                criavazia();
                break;
            //Exibindo todos elementos
            case '7':
                exibe();
                break;
            //Exibindo tamanho da lista
            case '8':
                exibetam();
                break;
            //Deleta elemento buscado
            case 'b':
                delbusca();
                break;
            //Buscando elementos
            case 'c':
                busca();
                break;
            //Saindo e finalizando o programa
            case 'd':
                fprintf(stderr,"Obrigado por utilizar esse programa!\n");
                fprintf(stderr,"------>Terminal de Informação<------\n\n");

                exit(0);
                break;
            //Se foi algum valor inválido
            default:
                fprintf(stderr,"Digite uma opcao valida (pressione -Enter- para continuar)!\n");
                getchar();
                break;
        }
        //Impedindo sujeira na gravação da escolha
        getchar();
    }
    while (escolha > 0); //Loop Infinito
    return 0;
}
