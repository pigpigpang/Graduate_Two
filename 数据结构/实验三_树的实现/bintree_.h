#include "bintree.h"
#include <iostream>
#include <queue>
using namespace std;
node* node::create(int post[],int in[],int postL,int postR,int inL,int inR){
	if(postL > postR){//˵����ͷ�� 
		return NULL; 
	}
	//����������ǽ����Ĳ��� 
	node* root = new node;
	root->data = post[postR];//�½ڵ��������Ϊ���ڵ��ֵ 
	int i;
	for(i = inL; i <= inR;i++ ){
		if(in[i] == post[postR]){//˵���ҵ�����ֵͬ 
			break;
		}
	}
	int numLeft ;//��ʾ����������ڵ����Ľڵ���
	numLeft = i - inL;
	root->left = create(post,in,postL,postL+numLeft-1,inL,i-1); //�������� 
	root->right = create(post,in,postL+numLeft,postR-1,i+1,inR);//�������� 
	return root; 
} 

void node::levelorder(node *root){
	node *queue[31];                      //�Զ���˳��ѭ������
	int front =0, rear = 0;                 //��ͷ/β
    rear = (rear +1) % 31;
	queue[rear] = root;                     //��������
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

void node::preOrder(node*tmp)//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
{
	if (tmp == NULL)
		return;
	cout << tmp->data; 
	preOrder(tmp->le());
	preOrder(tmp->ri());
}
void node::inOrder(node*tmp)//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
{
	if (tmp == NULL)
		return;
	inOrder(tmp->le());
	cout << tmp->data;
	inOrder(tmp->ri());
}
void node::postOrder(node*tmp)//���������void(*visit)(BinNode<E>*node)Ϊһ������ָ���������visit���洫�����ĺ������ڱ���������ʹ�ô������ĺ�������
{
	if (tmp == NULL)
		return;
	postOrder(tmp->le());
	postOrder(tmp->ri());
	cout << tmp->data;
}
int node::nodeDepth(node*tmp)//��ö����������
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
int node::nodeNodes(node*tmp)//��ö������Ľ����
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
int node::nodeHeight(node*tmp)//��ö������ĸ߶�
{
	if (tmp == NULL)
		return 0;
	return nodeDepth(tmp) - 1;
}
int node::nodeLeafs(node*tmp)//��ö�������Ҷ�ӽ����
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
bool node::find(node*tmp, int e)//���Ҷ��������Ƿ���ĳ����Ϊe�Ľ��
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
