#include <iostream> 
#include <vector>
#include <stack> 

using namespace std; 
/*

8 4 3 

*/
int main(void){
    
    stack<int> s;
    int N; 
    cin >> N; 
     
    vector<int> v(N,0);
    int arr[N];
    bool flag= false; 
    for(int i=0, a; i<N; i++){
        arr[i] = i+1; 
        cin >> a ; 
        v.push_back(a); 
    }
    
    int n=1; 
    int i=0; 
    while( n < N ){
        s.push(n);
        cout << '+' << endl;

        while(1)
            if(s.top() == arr[i++]){
                s.pop(); 
                cout << '-' << endl; 
            }

        if(s.empty() && n == N ){
            flag =1; 
            break; 
        }        
    }


    

    
    

    return 0; 
}