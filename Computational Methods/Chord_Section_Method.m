% Author: Bao Wenjie
% Date  : 2020-8-17
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 弦截法
% param: func: f(x)
% param: n: 迭代n次
% param x0: 初值
% param x1: 初值

function X = Chord_Section_Method(func, n, x0, x1)
for i = 1:n
    df = func(x1) - func(x0);
    if df == 0
        return;
    end
    X = x1 - func(x1)*(x1 - x0)/df;
    x0 = x1;
    x1 = X;
end
end

