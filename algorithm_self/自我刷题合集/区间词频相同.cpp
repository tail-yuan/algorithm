#include"head.hpp"
// ���Ի�ΪOD
// ������λ����
// ����һ����'W'��'A'��'S'��'D'�����ַ���ɵ��ַ���������һ����4�ı���
// ����԰�����������һ���Ӵ������'W'��'A'��'S'��'D'��ɵ�����״̬
// Ŀ������4���ַ���Ƶһ��
// ������Ҫ�޸ĵ�����Ӵ�����
// �ҵ��˳�������leetcodeԭ��
// �������� : https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

// �����ַ�����,��һ���������������ĸ�滻Ϊȱʧ����ĸʹ�������ַ����и�����ĸ��Ƶ��ͬ
// ���������ڵ���С���������Ӵ�����
// 
// ���һ������,��[l,r)����������֧��,�ܷ�����������ĸ��Ƶ��ͬ
	//�������,����true,�����Է���false
// ����ϴ����䷵��false,��ô��С������϶�Ҳfalse
// ���������α�����ĸ,ʹ�ô���,�õ�ÿһ����ĸ�ܹ�����������
// ��ÿһ����ĸ�õ��������С�����Сֵ
class Solution
{
public:
	int balancedString(string s) 
	{
		int n = s.size();
		int* arr = new int[n];
		//cnts��¼��������֮�����ĸ��Ƶ��
		int* cnts = new int[4] {0};
		//���ַ�ת��Ϊ���ִ洢
		for (int i = 0; i < n; i++)
		{
			char c = s[i];
			arr[i] = c == 'W' ? 1 : (c == 'E' ? 2 : (c == 'R' ? 3 : 0));
			cnts[arr[i]]++;
		}
		int ans = n;
		for (int l = 0, r = 0; l < n; l++)
		{
			//!ok(cnts,l,r),��ǰ����[l,r)��������������ַ�һ����
			//�����ұ߽绹������,������
			while (!ok(cnts, l, r) && r < n)
				cnts[arr[r++]]--;
			// 1) ok ��������û����,������ok��
			// 2) !ok,���һ�û�пռ�������չ��
			if (ok(cnts, l, r))
			{
				ans = min(ans,r-l);
			}
			else//[l,r)��û��ʵ��,���ٴӸ�С����[l+1,r)�͸�û������
			{
				break;
			}
			cnts[arr[l]]++;
		}
		return ans;
	}
	// ���ڣ�str[l.....r)����������ɱ仯�����Ǵ�����Ĳ��ܱ仯
	// l = 3, r = 10
	// [3,10) <=> [3....9]
	// ���ڳ��� = r - l= 10 - 3 = 7
	// cnts������֮��ÿһ���ַ��Ĵ�Ƶͳ�ƣ������㴰���ڵ�ͳ�Ƶģ�
	// w : cnts[0]
	// a : cnts[1]
	// s : cnts[2]
	// d : cnts[3]
	// cntsֻ��4����
	// ÿ����ĸƵ��׷�������������Ƶ�����sum,�����м�ȥsum
	// ʣ�µĿռ��ܷ�ʵ��4��ĸ�ľ���,��ʵ�־�ok
	bool ok(int *& cnts,int l,int r)
	{
		int maxCnt = max(max(cnts[0], cnts[1]), max(cnts[2], cnts[3]));
		int changes = maxCnt * 4 - cnts[0] - cnts[1] - cnts[2] - cnts[3];
		int rest = r - l - changes;
		return rest >= 0 && rest % 4 == 0;
	}
};
