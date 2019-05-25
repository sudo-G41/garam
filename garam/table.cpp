#include "table.h"
#include "goods.h"
#define TRUE 1
#define FLASE 0
#define TABLESIZE 10

void input(HEAD*);
void tableList(HEAD*);
void cancel(HEAD*);

HEAD* createNode() {
	HEAD* head = (HEAD*)malloc(sizeof(HEAD));
	if (head == NULL) {
		printf("예외발생! 메모리가 부족합니다.\n");
		printf("시스템을 종료합니다.\n");
		system("pause");
		exit(1);
	}
	head->next = NULL;
	head->length = 0;
	head->pay = 0;
	return head;
}
void printTable(HEAD *head[]) {
	printf("=================================================================================\n");
	printf("| 1번테이블\t| 2번테이블\t| 3번테이블\t| 4번테이블\t| 5번테이블\t|\n");
	for (int i = 0; i < 5; i++) {
		if (head[i]->next == NULL) {
			printf("| 빈테이블\t");
		}
		else {
			printf("| 주문중 \t");
		}
	}
	printf("|\n=================================================================================\n");
	printf("| 6번테이블\t| 7번테이블\t| 8번테이블\t| 9번테이블\t| 10번테이블\t|\n");
	for (int i = 5; i < 10; i++) {
		if (head[i]->next == NULL) {
			printf("| 빈테이블\t");
		}
		else {
			printf("| 주문중 \t");
		}
	}
	printf("|\n=================================================================================\n");
}
void input(HEAD* head) {
	NODE* tmp;
	NODE* node = (NODE*)malloc(sizeof(NODE));
	FILE *fp;
	GOODS list;
	int get,count=0;

	if ((fp = fopen("product.txt", "r")) == NULL) { printf("파일을 불러올 수 없습니다."); }
	
	printf("=================================================\n");
	for(int i = 1; !feof(fp);i++) {
		fscanf(fp, "%d %s %d %s %d \n", &list.gn, list.gname, &list.gstock, list.gcompany, &list.gprice);
		printf("%d. %s\n", i,list.gname);
		count++;
	}
	printf("=================================================\n");
	fseek(fp, 0L, SEEK_SET);
	printf("상품번호를 입력해 주세요 : ");
	scanf("%d", &get);
	if (get < 1 || count < get) {
		printf("없는 상품입니다.\n");
		free(node);
		return;
	}
	for (int i = 0; i < get; i++) {
		fscanf(fp, "%d %s %d %s %d \n", &list.gn, list.gname, &list.gstock, list.gcompany, &list.gprice);
	}
	strcpy(node->gname, list.gname);
	printf("개수를 입력해 주세요 : ");
	scanf("%d", &node->count);

	fclose(fp);

	if (node->count < 1) {
		printf("잘못된 값입니다.\n");
		free(node);
		return;
	}

	head->pay += (list.gprice*node->count);
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
		printf("|%3d. %-20s %4d개 |\n", i++, tmp->gname, tmp->count);
	}
	printf("====================================\n");
}
void cancel(HEAD* head) {
	NODE*tmp = head->next;
	NODE*ptr;
	GOODS list;

	FILE *fp;
	int i;
	if (tmp == NULL) {
		printf("비어있습니다.\n");
		return;
	}
	printf("몇 번째 물품을 취소하시겠습니까? ");
	scanf("%d", &i);
	
	if (1>i||i > head->length) {
		printf("없는 번호입니다.\n");
		return;
	}

	if ((fp = fopen("product.txt", "r")) == NULL) { printf("파일을 불러올 수 없습니다."); }

	if (i == 1) {
		head->next = tmp->next;
		head->length--;
		while (!feof(fp)) {
			fscanf(fp, "%d %s %d %s %d \n", &list.gn, list.gname, &list.gstock, list.gcompany, &list.gprice);
			if (strcmp(list.gname, tmp->gname) == 0)break;
		}
		head->pay -= (list.gprice*tmp->count);
		free(tmp);
		return;
	}
	for (int x = 1; x < i; x++) {
		ptr = tmp;
		tmp = tmp->next;
	}
	ptr->next = tmp->next;
	head->length--;
	while (!feof(fp)) {
		fscanf(fp, "%d %s %d %s %d \n", &list.gn, list.gname, &list.gstock, list.gcompany, &list.gprice);
		if (strcmp(list.gname, tmp->gname) == 0)break;
	}
	head->pay -= (list.gprice*tmp->count);
	free(tmp);
	return;
}
void cancelAll(HEAD*head) {
	if (head->next == NULL) {
		printf("이미 비어있습니다.\n");
		return;
	}
	for (; head->next != NULL;) {
		NODE*ptr=head->next;
		head->next = ptr->next;
		free(ptr);
	}
	head->length = 0;
	head->pay=0;
}

void Tmain(HEAD*head[]) {
	int num,Tnum;

	printTable(head);

	printf("=============\n");
	printf("1.테이블 선택\n");
	printf("2.나가기\n");
	printf("=============\n");
	printf("번호입력: ");
	scanf("%d", &num);
	printf("\n");
	if (num == 1) {
		printf("몇번 테이블? : ");
		scanf("%d", &Tnum);
		while (true) {
			printf("%d번 테이블\n", Tnum);
			tableList(head[Tnum - 1]);
			printf("==========\n");
			printf("1.주문\n");
			printf("2.주문취소\n");
			printf("3.전체취소\n");
			printf("4.나가기\n");
			printf("==========\n");
			printf("번호입력: ");
			scanf("%d", &num);
			if(num==1)input(head[Tnum - 1]);
			else if (num == 2)cancel(head[Tnum - 1]);
			else if (num == 3)cancelAll(head[Tnum - 1]);
			else if (num == 4)break;
			//else if (num == 5)printf("%d원\n", head[Tnum - 1]->pay);
		}
	}
	else if (num == 2) { return; }
}