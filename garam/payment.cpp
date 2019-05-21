#include <stdio.h>
#include "payment.h"

#pragma warning(disable:4996)


// 카드 선택
void paymentSelect() {
	int paySel = 0;

	printf("현금결제 1, 카드결제 2\n");
	scanf("%d", &paySel);

	if (paySel == 1) {
		printf("현금결제를 선택하였습니다\n ");
		cashChange(10000);
	}
	else if (paySel == 2) printf("카드결제를 선택하였습니다\n");
	else {
		while (getchar() != '\n');
		printf("다시 선택해주세요\n");
		paymentSelect();
	}
	return;
}



// 현금 결제 거스름 돈
void cashChange(int cost) {
	int change = 0;
	int cash = 0;
	static int costRemain = 0;
	costRemain = cost;

	printf("받은 현금: ");
	scanf("%d", &cash);


	if (costRemain < cash) {
		change = -(costRemain - cash);
		printf("거스름 돈: %d\n", change);
	}
	else if (costRemain == cash) printf("\n결제 완료\n\n");
	else if (costRemain > cash) {
		costRemain = costRemain - cash;
		printf("%d원이 부족합니다.\n", costRemain);
		cashChange(costRemain);
	}

}