#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define TRUE 1
#define FLASE 0
#define TABLESIZE 10

typedef struct NODE {
	char gname[20];
	int count;
	struct NODE* next;
}NODE;

typedef struct HEAD {
	int length;
	//int pay;
	NODE* next;
}HEAD;

void Tmain(HEAD*head[]);
void cancelAll(HEAD*head);
void printTable(HEAD*[]);
HEAD* createNode();