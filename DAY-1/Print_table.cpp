#include <iostream>
using namespace std;

int main() {
    int n,m;
    cout << "Enter the number to print table and the number of rows: ";
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cout<<n<<" * "<<i<<" = "<<n*i<<endl;
    }
    return 0;
}