//Data: 26/11/18
//All structs used in work stay here
#define SIZE 50 //Used as width of students names
#define MAX  14  //Used as widht of RA

/* Struct with data of students */
typedef struct aluno_st
{
	char Nome[SIZE];
	char RA[MAX];
	float P1, P2;
	float Trab;
	float PO;
	float Media;
	bool situacao;
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
