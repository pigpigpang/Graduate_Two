#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

void maopaosort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=n-2;j>=i;j--)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int partition(int arr[], int left, int right)  //找基准数 划分
{
    int i = left + 1 ;
    int j = right;
    int temp = arr[left];

    while(i <= j)
    {
        while (arr[i] < temp)
        {
            i++;
        }
        while (arr[j] > temp )
        {
            j--;
        }
        if (i < j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j], arr[left]);
    return j;

}

void quicksort(int arr[], int left, int right) 
{
    if (left > right)
        return;
    int j = partition(arr, left, right);
    quicksort(arr, left, j - 1);
    quicksort(arr, j + 1, right);
}


void trans(char a[],int x)
{
	stringstream ss;
	string str;
	ss << x;
	ss >> str;
	str=str+".txt";
	strcpy(a,str.c_str());
}
void trans_maopao(char a[],int x)
{
	stringstream ss;
	string str;
	ss << x;
	ss >> str;
	str=str+"_maopao.txt";
	strcpy(a,str.c_str());
}
void trans_quick(char a[],int x)
{
	stringstream ss;
	string str;
	ss << x;
	ss >> str;
	str=str+"_quick.txt";
	strcpy(a,str.c_str());
}
int main() {
	int n,target,flag_=0,flag=0;
	cout << "要使用的文件大小为（100,1000,10000,100000,1000000）"<<endl;
	cin >> n;
	cout << "是否要输出排序前的原始数据（1： 是     0：否）"<<endl; 
	cin >>flag_;
	cout << "是否要输出排序完成的数据（1： 是     0：否）"<<endl; 
	cin >>flag;
	int *tempA = new int[n];
	int *tempB = new int[n];
	char path[n],maopao_out[n],quick_out[n];
	trans(path,n);
	trans_maopao(maopao_out,n);
	trans_quick(quick_out,n);
	ifstream input(path);
	ofstream maopao(maopao_out),quick(quick_out);
	if (!input.is_open())
	{
		cout << "can not open this file" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		input >> tempA[i];
		tempB[i] = tempA[i];
	}
	if(flag_!=0)
	{
		cout <<"原始数据如下：" <<endl;
		for(int i=0;i<n;i++)
		{
			if(i%10==0) cout<<endl;
			cout << tempA[i] <<' ';
		}
	}
	input.close();
	cout <<endl<<"正在开始冒泡排序"<<endl;
	clock_t start_time1 = clock();
	maopaosort(tempA,n);
	clock_t end_time1 = clock();
	cout <<"冒泡排序完成"<<endl;
	if(flag!=0)
	{
		cout << "冒泡排序结果为: "<<endl;
		for(int i=0;i<n;i++)
		{
			if(i%10==0) cout<<endl;
			cout << tempA[i] <<' ';
		}	
	}
	cout <<endl<< "冒泡排序时间为："
	     << static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC * 1000
	     << "ms" << endl;
	cout <<"正在开始快速排序: "<<endl;
	start_time1 = clock();
	quicksort(tempB,0,n-1);
	end_time1 = clock();
	cout <<"快速排序完成"<<endl;
	if(flag!=0)
	{
		cout << "快速排序结果为: "<<endl;
		for(int i=0;i<n;i++)
		{
			if(i%10==0) cout<<endl;
			cout << tempA[i] <<' ';
		}	
	}
	cout <<endl<< "快速排序运行时间："
	     << static_cast<double>(end_time1 - start_time1) / CLOCKS_PER_SEC * 1000
	     << "ms" << endl;
	for (int i = 0; i < n; ++i) {
		maopao << tempA[i]<<' ';
		quick << tempB[i]<<' ';
	}
	return 0;
}

