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

   traverse_array(first);
   return 0;
}