

int main() {
    while( i< N){
    int k = arr[i];

    if( !s.empty() && s.top() == k)  {
        s.pop();
        i++;
        str += "-";
    }
    else{
        if( curr <= k){
            s.push(++curr);
            str += "+";
        }
        else{
            flag = true; 
            break;
        }
    }
}
