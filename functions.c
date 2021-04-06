/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)David Zhu				   dzhu34@myseneca.ca
   2)Raj Jaydeepsinh Kiransinh jkraj@myseneca.ca
   3)Sawan Harshadkumar Patel  shpatel18@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "file_helper.h"
#include "functions.h"

#define SIZE 2000

//Function 1: clear buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

//Function 2: get an integer
int getInt(void)
{
	int value = 0;
	char NL = 'x';

	while (NL != '\n')
	{
		scanf("%d%c", &value, &NL);

		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return value;
}

//Function 3: get an integer in a range
int getIntInRange(int min, int max)
{
	int value = 0;
	do
	{
		value = getInt();

	} while ((value < min || value > max) && printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max));

	return value;
}

//Function 4: display menu
int menu(void)
{
	int value = 0;
	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Print top 3 skiers in a category\n");
	printf("2 - Print all skiers in a category\n");
	printf("3 - Print last 3 skiers in a category\n");
	printf("4 - Print winners in all categories\n");
	printf(": ");

	value = getIntInRange(0, 4);

	printf("\n");
	
	return value;
}

//Function 5: main ski reporting system function
void skiReportingSystem(void)
{
	int selection = 0, flag = 0, size = 0;
	struct SkierInfo nm[SIZE] = { 0 };

	size = getData(nm);

	do
	{
		selection = menu();
		switch (selection)
		{
		case 1:
			topThree(nm, size);
			break;

		case 2:
			all(nm, size);
			break;

		case 3:
			lastThree(nm, size);
			break;

		case 4:
			winner(nm, size);
			break;

		case 0:
			printf("Keep on Skiing!\n");
			flag = 1;
			break;
		}
	} while ((selection != 0 || flag == 0) && printf("\n"));
}

//Function 6: store data from text file to a struct
int getData(struct SkierInfo* info)
{
	int i = 0;
	FILE* fp = NULL;

	fp = fopen("data.txt", "r");

	while (i < SIZE && !feof(fp))
	{
		readFileRecord(fp, &info[i]);
		i++;
	}

	return i;	//return how many lines in the text file to avoid unnecessary looping
}

//Function 7: return 1,2 or 3 for S(s), M(m), or L(l), validate input. 
int sml(void)
{
	int value = 0;
	char sml = 'x', nl = 'x';
	
	printf("Which category (S, M, L): ");
	scanf("%c%c", &sml, &nl);

	while ((sml != 'S' && sml != 's' && sml != 'M' && sml != 'm' && sml != 'L' && sml != 'l') || nl != '\n')
	{
		if (nl != '\n')
		{
			clearKeyboard();
		}
		printf("*** INVALID ENTRY *** <Only S M or L are acceptable>: ");
		scanf("%c%c", &sml, &nl);
	}
	
	if (sml == 'S' || sml == 's')
	{
		value = 1;
	}
	else if (sml == 'M' || sml == 'm')
	{
		value = 2;
	}
	else if (sml == 'L' || sml == 'l')
	{
		value = 3;
	}

	printf("\n");
	return value;
}

//Function 8: convert finish time and start time to totol time in the correct format
void timeConversion(double startTime, double finishTime)
{
	int hour = 0, minute = 0;
	hour = finishTime - startTime;
	minute = (finishTime - startTime - hour) * 60 + 0.5;
	if (minute < 10)
	{
		printf("%d:0%d", hour, minute);
	}
	else
	{
		printf("%d:%d", hour, minute);
	}
}

//Function 9: sort skier info by time 
void sortSkier(struct SkierInfo info[], int size)
{
	int i = 0, j = 0, counter = 0;
	struct SkierInfo temp = { {{0}} };

	//Count how many withdrawns
	for (i = 0; i < size; i++)
	{
		if (info[i].withdrawn == 1)
		{
			counter++;
		}
	}

	//Sort withdraw to the end of data array
	for (i = size - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (info[j].withdrawn == 1)
			{
				temp = info[j];
				info[j] = info[j + 1];
				info[j + 1] = temp;
			}
		}
	}

	//sort the rest by time
	for (i = size - counter - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if ((info[j].finishTime - info[j].startTime) > (info[j + 1].finishTime - info[j + 1].startTime))
			{
				temp=info[j];
				info[j]=info[j+1];
				info[j + 1] = temp;
			}
		}
	}
}

//Function 10: grouping age and print corresponding age group in correct text
void ageGroup(int age)
{
	if (age >= 16 && age <= 20)
	{
		printf("Junior");
	}
	else if (age >= 21 && age <= 34)
	{
		printf(" Adult");
	}
	else if (age >= 35)
	{
		printf("Senior");
	}
	else
	{
		printf("Stop!!");
	}
	return;
}

//Function 11: display top three skier in a category
void topThree(struct SkierInfo info[], int size)
{
	int selection = 0, i = 0, age = 0, counter = 0;
	
	sortSkier(info, size);
	selection = sml();
	printf("Skier                    Age Group Time\n");
	printf("---------------------------------------\n");

	if (selection == 1)
	{
		for (i = 0; i < size; i++)
		{
			if ((info[i].raceLength == 'S' || info[i].raceLength == 's') && info[i].withdrawn == 0 && counter < 3)
			{
				printf("%-28s", info[i].name);
				ageGroup(info[i].age);
				printf(" ");
				timeConversion(info[i].startTime, info[i].finishTime);
				printf("\n");
				counter++;
			}
		}
		if (counter == 0)
		{
			printf("Not Awarded\n");
		}
	}

	else if (selection == 2)
	{
		for (i = 0; i < size; i++)
		{
			if ((info[i].raceLength == 'M' || info[i].raceLength == 'm') && info[i].withdrawn == 0 && counter < 3)
			{
				printf("%-28s", info[i].name);
				ageGroup(info[i].age);
				printf(" ");
				timeConversion(info[i].startTime, info[i].finishTime);
				printf("\n");
				counter++;
			}
		}
		if (counter == 0)
		{
			printf("Not Awarded\n");
		}
	}

	else if (selection == 3)
	{
		for (i = 0; i < size; i++)
		{
			if ((info[i].raceLength == 'L' || info[i].raceLength == 'l') && info[i].withdrawn == 0 && counter < 3)
			{
				printf("%-28s", info[i].name);
				ageGroup(info[i].age);
				printf(" ");
				timeConversion(info[i].startTime, info[i].finishTime);
				printf("\n");
				counter++;
			}
		}
		if (counter == 0)
		{
			printf("Not Awarded\n");
		}
	}
}

//Function 12: display all skier in a distance category
void all(struct SkierInfo info[], int size)
{
	int selection = 0, i = 0, age = 0, counter = 0;

	sortSkier(info, size);
	selection = sml();
	sortSkier(info, size);	//sort skier by time
	printf("Skier                    Age Group Time Withdrew\n");
	printf("------------------------------------------------\n");

	switch (selection)	
	{
		case 1:
			for (i = 0; i < size; i++)
			{
				if (info[i].raceLength == 'S' || info[i].raceLength == 's')
				{
					if (info[i].withdrawn)
					{
						printf("%-28s", info[i].name);
						ageGroup(info[i].age);
						printf("  N/A      Yes\n");
					}
					else
					{
						printf("%-28s", info[i].name);
						ageGroup(info[i].age);
						printf(" ");
						timeConversion(info[i].startTime, info[i].finishTime);
						printf("       No\n");
					}
					counter++;
				}
			}
			if (counter == 0)
			{
				printf("Not Awarded\n");
			}
			break;

		case 2:
			for (i = 0; i < size; i++)
			{
				if (info[i].raceLength == 'M' || info[i].raceLength == 'm')
				{
					if (info[i].withdrawn)
					{
						printf("%-28s", info[i].name);
						ageGroup(info[i].age);
						printf(" N/A       Yes\n");
					}
					else
					{
						printf("%-28s", info[i].name);
						ageGroup(info[i].age);
						printf(" ");
						timeConversion(info[i].startTime, info[i].finishTime);
						printf("       No\n");
					}
					counter++;
				}
			}
			if (counter == 0)
			{
				printf("Not Awarded\n");
			}
			break;

		case 3:
			for (i = 0; i < size; i++)
			{
				if (info[i].raceLength == 'l' || info[i].raceLength == 'L')
				{
					if (info[i].withdrawn)
					{
						printf("%-28s", info[i].name);
						ageGroup(info[i].age);
						printf(" N/A       Yes\n");
					}
					else
					{
						printf("%-28s", info[i].name);
						ageGroup(info[i].age);
						printf(" ");
						timeConversion(info[i].startTime, info[i].finishTime);
						printf("       No\n");
					}
					counter++;
				}
			}
			if (counter == 0)
			{
				printf("Not Awarded\n");
			}
			break;
	}
}

//Function 13: display last three in a category
void lastThree(struct SkierInfo info[], int size)
{
	int selection = 0, i = 0, age = 0, counter = 0;

	sortSkier(info, size);
	selection = sml();
	printf("Skier                    Age Group Time\n");
	printf("---------------------------------------\n");

	switch (selection)
	{
		case 1:
			for (i = size - 1; i >= 0; i--)
			{
				if ((info[i].raceLength == 'S' || info[i].raceLength == 's') && info[i].withdrawn == 0 && counter < 3)
				{
					printf("%-28s", info[i].name);
					ageGroup(info[i].age);
					printf(" ");
					timeConversion(info[i].startTime, info[i].finishTime);
					printf("\n");
					counter++;
				}
			}
			if (counter == 0)
			{
				printf("Not Awarded\n");
			}
			break;

		case 2:
			for (i = size - 1; i >= 0; i--)
			{
				if ((info[i].raceLength == 'M' || info[i].raceLength == 'm') && info[i].withdrawn == 0 && counter < 3)
				{
					printf("%-28s", info[i].name);
					ageGroup(info[i].age);
					printf(" ");
					timeConversion(info[i].startTime, info[i].finishTime);
					printf("\n");
					counter++;
				}
			}
			if (counter == 0)
			{
				printf("Not Awarded\n");
			}
			break;

		case 3:
			for (i = size - 1; i >= 0; i--)
			{
				if ((info[i].raceLength == 'L' || info[i].raceLength == 'l') && info[i].withdrawn == 0 && counter < 3)
				{
					printf("%-28s", info[i].name);
					ageGroup(info[i].age);
					printf(" ");
					timeConversion(info[i].startTime, info[i].finishTime);
					printf("\n");
					counter++;
				}
			}
			if (counter == 0)
			{
				printf("Not Awarded\n");
			}
			break;
	}
}

//Function 14: display winner for each category
void winner(struct SkierInfo info[], int size)
{
	int i = 0, flag = 0;

	sortSkier(info, size);
	printf("Skier                    Age Group Category Time\n");
	printf("------------------------------------------------\n");
	
	for (i = 0, flag = 0; i < size && flag == 0; i++)
	{
		if (info[i].raceLength == 's' || info[i].raceLength == 'S')
		{
			flag = 1;
			printf("%-28s", info[i].name);
			ageGroup(info[i].age);
			printf("    10 km ");
			timeConversion(info[i].startTime, info[i].finishTime);
			printf("\n");
		}
	}
	if (flag == 0)
	{
		printf("Not Awarded");
	}

	for (i = 0, flag = 0; i < size && flag == 0; i++)
	{
		if (info[i].raceLength == 'm' || info[i].raceLength == 'M')
		{
			flag = 1;
			printf("%-28s", info[i].name);
			ageGroup(info[i].age);
			printf("    25 km ");
			timeConversion(info[i].startTime, info[i].finishTime);
			printf("\n");
		}
	}
	if (flag == 0)
	{
		printf("Not Awarded");
	}

	for (i = 0, flag = 0; i < size && flag == 0; i++)
	{
		if (info[i].raceLength == 'l' || info[i].raceLength == 'L')
		{
			flag = 1;
			printf("%-28s", info[i].name);
			ageGroup(info[i].age);
			printf("    50 km ");
			timeConversion(info[i].startTime, info[i].finishTime);
			printf("\n");
		}
	}
	if (flag == 0)
	{
		printf("Not Awarded");
	}
}