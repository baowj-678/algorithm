% Author: Bao Wenjie
% Date  : 2020-8-12
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 梯形公式求积分
% param func: x=f(x)的函数
% param a: 积分下限
% param b: 积分上限
% param h: 区间大小

function y = Medi_Rectangle_Integral(func, a, b, h)
x = a+h/2:h:b;
y = sum(func(x(1:end-1))*h);
end