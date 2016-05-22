#include "SeqList.h" 

// ��ʼ��˳��� 
void InitSeqList(PSeqList seqList)
{
	seqList->size = 0;
	seqList->seqlist = (DataType*)malloc(MIN_SIZE*sizeof(DataType));
	if (NULL == seqList->seqlist)
	{
		printf("out of memory");
		exit(NULL_FAILURE);
	}
	memset(seqList->seqlist, 0, MIN_SIZE*sizeof(DataType));
	seqList->Capacity = MIN_SIZE;
}
//��麯��
void check(PSeqList pSeqList)
{
	if (pSeqList->size >= (pSeqList->Capacity))
	{
		pSeqList->seqlist = (DataType*)realloc(pSeqList->seqlist, (pSeqList->Capacity + ADDSIZE)*sizeof(DataType));
		pSeqList->Capacity =pSeqList->Capacity + ADDSIZE;

	}
	if (pSeqList->Capacity == 0)
	{
		perror("����ʧ��");
		exit(NULL_FAILURE);
	}
}
void PushBack(PSeqList pSeqList, DataType data)
{
	check(pSeqList);
	assert(NULL != pSeqList);
	int size = pSeqList->size;
	pSeqList->seqlist[size] = data;
	pSeqList->size++;
}
//βɾ	 
void PopBack(PSeqList pSeqList)
{
	assert(NULL != pSeqList);
	
	pSeqList->size--;
}
//��ӡ˳��� 
void PrintfSeqList(PSeqList pSeqList)
{
	
	if (NULL == pSeqList)
		return;

	for (size_t i = 0; i < pSeqList->size; i++)
	{
		printf("%d ", pSeqList->seqlist[i]);

	}
    printf("\n");
}

//ͷ�� 
void PushFront(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	check(pSeqList);
	int size = pSeqList->size;
	int i = size ;
	for (i = size; i >=0; i--)
	{
		pSeqList->seqlist [i]= pSeqList->seqlist[i- 1];
	}
	pSeqList->seqlist[0] = data;
	/*Insert(pSeqList, 0, data);*/
	pSeqList->size++;
}

// ͷɾ 
void PopFront(PSeqList pSeqList)
{
	assert(NULL != pSeqList);
	if (pSeqList->size <= 0)
	{
		return;
	}
	int iIdx = 1;
	for (; iIdx <pSeqList->size; iIdx++)
	{
		pSeqList->seqlist[iIdx - 1] = pSeqList->seqlist[iIdx];
	}
	pSeqList->size--;
}

void Insert(PSeqList pSeqList, int pos, DataType data)
{
	//����Ҫ����ָ�룬��Ҫ����pos��λ�õ�˳���û�з�����ʱ������ 
	//�����ڿ�ͷ��ĩβ�����,ע��insert������λ�� 
	//assert(NULL != pSeqList); 

	assert(NULL != pSeqList);
	assert(pos >= 0 && pos <= pSeqList->size);
	if (pSeqList->size >= MAX_SIZE)
	{
		return;
	}
	int iIdx = pSeqList->size;
	for (; iIdx >pos; iIdx--)
	{
		pSeqList->seqlist[iIdx] = pSeqList->seqlist[iIdx - 1];
	}
	pSeqList->seqlist[pos] = data;
	pSeqList->size++;
}

// ��˳����в���Ԫ��data 
int Find(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	int iIdx = 0;
	for (; iIdx < pSeqList->size; iIdx++)
	{
		if (pSeqList->seqlist[iIdx] == data)
		{
			return iIdx;
		}
	}

	return -1;

}

// ɾ��˳�����posλ���ϵ�Ԫ�� 
void Erase(PSeqList pSeqList, int pos)
{
	assert(NULL != pSeqList && (pos >= 0 && pos <= pSeqList->size));
	if (pSeqList->size >= MAX_SIZE)
	{
		return;
	}
	int iIdx = pos;
	for (; iIdx <pSeqList->size; iIdx++)
	{
		pSeqList->seqlist[iIdx] = pSeqList->seqlist[iIdx + 1];
	}

	pSeqList->size--;
}
//�Ƴ�˳����е�Ԫ��data 
void Remove(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	Erase(pSeqList, Find(pSeqList, data));
}

// �Ƴ�˳���������Ԫ��data 
void RemoveAll(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	int iIdx = 0;
	//����˳��� �������Ͳ���� 
	for (; iIdx < pSeqList->size; iIdx++)
	{
		if (pSeqList->seqlist[iIdx] == data)
		{
			Remove(pSeqList, data);
			iIdx--;
		}
	}

}

//ð������
void Bubble_Sort(PSeqList pSeqList)
{
	int i = 0;
	int j = 0;
	//int flag = 0;
	int tmp = 0;
	assert(pSeqList);
	for (i=0; i < (pSeqList->size)-1; i++)
	{
		//flag = 0;
		for (j=0; j < (pSeqList->size) - i-1 ; j++)
		{
			if (pSeqList->seqlist[j]>pSeqList->seqlist[j + 1])
			{
				tmp = pSeqList->seqlist[j];
				pSeqList->seqlist[j] = pSeqList->seqlist[j + 1];
				pSeqList->seqlist[j + 1] = tmp;
				//int flag = 1;
			}
		}
		//if (flag == 0)
		//{
			//break;
		//}
	}

}

//���ֲ���
int FindMid(PSeqList pSeqList, DataType data)
{
	int left = 0;
	//int right =0;
	int mid = 0;
	assert(pSeqList);
	int right = pSeqList->size;
	while (left < right)
	{
		mid = left + right / 2;
		if (data == pSeqList->seqlist[mid])
		{
			return mid;
		}
		else if(pSeqList->seqlist[mid] < data)
		{
			left = left + 1;
		}
		else
		{
			right = mid;
		}
   }
	return -1;
}






