#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<int>& arr)
{

    cout << "[";
    for (int val = 0; val < arr.size(); val++)
    {
        cout << arr[val] << (val < arr.size() - 1 ? "," : "");
    }
    cout << "]" << endl;
}

void Q1()
{
    vector<string> names = {"Ubaid", "Ali", "Fahad", "Usman", "Umair"};
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    int comparisons = 0, index = -1;
    for (int i = 0; i < names.size(); i++)
    {
        comparisons++;
        if (names[i] == name)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
        cout << "Patient found at index " << index << ". Comparisons: " << comparisons << endl;
    else
        cout << "Patient Not Found. Comparisons: " << comparisons << endl;
}
void Q2()
{
    vector<int> number = {101, 105, 110, 120, 130, 150};
    int bus;
    cout << "Q2: Enter bus number to search: ";
    cin >> bus;
    int left = 0, right = number.size() - 1, mid;
    bool flag = false;
    cout << "Mid indices checked: ";
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        cout << mid << " ";
        if (number[mid] == bus)
        {
            flag = true;
            break;
        }
        else if (number[mid] < bus)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << endl;
    if (flag)
        cout << "Booking Confirmed." << endl;
    else
        cout << "Bus Not Available." << endl;
}
void Q3()
{
    vector<int> marks = {56, 78, 45, 89, 67, 90, 34};
    int n = marks.size(), swaps = 0, comparisons = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (marks[j] > marks[j + 1])
            {
                int temp=marks[j];
                marks[j]=marks[j+1];
                marks[j+1]=temp;
                swaps++;
            }
        }
    }
    cout << "Sorted marks: ";
    print(marks);
    int searchMark = 0, pos = -1, linComparisons = 0;
    cout << "Enter mark to search: ";
    cin >> searchMark;
    for (int i = 0; i < n;i++)
    {
        linComparisons++;
        if (marks[i] == searchMark)
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
        cout << "Mark found at position " << pos << endl;
    else
        cout << "Mark not found" << endl;
    cout << "Swaps: " << swaps << ", Bubble Sort Comparisons: " << comparisons
         << ", Linear Search Comparisons: " << linComparisons << endl;
}

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void Q4()
{
    vector<int> prices;
    int price;
    bool flag = true;
    while (flag)
    {
        char c = 'l';
        cout << "Do you want to insert new price(y/n)" << endl;
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            cout << "Enter Price to insert" << endl;
            int p = 0;
            cin >> p;
            prices.push_back(p);
            insertionSort(prices);
            print(prices);
            if (prices.size() > 9)
            {
                cout << "Cheapest: ";
                for (int i = 0; i < 2; i++)
                    cout << prices[i] << " ";
                cout << "Expensive: ";
                for (int i = prices.size() - 2; i < prices.size(); i++)
                    cout << prices[i] << " ";
                cout << endl;
            }
        }
        else if (c == 'n' || c == 'N')
        {
            flag = false;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
}

int main()
{
    Q1();
    cout << "------------------------" << endl;
    Q2();
    cout << "------------------------" << endl;
    
    Q3();
    cout << "------------------------" << endl;
    Q4();
    return 0;
}