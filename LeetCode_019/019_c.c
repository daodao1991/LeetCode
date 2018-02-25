#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*单链表的存储结构*/
typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node *next;
}Node;

/*尾插法创建单链表*/
Node* CreateLinkedList(Datatype a[], int n)
{
	Node *s = NULL, *r = NULL;
	Node *first = (Node*)malloc(sizeof(Node));
	r = first;

	for (int i = 0; i < n; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = a[i];
		r->next = s; r = s;
	}
	r->next = NULL;

	return first;
}

/*遍历单链表*/
void PrintLinkedList(Node *first)
{
	Node *p = first->next;
	while (p->next)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("%d", p->data);
}



Node* RemoveNthFromEnd(Node *first, int n)
{
	if (!first->next) return NULL;
	
	Node *pre = first, *cur = first;
	for (int i = 0; i < n; i++)
	{
		cur = cur->next;
	}
	if (!cur)  return first->next;

	while (cur->next)
	{
		cur = cur->next;
		pre = pre->next;
	}
	pre->next = pre->next->next;

	return first;

}



int main()
{
	int aa;
	int array[5] = { 1,2,3,4,5 };
	Node *f = NULL;

	f = CreateLinkedList(array, 5);
	printf("当前单链表的数据为：");
	PrintLinkedList(f);

	printf("\n\n");
	printf("请输入要删除的元素位置（倒着数）：");
	scanf("%d", &aa);

	printf("\n");

	RemoveNthFromEnd(f, aa);
	PrintLinkedList(f);
	printf("\n");

	system("pause");
	return 0;
}