#include <iostream>
#include <algorithm>
#include "bst_.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	node* bst=NULL;
	bst=bst->create(0,n);
	bst->inOrder(bst,a);
	bst->levelorder(bst);
	return 0;
}
