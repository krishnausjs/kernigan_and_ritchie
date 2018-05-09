#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step  = 20;
	
	celsius = lower;
    printf("Fahrienheit\tCelicus\n");
    printf("=======================\n");
	while(celsius <= upper)
	{
		fahr = (((9.0/5.0) * celsius)+32);
		printf("%10.2f\t %3.2f\n",fahr,celsius);
		celsius = celsius + step;
	}
}
