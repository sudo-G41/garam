#include <stdio.h>
#include "payment.h"

#pragma warning(disable:4996)


// ī�� ����
void paymentSelect() {
	int paySel = 0;

	printf("���ݰ��� 1, ī����� 2\n");
	scanf("%d", &paySel);

	if (paySel == 1) {
		printf("���ݰ����� �����Ͽ����ϴ�\n ");
		cashChange(10000);
	}
	else if (paySel == 2) printf("ī������� �����Ͽ����ϴ�\n");
	else {
		while (getchar() != '\n');
		printf("�ٽ� �������ּ���\n");
		paymentSelect();
	}
	return;
}



// ���� ���� �Ž��� ��
void cashChange(int cost) {
	int change = 0;
	int cash = 0;
	static int costRemain = 0;
	costRemain = cost;

	printf("���� ����: ");
	scanf("%d", &cash);


	if (costRemain < cash) {
		change = -(costRemain - cash);
		printf("�Ž��� ��: %d\n", change);
	}
	else if (costRemain == cash) printf("\n���� �Ϸ�\n\n");
	else if (costRemain > cash) {
		costRemain = costRemain - cash;
		printf("%d���� �����մϴ�.\n", costRemain);
		cashChange(costRemain);
	}

}