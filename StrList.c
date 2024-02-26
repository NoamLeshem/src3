#include <stdio.h>
#include <string.h>
#include "StrList.h"

typedef struct _node
{
    char* _data;
    struct _node* _next;
} Node;

struct _StrList
{
    Node* _head;
    size_t _size;
};

Node* Node_alloc(const char* data, Node* next)
{
	Node* p= (Node*) malloc(sizeof(Node));
	p->_data = (char*) malloc(strlen(data) + 1);
	strcpy(p->_data, data);
	p->_next = next;
	return p;
}

void Node_free(Node* node)
{
	free(node->_data);
	free(node);
}

StrList* StrList_alloc()
{
	StrList* p = (StrList*) malloc(sizeof(StrList));
	p->_head = NULL;
	p->_size = 0;
	return p;
}

void StrList_free(StrList* list)
{
	if (list == NULL || list->_head == NULL || list->_size < 1)
		return;
	Node* p1 = list->_head;
	Node* p2;
	while(p1)
	{
		p2 = p1;
		p1 = p1->_next;
		Node_free(p2);
	}
	list->_size = 0;
}

size_t StrList_size(const StrList* list)
{
	return list->_size;
}

void StrList_insertLast(StrList* list, const char* data)
{
	Node* p = list->_head;
	if (p == NULL)
		list->_head = Node_alloc(data, NULL);
	else {
		while (p->_next)
			p = p->_next;
		p->_next = Node_alloc(data, NULL);
	}
	++(list->_size);
}

void StrList_insertAt(StrList* list, const char* data, int index)
{
	Node* p1 = list->_head;
	Node* p2 = p1->_next;
	for (int i = 0; i < index - 1; i++)
	{
		p1 = p2;
		p2 = p2->_next;
	}
	p1->_next = Node_alloc(data, p2);
	++(list->_size);
}

char* StrList_firstData(const StrList* list)
{
	return list->_head->_data;
}

void StrList_print(const StrList* list)
{
	if (list == NULL || list->_head == NULL || list->_size < 1)
	{
		printf("\n");
		return;
	}
	const Node* p = list->_head;
	printf("%s",p->_data);
	p = p->_next;
	while(p)
	{
		printf(" %s",p->_data);
		p = p->_next;
	}
	printf("\n");
}

void StrList_printAt(const StrList* list, int index)
{
	const Node* p = list->_head;
	for (int i = 0; i < index && p; i++, p = p->_next);
	if (p)
	{
		printf("%s\n", p->_data);
	}
}

int StrList_printLen(const StrList* list)
{
	if (list == NULL || list->_head == NULL || list->_size < 1)
		return 0;
	int sum = 0;
	for (const Node* p = list->_head; p; p = p->_next)
	{
		sum += strlen(p->_data);
	}
	return sum;
}

int StrList_count(StrList* list, const char* data)
{
	const Node* p = list->_head;
	int count = 0;
	while(p)
	{
		if (!strcmp(p->_data, data))
			++count;
		p = p->_next;
	}
	return count;
}

void StrList_remove(StrList* list, const char* data)
{
	Node* p1 = list->_head;
	Node* p2 = p1->_next;
	while(p2)
	{
		if (!strcmp(p2->_data, data))
		{
			p1->_next = p2->_next;
			Node_free(p2);
			p2 = p1->_next;
			--(list->_size);
		}
		else
		{
			p1 = p2;
			p2 = p2->_next;
		}
	}
	if (!strcmp(list->_head->_data, data))
	{
		p1 = list->_head;
		list->_head = list->_head->_next;
		Node_free(p1);
		--(list->_size);
	}
}

void StrList_removeAt(StrList* list, int index)
{
	if (list == NULL || list->_head == NULL || index < 0 || index >= list->_size || list->_size < 1)
		return;
	Node* p1 = list->_head;
	Node* p2 = p1->_next;
	if (!index)
	{
		list->_head = list->_head->_next;
		Node_free(p1);
		--(list->_size);
		return;
	}
	for (int i = 0; i < index - 1; i++, p2 = p2->_next)
	{
		p1 = p2;
	}
	p1->_next = p2->_next;
	Node_free(p2);
	--(list->_size);
}

int StrList_isEqual(const StrList* list1, const StrList* list2)
{
	if (list1 == NULL && list2 == NULL)
		return 1;

	if (list1 == NULL || list2 == NULL || list1->_size != list2->_size)
		return 0;

	const Node* p1 = list1->_head;
	const Node* p2 = list2->_head;
	while (p1 && p2)
	{
		if (strcmp(p1->_data, p2->_data))
			return 0;
		p1 = p1->_next;
		p2 = p2->_next;
	}

	if (p1 != NULL || p2 != NULL)
		return 0;

	return 1;
}


StrList* StrList_clone(const StrList* list)
{
	StrList* ret = StrList_alloc();
	const Node* old = list->_head;
	Node** copy = &(ret->_head);
	ret->_size = list->_size;
	while (old)
	{
		*copy = Node_alloc(old->_data, NULL);
		old = old->_next;
		copy = &((*copy)->_next);
	}
	return ret;
}

void StrList_reverse(StrList* list)
{
	if (list == NULL || list->_head == NULL || list->_size < 1)
		return;
	Node* p1 = list->_head;
	Node* p2 = p1->_next;
	Node* p3 = p2->_next;
	p1->_next = NULL;
	while(p3)
	{
		p2->_next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->_next;
	}
	p2->_next = p1;
	list->_head = p2;
}

int compareStrings(const void* a, const void* b)
{
	return strcmp(*(const char **) a, *(const char **) b);
}

void StrList_sort(StrList* list)
{
	if (list == NULL || list->_head == NULL || list->_size < 1)
		return;
	if (list->_size < 2) return;
	Node* node = list->_head;
	char** strings = malloc(list->_size * sizeof(char*));
	for (int i = 0; i < list->_size; i++, node = node->_next)
		strings[i] = node->_data;
	qsort(strings, list->_size, sizeof(char*), compareStrings);
	node = list->_head;
	for (int i = 0; i < list->_size; i++, node = node->_next)
		node->_data = strings[i];
	free(strings);
}

int StrList_isSorted(StrList* list)
{
	if (list == NULL || list->_head == NULL || list->_size < 1)
		return 1;
	Node* p1 = list->_head;
	Node* p2 = p1->_next;
	while(p2)
	{
		if (strcmp(p1->_data, p2->_data) > 0)
			return 0;
		p1 = p2;
		p2 = p2->_next;
	}
	return 1;
}