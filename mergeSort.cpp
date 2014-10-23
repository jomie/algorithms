#include <iostream>

using namespace std;
typedef int TYPE

struct node
{
	TYPE data;
	struct node *next;
};

void splitList(struct node* src, struct node** front, struct node** tail);
void mergeSort(struct node** root);
struct node* mergeHandle(struct node* list1, struct node* list2);

void mergeSort(struct node**  root)
{
	if (*root == NULL || *root->next == NULL)
		return ;

	struct node* head = *root;
	struct node *first = NULL;
	struct node* second = NULL;
	
	splitList(root, first, second);
	mergeSort(&first);
	mergeSort(&second);
	*root = mergeHandle(first, second);
}

void splitList(struct node*src, struct node** front, struct node** tail)
{
	if (src == NULL)
		return ;
	struct node* slow = src;
	struct node* fast = src->next;

	while(fast && fast->next != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*front = src;
	*tail = slow->next;
	slow->next = NULL;
}

struct node* mergeHandle(struct node* list1, struct node* list2)
{
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;

	struct node result;
	struct node* p = result;
	
	while(list1 && list2)
	{
		if (list1->data <= list2->data)
		{
			p->next = list1;
			p = p->next;
			list1 = list1->next;	
		}else
		{
			p->next = list2;
			p = p->next;
			list2 = list2->next;
		}
	}

	if (list1)
		p->next = list1;
	else
		p->next = list2;

	return result->next;
}
