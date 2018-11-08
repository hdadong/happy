#pragma once
#include<iostream>
using namespace std;

const int DefaultSize = 10;
class UFSets
{
public:
	UFSets(int sz = DefaultSize);
	~UFSets() { delete[]parent; }
	UFSets &operator=(UFSets&R);//集合赋值
	void Union(int Root1, int Root2);
	int Find(int x);//搜寻x的跟
	void WeightedUnion(int Root1, int Root2);//改进例程：加权合并算法
private:
	int *parent;
	int size;
};

UFSets::UFSets(int sz)
{
	//构造函数：sz是集合元素个数。
	size = sz;
	parent = new int[size];//创建父指针数组
	for (int i = 0; i < size; i++)parent[i] = -1;//每个自成单元素集合
}

int UFSets::Find(int x)
{
	//函数搜索并返回包含元素x的树的根
	while (parent[x] >= 0)x = parent[x];//循链寻找x的根
	return x;
}

void UFSets::Union(int Root1, int Root2)
{
	//函数求两个不相交集合的并，要求Root1与Root2是不同的，且表示了子集合的名字。
	parent[Root1] += parent[Root2];
	parent[Root2] = Root1;
}