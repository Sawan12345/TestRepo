
#include "stdafx.h"
#include <iostream>
#include <array>



using namespace std;

struct node{
	int value;
	node* pNext;
};


node* createListfromArray(int a[], int size)
{
	node *head, *curr;
	head = new node();
	head->value = a[0];
	head->pNext = NULL;
	curr = head;
	for (int i = 1; i < size; i++)
	{
		node *temp = new node();
		temp->value = a[i];
		temp->pNext = NULL;
		curr->pNext = temp;
		curr = temp;
	}
	return head;
}
void insertAtFront(node** head, int value)  // what if head is not available, or wrong?
{
	node* newNode = new node();
	newNode->value = value;
	newNode->pNext = *head;
	*head = newNode;

}

void insertLast(node* head, int value)  // what if head is not available or wrong? 
{
	node *curr = head;
	node* newNode = new node();
	newNode->value = value;
	newNode->pNext = NULL;
	while (curr->pNext != NULL)
	{
		curr = curr->pNext;
	}
	curr->pNext = newNode;

}

bool insertAt(node** head, int index, int value) // what if head is not avilable ?
{
	node* curr;
	curr = *head;
	if (index < 0)
		return false;
	if (index == 0)
		insertAtFront(head, value);

	int i = 0;
	node* newNode = new node();
	newNode->value = value;
	while (curr->pNext != NULL)
	{
		i++;
		if (i == index)
		{

			newNode->pNext = curr->pNext;
			curr->pNext = newNode;
			return true;
		}
		curr = curr->pNext;
	}
	if (++i == index)
	{
		newNode->pNext = NULL;
		curr->pNext = newNode;
		return true;
	}
	return false;
}

bool deleteAt(node** head, int index)  // no head?
{

	node *curr = *head;
	int i = 0;
	if (index == i && i == 0)
	{
		curr = curr->pNext;
		delete *head;
		*head = curr;
		return true;
	}
	while (curr->pNext != NULL)
	{
		if (index == i + 1 )
		{
			node *temp = curr->pNext;
			curr->pNext = temp->pNext;
			delete temp;
			return true;
		}
		i++;
		curr = curr->pNext;
	}
	
	return false;
}
void printList(node* head)  
{
	if (!head)
	{
		cout << "Empty List" << endl;
		return;
	}
	cout << "POS\t" << "Value" << endl;
	int i = 0;
	while (head->pNext != NULL)
	{
		cout << i++ << "\t" << head->value << endl;
		head = head->pNext;
	}
	cout << i << "\t" << head->value << endl;
}
void deleteList(node **head)
{
	node* me = *head;
	node* child = me->pNext;
	while (child)
	{
		delete me;
		me = child;
		child = child->pNext;
	}
	delete me;
	*head = child;
	//*head = NULL;

}
void reverseList(node **head)
{
	node *parent=*head;
	node *me= parent->pNext;
	node *child = me->pNext;
	parent->pNext = NULL;
	while (child)
	{
		me->pNext = parent;
		parent = me;
		me = child;
		child = child->pNext;

	}
	me->pNext = parent;
	parent = me;
	*head = parent;
}
int main()
{
	node *head;
	int arr[5] = { 1, 2, 3, 4, 5 };
	head = createListfromArray(arr, 5);
	insertAtFront(&head, 6);
	insertAtFront(&head, 6);
	insertAtFront(&head, 6);
	insertAtFront(&head, 6);
	insertAtFront(&head, 6);
	insertAtFront(&head, 6);
	insertLast(head, 7);

	insertAt(&head, 0, 8);
	insertAt(&head, 8, 9);

	printList(head);
	deleteAt(&head, 0);
	printList(head);
	deleteAt(&head, 6);
	printList(head);
	deleteAt(&head, 6);
	printList(head);
	reverseList(&head);
	printList(head);
	reverseList(&head);
	printList(head);
	deleteList(&head);
	printList(head);
}
