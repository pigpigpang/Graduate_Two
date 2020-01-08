#include <iostream>
#include "one.h"
using namespace std;
template <typename E>class Link{
	public :
		E element;
		Link *next;
		// Constructors
		Link(const E& elemval, Link* nextval = NULL)
		{
			element = elemval; next=nextval;
		};
		Link(Link* nextval = NULL)
		{	next=nextval;	} ;
		
};

template <typename E>class LList : public List<E>{
	private:
		Link<E>* head;
		Link<E>* tail;
		Link<E>* curr;
		int cnt;
		void init(){
			curr=tail=head=new Link<E>;
			cnt=0;
		}
		void removeall(){
			while(head!=NULL)
			{
				curr=head;
				head=head->next;
				delete curr;
			}
		}
	public:
		LList() { init();}
		~LList() {	removeall();}
		void print() {
			Link<E>* temp=head;
			while(temp->next!=NULL){
				cout << temp->next->element;
				temp=temp->next;
			}
			delete temp;
		}
		void clear() { removeall(); init();}
		void insert (const E& it) {
			curr->next = new Link<E>(it,curr->next);
			if(tail==curr) tail=curr->next;
			cnt++;
		}
		void append(const E& it){
			tail = tail->next = new Link<E>(it,NULL);
		}
		E remove(){
			try{
				if(curr->next == NULL)
				{
					throw "没有元素，无法删除";
				}
				E it= curr->next->element;
				Link<E>* ltemp = curr->next;
				if(tail==curr->next) tail=curr;
				curr->next=curr->next->next;
				delete ltemp;
				cnt--;
				return it;
			}
			catch (char const *str) {
            cerr << str;
            exit(-1); 
        	}
		}
		void moveToStart(){
			curr=head;
		}
		void moveToEnd(){
			curr=tail;
		}
		void prev(){
			if(curr==head) return ;
			Link<E>* temp=head;
			while(temp->next !=curr) temp=temp->next;
			curr=temp;
		}
		void next()
		{
			if(curr!=tail) curr=curr->next;
		}
		int length() const { return cnt;}
		int currPos() const{
			Link<E>* temp=head;
			int i;
			for(i=0;curr!=temp;i++)
				temp=temp->next;
			return i;
		} 
		void moveToPos(int pos){
			try{
				if(pos<0 || pos > cnt)
				{
					throw "位置超出范围";
				}
				curr=head;
				for(int i=0;i<pos;i++) curr=curr->next;
			}catch (char const *str) {
	            cerr << str;
	            exit(-1); 
	        }
		}
		const E& getValue() const{
			try {
            	if (curr->next == NULL) {
             	   throw "不存在这样的值";
           		}
            return curr->next->element;
	        } catch (char const *str) {
	            cerr << str;
	            exit(-1); 
	    	}
		}
		int  min_()
		{
			int min=99999999;
			Link<E>* temp1=head->next;
			Link<E>* temp2=head->next;
			for(temp1=head->next; temp1!=NULL; temp1=temp1->next)
			{
				for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
				{
					int te=temp1->element - temp2->element;
					if(te<0) te=-te;
					if(te < min ) min=te;
				}
			}
			return min;
		}
};
