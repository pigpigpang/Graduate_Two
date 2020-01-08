#include "Graph.h"
class Graphl : public Graph{
	private:
		int numVert;
		std::list<int> ee[50]; 
	public :
		Graphl(int numvert){
			this->numVert=numvert;
			for(int i=0;i<50;i++) ee[i].push_back(i);
			
		}
		~Graphl(){
		}
		void build(int v1,int v2){
			std::list<int>::iterator it = find( ee[v1].begin(), ee[v1].end(), v2 ); 
		    if ( it == ee[v1].end() )
		        ee[v1].push_back(v2);
		}
		void dele(int v1,int v2)
		{
			ee[v1].remove(v2);
		}
		void print(int n)           //¼ìÑé²âÊÔÁÚ½Ó±í 
		{
			std::list<int>::iterator it = ee[n].begin();
			if(it==ee[n].end()){
				std::cout<<std::endl;
				return;
			}
			std::cout << *it;
			for(it++;it!=ee[n].end();it++)
			{
				std::cout << "->"<<*it;
			}
			std::cout<<std::endl;
		}
		int n() {};
		int e() {};
		int first (int v) {};
		int next(int v,int w) {};
		void setEdge(int v1,int v2,int wght) {};
		void delEdge(int v1,int v2) {};
		bool isEdge(int i,int j) {};
		int weight(int v1,int v2) {};
		int getMark(int v) {};
		void setMark(int v,int val) {};
};
