#include <iostream>
#include "Graphl.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	Graphl a(5);
	a.build(1,2);
	a.build(1,3);
	a.build(1,0);
	a.dele(1,3);
	a.build(1,0);
	a.build(2,0);
	a.build(2,4);
	a.build(2,3);
	for(int i=0;i<5;i++) a.print(i);
	return 0;
}
