//Date:27/11/2018
//Função Principal
#include "interface.h"
#include "lista_alunos.h"

int main()
{
  char option;
  
  option=interface()
  option=toupper(option);
  
  do
  {
    switch(option)
    {
     case 'C':
       cadastra_aluno(ls_alunos*);
     case 'B':
       busca_aluno(lista);
     case 'L':
       ;
     case 'A':
       ;
     case 'R':
       ;
     case 'F':
       break;
     default:
       printf("Opcão inválida\n"); 
    }
  }while(option != 'F');
  
      
      
      
      
