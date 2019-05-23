#include <stdio.h>
#include <Windows.h>
#include "payment.h"

#pragma warning(disable:4996)


// 결제 선택
void paymentSelect(int cost) {
	int paySel = 0;

	printf("총 가격:%d \n",cost);
	printf("=========\n");
	printf("1.현금결제\n");
	printf("2.카드결제\n");
	printf("0.종료\n");
	printf("=========\n");
	scanf("%d", &paySel);

	if (paySel == 1) {
		system("cls");
		printf("현금결제를 선택하였습니다.\n총 가격: %d\n ",cost);
		cashChange(cost);
	}
	else if (paySel == 2) {
		printf("카드결제를 선택하였습니다\n");
		cardPay();
	}
	else if (paySel == 0) exit(0);
	else {
		while (getchar() != '\n');
		printf("다시 선택해주세요\n");
		paymentSelect(cost);
	}
	return;
}



// 현금 결제 거스름 돈
void cashChange(int cost) {
	int change = 0;
	int cash = 0;
	static int costRemain = 0;
	costRemain = cost;

	printf("\n받은 금액: ");
	scanf("%d", &cash);


	if (costRemain < cash) {
		change = -(costRemain - cash);
		printf("거스름 돈: %d\n\n", change);
	}
	else if (costRemain == cash) printf("\n결제 완료\n\n");
	else if (costRemain > cash) {
		costRemain = costRemain - cash;
		printf("남은 금액: %d\n", costRemain);
		cashChange(costRemain);
	}

}

// 카드 결제
void cardPay() {
	int cardNum;

	system("cls");
	printf("카드번호를 입력해주세요: "); 	scanf("%d", &cardNum);
	printf("결제완료되었습니다.\n\n");

}