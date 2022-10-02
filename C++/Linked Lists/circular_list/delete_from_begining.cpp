#include <iostream>
using namespace std;

struct yogesh
{
	int data;
	struct yogesh *next;
};

void insertBeg(yogesh **head, int data)
{
	yogesh *current = *head;
	yogesh *newNode = new yogesh();
	newNode->data = data;
	if (*head == NULL)
	{
		newNode->next = newNode;
		*head = newNode;
		return;
	}
	else
	{

		while (current->next != *head)
		{
			current = current->next;
		}
		newNode->next = *head;
		current->next = newNode;
	}
}

void traverse_list(yogesh *head)
{
	yogesh *current = head;

	if (head == NULL)
	{
		cout << "\nDisplay List is empty\n";
		return;
	}
	else
	{
		do
		{
			printf("%d ", current->data);
			current = current->next;
		} while (current != head);
	}
}

void deleteBeg(yogesh **head)
{
	struct yogesh *previous = *head, *next = *head;

	if (*head == NULL)
	{
		printf("\nList is empty\n");
		return;
	}

	if (previous->next == previous)
	{
		*head = NULL;
		return;
	}

	while (previous->next != *head)
	{

		previous = previous->next;
		next = previous->next;
	}

	previous->next = next->next;

	*head = previous->next;
	free(next);

	return;
}

int main()
{
	struct yogesh *head = NULL;
	insertBeg(&head, 1);
	insertBeg(&head, 2);
	insertBeg(&head, 3);
	insertBeg(&head, 4);
	insertBeg(&head, 5);

	cout << "Circular Linked list before deletion\n";
	traverse_list(head);
	cout << "\nCircular Linked list before deletion\n";
	deleteBeg(&head);
	traverse_list(head);

	return 0;
}
