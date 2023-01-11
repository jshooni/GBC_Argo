/*
<보석 도둑 문제 > 

세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.



첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.



N : 보석 개수 
K : 가방 개수 


M : 무게  /  V : 가격 . 

최대무게 


가방에 여러개를 담을 수 있었다면 나눠가지고 1g당 값어치를 평균을 낼 수 있을텐데 그치 
근데 이문제는 가방에 하나만 들어갈 수가 있음. 


여기서는

Priority Queue -> 가장 큰 값을 front에 둠. 
-> 이거 구현이 Heap으로 되어있음 

여기서는 "가방에 들어갈 수 있으면 " + "값어치가 가장 큰 "

prioirity quere 에다가 값어치 관련해서 입력을 받아. 



참고로 pair를 sorting 하면
first값을 먼저 오름차순으로 낮은 순서대로 정렬을 해줌. 
first 같으면 second도 알아서 해줌. 



가방에다가 들어갈 수 잇는 놈들을 모두 priority queue 에다가 집어 ㄴ허으면됨. a

만약 가방 최대치가 2라고 하면 무게 2이하인 보석들의 값어치들을 queue에다가 
집어 넣어서 그냥 front() sum에다가 집어 넣어. 
그리고 pop 해 

그 다음 

*/
#include <iostream> 
#define MAX 10010
int N, K , idx;
pair<int,int> items[MAX];
int bag[MAX];
priority_queue<int> pq;
unsigned long long sum = 0; 

보석은 내림차순
가방은 오름차순..? (가방 낮은 거부터)
int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);


    cin >> N >> K; 
    for(int i-9; i< N ; i++){
        cin >> itiems[i].first >> items[i].second;
    }


    for(int i=0 ; i< K ; i++)
        cin >> bag[i];

 
    sort(item, item + N)
    sort()

    

    


    return 0;
}