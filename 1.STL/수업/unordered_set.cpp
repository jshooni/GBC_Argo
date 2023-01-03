/**
 * insert를 1을 하면 그대로 1,2,3이 유지가 된다. 
 * 1. 정렬
 * 2. 값을 하나씩만 받고 싶을 때. 
 * 
 * "Sort + Only one"
 * 
 * <--> #include <unordered_set> : 정렬이 안된 set (중복만 제거해주는)
 * 
 *
 * */
#include <iostream>
#include <unordered_set>
using namespace std; 

int main(void) {
    
    ios:: sync_with_stdio(false);
    cin.tie(0);
    
    unordered_set<int> s ; 

    s.insert(3);
    s.insert(1);
    s.insert(6);

    s.insert(1);
    
    unordered_set<int> ::iterator iter;

    for(iter = s.begin() ; iter != s.end() ; iter ++) {
        cout << *iter << ' ';
    }
    cout << '\n';

    return 0; 
}