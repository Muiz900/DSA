#include<iostream>
using namespace std;
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
#include <iostream>
#include <initializer_list>
using namespace std;

// Assume your Vector class is already here
// (You can reuse the Vector code you provided)

template <typename T>
class Queue {
private:
    Vector<T> data; // internal vector to store elements

public:
    Queue() {}

    // Add element at the end (enqueue)
    void enqueue(T val) {
        data.push_back(val);
    }

    // Remove element from front (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        data.removeByIndex(0);
    }

    // Get front element
    T front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            exit(1);
        }
        return data.front();
    }

    // Get rear element
    T back() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            exit(1);
        }
        return data.back();
    }

    // Check if queue is empty
    bool isEmpty() {
        return data.getSize() == 0;
    }

    // Get size of queue
    size_t size() {
        return data.getSize();
    }

    // Print queue elements
    void print() {
        data.print();
    }
};

