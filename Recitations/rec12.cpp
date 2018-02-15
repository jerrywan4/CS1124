/*
Programmer: Jerry Wan
rec12.cpp
*/

#include <iostream>

using namespace std;

struct Node{
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

class Sequence{
public:
	Sequence() : headPtr(NULL), curr(NULL) {}

	Sequence( const Sequence& rhs ) : headPtr(NULL) , curr(NULL) {
        Node* temp = rhs.headPtr;
        while(temp){
            add(temp->data);
            temp= temp->next;
        }
	}

	Sequence& operator=(const Sequence& lhs){
		if(this!= &lhs){
			clear();
			Node* temp = lhs.headPtr;
			while(temp){
				add(temp->data);
				temp= temp->next;
			}
		}
		return *this;	
	}

	void reset(){
		curr = headPtr;
	}
	
	Node* listFindLast(Node* headPtr) {
    	if (headPtr == nullptr) return nullptr;
    	Node* p = headPtr;
    	while (p->next != nullptr) {
        	p = p->next; 
    	}
    return p;
	}

	void add(int data){
		if(!valid()){
			headPtr = new Node(data);
			curr = headPtr;
		}
    	else {
    		Node* ptr = new Node(data);
			ptr->next = curr->next;
			curr->next = ptr;
			curr = ptr;
		}
	}

	void remove(){
		if(curr == headPtr){
			headPtr = curr->next;
			delete curr;
			headPtr = curr;
		}
		else{
			Node* nextPtr = curr->next;
			Node* prevPtr = headPtr;
			while( prevPtr->next != curr ){
				prevPtr = prevPtr->next;
			}
			prevPtr->next = curr->next;
			delete curr;
			curr = nextPtr;
		}
	}
	int data(){
		if(valid()){
			return curr->data;
		}
		else{
			return 0;
		}
	}

	void next(){
		if(!valid()) return;
		curr = curr->next;
	}

	bool valid(){
		return curr!=NULL;
	}

	void clear(){
		if (headPtr == NULL) return;
    	Node* cur = headPtr;
    	Node* nextNodePtr = cur->next;
    	while(cur != NULL) {
    		delete cur;
        	cur = nextNodePtr;
        	if (nextNodePtr != NULL) {nextNodePtr = nextNodePtr->next;}
    	}
    	headPtr = NULL;
	}
	
	void display(){
		Node* p = headPtr;
    	while (p != nullptr) {
       		cout << p->data << " ";
        	p = p->next; 
    	}
    	cout << endl;
	}
private:
	Node* headPtr;
	Node* curr;
};

int main() {
  Sequence s;
  for (int i = 0; i < 6; ++i) s.add(i);
  s.display();
  cout << "==========\n";
  s.reset();
  for (int i = 0; i < 3; ++i) s.next();
  s.add(42);
  s.display();
  cout << "==========\n";
  s.reset();
  for (int i = 0; i < 2; ++i) s.next();
  s.remove();
  s.display();
  cout << "==========\n";
  s.clear();
  s.display();
  cout << "==========\n";
}