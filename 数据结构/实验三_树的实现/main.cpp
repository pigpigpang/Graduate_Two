#include <iostream>
#include "bintree_.h"
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	int post[n],in[n];
	for(int i=0;i<n;i++)
	{
		cin >> post[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> in[i];
	}
	node* root=NULL;
	root=root->create(post,in,0,n-1,0,n-1);
	root->levelorder(root);
	return 0;
}
