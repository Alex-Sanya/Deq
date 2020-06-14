#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define deq_SIZE 8
#define deq_OVERFLOW -1
#define deq_IS_EMPTY 1
#define deq_IS_FULL 2
#define INCORRECT_VALUE 3
#define ESC 27

// структура дека
typedef struct _s_deq
{
	int arr[deq_SIZE]; // массив 
	int size,  // размер массива
		count, // счЄтчик заполненных €чеек массива
		begin, // индекс первого элемента
		end;   // индекс последнего элемента
} s_deq;

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

// задание изначальных параметров
void deq_null(s_deq* deq)
{
	deq->size = deq_SIZE;
	for (int i = 0; i < deq->size; i++)
		deq->arr[i] = 0;
	deq->count = deq->begin = deq->end = 0;
}

// очистка значений дека
void deq_clear(s_deq* deq)
{
	deq->size = deq_SIZE; 
	for (int i = 0; i < deq->size; i++)
		deq->arr[i] = 0;
	deq->count = deq->begin = deq->end = 0;
}

// проверка: дек пустой
int deq_is_empty(s_deq* deq)
{
	if (!deq->count)
		return 1;
	return 0;
}

// проверка: дек заполнен
int deq_is_full(s_deq* deq)
{
	if (deq->count >= deq->size)
		return 1;
	return 0;
}

// добавить в конец
int deq_push_back(s_deq* deq, int n)
{
	if (deq->count >= deq->size)
		return err(deq_OVERFLOW);
	if (!deq_is_empty(deq))
		deq->end = (deq->end + 1) % deq->size;
	deq->count++;
	deq->arr[deq->end] = n;
	return 1;
}

// добавить в начало
int deq_push_front(s_deq* deq, int n)
{
	if (deq->count >= deq->size)
		return err(deq_OVERFLOW);
	if (!deq_is_empty(deq))
		deq->begin = (deq->begin + deq->size - 1) % deq->size;
	deq->count++;
	deq->arr[deq->begin] = n;
	return 1;
}

// удалить последний элемент
int deq_pop_back(s_deq* deq)
{
	if (deq_is_empty(deq))
		return err(deq_IS_EMPTY);
	deq->count--;
	if (!deq_is_empty(deq))
		deq->end = (deq->end + deq->size - 1) % deq->size;
	return 1;
}

// удалить первый элемент
int deq_pop_front(s_deq* deq)
{
	if (deq_is_empty(deq))
		return err(deq_IS_EMPTY);
	deq->count--;
	if (!deq_is_empty(deq))
		deq->begin = (deq->begin + 1) % deq->size;
	return 1;
}

// вывод всех элементов с начала
void deq_print_from_begin(s_deq* deq, int new_line)
{
	if (new_line)
		printf("\n");
	for (int i = deq->begin; deq->count > 0; i = (i + 1) % deq->size)
	{
		printf("%d ", deq->arr[i]);
		if (i == deq->end)
			break;
	}
	return;
}

// вывод всех элементов с конца
void deq_print_from_end(s_deq* deq, int new_line)
{
	if (new_line)
		printf("\n");
	for (int i = deq->end; deq->count > 0; i = (i + deq->size - 1) % deq->size)
	{
		printf("%d ", deq->arr[i]);
		if (i == deq->begin)
			break;
	}
	return;
}

// корректный ввод целого числа
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

int main()
{
	s_deq deq;
	deq_null(&deq);
	demonstration(&deq);
	printf("\n\n");
	system("pause");
	return 0;
}