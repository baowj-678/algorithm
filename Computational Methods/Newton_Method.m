% Author: Bao Wenjie
% Date  : 2020-8-17
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 牛顿迭代法
% param: func: f(x)
% param: dfunc: f'(x)
% param: n: 迭代n次
% param x0: 初值

function X = Newton_Method(func, dfunc, n, x0)
X = x0;
for i = 1:n
    df = dfunc(X);
    if df == 0
        X = inf;
        return;
    end
    X = X - func(X)/dfunc(X);
end
end