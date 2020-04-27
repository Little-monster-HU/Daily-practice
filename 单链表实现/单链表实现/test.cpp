#define _CRT_SECURE_NO_WARNINGS 1


#include "Slist.h"

void SListInit(SList* pl)
{
	assert(pl);
	//pl=(SList*)malloc(sizeof(Node));
	pl->_pHead = NULL;
}
// ��������β��ֵΪdata�Ľڵ� 
Node* SetNode(SDataType data)//����һ���½ڵ�
{
	Node*NewSlist = NULL;
	NewSlist = (Node*)malloc(sizeof(Node));
	if (NewSlist == NULL)
	{
		assert(NewSlist);
		return NULL;
	}

	NewSlist->_data = data;
	NewSlist->_pNext = NULL;
	return NewSlist;
}
void SListPushBack(SList* pl, SDataType data)//β��һ���ڵ�
{

	Node*NewSlist = SetNode(data);
	Node*RetSlist = pl->_pHead;
	assert(pl);
	if (pl->_pHead == NULL)
	{
		pl->_pHead = NewSlist;
	}
	else
	{
		while (RetSlist->_pNext)
		{
			RetSlist = RetSlist->_pNext;
		}
		RetSlist->_pNext = NewSlist;
	}
}

// ɾ���������һ���ڵ� 
void SListPopBack(SList* pl)
{
	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	while (ret->_pNext->_pNext)
	{
		ret = ret->_pNext;
	}
	free(ret->_pNext);
	ret->_pNext = NULL;
	printf("ɾ���ɹ���\n");
}

// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
void SListPushFront(SList* pl, SDataType data)
{
	Node* ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	pl->_pHead = SetNode(data);
	pl->_pHead->_pNext = ret;
	//free(ret);
	//ret=NULL;
}
// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* pl)
{
	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	pl->_pHead = ret->_pNext;
	free(ret);
}

// ������posλ�ú����ֵΪdata�Ľڵ� 
void SListInsertAfter(SList* pl, Node* pos, SDataType data)
{
	Node*ret = NULL;
	Node* New = NULL;
	assert(pl);
	ret = pl->_pHead;
	New = SetNode(data);
	while (ret != pos)
	{
		ret = ret->_pNext;
	}
	New->_pNext = ret->_pNext;
	ret->_pNext = New;

}

// ɾ��������posλ�õĽڵ�
void SListErase(SList* pl, Node* pos)
{
	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	if (pl->_pHead == NULL)
	{
		printf("�������Ѿ�Ϊ�գ��޷�ɾ��\n");
	}
	else if (pl->_pHead->_pNext == NULL)
	{
		if (pl->_pHead == pos)
		{
			free(pl->_pHead);
			pl->_pHead = NULL;
		}
		else
		{
			printf("λ����Ч���޷�ɾ����\n");
		}
	}
	else
	{
		//��һ�����ϵĽڵ�
		while (ret->_pNext != pos)
		{
			ret = ret->_pNext;
		}
		ret->_pNext = pos->_pNext;
		free(pos);
		pos = NULL;
	}
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* pl, SDataType data)
{
	Node* ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	while ((ret != NULL) && (ret->_data != data))
	{
		ret = ret->_pNext;
	}
	return ret;
}

// �������� 
void SListDestroy(SList* pl)
{
	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	pl->_pHead = NULL;
	free(ret);
	ret = NULL;
	printf("��������ɹ���\n");
}

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* pl)
{
	int count = 0;
	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	while (ret)
	{
		count += 1;
		ret = ret->_pNext;
	}
	printf("��ЧԪ�صĸ���Ϊ��");
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* pl)
{
	assert(pl);
	printf("����1 Ϊ�գ�����0��Ϊ��,����ֵΪ��");
	return (NULL == pl->_pHead);//����1 Ϊ�գ�����0��Ϊ��
}
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* pl)
{
	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	return ret;

}

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* pl)
{
	Node* ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	return ret->_pNext;
}
void PrintSlist(SList* pl)
{

	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	while (ret)
	{
		printf("%d->", ret->_data);
		ret = ret->_pNext;
	}
	printf("NULL\n");
}

void SListRemove(SList* pl, SDataType data)//�Ƴ���һ��ֵΪdata�Ľڵ�
{
	Node*ret = NULL;
	assert(pl);
	ret = pl->_pHead;
	if (ret->_data == data)//��һ��
	{
		SListPopFront(pl);
	}
	else
	{
		while (ret->_pNext != NULL)//��һ�������һ��֮���Ԫ��
		{
			if (ret->_pNext->_data == data)
			{
				SListErase(pl, ret->_pNext);
			}
			else
			{
				ret = ret->_pNext;
			}
		}
		if (ret->_data == data)//���һ��
		{
			SListPopBack(pl);
		}
	}
}
/*Node* ret=NULL;
Node* ret2=NULL;
assert(pl);
ret=pl->_pHead;
if(ret==NULL)
{
printf("ɾ���ɹ���\n");
}
else
{
if(ret->_data==data)
{
pl->_pHead=ret->_pNext;
printf("ɾ���ɹ���\n");
free(ret);
ret=NULL;
}
else
{
SListRemove(ret->_pNext,data);
}*/
//}
//}

//while((ret!=NULL)&&(ret->_data!=data))//2 0 1 4
//{
//	ret2=ret;
//	ret=ret->_pNext;
//	
//}
//if(ret==NULL)
//{
//	return;
//}
//else
//{
//  ret2->_pNext=ret->_pNext;
//  //ret->_pNext=ret2->_pNext;
//  free(ret);
//  ret=NULL;

void SListRemoveAll(SList* pl, SDataType data)
{
	Node* head = NULL;
	Node* next = NULL;
	assert(pl);
	head = pl->_pHead;
	while (head->_pNext)
	{
		if (head->_pNext->_data == data)
		{
			next = head->_pNext;
			head->_pNext = head->_pNext->_pNext;
			free(next);

		}
		else
		{
			head = head->_pNext;
		}
	}
	if (head->_pNext == NULL&&head->_data == data)
	{
		SListPopBack(pl);
	}
	if (pl->_pHead->_data == data)
	{
		SListPopFront(pl);

	}
}


//���ҵ�һ��֮��ɾ������ڵ㣬Ȼ�������ڵ��������

//Node*ret=NULL;
//Node* freelist=NULL;
//assert(pl);
//ret=pl->_pHead;
//if(ret==NULL)
//{
//	printf("û��Ԫ�ؿ���ɾ��\n");
//}
//else if(ret->_pNext==NULL&&ret->_data==data)
//{

//	free(ret);
//	ret=NULL;
//}
//else
//{
//	while(ret)
//	{
//		if(ret->_data==data)
//		{
//			SListErase(pl,ret);
//			continue;
//                /*freelist=ret->_pNext; 
//			 ret->_pNext=freelist->_pNext;
//			 free(freelist);
//			 freelist=NULL;*/
//		}
//		ret=ret->_pNext;
//	}
//}

//}
void TEST1(SList* pl)
{
	SListInit(pl);
	SListPushBack(pl, 1);
	SListPushBack(pl, 2);
	SListPushBack(pl, 3);
	SListPushBack(pl, 4);
	SListPushBack(pl, 5);
	PrintSlist(pl);
	SListPopBack(pl);
	PrintSlist(pl);

	// �������һ��Ԫ��ǰ����ֵΪdata�Ľڵ� 
	SListPushFront(pl, 0);
	SListPushFront(pl, 3);
	SListPushFront(pl, 2);
	SListPushFront(pl, 3);

	PrintSlist(pl);
	// ɾ�������е�һ���ڵ� 
	SListPopFront(pl);
	PrintSlist(pl);

	// ������posλ�ú����ֵΪdata�Ľڵ� 
	SListInsertAfter(pl, pl->_pHead->_pNext->_pNext, 9);
	PrintSlist(pl);

	// ɾ��������posλ�õĽڵ�
	SListErase(pl, pl->_pHead->_pNext->_pNext);
	PrintSlist(pl);
	SListRemove(pl, 2);//�Ƴ���һ��ֵΪdata�Ľڵ�
	PrintSlist(pl);
	SListRemoveAll(pl, 3);
	PrintSlist(pl);

	printf("%d \n", SListBack(pl));
	//PrintSlist(pl);

	printf("%d \n", SListFront(pl));
	//PrintSlist(pl);



	// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
	SListFind(pl, 2);



	// ��ȡ��������Ч�ڵ�ĸ��� 
	printf("%d \n", SListSize(pl));


	// ��������Ƿ�Ϊ�� 
	printf("%d \n", SListEmpty(pl));


	// �������� 
	SListDestroy(pl);

}