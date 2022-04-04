% Author: Bao Wenjie
% Date  : 2020-8-17
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 简化牛顿迭代法
% param: func: f(x)
% param: dfunc: f'(x0)
% param: n: 迭代n次
% param: x0: 初值

function X = Newton_Method_Simple(func, c, n, x0)
if c == 0
    X = inf;
    return;
end
X = x0;
for i = 1:n
    X = X - func(X)/c;
end
end