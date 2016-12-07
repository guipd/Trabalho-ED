#include <stdio.h>
#include <stdlib.h>
#include "Listaligada.h"


int main()
{
  Lista *li;
  li = criaLista();
  menu(li);
  apagaLista(li);

    return 0;
}




