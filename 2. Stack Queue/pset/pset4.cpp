/*
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 
스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아
제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 
 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 
이를 계산하는 프로그램을 작성하라.


첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 
둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 
물론 같은 정수가 두 번 나오는 일은 없다.

입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. 
push연산은 +로, pop 연산은 -로 표현하도록 한다. 
불가능한 경우 NO를 출력한다.

4 3 6 8 7 5 2 1
*/

        /**
         *  i ==0 일 때는 스택에 vector.top() 전까지 차례대로 집어넣어. 
         * 그이후에는 ex)3 이면 4랑 비교해서 큰지 작은지 확인한다음에 Pop을 하던 push 차례대로 하던 해. 
         * 만나면 멈추고, 스택에 저장을 하고 팝을 해. 
         * 
         * 아니야 
         * 
         * 스택만을 이용해보자. 
         * 내가 입력한 값이 나올 때까지 그치? 그러면 스택에다가 저장을 하는거야.
         * --> 스텍을 무조건 이용을 해야함. 
         * 
         * 
         * 
        */

#include <iostream> 
#include <string> 
#include <vector> 
#include <stack> 

using namespace std; 


int main(void) {
    ios:: sync_with_stdio(false); cin.tie(0);
    
    int N; 
    cin >> N; 

    vector<string> V; 
    vector<int> vec(N); //
    stack<int> s; 

    for(int i=0; i<N; i++){
        cin >> vec[i];
    }

    bool flag = false ;


    for(int i=0; i<N; i++){
         cout << "-" << i << "번째 "<< endl; 
        if (flag==true) break; 


        if(i==0){
            for(int j=1; j<=vec[i]; j++){
                s.push(j);
                V.push_back("+");
                cout << "이것은 첫번째 stack top : " << s.top() << endl ;
            }
        }
        if (s.top() == vec[i]){
            s.pop(); 
            V.push_back("-");
        }

        else if ( s.top() < vec[i] ){
            while(1){
                if(vec[i] == s.top()) break; 
                V.push_back("+");
                s.push(s.top()+1); 

                cout << "vec[i] < s.top 일때 : " << s.top() << endl; 
            }
        }
        else if ( s.top() > vec[i] ){
            while(1){
                if(vec[i] == s.top()) break; 
                V.push_back("-");
                s.pop();

                if(s.empty()){
                    flag=true; 
                    break;
                } 
            }
        }


        cout << "flag 상태 : " << flag << endl; 
        cout << "s.top : " << s.top() << endl; 
    }

    if(flag==false){
        for(auto iter = V.begin() ; iter != V.end() ; iter++) {
            cout << *iter << " ";
        }
        cout << endl; 
    }
    else
        cout << "NO" << endl; 

    
}

