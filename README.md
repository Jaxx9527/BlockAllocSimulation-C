# BlockAllocSimulation  
模拟位示图管理磁盘空间的分配与回收-以C語言實現

## 題目要求
| 位 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | … | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
|----|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|
| Bit[0] | 1 | 1 | 1 | 1 | 0 | 0 | 1 | … | 0 | 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| Bit[1] | 0 | 1 | 1 | 1 | 1 | 1 | 1 | … | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 |
| … | … |   |   |   |   |   |   |   | … |   |   |   |   |   |   |   |
| … | … |   |   |   |   |   |   |   | … |   |   |   |   |   |   |   |

1. 假设现在有一个硬盘，有4个磁头，40个柱面，1个磁头和1个柱面划分出8个扇区。磁盘的空间使用情况由位示图表示。位示图的每一位对应一个磁盘块，1表示占用，0表示空闲。  
2. 申请一块磁盘块时，由分配程序查位示图，找到一个为0的位，并计算磁盘的物理地址（即求出磁盘块对应的柱面号、磁头号和扇区号）。  
3. 当释放一个相对物理块时，运行回收程序，计算该磁盘块在位示图中的位置，在把相应的位清零。  
4. 设计一个磁盘块分配程序。输入需要申请的磁盘块数，运行分配程序后返回这些磁盘块的物理地址（柱面号、磁头号和扇区号），并且打印位示图。  
5. 设计一个磁盘块回收程序，输入一系列磁盘块的物理地址，在位示图上对应的位置清零，表示释放了该磁盘块。并且打印位示图。

## 需求分析
2个主要功能：磁盘块分配和磁盘块回收，以及显示磁盘块的位示图。以及製作显示、重置位示图的函数。  
<table >
<tr>
  <td><img width="100%" alt="image" src="https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.1.png" />
</td>
  <td><img width="100%" alt="image" src="https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.2.png" />
</td>
</tr>
  <tr>
    <td align="center">图1.1 磁盘块分配流程图</td>
    <td align="center">图1.2 磁盘块回收流程图	</td>
  </tr>
</table>

## 運行環境 
Ubuntu 14.04 LTS  
gcc version 4.8.4  
编译标准：C99  

## 運行截圖
![https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.4.png](https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.4.png)  
图1.4 程序执行显示位视图截图  

![https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.5.png](https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.5.png)  
图1.5 程序执行分配磁盘块成功截图  

![图1.6 程序执行分配磁盘块失败截图-输入块数大于空闲块](https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.6.png)  
图1.6 程序执行分配磁盘块失败截图-输入块数大于空闲块  

![图1.7 程序执行分配磁盘块失败截图-输入块数非正整数](https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.7.png)  
图1.7 程序执行分配磁盘块失败截图-输入块数非正整数  

![图1.8 程序执行回收磁盘块成功截图](https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.8.png)  
图1.8 程序执行回收磁盘块成功截图  

![图1.9 程序执行分配磁盘块失败截图-输入块地址为空闲块](https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.9.png)  
图1.9 程序执行分配磁盘块失败截图-输入块地址为空闲块  

![图1.10 程序执行分配磁盘块失败截图-输入块地址非法](https://github.com/Jaxx9527/BlockAllocSimulation-C/blob/main/img/1.10.png)  
图1.10 程序执行分配磁盘块失败截图-输入块地址非法

