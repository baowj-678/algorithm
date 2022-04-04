/**
* @Title: SPFA�㷨
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/8/21
* @IDE: Microsoft Visual Studio Community 2019 �汾 16.7.2
*/

#include <iostream>
#include <queue>
#include<vector>
#define INF	9999999
using namespace::std;

/**
* �ߵĽṹ��
*/
struct Edge {
	int from;
	int to;
	int value;
};

typedef Edge* pEdge;
/**
* @n n���ڵ�
* @Graph �ڽӾ���
* @s ���
*/
int* SPFA(int n, vector<vector<pEdge>> Graph, int s);
int main()
{
	// ����
	int n;
	cout << "������ڵ���:" << endl;
	cin >> n;
	int m;
	cout << "���������:" << endl;
	cin >> m;
	int s;
	cout << "������Դ���ţ���0��ʼ��:" << endl;
	cin >> s;
	int u, v, value;
	vector<vector<pEdge>> Graph(n);
	for (int i(0); i < m; i++)
	{
		pEdge tmp = new Edge;
		cin >> u >> v >> value;
		if (value == -1)
			value = INF;
		tmp->value = value;
		tmp->from = u;
		tmp->to = v;
		Graph[u].push_back(tmp);
	}
	// ����
	int* ans = SPFA(n, Graph, s);
	// ���
	for (int i(0); i < n; i++)
		cout << ans[i] << " ";
	return 0;
}

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