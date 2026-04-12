#include<iostream>
#include<vector>

using namespace std;

int SingleNumber(vector<int>& nums){
    int ans = 0;
    for(int value: nums){
        ans = ans ^ value;
    }
    return ans;
}

int main(){
    vector<int> a = {4,1,2,1,2};
    int x = SingleNumber(a);
    cout<<x<<endl;
}