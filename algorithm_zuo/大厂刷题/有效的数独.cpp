
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    bool row[9][10], col[9][10], grid[9][10];
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int bid = 3 * (i / 3) + (j / 3);
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (row[i][num] || col[j][num] || grid[bid][num])
                        return false;
                    else
                        row[i][num] = col[j][num] = grid[bid][num] = true;
                }
            }
        }
        return true;
    }
};
class Solution
{
    bool row[9][10], col[9][10], grid[3][3][10];
    //某一行,哪一个数字在不在
    //某一列,哪一个数字在不在
    //在3*3矩阵中,哪一个数字在不在
    //数字范围是1~9
    //第一次遇到数字,就标记为true,如果在下一次遍历到这个数时在非法位置,就返回false
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j]-'0';
                    if (row[i][num] || col[j][num] || grid[i / 3][j / 3][num])
                        return false;
                    else
                        row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        }
        return true;
    }
};