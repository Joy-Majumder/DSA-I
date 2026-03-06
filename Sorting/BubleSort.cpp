#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    // starting bubble sorting from here also this is the best efficient way of bubble sort!
    for(int i=0;i<n-1;i++){ // for iteration
        int flag = 0; // this is the another way of get that arr is swapped or not! if it got swapped then it will print 1 otherwise it will print 0 it means its not swapped!
        for(int j=0;i<n-1-i;j++){ // here we used i for time complex

                if(arr[j]>arr[j]){
                    //swap(arr[j],arr[j+1]);
                    //we can do it in traditional way
                    int temp = arr[j];
                    arr[j]= arr[j+1];
                    arr[j+1]=temp;
                    flag = 1;

                }
        }
        if(flag==0){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
