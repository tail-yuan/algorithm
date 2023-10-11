//https://leetcode.cn/problems/sudoku-solver/
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    bool row[9][10], col[9][10], grid[3][3][10];
public:
    //������: ������ά����,�����ո����1~9���л����ѡ��,ѡ��һ��,����dfs()�����ܽ��¸��ո�,����������.ֻ�����ո���Ҫ�ҳ���,��������ѭ������!Ȼ������ǽ����пո�ö����
    //����: ���пո񶼱�������
    //��֦: ������ϣ��,��¼��,��,�������������ܷ�ѡ��; 
    //����:�ָ��ֳ�: �������λ��������������޷���ɹ�,ֻ��Ҫ��֪��һ��ѡ��������Ǵ����,����dfs����ֵ����Ϊbool����
    void solveSudoku(vector<vector<char>>& board)
    {
        //Ԥ����������
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
    //ѡ��һ��֮��,��Ҫdfs���ⲿѡ��֮����ɵ�Ӱ�췵��,�ⲽ��ѡ���˻���ѡ����
    bool dfs(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    //����ѡ��һ��0~9������,֮������һ��λ��
                    for (int num = 1; num <= 9; num++)
                    {
                        if (!row[i][num] && !col[j][num] && !grid[i / 3][j / 3][num])
                        {
                            board[i][j] = num + '0';
                            row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = true;
                            if (dfs(board)==true)//�ⲽѡnumѡ����,�ͷ���True
                                return true;
                            else//�ⲽѡ����,�ָ��ֳ�,ѡ��һ��
                            {
                                board[i][j] = '.';
                                row[i][num] = col[j][num] = grid[i / 3][j / 3][num] = false;
                            }
                        }
                    } //9����ö������,��û����true,˵�����������
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
    //רע��i,jλ��,��������,��������Ȼ��س�λ��
    void solveSudoku(vector<vector<char>>& board)
    {
        //Ԥ����������
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
            return dfs(board, x, y);//ֱ��ȥ��һ��λ��
        else
        {
            //����ĳ���1~9
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