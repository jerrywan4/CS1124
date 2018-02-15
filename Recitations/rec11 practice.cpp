#include <iostream>

using namespace std;

class LList;

struct Node{
	int data;
	Node* link;
	Node(int data = 0, Node* link = nullptr) : data(data), link(link){}
	int getData();
};

class LList{
	Node* head;
public:

	LList(Node* head = nullptr) : head(head){}

	Node* getHead();

	friend ostream& operator<<(ostream& os, LList& list1){
		if(list1.head == nullptr){
			os << "Nothing to output" << endl;
		}
		else{
			Node* temp = list1.head;
			while(temp!=nullptr){
				os << temp->data << " ";
				temp = temp->link; 
			}
		os << endl;
		}
		return os;
	}

	Node* searchNode(int data){
		Node* temp = head;
		while(temp != nullptr){
			if(temp->data == data){
				return temp;
			}
			temp = temp->link;
		}
		return nullptr;
	}

	void pushFront(int newData){
		head = new Node(newData, head);
	}

	void pushAfter(int data, int newData){
		Node* node1 = searchNode(data);
		Node* node2 = new Node(newData, node1->link);
		node1->link = node2;
	}


};

Node* LList::getHead(){
	return head;
}

int Node::getData(){
	return data;
}

void spliceList(Node* splicePoint, Node* l2Head){
	if(splicePoint==nullptr||l2Head==nullptr)return;
	Node* temp = splicePoint;
	Node* temp2 = splicePoint->link;
	temp->link = l2Head;
	while(temp->link){
		temp = temp->link;
	}
	temp->link = temp2;
}

void searchList(Node* mLHead, Node* sLHead){
	if(mLHead==nullptr||sLHead==nullptr)return;
	Node* temp = mLHead;
	Node* temp2 = sLHead;

	while(mLHead!=sLHead){
		mLHead = mLHead->link;
		if(mLHead->link==nullptr){
			cout << "No match found" << endl;
			return;
		}
	}
	Node* startOfSub = temp;
	while(temp2->link){
		if(temp!=temp2){
			return;
		}
		temp=temp->link;
		temp2=temp2->link;
	}	
	while(startOfSub->link){
		cout << startOfSub->getData();
	}
}

int main(){
	LList list1;
	list1.pushFront(1);
	list1.pushFront(9);
	list1.pushFront(7);
	list1.pushFront(5);
	
	LList list2;
	list2.pushFront(2);
	list2.pushFront(3);
	list2.pushFront(6);

	Node* splicePoint = list1.searchNode(7);
	Node* l2Head = list2.getHead();
	spliceList(splicePoint, l2Head);
	cout << list1 << endl;

	LList list3;
	list3.pushFront(1);
	list3.pushFront(9);
	list3.pushFront(2);
	list3.pushFront(3);
	list3.pushFront(6);
	list3.pushFront(7);
	list3.pushFront(5);

	LList list4;
	list4.pushFront(9);
	list4.pushFront(2);
	list4.pushFront(3);
	list4.pushFront(6);

	Node* mLHead = list3.getHead();
	Node* sLHead = list4.getHead();

	searchList(mLHead, sLHead);
}