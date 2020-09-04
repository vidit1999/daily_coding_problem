#include <iostream>
#define K 3
using namespace std;

struct node{
  int data;
  struct node* children[K];
};

node* newNode(int data){
  node* root = new node;
  root->data = data;
  for(int i=0;i<K;i++)
    root->children[i] = NULL;
  return root;
}

bool isMirror(node* root1, node* root2){
  if(root1 == NULL && root2 == NULL)
    return true;
  if(root1 && root2 && root1->data == root2->data){
    for(int i=0;i<K;i++){
      if(!isMirror(root1->children[i],root2->children[K-1-i]))
        return false;
      return true;
    }
  }
  return false;
}

bool isSymmetric(node* root){
  return isMirror(root, root);
}

/*
        4
      / | \
    3   5   3
  /           \
9              9
*/

int main(){
  node* root = newNode(4);
  root->children[0] = newNode(3);
  root->children[1] = newNode(5);
  root->children[2] = newNode(3);
  root->children[0]->children[0] = newNode(9);
  root->children[2]->children[2] = newNode(9);

  if(isSymmetric(root))
    cout << "Yes\n";
  else
   cout << "No\n";
  return 0;
}