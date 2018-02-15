
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void pushFront(Node*& head, int data){
    head = new Node(data, head);
}

void theBinary( const int& number ){
    if(number < 2){
        cout << number%2;
        return;
    }
    int quotient = number/2;
    if( quotient != 1 ){
        theBinary(quotient);
    }
    else{
        cout << quotient;
    }
    cout <<  number%2;
}

Node* listSum( Node*& list1, Node*& list2 ){
    if( list1 == NULL || list2 == NULL){
        return NULL;
    }
    Node* head = new Node( (list1->data + list2->data) , listSum( list1->next, list2->next ) );
    return head;
}

void printList(Node* head)
{
  for ( ; head; head = head->next )
  {
    cout << head->data << " ";
  }
}

int max(TNode* root) {
    if(root == NULL) return 0;
    int maximum = root->data;
    int maxLeft = max( root->left );
    int maxRight = max( root->right );
    if( maxRight > maxLeft && maxRight > maximum){
        return maxRight;
    }
    else if( maxLeft > maxRight && maxLeft > maximum ){
        return maxLeft;
    }
    else{
        return maximum;
    }
}

int cStringSum( char* charArray  ){
    if(*charArray == '\0') return 0;
    int sum = 0;
    sum = (int)(*charArray) + cStringSum(charArray+1);
    return sum;
}

int binarySearch( char* array, char target, int start, int end ){
    if ( end < start ) return -1;
    int mid = start + end / 2 ;
    if( target == array[mid] ) return mid;
    
    else if( target < array[mid] ){
        return binarySearch(array, target, start, mid-1);
    }
    else{
        return binarySearch(array, target, mid+1, end);
    }
}

void foo(int n) { 
   if (n > 1) { 
      cout << 'a'; 
      foo(n/2); 
      cout << 'b'; 
      foo(n/2); 
   } 
   cout << 'c'; 
}

int main(){
    cout << "===============" << endl;
    cout << "Binary value is: " << endl;
    theBinary(1);
    cout << endl;
    cout << "===============" << endl;
    Node* list1 = nullptr;
    for (int i = 0; i < 5; i++){
        pushFront(list1, i * 2);
    }
    Node* list2 = nullptr;
    for (int i = 2; i < 5; i++){
        pushFront(list2, i * 3);
    }
    Node* head = listSum(list1, list2);
    cout << "The sum list is: ";
    printList(head);
    cout << endl;
    cout << "===============" << endl;
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(2, &d, &e);
    cout<< "The max is: " << endl;
    cout << max(&f) << endl;
    cout << "===============" << endl;
    cout << "Sum of C String: " << endl;
    char charArr[] = "chs";
    cout << cStringSum( charArr ) << endl;
    cout << "===============" << endl;
    cout << "Binary Search: " << endl;
    sort(charArr, charArr+3);
    cout << charArr[0] << endl;
    cout << charArr[1] << endl;
    cout << charArr[2] << endl;
    cout << binarySearch(charArr, 'z', 0, 2) << endl;
    cout << "===============" << endl;
    foo(8);
}