#include "SeqList.h" 

void FunTest()
{
	//初始化 
	SeqList seqList;
	InitSeqList(&seqList);
	//尾插 
	PushBack(&seqList, 5);
	PushBack(&seqList, 4);
	PushBack(&seqList, 3);
	PushBack(&seqList, 2);
	PushBack(&seqList, 1);
	PrintfSeqList(&seqList);
	////尾删 
	//PopBack(&seqList);
	//PrintfSeqList(&seqList);

	//前插 
	PushFront(&seqList, 5);
	PrintfSeqList(&seqList);
	//////头删 
	//PopFront(&seqList);
	//PrintfSeqList(&seqList);
	////在任意位置插入 

	//Insert(&seqList, 3, 0);
	//PrintfSeqList(&seqList);
	//Insert(&seqList, 0, 0);
	//PrintfSeqList(&seqList);
	//Insert(&seqList, 6, 0);
	//PrintfSeqList(&seqList);

	////查找一个数 
	//if (-1 != Find(&seqList, 3))
	//{
	//	printf("3存在\n");
	//}
	//else

	//	printf("3不存在");


	////删除指定位置的数 
	//Erase(&seqList, 1);
	//PrintfSeqList(&seqList);
	////删除顺序表中的指定data 
	//Remove(&seqList, 4);
	//PrintfSeqList(&seqList);
	////删除所有的data 
	//RemoveAll(&seqList, 0);
	//PrintfSeqList(&seqList);
	//冒泡
	//Bubble_Sort(&seqList);
	//PrintfSeqList(&seqList);
	/*if (-1 != FindMid(&seqList, 6))
		{
			printf("6存在\n");
		}
		else

			printf("6不存在");
		*/
}

int main()
{
	FunTest();
	return 0;
}

