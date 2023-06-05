#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long int>> pascalTri(int n)
{
    vector<vector<long long int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<long long int> ans;
        for (int j = 0; j < i + 1; j++)
        {
            ans.push_back(1);
        }
        v.push_back(ans);
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    return v;
}

void printMatrix(const vector<vector<long long int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;

    vector<vector<long long int>> matrix = pascalTri(n);

    cout << "Pascal's Triangle-like Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
