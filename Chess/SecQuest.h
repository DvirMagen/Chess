#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

typedef char chessPos[2];

typedef struct _chessPoseCell
{
	chessPos position;
	struct _chessPoseCell* next;
}ChessPoseCell;


typedef struct _chessPosList
{
	ChessPoseCell* head;
	ChessPoseCell* tail;
}ChessPosList;

void display(ChessPosList* lst);
bool isValidStep(ChessPosList* lst, chessPos value);
void makeEmptyList(ChessPosList* lst);
void insertCellToEndList(ChessPosList* lst, ChessPoseCell* new_tail);
ChessPoseCell* createNewListCell(chessPos position_value, ChessPoseCell* next_cell);
void insertDataToEndList(ChessPosList* lst, chessPos value);
void printListData(ChessPosList* lst);
void freeList(ChessPosList* lst);
void EnterPoseList();
int adressNodeInList(ChessPosList* lst, chessPos data);
