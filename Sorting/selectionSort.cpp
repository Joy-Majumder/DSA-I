#include <iostream>
using namespace std;
// selection sort
// 0 1 2 3 4 // index size
// 22 14 12 18 9

// it 0: 9 14 12 18 22 // here swapped first and last element
// it 1: 9 12 14 18 22
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i =0;i<n;i++) {
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
            swap(arr[i],arr[min_index]);
        }
        // for if we want to chck every iteration
         //for(int i=0;i<n;i++){
           // cout<<arr[i]<<" ";
        //}
    }
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
}
