
//����: �����˶���ʶ��,�����Ҳ���ʶ����
//��������know(i,j),��ʾiλ�õ����Ƿ���ʶj
//�������ǵı��,���û�з���-1

//�ṩknow(x,y)����,����x�Ƿ���ʶy,���x��ʶy,��ôy���Ǻ�ѡ����,���x����ʶy,��ôy�϶��������Ǻ�ѡ
//�õ����Ǻ�ѡ֮��,��֤cand�Ƿ���ʶ������
//�϶�����ʶ�������,
// ������Ҫ��֤��������Ƿ񶼲���ʶ
//�Ƿ������˶���ʶcand
class Solution
{
	//����know����,���������Լ�ʵ��
	bool know(int x, int y)
	{
		return true;
	}
public:
	int findCelebrity(int n)
	{
		int cand = 0;
		for (int i = 0; i < n; i++)
		{
			if (know(cand, i))
				cand = i;
		}
		//candλ�þ����Ҳ�����ȷ�������Ǻ�ѡ��
		//�����������Ƿ񶼲���ʶ
		for (int i = 0; i < cand; i++)
		{
			if (know(cand,i))
				return -1;
		}
		//�������Ƿ���ʶcand
		for (int i = 0; i < n; i++)
		{
			if (!know(i, cand))
				return -1;
		}
		return cand;
	}
};