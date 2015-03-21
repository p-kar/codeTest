#include "llist.h"

#include <stdio.h>
#include <stdlib.h>

llist createLList()
{
	llist l;
	l.size = 0;
	l.head = NULL;
	l.tail = NULL;
	return l;
}

void push_front(int e, llist *l)
{
	node *p = (node*) malloc(sizeof(node));
	p->val = e;
	p->next = l->head;
	p->prev = NULL;
	if(l->size == 0)
	{
		l->head = p;
		l->tail = p;
		l->size++;
		return;
	}
	l->head->prev = p;
	l->head = p;
	l->size++;
}

void push_back(int e, llist *l)
{
	if(l->size == 0)
	{
		push_front(e, l);
		return;
	}
	node *p = (node*) malloc(sizeof(node));
	p->val = e;
	l->tail->next = p;
	p->prev = l->tail;
	p->next = NULL;
	l->tail = p;
	l->size++;
}

void pop_front(llist *l)
{
	if(l->size == 0)
		return;
	if(l->size == 1)
	{
		node *p = l->head;
		l->head = NULL;
		l->tail = NULL;
		l->size--;
		free(p);
		return;
	}
	node *p = l->head;
	l->head = p->next;
	l->head->prev = NULL;
	p->next = NULL;
	free(p);
	l->size--;
}

void pop_back(llist *l)
{
	if(l->size < 2)
	{
		pop_front(l);
		return;
	}
	node *p = l->tail;
	node *q = p->prev;
	q->next = NULL;
	p->prev = NULL;
	l->tail = q;
	free(p);
	l->size--;
}

void displayList(llist *l)
{
	node *p = l->head;
	printf("HEAD <-> ");
	while(p != NULL)
	{
		printf("%d <-> ", p->val);
		p = p->next;
	}
	printf("NULL\n");
}

void clearList(llist *l)
{
	l->size = 0;
	free(l->head);
	free(l->tail);
	l->head = NULL;
	l->tail = NULL;
}

void insertSortLL(llist *l)
{
	node *p = l->head->next;
	while(p != NULL)
	{
		node *q = p->prev;
		int temp = p->val;
		int flag = 0;
		while(q != NULL)
		{
			if(q->val <= temp)
			{
				q->next->val = temp;
				flag = 1;
				break;
			}
			q->next->val = q->val;
			q = q->prev;
		}
		if(flag == 0)
			l->head->val = temp;
		p = p->next;
	}
}

void mergeSortLL(llist *l)
{
	if(l->size == 1)
		return;
	int size1 = l->size/2;
	int size2 = l->size - size1;
	llist l1 = createLList();
	llist l2 = createLList();
	node *x = l->head;
	int cnt = 0;
	while(cnt < size1)
	{
		push_back(x->val, &l1);
		x = x->next;
		cnt++;
	}
	cnt = 0;
	while(cnt < size2)
	{
		push_back(x->val, &l2);
		x = x->next;
		cnt++;
	}
	mergeSortLL(&l1);
	mergeSortLL(&l2);
	node *p = l1.head;
	node *q = l2.head;
	clearList(l);
	while(p != NULL && q != NULL)
	{
		if(p->val <= q->val)
		{
			push_back(p->val, l);
			p = p->next;
		}
		else
		{
			push_back(q->val, l);
			q = q->next;
		}
	}
	while(p != NULL)
	{
		push_back(p->val, l);
		p = p->next;
	}
	while(q != NULL)
	{
		push_back(q->val, l);
		q = q->next;
	}
}

void quickSortLL(llist *l)
{
	quickSortHelperLL(l, l->head, l->tail);
}

node* partitionLL(llist *l1, node *l, node *r)
{
	node *p = l;
	node *i = p->next;
	while(i != r->next)
	{
		if(i->val >= p->val)
		{
			i = i->next;
			continue;
		}
		int pivot = p->val;
		p->val = i->val;
		i->val = p->next->val;
		p->next->val = pivot;
		p = p->next;
		i = i->next;
	}
	return p;
}

void quickSortHelperLL(llist *l1, node *l, node *r)
{
	if(l == r)
		return;
	if(l == NULL)
		return;
	if(l->prev == r)
		return;
	node *q = partitionLL(l1, l, r);
	quickSortHelperLL(l1, l, q);
	quickSortHelperLL(l1, q->next, r);
}

