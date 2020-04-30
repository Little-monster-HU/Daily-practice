
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef int HpDataType;
typedef struct heap
{
	HpDataType * arr;
	int capacity;//��ǰ������Ԫ�ظ���
	int size;//��ǰ��������ЧԪ�ظ���

}heap;

void Adjust(heap *hp, int size)
{
	int parent = 0;
	int child = 2 * parent + 1;
	HpDataType temp;
	while (child<hp->size)
	{
		//�����Һ�������С�ĺ���
		if (child + 1<hp->size&&hp->arr[child]>hp->arr[child + 1])
		{
			child += 1;
		}

		if (hp->arr[parent]>hp->arr[child])
		{
			//����������
			temp = hp->arr[parent];
			hp->arr[parent] = hp->arr[child];
			hp->arr[child] = temp;
			parent = child;
			child = 2 * child + 1;
		}

		else
			return;
	}
}


void HeapCreate(heap *hp, HpDataType arr[10], int size)//�ѵĴ���
{

	assert(hp);//����ɳ�ʼ���������ڴ�Ŀ��٣����ݵĳ�ʼ���ȵȡ�
	hp->arr = (HpDataType*)malloc(sizeof(HpDataType)*size);
	if (hp->arr == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
	}
	memcpy(hp->arr, arr, sizeof(HpDataType)*size);
	hp->capacity = size;
	hp->size = size;
	//����С��

	Adjust(hp, size);
}
void Heapdestry(heap *hp)//�ѵ�����
{
	assert(hp);
	if (hp == NULL)
	{
		return;
	}
	hp->size = 0;
	hp->capacity = 0;
	//free(hp);
	//hp->arr=NULL;
	printf("���ٳɹ���\n");

}
void AddData(HpDataType ret, heap *hp)
{
	int i = 0;
	assert(hp);
	//�ȼӽ�ȥ
	for (i = hp->size; i>0; i--)
	{
		hp->arr[i] = hp->arr[i - 1];
	}
	hp->arr[i] = ret;
	hp->size += 1;
	//Ȼ�����
	Adjust(hp, hp->size);

}
void Addcatacity(heap *hp)//����
{
	HpDataType* p = NULL;
	assert(hp);
	p = (HpDataType*)realloc(hp->arr, sizeof(HpDataType)*hp->size + 2);
	if (p == NULL)
	{
		printf("����ʧ�ܣ�\n");
		return;
	}
	hp->arr = p;
	hp->capacity = hp->size + 2;

}

void Heapinsert(HpDataType ret, heap *hp)//�ѵĲ�������,������ɣ���Ȼ����
{
	assert(hp);
	//�Ƿ���������
	if (hp->capacity == hp->size)
	{
		//���ˣ�����
		Addcatacity(hp);

	}

	//û����ֱ�Ӽ�
	AddData(ret, hp);

}
void Heapafterdelete(heap * hp)//�ѵ����һ��Ԫ�ص�ɾ��
{
	assert(hp);
	//�п�
	if (hp->size == 0)
	{
		return;
	}
	//free();
	hp->size -= 1;
}
void Heapfrontdelete(heap * hp)//�Ѷ�Ԫ�ص�ɾ��
{
	int i = 0;
	HpDataType ret;
	assert(hp);
	//�п�
	if (hp->size == 0)
	{
		return;
	}
	//�ѶѶ�Ԫ�غ����һ��Ԫ�ؽ���
	ret = hp->arr[0];
	hp->arr[0] = hp->arr[hp->size - 1];
	hp->arr[hp->size - 1] = ret;
	Heapafterdelete(hp);
	Adjust(hp, hp->size);

}
HpDataType HeapTop(heap *hp)//�Ѷ�Ԫ�صĻ�ȡ
{

	assert(hp);
	//�п�
	if (hp->size == 0)
	{
		return;
	}
	else
		return hp->arr[0];
}
int HeapEmpty(heap *hp)//�����Ƿ�Ϊ��
{
	assert(hp);
	return (hp->arr[0] == 0);
}
int HeapSize(heap *hp)//��ȡ������ЧԪ�صĸ���
{
	assert(hp);
	return hp->size;
}
void HeapPrint(heap *hp)//��ӡ����
{
	int i = 0;
	assert(hp);
	if (hp->size == 0)
	{
		return;
	}
	for (i = 0; i<hp->size; i++)
	{
		printf("%d ", hp->arr[i]);
	}
	printf("\n");
}
void TEST()
{
	heap h;
	HpDataType arr[10] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };

	HeapCreate(&h, arr, 10);//�ѵĴ���
	HeapPrint(&h);//��ӡ
	Heapinsert(23, &h);//��������
	HeapPrint(&h);//��ӡ
	Heapinsert(17, &h);//��������
	HeapPrint(&h);//��ӡ
	printf("�Ѷ���Ԫ���� %d \n", HeapTop(&h));
	Heapfrontdelete(&h);
	HeapPrint(&h);
	Heapafterdelete(&h);
	HeapPrint(&h);
	printf("���е�Ԫ�ظ���Ϊ�� %d\n", HeapSize(&h));
	Heapdestry(&h);

}