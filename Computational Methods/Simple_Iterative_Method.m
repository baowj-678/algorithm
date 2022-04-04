% Author: Bao Wenjie
% Date  : 2020-8-12
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 简单迭代方法求非线性方程的解
% param func: x=f(x)的函数
% param e: 精确度
% param x0: 初值


function [x, n] = Simple_Iterative_Method(func, e, x0)
n = 1;
x = func(x0);
while abs(x0 - x) > e && n < 1000
    x0 = x;
    x = func(x);
    n = n + 1;
end
end