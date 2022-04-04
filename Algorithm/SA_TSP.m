% @Title: 模拟退火算法求解TSP问题
% @Author: Bao Wenjie
% @Email: bwj_678@qq.com
% @Date: 2020/9/3

function distance = SA_TSP(X, q)
%% 1.计算距离矩阵
D = Distance(X); % 计算距离矩阵
N = size(D,1);   % 城市的个数

%% 2.初始化参数
T0 = 1e10;     % 初始温度
Tend = 1e-30;  % 终止温度
L = 2;         % 各温度下的迭代次数
% q = 0.9;       % 降温速率
               % 计算迭代的次数
Time = ceil(double(solve([num2str(T0), '*', num2str(q), '^x =', num2str(Tend)])));
count = 0;              %迭代计数
Obj = zeros(Time,1);    %目标值矩阵初始化
track = zeros(Time,N);  %每代的最优路线矩阵初始化


%% 3.随机产生一个初始路线
S1 = randperm(N);
DrawPath(S1,X)
disp('初始种群中的一个随机值:')
OutputPath(S1);
Rlength = PathLength(D,S1);
disp(['总距离：',num2str(Rlength)]);

%% 4.迭代优化
 
while T0 > Tend
    count = count + 1;  %更新迭代次数
	% 1. 产生新解
    S2 = NewAnswer(S1);
    % 2.Metropolis法则判断是否接受新解
    [S1,R] = Metropolis(S1,S2,D,T0); % Metropolis 抽样算法
    % 3.记录每次迭代过程的最优路线
    if count == 1 || R < Obj(count - 1)
        Obj(count) = R; % 如果当前温度下最优路程小于上一路程则记录当前路程
    else
        Obj(count) = Obj(count - 1);%如果当前温度下最优路程大于上一路程则记录上一路程
    end
    track(count, :) = S1;
    T0 = q * T0; %降温
 
end
 
%% 5.优化过程迭代图
figure
plot(1:count,Obj)
xlabel('迭代次数')
ylabel('距离')
title('优化过程')

%% 6.绘制最优路径图
DrawPath(track(end,:), X)

%% 7.输出最优解的路线和总距离
disp('最优解:')
S = track(end,:);
p = OutputPath(S);
disp(['总距离：',num2str(PathLength(D,S))]);

distance = p;
end

%%%%%%%%%%%%%%%%%%% Distance函数%%%%%%%%%%%%%%%%%%%%
function D = Distance(citys)
%% 计算两两城市之间的距离
% 输入 citys? 各城市的位置坐标
% 输出 D?两两城市之间的距离
n = size(citys,1);
D = zeros(n,n);
for i = 1:n
    for j =i+1:n
        D(i, j) = sqrt(sum((citys(i,:) - citys(j,:)).^2));
        D(j, i) = D(i,j);
    end
end
end

%%%%%%%%%%%%%%%%%%% DrawPath函数%%%%%%%%%%%%%%%%%%%%
function DrawPath(Route,citys)
%% 画路径函数
%输入
% Route? 待画路径??
% citys? 各城市坐标位置
figure
plot([citys(Route,1);citys(Route(1),1)],...
[citys(Route,2);citys(Route(1),2)],'o-');
grid on
for i = 1:size(citys,1)
    text(citys(i,1),citys(i,2),['    ', num2str(i)]);
end
text(citys(Route(1),1),citys(Route(1),2),'       起点');
text(citys(Route(end),1),citys(Route(end),2), '       终点');
end


%%%%%%%%%%%%%%%%%%% Metropolis函数%%%%%%%%%%%%%%%%%%%%
function [S,R] = Metropolis(S1,S2,D,T)
%% 输入
% S1：?当前解
% S2:   新解
% D:??距离矩阵（两两城市的之间的距离）
% T:??当前温度
%% 输出
% S：??下一个当前解
% R：??下一个当前解的路线距离

R1 = PathLength(D,S1); %计算当前路线长度
N = length(S1); %得到城市的个数
R2 = PathLength(D,S2); %计算新解路线长度
dC = R2 - R1; %计算能力之差
if dC < 0  %如果能力降低 接受新路线
    S = S2;
    R = R2;
elseif exp(-dC/T) >= rand % 以exp(-dC/T)概率接受新路线
    S = S2;
    R = R2;
else % 不接受新路线
    S = S1;
    R = R1;
end
end

%%%%%%%%%%%%%%%%%%% NewAnswer函数%%%%%%%%%%%%%%%%%%%%
function S2 = NewAnswer(S1)
%% 输入
% S1:当前解
%% 输出
% S2：新解
N = length(S1);
S2 = S1;
a = round(rand(1,2)*(N-1)+1); %产生两个随机位置 用来交换
W = S2(a(1));
S2(a(1)) = S2(a(2));
S2(a(2)) = W; %得到一个新路线
end


%%%%%%%%%%%%%%%%%%% OutputPath函数%%%%%%%%%%%%%%%%%%%%
function p = OutputPath(R)
%% 输出路径函数 
% 输入：R 路径
R = [R,R(1)];
N = length(R);
p = num2str(R(1));
for i = 2:N
    p = [p,'—>',num2str(R(i))];
end
disp(p)
end
 
 
%%%%%%%%%%%%%%%%%%% PathLength函数%%%%%%%%%%%%%%%%%%%%
function Length = PathLength(D,Route)
%% 计算各个体的路径长度
% 输入：
% D?两两城市之间的距离
% Route 个体的轨迹
 
Length = 0; 
n = size(Route, 2);
for i = 1:(n - 1)
        Length = Length + D(Route(i), Route(i + 1));
end
Length = Length + D(Route(n), Route(1));
end