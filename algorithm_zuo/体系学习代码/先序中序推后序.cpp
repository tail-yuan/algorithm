#include<iostream>
#include<vector>
using namespace std;

class getPostArray
{
public:
	void setPostArr(vector<int>& pre, vector<int>& in,vector<int>&post
					,int prei,int prej
					,int ini,int inj
					,int posti,int postj)
	{
		if (prei>prej)//���û�ڵ�
			return;
		if (prei == prej)//����ֻʣһ��
		{
			post[posti] = pre[prei];
			return;
		}
		post[postj] = pre[prei];//�����һ���϶��Ǻ������һ��
		//�ҵ�ͷ�������������е�λ��,�û��ֳ�����
		int findi = 0;
		for (; findi <= inj; findi++)
		{
			if (in[findi] == pre[prei])
				break;
		}
		//��ǰ��������������,����������������ȥ��������������
		setPostArr(pre,in,post,prei+1,prei+ findi-ini,ini,findi-1,posti,posti+findi-ini-1);
		//����������
		setPostArr(pre,in,post,prei+findi-ini+1,prej,findi+1,inj,posti+findi-ini,postj);
	}

};