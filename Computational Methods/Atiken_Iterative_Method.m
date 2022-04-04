% Author: Bao Wenjie
% Date  : 2020-8-12
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction Atiken迭代方法求非线性方程的解
% param func: x=f(x)的函数
% param e: 精确度
% param x0: 初值


function [x, n] = Atiken_Iterative_Method(func, e, x0)
y = func(x0);
z = func(y);
n = 1;
tmp = z - 2*y + x0;
if tmp == 0
    x = x0;
    return;
end
x = x0 - (y - x0)^2/tmp;
while abs(x - x0) > e && n < 1000
    x0 = x;
    y = func(x0);
    z = func(y);
    tmp = z - 2*y + x0;
    if tmp == 0
        return;
    end
    x = x0 - (y - x0)^2/tmp;
    n = n + 1;
end
end