FILE *fp = fopen("CBO.txt", "r");
   char *caractere;
   int linha=1;
while((caractere = fgetc(fp)) != EOF){              //percorre o arquivo caractere por caractere e checa para ver se j� esta no fim do mesmo!
	if(linha==y && caractere!='\n'){                   //se estiver na linha 3 e o caractere for diferente de quebra de linha execulta
		scanf("%s",caractere);                        //printa o caractere em quest�o
	}
	if(caractere=='\n'){     //procura quebra de linha e execulta quando encontrar
		linha++;             //incrementa linha, informando que pulou a linha
	}

}
if(linha<y){
	printf("N�o existe linha no seu arquivo");
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
