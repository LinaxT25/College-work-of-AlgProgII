//Data: 26/11/18
//All functions used in work stay here
#include "aluno.h"
#include "bibliotecas.h"

/* Strucuture of functions */
ls_alunos* cria_lista_alunos()
{
	ls_alunos* lista = (ls_alunos*) malloc(sizeof(ls_alunos));
	lista->cabeca = (no*) malloc(sizeof(no));
	lista->cabeca->ant = NULL;
	lista->cabeca->prox = NULL;
	return lista;
}

void cadastra_aluno(ls_alunos* lista, float media_aluno(float,float,float,float))
{
	aluno* novo_aluno;
	no *novo_no, *p, *q;
	char armazena;
	
	/* Create new space in list for student and fills the data field */
	novo_aluno = (aluno*) malloc(sizeof(aluno));
	printf("Insira os dados do aluno(Nome, RA, Nota da P1, da P2, do Trabalho e da PO):\n");
	for(int i=0; i<SIZE; i++)
	{	
		armazena=getchar();
		if(isdigit(armazena) == 0)
			novo_aluno->Nome[i] = armazena;
		else
		{
			novo_aluno->RA[0] = armazena;
			for(int j=1; j<MAX-1; j++)
			{
				novo_aluno->RA[j] = getchar();
			}
			novo_aluno->RA[13] = '\0';
			break;
		}
	}
	scanf("%f %f %f %f", &(novo_aluno->P1), &(novo_aluno->P2),
		&(novo_aluno->Trab), &(novo_aluno->PO));
	/* Calculate average of test */
		novo_aluno->Media = media_aluno(novo_aluno->P1, novo_aluno->P2, novo_aluno->PO, novo_aluno->Trab);
	/* Setting true or false for situacao */
	if(novo_aluno->Media >= 6.0)
		novo_aluno->situacao = true;
	else
		novo_aluno->situacao = false;
	/* Create a new nó for new student */
	novo_no = (no*) malloc(sizeof(no));
	novo_no->al = novo_aluno;
    /* Founding end of list */
	p = lista->cabeca;
	q = lista->cabeca->prox;
	while(q != NULL && strcmp(q->al->Nome, novo_aluno->Nome) < 0)
	{
		p = q;
		q = q->prox;
	}
    /* Point novo_no's ant and prox to p and q, and make them point back */
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
	int a = 0;

	printf("Insira o nome do aluno a ser buscado:\n");
	scanf("%s", nome);

	for(p = lista->cabeca->prox; p != NULL; p = p->prox)
	{
		if(strstr(p->al->Nome, nome) != NULL)
		{
			a++;
			if(p->al->situacao == true)
				printf("%s%s%.2f Aprovado!\n", p->al->Nome, p->al->RA, p->al->Media);
			else
				printf("%s%s%.2f Reprovado!\n", p->al->Nome, p->al->RA, p->al->Media);
		}
	}

	printf("Total de alunos encontrados: %d\n", a);
}

float media_aluno(float P1, float P2, float PO, float T) 
{
	float media;
	if(PO > P1)
		media = (PO + P2)*0.35 + T*0.3;
	else if(PO > P2)
		media = (P1 + PO)*0.35 + T*0.3;
	else
		media = (P1 + P2)*0.35 + T*0.3;
	
	return media;
}

// Leitura cadastro de alunos através de arquivos
void cadastra_aluno_arquivo(ls_alunos* lista, float media_aluno(float,float,float,float))
{
	// Declaração das variaveis locais
	char nome_arquivo[SIZE];
	FILE *pt;
	int contagem = 0;
	int aux = 0;
	aluno* novo_aluno;
	no *novo_no, *p, *q;
	
	// lendo o nome do arquivo e abrindo
	scanf("%s", nome_arquivo);
	pt = fopen(nome_arquivo, "r");
	
	// se pt!= NULL então o arquivo foi aberto
	if(pt != NULL)
	{	//enquanto o auxiliar do fscanf não der erro
		while(aux != -1)
		{	// alocando espaço para o aluno e lendo as informações do mesmo
			novo_aluno = (aluno*) malloc(sizeof(aluno));
			aux = fscanf(pt, "%s %u %f %f %f %f", novo_aluno->Nome, &(novo_aluno->RA), &(novo_aluno->P1), &(novo_aluno->P2),
				     &(novo_aluno->Trab), &(novo_aluno->PO));
			
			// Calculando a média
			novo_aluno->Media = media_aluno(novo_aluno->P1, novo_aluno->P2, novo_aluno->PO, novo_aluno->Trab);
			
			// Verificando a situação do aluno
			if(novo_aluno->Media >= 6.0)
				novo_aluno->situacao = true;
			else
				novo_aluno->situacao = false;
			
			// criando nó para o estudante
			novo_no = (no*) malloc(sizeof(no));
			novo_no->al = novo_aluno;
			
			// localizando em ordem alfabética onde deve ficar esse aluno 
			p = lista->cabeca;
			q = lista->cabeca->prox;
			while(q->prox != NULL && strcmp(q->al->Nome, novo_aluno->Nome) < 0)
			{
				p = q;
				q = q->prox;
			}
			
			// colocando o aluno dentro da lista
			novo_no->ant = p;
			novo_no->prox = q;
			p->prox = novo_no;
			if(q != NULL)
				q->ant = novo_no;
			
			// garantindo que o contador contará apenas alunos cadastrados corretamente
			if(aux != -1)
				contagem++;
		}
		// fechando o arquivo e printando a quantidade de alunos cadastrados
		fclose(pt);
		printf("%d alunos foram cadastrados!\n", contagem);		
	}
	else	// caso o arquivo não consiga ser aberto
		printf("Falha na abertura do arquivo!\n");
}	


void aprovados(ls_alunos* lista)
{
    FILE *aprovados;
    no *p;
    unsigned int contagem = 0;

    aprovados = fopen("aprovados.txt","w");
    if(aprovados != NULL)
    {
        for(p = lista->cabeca->prox; p!=NULL; p=p->prox)
        {
            if(p->al->situacao == true)
            {
               contagem++;
               fprintf(aprovados, "%s%.2f", p->al->Nome, p->al->Media); 
            }
        }
        fprintf(aprovados, "\nO numero total de aprovados e de: %u", contagem);
        fclose(aprovados);
    }
}

void reprovados(ls_alunos* lista)
{
    FILE *reprovados;
    no *p;
    unsigned int contagem = 0;

    reprovados = fopen("reprovados.txt","w");
    if(reprovados != NULL)
    {
        for(p = lista->cabeca->prox; p!=NULL; p=p->prox)
        {
            if(p->al->situacao == false)
            {
                contagem++;
                fprintf(reprovados, "%s%.2f", p->al->Nome, p->al->Media);
            }
        }
        fprintf(reprovados, "\nO numero total de reprovados e de: %u", contagem);
        fclose(reprovados);
    }
}
