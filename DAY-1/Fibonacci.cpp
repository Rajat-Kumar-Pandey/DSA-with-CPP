#include <iostream>
using namespace std;

int main(){
    int a=0,b=1,n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    cout<<"Fibonacci Series: ";
    for(int i=1;i<=n;i++){
        cout<<a<<" ";
        int next=a+b;
        a=b;
        b=next;
    }
    return 0;
}