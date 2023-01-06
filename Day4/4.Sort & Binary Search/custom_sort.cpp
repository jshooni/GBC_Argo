#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

typedef struct Person{
    int height; 
    int weight; 
    int age; 
} PERSON;

bool compare(const PERSON &a, const PERSON &b){
    if( a.height > b.height) return true; 
    else if( a.height == b.height){
        if(a.weight > b.weight) return true;
        else if(a.weight == b.weight) {
            return a.age > b.age;
        }
        else return false; 
    }
    else return false; 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    vector<PERSON> V;
    V.push_back({170,61, 92});
    V.push_back({128,36, 10});
    V.push_back({182,82, 23});
    V.push_back({152,35, 25});
    V.push_back({201,91, 64});

    sort(V.begin(), V.end(), compare);
    
    for(int i=0; i<V.size(); i++) 
        cout << V[i].height << ' ' << V[i].weight << ' ' << V[i].age<<  '\n'; 

    return 0;
}