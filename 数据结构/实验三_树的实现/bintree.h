#include<iostream>
using namespace std;
class node{
	private:
	int data;//值 
	int height;//高度 
	node* left;//左子树 
	node* right; //右子树 
	public : 
	node(){left=right=NULL;}
	node(int tmp, node *l=NULL, node *r=NULL)//带参构造函数
	{
		data = tmp;
		left = l;
		right = r;
	}
	node* le()//返回左孩子
	{
		return left;
	}
	node* ri()//返回右孩子
	{
		return right;
	}
	void setLeft(node*l)//设置左孩子
	{
		left = l;
	}
	void setRight(node*r)//设置右孩子
	{
		right = r;
	}
	void setValue(int tmp)//设置当前结点的值
	{
		data = tmp;
	}
	int getValue()//获得当前结点的值
	{
		return data;
	}
	bool isLeaf()//判断当前结点是否为叶子结点
	{
		if (left == NULL&&right == NULL)
			return true;
		else
			return false;
	}
	node* create(int a[],int b[],int postL,int postR,int inL,int inR);
	void levelorder(node *root);
	void preOrder(node*tmp);
	void inOrder(node*tmp);
	void postOrder(node*tmp);
	int nodeDepth(node*tmp);
	int nodeNodes(node*tmp);
	int nodeHeight(node*tmp);
	int nodeLeafs(node*tmp);
	bool find(node*tmp, int e);
};
