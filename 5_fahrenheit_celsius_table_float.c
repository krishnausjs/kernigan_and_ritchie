#include <stdio.h>

int main()
{
	float fahr=0;
    printf("Fahrienheit\tCelicus\n");
    printf("=======================\n");	
	for(fahr=0; fahr <= 300; fahr=fahr+20)
		printf("%10.2f\t%6.2f\n",fahr,((5.0/9.0)*(fahr-32)));
	return 0;
}
