#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max(int *arr, int n){
    int maxi=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>maxi)
        maxi=arr[i];
    }
    return maxi;
}                  

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i++){
        cin>>arr[i];
    }
    clock_t start, end;
    start = clock();

    cout<<"max element is =>"<<max(arr,n)<<endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is :" << fixed
         <<time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;

}
