#include <iostream>
#include <vector>
#include <string> 

using namespace std;

// void func(int &arr[]){
//     for(int i=0; i<10; i++){
//         arr[i] = 100+i; 
//     }
//     return;
// }
void func(int& z){
    z = 123; 
    return ; 
}
int main(void) {
    // int arr[10]; 
    // for(int i=0; i<10; i++){
    //     arr[i] = 10+i; 
    // }
    
    // for(int i=0; i<10; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl << endl; 

    // func(arr); 
    // for(int i=0; i<10; i++){
    //     cout << arr[i] << ' ';
    // }

    int* ptr;
    cout << ptr << endl;
    cout << *ptr << endl;
    int x =100;
    cout << "x 의 주소 : " << &x << endl; 
    ptr = &x; 
    cout << "바뀐 ptr 의 주소 : " << ptr << endl; 
    cout << "x를 보았을때 ." << x << endl; 
    cout << "ptr을 보았을 때. " << *ptr << endl; 
    
    func(x);
    cout << "FUNC 이후 x : " << x << endl; 

    // char arr[100] = "Happy New fuck";
    char* pptr= "GHOST";
    // pptr = new char[20]; 
    cout << "고스트 : " << pptr << endl; 
    printf("new pptr!! : %p\n", pptr);
    cout << "dmddmdmdmdmdmdmdmdmdm"<< endl; 
    // for(int i=0; i<5; i++){
    //     printf("%d)설마? : %p\n",i, &pptr++);     
    // }
    cout << "dmddmdmdmdmdmdmdmdmdm"<< endl; 
    for(int i=0; i<5; i++){
        printf("printf : %d)설마? : %p -- %c\n",i, pptr,*pptr);
        cout << "cout : " << i << ": " << pptr << "--" << *pptr << "   응애응애 : " << pptr[i]<< endl;
        pptr++;
    }
    cout << "dmddmdmdmdmdmdmdmdmdm"<< endl; 
    cout  << &pptr << endl;

    char ch = 'B'; 
    printf("이것은 수류탄이오 !! : %p\n", &ch);
    cout << "..." << &ch << "..."  << endl; 
    ch = 'A' ;
    cout << ch << endl; 

    
    return 0; 
}