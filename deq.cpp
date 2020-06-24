#include "deq.h"
#include "utl.h"
#include <stdio.h>

// задание размера массива пользователем
void deq_set_size(s_deq* deq)
{
	do
	{
		printf("\nEnter deq size less than 10,000: ");
	} while (positive_int(&(deq->size)) > 10000);
}

// задание изначальных параметров
void deq_null(s_deq* deq)
{
	for (int i = 0; i < deq->size; i++)
		deq->arr[i] = 0;
	deq->count = deq->begin = deq->end = 0;
}

// очистка значений дека
void deq_clear(s_deq* deq)
{ 
	//for (int i = 0; i < deq->size; i++)
	//	deq->arr[i] = 0;
	deq->size = 0;
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
		return err(deq_overlow);
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
		return err(deq_overlow);
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
	if (deq_is_empty(deq))
		printf("deq is empty");
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
	if (deq_is_empty(deq))
		printf("deq is empty");
	return;
}