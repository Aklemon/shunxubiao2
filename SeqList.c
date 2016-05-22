#include "SeqList.h" 

// 初始化顺序表 
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
//检查函数
void check(PSeqList pSeqList)
{
	if (pSeqList->size >= (pSeqList->Capacity))
	{
		pSeqList->seqlist = (DataType*)realloc(pSeqList->seqlist, (pSeqList->Capacity + ADDSIZE)*sizeof(DataType));
		pSeqList->Capacity =pSeqList->Capacity + ADDSIZE;

	}
	if (pSeqList->Capacity == 0)
	{
		perror("开辟失败");
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
//尾删	 
void PopBack(PSeqList pSeqList)
{
	assert(NULL != pSeqList);
	
	pSeqList->size--;
}
//打印顺序表 
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

//头插 
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

// 头删 
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
	//不仅要断言指针，还要考虑pos的位置当顺序表没有放满的时候它是 
	//可以在开头和末尾放入的,注意insert是任意位置 
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

// 在顺序表中查找元素data 
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

// 删除顺序表中pos位置上的元素 
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
//移除顺序表中的元素data 
void Remove(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	Erase(pSeqList, Find(pSeqList, data));
}

// 移除顺序表中所有元素data 
void RemoveAll(PSeqList pSeqList, DataType data)
{
	assert(NULL != pSeqList);
	int iIdx = 0;
	//遍历顺序表 遇到它就不输出 
	for (; iIdx < pSeqList->size; iIdx++)
	{
		if (pSeqList->seqlist[iIdx] == data)
		{
			Remove(pSeqList, data);
			iIdx--;
		}
	}

}

//冒泡排序
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

//二分查找
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






