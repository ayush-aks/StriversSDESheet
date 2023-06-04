#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    vector<int> row (n,0);
    vector<int> cols (m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
            if(matrix[i][j]==0)
            {
                    row[i]=1;
                    cols[j]=1;
            }
        }
    }
// converting all -1s to 0s
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i]==1 || cols[j]==1)
            {
                    matrix[i][j]=0;
            }
        }
    }
}

void printMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> matrix = {{7, 19, 3},
                                  {4, 21, 0}};

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    setZeros(matrix);

    cout << "Matrix after setting zeros:" << endl;
    printMatrix(matrix);

    return 0;
}
