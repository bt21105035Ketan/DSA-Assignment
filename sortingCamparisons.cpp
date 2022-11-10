/*
NAME : KETAN MATTOO
SID : 21105035
BRANCH : ECE
*/

#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY (O(n^2))
pair<int, int> bubbleSort(int arr[], int size){
    int swaps = 0;
    int comparisons = 0;
    for(int i = 0; i< size - 1; i++){
        for(int j = 0 ; j <size-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps ++; 
            }
            comparisons++;
        }
    }
    pair<int, int> output;
    output.first = swaps;    // it will hold the value swaps
    output.second = comparisons;    // it will hold the value of comparisons
    return output;
}

// TIME COMPLEXITY (O(n^2))
pair<int,int> selectionSort(int arr[], int size){
    int min_index;
    int swaps = 0;
    int comparisons = 0;
    for(int i = 0; i<size; i++){
        min_index = i;
        for(int j = i+1; j<size; j++){
            if(arr[j] < arr[min_index]){
                swaps++;
            }
            comparisons++;
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    pair<int, int> output;
    output.first = swaps;    // it will hold the value swaps
    output.second = comparisons;    // it will hold the value of comparisons
    return output;
}

int main(){
    int size;
    cout<<"Enter the size of array"<<" ";
    cin>>size;

    int arr[size];
    for(int i = 0; i< size; i++){
        cin>>arr[i];
    }
    
    pair<int, int> bubble = bubbleSort(arr, size);
    pair<int, int> selection = selectionSort(arr, size);

    cout<<"1. Comparing Bubble sort and Selection sort based on the number of comparisons:"<<endl;

    if(selection.second > bubble.second){
        cout<<selection.second - bubble.second<<" More Comparisons Required for Selection Sort."<<endl<<endl;
    }

    else if(bubble.second > selection.second){
        cout<<bubble.second - selection.second<<" More Comparisons Required for Bubble Sort"<<endl<<endl;
    }

    else{
        cout<<"Same Comparisons"<<endl<<endl;
    }

    cout<<"2. Comparing Bubble sort and Selection sort based on the number of swaps:"<<endl;

    if(selection.first > bubble.first){
        cout<<selection.first - bubble.first<<" More Swaps Required for Selection Sort."<<endl<<endl;
    }

    else if(bubble.first > selection.first){
        cout<<bubble.first - selection.first<<" More Swaps Required for Bubble Sort"<<endl<<endl;
    }

    else{
        cout<<"Same Swaps"<<endl<<endl;
    }

    cout<<"3. Both Algorithms written above are the InPlace Algorithms of both Sorting Methods"<<endl;
    cout<<endl;

    return 0;
}