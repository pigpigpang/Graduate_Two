#include <iostream>
#include "Graphm.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n,m;
	cin >> n>>m;
	char name[n];
	int chu[n];
	for(int i=0;i<n;i++)
	{
		cin >> name[i];
		chu[i]=0;
	}
	Graphm a(n);
	for(int i=0;i<m;i++)
	{
		char aa,bb;
		int a1=0,b1=0,c1=0,j=0;
		cin >> aa>>bb>>c1;
		for(j=0;j<n;j++)
		{
			if(aa==name[j]) a1=j;
			if(bb==name[j]) b1=j;
		}
		a.setEdge(a1,b1,c1);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << a.matrix[i][j]<<" ";
			if(a.matrix[i][j]!=0) chu[i]++;
		}
		cout << endl; 
	}
	char Ma='#';
	int max=-1;
	for(int i=0;i<n;i++)
	{
		if(max<chu[i]){
			Ma=name[i];
			max=chu[i];
		} 
		if(max==chu[i])
			Ma=(Ma>name[i])?Ma:name[i];
	}
	cout << Ma<<' '<<max;
	return 0;
}
