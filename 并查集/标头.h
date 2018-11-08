#pragma once
#include<iostream>
using namespace std;

const int DefaultSize = 10;
class UFSets
{
public:
	UFSets(int sz = DefaultSize);
	~UFSets() { delete[]parent; }
	UFSets &operator=(UFSets&R);//���ϸ�ֵ
	void Union(int Root1, int Root2);
	int Find(int x);//��Ѱx�ĸ�
	void WeightedUnion(int Root1, int Root2);//�Ľ����̣���Ȩ�ϲ��㷨
private:
	int *parent;
	int size;
};

UFSets::UFSets(int sz)
{
	//���캯����sz�Ǽ���Ԫ�ظ�����
	size = sz;
	parent = new int[size];//������ָ������
	for (int i = 0; i < size; i++)parent[i] = -1;//ÿ���Գɵ�Ԫ�ؼ���
}

int UFSets::Find(int x)
{
	//�������������ذ���Ԫ��x�����ĸ�
	while (parent[x] >= 0)x = parent[x];//ѭ��Ѱ��x�ĸ�
	return x;
}

void UFSets::Union(int Root1, int Root2)
{
	//�������������ཻ���ϵĲ���Ҫ��Root1��Root2�ǲ�ͬ�ģ��ұ�ʾ���Ӽ��ϵ����֡�
	parent[Root1] += parent[Root2];
	parent[Root2] = Root1;
}