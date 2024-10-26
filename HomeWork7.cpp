

#include <iostream>
#include "IntArray.h"
#include "BadIndex.h"

using namespace std;


int main()
{
    cout << "Creating container(10) from 0 to 9, fill with 20+i \n";
    IntArray MyArray(10);

    for (int i = 0; i < 10; i++)
    {
        MyArray[i] = 20 + i; 
    };

    // выполняем корректные операции: 

    IntArray My2Array; //создаем пустой массив
    My2Array = MyArray; // копируем туда предыдущий
   
    My2Array.PrintArray(); // распечатываем новый

    
    My2Array.insertAtEnd(200);
    My2Array[4] = 100;

    cout << "Adding value 200 to the end, change #5 to 100" << endl;
    My2Array.PrintArray(); // распечатываем 


    //проверяем исключеия
 
    try
    {
        // создаем массив отрицательной длины
        //IntArray m3(-2);

        //пытаемся достать элемент вне диапазона
        //cout << My2Array[12];

        //меняем длину на отрицательную
        //My2Array.reallocate(-1);

        //протоколирование и передача исключения наружу - try/catch  внутри метода класса IntArray 
        My2Array.insertBefore(25, -2);


    }
    catch (BadIndex& bi)
    {
        bi.what();
        cout << "Exception handled!" << endl;
    }
    
    
}

