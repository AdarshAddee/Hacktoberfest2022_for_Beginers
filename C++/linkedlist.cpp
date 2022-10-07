#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* Next;
	Node(int data)
	{
		this->data = data;
		this->Next = NULL;
	}
	~Node()
	{
		int value = this->data;
		//memory free
		if (this->Next != NULL)
		{
			delete Next;
			this->Next = NULL;
		}
	}
};
void insertAthead(Node* &head, int d)
{
	Node* temp = new Node(d);
	temp->Next = head;
	head = temp;

}
void insertAttail(Node* &tail, int d)
{
	Node* temp = new Node(d);
	tail->Next = temp;
	temp = tail;
}
void print(Node* &head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << endl;
}
void insertToposition(Node*& tail, Node* &head, int position, int d)
{
	if (position == 1)
	{
		insertAthead(head, d);
		return;
	}
	Node* temp = head;
	int cnt = 1;
	while (cnt < position - 1)
	{
		temp = temp->Next;
		cnt++;
	}
	if (temp->Next == NULL)
	{
		insertAttail(tail, d);
		return;
	}
	Node* NodeToinsert = new Node(d);
	NodeToinsert->Next = temp->Next;
	temp->Next = NodeToinsert;
}
void deleteNode(int position, Node*& head)
{
	if (position == 1)
	{
		Node* temp = head;
		head = head->Next;
		temp->Next = NULL;
		delete temp;
	}
	else
	{
		Node* curr = head;
		Node* prev = NULL; 
		int cnt = 1;
		while (cnt < position)
		{
			prev = curr;
			curr = curr->Next;
			cnt++;
		}
		prev->Next = curr->Next;
		curr->Next = NULL;
		delete curr;
	}
}
int main()
{
	Node* Node1 = new Node(10);
	Node* head = Node1;
	Node* tail = Node1;
	print(head);
	insertAttail(tail, 12);
	print(head);
	insertToposition(tail, head, 1, 8);
	print(head);
	deleteNode(2, head);
	print(head);
	return 0;
}