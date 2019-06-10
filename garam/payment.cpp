#include <stdio.h>
#include <Windows.h>
#include "payment.h"
#include "table.h"

#pragma warning(disable:4996)


// 결제 선택
void paymentSelect(HEAD* head) {

	if (head->next == NULL) {
		printf("주문이 없습니다.\n");
		return;
	}
	int cost=0;
	int paySel;
	int check;
	
	cost = head->pay;


	printf("총 가격:%d \n",cost);
	printf("=========\n");
	printf("1.현금결제\n");
	printf("2.카드결제\n");
	printf("0.종료\n");
	printf("=========\n");
	printf("번호입력 :_\b");
	scanf("%d", &paySel);

	if (paySel < 0 || paySel > 2) {
		printf("다시 입력해주세요.\n\n");
		while (getchar() != '\n');

		return;
	}

	if (paySel == 1) {
		system("cls");
		printf("현금결제를 선택하였습니다.\n총 가격: %d\n ",cost);
		check = cashChange(cost, head);
	}
	else if (paySel == 2) {
		printf("카드결제를 선택하였습니다\n");
		cardPay();
	}
	else if (paySel == 0) {
		system("cls");
	}
	else {
		while (getchar() != '\n');
		printf("다시 선택해주세요\n");
		paymentSelect(head);
	}

	if(check == TRUE) cancelAll(head);
	return;
}



// 현금 결제 거스름 돈
int cashChange(int cost, HEAD* head) {
	int change = 0;
	int cash ;
	static int costRemain = 0;
	costRemain = cost;

	printf("\n받은 금액: ");
	scanf("%d", &cash);

	if (cash < 0 ) {
		printf("다시 입력해주세요.\n\n");
		while (getchar() != '\n');

		return FALSE;
	}



	if (costRemain < cash) {
		change = -(costRemain - cash);
		printf("거스름 돈: %d\n\n", change);
	}
	else if (costRemain == cash) printf("\n결제 완료\n\n");
	else if (costRemain > cash) {
		costRemain = costRemain - cash;
		head->pay = costRemain;
		printf("남은 금액: %d\n", costRemain);
		return FALSE;
	}
	return TRUE;

}

// 카드 결제
void cardPay() {
	int cardNum;

	system("cls");
	printf("카드번호를 입력해주세요: "); 	scanf("%d", &cardNum);
	printf("결제완료되었습니다.\n\n");

}