#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

using namespace std;


int CountRobots(int n, ofstream& f)
{
    int robots[5] = { 0,0,0,0,9 };
    int sum;
    int sumBroke = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += robots[j];
        }
        if (sum == 0)
        {
            cout << "роботы погибли";
            break;
        }
        int work = sum / 3;

        int broke = robots[0];
        sumBroke += broke;


        robots[0] = robots[1];//уменьшаем всем роботам время жизни на 1 день
        robots[1] = robots[2];
        robots[2] = robots[3];
        robots[3] = robots[4];
        robots[4] = work;//новые роботы, каждый строится бригадой из трех


        cout << "В день №: " << i + 1 << " работало: " << work * 3 << " роботов; простаивало: " << sum % 3 << " роботов; сломанных всего: " << sumBroke << " , за день: " << broke << " роботов." << endl;
        f << "В день № " << i + 1 << " работало: " << work * 3 << " роботов; простаивало: " << sum % 3 << " роботов; сломанных: " << sumBroke << " , за день: " << broke << " роботов." << endl;
    }


    cout << "В день № " << n << " функционирует " << sum << " роботов.";
    f << "В день № " << n << " функционирует " << sum << " роботов.";
    return sum;
}


int main()
{
    setlocale(LC_ALL, "");


    string name = "out.txt";//имя файла
    /* cout << "Введите имя файла:";
     cin >> name;*/

    ofstream f(name, ios::trunc);//открываем файл для записи,ios::trunc - данные в файле удалятся
    if (f.is_open()) //если файл успешно открыт
    {
        cout << "Введите количество дней: ";
        int n;
        cin >> n;
        CountRobots(n, f);

    }
    else
    {
        cout << "Ошибка при октрытии файла." << endl;
    }
}
