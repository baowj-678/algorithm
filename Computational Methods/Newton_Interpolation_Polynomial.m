% Author: Bao Wenjie
% Date  : 2020-8-22
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 牛顿插值多项式
% param:
%       x: (n, 1) 自变量
%       y: (n, 1) 因变量
%       Y_last: n_last阶下Y的值
%       X: 插值点(n, 1)
%       X_last: (x-x1)(x-x1)...(x-xlast)
%       n_last: 求解差商的阶数,(0)代表从头开始
%       n: 目标插值阶数
% return:
%        Y: 结果
%        y_next: n阶差商的值
%        X_next: (x-x1)(x-x2)...(x-xn)

function [Y, y_next, X_next] = Newton_Interpolation_Polynomial(x, y, Y_last, X, X_last, n_last, n)
% 从头开始
if n_last == 0
    Y_last = ones(size(X)).*y(1);
    X_last = ones(size(X));
end
for i = n_last + 1:n
    % 计算i阶差商
    y = (y(2:end) - y(1:end-1))./(x(1+i:end) - x(1:end-i));
    % 计算(x-x1)(x-x2)...(x-xi)
    X_last = X_last.*(X - x(i));
    % 计算Y、
    Y = Y_last + y(1).*X_last;
end
y_next = y;
X_next = X_last;
end