//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void changedirection(string &dir)
    {
        if (dir == "right")
            dir = "down";
        else if (dir == "down")
            dir = "left";
        else if (dir == "left")
            dir = "up";
        else
            dir = "right";
    }

    vector<int> FindExitPoint(int n, int m, vector<vector<int>> &matrix)
    {
        string dir = "right";
        int i = 0;
        int j = 0;
        while (i < n && j < m && 0 <= i && 0 <= j)
        {
            if (matrix[i][j] == 1)
            {
                changedirection(dir);
                matrix[i][j] = 0;
            }
            if (dir == "right")
            {
                j++;
            }
            else if (dir == "down")
            {
                i++;
            }
            else if (dir == "left")
            {
                j--;
            }
            else
            {
                i--;
            }
        }
        if (i < 0)
            i = 0;
        if (i > n - 1)
            i = n - 1;
        if (j < 0)
            j = 0;
        if (j > m - 1)
            j = m - 1;
        return {i, j};
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends