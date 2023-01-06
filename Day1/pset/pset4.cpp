/**
 * 다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

    다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 
    한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
    다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. 
    (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.

필요한 세트수...
6,9를 제외한 나머지 숫자들이 한번씩 나오면 세트 하나 증발. 
그 이후 같은 숫자가 나오면 세트수 증가. 
6,9 말고 같은 숫자가 나오면 세트수가 증가한다. 
0~9의 vector에서 최댓값을 출력하면 될 것 같다.
한번 나오면 그냥 ++; 
66  6 9  9 3세트  
    그럼 최댓값 출력할 때만 6+9 / 2 한 거랑 나머지 최댓값이랑 비교를 해보자.  

*/

#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 

int main(void) {
    ios:: sync_with_stdio(false); cin.tie(0);
    
    int num;
    int n=0;  
    cin >> num; 
    int sum_n = num; 
    while(sum_n != 0){
        //cout << "sum_n : " << sum_n << endl; 
        sum_n/=10;
        n++;
    }

    //cout << "n : " << n << endl; 

    vector<int> V(10,0);
    for(int i=0; i<n; i++){
        V[num%10]++;
        num/=10;
    }
    
    int max=0; 
    for(int i=0; i<10; i++){
        //cout << "V[" << i << "] : " << V[i] << endl; 
        if(i==6 || i==9) continue; // 6이나 9는 건너뛴다. 
        if(V[i]> max) max = V[i];
    }
    
    float six_nine = V[6]+V[9]; 
    six_nine = ceil(six_nine/2); 
    
    if(max < (int)six_nine) max = (int)six_nine; 
    
    cout << max;

    return 0; 
}