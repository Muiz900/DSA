#include <iostream>
#include <initializer_list>
#include <cmath>
using namespace std;
template <typename T>
class Vector
{
private:
    T *data;
    size_t size;
    size_t capacity;

public:
    Vector() : data(nullptr), size(0), capacity(0)
    {
    }
    Vector(size_t size, T val) : size(size), capacity(1)
    {
        while (size > capacity)
        {
            capacity *= 2;
        }
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = val;
        }
    }

    Vector(initializer_list<T> list)
    {
        size = list.size();
        capacity = 1;
        while (size > capacity)
        {
            capacity *= 2;
        }
        data = new T[capacity];
        size_t i = 0;
        for (const T &val : list)
        {
            data[i++] = val;
        }
    }
    void push_back(T &val)
    {
        if (size != capacity)
        {
            data[size++] = val;
        }
        else
        {
            T *new_data = new T[capacity * 2];
            for (size_t i = 0; i < size; ++i)
            {
                new_data[i] = data[i];
            }
            new_data[size++] = val;
            delete[] data;
            data = new_data;
            capacity *= 2;
        }
    }
    void pop_back()
    {
        if (size > 0)
        {
            --size;
        }
    }
    T front()
    {
        return data[0];
    }
    T back()
    {
        return data[size - 1];
    }
    T at(size_t index)
    {
        if (index >= size)
        {
            cout << "Index out of bounds" << endl;
        }
        return data[index];
    }
    ~Vector()
    {
        delete [] data;
    }

    T *begin()
    {
        return data;
    }
    T *end()
    {
        return data + size;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void removeByValue(T val)
    {
        int i = 0;
        for (i = 0; i < size; i++)
        {
            if (data[i] == val)
            {
                break;
            }
        }
        if (i == size)
        {
            cout << "Element not found" << endl;
            return;
        }
        for (int j = i; j < size - 1; j++)
        {
            data[j] = data[j + 1];
        }
        size--;
    }
    void removeByIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
    const T &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds!" << endl;
            
        }
        return data[index];
    }
    size_t getSize(){
        return this->size;
    }
    
};

int main()
{

    Vector<int> vec1 = {1, 2, 3, 4, 5,6,7,8};
    cout << "Elements in vec1: ";
    vec1.print();
    int element = 5;
    for (size_t i = 0; i < vec1.getSize(); i++)
    {
        if (vec1[i] == element)
        { 

            vec1.removeByIndex(i);
        }
    }
    cout << endl;
    cout<<"After Removing Element"<<endl;
    vec1.print();

int n;

Vector<int>vec2;
    cout<<"Enter Amount of Numbers You want to enter:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" Element:";
        cin>>element;
        vec2.push_back(element);
    }
    int even=0,odd=0;
    vec2.print();
    for(size_t i=0;i<vec2.getSize();i++)
    {
        if(vec2[i]%2==0)
        {
            even++;
        }else if(vec2[i]==0){
            
        }else{
            odd++;
        }
    }
    cout<<"Even Numbers:"<<even<<endl;
    cout<<"Odd Numbers:"<<odd<<endl;
}