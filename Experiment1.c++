#include <iostream>
using namespace std;

int main(){
    int arr[40],n,posn,x,i;

    cout<<"Enter the size of array: ";
    cin >> n;

    cout<<"Enter the element of the array : ";
    for(int i = 0; i < n; i++){
        cin>> arr[i];
    }

    // Insertion at beginning 
    cout <<"Enter the element to be inserted at beginning: ";
    cin >> x;
    for(int i = n; i > 0; i--){
        arr[i]=arr[i - 1];
    }
    arr[0]=x;
    n++;

    cout<< "New array elements are : ";
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }

    // Insertion at middle or any position
    cout << endl << "Enter the position to insert the element: ";
    cin >> posn;
    cout << "Enter the element to insert at position " << posn << ": ";
    cin >> x;
    for(int i = n; i >= posn; i--) {
        arr[i] = arr[i-1];
    }
    arr[posn-1] = x; 
    n++;

    cout<< "New array elements are : ";
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }

    // Insertion at end
    cout << endl << "Enter the element to be inserted at end: ";
    cin >> x;
    arr[n] = x;
    n++;

    cout<< "New array elements are : ";
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }


    // Deletion from beginning
    if (n > 0) {
        for(int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        cout << "\nArray after deletion from beginning: ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    } else {
        cout << "\nArray is empty, cannot delete from beginning!";
    }

    // Deletion from a specific position
    cout << "\n Enter the position to delete the element from: ";
    cin >> posn;
    if(posn < 1 || posn > n) {
        cout << "Invalid position!" << endl;
    } else {
        for(int i = posn - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        } 
        n--; 
        cout << "Array after deletion from position " << posn << ": ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }

    // Deletion from end
    if (n > 0) {
        n--;
        cout << "\nArray after deletion from end: ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    } else {
        cout << "\nArray is empty, cannot delete from end!";
    }

    return 0;
}
