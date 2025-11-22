#include <iostream>

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
        delete[] data;
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
    size_t getSize()
    {
        return this->size;
    }
};
template <typename T>
class queue
{
    Vector<T> data;

public:
    void enqueue(T val)
    {
        if (data.getSize() == 0)
            data.push_back(val);
        else
            data.push_back(val);
        rearIndex++;
    }
    void dequeue()
    {
        data.removeByIndex(0);
        rearIndex--;
    }
    T front()
    {
        if (data.getSize == 0)
        {
            cout << "Empty Queue" << endl;
            return;
        }
        return data.front();
    }
    T back()
    {
        if (data.getSize() == 0)
        {
            cout << "Empty Queue" << endl;
            return;
        }
        return data.back();
    }
}

;