#include <iostream>
#include <deque> 
// stack & queue 짬뽕."앞뒤가 뚫려있다."
// 처음에 빠졌던 얘가 뒤로 가야한다던 지, 그럴때 사용함. 
// stack queue 두개 다 쓰면 귀찮을 때가 있음.  (연산 많아지구)

using namespace std ;

int main(void) { 
    ios::sync_with_stdio(false); cin.tie(0) ; 

    deque<int> D ; 

    D.push_back(2) ; 
    D.push_back(3) ; 
    D.push_back(4) ; 
    D.push_front(1) ; 

    while(!D.empty()) { 
        int k = D.front() ; 
        cout << k << ' '; 
        D.pop_front() ; 
    }

    cout << '\n' ; 

    D.push_back(2) ; 
    D.push_back(3) ; 
    D.push_back(4) ; 
    D.push_front(1) ; 

    while(!D.empty()) { 
        int k = D.back() ; 
        cout << k << ' '; 
        D.pop_back() ; 
    }
    cout << '\n' ; 

    return 0 ; 
}