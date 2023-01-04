/*
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 
각 문자가 연속해서 나타나는 경우만을 말한다. 

예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, 
kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, 
aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 
그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

첫째 줄에 단어의 개수 N이 들어온다.
N은 100보다 작거나 같은 자연수이다. 
둘째 줄부터 N개의 줄에 단어가 들어온다. 
단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
*/
#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm>
#include <unordered_set>
using namespace std; 

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif
/*
간단하게 가려면 그냥 문자열 하나 받고 / 판단을 해가지고 /  count++ 
어떻게 판단할건데? 
--> 
*/
int main(void){

    int N; 
    cin >> N; 
    int count=0; 

    for(int i=0; i<N; i++){
        bool flag = false; 
        // vector<int> V(26,0);
        vector<bool> S(26,false); 

        string str="";
        cin >> str;
        if(str.size()==1) continue; 

        for(int j=0; j<str.size(); j++){
            if(flag == true) break;
            if(j>0){
                if( (S[str[j]-'a'] == true ) && ( str[j] != str[j-1] )){
                    count++;
                    flag = true; 
                }    
            }
            // V[str[j]-'a']++;     
            S[str[j]-'a'] = true;   
        }
    }

    cout << N-count ; 

    return 0; 
}
