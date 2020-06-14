#include "deq.h"
#include <stdio.h>
#include <Windows.h>

// пишет сообщение по коду ошибки
int err(int type)
{
	switch (type)
	{
	case INCORRECT_VALUE:
		printf("\nIncorrect value!\n");
		break;
	case deq_IS_EMPTY:
		printf("\ndeq is empty.\n");
		break;
	case deq_IS_FULL:
		printf("\ndeq is full.\n");
		break;
	case deq_OVERFLOW:
		printf("\ndeq overflow.\n");
		break;
	default:
		break;
	};
	system("pause");
	return 0;
}

// проверка на целочисоенность ввода
int input_int(int* n)
{
	int check = 0;
	while (!check)
	{
		check = scanf("%d", n);
		if (!check)
			printf("\nIncorrect input. Try again: ");
		fflush(stdin);
	}
	return *n;
}

// вывести команды
void print_comands()
{
	printf("input command:\n\n");
	printf("exit programm------0\n");
	printf("clear deq----------1\n");
	printf("add new in begin---2\n");
	printf("add new in end-----3\n");
	printf("delete in begin----4\n");
	printf("delete in end------5\n");
	printf("print from begin---6\n");
	printf("print from end-----7\n");
}

// команды
int comands(char comand, s_deq* deq)
{
	int n = 0;
	switch (comand - '0')
	{
	case 0:
		printf("\nprogram is over");
		return 0;
	case 1:
		deq_clear(deq);
		break;
	case 2:
		printf("\nInput integer number: ");
		input_int(&n);
		deq_push_front(deq, n);
		break;
	case 3:
		printf("\nInput integer number: ");
		input_int(&n);
		deq_push_back(deq, n);
		break;
	case 4:
		deq_pop_front(deq);
		break;
	case 5:
		deq_pop_back(deq);
		break;
	case 6:
		printf("\ndeq from begin: ");
		deq_print_from_begin(deq, 1);
		break;
	case 7:
		printf("\ndeq from end: ");
		deq_print_from_end(deq, 1);
		break;
	default:
		break;
	};
	return 1;
}

// процесс демонстрации
void demonstration(s_deq* deq)
{
	print_comands();
	char comand = 0;
	while (comand != ESC)
	{
		system("cls");
		print_comands();
		if (!deq_is_empty(deq))
			deq_print_from_begin(deq, 1);
		printf("\ncomand: %c", comand);
		if (!comands(comand, deq))
			break;
		printf("\ninput comand: ");
		while (!_kbhit());
		comand = _getch();
	}
}