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
void busca_aluno(ls_alunos*);
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

void cadastra_aluno(ls_alunos* lista)
{
	aluno* novo_aluno;
	no *novo_no, *p, *q;
	novo_aluno = (aluno*) malloc(sizeof(aluno));

	printf("Insira os dados do aluno(Nome, RA, Nota da P1, da P2, do Trabalho e da PO):\n");
	scanf("%s %s %f %f %f %f", novo_aluno->Nome, novo_aluno->RA, &(novo_aluno->P1), &(novo_aluno->P2),
		&(novo_aluno->Trab), &(novo_aluno->PO));

	novo_no = (no*) malloc(sizeof(no));
	novo_no->al = novo_aluno;

	p = lista->cabeca;
	q = lista->cabeca->prox;
	while(q != NULL && strcmp(q->al->Nome, novo_aluno->Nome) < 0)
	{
		p = q;
		q = q->prox;
	}

	novo_no->ant = p;
	novo_no->prox = q;
	p->prox = novo_no;
	if(q != NULL)
		q->ant = novo_no;
}

void busca_aluno(ls_alunos* lista)
{
	char nome[SIZE];
	no* p;
	p = lista->cabeca->prox;
	int a = 0;

	printf("Insira o nome do aluno a ser buscado:\n");
	scanf("%s", nome);

	for(p = lista->cabeca->prox; p != NULL; p = p->prox)
	{
		if(strstr(p->al->Nome, nome) != NULL)
		{
			a++;
			printf("%s %s \n", p->al->Nome, p->al->RA, p->al->P1);
		}
	}

	printf("%d", a);
}
