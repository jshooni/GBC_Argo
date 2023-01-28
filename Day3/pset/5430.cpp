/**
 * AC는 정수 배열에 연산을 하기 위해 만든 언어
 * 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)
 * 
 * 함수 R은 배열에 있는 수의 순서를 뒤집는 함수
 * D는 첫 번째 수를 버리는 함수 ( 배열이 비어있는데 D를 사용한 경우에는 에러가 발생 )
 * 
 * 
 * 함수는 조합해서 한 번에 사용할 수 있다.
 * "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수
 * 
 * 
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std; 

/*
[] 양쪽은 무시한 채 
R 나오면 Reverse 'up' ->  뒤에서부터 삭제 
D 나오면 REverse에 따라서 삭제 실시. 
출력할 때는 그냥 앞뒤로 쭉쭉 출력하면되는거임.
*/

void R_func(string met){
    char a; 
    for(int i=0; i<met.size()/2; i++){
        a = met[i]; 
        met[i] = met[met.size()-1-i]; 
        met[met.size()-1-i] = a;
    }
    // return met.data(); 
    return; 
}

void D_func(string met){
    int i=0; 
    while(i< met.size()-1){
        met[i] = met[i+1]; 
        i++;
    }
    met[met.size()-1] = '\0'; 
    return; 
}

char* modify_metrix(string met, int n){
    char* a = new char[n];
    string s; 
    int j=0; 
    for(int i=0; i<met.size(); i++){
        if(s[i]=='[' || s[i] == ',' || s[i]==']') continue; 
        else {
            a[j] = s[i];
            j++;
        }
    }
    return a;
}

int main(void){
    int T; 
    cin >> T;
    
    queue<char> Q;
    string str;
    string str_set; 

    for(int i=0, n; i<T; i++){
        cin >> str; // RDD 
        for(int j=0; j<str.size(); j++) Q.push(str[j]); 

        cin >> n ;
        cin >> str_set; 
        string modi_set = modify_metrix(str_set,n);
        cout << "modified modi_set : " << modi_set << endl;
        bool flag = false;
        
        for(int j=0; j<Q.size(); j++){
            if(Q.front() == 'R') R_func(modi_set);
            else if (Q.front() == 'D'){
                if(modi_set.size() == 0) {
                    flag = true; 
                    cout << "error" << endl; 
                    break;
                }
                else D_func(modi_set);
            }
            Q.pop();
        }

        if(flag == false){
            int k= modi_set.size(); 
            cout << '[';
            for(int i=0; i<modi_set.size(); i++){
                if(i != modi_set.size()-1)
                    cout << modi_set[i] << ",";
                else cout << modi_set[i]; 
            }
            cout << ']' << endl;
        }
   
    }
    return 0; 
}
