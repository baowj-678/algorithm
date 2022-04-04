% Author: Bao Wenjie
% Date  : 2020-8-10
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction Crout分解
% param: A(1, n-1) 
% param: B(1, n) 
% param: C(1, n-1) 

function [alpha, beta, gamma] = Crout(A, B, C)
% 获取矩阵形状
n = size(B);
n = n(2);
% 初始化
alpha = zeros(1, n);
beta = zeros(1, n-1);
gamma = zeros(1, n-1);

% 进行分解
alpha(1) = B(1);
if alpha(1) == 0
    alpha = inf;
    beta = inf;
    gamma = inf;
    return
end
beta(1) = C(1)/alpha(1);
gamma(1:n-1) = A(1:n-1);
for i = 2:1:n-1
    alpha(i) = B(i) - A(i-1)*beta(i-1);
    if alpha(i) == 0
        alpha = inf;
        beta = inf;
        gamma = inf;
        return
    end
    beta(i) = C(i) / alpha(i);
end
alpha(n) = B(n) - A(n-1)*beta(n-1);
end