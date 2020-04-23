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