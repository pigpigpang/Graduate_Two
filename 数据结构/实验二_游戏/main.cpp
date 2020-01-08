#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> a;
	int n,k;
	cin >> n>>k;
	for(int i=0;i<n;i++)
	{
		a.push_back(i+1);
	}
	if(n==1){
		cout << a.front();
		a.clear();
		return 0;
	}
	int sum=1;
	list<int>::iterator it=a.begin();
	while(a.size()>1)
	{
		if(sum%k==0 || sum-10*(sum/10)==k)
		{
			it=a.erase(it);
		}
		else it++;
		sum++;
		if(it==a.end()) it=a.begin();
	}
	cout << *it;
	return 0;
}
