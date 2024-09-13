#include "application.h"
#include <iostream>
#include "array.h"
#include "number.h"


using namespace std;

TApplication::TApplication() {

}


TApplication::exec() {
    int ch;
    TArray array;
    array.len = 10;

    while (true)
    {
        ch = menu();
        switch (ch)
        {
        case 0: // выход
        {
            //delete []array.arr;
            return 0;
        }
        break;
        case 1: // ввести массив
        {
            cout << "Вводите элементы массива построчно:" << endl;
            number item;
            for (int i = 0; i < array.len; i++)
            {
                cout << i+1 << ") ";
                cin >> item;
                array.arr[i] = item;
            }

        }
        break;
        case 2: // изменить длину
        {
            cout << "Введите длину массива: ";
            int old_len = array.len;
            cin >> array.len;
            cout << "Длина массива изменена: " << old_len << " -> " << array.len << endl;
            for (int i = old_len; i < array.len; i++)
            {
                array.arr[i] = 0;
            }
        }
        break;
        case 3: // Рассчитать среднее значение и СКО
        {
            array.aver();
            cout << "Среднее значение = " << array.average << endl;
            cout << "СКО = " << array.sko << endl;
        }
        break;
        case 4: // Сортировать по возрастанию
        {
            array.setSortMode(ESortModeUp);
            array.sortArr();
            cout << "Список успешно отсортирован по возрастанию" << endl;
        }
            break;
        case 5: // Сортировать по убыванию
        {
            array.setSortMode(ESortModeDown);
            array.sortArr();
            cout << "Список успешно отсортирован по убыванию" << endl;

        }
            break;
        case 6: // Изменить значение элемента по индексу
        {
            int index;
            number item;
            cout << "Введите индекс элемента (начиная с 0): ";
            cin >> index;
            if (index > array.len-1)
                cout << "Индекс не должен превышать размеры массива" << endl;
            else
            {
                cout << "Введите значение изменяемого элемента:" << endl;
                cin >> item;
                array.changeItem(index, item);
                cout << "Элемент с индексом " << index << " был успешно заменен" << endl;
            }


        }
            break;
        case 7: // Вывести массив
        {
            cout << array << endl;
        }
        break;
        default:
            cout << "Некорректный ввод" << endl;
        }
    }
    return 0;
}

int TApplication::menu()
{
    int ch;
    cout << "1 - Ввести массив" << endl;
    cout << "2 - Изменить длину" << endl;
    cout << "3 - Рассчитать среднее значение и СКО" << endl;
    cout << "4 - Сортировать по возрастанию" << endl;
    cout << "5 - Сортировать по убыванию" << endl;
    cout << "6 - Изменить значение элемента по индексу" << endl;
    cout << "7 - Вывести массив" << endl;
    cout << "0 - Выход" << endl;
    cout << ">> ";
    cin >> ch;
    return ch;
}


