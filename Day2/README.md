#Stack Queue

##Stack
    #include <iostream>
    #include <stack>

    using namespace std; 

    int main(void) {
        ios::sync_with_stdio(false); cin.tie(0);

        stack<int> s ; 

        s.push(3) ; 
        s.push(4) ; 
        s.push(5) ; 

        //s.empty : 비어 있으면 1을 출력. 
        while (!s.empty()) { 
            int k = s.top(); 
            cout << k << '\n';
            s.pop(); 
        }

        return 0; 
    }

stack : Vname.top(); 
queue : Vname.front(); 


Queue 
BFS 알고리즘을 구현하는데 사용을 한다. 



* 전역변수로 선언을 하면 자동으로 0으로 초기화가 된다. 

함수
memset() --> c에서 string 세티할 때 흔히 씀.  // 0 초기화 가능. (<#include string> 해야함)
memset(arr, 0, sizeof(arr)); 
코딩을하다가 중간에 초기화를 시켜줘야할 때가 있음 그럴 때 for문을 안쓰고 memset을 자주 쓴다. 
int arr[10] = {0, }; 
이렇게 해줘도 상관은 없긴한데,
만약 지역변수에서 배열을 1,000,000 선언하면 프로그램 터짐. 
그래서 전역변수로 선언을 하게되는데 
그걸 지역안에서 계속 사용을 하면서 초기화를 사용해줘야할 대 써야함. 


fill()

Naming Convension 한번 훑어보는 것도 좋을듯. 

