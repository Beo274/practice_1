#include <application.h>
#include <iostream>
#include <clocale>
#include <Windows.h>



int main()
{
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    TApplication a;

    return a.exec();
}
