#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include <string.h>

typedef struct {
	char *string;
	char* outstr;
	int MaxLength;
	int size;
} word;

typedef struct {
	char *failedGuesses;
	int level;
	int trycount;

}guesses;

void chooseTheMode(int* mode)
{
	printf("How many players would you like?\n");
	scanf_s("%i", mode);
}

void chooseTheLevel(guesses* degree)
{
	int difficulty;
	printf("Choose the difficulty level - 1 or 2.\n");
	scanf_s("%i", &difficulty);
	if (difficulty == 2)
	{
		degree->level = 6;
	}
	else
	{
		degree->level = 10;
	}
	degree->failedGuesses= (char*)malloc((degree->level+1) * sizeof(char));
	degree->trycount = 0;
}

void initializeSearchedString(word*given, int initialSize)
{
	given->string = (char*)malloc(initialSize * sizeof(char));
	given->MaxLength = initialSize;
}

void initializeDisplayedString(word* given)
{
	given->outstr = (char*)malloc((given->size) * sizeof(char));
	for (int i = 0; i < (given->size); i++)
	{
		given->outstr[i] = '-';
	}
	
}

void setupOnePlayer(word* given)
{
	srand((unsigned int)time(NULL));
	FILE* dictionary;
	fopen_s(&dictionary, "words.txt", "r");
	char *container= (char*)malloc(given->MaxLength * sizeof(char));
	fgets(container, given->MaxLength,dictionary);
	int readcount = 2;
	while (fgets(container, given->MaxLength, dictionary) != NULL)
	{
		if ((rand() % readcount) == 0)
		{
			strcpy(given->string, container);
		}
		readcount++;
	}
	free(container);
	fclose(dictionary);
	given->size = strlen(given->string)-1;
	initializeDisplayedString(given);
}

void setupTwoPlayers(word* given)
{
	printf("Give the desired word.\n");
	scanf("%s", given->string);
	given->size = strlen(given->string);
	initializeDisplayedString(given);
}

void drawTheHangman(guesses* degree)
{
	if (degree->trycount == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	else if (degree->trycount == 1)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n==========\n");
	}
	else if (degree->trycount == 2 && degree->level == 10)
	{
		printf("\n\n  ||  \n");
		printf("  || \n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  || \n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("==========\n");
	}
	else if (degree->trycount == 2 && degree->level == 6 || degree->trycount == 3 && degree->level == 10)
	{
		printf("\n\n  ||  //\n");
		printf("  || //\n");
		printf("  ||//\n");
		printf("  ||\n");
		printf("  || \n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("==========\n");
	}
	else if (degree->trycount == 4 && degree->level == 10)
	{
		printf("  \n  ===========\n");
		printf("  ||  //\n");
		printf("  || //\n");
		printf("  ||//\n");
		printf("  ||\n");
		printf("  || \n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("==========\n");
	}
	else if (degree->trycount == degree->level / 2)
	{
		printf("  ___________\n");
		printf("  ===========\n");
		printf("  ||  //\n");
		printf("  || //\n");
		printf("  ||//\n");
		printf("  ||\n");
		printf("  || \n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("==========\n");
	}
	else if (degree->trycount == 4 && degree->level == 6 || degree->trycount == 6 && degree->level == 10)
	{
		printf("  ___________\n");
		printf("  ===========|\n");
		printf("  ||  //     |\n");
		printf("  || //      |\n");
		printf("  ||//       |\n");
		printf("  ||\n");
		printf("  || \n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("  ||\n");
		printf("==========\n");
	}
	else if (degree->trycount == 7 && degree->level == 10)
	{
		printf("  ___________     \n");
		printf("  ===========|    \n");
		printf("  ||  //     |    \n");
		printf("  || //      |    \n");
		printf("  ||//       |_   \n");
		printf("  ||         / \\ \n");
		printf("  ||         \\ /  \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("==========        \n");
	}
	else if (degree->trycount == 5 && degree->level == 6 || degree->trycount == 8 && degree->level == 10)
	{
		printf("  ___________     \n");
		printf("  ===========|    \n");
		printf("  ||  //     |    \n");
		printf("  || //      |    \n");
		printf("  ||//       |_   \n");
		printf("  ||         / \\ \n");
		printf("  ||         \\ /  \n");
		printf("  ||          |   \n");
		printf("  ||          |   \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("==========        \n");
	}
	else if (degree->trycount == 9 && degree->level == 10)
	{
		printf("  ___________     \n");
		printf("  ===========|    \n");
		printf("  ||  //     |    \n");
		printf("  || //      |    \n");
		printf("  ||//       |_   \n");
		printf("  ||         / \\ \n");
		printf("  ||         \\ /  \n");
		printf("  ||         /|\\  \n");
		printf("  ||          |   \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("==========        \n");
	}
	else if (degree->trycount == degree->level) //end of game
	{
		printf("   ___________    \n");
		printf("  ===========|    \n");
		printf("  ||  //     |    \n");
		printf("  || //      |    \n");
		printf("  ||//       |_   \n");
		printf("  ||         / \\ \n");
		printf("  ||         \\ / \n");
		printf("  ||          |   \n");
		printf("  ||         /|\\ \n");
		printf("  ||          |   \n");
		printf("  ||         / \\ \n");
		printf("  ||              \n");
		printf("  ||              \n");
		printf("==========        \n");
	}
}

void printGuess(word* given, guesses* degree)
{

	system("cls");
	printf("Here is your word:\n");
	for (int i = 0; i < (given->size); i++)
	{
		printf("%c", given->outstr[i]);
	}
	printf("\n");
	drawTheHangman(degree);
	printf("\nHere are incorrect letters you have already used:\n");
	for (int i = 0; i < degree->trycount; i++)
	{
		printf("%c ", degree->failedGuesses[i]);
	}
}

void makeOneGuess(word* given, guesses* degree)
{
	int checkvalue = 0;
	printf("\nType the desired letter.\n");
	char input;
	scanf(" %c", &input);
	for (int i = 0; i < given->size; i++)
	{
		if (given->string[i] == input)
		{
			given->outstr[i] = given->string[i];
			checkvalue = 1;
		}
	}
	if (checkvalue == 0)
	{
		degree->trycount++;
		degree->failedGuesses[(degree->trycount-1)] = input; 
		
	}
	checkvalue = 0;
}

void checkForVictory(word* given, guesses* degree, int *breakingloop)
{
	for (int i = 0; i < (given->size); i++)
	{
		if (given->outstr[i] == given->string[i])
		{
			(*breakingloop)++;
		}
	}
}

void estimateTheResult(word* given, guesses* degree)
{
	if (degree->trycount == degree->level)
	{
		printf("\nGame over!");
	}
	else
	{
		printf("\nThis is the word!");
	}
}

int main()
{
	word given;
	int initialSize = 100;
	initializeSearchedString(&given, initialSize);
	int mode;
	chooseTheMode(&mode);
	guesses degree;
	chooseTheLevel(&degree);
	if (mode > 1)
	{
		setupTwoPlayers(&given);
	}
	else
	{
		setupOnePlayer(&given);
	}

	printGuess(&given, &degree);

	while (degree.trycount < degree.level)
	{
		makeOneGuess(&given, &degree);
		printGuess(&given, &degree);
		int breakingloop = 0;
		checkForVictory(&given, &degree, &breakingloop);
		if (breakingloop == given.size)
		{
			break;
		}
	}
		
	estimateTheResult(&given, &degree);

	free(given.outstr);
	free(given.string);
	free(degree.failedGuesses);
	return 0;
}
