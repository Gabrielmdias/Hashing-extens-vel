#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_BUCKET 3
 
char *hash(int KEY);
int make_address(int KEY, int PROFUNDIDADE);
int op_add(int KEY);
int op_find(int KEY, int FOUND_BUCKET);

typedef struct BUCKET
{
	int PROFUNDIDADE; // bits usados para endereçar as chaves deste bucket
	int CONTADOR; // número de chaves contidas no bucket
	int	CHAVES[TAM_MAX_BUCKET]; //armazena as chaves
} BUCKET;

typedef struct DIR_CELL
{
	int BUCKET_REF; // armazena o RRN ou outra referência para um BUCKET em disco
} DIR_CELL;

typedef struct DIRETORIO
{
	int PROFUNDIDADE;
	DIR_CELL *celulas;
} DIRETORIO;

/* Usaremos a própria chave como endereço hash
não há necessidade de transformar as chaves antes de 
fazer a extração dos bits usados para o endereçamento 
No. máx de 6 dígitos é 999999 em decimal que equivale a 
1111 0100 0010 0011 1111 que usa 20 bits */
 
int main(int argc, char const *argv[])
{
   int KEY;
   char *pointer;
 
   printf("Enter an integer in decimal number system:\n");
   scanf("%d", &KEY);

   pointer = hash(KEY);
   printf("Binary string of %d is: %s\n", KEY, pointer);

   op_add(KEY);
 
   free(pointer);
 
   return 0;
}
 
char *hash(int KEY)
{
	int c, d, count = 0;
	char pointer[32+1];
 
   	if (pointer == NULL)
    	exit(EXIT_FAILURE);
 
	for (c = 32; c >= 0; c--) {
 		d = KEY >> c; 
      	if (d & 1)
      		*(pointer+count) = 1 + '0';
      	else
      		*(pointer+count) = 0 + '0'; 
      	count++;
   	}
   	*(pointer+count) = '\0';
   	printf("%s\n", pointer);
   	return pointer;
}

int make_address(int KEY, int PROFUNDIDADE)
{
	int RETVAL = 0, LOWBIT,	MASK = 1;
	char *HASHVAL = hash(KEY);
	for (int i = 1; i < PROFUNDIDADE; i++)
	{
		//RETVAL = RETVAL << 1;
		//LOWBIT = HASHVAL bitwise & MASK
		//RETVAL = RETVAL bitwise | LOWBIT;
	}
	return RETVAL;
}

int op_add(int KEY)
{
	int FOUND_BUCKET = 0;
	if (op_find(KEY, FOUND_BUCKET))
		printf("success\n");
	else
		//bk_add_key(FOUND_BUCKET, KEY);
		printf("failure\n");
}

int op_find(int KEY, int FOUND_BUCKET){
	int DIR_PROF = 0;
	int ADDRESS = make_address(KEY, DIR_PROF);

	int FOUND_BUCKET = DIRETORIO[ADDRESS].celulas

	//Ler FOUND_BUCKET para a memória e buscar por KEY
	//if (chave está em FOUND_BUCKET)
		//retornar success
	//else
		//retornar failure
}

/*
bk_add_key(BUCKET, KEY){
	if (BUCKET.CONTADOR < TAM_MAX_BUCKET)
		inserir a chave KEY em BUCKET
	else{
		bk_split(BUCKET)
		op_add(KEY)
	}
}

bk_split(BUCKET){
	if (BUCKET.PROFUNDIDADE == DIR_PROF)
		dir_double()
		Alocar um NOVO_BUCKET e atribuir o seu RRN a END_NOVO_BUCKET
		find_new_range(BUCKET, NEW_START, NEW_END)
		dir_ins_bucket(END_NOVO_BUCKET, NEW_START, NEW_END)
		BUCKET.PROFUNDIDADE++;
		NOVO_BUCKET.PROFUNDIDADE = BUCKET.PROFUNDIDADE
		Redistribuir as chaves entre BUCKET e NOVO_BUCKET
}

dir_double(){
	Calcular o TAM_ATUAL do DIRETORIO e o NOVO_TAM (dobro do atual)
	Alocar memória (NOVO_TAM) para o novo diretório NOVO_DIR
	Transferir os endereços contidos no DIRETORIO atual para NOVO_DIR
		Cada célula do diretório atual é copiada em duas células do NOVO_DIR
		Para I = 0 até TAMANHO_ATUAL-1 faça
			NOVO_DIR[2*I].BUCKET_REF = DIRETORIO[I].BUCKET_REF
			NOVO_DIR[2*I+1].BUCKET_REF = DIRETORIO[I].BUCKET_REF
	Liberar a memória usada por DIRETORIO (diretório antigo)
	Renomear NOVO_DIR para DIRETORIO
	Incrementar DIR_PROF
}

find_new_range(OLD_BUCKET, NEW_START, NEW_END){
	Encontrar o endereço “comum” das chaves contidas em OLD_BUCKET
		SHARED_ADDRESS = make_address(qualquer chave de OLD_BUCKET, OLD_BUCKET.PROFUNDIDADE)
	Fazer um “shift” de SHARED_ADDRESS um bit para esquerda e então	colocar 1 no lugar do bit de mais baixa ordem
		Este é o endereço “comum” das chaves que ficarão no novo bucket a ser inserido no diretório
	NEW_START = SHARED_ADDRESS  preenchido com 0’s à direita até que o endereço tenha o tamanho correto (DIR_PROF)
	NEW_END = SHARED_ADDRESS  preenchido com 1’s à direita até que o endereço tenha o tamanho correto (DIR_PROF)
	Para saber quantos bits precisam ser preenchidos (BITS_TO_FILL)
		BITS_TO_FILL = DIR_PROF –(OLD_BUCKET .PROF + 1)
}

dir_ins_bucket(BUCKET_ADDRESS, START, END){
	Para J = START até END faça
		DIRETORIO[J].BUCKET_REF = BUCKET_ADDRES
}
*/