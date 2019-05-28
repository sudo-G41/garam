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

	for (int i = 0; i < TABLESIZE; i++) {
		head[i] = createNode();
	}//테이블 초기화

	if ((fp = fopen("product.txt", "r")) == NULL) {
		fp = fopen("product.txt", "w");
		fclose(fp);
	}

	for (int i = 0; i < SIZE; i++) {
		fscanf(fp, "%d %s %d \n", &GN[i].gn, GN[i].gname, &GN[i].gprice);
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
		//printf("5 결제\n");
		printf("0.종료\n");
		printf("=========\n");
		printf("번호입력: ");
		scanf("%d", &a);
		printf("\n");

		if (a == 1) warehouse();
		else if (a == 2) unstore();
		else if (a == 3) present_condition();
		else if (a == 4) Tmain(head);
		//else if (a == 5) paymentSelect(head);
		else if (a == 0) exit(0);
		else {
			system("cls");
			printf("잘못된 입력입니다. 다시입력해주세요\n\n");
			while (getchar() != '\n');
		}
	}
}

void warehouse() {
	GOODS G1;

	if ((fp = fopen("product.txt", "a")) == NULL) {
		printf("파일 열기 오류...\n");
		exit(-1);
	}

	while (1) {
		printf("%d번째 물품 \n", n + 1);
		//printf("물품번호: "); scanf("%d", &G1[n].gn);
		G1.gn = n;
		if (G1.gn >= 0) {
			printf("물품이름: ");   scanf("%s", G1.gname);
			printf("물품가격: ");   scanf("%d", &G1.gprice);

			if (G1.gprice < 0) {
				printf("물품가격이 잘못 입력되었습니다. 다시 입력해주세요.\n\n");
				continue;
			}

			fprintf(fp, " %d %s %d\n", n + 1,/* G1[n].gnumber,*/ G1.gname, G1.gprice);


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
		fscanf(fp, "%d %s %d \n", &G2[i].gn, G2[i].gname,&G2[i].gprice);
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
				fprintf(fp, " %d %s %d %f\n", i + 1, G2[i].gname, G2[i].gprice);
			}
			printf("\n\n☆물품정보 저장완료☆\n\n");
			fclose(fp);
			break;
		}
		else
			for (int i = 0; i < n; i++) {
				if (G2[i].gn == a) {
					while (1) {
						printf("출고수량 입력: ");
						scanf("%d", &gnum2);
			
					}
					break;
				}
			}
	}
}

void present_condition()
{
	GOODS G3;

	if ((fp = fopen("product.txt", "r")) == NULL) {
		printf("파일 열기 오류...\n");
		exit(-1);
	}
	printf("\n\n");

	
	while (!feof(fp)) {
		fscanf(fp, "%d %s %d \n", &G3.gn, G3.gname, &G3.gprice);
		printf("%3d번째   ", G3.gn);
		printf("물품이름: %-10s\t", G3.gname);
		printf("물품가격: %d원\t", G3.gprice);
	}

	printf("\n\n");
	fclose(fp);
}