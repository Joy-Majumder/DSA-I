#include<iostream>
#include<vector>

using namespace std;

int main(void){
    // vector<int>vec;
    // vec = {1,2,3,4,5};
    // cout<<vec[0];   
    vector<int>vec;

    cout<<"Size of : "<<vec.size()<<endl; // this is used for previewing size of the vector
    
    vec.push_back(69); // this is used to push elemnts in a vector
    vec.push_back(96); // we can see that the numbers of push back prints in a order because it push from the back 
    vec.push_back(88); 
    cout<<"Size after push back : "<<vec.size()<<endl; 
    
    vec.pop_back(); //by using this we want to delete the last index elemnt in a vector we have 
    cout<<"Size after pop back : "<<vec.size()<<endl; // when something pop out then it automatically reduce the size like : n - 1

    vec.front(); // it means we want to return the front value or starting element
    cout<<"Starting value is : "<<vec.front()<<endl;

    vec.back(); // it means we want to return the back value or last element
    cout<<"Last elemnt is : "<<vec.back()<<endl;
    
    cout<<"'at' used elemnt is : "<<vec.at(0)<<endl; // at is actually alt version of vec[i] here we use : vec.at(i) and in e.g : here it will prints the value of the 0th index
                                              // and 0th index elemnt is 69 so it will print 69 now

    
    for(int val: vec){ //for each loop here
        cout<<"Value are : "<<val<<endl;
    } // prints 69 and 96 because in the beginning we used a vector function named pop back that actually removed the last elemnt thats why here prints only 69 and 96

    
}