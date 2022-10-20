// KETAN MATTOO
// ECE 21105035
/*      

Ques 1:  What is the difference between in-place and out-place sorting algorithms?
Ans: "In-Place" 1)sorting algorithm is algorithm whose space complexity lies between O(1) and O(logn) both included.
2) An in-place algorithm may require a small amount of extra memory for its operation. However, the amount of memory 
required must not be dependent on the input size and should be constant.

"Out-Place" 1) sorting algorithm is algorithm whose space complexity is 
greater than O(logn).
2) An algorithm that is not in-place is called a not-in-place or out-of-place algorithm. Unlike an in-place algorithm, 
the extra space used by an out-of-place algorithm depends on the input size.
*/


//Ques 2: Implement Insertion sort in both (in-place and out-place) manner.

//[Ans.2]
//Insertion Sort Using In-Place Algorithm
#include <iostream>
using namespace std;
//Creating Insertion Sort function
void insertion_sort_InPlace(int arr[],int n){
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

//Insertion Sort Using Out-Place Algorithm
void insertion_sort_OutPlace(int arr[],int start_index,int end_index){
    if(start_index == end_index){return;}
    int j=start_index+1;
    int temp=arr[j];
    while(start_index>=0){
        if(arr[start_index]>temp){
            arr[start_index+1]=arr[start_index];
            start_index--;
        }
        if(start_index==-1){
            arr[0]=temp;break;
            }
        if(arr[start_index]<=temp){
            arr[start_index+1]=temp;break;
            }
    }
    insertion_sort_OutPlace(arr,start_index+1,end_index);
}
//Function to print array
void print(int arr[],int n){
    for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		}
}
int main(){
    int n;
    //Taking Input array
    cout<<"ENTER NUMBER OF ELEMENTS IN THE ARRAY: ";
    cin>>n;
    int arr[n],arr2[n];//Two array with same size and elements
    cout<<"ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"ARRAY BEFORE SORTING : ";print(arr,n);
    //Calling insertion sort using in-place algorithm.
    insertion_sort_InPlace(arr,n);
    cout<<endl;
    cout<<"ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    //printing the array
    print(arr,n);
    cout<<endl;
    //calling insertiong sort using out-place algorithm.
    insertion_sort_OutPlace(arr2,0,n-1);
    cout<<"ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    //printing the array
    print(arr,n);
    cout<<endl;

}

/* Ques 3: Suggest some practical examples of using in-place and out-place techniques.
 
Ans 3 : "In-place" In-place algorithms are usually used in an embedded system that runs in limited memory. They 
reduce the space requirements to a great extent, but the algorithm time complexity increases in some cases.

"Out-place" The standard merge sort algorithm is an example of out-of-place algorithm as 
it requires O(n) extra space for merging. 
*/