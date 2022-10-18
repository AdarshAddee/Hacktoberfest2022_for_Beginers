#include<stdio.h>
#include<stdio.h>

struct node
{
    int data;
    struct node*left,*right;

};

struct node *newnode(int data);
{
    struct node*Node=(struct node*)malloc(sizeof(struct node));
    Node->data=data;
    Node->left=NULL;
    Node->right=NULL;

    return node;
}

struct node* insert(struct node*node,int data)
{
    if(node==NULL)
     return newnode(data);
    else{
    

        if(data<node->data)
         node->left= insert(node->left,data);
        else if(data>node->data)
        {
            node->right=insert(node->right,data);
        }
    }    
    return node; 
    
}

void preorder(struct node*n){
    if(n==NULL)
    return;
        
         preorder(n->left);
         printf("\t%d",n->data);
        
         preorder(n->right);
     
}

struct node*minnode(struct node*node)
{
    struct node*ptr=node;
    while(ptr!=NULL && ptr->left!=NULL)
    {
        ptr=ptr->left;

    }
    return ptr;
}

struct node*delete(struct node*root,int data)
{
    if(root==NULL)
      return root;
    if(data<root->data)
     root->left=delete(root->left,data);
    else if(data>root->data)
    {
      root->right=delete(root->right,data);
    }

    else
    {
        if(root->left==NULL)
         {
             struct node*temp=root->right;
             free(root);
             return temp;
         }
         else
         {
             struct node*temp=root->left;
             free(root);
             return temp;
         }

         struct node* temp = minnode(root->right);
         root->data=temp->data;
         root->right = delete(root->right, temp->data);
         return root;
    }
     

}

