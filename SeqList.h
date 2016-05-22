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
#define  MAX_SIZE 10 //最大容量
#define MIN_SIZE  3 //最初容量
#define ADDSIZE 3//每次的增量

typedef struct  seqlist
{ 

	DataType*  seqlist; // 指向顺序表  
	int size;//当前存储了多少元素
	int Capacity;//当前存储空间的长度
}SeqList, *PSeqList;
 



// 初始化顺序表 
void InitSeqList();
//检查函数
void check(PSeqList pSeqList);

//尾插 
void PushBack(PSeqList pSeqList, DataType data);
////尾删 
void PopBack(PSeqList pSeqList);
//打印 
void PrintfSeqList(PSeqList pSeqList);
//头插 
void PushFront(PSeqList pSeqList, DataType data);
//头删 
void PopFront(PSeqList pSeqList);
// 任意位置插入 
void Insert(PSeqList pSeqList, int pos, DataType data);
// 在顺序表中查找元素data 
int Find(PSeqList pSeqList, DataType data);

// 删除顺序表中pos位置上的元素 
void Erase(PSeqList pSeqList, int pos);
//移除顺序表中的元素data 
void Remove(PSeqList pSeqList, DataType data);
// 移除顺序表中所有元素data 
void RemoveAll(PSeqList pSeqList, DataType data);
//冒泡排序
void Bubble_Sort(PSeqList pSeqList);
//二分查找
int FindMid(PSeqList pSeqList, DataType data);


#endif 
