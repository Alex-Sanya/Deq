#ifndef _UTL_H
#define _UTL_H
#define _CRT_SECURE_NO_WARNINGS

#include "deq.h"
#include <conio.h>

#define deq_overlow -1
#define deq_IS_EMPTY 1
#define deq_IS_FULL 2
#define INCORRECT_VALUE 3
#define NOT_POSITIVE 4
#define MORE_THAN_MAXIMUM 5
#define ESC 27

// пишет сообщение по коду ошибки. всегда возвращает 0
int err(int);

// корректный ввод целого числа
int input_int(int* x);

// ввод положительного числа
int positive_int(int *x);

// вывести команды
void print_comands();

// команды
int comands(char comand, s_deq* deq);

// процесс демонстрации
void demonstration(s_deq* deq);

#endif _UTL_H