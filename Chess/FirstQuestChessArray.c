#define _CRT_SECURE_NO_WARNINGS
#include "FirstQuest.h"
void getChessPoseFromUser()
{
	char row_ch, col_ch;
	int row_num, col_num;
	chessPosArray*** chessPoseArr = validKnightMoves();
	printf("Please enter pose on the board: \n");
	scanf("%c%c", &row_ch, &col_ch);
	row_num = row_ch - 'A';
	col_num = col_ch - '1';
	printChessPose(chessPoseArr[row_num][col_num]);
	freeArray(chessPoseArr);
}
chessPosArray*** validKnightMoves()
{
	chessPosArray*** pointersArray = (chessPosArray***)malloc(sizeof(chessPosArray**) * SIZE);
	checkMemoryAllocation(pointersArray);
	for (int i = 0; i < SIZE; i++)
	{
		pointersArray[i] = (chessPosArray**)malloc(sizeof(chessPosArray*) * SIZE);
		checkMemoryAllocation(pointersArray[i]);
		for (int j = 0; j < SIZE; j++)
		{
			pointersArray[i][j] = (chessPosArray*)malloc((sizeof(chessPosArray)) * SIZE);
			checkMemoryAllocation(pointersArray[i][j]);
			updateKnightMovesArray((pointersArray[i][j]), i, j);
		}
	}
	return pointersArray;
}
void printChessPose(chessPosArray* chessPose)
{
	unsigned int i;
	for (i = 0; i < chessPose->size; i++)
	{
		printf("%c%c\n", chessPose->positions[i][0], chessPose->positions[i][1]);
	}
}
void updateKnightMovesArray(chessPosArray* pose, int row, int col)
{
	int k = 0;
	unsigned int count = countMovesOptions(row, col);
	pose->positions = (chessPos*)malloc(sizeof(chessPos) * count);
	checkMemoryAllocation(pose->positions);
	pose->size = count;
	if (isValidTile(row + 2, col + 1) == true)
	{
		pose->positions[k][0] = (char)(row + 2 + 'A');
		pose->positions[k][1] = (char)(col + 1 + '1');
		k++;
	}

	if (isValidTile(row + 2, col - 1) == true)
	{
		pose->positions[k][0] = (char)(row + 2 + 'A');
		pose->positions[k][1] = (char)(col - 1 + '1');
		k++;
	}
	if (isValidTile(row - 2, col + 1) == true)
	{
		pose->positions[k][0] = (char)(row - 2 + 'A');
		pose->positions[k][1] = (char)(col + 1 + '1');
		k++;
	}
	if (isValidTile(row - 2, col - 1) == true)
	{
		pose->positions[k][0] = (char)(row - 2 + 'A');
		pose->positions[k][1] = (char)(col - 1 + '1');
		k++;
	}
	if (isValidTile(row + 1, col + 2) == true)
	{
		pose->positions[k][0] = (char)(row + 1 + 'A');
		pose->positions[k][1] = (char)(col + 2 + '1');
		k++;
	}
	if (isValidTile(row + 1, col - 2) == true)
	{
		pose->positions[k][0] = (char)(row + 1 + 'A');
		pose->positions[k][1] = (char)(col - 2 + '1');
		k++;
	}
	if (isValidTile(row - 1, col + 2) == true)
	{
		pose->positions[k][0] = (char)(row - 1 + 'A');
		pose->positions[k][1] = (char)(col + 2 + '1');
		k++;
	}
	if (isValidTile(row - 1, col - 2) == true)
	{
		pose->positions[k][0] = (char)(row - 1 + 'A');
		pose->positions[k][1] = (char)(col - 2 + '1');
		k++;
	}

}
unsigned int countMovesOptions(int row, int col)
{
	unsigned int count = 0;
	if (isValidTile(row + 2, col + 1) == true)
		count++;
	if (isValidTile(row + 2, col - 1) == true)
		count++;
	if (isValidTile(row - 2, col + 1) == true)
		count++;
	if (isValidTile(row - 2, col - 1) == true)
		count++;
	if (isValidTile(row + 1, col + 2) == true)
		count++;
	if (isValidTile(row + 1, col - 2) == true)
		count++;
	if (isValidTile(row - 1, col + 2) == true)
		count++;
	if (isValidTile(row - 1, col - 2) == true)
		count++;
	return count;
}
bool isValidTile(int row, int col)
{
	if (row < 0 || row > SIZE || col < 0 || col > SIZE)
	{
		return false;
	}
	return true;
}
void freeArray(chessPosArray*** chessPoseArr)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (chessPoseArr[i][j]->positions != NULL)
			{
				free(chessPoseArr[i][j]->positions);
				chessPoseArr[i][j]->positions = NULL;
			}
			if (chessPoseArr[i][j] != NULL)
			{
				free(chessPoseArr[i][j]);
				chessPoseArr[i][j] = NULL;
			}
		}
		free(chessPoseArr[i]);
		chessPoseArr[i] = NULL;
	}
	free(chessPoseArr);
	chessPoseArr = NULL;
}