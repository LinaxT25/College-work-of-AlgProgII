//Date:27/11/2018
//Função Principal
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
       ;
     case 'A':
       aprovados(lista);
     case 'R':
       reprovados(lista);
     case 'F':
       break;
     default:
       printf("Opcão inválida\n"); 
    }
  }while(option != 'F');
  
      
      
      
      
