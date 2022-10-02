#include <iostream>
using namespace std;

struct yogesh
{
   int value;
   yogesh *next;
};

yogesh *insertBeg(yogesh *head, int data)
{
   yogesh *temp = new yogesh();
   temp->value = data;
   temp->next = head;
   return temp;
}

yogesh *deleteAtChoice(yogesh *head, int index)
{
   yogesh *a = head;
   yogesh *b = head->next;

   for (int i = 0; i < index - 1; i++)
   {
      a = a->next;
      b = b->next;
   }
   a->next = b->next;
   free(b);
   return a;
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
   first = insertBeg(first, 4);
   first = insertBeg(first, 3);
   first = insertBeg(first, 2);
   first = insertBeg(first, 1);

   cout << "The Array before deletion is : \n";
   traverse_array(first);
   deleteAtChoice(first, 2);
   cout << "The Array after deletion is : \n";
   traverse_array(first);
   return 0;
}