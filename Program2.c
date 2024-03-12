/*
Author: <Mark Daoud>
Date: <11/29/23>
Purpose: <The purpose of this program is to calculate the population growth of the green crud population based on the initial amount there is 
and the number of days that the population is growing entered by the user based oon the fact that after the initial 5 days every 5 days after 
that the population is equal to the previous two population numbers added up>
Time Spent: <45 minutes>
*/



#include <stdio.h>
#include <ctype.h>

//Pre Condition: None
//Post Condition: The keyboard buffer has been cleared 
void clear_keyboard_buffer(void);

//Pre Condition: None
//Post Condition: User has entered the values for pounds and days and those values have been stored in the adresses of pounds and days
void Get_input(int* ppounds, int* pdays);

//Pre Condition: User has entered the values for pounds and days and those values have been stored in the addresses of pounds and days
//Post Condition: The value for tpounds has been calculated and stored in the address of tpounds
void Calculate_tpounds(int* ppounds, int* pdays, int* ptpounds); 

int main(int argc, char* argv[])
{
	int pounds; 
	int days;
	int tpounds;
	char answer;
	do
	{
		Get_input(&pounds, &days);
		Calculate_tpounds(&pounds, &days, &tpounds);
		printf("With an initial population of %d pounds of crud growing for %d days,\n", pounds,days);
		printf("the final population would be %d pounds\n", tpounds);
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

void Get_input(int* ppounds, int* pdays)
{
	int noc = 0;
	do
	{
		printf("Please enter the initial size of the green curd: ");
		noc= scanf("%d", ppounds);
		clear_keyboard_buffer();
		if (noc != 1 || *ppounds < 0 )
		{
			printf("I'm sorry that value is negative or unrecognized\n"); 
		}
	} while (noc != 1 || *ppounds < 0);
	do
	{
		printf("Please enter the number of days: ");
		noc = scanf("%d", pdays);
		clear_keyboard_buffer(); 
		if (noc != 1 || *pdays < 0) 
		{ 
			printf("I'm sorry that value is negative or unrecognized\n");
		} 
	} while (noc != 1 || *pdays < 0); 

}
void Calculate_tpounds(int* ppounds, int* pdays, int* ptpounds)
{
	int i;
	int current;
	int previous;
	int temp;
	if (*pdays == 0)
	{
		*ptpounds = *ppounds;
	}
	else
	{
		current = *ppounds;
		previous = 0;
		for (i = 1; i <= *pdays; ++i)
		{
			if (i % 5 == 0)    
			{
				temp = current; 
				current += previous; 
				previous = temp; 
			}
		}
		*ptpounds = current;  
	}
}