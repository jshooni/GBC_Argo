#include <iostream>
#include <vector>

#define INF 99999997

using namespace std; 

int main(void){
    vector<int> v_int(10 , INF); 
    vector<double> v_double(10 , INF); 

    cout << 2/3 << endl;
    cout << 2.0/3 << endl;
    cout << 2 / 3.0 << endl;

    cout << v_int[0]/222221 << endl; 
    cout << v_double[0]/222221 << endl; 


    return 0 ; 
    
}   