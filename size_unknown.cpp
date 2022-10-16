/*
NAME - KETAN MATTOO
SID - 21105035
BRANCH - ECE
*/

/*
QUESTION:How would you search for an element in an array/list whose size is unknown?
SOLUTION: We can search an element in an array whose size is unknown in O(logn) time complexity provided that the array is in sorted order. We can do this by making some modification in binary search technique.
The concept behind this approach is:
  ->Take inital value of low as 0 and high as 1.
  ->Now increase high to high*2 until arr[high] exceed the key to be searched.
  ->Now search the element using binary search between low and high.
*/

#include <bits/stdc++.h>
using namespace std;

// CREATING THE FUNCTION SUCH THAT WE ARE NOT PASSING THE SIZE OF THE ARRAY TO THE FUNCTION.

// LINEAR SEARCH
int linear_search(int arr[], int element){
    for (int i = 0; ;i++){ // no condition to stop the loop until the element not found.
        if (arr[i] == element){
            return i;
        }
    }
}

// BINARY SEARCH
int binary_search_code(int arr[],int left,int right,int element)
{
    int mid = (left+right) / 2;
    while(left<=right)
    {
        if(arr[mid]>element)
        {
            right = mid - 1;
            mid = (left+right) / 2;
        }
        else if(arr[mid]<element)
        {
            left = mid+1;
            mid = (left+right) / 2;
        }
        else
        {
            return mid;
        }
    }

}

int binary_search(int arr[], int element)
{
    int low = 0;
    int high = 1;

    while (arr[high] < element)//if element to be found is still high the value at high index .
    {
        low = high;
        high = 2 * high;
    }

    return binary_search_code(arr,low,high,element);
}

int main()
{
    // you are given the starting index of the array.
    int *arr = new int[10000];
    int n;
    cout << "Number of elements in an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int element;
    cout << "ENTER THE ELEMENT TO SEARCH FOR : ";
    cin >> element;
    cout << endl;

    cout << "Index of " << element << " from LINEAR SEARCH is : " << linear_search(arr, element) << endl;
    cout << "Index of " << element << " from BINARY SEARCH is : " << binary_search(arr, element) << endl;
    delete[] arr;
}