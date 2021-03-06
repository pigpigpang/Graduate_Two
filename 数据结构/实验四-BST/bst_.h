#include "bst.h"
#include <iostream>
#include <queue>
using namespace std;
int pos=0;
node* node::create(int index,int n){
	if(index >= n)
	{
		return NULL; 
	}
	int l=index*2+1;
	int r=index*2+2;
	node* root = new node;
	root->left = create(l,n); //建左子树 
	root->right = create(r,n);//建右子树 
	return root; 
} 

void node::levelorder(node *root){
	node *queue[31];                      //自定义顺序循环队列
	int front =0, rear = 0;                 //队头/尾
    rear = (rear +1) % 31;
	queue[rear] = root;                     //根结点进队
	node *p;
	while(front != rear){
  		front = (front + 1)%31;
  		p = queue[front];
  		printf("%d ", p->data);
  		if(p->left != NULL){
  		    rear = (rear + 1) % 31;
			queue[rear] = p->left;
		}
		if(p->right != NULL){
   			rear = (rear + 1) % 31;
			queue[rear] = p->right;
		}
	}
}

void node::preOrder(node*tmp)//先序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
{
	if (tmp == NULL)
		return;
	cout << tmp->data; 
	preOrder(tmp->le());
	preOrder(tmp->ri());
}
void node::inOrder(node*tmp , int t[])//中序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
{
	if (tmp == NULL)
		return;
	
	inOrder(tmp->le(),t);
	tmp->data=t[pos++];
	inOrder(tmp->ri(),t);
}
void node::postOrder(node*tmp)//后序遍历，void(*visit)(BinNode<E>*node)为一个函数指针参数，用visit代替传进来的函数，在遍历函数中使用传进来的函数功能
{
	if (tmp == NULL)
		return;
	postOrder(tmp->le());
	postOrder(tmp->ri());
	cout << tmp->data;
}
int node::nodeDepth(node*tmp)//获得二叉树的深度
{
	if (tmp == NULL)
		return 0;
	int ld = 0;
	int rd = 0;
	if (tmp->le() != NULL)
		ld = nodeDepth(tmp->le());
	if (tmp->ri() != NULL)
		rd = nodeDepth(tmp->ri());
	if (ld >= rd)
		return ld + 1;
	else
		return rd + 1;
}
int node::nodeNodes(node*tmp)//获得二叉树的结点数
{
	if (tmp == NULL)
		return 0;
	queue<node*>que;
	que.push(tmp);
	node* curr;
	int sum = 0;
	while (que.empty() != true)
	{
		curr = que.front();
		if (curr->le() != NULL)
		{
			que.push(curr->le());
		}
		if (curr->ri() != NULL)
		{
			que.push(curr->ri());
		}
		que.pop();
		sum++;
	}
	return sum;
}
int node::nodeHeight(node*tmp)//获得二叉树的高度
{
	if (tmp == NULL)
		return 0;
	return nodeDepth(tmp) - 1;
}
int node::nodeLeafs(node*tmp)//获得二叉树的叶子结点数
{
	if (tmp == NULL)
		return 0;
	queue<node*>que;
	que.push(tmp);
	node* curr;
	int sum = 0;
	while (que.empty() != true)
	{
		curr = que.front();
		if (curr->le() != NULL)
		{
			que.push(curr->le());
		}
		if (curr->ri() != NULL)
		{
			que.push(curr->ri());
		}
		if (curr->ri() == NULL&&curr->le() == NULL)
			sum++;
		que.pop();
	}
	return sum;
}
bool node::find(node*tmp, int e)//查找二叉树中是否含有某个名为e的结点
{
	if (tmp == NULL)
		return false;
	queue<node*>que;
	que.push(tmp);
	node* curr;
	while (que.empty() != true)
	{
		curr = que.front();
		if (curr->le() != NULL)
		{
			que.push(curr->le());
		}
		if (curr->ri() != NULL)
		{
			que.push(curr->ri());
		}
		if (curr->getValue() == e)
			return true;
		que.pop();
	}
	return false;
}
