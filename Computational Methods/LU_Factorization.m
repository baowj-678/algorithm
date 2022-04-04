% Author: Bao Wenjie
% Date  : 2020-8-9
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction LU分解
% param: A(n, m) 满足Ax=b

function [L, U] = LU_Factorization(A)
% 预处理
n = size(A);
m = n(2);
n = n(1);
L = zeros(n, m);
U = zeros(n, m);
% 第一步
U(1, 1:m) = A(1, 1:m);
L(1, 1) = 1;
if U(1, 1) == 0
    L = inf;
    U = inf;
    return;
end
L(2:n, 1) = A(2:n, 1) ./ U(1, 1);
% 第二步
for r = 2:1:n
    U(r, r:m) = A(r, r:m) - L(r, 1:r-1) * U(1:r-1, r:m);
    L(r, r) = 1;
    if U(r, r) == 0
        L = inf;
        U = inf;
        return;
    end
    L(r+1:n, r) = (A(r+1:n, r) - L(r+1:n, 1:r-1) * U(1:r-1, r)) ./ U(r, r);
end
end