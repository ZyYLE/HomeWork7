#pragma once
class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;                                       //������� ���������;
    IntArray(int length);                                       //������� ���������;

    IntArray(const IntArray& a);                                // ����������� ���������;
    int& operator[](int index);                                 //�������� ������ � ������ �������� ���������� �� �������;
    
    void Resize(int newsize);                                   //�������� ������ ����������;

    void Insert(int index, int mdata);                          //�������� ������� � ��������� �� ������� index;

    void Delete(int index);                                     //������� ������� �� ���������� �� ������� index

    int Find(int value);                                        // ����� �� ��������


  
};




/*

        ������� ���������;
        ����������� ���������;
        �������� ������ � ������ �������� ���������� �� �������;
        �������� ������ ����������;
        �������� ������� � ���������;
        ������� ������� �� ����������.

���������

�������������� ���� ����� �������� �� ���������� ������� � ������ � ����� � ������ � ���������� �������� �� ��������.
*/