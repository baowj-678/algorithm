/**
* @Title: �����С�����������Busacker-Gowan�㷨
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/4
*/
#include <iostream>
#include <queue>

#define	INF	1e17
#define E	0.0001

using namespace::std;
double** get_space(int n, int m);
void free_space(double** matrix, int n, int m);
double** Busacker_Gowan(double** contain_graph, double** cost_graph, int n, int s, int t);
int main()
{
	int n, m, s, t;
	cout << "������ͼ�������" << endl;
	cin >> n;
	cout << "�����������յ㣺" << endl;
	cin >> s >> t;
	double** contain_graph = get_space(n, n);
	double** cost_graph = get_space(n, n);
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
		{
			*(*(cost_graph + i) + j) = INF;
			*(*(contain_graph + i) + j) = 0;
		}
	cout << "�����������" << endl;
	cin >> m;
	cout << "������ߣ�����0 1 3 4������0-1�����������3������Ϊ4����" << endl;
	int x, y, a, b;
	for (int i(0); i < m; i++)
	{
		cin >> x >> y;
		cin >> a >> b;
		*(*(contain_graph + x) + y) = a;
		*(*(cost_graph + x) + y) = b;
		*(*(cost_graph + y) + x) = -b;
	}
	double** graph = Busacker_Gowan(contain_graph, cost_graph, n, s, t);
	cout << "��С���������Ϊ��" << endl;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}


/**
* ��ȡ����ռ�
*/
double** get_space(int n, int m)
{
	double** ans = new double* [n];
	for (int i(0); i < n; i++)
	{
		ans[i] = new double[m];
	}
	return ans;
}

/**
* ɾ������ռ�
*/
void free_space(double** matrix, int n, int m)
{
	for (int i(0); i < n; i++)
		free(matrix[i]);
	free(matrix);
}

/**
* @function: Busacker Gowan�㷨
* @param:
* contain_graph: �ߵ���������
* cost_graph: �ߵķ��þ���
* n: ������
* s: ���
* t: �յ�
* @return:
* graph: ÿ���ߵ������������
*/
double** Busacker_Gowan(double** contain_graph, double** cost_graph, int n, int s, int t)
{
	// ��ʼ��
	double** graph = get_space(n, n);
	double** cost_graph_tmp = get_space(n, n);
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
		{
			*(*(graph + i) + j) = 0;
			*(*(cost_graph_tmp + i) + j) = abs(*(*(contain_graph + i) + j) - 0) > E ? *(*(cost_graph + i) + j) : INF;
		}
	queue<int> Q;
	/**
	* ��¼ÿ������������
	*/
	int* count = new int[n];
	double* shortest = new double[n];
	int* path = new int[n];
	// ѭ��
	while (true)
	{
		// Ѱ������·��
		Q.push(s);
		memset(count, 0, sizeof(int) * n);
		for (int i(0); i < n; i++)
			shortest[i] = INF;
		shortest[s] = 0;
		memset(path, -1, sizeof(int) * n);
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			double* cost_edges = *(cost_graph_tmp + u);
			for (int i(0); i < n; i++)
			{
				if (abs(*(cost_edges + i) - INF) < E)
					continue;
				double value = shortest[u] + *(cost_edges + i);
				if (value < shortest[i])
				{
					shortest[i] = value;
					path[i] = u;
					if (count[i] > n)
					{
						goto out;
					}
					count[i]++;
					Q.push(i);
				}
			}
		}
	out:
		int tmp = shortest[t];
		// �ҵ����·��
		if (Q.empty() && shortest[t] != INF)
		{
			double add_flow = INF;
			double value;
			int v = t;
			int u = path[v];
			while (u != -1)
			{
				value = *(*(contain_graph + u) + v) - *(*(graph + u) + v);
				if (value < add_flow)
					add_flow = value;
				v = u;
				u = path[v];
			}
			v = t;
			u = path[v];
			while (u != -1)
			{
				*(*(graph + u) + v) += add_flow;
				*(*(graph + v) + u) -= add_flow;
				if (*(*(graph + u) + v) == *(*(contain_graph + u) + v))
					*(*(cost_graph_tmp + u) + v) = INF;
				else
					*(*(cost_graph_tmp + u) + v) = *(*(cost_graph + u) + v);

				if (*(*(graph + v) + u) == *(*(contain_graph + v) + u))
					*(*(cost_graph_tmp + v) + u) = INF;
				else
					*(*(cost_graph_tmp + v) + u) = *(*(cost_graph + v) + u);
				v = u;
				u = path[v];
			}
		}
		else
		{
			break;
		}
	}
	for (int i(0); i < n; i++)
		for (int j(0); j < n; j++)
			if (*(*(graph + i) + j) < 0)
				*(*(graph + i) + j) = 0;
	return graph;
}

/**
����������
5
0 4
6
0 1 2 4
0 2 8 1
1 4 4 2
2 1 9 2
2 3 10 3
3 4 8 2
�����
0 2 8 0 0
0 0 0 0 4
0 2 0 6 0
0 0 0 0 6
0 0 0 0 0
*/