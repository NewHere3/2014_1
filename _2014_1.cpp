#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

void taskai(int balsai[3])
{
    int temp=0;
    for (int i = 0; i < 3; i++)
    {
        if (temp<balsai[i])
        {
            temp = balsai[i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (temp == balsai[i])
        {
            balsai[i] = 4;
        }
        else
        {
            balsai[i] = 0;
        }
    }

    if (balsai[0] + balsai[1] + balsai[2] == 12)
    {
        balsai[0] = 0;
        balsai[1] = 0;
        balsai[2] = 0;
        return;
    }

    if (balsai[0] + balsai[1] == 8 || balsai[1] + balsai[2] == 8 || balsai[0] + balsai[2] == 8)
    {
        for (int i = 0; i < 3; i++)
        {
            if (balsai[i] == 4) balsai[i] = 2;
        }
    }
}

int laimejo(int arr[3], int dir[3], ofstream& rez)
{
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
        }
    }

    if (arr[0] + arr[1] == temp*2 || arr[1] + arr[2] == temp * 2 || arr[0] + arr[2] == temp * 2)
    {
        arr[0] += dir[0];
        arr[1] += dir[1];
        arr[2] += dir[2];
    }
    rez << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';

    temp = 0;
    int x = 0;
    for (int i=0; i < 3; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
            x = i + 1;
        }
    }
    return x;
}

int main()
{
    int k, dir[3], balsai[10][3], sum_taskai[3] = { 0 }, temp[3] = { 0 };
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");

    duom >> k;

    for (int i = 0; i < k; i++)
    {
        duom >> balsai[i][0] >> balsai[i][1] >> balsai[i][2];
    }
    duom >> dir[0] >> dir[1] >> dir[2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < k; j++)
        {
            temp[i] += balsai[j][i];
        }
    }

    rez << temp[0] << ' ' << temp[1] << ' ' << temp[2] << '\n';

    for (int i = 0; i < k; i++)
    {
        taskai(balsai[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum_taskai[i] += balsai[j][i];
        }
    }
    rez << laimejo(sum_taskai, dir, rez);

    return 0;
}