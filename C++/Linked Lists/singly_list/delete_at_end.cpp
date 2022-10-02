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

yogesh *deleteEnd(yogesh *head)
{
   yogesh *a = head;
   yogesh *b = head->next;

   while (b->next != NULL)
   {
      a = a->next;
      b = b->next;
   }
   a->next = NULL;
   free(b);
   return a;
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
   yogesh *first = NULL;
   first = insertEnd(first, 1);
   first = insertEnd(first, 2);
   first = insertEnd(first, 3);
   first = insertEnd(first, 4);

   cout << "Linked List before Deletion \n";
   traverse_array(first);
   deleteEnd(first);
   cout << "Linked List after Deletion \n";
   traverse_array(first);
   return 0;
}