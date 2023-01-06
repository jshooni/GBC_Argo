/**
 * 두 영어 단어가 철자의 순서를 뒤바꾸어 같아질 수 있을 때, 
 * 그러한 두 단어를 서로 애너그램 관계에 있다고 한다. 
 * 
 * 예를 들면 occurs 라는 영어 단어와 succor 는 서로 애너그램 관계에 있는데, 
 * occurs의 각 문자들의 순서를 잘 바꾸면 succor이 되기 때문이다.
 * 
 * 한 편, dared와 bread는 서로 애너그램 관계에 있지 않다. 
 * 하지만 dared에서 맨 앞의 d를 제거하고, 
 * bread에서 제일 앞의 b를 제거하면, 
 * ared와 read라는 서로 애너그램 관계에 있는 단어가 남게 된다.
 * 
 * 두 개의 영어 단어가 주어졌을 때, 
 * 두 단어가 서로 애너그램 관계에 있도록 만들기 위해서 제거해야 하는 최소 개수의 문자 수를 구하는 프로그램을 작성하시오. 
 * 문자를 제거할 때에는 아무 위치에 있는 문자든지 제거할 수 있다.
 * 
 * 첫째 줄과 둘째 줄에 영어 단어가 소문자로 주어진다. 
 * 각각의 길이는 1,000자를 넘지 않으며, 적어도 한 글자로 이루어진 단어가 주어진다.
 * 
 * 서로 애너그램 관계가 없을 때 -> 몇개의 문자를바꿔아하는가. 
 * 일단 애너그램인지 판별이 가능해야하지 않을까. 
 * 
 * 

"제거해야 하는 최소 개수의 문자 수"

aabbcc
kkeebb  --> 8개를 삭제하면 bb가 남음.
o(n)이 너무 커지지 않았으면 좋겠는데... 음... 

최소 몇개를 제거해야하나 -> 
26벡터를 하나 선언을 하고. 이중백터.? 를해서 둘다 영이 아닌 알파벳의 개수를 지우면되는거 아닌가. ? 
교집합 구하듯이 A+B-AB 이런식으로 ㅇㅇ 



*/
#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm>
using namespace std; 

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

int main(void){
    ios:: sync_with_stdio(false); cin.tie(0);
    string str1, str2; 
    cin >> str1 >> str2; 

    DPRINT(cout <<"str1: " << str1<< endl);
    DPRINT(cout <<"str2: " << str2<< endl);
    
    sort(str2.begin(), str2.end());
    sort(str1.begin(), str1.end());
    
    // DPRINT(cout <<"sorted str1: " << str1<< endl);
    // DPRINT(cout <<"sorted str2: " << str2<< endl);

    vector<int> V(26,0);
    vector<int> S(26,0); 


    for(int i=0; i<str1.size(); i++){
        V[str1[i]-'a']++;
    }
    for(int i=0; i<str2.size(); i++){
        S[str2[i]-'a']++;
    }
    
    int count=0; 
    for(int i=0; i<26; i++){
        DPRINT(cout << "V[" << i << "] : " << V[i] << "\t" << "S[" << i << "] : " << S[i] << endl);
        if(V[i] == S[i]) continue; 

        else if(V[i]>S[i]){
            while(V[i]!=S[i]) {
                DPRINT(cout << "\tV[i] : " << V[i] << endl);
                V[i]--; 
                count++;
            }
        }
        else
            while(V[i]!=S[i]) {
                S[i]--; 
                count++;
            }
        
    }
    cout << count << endl; 
    
    return 0; 
    
}