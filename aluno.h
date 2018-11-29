//Data: 26/11/18
//All structs used in work stay here
#define SIZE 50 //Used as width of students names

/* Struct with data of students */
typedef struct aluno_st
{
	char Nome[SIZE];
	unsigned int RA;
	float P1, P2;
	float Trab;
	float PO;
	float media;
} aluno;

/* Struct with no(positions) of list */
typedef struct no_st
{
	aluno* al;
	struct no_st* ant;
	struct no_st* prox;
} no;

/* Struct with head of list */
typedef struct ls_alunos_st
{
	no* cabeca;
} ls_alunos;
