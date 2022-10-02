#include <iostream>
using namespace std;

struct yogesh
{
	int value;
	struct yogesh *next;
};

yogesh *deleteBeg(struct yogesh *head)
{
	if (head == NULL)
		return NULL;

	yogesh *temp = head;
	head = head->next;

	delete temp;

	return head;
}

void insert(struct yogesh **head_ref, int new_data)
{
	struct yogesh *new_node = new yogesh;
	new_node->value = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void traverse_array(yogesh *ptr)
{
	while (ptr != NULL)
	{
		cout << ptr->value << "\n";
		ptr = ptr->next;
	}
}

int main()
{
	yogesh *head = NULL;

	insert(&head, 12);
	insert(&head, 29);
	insert(&head, 11);
	insert(&head, 23);
	insert(&head, 8);

	cout << "Linked List before deletion \n";
	traverse_array(head);
	head = deleteBeg(head);
	cout << "Linked List After deletion \n";
	traverse_array(head);
	return 0;
}
