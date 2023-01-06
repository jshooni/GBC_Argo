#include <iostream> 
using namespace std; 

//첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.
//모래시계 만드는거임.

void printstar(void);
void printblank(void);
int main(){
    int N; 
    cin >> N; 
    int height = N*2 -1; // 무조건 홀수. 
    int star = height;
    int blank =0; 

    for(int i=0; i<height; i++){
        for(int j=0; j<blank; j++)
            printblank();
        for(int j=0; j<star; j++)
            printstar(); 
        cout << endl; 

        if(i<height/2){ 
            star-=2; 
            blank++; 
        } 
        else{
            star+=2;
            blank--; 
        }
    }
}

void printstar(void){
    cout << "*" ; 
}
void printblank(void){
    cout << " "; 
}