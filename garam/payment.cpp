#include <stdio.h>
#include <Windows.h>
#include "payment.h"
#include "table.h"

#pragma warning(disable:4996)


// ���� ����
void paymentSelect(HEAD* head) {

	if (head->next == NULL) {
		printf("�ֹ��� �����ϴ�.\n");
		return;
	}
	int cost=0;
	int paySel;
	int check;
	
	cost = head->pay;


	printf("�� ����:%d \n",cost);
	printf("=========\n");
	printf("1.���ݰ���\n");
	printf("2.ī�����\n");
	printf("0.����\n");
	printf("=========\n");
	printf("��ȣ�Է� :_\b");
	scanf("%d", &paySel);

	if (paySel < 0 || paySel > 2) {
		printf("�ٽ� �Է����ּ���.\n\n");
		while (getchar() != '\n');

		return;
	}

	if (paySel == 1) {
		system("cls");
		printf("���ݰ����� �����Ͽ����ϴ�.\n�� ����: %d\n ",cost);
		check = cashChange(cost, head);
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

	if(check == TRUE) cancelAll(head);
	return;
}



// ���� ���� �Ž��� ��
int cashChange(int cost, HEAD* head) {
	int change = 0;
	int cash ;
	static int costRemain = 0;
	costRemain = cost;

	printf("\n���� �ݾ�: ");
	scanf("%d", &cash);

	if (cash < 0 ) {
		printf("�ٽ� �Է����ּ���.\n\n");
		while (getchar() != '\n');

		return FALSE;
	}



	if (costRemain < cash) {
		change = -(costRemain - cash);
		printf("�Ž��� ��: %d\n\n", change);
	}
	else if (costRemain == cash) printf("\n���� �Ϸ�\n\n");
	else if (costRemain > cash) {
		costRemain = costRemain - cash;
		head->pay = costRemain;
		printf("���� �ݾ�: %d\n", costRemain);
		return FALSE;
	}
	return TRUE;

}

// ī�� ����
void cardPay() {
	int cardNum;

	system("cls");
	printf("ī���ȣ�� �Է����ּ���: "); 	scanf("%d", &cardNum);
	printf("�����Ϸ�Ǿ����ϴ�.\n\n");

}