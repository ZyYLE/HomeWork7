#pragma once
#include <algorithm> // for std::copy_n

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray();

    IntArray(int length);

    ~IntArray();

    IntArray(const IntArray& a);


    IntArray& operator=(const IntArray& a);


    void erase();

    int& operator[](int index);

    void reallocate(int newLength);

    void resize(int newLength);


    void insertBefore(int value, int index);


    void remove(int index);


    void insertAtBeginning(int value);
    void insertAtEnd(int value);

    int getLength() const;

    void PrintArray();
};

