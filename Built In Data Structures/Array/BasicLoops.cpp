    #include<iostream>
    using namespace std;
    int main() {
        
        cout<<"Enter Size of an Array: ";
        int size=0;
        cin >> size;
        int arr[size];
        cout << "Enter " << size << " elements of the array:" << endl;
       // Using a for loop to take input for the array
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        // Using a for loop to iterate through the array
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Using a range-based for loop to iterate through the array
        cout << "Using range-based for loop:" << endl;
        for (const auto &element : arr) {
            cout << element << " ";
        }
        cout << endl;

        //using loop to find the sum of the array elements
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        cout << "Sum of array elements: " << sum << endl;
        sum=0;
        //Using for based loop to find the sum of the array elements
        for (const auto &element : arr) {
            sum += element;
        }
        cout << "Sum of array elements using range-based loop: " << sum << endl;

        return 0;
   

    }