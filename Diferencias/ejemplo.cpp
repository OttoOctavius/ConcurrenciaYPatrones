#include <malloc.h>

int main(int argc, char const *argv[])
{
	int *var = (int*) malloc(8*sizeof(int));

	for(int contador=0;contador<8;contador++){
		var[contador] = contador;
		printf("%d,",var[contador]);
	}

	free(var);
	return 0;
}