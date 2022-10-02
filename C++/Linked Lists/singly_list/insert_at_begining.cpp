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

   traverse_array(first);
   return 0;
}