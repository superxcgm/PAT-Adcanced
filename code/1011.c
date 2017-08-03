#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double result = 1.0;

void bet()
{
	double a, b, c;

	scanf("%lf %lf %lf", &a, &b, &c);
	if(a > b && a > c){
		result *= a;
		printf("W ");
	}
	if(b > a && b > c){
		result *= b;
		printf("T ");
	}
	if(c > a && c > b){
		result *= c;
		printf("L ");
	}
}

int main(void)
{
	bet();
	bet();
	bet();
	printf("%.2lf", (result*0.65 - 1) * 2);

	return 0;
}