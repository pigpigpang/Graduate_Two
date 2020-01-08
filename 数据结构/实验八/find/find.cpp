#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
using namespace std;

int shunxufind(int a[],int n,int target)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==target) return i;
	}
	return -1;
}
int erfenfind(int a[], int n , int target)
{
	int low = 0 ,high = n , middle;
	while(low < high)
	{
	   middle = (low + high)/2;
       if(target == a[middle])
		   return middle;
	   else if(target > a[middle])
		   low = middle +1;
	   else if(target < a[middle])
		   high = middle;
	}
	return -1;
}
bool trans(char a[],int x)
{
	stringstream ss;
	string str;
	ss << x;
	ss >> str;
	str=str+".txt";
	strcpy(a,str.c_str());
}
int main() {
	int n,target;
	cout << "Ҫ���ҵ��ļ���СΪ��100,1000,10000,100000,1000000��"<<endl;
	cin >> n;
	cout << "Ҫ���ҵ�����Ϊ"<<endl;
	cin >> target;
	int *tempA = new int[n];
	int *tempB = new int[n];
	char path[n];
	trans(path,n);
	ifstream input(path);
	if (!input.is_open())
	{
		cout << "can not open this file" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		input >> tempA[i];
		tempB[i] = tempA[i];
	}
	sort(tempB,tempB+n);
	input.close();
	clock_t start_time1 = clock();
	if(shunxufind(tempA, n,target)==-1)	cout << "˳�����δ���ҵ���Ӧ����   "<<endl;
	else cout << "˳����Ҳ��ҵ���Ӧ����    "<<target<<endl;
	clock_t end_time1 = clock();
	cout << "˳���������ʱ�䣺"
	     << static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC * 1000
	     << "ms" << endl;
	start_time1 = clock();
	if(erfenfind(tempB, n,target)==-1)	cout << "���ֲ���δ���ҵ���Ӧ����   "<<endl;
	else cout << "���ֲ��Ҳ��ҵ���Ӧ����    " <<target<<endl;
	end_time1 = clock();
	cout << "���ֲ�������ʱ�䣺"
	     << static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC * 1000
	     << "ms" << endl;
	return 0;
}

