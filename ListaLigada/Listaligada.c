#include <stdio.h>
#include <stdlib.h>
#include "Listaligada.h"

struct elemento{
    FUNCIONARIO dados;
    struct elemento *prox;

};

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista*li;
    li=(Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li= NULL;
    }

    return li;
}

void apagaLista(Lista *li){
    if(li != NULL){

        ELEM *no;
        while((*li) != NULL){

            no= *li;
            *li= (*li) ->prox;
            free(no);

        }

        free(li);
    }
}

int tamLista(Lista *li){
    if(li==NULL)

    return 0;


int acum = 0;

ELEM *no = *li;
while (no != NULL){

        acum++;
        no = no -> prox;

    }
return acum;

}

int Listacheia(Lista *li){
    return 0;
}

int ListaVazia(Lista *li){
    if(li==NULL){

        return 1;
    }

    if(*li == NULL){

        return 1;
    }

    return 0;
}


int insere_inicio_lista(Lista *li,FUNCIONARIO func){
    if(li==NULL){

        return 0;
    }

    ELEM *no = (ELEM*) malloc(sizeof(ELEM));

        if(no== NULL){

            return 0;
        }
        no->dados = func;
        no->prox = (*li);
        *li = no;
        return 1;
    }

int insere_final_lista(Lista *li,FUNCIONARIO func){

    if(li==NULL){

        return 0;
    }

    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){

        return 0;
    }

    no->dados = func;
    no->prox = NULL;

    if((*li)==NULL){

            *li=no;

    }else{
            ELEM *aux = *li;
            while(aux->prox != NULL){

                aux = aux->prox;
            }
            aux->prox=no;
    }

    return 1;
}

int insere_ordenada_lista(Lista *li,FUNCIONARIO func){

    if(li==NULL){

        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no==NULL){
            return 0;
    }

        no->dados = func;
        if(ListaVazia(li)){

            no->prox= (*li);
            *li = no;
            return 1;

        }else{
            ELEM *ant, *atual = *li;
            while(atual != NULL && atual -> dados.id < func.id){

                ant = atual;
                atual = atual -> prox;

            }

            if(atual == *li){

                no->prox = (*li);
                *li = no;
            }else{

                no->prox= ant -> prox;
                ant -> prox = no;

            }

                return 1;
        }


}

int remove_inicio_lista(Lista *li){



    ELEM *no = *li;
    *li = no -> prox;
    free(no);
    return 1;
}

int remove_final_lista(Lista *li){
   if(li==NULL){

        return 0;
    }
    if(*li == NULL){

        return 0;
    }

    ELEM *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no -> prox;

    }

    if(no==(*li)){
        *li = no->prox;

    }else{
        ant->prox = no ->prox;

    }

    free(no);

    return 1;

}


int remove_lista(Lista *li,int id){

   if(li==NULL){

        return 0;
    }
    if(*li == NULL){

        return 0;
    }



    ELEM *ant,*no = *li;

    while(no!= NULL&& no->dados.id != id){

        ant = no;
        no = no->prox;
    }

    if(no==NULL){

        return 0;
    }

    if(no== *li){

        *li = no ->prox;
    }else{
        ant -> prox = no -> prox;
    }

    free (no);
    return 1;

}

int consulta_lista_pos(Lista *li, int posicao, FUNCIONARIO *func){
    if(li==NULL || posicao <=0){
            return 0;
    }

    ELEM *no = *li;
    int i = 1;
    while (no!= NULL && i < posicao){

        no= no->prox;
        i++;
    }
    if(no==NULL){

        return 0;
    }else{

        *func = no->dados;
        return 1;

    }


}

int consulta_lista_id(Lista *li, int id, FUNCIONARIO *func){
    if(li==NULL){
            return 0;
    }

    ELEM *no = *li;
        while (no!= NULL && no->dados.id != id){

        no= no->prox;

    }
    if(no==NULL){

        return 0;
    }else{

        *func= no->dados;
        return 1;

    }


}

void menu(Lista *li){
    int y;
    int id,tam,x;
    char escolha;
    int chave=0;
    FUNCIONARIO func;
    FUNCIONARIO* func1;
    func1 = &func;

    system("cls");

    //La�o que ir� mostrar o menu esperando uma op��o (char)
    do {
        //Limpando a tela, e mostrando o menu lembrando que primeiramente, os itens est�o bloqueados at� que seja criada uma lista vazia

        printf( "\n\t\tCadastro de funcionarios\n\n");
        printf( "Escolha uma opcao: \n");
        printf( "1 - Cadastrar funcionario\n");
        if(chave==1){
            printf( "7 - Exibir todos os funcionarios\n");
            printf( "8 - Exibir o tamanho da Lista\n");
            printf( "b - Excluir funcionario\n");
            printf( "c - Buscar funcionario\n");
        }
        printf( "d - Sair\n\n");
        printf( "Resposta: ");
        scanf("%c", &escolha);
        //Se a chave for diferente de zero, por�m a escolha for diferente de 1, 4 e d, a escolha ser� z (op��o inv�lida)
        if((chave==0)&&((escolha!='1')&&(escolha!='d')))
            escolha='z';

        switch(escolha) {

            case '1':
                chave=1;

                printf("Digite o ID: ");
                scanf("%i",&func.id);

                printf("Digite o nome do funcionario: ");
                fgets(func.nome,101,stdin);
                getchar();
                fflush(stdin);

                printf("Digite a idade: ");
                scanf("%i",&func.idade);

                printf("Digite seu salario: ");
                scanf("%i",&func.salario);


                lista_CBO();
                printf("Selecione o cargo desejado: \n\n");
                scanf("%i",&func.cargo);

                x=insere_ordenada_lista(li, func);
                if(x){
                    printf("Inserido com sucesso");
                }else{
                    printf("Erro ao inserir! ");
                }
                break;
            //Exibindo todos elementos
            case '7':
                exibe(li);
                break;
            //Exibindo tamanho da lista
            case '8':
                tam = tamLista(li);
                if(tam){
                    printf("O tamanho da lista �: %i ", tam);
                }else{
                    printf("A lista est� vazia! ");
                }
                break;
            //Deleta elemento buscado
            case 'b':
                printf("Digite o id desejado para a remo��o: ");
                scanf("%i",&id);
                x = consulta_lista_id(li,id,&func);
                if(x){
                    printf("Consulta realizada com sucesso!\n");
                    printf("ID: %i\n",func.id);
                    printf("Nome: %s \n",func.nome);
                    printf("Idade: %i\n",func.idade);
                    printf("Cargo CBO: %i \n",func.cargo);
                    printf("Salario: %i \n",func.salario);


                }
                printf("Tem certeza que deseja remover esse usu�rio? Digite 1 para remove-lo");
                scanf("%i",&y);
                if(y==1){
                x = remove_lista(li,id);
                }else{
                break;
                }
                if(x){
                    printf("Removido com sucesso!");
                }else{
                    printf("Erro!");
                }
                break;
            //Buscando elementos
            case 'c':
                printf("Digite o id desejado para a busca:");
                scanf("%i",&id);
                x = consulta_lista_id(li,id,&func);
                if(x){
                    printf("Consulta realizada com sucesso!\n");
                    printf("ID: %i\n",func.id);
                    printf("Nome: %c \n",func.nome);
                    printf("Idade: %i\n",func.idade);
                    printf("Cargo: %i \n",func.cargo);
                    printf("Salario: %i \n",func.salario);

                }

                break;
            //Saindo e finalizando o programa
            case 'd':
                printf(stderr,"Obrigado por utilizar esse programa!\n");
                printf(stderr,"------>Terminal de Informa��o<------\n\n");

                exit(0);
                break;
            //Se foi algum valor inv�lido
            default:
                printf(stderr,"Digite uma opcao valida (pressione -Enter- para continuar)!\n");
                getchar();
                fflush(stdin);
                break;
        }
        //Impedindo sujeira na grava��o da escolha
        getchar();
    }
    while (escolha > 0); //Loop Infinito
}


void lista_CBO(){
    FILE *f1;

    f1 = fopen("CBO.txt","r");
    if(f1==NULL){
        printf("Erro ao tentar abrir o arquivo!\n");
        system("pause");
        exit(1);
    }
    int i;
    char c[50];


        while(fgets(c,sizeof(c),f1)!=NULL){

                 printf("%s",c);
                    i=c;
                 i++;
        }
        printf("\n");




     fclose(f1);
}

void exibe(Lista *li){

        ELEM *no = *li;



        while(no != NULL){

        printf("\nID:%i",no->dados.id);
        printf("\nNome:%c",no->dados.nome);
        printf("\nIdade:%i",no->dados.idade);
        printf("\nSalario:%i",no->dados.salario);
        printf("\nCargo:%i \n",no->dados.cargo);
        no = no->prox;

        }

}


