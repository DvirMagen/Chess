#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

typedef char chessPos[2];

typedef struct _chessPosArray
{
	unsigned int size;
	chessPos* positions;
} chessPosArray;


chessPosArray*** validKnightMoves();
void updateKnightMovesArray(chessPosArray* pose, int row, int col);
unsigned int countMovesOptions(int row, int col);
bool isValidTile(int row, int col);
void printChessPose(chessPosArray* chessPose);
void getChessPoseFromUser();
void freeArray(chessPosArray*** chessPoseArr);