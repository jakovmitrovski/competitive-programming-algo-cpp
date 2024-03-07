#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int compare_by_joint_value(string a, string b)
{
    return (b + a) < (a + b);
}

int main()
{

    int N;
    cin >> N;

    vector<string> numbers;

    for (int i = 0; i < N; i++)
    {
        string current;
        cin >> current;

        numbers.push_back(current);
    }

    sort(numbers.begin(), numbers.end(), compare_by_joint_value);

    for (int i = 0; i < N; i++)
    {
        cout << numbers[i];
    }

    cout << endl;
    return 0;
}