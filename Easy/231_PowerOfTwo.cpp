//. Given a positive integer, return true if it is a power of 2.
#include<iostream>
using namespace std;
bool powerOf2(int n){
    if(n==1) return true;
    if(n%2==0){
        return powerOf2(n/2);
    }
    return false;
}

int main(){
int n;
cin>>n;
cout<<powerOf2(n);   
}
