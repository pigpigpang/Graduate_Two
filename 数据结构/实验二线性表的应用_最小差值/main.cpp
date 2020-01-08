#include <iostream>
#include <string>
#include "link.h"
using namespace std;
int main(int argc, char** argv) {
	LList<int> a;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		a.append(x);
	}
	cout<<a.min_();
	return 0;
}
