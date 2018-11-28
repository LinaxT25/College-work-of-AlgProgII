//Data: 26/11/18
//Definição da lista e prototipação de funções
#include <no.h>
#include <bibliotecas.h>

typedef struct ls_alunos_st
{
	no* cabeca;
} ls_alunos;

//Prototipação
ls_alunos* cria_lista_alunos();
void cadastra_aluno(ls_alunos*);
no* busca_aluno(ls_alunos*);
void cadastra_com_arquivo(ls_alunos*);
void aprovados(ls_alunos*);
void reprovados(ls_alunos*);

//Estrutura das funções
ls_alunos* cria_lista_alunos()
{
	ls_alunos* lista = (ls_alunos*) malloc(sizeof(ls_alunos));
	lista->cabeca = (no*) malloc(sizeof(no));
	lista->cabeca->ant = NULL;
	lista->cabeça->prox = NULL;
	return lista;
}
