

#include <stdio.h>
#include <stdlib.h>
 
char *decimal_to_binary(int);
 
int main(int argc, char const *argv[])
{
   int n, c, k;
   char *pointer;
 
   printf("Enter an integer in decimal number system\n");
   scanf("%d",&n);
 
   pointer = decimal_to_binary(n);
   printf("Binary string of %d is: %s\n", n, pointer);
 
   free(pointer);
 
   return 0;
}
 
char *decimal_to_binary(int n)
{
   int c, d, count;
   char *pointer;
 
   count = 0;
   pointer = (char*)malloc(32+1);
 
   if ( pointer == NULL )
      exit(EXIT_FAILURE);
 
   for ( c = 31 ; c >= 0 ; c-- )
   {
      d = n >> c;
 
      if ( d & 1 )
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
 
      count++;
   }
   *(pointer+count) = '\0';
 
   return  pointer;
}

/* Usaremos a própria chave como endereço hash
não há necessidade de transformar as chaves antes de 
fazer a extração dos bits usados para o endereçamento 
No. máx de 6 dígitos é 999999 em decimal que equivale a 
1111 0100 0010 0011 1111 que usa 20 bits */

/*
op_add(KEY){	//FUNÇÃO DE INSERÇÃO
	if (op_find(KEY, FOUND_BUCKET))
		//retornar success
	else
		bk_add_key(FOUND_BUCKET, KEY)
		//retornar failure
}

op_find(KEY, FOUND_BUCKET){	//FUNÇÃO DE BUSCA
	ADDRESS = make_address(KEY, DIR_PROF)
	FOUND_BUCKET = bucket referenciado por DIRETORIO[ADDRESS].BUCKET_REF
	Ler FOUND_BUCKET para a memória e buscar por KEY
	if (chave está em FOUND_BUCKET)
		//retornar success
	else
		//retornar failure
}

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