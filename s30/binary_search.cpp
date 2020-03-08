
// Time Complexity :O(logn)
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : N/A
// Any problem you faced while coding this : N/A


// Your code here along with comments explaining your approach

//Insertion of an element in Binary Search


#include <iostream>

using namespace std;

int binary_search(int *arr, int value, int low, int high){
    int index =-1;
    
    if(low<=high){
       int mid = low + ((high-low)/2);
        if(arr[mid] == value){
            return mid;
        }
        //Call upper half
        if (arr[mid] < value ){
          index=  binary_search(arr,value, mid+1, high);
        }//Call lower half
        else{
          index=  binary_search(arr,value, low, mid-1);
        }
    }
    return index;
}


int main(void){
    int arr[] = {5, 7,12,30,39,45,58,66,71,90};
    int index;
    index = binary_search(arr, 12, 0, sizeof(arr)/sizeof(int));
    cout<<index<<"\n";
    return 0;
}



