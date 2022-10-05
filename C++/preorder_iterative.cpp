// the following code contains preorder traversal of a tree using stack
void preorder(node*root){
  stack<node*> s;
  s.push(root);
  while(!s.empty()){
    node *temp = s.top();
    cout<<temp->data<<" ";
    s.pop();
    if(temp->right) s.push(temp->right);
    if(temp->left) s.push(temp->left);
  }
  
                    
