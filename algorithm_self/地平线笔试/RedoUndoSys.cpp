#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
//想法如下:只想到了两个堆栈之间的互相操作实现撤销和反撤销操作,但是没能结合已有代码实现功能
//只是简单的想让stack存放数据,而不是存放Command指令.
class Data
{
	int m_val = 0;
public:
	virtual void Set(int val)
	{
		m_val = val;
	}
	virtual int Get()
	{
		return m_val;
	}
};
class Command
{
public:
	virtual void Exectute() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};
class EditCommand :public Command
{
	Data* ptr;
	int oldVal;
	int newVal;
public:
	EditCommand(Data* pData, int newNVal)
		:ptr(pData)
		,newVal(newNVal)
		,oldVal(ptr->Get())
	{}
	virtual void Exectute()
	{
		oldVal = ptr->Get();
		ptr->Set(newVal);
	}
	virtual void Undo()
	{
		ptr->Set(oldVal);
	}
	virtual void Redo()
	{
		ptr->Set(newVal);
	}
};
//我们需要在 RedoUndoSystem 类中维护两个堆栈：
//一个用于保存已执行的命令（以便于进行撤销），另一个用于保存已撤销的命令（以便于进行反撤销）。
class RedoUndoSystem
{
	stack<Command*>help_st; 
	stack<Command*>main_st;
public:
	void Push(Command* pc)
	{
		pc->Exectute();
		help_st.push(pc);
		while (!main_st.empty())
		{
			main_st.pop();
		}
	}
	void Redo()
	{
		if (!main_st.empty())
		{
			Command* pc = main_st.top();
			main_st.pop();
			pc->Redo();
			help_st.push(pc);
		}
	}
	void Undo()
	{
		if (!help_st.empty())
		{
			Command* pc = help_st.top();
			help_st.pop();
			pc->Undo();
			main_st.push(pc);
		}
	}
};