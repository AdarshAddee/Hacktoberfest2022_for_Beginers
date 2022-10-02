#include <iostream>
using namespace std;

struct yogesh
{
   int value;
   yogesh *next;
};

yogesh *insertEnd(yogesh *head, int data)
{
   yogesh *temp = new yogesh();
   temp->value = data;
   if (head == NULL)
   {
      return temp;
   }
   yogesh *latest = head;
   while (latest->next != NULL)
   {
      latest = latest->next;
   }
   latest->next = temp;
   return head;
}

yogesh *insertAtChoice(struct yogesh *head, int data, int index)
{
   yogesh *a = head;
   yogesh *b = head->next;
   yogesh *ptr = new yogesh();
   ptr->value = data;
   for (int i = 0; i < index - 1; i++)
   {
      a = a->next;
      b = b->next;
   }
   a->next = ptr;
   ptr->next = b;
   return head;
}

void traverse_array(yogesh *ptr)
{
   while (ptr != NULL)
   {
      cout << "The data is : " << ptr->value << "\n";
      ptr = ptr->next;
   }
}

int main()
{
   yogesh *first = NULL;

   first = insertEnd(first, 4);
   first = insertEnd(first, 3);
   first = insertEnd(first, 2);
   first = insertEnd(first, 1);

   insertAtChoice(first, 45, 2);
   traverse_array(first);
   return 0;
}