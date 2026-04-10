#include<iostream>
#include<vector>

using namespace std;

// void Func1(int* a){
//     *a = 69;
// }

int main(void){
    int a = 100;
    int b = 10;
    // int* ptr = &a;
    // cout<<"A : "<<&a<<endl;
    // cout<<"Pointer 1 : "<<ptr<<endl;
    // // p to p
    // int** ptr2 = &ptr;
    // cout<<"Pointer 2 : "<<ptr2<<endl;
    // cout<<"Pointer 2 : "<<**(ptr2)<<endl;
    // int* ptr21 = NULL; // zsh: segmentation fault  "/Users/joy0x1/Downloads/Code/DSA 1/"pointer 
    // cout<<*ptr21<<endl;
    // Pass by ref
    // Func1(&a);
    int* ptr1 = &a;
    int* ptr2 = &b;
    cout<<(ptr1-ptr2)<<endl;
    
}