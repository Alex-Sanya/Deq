#ifndef _deq_H
#define _deq_H
#define _CRT_SECURE_NO_WARNINGS

#define deq_SIZE 8

// ��������� ����
typedef struct _s_deq
{
	int arr[deq_SIZE]; // ������ 
	int size, // ������ �������
		count, // ������� ����������� ����� �������
		begin, // ������ ������� ��������
		end; // ������ ���������� ��������
} s_deq;

#include "utl.h"

// ������� ����������� ����������
void deq_null(s_deq* deq);

// ������� �������� ����
void deq_clear(s_deq* deq);

// ��������: ��� ������
int deq_is_empty(s_deq* deq);

// ��������: ��� ��������
int deq_is_full(s_deq* deq);

// ����� ���� ��������� � ������
void deq_print_from_begin(s_deq* deq, int new_line);

// ����� ���� ��������� � �����
void deq_print_from_end(s_deq* deq, int new_line);

// �������� � �����
int deq_push_back(s_deq* deq, int n);

// �������� � ������
int deq_push_front(s_deq* deq, int n);

// ������� ��������� �������
int deq_pop_back(s_deq* deq);

// ������� ������ �������
int deq_pop_front(s_deq* deq);

#endif // _deq_H