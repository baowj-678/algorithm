/**
* @Title: ���Լ��(System of Difference Constrains)
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/2
*/
#include "SDC.h"
#include <iostream>
#include <vector>

using namespace::std;

int main()
{
	cout << "���������������" << endl;
	int n;
	cin >> n;
	cout << "������Լ�����̸�����" << endl;
	int m;
	cin >> m;
	cout << "������Լ�����̣�1 2 6.7����x1 - x1 <= 6.7������1��ʼ����" << endl;

	vector<vector<pEdge>> vec(n);
	for (int i(0); i < m; i++)
	{
		int x, y;
		double value;
		cin >> x >> y >> value;
		pEdge tmp = new Edge;
		tmp->from = y - 1;
		tmp->to = x - 1;
		tmp->value = value;
		vec[y - 1].push_back(tmp);
	}
	int* ans = SPFA(n, vec, 0);
	for (int i(0); i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}