#include "SeqList.h" 

void FunTest()
{
	//��ʼ�� 
	SeqList seqList;
	InitSeqList(&seqList);
	//β�� 
	PushBack(&seqList, 5);
	PushBack(&seqList, 4);
	PushBack(&seqList, 3);
	PushBack(&seqList, 2);
	PushBack(&seqList, 1);
	PrintfSeqList(&seqList);
	////βɾ 
	//PopBack(&seqList);
	//PrintfSeqList(&seqList);

	//ǰ�� 
	PushFront(&seqList, 5);
	PrintfSeqList(&seqList);
	//////ͷɾ 
	//PopFront(&seqList);
	//PrintfSeqList(&seqList);
	////������λ�ò��� 

	//Insert(&seqList, 3, 0);
	//PrintfSeqList(&seqList);
	//Insert(&seqList, 0, 0);
	//PrintfSeqList(&seqList);
	//Insert(&seqList, 6, 0);
	//PrintfSeqList(&seqList);

	////����һ���� 
	//if (-1 != Find(&seqList, 3))
	//{
	//	printf("3����\n");
	//}
	//else

	//	printf("3������");


	////ɾ��ָ��λ�õ��� 
	//Erase(&seqList, 1);
	//PrintfSeqList(&seqList);
	////ɾ��˳����е�ָ��data 
	//Remove(&seqList, 4);
	//PrintfSeqList(&seqList);
	////ɾ�����е�data 
	//RemoveAll(&seqList, 0);
	//PrintfSeqList(&seqList);
	//ð��
	//Bubble_Sort(&seqList);
	//PrintfSeqList(&seqList);
	/*if (-1 != FindMid(&seqList, 6))
		{
			printf("6����\n");
		}
		else

			printf("6������");
		*/
}

int main()
{
	FunTest();
	return 0;
}

