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

// ����� ��������� �� ���� ������. ������ ���������� 0
int err(int);

// ���������� ���� ������ �����
int input_int(int* x);

// ���� �������������� �����
int positive_int(int *x);

// ������� �������
void print_comands();

// �������
int comands(char comand, s_deq* deq);

// ������� ������������
void demonstration(s_deq* deq);

#endif _UTL_H