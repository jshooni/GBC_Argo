/**
 * 알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.
 * 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
*/


#include <iostream>
#include <vector>
using namespace std; 

int main(void) {
    ios:: sync_with_stdio(false);
    cin.tie(0);

    string str; 
    getline(cin, str); 

    //cout << "string : " << str << endl ;
    //cout << "string size : " << str.size() << endl; 
    
    vector<int> V(26,0);
    
    for(int i=0; i<str.size(); i++){
        V[str[i] - 'a']++;
    }
    
    for(int i=0; i< V.size(); i++){
        cout << V[i] << ' ' ; 
    }
    




    return 0; 
}
