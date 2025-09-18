#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define P1 1
#define P2 2

char *board[10][10] = {{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"}, {"11", "12", "13 S", "14", "15 S", "16", "17", "18", "19", "20"}, {"21", "22", "23", "24", "25", "26", "27", "28", "29 S", "30"}, {"31", "32", "33", "34", "35", "36 S", "37", "38", "39", "40"}, {"41", "42", "43", "44", "45", "46", "47", "48 S", "49", "50"}, {"51", "52 S", "53", "54", "55", "56", "57", "58", "59 S", "60"}, {"61", "62", "63", "64", "65", "66", "67", "68", "69", "70"}, {"71", "72", "73", "74", "75", "76", "77", "78 S", "79", "80"}, {"81", "82", "83", "84", "85", "86", "87", "88", "89", "90"}, {"91", "92", "93", "94", "95 S", "96", "97", "98", "99 S", "100"}};

void drawBoard()
{
	int i , j, k = 1;
	printf("________________________________________________________________________________\n");
	for(i = 9; i >= 0; i--)
	{
		if(k == 0)
		{
			for(j = 0; j < 10; j++)
			{
				
				printf("%s\t|", board[i][j]);
				
			}
			k = 1;
		}
		else
		{
			for(j = 9; j >= 0; j--)
			{
				
				printf("%s\t|", board[i][j]);
				
			}
			k = 0;			
		}
		printf("\n________|_______|_______|_______|_______|_______|_______|_______|_______|______|\n");
	}
};

int strHas(char *str, char s)
{
	int i = 0;
	for(i = 0; i < strlen(str); i++)
	{
		if(s == (*str))
			return 1;
		str++;
	}
	return 0;
};

int finished()
{
	if(strlen(board[9][9]) > 3)
	{
		if(strHas(board[9][9], 'A'))	printf("Player 1 wins!...");
		else	printf("Player 2 wins!...");
		return 1;
	}
	return 0;
};

void checkSnakeBite(int *p, char pl)
{
	if(strHas(board[*p / 10][*p % 10], 'S'))	*p = 0;
};

int getDieVal()
{
	int d = rand() % 13;
	return (d == 0 ? 1 : d);
};

char *concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void removePosition(int pos, char *p)
{
	if(strHas(board[pos / 10][pos % 10], 'A') && strHas(board[pos / 10][pos % 10], 'B'))
	{
		if(p == "A")	board[pos / 10][pos % 10] = concat((char *) (pos + 1), " B");
		else	board[pos / 10][pos % 10] = concat((char *) (pos + 1), " A");
	}
	else
	{
		board[pos / 10][pos % 10] = (char *) (pos + 1);
	}
}

void addPosition(int pos, char *p)
{
	board[pos / 10][pos % 10] = concat(board[pos / 10][pos % 10], p);
}

int main()
{
	int chance = P1, p1 = 0, p2 = 0;
	char *pl1 = "A", *pl2 = "B", *current_player, d;
	board[0][0] = concat(concat(board[0][0], " "), concat(pl1, pl2));
	drawBoard();
	while(!finished())
	{
		if(chance == P1)
		{
			printf("Press \'Enter\' key to throw die...");
			scanf("%c", &d);
			//removePosition(p1, pl1);
			p1 += getDieVal();
			checkSnakeBite(&p1, 'A');
			addPosition(p1, pl1);
			drawBoard();
			chance = P2;
		}
		else
		{
			printf("Press \'Enter\' key to throw die...");
			scanf("%c", &d);
			//removePosition(p2, pl2);
			p2 += getDieVal();
			checkSnakeBite(&p2, 'B');
			addPosition(p2, pl2);
			drawBoard();
			chance = P1;
		}
	}
	return 0;
}