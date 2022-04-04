% Author: Bao Wenjie
% Date  : 2020-8-22
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 计算n阶差商
% param x: (n, 1) 自变量
% param y: (n, 1) 因变量
% param n: 求解差商的阶数

function dx = Difference_Quotient(x, y, n)
for i = 1:n
    y = (y(2:end) - y(1:end-1))./(x(1+i:end) - x(1:end-i));
end
dx = y;
end