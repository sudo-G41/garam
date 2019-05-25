#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define TRUE 1
#define FLASE 0
#define TABLESIZE 10

typedef struct NODE {
	char gname[20];//상품명
	int count;//주문 개수
	struct NODE* next;
}NODE;

typedef struct HEAD {
	int length;//테이블별 주문 수(상품 종류별 개수)
	int pay;//총 결제 금액
	NODE* next;
}HEAD;

void Tmain(HEAD*head[]);
void cancelAll(HEAD*head);
void printTable(HEAD*[]);
HEAD* createNode();