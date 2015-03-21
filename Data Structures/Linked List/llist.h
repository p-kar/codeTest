#ifndef LLIST_H
#define LLIST_H

struct NODE
{
	int val;
	struct NODE *next;
	struct NODE *prev;
};

typedef struct NODE node;

typedef struct
{
	int size;
	node *head;
	node *tail;
}llist;

llist createLList();
void push_front(int e, llist *l);
void push_back(int e, llist *l);
void pop_front(llist *l);
void pop_back(llist *l);
void displayList(llist *l);
void clearList(llist *l);
void insertSortLL(llist *l);
void mergeSortLL(llist *l);
void quickSortLL(llist *l);
void quickSortHelperLL(llist *l1, node *l, node *r);
node* partitionLL(llist *l1, node *l, node *r);

#endif