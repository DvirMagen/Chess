#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "FirstQuest.h"
#include "SecQuest.h"
#define SIZE 8

typedef char chessPos[2];

typedef struct _treeNode {
	chessPos position;
	struct treeNodeListCell* next_possible_position;
}treeNode;

typedef struct _treeNodeListCell
{
	treeNode* node;
	struct _treeNodeListCell* next;
}treeNodeListCell;

typedef struct _pathTree
{
	treeNode* root;
}pathTree;
/*Third Quest*/
void makeEmptyTreeList(treeNode* TreeLst);
pathTree findAllPossibleKnightPaths(chessPos* startingPosition);
treeNodeListCell* createNewTreeListCell(chessPos position_value, treeNodeListCell* next_cell);
void insertDataToEndTreeList(treeNodeListCell** treeLst, chessPos value);
void insertCellToEndTreeList(treeNodeListCell** treeLst, treeNodeListCell* new_tail);
/*More Functions*/
void checkMemoryAllocation(void* data);
void main()
{
	int chekerChoose;
	printf("Please enter which quest do you like check: \n");
	scanf("%d", &chekerChoose);
	if (chekerChoose == 1)
	{
		getchar();
		getChessPoseFromUser();
	}
	else
		EnterPoseList();
}

//Add this shit - For Niro
pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
	pathTree path_tree;
	chessPosArray*** chessArray = validKnightMoves();
	int i;
	int p1 = startingPosition[0] - 'A';
	int p2 = startingPosition[1] - '1';
	path_tree.root = createNewtreeNode(path_tree.root->position, path_tree.root->next_possible_position);
	makeEmptyTreeList(path_tree.root);
	//need to think how to make the positions 0 for the stopping site of the recrusia
	if ((chessArray[p1][p2])->positions == 0)
		return;
	else
	{
		for (i = 0; i < chessArray[p1][p2]->size; i++)
		{
			insertDataToEndTreeList(&(path_tree.root), chessArray[p1][p2]->positions[i]);

		}
		return path_tree;
	}
}
//Add this shit - For Niro
void makeEmptyTreeList(treeNode* TreeLst)
{
	TreeLst->next_possible_position = NULL;
}
//Add this shit - For Niro
treeNode* createNewtreeNode(int data, treeNode* next)
{
		treeNode* node = (treeNode*)malloc(sizeof(treeNode));
		checkMemoryAllocation(node);
		*node->position = data;
		node->next_possible_position = next;
		return node;
}
treeNodeListCell* createNewTreeListCell(chessPos position_value, treeNodeListCell* next_cell)
{
	treeNodeListCell* res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	checkMemoryAllocation(res);
	res->node->position[0] = position_value[0];
	res->node->position[1] = position_value[1];
	res->next = next_cell;
	return res;
}
void insertDataToEndTreeList(treeNodeListCell** treeLst, chessPos value)
{
	treeNodeListCell* new_tail = createNewTreeListCell(value, NULL);
	insertCellToEndTreeList(treeLst, new_tail);
}
void insertCellToEndTreeList(treeNodeListCell** treeLst, treeNodeListCell* new_tail)
{
	if (*treeLst == NULL)
	{
		*treeLst = new_tail;
	}
	else
	{
		while ((*treeLst)->next != NULL)
		{
			(*treeLst) = (*treeLst)->next;
		}
		(*treeLst)->next = new_tail;
	}
}
/*More Functions*/
void checkMemoryAllocation(void* data)
{
	if (data == NULL)
	{
		printf("Memory Allocation failed!\n");
		exit(1);
	}
}