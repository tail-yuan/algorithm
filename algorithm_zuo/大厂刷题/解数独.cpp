//https://leetcode.cn/problems/sudoku-solver/
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    bool row[9][10], col[9][10], grid[3][3][10];
public:
    //子问题: 遍历二维数组,遇到空格就在1~9数中互斥的选择,选中一个,相信dfs()函数能将下个空格,完美的填上.只不过空格需要找出来,所以两层循环罢了!然后出口是将所有空格枚举完
    //出口: 所有空格都遍历完了
    //剪枝: 三个哈希表,记录行,列,矩阵决定这个数能否选中; 
    //回溯:恢复现场: 可能这个位置填这个数填到最后无法填成功,只需要告知上一次选择这个数是错误的,所以dfs返回值设置为bool类型
    void solveSudoku(vector<vector<char>>& board)
    {
        //预处理三个表
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        }
        dfs(board);
    }
    //选择一步之后,需要dfs将这部选择之后造成的影响返回,这步是选对了还是选错了
    bool dfs(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    //互斥选择一个0~9的数字,之后走下一个位置
                    for (int num = 1; num <= 9; num++)
                    {
                        if (!row[i][num] && !col[j][num] && !grid[i / 3][j / 3][num])
                        {
                            board[i][j] = num + '0';
                            row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                            if (dfs(board)==true)//这步选num选对了,就返回True
                                return true;
                            else//这步选错了,恢复现场,选下一个
                            {
                                board[i][j] = '.';
                                row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = false;
                            }
                        }
                    } //9个数枚举完了,都没返回true,说明这个不可填
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution
{
    bool row[9][10], col[9][10], grid[3][3][10];
public:
    //专注于i,j位置,从左往右,到达最右然后回车位置
    void solveSudoku(vector<vector<char>>& board)
    {
        //预处理三个表
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                }
            }
        }
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>& board, int i, int j)
    {
        if (i == 9)
            return true;
        int x = j != 8 ? i : i + 1;
        int y = j != 8 ? j + 1 : 0;
        if (board[i][j] != '.')
            return dfs(board, x, y);//直接去下一个位置
        else
        {
            //互斥的尝试1~9
            for (int num = 1; num <= 9; num++)
            {
                if (!row[i][num] && !col[j][num] && !grid[i / 3][j / 3][num])
                {
                    board[i][j] = '0' + num;
                    row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                    if (dfs(board, x, y) == true)
                        return true;
                    else
                    {
                        board[i][j] = '.';
                        row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = false;
                    }
                }
            }
            return false;
        }
        return true;
    }
};