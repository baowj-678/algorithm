/**
* @Title: SPFA�㷨
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/8/21
* @IDE: Microsoft Visual Studio Community 2019 �汾 16.7.2
*/

#include "SDC.h"
#include <iostream>
#include <queue>
#include<vector>
#define INF	9999999
using namespace::std;

typedef Edge* pEdge;
/**
* @n n���ڵ�
* @Graph �ڽӾ���
* @s ���
*/
int* SPFA(int n, vector<vector<pEdge>> Graph, int s)
{
	// ��ʼ��
	queue<int> Q;
	/**
	* ��¼ÿ���ڵ㵽s�����
	*/
	int* d = new int[n];
	/**
	* ��¼ÿ���ڵ��������
	*/
	int* count = new int[n];
	for (int i(0); i < n; i++)
	{
		count[i] = 0;
		if (i != s)
			d[i] = INF;
	}
	d[s] = 0;
	Q.push(s);
	// ����
	while (Q.empty() == false)
	{
		int u = Q.front();
		Q.pop();
		vector<pEdge> Vs = Graph[u];
		vector<pEdge>::iterator itor = Vs.begin();
		while (itor != Vs.end())
		{
			if (d[u] == INF)
				break;
			else
			{
				int v = (*itor)->to;
				int value = (*itor)->value;
				if (value == INF)
					continue;
				else
					value += d[u];
				if (d[v] > value)
				{
					d[v] = value;
					count[v]++;
					if (count[v] > n)
						return NULL;
					Q.push(v);
				}
				itor++;
			}
		}
	}
	return d;
}