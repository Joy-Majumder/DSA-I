/*

Searching :
    1. linear search
    2. Binary search
    3. ternary search

1. Linear search
suppose u got a arr like:
    5 4 6 8 10 12 9
here we have to find 10 so its searching!
In this array we gonna check where 10 placed from first to last when 10 found then return found!

here is the logic for Linear searching:

    for(int i = 0; i<n;I++){
        if(arr[i]==item){
            cout<<"Found at place"<<i<<endl;
        }
        //break;
    }
     if(i==n){
        cout<<"Not found"<<endl;
    }

Time complexity: O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    // by this loop we gonna take input for array
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    int item;
    cout<<"Enter item No: ";
    cin>>item;
    // starting linear search from here!
    int plug = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]==item)
        {
            cout<<"Found at index: "<<i<<endl;
            plug = 1;
            break;
        }
        //break;
    }
    if(plug==0){
        cout<<"Not found"<<endl;
    }
// main();
}
