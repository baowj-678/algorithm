#include <iostream>
#include <queue>
using namespace::std;

double** get_space(int n, int m);
double Ford_Folkerson(double** graph, int n, int s, int t);
int main()
{
	cout << "�������������" << endl;
	int n;
	cin >> n;
	cout << "��������㣨��0��ʼ����" << endl;
	int s;
	cin >> s;
	cout << "�������յ㣺" << endl;
	int t;
	cin >> t;
	cout << "������ߵĸ�����" << endl;
	int m;
	cin >> m;
	cout << "������ߣ����磺0 1 3.1����" << endl;
	double** graph = get_space(n, n);
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
			*(*(graph + i) + j) = 0;
	int x, y;
	double value;
	for (int i(0); i < m; i++)
	{
		cin >> x >> y >> value;
		graph[x][y] = value;
	}
	cout << "�������" << Ford_Folkerson(graph, n, s, t) << endl;
}


/**
* ��ȡ��ά����ռ�
*/
double** get_space(int n, int m)
{
	double** ans = new double* [n];
	for (int i(0); i < n; i++)
	{
		*(ans + i) = new double[m];
	}
	return ans;
}

/**
* Ford-Folkerson �㷨
*/
double Ford_Folkerson(double** graph, int n, int s, int t)
{
	// ��ʼ��
	double** resual_graph = get_space(n, n);
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
			*(*(resual_graph + i) + j) = *(*(graph + i) + j);
	double max_flow = 0;
	int* path = new int[n];
	queue<int> Q;
	// ѭ��
	// Ѱ������·
	while (true)
	{
		while (!Q.empty())
			Q.pop();
		Q.push(s);
		memset(path, -1, sizeof(int) * n);
		while (!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			double* tmp = *(resual_graph + v);
			for (int i(0); i < n; i++)
			{
				if (*(tmp + i) > 0 && path[i] == -1)
				{
					path[i] = v;
					if (i == t)
						goto out;
					Q.push(i);
				}
			}
		}
		//
		out:
		// ����ҵ�����·��
		if (path[t] != -1)
		{
			// ����
			int v = t;
			int u, value;
			double add_flow = 99999;
			while (v != s)
			{
				u = path[v];
				value = *(*(resual_graph + u) + v);
				if (value < add_flow)
					add_flow = value;
				v = u;
			}
			// ���²�������
			max_flow += add_flow;
			v = t;
			while (v != s)
			{
				u = path[v];
				*(*(resual_graph + u) + v) -= add_flow;
				*(*(resual_graph + v) + u) += add_flow;
				v = u;
			}
		}
		else
		{
			break;
		}
	}
	return max_flow;
}

/**
����������
0 2 13
0 1 16
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 3 7
3 5 20
4 5 4
�����
23
*/