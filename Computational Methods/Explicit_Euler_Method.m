% Author: Bao Wenjie
% Date  : 2020-8-25
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 显式欧拉法求解常微分方程
% param func: dy/dx = f(x, y)的函数
% param y0: 初始值
% param x0: 初始值
% param h: 步长
% parma x0: 待求解点

function y = Explicit_Euler_Method(func, x0, y0, h, xn)
for i=x0+h:h:xn
    y0 = y0 + func(x0, y0);
    x0 = x0 + h;
end
end