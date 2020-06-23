#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "deq.h"
#include "utl.h"

#define ESC 27

int main()//спросить у пользователя длинну
{
	s_deq deq;
	positive_int(&deq.size);
	printf("%d", deq.size);
	deq_null(&deq);
	demonstration(&deq);
	printf("\n\n");
	system("pause");
	return 0;
}