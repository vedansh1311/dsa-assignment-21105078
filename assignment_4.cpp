// ASSIGNMENT - 4 (INPLACE AND OUTPLACE)

// Name - Vedansh Singh
// sid- 21105078

// An  In-place sorting algorithm is that kind of algorithm whose 
// space complexitylies between O(1) and O(logn).
// An Out-place sorting algorithm is that kind of algorithm whose
//  space complexity is greater than O(logn).
// We can say an in-place algorithm is an algorithm that does need a
// small extra space and produces an output in the same memory that
// contains the data by transforming the input ‘in-place’ whereas out-place 
// algorithm need extra space.



// INSERTION SORT

// In-Place Algorithm
#include <iostream>
using namespace std;

void insertion_sort_IP(int arr[],int n){
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

// Out-Place Algorithm
void insertion_sort_OP(int arr[],int start,int end){
    
   
    if(start==end){return;}
    int j=start+1;
    int temp=arr[j];
    while(start>=0){
        if(arr[start]>temp){
            arr[start+1]=arr[start];
            start--;
        }
        if(start==-1){arr[0]=temp;break;}
        if(arr[start]<=temp){arr[start+1]=temp;break;}
    }
    insertion_sort_OP(arr,start+1,end);
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    cout<<"number of elements";
    cin>>n;
    int arr[n],arr2[n];//Two array with same startze and elements

    cout<<"enter elements";
    for(int i=0;i<n;i++){cin>>arr[i];}

    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"initial array : ";print(arr,n);

    //Calling insertion sort using in-place algorithm.
    insertion_sort_IP(arr,n);
    cout<<endl;
    cout<<"final array : ";

    //printing the array
    print(arr,n);
    cout<<endl;

    //calling insertiong sort using out-place algorithm.
    insertion_sort_OP(arr2,0,n-1);
    cout<<"Array after out-place algorithm : ";

    //printing the array
    print(arr,n);
    cout<<endl;

}

/*
[ANS.3]
In-place techniques have lesser space complexity but are difficult to 
apply in algorithm whereas out-place techniques are easy to aplly but 
increases the space complexity of algorithm.
For exapmle if we want to reverse an array then its in-place algorithm
will be swaping the first and last element of array until we reach the 
middle of array,If we want to solve the same problem ustartng out-place 
algorithm we have to create one extra array of same startze and copy 
elements of original array from back to the front of new array,this 
algorith increases the space complexity to O(n) as we have creaed an 
extra array.
IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.
*/