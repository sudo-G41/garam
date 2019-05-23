//#include "table.h"
//#define TRUE 1
//#define FLASE 0
//#define TABLESIZE 10
//
//
//void printTable(HEAD*[]);
//void input(HEAD*);
//void tableList(HEAD*);
//void cancel(HEAD*);
//
//HEAD* createNode() {
//	HEAD* head = (HEAD*)malloc(sizeof(HEAD));
//	if (head == NULL) {
//		printf("예외발생! 메모리가 부족합니다.\n");
//		printf("시스템을 종료합니다.\n");
//		system("pause");
//		exit(1);
//	}
//	head->next = NULL;
//	head->length = 0;
//	return head;
//}
//void printTable(HEAD *head[]) {
//	printf("=================================================================================\n");
//	printf("| 1번테이블\t| 2번테이블\t| 3번테이블\t| 4번테이블\t| 5번테이블\t|\n");
//	for (int i = 0; i < 5; i++) {
//		if (head[i]->next == NULL) {
//			printf("| 빈테이블\t");
//		}
//		else {
//			printf("| 주문중 \t");
//		}
//	}
//	printf("|\n=================================================================================\n");
//	printf("| 6번테이블\t| 7번테이블\t| 8번테이블\t| 9번테이블\t| 10번테이블\t|\n");
//	for (int i = 5; i < 10; i++) {
//		if (head[i]->next == NULL) {
//			printf("| 빈테이블\t");
//		}
//		else {
//			printf("| 주문중 \t");
//		}
//	}
//	printf("|\n=================================================================================\n");
//}
//void input(HEAD* head) {
//	NODE* tmp;
//	NODE* node = (NODE*)malloc(sizeof(NODE));
//	printf("상품명을 입력해 주세요 : ");
//	scanf("%s", node->gname);
//	printf("개수를 입력해 주세요 : ");
//	scanf("%d", &node->count);
//	if (node->count < 1) {
//		printf("잘못된 값입니다.\n");
//		return;
//	}
//	if (head->next == NULL) {
//		node->next = head->next;
//		head->next = node;
//		head->length++;
//		return;
//	}
//	tmp = head->next;
//	for (; tmp->next != NULL; tmp = tmp->next) {
//		if (strcmp(tmp->gname, node->gname)==0) {
//			tmp->count += node->count;
//			return;
//		}
//	}
//	if (strcmp(tmp->gname, node->gname)==0) {
//		tmp->count += node->count;
//		free(node);
//		return;
//	}
//	else {
//		node->next = tmp->next;
//		tmp->next = node;
//		head->length++;
//		return;
//	}
//}
//void tableList(HEAD* head) {
//	int i = 1;
//	if (head->next == NULL)return;
//	NODE *tmp = head->next;
//	printf("====================================\n");
//	for (; tmp != NULL; tmp = tmp->next) {
//		printf("|%3d. %-20s %4d개 |\n", i++, tmp->gname, tmp->count);
//	}
//	printf("====================================\n");
//}
//void cancel(HEAD* head) {
//	NODE*tmp = head->next;
//	NODE*ptr;
//	int i;
//	if (tmp == NULL) {
//		printf("비어있습니다.\n");
//		return;
//	}
//	tableList(head);
//	printf("몇 번째 물품을 취소하시겠습니까? ");
//	scanf("%d", &i);
//	if (0>i||i > head->length) {
//		printf("없는 번호입니다.\n");
//		return;
//	}
//	if (i == 1) {
//		head->next = tmp->next;
//		head->length--;
//		free(tmp);
//		return;
//	}
//	for (int x = 1; x < i; x++) {
//		ptr = tmp;
//		tmp = tmp->next;
//	}
//	ptr->next = tmp->next;
//	head->length--;
//	free(tmp);
//	return;
//}
//void cancelAll(HEAD*head) {
//	if (head->next == NULL) {
//		printf("이미 비어있습니다.\n");
//		return;
//	}
//	for (; head->next != NULL;) {
//		NODE*ptr=head->next;
//		head->next = ptr->next;
//		free(ptr);
//	}
//	head->length = 0;
//}
//
//void Tmain() {
//	int num,Tnum;
//	static HEAD *head[10];
//	static int flag = FALSE;
//	if (flag==FLASE) {//처음 생성되었을 경우 초기화 시키기
//		for (int i = 0; i < TABLESIZE; i++) {
//			head[i] = createNode();
//		}
//		flag = TRUE;
//		printf("헤더 배열 초기화 실행\n");
//	}
//
//	printf("=============\n");
//	printf("1.테이블 확인\n");
//	printf("2.테이블 선택\n");
//	printf("3.종료\n");
//	printf("=============\n");
//	printf("번호입력: ");
//	scanf("%d", &num);
//	printf("\n");
//	if (num == 1)printTable(head);
//	else if (num == 2) {
//		printf("몇번 테이블? : ");
//		scanf("%d", &Tnum);
//		while (true) {
//			tableList(head[Tnum - 1]);
//			printf("==========\n");
//			printf("1.주문\n");
//			printf("2.주문취소\n");
//			printf("3.전체취소\n");
//			printf("4.나가기\n");
//			printf("==========\n");
//			printf("번호입력: ");
//			scanf("%d", &num);
//			if(num==1)input(head[Tnum - 1]);
//			else if (num == 2)cancel(head[Tnum - 1]);
//			else if (num == 3)cancelAll(head[Tnum - 1]);
//			else if (num == 4)break;
//		}
//	}
//	else if(num == 3){
//		for (int i = 0; i < TABLESIZE; i++) {
//			cancelAll(head[i]);
//			free(head[i]);
//		}
//		exit(0);
//	}
//}