#ifndef _deq_H
#define _deq_H
#define _CRT_SECURE_NO_WARNINGS

#define deq_SIZE 8

// структура дека
typedef struct _s_deq
{
	int arr[deq_SIZE]; // массив 
	int size, // размер массива
		count, // счЄтчик заполненных €чеек массива
		begin, // индекс первого элемента
		end; // индекс последнего элемента
} s_deq;

#include "utl.h"

// задание изначальных параметров
void deq_null(s_deq* deq);

// очистка значений дека
void deq_clear(s_deq* deq);

// проверка: дек пустой
int deq_is_empty(s_deq* deq);

// проверка: дек заполнен
int deq_is_full(s_deq* deq);

// вывод всех элементов с начала
void deq_print_from_begin(s_deq* deq, int new_line);

// вывод всех элементов с конца
void deq_print_from_end(s_deq* deq, int new_line);

// добавить в конец
int deq_push_back(s_deq* deq, int n);

// добавить в начало
int deq_push_front(s_deq* deq, int n);

// удалить последний элемент
int deq_pop_back(s_deq* deq);

// удалить первый элемент
int deq_pop_front(s_deq* deq);

#endif // _deq_H