#include <stdio.h>
#include <Windows.h>
#include "payment.h"
#include "table.h"

#pragma warning(disable:4996)


// ���� ����
void paymentSelect(HEAD*head) {

	
	int cost=0;
	int paySel = 0;
	
	cost = head->pay;


	printf("�� ����:%d \n",cost);
	printf("=========\n");
	printf("1.���ݰ���\n");
	printf("2.ī�����\n");
	printf("0.����\n");
	printf("=========\n");
	scanf("%d", &paySel);

	if (paySel == 1) {
		system("cls");
		printf("���ݰ����� �����Ͽ����ϴ�.\n�� ����: %d\n ",cost);
		cashChange(cost);
	}
	else if (paySel == 2) {
		printf("ī������� �����Ͽ����ϴ�\n");
		cardPay();
	}
	else if (paySel == 0) {
		system("cls");
	}
	else {
		while (getchar() != '\n');
		printf("�ٽ� �������ּ���\n");
		paymentSelect(head);
	}
	cancelAll(head);
	return;
}



// ���� ���� �Ž��� ��
void cashChange(int cost) {
	int change = 0;
	int cash = 0;
	static int costRemain = 0;
	costRemain = cost;

	printf("\n���� �ݾ�: ");
	scanf("%d", &cash);


	if (costRemain < cash) {
		change = -(costRemain - cash);
		printf("�Ž��� ��: %d\n\n", change);
	}
	else if (costRemain == cash) printf("\n���� �Ϸ�\n\n");
	else if (costRemain > cash) {
		costRemain = costRemain - cash;
		printf("���� �ݾ�: %d\n", costRemain);
		cashChange(costRemain);
	}

}

// ī�� ����
void cardPay() {
	int cardNum;

	system("cls");
	printf("ī���ȣ�� �Է����ּ���: "); 	scanf("%d", &cardNum);
	printf("�����Ϸ�Ǿ����ϴ�.\n\n");

}