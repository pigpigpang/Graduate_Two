#include<iostream>
using namespace std;
class node{
	private:
	int data;//ֵ 
	int height;//�߶� 
	node* left;//������ 
	node* right; //������ 
	public : 
	node(){left=right=NULL;}
	node(int tmp, node *l=NULL, node *r=NULL)//���ι��캯��
	{
		data = tmp;
		left = l;
		right = r;
	}
	node* le()//��������
	{
		return left;
	}
	node* ri()//�����Һ���
	{
		return right;
	}
	void setLeft(node*l)//��������
	{
		left = l;
	}
	void setRight(node*r)//�����Һ���
	{
		right = r;
	}
	void setValue(int tmp)//���õ�ǰ����ֵ
	{
		data = tmp;
	}
	int getValue()//��õ�ǰ����ֵ
	{
		return data;
	}
	bool isLeaf()//�жϵ�ǰ����Ƿ�ΪҶ�ӽ��
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
