#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "deq.h"
#include "utl.h"

#define ESC 27

void main()
{
	s_deq deq = { {0,},0,0,0,0};
	demonstration(&deq);
	printf("\n\n");
	system("pause");
}