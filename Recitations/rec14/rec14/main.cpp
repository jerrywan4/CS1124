#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>

using namespace std;

void printer(const list<int>& li) {
    for (list<int>::const_iterator it = li.begin(); it != li.end(); it++) {
        cout << *it;
    }
}
void p2(const list<int>& li) {
    for(int n : li) { cout << n; }
}
list<int>::const_iterator finder(const list<int>& li, int n) {
    list<int>::const_iterator it;
    for (it = li.begin(); it != li.end(); it++) {
        if (*it == n) { return it; }
    }
    return it;
}
list<int>::const_iterator f2(const list<int>& li, int n) {
    for (auto it = li.begin(); it != li.end(); it++) {
        if (*it == n) { return it; }
    }
    return li.end();
}
bool isEven(int n) {
    if( n % 2 == 0) { return true; }
    else { return false; }
}
template<typename A, typename B>
A find1(A L1, A L2, B target){
    for(A iter = L1; iter != L2; iter++) {
        if(*iter == target) {
            return iter;
        }
    }
    return L2;
}
bool checker(const vector<string>& v, string w) {
    for (string s : v) {
        if (s == w) { return false; }
    }
    return true;
}
int main() {
    
    
    // task 1
    
    cout << "// task 1: ";
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    v.push_back(4);
    v.push_back(6);
    for (int n : v) { cout << n; }
    cout << endl;
    
    // task 2
    
    cout << "// task 2: ";
    list<int> li(v.begin(), v.end());
    for (int n : li) { cout << n; }
    cout << endl;
    
    // task 3
    cout << "// task 3: ";
    sort(v.begin(), v.end());
    for (int n : v) { cout << n; }
    cout << endl;
    // task 4
    cout << "// task 4: ";
    for (int i=0; i < v.size(); i++) {
        cout << v[i];
        i++;
    }
    cout << endl;
    // task 5
    cout << "// task 5: ";
    li.sort();
    for (int n : li) { cout << n; }
    cout << endl;
    
    // task 6
    cout << "// task 6: ";
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it;
        it++;
    }
    cout << endl;
    
    // task 7
    cout << "// task 7: ";
    for (list<int>::iterator it = li.begin(); it != li.end(); it++) {
        cout << *it;
        it++;
    }
    cout << endl;
    
    // task 8
    cout << "// task 8: ";
    printer(li);
    cout <<endl;
    
    // task 9
    cout << "// task 9: ";
    p2(li);
    cout <<endl;
    // task 10
    cout << "// task 10: ";
    for (auto it = li.begin(); it != li.end(); it++) {
        cout << *it;
        it++;
    }
    cout << endl;
    
    // task 11
    cout << "// task 11: ";
    cout << *finder(li, 3);
    cout << endl;
    
    // task 12
    cout << "// task 12: ";
    cout << *f2(li, 5);
    cout << endl;
    
    // task 13
    cout << "// task 13: ";
    cout << *find(li.begin(), li.end(), 3);
    cout << endl;
    
    // task 14
    cout << "// task 14: ";
    cout << *find_if(li.begin(), li.end(), isEven);
    cout << endl;
    
    // task 15
    cout << "// task 15: ";
    cout << *find_if(li.begin(), li.end(), [](int n) {return n%2; });
    cout << endl;
    
    // task 16
    cout << "// task 16: ";
    int array[6];
    copy(li.begin(), li.end(), array);
    for (int n : array) { cout << n; }
    cout << endl;
    
    // task 18
    cout << "// task 18: ";
    cout << *find1(array, array+6, 2);
    cout << endl;
    
    // task 19
    cout << "// task 19: ";
    vector<string> words;
    ifstream ifs("text.txt");
    string word;
    while (ifs >> word) {
        if(checker(words, word) ) {
            words.push_back(word);
        }
    }
    for (string w : words) { cout << w << " "; }
    
    cout << endl << endl;
    
    // task 20
    cout << "// task 20: ";
    set<string> words2;
    ifstream ifst("text.txt");
    while (ifst >> word) {
        words2.insert(word);
    }
    for (string w : words2) { cout << w << " "; }
    
    // task 21
    cout << "// task 21: ";
    map<string, vector<int>> map;
    int count = 0;
    while (ifs >> word) {
        ++count;
        map[word].push_back(count);
    }
    for (auto w : map) {
        cout << w.first << ":";
        for (int i=0; i < w.second.size(); i++) {
            cout << w.second[i];
        }
        cout << endl;
    }
    
    
    
}
