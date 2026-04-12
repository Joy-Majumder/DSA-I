#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
using namespace std;

// here we are studing couting sort and its "Not comparisson sort"
// also its the one of the fastest sort
void printArray(vector<int>arr,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int maximum(vector<int>& arr,int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
    
}

void countSort(vector<int>& arr, int n){
    int i,j;
    // finding the max value in A
    int max = maximum(arr,n);
    int* count = (int *) malloc((max+1)*sizeof(int)); // create the count array 
    // init the array elements to 0 
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    // increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    i = 0; // counter for the count array
    j = 0; // counter for main array
    while (i <= max)
    {
        if(count[i]>0){
            arr[j] = i;
            count[i] -= 1; // count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
    

}

int main(){
    vector<int>arr = {9,1,4,14,4,15,6};
    int n = 7;
    printArray(arr,n);
    countSort(arr,n);
    printArray(arr,n);
}