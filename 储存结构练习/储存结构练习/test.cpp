#include<iostream>
#define N 100
#include<assert.h>
typedef int SeDataType;

typedef struct SeqList
{
	SeDataType array[N];
	size_t size;

}SeqList;

typedef struct SeqList
{
	SeDataType* array;
	size_t size;
	size_t capicity;
}SeqList;



void SeqListInit(SeqList ps)
{
	assert(ps);
	ps->_array = (DataType*)malloc(sizeof(DataType)* 6);
	if (ps->_array == NULL)
	{
		printf("��ʼ��δ�ɹ�!\n");
		assert(0);
		return;
	}
	ps->_capacity = 6;
	ps->_size = 0;
}
int check_Capacity(SeqList ps)
{
	if (ps->_size == ps->_capacity)
	{
		DataType*ret = NULL;
		//��Ҫ����
		//realloc(ps->_array,2*sizeof(DataType)*ps->_capacity);
		ret = (DataType*)malloc(2 * sizeof(DataType)*(ps->_capacity));
		if (ret == NULL)
		{
			printf("����ʧ�ܣ�\n");
			assert(0);
			return -1;
		}
		//ret=ps->_array;
		memcpy(ret, ps->_array, sizeof(DataType)*ps->_size);
		ps->_array = ret;
		ps->_capacity = 2 * ps->_capacity;
		printf("���ݳɹ���\n");
		return 1;
	}
	return 0;
}
void SeqListDestroy(SeqList ps)
{
	assert(ps);
	free(ps->_array);
	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

// β�� 
void SeqListPushBack(SeqList ps, DataType data)
{
	assert(ps);
	SeqListInsert(ps, ps->_size, data);
}
// βɾ 
void SeqListPopBack(SeqList ps)
{
	assert(ps);
	SeqListErase(ps, ps->_size - 1);
}
// ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data)
{
	assert(ps);
	SeqListInsert(ps, 0, data);
}
// ͷɾ 
void SeqListPopFront(PSeqList ps)
{
	assert(ps);
	SeqListErase(ps, 0);
}

// ����λ�ò��� 
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	int i = 0;
	assert(ps);
	if (check_Capacity(ps) >= 0)
	{
		if (pos<0 && (pos>ps->_size))
		{
			printf("��λ�÷Ƿ����޷����룡\n");
			return;
		}
		else
		{
			for (i = ps->_size; i >= pos; i--)
			{
				ps->_array[i] = ps->_array[i - 1];
			}
			ps->_array[pos] = data;
			ps->_size++;
		}

	}
}

// ����λ��ɾ�� 
void SeqListErase(PSeqList ps, int pos)
{
	int i = 0;
	assert(ps);
	if (pos<0 && pos >= ps->_size)
	{
		printf("���λ��û��Ԫ�أ��޷�ɾ����\n");
		return;
	}
	if (ps->_size == 0)
	{
		printf("û��Ԫ�ؿ���ɾ����\n");
		return;
	}
	for (i = pos; i<ps->_size - 1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;

}

// ���data�Ƿ����˳����� 
int SeqListFind(PSeqList ps, DataType data)
{
	int i = 0;
	assert(ps);
	for (i = 0; i<ps->_size; i++)
	{
		if (ps->_array[i] == data)
			return i;
	}
	return -1;
}

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList ps, DataType data)
{
	int i = 0;
	assert(ps);
	for (i = 0; i<ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			SeqListErase(ps, i);
			return;
		}
	}
}

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data)
{
	int i = 0;
	assert(ps);
	for (i = 0; i<ps->_size; i++)
	{
		if (ps->_array[i] == data)
		{
			SeqListErase(ps, i);
		}
	}
	return;
}

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList ps)
{
	assert(ps);
	return ps->_capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList ps)
{
	assert(ps);
	return ps->_size;
}

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList ps)
{
	assert(ps);
	return ps->_array[0];
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];
}

void PrintSeqList(PSeqList ps)
{
	int i = 0;
	assert(ps);
	for (i = 0; i<ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}