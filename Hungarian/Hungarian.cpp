/**
* @Title: Hungarian�㷨
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/5
*/
#include <iostream>
#include <vector>
#include <set>

using namespace::std;
int* Hungarian(short** graph, int n, int m);
short** get_space(int n, int m);
void free_space(short** graph, int n, int m);
bool find_path(short** graph, int* X, int* Y, int* path_X, int* path_Y, int tmp, int xory, int n, int m);
int main()
{
	int n, m;
	cout << "������X�������Y�������" << endl;
	cin >> n >> m;
	int k;
	cout << "�����������" << endl;
	cin >> k;
	short** graph = get_space(n, m);
	int x, y;
	cout << "��������ߣ�0 3��ʾ��X��0��Y��3����" << endl;
	for (int i(0); i < k; i++)
	{
		cin >> x >> y;
		*(*(graph + x) + y) = 1;
	}
	int* X = Hungarian(graph, n, m);
	cout << "����ǣ�" << endl;
	for (int i(0); i < n; i++)cout << X[i] << " ";
	cout << endl;
	return 0;
}

/**
* ��ȡ�洢�ռ�
*/
short** get_space(int n, int m)
{
	short** ans = new short* [n];
	for (int i(0); i < n; i++)ans[i] = new short[m];
	return ans;
}

/**
* �ͷŴ洢�ռ�
*/
void free_space(short** graph, int n, int m)
{
	for (int i(0); i < n; i++)free(graph[i]);
	free(graph);
}

/**
* Hungarian�㷨
* @param:
* graph: n * mͼ
* n: X������
* m: Y������
* @return:
* X: X����Ӧ��Y���
*/
int* Hungarian(short** graph, int n, int m)
{
	// ��ʼ��
	int count = 0;
	int* X = new int[n];
	int* Y = new int[m];
	int* path_X = new int[n];
	int* path_Y = new int[m];
	memset(X, -1, sizeof(int) * n);
	memset(Y, -1, sizeof(int) * m);
	memset(path_X, 0, sizeof(int) * n);
	memset(path_Y, 0, sizeof(int) * m);
	// ѭ��
	for (int i(0); i < n; i++)
	{
		if (find_path(graph, X, Y, path_X, path_Y, i, 0, n, m))
		{
			memset(path_X, 0, sizeof(int) * n);
			memset(path_Y, 0, sizeof(int) * m);
		}
		else
		{
			break;
		}
	}
	return X;
}

/**
* DFSѰ������·��
* @param:
* graph: ͼ
* X: �����ӵ�X���(-1:δ���ӣ�
* Y: �����ӵ�Y���
* path_X: �ѷ��ʵ�X���(0:δ���ʣ�1:�ѷ���)
* path_Y: �ѷ��ʵ�Y���
* tmp: ��ǰ���ʽ��
* xory: ��ǰ���ʽ������X(0)��Y(1)
*/
bool find_path(short** graph, int* X, int* Y, int* path_X, int *path_Y, int tmp, int xory, int n, int m)
{
	bool is_find = false;
	// tmp��X������
	if (xory == 0)
	{
		// ���tmp�����
		if (path_X[tmp] == 1)
			return false;
		// ���tmp���ʹ�
		path_X[tmp] = 1;

		// ����tmp�����б�
		short* graph_row = *(graph + tmp);
		for (int i(0); i < n; i++)
		{
			// tmp->i ������
			if (*(graph_row + i) == 1)
			{
				// i����ͼ��
				if (Y[i] != -1)
				{
					bool isOK = find_path(graph, X, Y, path_X, path_Y, i, 1, n, m);
					// �ҵ�����·��
					if (isOK)
					{
						X[tmp] = i;
						Y[i] = tmp;
						return true;
					}
				}
				// i�㲻��ͼ��
				else
				{
					// ����tmp -> i
					X[tmp] = i;
					Y[i] = tmp;
					return true;
				}
			}
		}
		// ��ԭtmpδ����
		path_X[tmp] = 0;
	}
	// tmp��Y������
	else
	{
		// ���tmp�����
		if (path_Y[tmp] == 1)
			return false;
		// ���tmp���ʹ�
		path_Y[tmp] = 1;

		// ����tmp�����б�
		for (int i(0); i < n; i++)
		{
			// tmp->i ������
			if (*(*(graph + i) + tmp) == 1)
			{
				// i����ͼ��
				if (X[i] != -1)
				{
					bool isOK = find_path(graph, X, Y, path_X, path_Y, i, 0, n, m);
					// �ҵ�����·��
					if (isOK)
					{
						Y[tmp] = i;
						X[i] = tmp;
						return true;
					}
				}
				// i�㲻��ͼ��
				else
				{
					// ����tmp -> i
					Y[tmp] = i;
					X[i] = tmp;
					return true;
				}
			}
		}
		// ��ԭtmpδ����
		path_Y[tmp] = 0;
	}
	return false;
}