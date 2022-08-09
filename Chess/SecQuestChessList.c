#define _CRT_SECURE_NO_WARNINGS
#include "SecQuest.h"
void display(ChessPosList* lst)
{
	ChessPoseCell* curr1 = lst->head;
	ChessPoseCell* curr2 = NULL;
	ChessPoseCell* tmp = NULL;
	while (curr1 != NULL)
	{
		curr2 = curr1;
		while (curr2->next != NULL)
		{
			if (curr1->position[0] == curr2->next->position[0] && curr1->position[1] == curr2->next->position[1])
			{
				tmp = curr2->next;
				if (lst->tail == curr2->next)
				{
					lst->tail = curr2;
				}
				curr2->next = curr2->next->next;
				tmp->next = NULL;
				free(tmp);
			}
			else
			{
				curr2 = curr2->next;
			}
		}
		curr1 = curr1->next;
	}
	printListData(lst);
}
bool isValidStep(ChessPosList* lst, chessPos value)
{
	ChessPoseCell* curr = lst->tail;
	if (curr == NULL)
		return true;
	int new_row = (int)(value[0] - 'A'), new_col = (int)(value[1] - '1');
	int current_row = (int)(curr->position[0] - 'A'), current_col = (int)(curr->position[1] - '1');
	if (current_row + 2 == new_row && current_col + 1 == new_col)
		return  true;
	else if (current_row + 2 == new_row && current_col - 1 == new_col)
		return  true;
	else if (current_row - 2 == new_row && current_col + 1 == new_col)
		return  true;
	else if (current_row - 2 == new_row && current_col - 1 == new_col)
		return  true;
	else if (current_row + 1 == new_row && current_col + 2 == new_col)
		return  true;
	else if (current_row + 1 == new_row && current_col - 2 == new_col)
		return  true;
	else if (current_row - 1 == new_row && current_col + 2 == new_col)
		return  true;
	else if (current_row - 1 == new_row && current_col - 2 == new_col)
		return  true;
	else return false;
}
void makeEmptyList(ChessPosList* lst)
{
	lst->head = lst->tail = NULL;
}
void insertCellToEndList(ChessPosList* lst, ChessPoseCell* new_tail)
{
	if (lst->head == NULL)
	{
		lst->head = new_tail;
		lst->tail = new_tail;
	}
	else
	{
		lst->tail->next = new_tail;
		lst->tail = new_tail;
	}
}
ChessPoseCell* createNewListCell(chessPos position_value, ChessPoseCell* next_cell)
{
	ChessPoseCell* res;
	res = (ChessPoseCell*)malloc(sizeof(ChessPoseCell));
	checkMemoryAllocation(res);
	res->position[0] = position_value[0];
	res->position[1] = position_value[1];
	res->next = next_cell;
	return res;
}
void insertDataToEndList(ChessPosList* lst, chessPos value)
{
	ChessPoseCell* new_tail = createNewListCell(value, NULL);
	insertCellToEndList(lst, new_tail);
}
void freeList(ChessPosList* lst)
{
	ChessPoseCell* curr = lst->head;
	ChessPoseCell* temp;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	free(lst);
}
void printListData(ChessPosList* lst)
{
	ChessPoseCell* curr;
	int tempArr[8][8];
	int i, k;
	int row, col;
	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
		{
			tempArr[row][col] = 0;
		}
	}
	curr = lst->head;
	while (curr != NULL)
	{
		tempArr[curr->position[0] - 'A'][curr->position[1] - '1'] = adressNodeInList(lst, curr->position);
		curr = curr->next;
	}

	for (i = 0; i < SIZE + 1; i++)
	{
		printf("+-----");
	}
	printf("+\n");
	for (i = 0; i < SIZE + 1; i++)
	{
		printf("|");
		if (i >= 1)
			printf("  %c  |", i - 1 + 'A');
		for (int j = 0; j < SIZE + 1; j++)
		{
			if (i == 0 && j > 0)
				printf("  %c  |", (char)(j - 1 + '1'));
			else if (tempArr[i - 1][j] > 0 && j < SIZE)
			{

				printf("  %d  |", tempArr[i - 1][j]);
			}
			else if (j < SIZE)
			{
				printf("     |");
			}
		}
		printf("\n");
		for (k = 0; k < SIZE + 1; k++)
		{
			printf("+-----");
		}
		printf("+\n");
	}
}
int adressNodeInList(ChessPosList* lst, chessPos data)
{
	int address = 1;
	ChessPoseCell* curr = lst->head;
	while (curr != NULL)
	{
		if (curr->position[0] == data[0] && curr->position[1] == data[1])
			break;
		address++;
		curr = curr->next;
	}
	return address;
}
void EnterPoseList()
{
	ChessPosList* lst = (ChessPosList*)malloc(sizeof(ChessPosList));
	int steps;
	char row_ch, col_ch;
	makeEmptyList(lst);
	char cordinate[2];
	printf("Enter How many steps you want to move:  ");
	scanf("%d", &steps);
	while (steps > 0)
	{
		getchar();
		scanf("%c%c", &row_ch, &col_ch);
		/*Check if the user enter a valid coordinate*/
		if (isValidTile((int)(row_ch - 'A'), (int)(col_ch - '1')))
		{
			cordinate[0] = row_ch;
			cordinate[1] = col_ch;
			/*Check if the user makes a legal step*/
			//if (isValidStep(lst, cordinate))
			//{
			insertDataToEndList(lst, cordinate);
			steps--;
			//}
			//else
				//printf("Please enter a valid step!\n");
		}
		else
			printf("Please enter a valid step!\n");
	}
	display(lst);
	freeList(lst);
}
