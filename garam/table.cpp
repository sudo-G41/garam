#include "table.h"
#define TRUE 1
#define FLASE 0
#define TABLESIZE 10

void input(HEAD*);
void tableList(HEAD*);
void cancel(HEAD*);

HEAD* createNode() {
	HEAD* head = (HEAD*)malloc(sizeof(HEAD));
	if (head == NULL) {
		printf("���ܹ߻�! �޸𸮰� �����մϴ�.\n");
		printf("�ý����� �����մϴ�.\n");
		system("pause");
		exit(1);
	}
	head->next = NULL;
	head->length = 0;
	return head;
}
void printTable(HEAD *head[]) {
	printf("=================================================================================\n");
	printf("| 1�����̺�\t| 2�����̺�\t| 3�����̺�\t| 4�����̺�\t| 5�����̺�\t|\n");
	for (int i = 0; i < 5; i++) {
		if (head[i]->next == NULL) {
			printf("| �����̺�\t");
		}
		else {
			printf("| �ֹ��� \t");
		}
	}
	printf("|\n=================================================================================\n");
	printf("| 6�����̺�\t| 7�����̺�\t| 8�����̺�\t| 9�����̺�\t| 10�����̺�\t|\n");
	for (int i = 5; i < 10; i++) {
		if (head[i]->next == NULL) {
			printf("| �����̺�\t");
		}
		else {
			printf("| �ֹ��� \t");
		}
	}
	printf("|\n=================================================================================\n");
}
void input(HEAD* head) {
	NODE* tmp;
	NODE* node = (NODE*)malloc(sizeof(NODE));
	printf("��ǰ���� �Է��� �ּ��� : ");
	scanf("%s", node->gname);
	printf("������ �Է��� �ּ��� : ");
	scanf("%d", &node->count);
	if (node->count < 1) {
		printf("�߸��� ���Դϴ�.\n");
		return;
	}
	if (head->next == NULL) {
		node->next = head->next;
		head->next = node;
		head->length++;
		return;
	}
	tmp = head->next;
	for (; tmp->next != NULL; tmp = tmp->next) {
		if (strcmp(tmp->gname, node->gname)==0) {
			tmp->count += node->count;
			return;
		}
	}
	if (strcmp(tmp->gname, node->gname)==0) {
		tmp->count += node->count;
		free(node);
		return;
	}
	else {
		node->next = tmp->next;
		tmp->next = node;
		head->length++;
		return;
	}
}
void tableList(HEAD* head) {
	int i = 1;
	if (head->next == NULL)return;
	NODE *tmp = head->next;
	printf("====================================\n");
	for (; tmp != NULL; tmp = tmp->next) {
		printf("|%3d. %-20s %4d�� |\n", i++, tmp->gname, tmp->count);
	}
	printf("====================================\n");
}
void cancel(HEAD* head) {
	NODE*tmp = head->next;
	NODE*ptr;
	int i;
	if (tmp == NULL) {
		printf("����ֽ��ϴ�.\n");
		return;
	}
	tableList(head);
	printf("�� ��° ��ǰ�� ����Ͻðڽ��ϱ�? ");
	scanf("%d", &i);
	if (0>i||i > head->length) {
		printf("���� ��ȣ�Դϴ�.\n");
		return;
	}
	if (i == 1) {
		head->next = tmp->next;
		head->length--;
		free(tmp);
		return;
	}
	for (int x = 1; x < i; x++) {
		ptr = tmp;
		tmp = tmp->next;
	}
	ptr->next = tmp->next;
	head->length--;
	free(tmp);
	return;
}
void cancelAll(HEAD*head) {
	if (head->next == NULL) {
		printf("�̹� ����ֽ��ϴ�.\n");
		return;
	}
	for (; head->next != NULL;) {
		NODE*ptr=head->next;
		head->next = ptr->next;
		free(ptr);
	}
	head->length = 0;
}

void Tmain(HEAD*head[]) {
	int num,Tnum;

	printf("=============\n");
	printf("1.���̺� Ȯ��\n");
	printf("2.���̺� ����\n");
	printf("3.����\n");
	printf("=============\n");
	printf("��ȣ�Է�: ");
	scanf("%d", &num);
	printf("\n");
	if (num == 1)printTable(head);
	else if (num == 2) {
		printf("��� ���̺�? : ");
		scanf("%d", &Tnum);
		while (true) {
			tableList(head[Tnum - 1]);
			printf("==========\n");
			printf("1.�ֹ�\n");
			printf("2.�ֹ����\n");
			printf("3.��ü���\n");
			printf("4.������\n");
			printf("==========\n");
			printf("��ȣ�Է�: ");
			scanf("%d", &num);
			if(num==1)input(head[Tnum - 1]);
			else if (num == 2)cancel(head[Tnum - 1]);
			else if (num == 3)cancelAll(head[Tnum - 1]);
			else if (num == 4)break;
		}
	}
}