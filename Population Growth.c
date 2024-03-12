/*
Author: <Mark Daoud>
Date: <11/29/23>
Purpose: <The purpose of this program is to calculate the population growth of the  population based on the initial size of it
, the time it takes to double, and the number of days that the population is growing entered by the user based on the fact that after the initial X days every X days after 
that the population is equal to the previous two population numbers added up>
Time Spent: <45 minutes>
*/



#include <stdio.h>
#include <ctype.h>

//Pre Condition: None
//Post Condition: The keyboard buffer has been cleared 
void clear_keyboard_buffer(void);

//Pre Condition: None
//Post Condition: User has entered the values for size, growth and days and those values have been stored in the adresses of size, growth, and days
void Get_input(int* psize, int* pgrowth, int* pdays); 

//Pre Condition: User has entered the values for size, growth, and days and those values have been stored in the addresses of size, and days
//Post Condition: The value for ptsize has been calculated and stored in the address of tsize
void Calculate_tsize(int* psize, int* pgrowth, int* pdays, int* ptsize); 

int main(int argc, char* argv[])
{
	int size; 
	int days;
	int tsize;
	int growth;
	char answer;
	do
	{
		Get_input(&size, &growth, &days); 
		Calculate_tsize(&size, &growth, &days, &tsize); 
		printf("With an initial population of %d with a growth rate of every %d days growing for %d days,\n", size, growth, days);
		printf("the final population would be %d \n", tsize);
		do {
			printf("Would you like to continue? (y/n): "); 
			scanf("%c", &answer);   
			clear_keyboard_buffer(); 
			answer = toupper(answer); 

			if (answer != 'Y' && answer != 'N') 
			{
				printf("I'm sorry, that answer is not recognized\n"); 
			}  

		} while (answer != 'Y' && answer != 'N'); 

	} while (answer == 'Y');


	return 0;
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}

}

void Get_input(int* psize, int* pgrowth, int* pdays)
{
	int noc = 0;
	do
	{
		printf("Please enter the initial size of the population: ");
		noc= scanf("%d", psize);
		clear_keyboard_buffer();
		if (noc != 1 || *psize < 0 )
		{
			printf("I'm sorry that value is negative or unrecognized\n"); 
		}
	} while (noc != 1 || *psize < 0); 
	do
	{
		printf("Please enter the amount of time in days it takes for the population to grow: ");
		noc = scanf("%d", pgrowth);  
		clear_keyboard_buffer();
		if (noc != 1 || *pgrowth < 0) 
		{
			printf("I'm sorry that value is negative or unrecognized\n");
		}
	} while (noc != 1 || *pgrowth < 0);
	do
	{
		printf("Please enter the number of days the population will grow: ");
		noc = scanf("%d", pdays);
		clear_keyboard_buffer(); 
		if (noc != 1 || *pdays < 0) 
		{ 
			printf("I'm sorry that value is negative or unrecognized\n");
		} 
	} while (noc != 1 || *pdays < 0); 

}
void Calculate_tsize(int* psize, int* pgrowth, int* pdays, int* ptsize) 
{
	int i;
	int current;
	int previous;
	int temp;
	if (*pdays == 0)
	{
		*ptsize = *psize;
	}
	else
	{
		current = *psize;
		previous = 0;
		for (i = 1; i <= *pdays; ++i)
		{
			if (i % *pgrowth == 0)     
			{
				temp = current; 
				current += previous; 
				previous = temp; 
			}
		}
		*ptsize = current;  
	}
}
