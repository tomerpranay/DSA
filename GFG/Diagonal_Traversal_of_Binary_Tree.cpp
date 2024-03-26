

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   queue<Node *> q;
   q.push(root);
   vector<int> ans;
   while(!q.empty()){
       Node *front=q.front();
       q.pop();
       while(front!=NULL){
           ans.push_back(front->data);
           if(front->left){
               q.push(front->left);
           }
           front=front->right;
       }
   }
   return ans;
   
}