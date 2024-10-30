#pragma once
//#include <algorithm> // for std::copy_n

//template <typename TX> class TeArray
template <typename TX> class TeArray
{
private:
   int m_length{};
   TX* m_data{};

public:
   TeArray();

   TeArray(int length);

    ~TeArray();

   
    TeArray(const TeArray& a);


    TeArray& operator=(const TeArray& a);


    void erase();

    TX& operator[](int index);

    void reallocate(int newLength);

    void resize(int newLength);


    void insertBefore(TX value, int index);


    void remove(int index);


    void insertAtBeginning(TX value);
    void insertAtEnd(TX value);

    int getLength() const;

    void PrintArray();
    

};

