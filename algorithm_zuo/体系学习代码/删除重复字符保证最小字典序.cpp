//����һ��ȫ��Сд��ĸ���ַ���str��ɾ�������ַ���ʹ��ÿ���ַ�ֻ����һ�����������ս���ַ������ֵ�����С
//��������
//str = "acbc"��ɾ����һ��'c'���õ�"abc"�������н���ַ������ֵ�����С�ġ�
//str = "dbcacbca"��ɾ����һ��'b'����һ��'c'���ڶ���'c'���ڶ���'a'���õ�"dabc"��
//�����н� ���ַ������ֵ�����С�ġ�

// ̰��:
// ÿ������һ���ַ�,�ͽ���Ƶ��һ,Ȼ�����������,ֱ��ĳһ���ַ���ƵΪ0,��֪������û������ַ���,break->
// �ͻ�����һ����Χ,�������Χ��[left,right]
// �����ֻ����һ���ַ�(��ʱ��ƵΪ0���ַ�)str[i],ʣ���ַ�ȫɾ��,��֤���������ÿ���ַ�����,
// �������Χ��ѡ����ֵ��С��
// Ȼ��ѡ������ַ�str[i],����ǰ���ȫɾ��,��[i,right]���ַ�����str[i]�ַ�ȫɾ���õ�����ַ���tmp
// �ݹ���remove(tmp)
#include<iostream>
#include<vector>
using namespace std;
class RemoveDuplicateLettersLessLexi
{
public:
	int remove(string& str)
	{
		if (str.size() < 2)
			return 0;
		vector<int>count(256, 0);
		for (int i = 0; i < str.size(); i++)
			count[i]++;
		int minIndex = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (--count[str[i]] == 0)
				break;
			else
				minIndex = str[minIndex] > str[i] ? i : minIndex;//�ҵ��ֵ�����С���±�
		}
		string next = str.substr(minIndex + 1);
		char target = str[minIndex];
		return str[minIndex] - '0' + remove(next.erase(target));
	}
	int removeDuplicateLettersLessLexi(string& str)
	{
		
	}
};