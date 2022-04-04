% Author: Bao Wenjie
% Date  : 2020-8-12
% Copyright Bao Wenjie
% Email : bwj_678@qq,com
% Introduction 二分法求方程的解
% param func: 函数
% param l: 左端点值
% param r: 右端点值
% param e: 精确度


function [x, n] = Bisection_Method(func, l, r, e)
l_ = func(l);
r_ = func(r);
if l_ * r_ > 0
    x = inf;
    return;
end

x = (r + l)/2;
mid_ = func(x);
n = 1;
while r - l > e
    if mid_*l_ < 0
        r = x;
    elseif mid_*r_ < 0
        l = x;
    else
        break
    end
    n = n + 1;
    x = (r + l)/2;
    mid_ = func(x);
end
end
