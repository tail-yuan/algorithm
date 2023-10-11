#include<iostream>
#include<vector>
using namespace std;
class CardsInLine
{
public:
	int win1(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		return max(f(arr, 0, arr.size() - 1),s(arr, 0, arr.size() - 1));
	}
	int f(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return arr[i];
		//��������ߵĻ����ұߵ�
		return max(arr[i]+s(arr, i + 1, j) ,
					arr[j]+s(arr,i,j-1) );
	}
	int s(vector<int>& arr, int i, int j)
	{
		if (i == j)
			return 0;
		return min(f(arr, i + 1, j), f(arr, i, j - 1));//�����õ�ʣ�µ��Ǹ����ұ߽���С��
	}
	//��Χ����,i<j,���Ա�����°����϶�û��
	//1.  i  [0,N-1] j  [0,N-1]��ά�� f s 
	//2. ����λ����f[0][N-1] s[0][N-1]
	//3. f��i==jλ��=arr[i] s��i==jλ��,0
	//4. ������ϵ,f[i][j]������s[i+1][j] s[i][j-1]������s���ж�Ӧ�����ߺ��±ߵ�ֵ,һ��б��,��֮Ҳ��,
	// �� i=j����б��֪��,���Կ��Խ��������Է����ǰһ��б��
	int win2(vector<int>& arr)
	{
		if (arr.size() == 0)
			return 0;
		int N = arr.size();
		vector<vector<int>>f(N, vector<int>(N));
		vector<vector<int>>s(N, vector<int>(N));
		for (int i = 0; i < N; i++)
			f[i][i] = arr[i];
		int row = 0;
		int col = 1;
		//�Խ��ߵķ�ʽ
		while (col < N)
		{
			int i = row;
			int j = col;
			while (i < N && j < N)
			{
				f[i][j] = max(arr[i]+s[i+1][j],arr[j]+s[i][j-1]);
				s[i][j] = min(f[i+1][j],f[i][j-1]);
				i++;
				j++;
			}
			col++;
		}
		return max(f[0][N-1],s[0][N-1]);
	}
};
