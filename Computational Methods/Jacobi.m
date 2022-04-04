% Author: Bao Wenjie
% Date  : 2020-8-10
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 雅可比迭代法求解线性方程组
% param: A(n, n) 满足Ax=b
% param: b(n, 1)


function X = Jacobi(A, b)
% 获取矩阵形状
n = size(A);
n = n(1);
% 构造B矩阵
D = zeros(n);
D_ = zeros(n);
for i = 1:1:n
    if A(i, i) == 0
        X = inf;
        return;
    end
    D_(i, i) = 1/A(i, i);
    D(i, i) = A(i, i);
end
B = D_*(D - A);
% 计算谱半径，判断是否收敛
if max(abs(eig(B))) >= 1
    X = inf;
    return;
end
% 构造f向量
f = D_*b;

% 迭代计算
X = zeros(n, 1);
for i = 1:1:100
    X = B*X + f;
end
end