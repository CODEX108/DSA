#include <iostream>
using namespace std;
/*
1.for outer loop count the number of rows
2.for the inner loop focus on the columns and connect them somehow to the rows
3.then print * in the inner loop
4. (Optional) Observe symmetry in case of some patterns
*/

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " " << j << " ";
        }
        cout << endl;
    }
}

void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch = ch + 1;
        }
        cout << endl;
    }
}

void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}

void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        // space
        for (int h = 0; h < n - i - 1; h++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 1 + 2 * i; j++)
        {
            cout << "*";
        }
        // space
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern7(int n)
{

    for (int i = 0; i < n; i++)
    {
        // space
        for (int h = 0; h < i; h++)
        {
            cout << " ";
        }

        for (int j = 0; j < 2 * n - (1 + 2 * i); j++)
        {
            cout << "*";
        }
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern9(int n)
{
    for (int i = 1; i <= n; i++)
    {
    }
}

void pattern10(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            start = 0;
        else
            start = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    // pattern1(n);
    // pattern2(n);
    // pattern3(n);
    // pattern4(n);
    // pattern5(n);
    // pattern6(n);
    // pattern7(n);
    // pattern8(n);
    // pattern9(n);
    // pattern10(n);
    return 0;
}