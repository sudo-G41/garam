#pragma once

typedef struct {
	int gn;            //n번째 물품
	int gnumber;      //등록번호
	char gname[20];      //물품이름
	long gprice;      //가격
	int gstock;         //재고수량
	char gcompany[20];   //회사이름
} GOODS;