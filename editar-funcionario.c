//Função para alterar cadastro.
void alterar_cadastro(Lista* primeiro){
     char nome_substituto[100];
     int ID, idade, salario, cargo;
     unsigned long int ID;
     Lista* atual=primeiro;

     //Requisitando e lendo o ID do funcionario a ser alterado.
     printf("  C%ID do funcionario a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&ID);

     //Procurando o funcionario na lista.
     while(atual!= NULL && atual->ID!=ID){
        atual= atual->prox;
     }

     //Alterando os dados do funcionario.
     if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 100, stdin);
        strcpy(atual->nome,nome_substituto);
        printf("\n  Novo ID: ");
        fflush (stdin); fgets(ID_substituto, stdin);
        strcpy(atual->ID,ID_substituto);
        printf("\n  Novo endere%co: ");
        fflush (stdin); fgets(endereco_substituto, stdin);
        strcpy(atual->endereco,endereco_substituto);
        printf("\n  Novo idade: ");
        fflush (stdin); fgets(idade_substituto, stdin);
        strcpy(atual->idade,idade_substituto);
        printf("\n  Novo salario: ");
        fflush (stdin); fgets(salario_substituto, stdin);
        strcpy(atual->salario,salario_substituto);
        printf("\n  Novo cargo: ");
        fflush (stdin); fgets(cargo_substituto, stdin);printf ("\n");
        strcpy(atual->cargo,cargo_substituto);
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  funcionario n%co encontrado.",198);
     }
     printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
