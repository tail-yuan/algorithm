
#include<iostream>
#include<vector>
using namespace std;
int nextp[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int curx, int cury, vector<vector<int>>& book)
    {
        book[curx][cury] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newx = curx + nextp[i][0];
            int newy = cury + nextp[i][1];
            if (newx >= row || newx < 0 || newy >= col || newy < 0)
            {
                continue;
            }
            if (grid[newx][newy] == '1' && book[newx][newy] == 0)
                dfs(grid, row, col, newx, newy, book);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> book(row, vector<int>(col, 0));
        int num = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1' && book[i][j] == 0)
                {
                    num++;
                    dfs(grid, row, col, i, j, book);
                }
            }
        }
        return num;
    }
};