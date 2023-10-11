#include<iostream>
#include<unordered_map>
using namespace std;


template<class Key>
class RandomPool
{
public:
	RandomPool()
	{ 
		size = 0; 
	}
public:
	void Insert(Key key)
	{
		if (keyIndexMap.find(key) == keyIndexMap.end())
		{
			keyIndexMap.insert(make_pair(key,size));
			indexKeyMap.insert(make_pair(size++, key));
		}
	}
	void Delete(Key key)
	{
		if (keyIndexMap.find(key) == keyIndexMap.end())
			return;
		int delIndex = keyIndexMap[key];
		int lastIndex = --size;
		Key lastKey = indexKeyMap[lastIndex];

		keyIndexMap[lastKey] = delIndex;
		indexKeyMap[delIndex] = lastKey;

		keyIndexMap.erase(key);
		indexKeyMap.erase(lastIndex);
	}
	Key GetRandom()
	{
		if (size == 0)
			return Key();
		int randomIndex = (int)(rand() % size);//[0,size-1]
		return indexKeyMap[randomIndex];
	}
private:
	unordered_map<Key, int> keyIndexMap;
	unordered_map<int, Key> indexKeyMap;
	int size;
};
int main()
{
	RandomPool<string> pool;
	pool.Insert("yuanwei1");
	pool.Insert("yuanwei2");
	pool.Insert("yuanwei3");
	cout<<pool.GetRandom()<<endl;
	cout<<pool.GetRandom()<<endl;
	cout<<pool.GetRandom()<<endl;
}