#ifndef SEQLIST_H 
#define SEQLIST_H 
#include<assert.h> 
#include<string.h> 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define NULL_FAILURE 1
#define MAX_SIZE 10 
typedef int DataType;
typedef unsigned int size_t;
#define  MAX_SIZE 10 //�������
#define MIN_SIZE  3 //�������
#define ADDSIZE 3//ÿ�ε�����

typedef struct  seqlist
{ 

	DataType*  seqlist; // ָ��˳���  
	int size;//��ǰ�洢�˶���Ԫ��
	int Capacity;//��ǰ�洢�ռ�ĳ���
}SeqList, *PSeqList;
 



// ��ʼ��˳��� 
void InitSeqList();
//��麯��
void check(PSeqList pSeqList);

//β�� 
void PushBack(PSeqList pSeqList, DataType data);
////βɾ 
void PopBack(PSeqList pSeqList);
//��ӡ 
void PrintfSeqList(PSeqList pSeqList);
//ͷ�� 
void PushFront(PSeqList pSeqList, DataType data);
//ͷɾ 
void PopFront(PSeqList pSeqList);
// ����λ�ò��� 
void Insert(PSeqList pSeqList, int pos, DataType data);
// ��˳����в���Ԫ��data 
int Find(PSeqList pSeqList, DataType data);

// ɾ��˳�����posλ���ϵ�Ԫ�� 
void Erase(PSeqList pSeqList, int pos);
//�Ƴ�˳����е�Ԫ��data 
void Remove(PSeqList pSeqList, DataType data);
// �Ƴ�˳���������Ԫ��data 
void RemoveAll(PSeqList pSeqList, DataType data);
//ð������
void Bubble_Sort(PSeqList pSeqList);
//���ֲ���
int FindMid(PSeqList pSeqList, DataType data);


#endif 
