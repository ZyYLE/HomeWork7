#include "IntArray.h"

IntArray::IntArray(int length):m_length{ length }
{

    if (length > 0)
        m_data = new int[length] {};
}