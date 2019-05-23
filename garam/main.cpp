#include <stdio.h>
#include <Windows.h>
#include "goods.h" // 구조체
#include "payment.h"
#include "table.h"


#pragma warning(disable:4996)


#define SIZE 3

void warehouse();
void unstore();
void present_condition();

 
HEAD *head[10];

int n = 0;
FILE *fp;




int main()
{
	GOODS GN[SIZE];

	if ((fp = fopen("product.txt", "r")) == NULL) {
		fp = fopen("product.txt", "w");
		fclose(fp);
	}

	for (int i = 0; i < SIZE; i++) {
		fscanf(fp, "%d %s %d %s %d \n", &GN[i].gn, /*&GN[i].gnumber,*/ GN[i].gname, &GN[i].gstock, GN[i].gcompany, &GN[i].gprice);
		if (i != GN[i].gn - 1) {
			n = i;
			break;
		}
	}
	fclose(fp);
	while (1) {
		int a;
		printf("=========\n");
		printf("1.입고\n");
		printf("2.출고\n");
		printf("3.현황표시\n");
		printf("4.테이블선택\n");
		printf("5 결제\n");
		printf("0.종료\n");
		printf("=========\n");
		printf("번호입력: ");
		scanf("%d", &a);
		printf("\n");

		if (a == 1) warehouse();
		else if (a == 2) unstore();
		else if (a == 3) present_condition();
		//else if (a == 4) Tmain(head);
		//else if (a == 5) paymentSelect();
		else if (a == 0) exit(0);
		else {
			//system("cls");
			printf("없는 번호입니다.\n");
			while (getchar() != '\n');
		}
	}
}

void warehouse() {
	GOODS G1[SIZE];

	if ((fp = fopen("product.txt", "a")) == NULL) {
		printf("파일 열기 오류...\n");
		exit(-1);
	}

	while (1) {
		printf("%d번째 물품 \n", n + 1);
		//printf("물품번호: "); scanf("%d", &G1[n].gn);
		G1[n].gn = n;
		if (G1[n].gn >= 0) {
			printf("물품이름: ");   scanf("%s", G1[n].gname);
			printf("물품가격: ");   scanf("%d", &G1[n].gprice);
			printf("재고수량: ");   scanf("%d", &G1[n].gstock);
			printf("생산회사: ");   scanf("%s", G1[n].gcompany);

			fprintf(fp, " %d %s %d %s %d\n", n + 1,/* G1[n].gnumber,*/ G1[n].gname, G1[n].gstock, G1[n].gcompany, G1[n].gprice);
			printf("\n\n☆물품정보 저장완료☆\n\n");
			n = n + 1;
			break;
		}
		else {
			printf("\n\n ★입고를 종료합니다★ \n\n");
			break;
		}
	}
	fclose(fp);
}

void unstore()

{
	GOODS G2[SIZE];
	int gnum2;
	int a = 0;

	if ((fp = fopen("product.txt", "r")) == NULL) {
		printf("파일 열기 오류...\n");
		exit(-1);
	}
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %s %d %s %f.000000 \n", &G2[i].gn, /*&G2[i].gnumber,*/ G2[i].gname, &G2[i].gstock, G2[i].gcompany, &G2[i].gprice);
	}
	fclose(fp);

	while (1) {
		printf("\n\n물품번호 입력: ");
		scanf("%d", &a);
		if (a <= 0) {
			if ((fp = fopen("product.txt", "w")) == NULL) {
				printf("파일 열기 오류...\n");
				exit(-1);
			}
			for (int i = 0; i < n; i++) {
				fprintf(fp, " %d %s %d %s %f\n", i + 1,/* G2[i].gnumber,*/ G2[i].gname, G2[i].gstock, G2[i].gcompany, G2[i].gprice);
			}
			printf("\n\n☆물품정보 저장완료☆\n\n");
			fclose(fp);
			break;
		}
		else
			for (int i = 0; i < n; i++) {
				if (G2[i].gn == a) {
					printf("\n※현재고수량: %d\n\n", G2[i].gstock);
					while (1) {
						printf("출고수량 입력: ");
						scanf("%d", &gnum2);
						if (gnum2 < G2[i].gstock) {
							G2[i].gstock = G2[i].gstock - gnum2;
							printf("\n※재고수량: %d -> %d\n", G2[i].gstock + gnum2, G2[i].gstock);
							break;
						}
						printf("\n입력오류! -> 출고수량이 재고수량보다 큽니다. (현재고수량 -> %d)\n\n", G2[i].gstock);
					}
					break;
				}
			}
	}
}

void present_condition()
{
	GOODS G3[SIZE];

	if ((fp = fopen("product.txt", "r")) == NULL) {
		printf("파일 열기 오류...\n");
		exit(-1);
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %s %d %s %d \n", &G3[i].gn, /*&G3[i].gnumber,*/ G3[i].gname, &G3[i].gstock, G3[i].gcompany, &G3[i].gprice);
		printf("%3d번째   ", G3[i].gn);
		//printf("물품번호: %d\t", G3[i].gnumber);
		printf("물품이름: %-10s\t", G3[i].gname);
		printf("물품가격: %d원\t", G3[i].gprice);
		printf("재고수량: %5d개   ", G3[i].gstock);
		printf("생산회사: %s\n", G3[i].gcompany);
	}
	printf("\n\n");
	fclose(fp);
}