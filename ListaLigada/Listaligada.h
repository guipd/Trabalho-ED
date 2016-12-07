typedef struct funcionario{
    int id;
    char nome[100];
    int idade;
    int salario;
    int cargo;
}FUNCIONARIO;

typedef struct elemento* Lista;


Lista *criaLista();

int tamLista(Lista*li);

int Listacheia(Lista*li);

int ListaVazia(Lista *li);

int insere_inicio_lista(Lista *li,FUNCIONARIO func);

int insere_final_lista(Lista *li,FUNCIONARIO func);

int insere_ordenada_lista(Lista *li,FUNCIONARIO func);

int consulta_lista_pos(Lista *li, int posicao, FUNCIONARIO *func);

int remove_inicio_lista(Lista *li);

int remove_final_lista(Lista *li);

int remove_lista(Lista *li,int id);

int consulta_lista_pos(Lista *li, int posicao, FUNCIONARIO*func);

int consulta_lista_id(Lista *li, int id, FUNCIONARIO*func);

void apagaLista(Lista *li);

void menu(Lista *li);

void exibe(Lista *li);




