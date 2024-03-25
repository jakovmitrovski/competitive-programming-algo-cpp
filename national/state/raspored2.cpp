#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int niza[20];

    vector<int> v, v1;

    int razlika = -1;

    for (int i = 0; i < n; i++)
        cin >> niza[i];

    sort(niza, niza + n);

    int mat[20][20];

    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            v.push_back(niza[i]);

        else
            v1.push_back(niza[i]);

    if (n == 3)
    {
        razlika = max(abs(v[0] - v[1]), abs(v[0] - v1[0]));
        cout << razlika;

        return 0;
    }

    for (int i = 1; i < v.size(); i++)
        razlika = max(razlika, abs(v[i - 1] - v[i]));

    for (int i = 1; i < v1.size(); i++)
        razlika = max(razlika, abs(v1[i - 1] - v1[i]));

    razlika = max(razlika, abs(v[0] - v1[0]));
    razlika = max(razlika, abs(v[v.size() - 1] - v1[v1.size() - 1]));

    cout << razlika;

    return 0;
}