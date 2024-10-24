#include "IntArray.h"

#include <algorithm>

using namespace std;

#include <algorithm> // for std::copy_n

//#include <cassert> // for assert()

#include "BadIndex.h"  // Класс для обработки исключений 


IntArray::IntArray() = default;

IntArray::IntArray(int length) :m_length{ length }
{
        
    //assert(length >= 0); // здесь обработаем исключением случай когда length<0                ***
    if (length < 0)
    {
        throw BadIndex(length, "bad_length exeption: wrong length for container creation");
    }

    if (length > 0)
    m_data = new int[length] {};
}

IntArray::~IntArray()
    {
        delete[] m_data;
        
    }

IntArray::IntArray(const IntArray& a) : IntArray(a.getLength()) 
    {
        copy_n(a.m_data, m_length, m_data); 
    }

IntArray& IntArray::operator=(const IntArray& a)
    {
        
        if (&a == this)
            return *this;

        
        reallocate(a.getLength());
        copy_n(a.m_data, m_length, m_data); 

        return *this;
    }

    void IntArray::erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to nullptr here, otherwise it will         оставил комментарий чтобы перечитывать и запоминать причину
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    int& IntArray::operator[](int index)
    {
        // assert(index >= 0 && index < m_length); // заменяем исключением                                                      ***
        if ((index < 0) || (index > m_length))
        {
            throw BadIndex(index, "bad_range exeption: index out of range");
        };

        return m_data[index];
    }


    
    void IntArray::reallocate(int newLength)
    {
    
        erase();

    
//        if (newLength <= 0)              // можно отработать отрицательную длину исключением, или создать пустой массив                                    ***
//        return;

        if (newLength < 0)
        {
            throw BadIndex(newLength, "bad_length exeption: length cant be negative");
        };
        if (newLength == 0) return; // при нулевой длине просто создаемпустой массив

        m_data = new int[newLength];
        m_length = newLength;
    }

    
    void IntArray::resize(int newLength)
    {
        // if the array is already the right length, we're done
        if (newLength == m_length)
            return;

        // If we are resizing to an empty array, do that and return
        if (newLength <= 0) // отрицательную длину снова в исключения можно
        {
            erase();
            return;
        }

        

        int* data{ new int[newLength] };

        // Then we have to figure out how many elements to copy from the existing
        // array to the new array.  We want to copy as many elements as there are
        // in the smaller of the two arrays.
        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength }; // опять запомнить конструкцию

            copy_n(m_data, elementsToCopy, data); // copy the elements
        }

        
        delete[] m_data;

        // And use the new array instead!  Note that this simply makes m_data point
        // to the same address as the new array we dynamically allocated.  Because
        // data was dynamically allocated, it won't be destroyed when it goes out of scope.
        // пользуемся неудаляемостью !!
        m_data = data;
        m_length = newLength;
    }

    void IntArray::insertBefore(int value, int index)
    {
        // assert(index >= 0 && index <= m_length); // обрабатываем исключением                                     ***

       try
       {
           if ((index < 0) || (index > m_length))
           {
               throw "bad_range exeption inside Insert function ";
           };

       }
       catch (const char* exception)
       {
           cout << "Inner Exception: " << exception << endl;
           throw BadIndex(index, exception);
       }
        


        // First create a new array one element larger than the old array
        int* data{ new int[m_length + 1] };

        // Copy all of the elements up to the index
        copy_n(m_data, index, data);

        // Insert our new element into the new array
        data[index] = value;

        // Copy all of the values after the inserted element
        copy_n(m_data + index, m_length - index, data + index + 1);

        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void IntArray::remove(int index)
    {
        // Sanity check our index value
        // assert(index >= 0 && index < m_length);  // меняем на исключение

        // If this is the last remaining element in the array, set the array to empty and bail out
        if (m_length == 1)
        {
            erase();
            return;
        }

        // First create a new array one element smaller than the old array
        int* data{ new int[m_length - 1] };

        // Copy all of the elements up to the index
        copy_n(m_data, index, data);

        // Copy all of the values after the removed element
        copy_n(m_data + index + 1, m_length - index - 1, data + index);

        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    // A couple of additional functions just for convenience
    void IntArray::insertAtBeginning(int value) { insertBefore(value, 0); }
    void IntArray::insertAtEnd(int value) { insertBefore(value, m_length); }

    int IntArray::getLength() const { return m_length; }

    void IntArray::PrintArray()
    {
        for (int i = 0; i < m_length;i++) { cout << m_data[i] << endl; }

    }









