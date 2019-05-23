#pragma once

#include <stdio.h>
#include <Windows.h>

typedef struct NODE{
	char gname[20];
	int count;
	struct NODE* next;
}NODE;

typedef struct {
	int length;
	NODE* next;
}HEAD;

void Tmain(HEAD*[]);