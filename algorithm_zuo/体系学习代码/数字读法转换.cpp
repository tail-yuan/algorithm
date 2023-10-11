//��һ�����������ı�ʾ���������ַ�ΧΪ [0, 99999]��
//Ϊ�˷��������ʹ����ĸ�滻��Ӧ�����ģ���W ǧQ ��B ʮS ��L��ʹ������ȡ����
//������ע������ 11 Ӧ�ñ�ʾΪ һʮһ(1S1)��������ʮһ(S1)
//����������
//���� 0���������� 99999����������
//���������
//����ĸ�滻��Ӧ�����ģ���W ǧQ ��B ʮS ��L
//ʾ��1 :
//����
//12001
//���
//1W2QL1

#include<iostream>
#include<vector>
using namespace std;
class ChineseEspression
{
public:
	string num1to9(int num)
	{
		if (num < 1 || num>9)
			return "";
		 vector<string> arr = {"һ","��","��","��","��","��","��","��","��"};
		 return arr[num - 1];
	}
	string num1to99(int num,bool isHasBai)// 0 12->ʮ�� 1 12->һ�� һʮ��
	{
		if (num < 1 || num>99)
			return "";
		if (num < 10)
			return num1to9(num);
		int shi = num / 10;
		if (shi == 1 && !isHasBai)
			return "ʮ" + num1to9(num % 10);
		else
			return num1to9(shi) + "ʮ" + num1to9(num%10);
	}
	string num1to999(int num)
	{
		if(num < 1 || num>999)
			return "";
		if (num < 100) return num1to99(num,false);
		
		string res = num1to9(num / 100) + "��";
		int rest = num % 100;
		if (rest == 0)
			return res;
		else if (rest >= 10)
			res += num1to99(rest, true);
		else
			res + "��" + num1to9(rest);
		return res;
	}
	string num1to9999(int num)
	{
		if (num < 1 || num>9999)
			return "";
		if (num < 1000) return num1to999(num);
		string res = num1to9(num / 1000) + "ǧ";
		int rest = num % 1000;
		if (rest == 0)
			return res;
		else if (rest > 100)
			res += num1to999(rest);
		else
			res += "��" + num1to99(rest,false);
		return res;
	}
	//�������ĸ��ĸ�һ��,����Ҫƴ�ĸ���ͬ��˵��,֮����ĸ��ĸ����ϼ�
	string num1to99999999(int num)
	{
		if (num < 1 || num>99999999)
			return "";
		int wan = num / 10000;
		int rest = num % 10000;
		if (wan == 0)
			return num1to9999(num);
		else
		{
			string res = num1to9(wan) + "��";
			if (rest < 1000)
				return res + "��" + num1to999(rest);
			else
				return res + num1to9999(rest);
		}
	}
	string getNumChiExp(int num)
	{
		if (num == 0) return "��";
		string res = num < 0 ? "��" : "";
		int yi = abs(num /100000000);
		int rest = abs(num %100000000);
		if (yi == 0)
			return res+num1to99999999(num);
		else
		{
			res += num1to9999(yi) + "��";
			if (rest == 0)
				return res;
			else
			{
				if (rest < 10000000)
					return res + "��" + num1to99999999(rest);
				else
					return res+ num1to99999999(rest);
			}
		}
	}
};