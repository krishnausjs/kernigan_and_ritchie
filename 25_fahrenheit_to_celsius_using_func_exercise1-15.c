#include <stdio.h>

int fah_to_cel(int fahr,int upper,int step)
{
	float celsius = 0;

	while(fahr <= upper)
	{
		celsius = 5.0 * (fahr - 32) / 9.0;
		printf("%10.2f\t %3.2f\n",fahr,celsius);
		fahr = fahr + step;
	}
	return 0;
}

int main()
{
	float fahr;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step  = 20;
	
	fahr = lower;
    printf("Fahrienheit\tCelicus\n");
    printf("=======================\n");
	
	fah_to_cel(fahr,upper,step);
	return 0;
}
