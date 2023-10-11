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
		if (prei>prej)//如果没节点
			return;
		if (prei == prej)//先序只剩一个
		{
			post[posti] = pre[prei];
			return;
		}
		post[postj] = pre[prei];//先序第一个肯定是后序最后一个
		//找到头结点在中序遍历中的位置,好划分出区间
		int findi = 0;
		for (; findi <= inj; findi++)
		{
			if (in[findi] == pre[prei])
				break;
		}
		//用前序中左子树区间,中序中左子树区间去构建后序左子树
		setPostArr(pre,in,post,prei+1,prei+ findi-ini,ini,findi-1,posti,posti+findi-ini-1);
		//构建右子树
		setPostArr(pre,in,post,prei+findi-ini+1,prej,findi+1,inj,posti+findi-ini,postj);
	}

};