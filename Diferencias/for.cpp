#include <stdio.h>


int main(int argc, char const *argv[]){
	int variable[] = new int[8];

	for(int contador=0;contador<8;contador++)
		cout << "Ciclo\t " << contador << endl;

	free(variable);

	return 0;
}
