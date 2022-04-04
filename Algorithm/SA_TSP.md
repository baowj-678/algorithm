# 模拟退火算法

### 简介：

**模拟退火算法(Simulated Annealing, SA)**，是一种适合解决大型组合优化问题，特别是**NP完全**类问题的通用有效近似算法。

****



### 算法过程：

```flow
flow
st=>start: 开始
op1=>operation: 确定初始温度t_0
               终止温度t_end
cond1=>condition: 是否满足算法收敛准则
                  (温度小于t_end)?
cond2=>condition: 是否满足蒙特卡洛
                     抽样准则？
op_out=>operation: 输出结果
op2=>operation: 由当前状态S1产生新状态S2
op3=>operation: 接收状态S2
op4=>operation: 拒绝状态S2
op5=>operation: 更新温度
e=>end
st->op1->cond1
cond1(yes)->op_out
op5->cond1
cond1(no)->op2->cond2
cond2(yes)->op3->op5
cond2(no)->op4->op5
op_out->end
```

