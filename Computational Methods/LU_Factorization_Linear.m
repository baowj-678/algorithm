% Author: Bao Wenjie
% Date  : 2020-8-10
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction LU分解求解线性方程组
% param: A(n, m) 满足Ax=b
% param: b(n, 1) 满足Ax=b

function [X] = LU_Factorization_Linear(A, b)
% LU分解
[L, U] = LU_Factorization(A);
% 如果无法进行LU分解
if L == inf
    X = inf;
    return;
end
% 得到矩阵形状
n = size(A);
m = n(2);
n = n(1);

% 求解Ly = b
y = zeros(n, 1);
y(1) = b(1);
for i = 2:1:n
    y(i) = b(i) - L(i, 1:i-1) * y(1:i-1);
end
% 求解 Ux = y
X = zeros(n, 1);
X(n) = y(n) / U(n, n);
for i = n-1:-1:1
    X(i) = (y(i) - U(i, i+1:n)*X(i+1:n)) / U(i, i);
end
end