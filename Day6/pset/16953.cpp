#include <iostream>

using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    int A, B; 
    cin >> A >> B ; 
    int cnt=1; 

    while(1){
        if(B<A){
            cnt = -1; 
            break;
        }
        if(B == A) break; 

        else{
            if( B%2 == 0 ){  
                B /= 2; 
                cnt++; 
            }
            else if( B%10 == 1){
                B /= 10; 
                cnt++; 
            }
            else{
                cnt = -1; 
                break; 
            }
        }       
    }

    cout << cnt ; 
    return 0;     
}