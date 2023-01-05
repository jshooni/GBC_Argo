#include <iostream> 
using namespace std; 

int f(int n){
    if(n<=1 ) return n ;
    else return f(n-1) + f(n-2);
}
int main(void){
    int a; 
    a = f(7);
    cout << a << endl;
}