#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
   int no; //�����Ž�������
   int code;//���������������
   node *next;//�����һ�����ĵ�ַ
};
int main()
{
   int m,n,i,j;
   node *p,*q,*first;
   cout<<"������m�ĳ�ʼֵ m:";
   cin>>m;
   cout<<"���������� n:";
   cin>>n;
   for(i=1;i<=n;i++)
   {
        if(i==1)
        {
            first=p=(node*)malloc(sizeof(node));
            if(p==0)
                return 0;
        }
        else
        {
            q=(node*)malloc(sizeof(node));
            if(q==0)
                return 0;
            p->next=q;
            p=q;
        }
        cout<<"������� "<<i<<" ���˵�����: ";
        cin>>(p->code);
        p->no=i;
   }
   p->next=first; //�ñ�βָ���ͷ�γ�ѭ������
   p=first;
   cout<<"����˳��Ϊ: ";
   for (j=1;j<=n;j++)
   {
        for(i=1;i<m;i++,p=p->next);
        m=p->code;
        cout<<p->no<<" ";
        p->no=p->next->no;
        p->code=p->next->code;
        q=p->next;
        p->next=p->next->next;
        free(q);
   }
   cout<<endl;
   return 0;
}
