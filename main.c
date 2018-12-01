//Date:27/11/2018
//Main Function
#include "interface.h"
#include "lista_alunos.h"

int main()
{
  char option;
  ls_alunos *lista;
  
  lista = cria_lista_alunos();
  option = interface();
  option = toupper(option);
  
   do
  {
    switch(option)
    {
     case 'C':
       cadastra_aluno(lista, media_aluno);
       break;
     case 'B':
       busca_aluno(lista);
       break;
     case 'L':
       cadastra_aluno_arquivo(lista, media_aluno);
       break;
     case 'A':
       aprovados(lista);
       break;
     case 'R':
       reprovados(lista);
       break;
     case 'F':
       return 0;
     default:
       printf("Opcão inválida\n"); 
    }
   printf("\nPor favor digite o que deseja fazer a seguir:\n");
   getchar();
   option=getchar();
   option = toupper(option);
  } while (option != 'F');
}
  
      
      
      
      
