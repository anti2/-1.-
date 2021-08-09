// Задание 3. Валидация IP-адреса.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Задание 3. Валидация IP-адреса.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

bool find_symbols(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
        {
            return false;
        }
    }
    return true;
}

std::string first_number(std::string ip)
{
    std::string fn;
    bool found = false;
    for (int i = 0; i < ip.length() && !found; i++)
    {
        if (ip[i] != '.')
        {
            fn += ip[i];
        }
        else
        {
            found = true;
        }
    }
    return fn;
}
std::string second_number(std::string ip)
{
    std::string fn;
    bool found = false;
    for (int i = first_number(ip).length() + 1; i < ip.length() && !found; i++)
    {
        if (ip[i] != '.')
        {
            fn += ip[i];
        }
        else
        {
            found = true;
        }
    }
    return fn;
}

std::string third_number(std::string ip)
{
    std::string fn;
    bool found = false;
    for (int i = first_number(ip).length() + second_number(ip).length() + 2; i < ip.length() && !found; i++)
    {
        if (ip[i] != '.')
        {
            fn += ip[i];
        }
        else
        {
            found = true;
        }
    }
    return fn;
}

std::string fourth_number(std::string ip)
{
    std::string fn;
    bool found = false;
    for (int i = first_number(ip).length() + second_number(ip).length() + third_number(ip).length() + 3; i < ip.length() && !found; i++)
    {
        if (ip[i] != '.')
        {
            fn += ip[i];
        }
        else
        {
            found = true;
        }
    }
    return fn;
}


int main() {
    std::string ip;
    int firstnum, secondnum, thirdnum, fourthnum;
    std::cout << "Input IP-address\n";
    std::cin >> ip;
    firstnum = atoi(first_number(ip).c_str());
    std::cout << firstnum << "\n";
    secondnum = atoi(second_number(ip).c_str());
    std::cout << secondnum << "\n";
    thirdnum = atoi(third_number(ip).c_str());
    std::cout << thirdnum << "\n";
    fourthnum = atoi(fourth_number(ip).c_str());
    std::cout << fourthnum << "\n";


    if (!find_symbols(ip))
    {
        std::cout << "No" << std::endl; return 0;
    }




    else if (first_number(ip).length() < 1
        || second_number(ip).length() < 1
        || third_number(ip).length() < 1
        || fourth_number(ip).length() < 1)
    {
        std::cout << "No" << std::endl; return 0;
    }
    else if ((firstnum < 0 || firstnum > 255)
        || (secondnum < 0 || secondnum > 255)
        || (thirdnum < 0 || thirdnum > 255)
        || (fourthnum < 0 || fourthnum > 255))
    {
        std::cout << "No" << std::endl; return 0;
    }
    else if ((first_number(ip)[0] == '0' && first_number(ip).length() > 1)
        || (second_number(ip)[0] == '0' && second_number(ip).length() > 1)
        || (third_number(ip)[0] == '0' && third_number(ip).length() > 1)
        || (fourth_number(ip)[0] == '0' && fourth_number(ip).length() > 1))
    {
        std::cout << "No" << std::endl; return 0;
    }
    else if (first_number(ip).length()
        + second_number(ip).length()
        + third_number(ip).length()
        + fourth_number(ip).length() + 3 != ip.length())
    {
        std::cout << "No" << std::endl; return 0;
    }
    else
    {
        std::cout << "Yes" << std::endl; return 0;
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
