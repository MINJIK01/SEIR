#include <stdio.h>
#include <conio.h>

int numDay = 0;
double allPeople = 51700000;
char answer = 0;

void function(void)
{
	float firstInfected = 0;
	int beta = 0;
	double sigma = 0;
	double gamma = 0;
	
	//사용자 입력부분 
	
	printf("Enter the number of infected people in Day 0: ");
	scanf("%f", &firstInfected);
	allPeople += firstInfected;
	printf("Enter the value of Beta (Transmission Rate): ");
	scanf("%d", &beta);
	printf("Enter the value of Sigma (Incuvation Rate): ");
	scanf("%lf", &sigma);
	printf("Enter the value of Gamma (Recovery Rate): ");
	scanf("%lf", &gamma);
	printf("How many days do you want to run the simulation: ");
	scanf("%d", &numDay);
			
	printf("Day     S               E               I               R           \n===================================================================\n");
			
	//SEIR 출력 부분 
	double S = 51700000;
	double E = 0;
	double I = firstInfected;
	double R = 0;
	int slist[80] = {0};
	int elist[80] = {0};
	int ilist[80] = {0};
	int rlist[80] = {0};
		
	int i = 0;
	double Sremain = 0;
	double Eremain = 0;
	double Iremain = 0;	
	
	for (i;i < numDay+1 ;++i)
	{	
		slist[i] = (int) ((S/allPeople)*100);
		elist[i] = (int) ((E/allPeople)*100);
		ilist[i] = (int) ((I/allPeople)*100);
		rlist[i] = (int) ((R/allPeople)*100);
		
		if (S < 0 )
		S = 0;
		if (E < 0 )
		E = 0;
		if (I < 0 )
		I = 0;				
		
		printf("Day %d:\t%-15lf %-15lf %-15lf %-15lf\n", i, S, E, I, R);

		double StoE = (beta*(S*I/allPeople));
		double EtoI = (sigma*E);
		double ItoG = (gamma*I);
		
		if (S - StoE >= 0 )
		{
			S = S - StoE;
			E = E + StoE - EtoI;
			I = I + EtoI - ItoG;
			R = R + ItoG;
		}
		else if(E - EtoI >= 0)
		{
			E = E + S - EtoI;
			S = 0;
			I = I + EtoI - ItoG;
			R = R + ItoG;						
		}
		else if(I - ItoG >= 0)
		{
			I = I + Eremain - ItoG;
			R = R + ItoG;			
		}
		else
		{
			R = R + Iremain;			
		}
		
	}
	puts("");
		
	//그래프 프린트여부 확인 
	char chosen = 0;
		
	printf("Do you want to plot the result [y/n]? ");
	scanf("%s", &answer);
	
					
	while (answer != 'n')
	{
		switch (answer) {
			case 'y':
				
				printf("Which data would you like to plot? [s/e/i/r]");
				scanf("%s", &chosen);
				int j = 0;
			
				if (chosen == 's')
				{
					for (j; j < numDay+1; ++j)
					{	
						int k = 1;
						printf("Day %d\t(%2d%%)   | ", j, slist[j]);
						for(k;k <= slist[j];++k)
						{
							printf("%c", '*');
						}
						
						puts("");
					}
					puts("");
				}
				else if (chosen == 'e')
				{
						for (j; j < numDay+1; ++j)
					{	
						int k = 1;
						printf("Day %d\t(%2d%%)   | ", j, elist[j]);
						for(k;k <= elist[j];++k)
						{
							printf("%c", '*');
						}
						
						puts("");
					}
					puts("");
				}
				else if (chosen == 'i')
				{
					for (j; j < numDay+1; ++j)
					{
						int k = 1;
						printf("Day %d\t(%2d%%)   | ", j, ilist[j]);
						for(k;k <= ilist[j];++k)
						{
							printf("%c", '*');
						}
						
						puts("");
					}
					puts("");
				}			
				else if (chosen =='r')
				{
					for (j; j < numDay+1; ++j)
					{
						int k = 1;
						printf("Day %d\t(%2d%%)   | ", j, rlist[j]);
						for(k;k <= rlist[j];++k)
						{
							printf("%c", '*');
						}
						
						puts("");
					}
					puts("");
				}
				else
				{
					printf("Input Error! Please enter [y/n]\n");				
				}
				
				printf("Do you want to plot the result [y/n]?");
				scanf("%s", &answer);
				break;
				
			default:
				printf("Input Error! Please enter [y/n]\n");
				printf("Do you want to plot the result [y/n]? ");
				scanf("%s", &answer);
				break;
		}
		
	}
}

	
int main(void)
{
	function();
	
	char simulAnswer = 0;
	printf("Do you want to run the simulation again? [y/n]? ");
	scanf("%s", &simulAnswer);
		
	while (simulAnswer != 'n')
	{
		switch (simulAnswer)
		{
			case 'y':
				function();
				printf("Do you want to run the simulation again? [y/n]? ");
				scanf("%s", &simulAnswer);
				break;
			
			default:
				printf("Input Error! Please enter [y/n]\n");
				printf("Do you want to run the simulation again? [y/n]? ");
				scanf("%s", &simulAnswer);
				break;
		}
	}
	
	return 0;
}
