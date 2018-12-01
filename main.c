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
       cadastra_aluno(lista);
     case 'B':
       busca_aluno(lista);
     case 'L':
       cadastra_aluno_arquivo(lista);
     case 'A':
       aprovados(lista);
     case 'R':
       reprovados(lista);
     case 'F':
       break;
     default:
       printf("Opcão inválida\n"); 
    }
  } while(option != 'F');
  
  return 0;
}
  
      
      
      
      
