#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define ROWS 40
#define COLS 32
#define TOTAL_BLOCKS 1280
 
int bitmap[ROWS][COLS];//初始化二维阵列bitmap用于保存位示图，初始全为空闲
 
int cZero = 0;//磁盘块为空闲的计数器
 
void resetRandom() {
    /*
     *重置随机位示图，初始化位示图内容
     */
    srand(time(NULL));  // 用当前时间设置随机种子
    cZero = 0;// 初始化空闲块计数器
 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {// 遍历位示图
            bitmap[i][j] = rand() % 2;//随机设置每个块的状态0/1
            if (bitmap[i][j] == 0) {// 如果是空闲块，计数器加一
                cZero++;
            }
        }
    }
    printf("已重置位示图，free block: %d\n", cZero);
}
 
void allocate(int num) {
    /*
     *申请指定数量的空闲磁盘块
     *参数：
     *num:还需要的磁盘块数量
     */
    for (int i = 0; i < ROWS && num > 0; i++) {
        for (int j = 0; j < COLS && num > 0; j++) {// 遍历位示图
            if (bitmap[i][j] == 0) {// 如果找到空闲块
                bitmap[i][j] = 1;// 标记为已占用
                //start计算物理地址
                int blockNum = i * COLS + j;
                int cylinder = blockNum / (4 * 8);
                int temp = blockNum % (4 * 8);
                int head = temp / 8;
                int sector = temp % 8;
                //end计算物理地址
                printf("申请|块地址 %d (柱面:%d 磁头:%d 扇区:%d)\n", blockNum, cylinder, head, sector);
 
                num--;//所需磁盘块数量-1
                cZero--;//空闲块计数器-1
            }
        }
    }
    printf("申请完成，free block: %d\n", cZero);
}
 
void reclaim(int blockNum) {
    /*
     *回收指定块号的磁盘块
     *参数：
     *blockNum:需要回收的块号
     */
 
    int i = blockNum / COLS; //计算索引值
    int j = blockNum % COLS;//计算索引值
 
    if (bitmap[i][j] == 0) {//检查指定磁盘块是否为空闲块，如是，报错返回
        printf("出错：该磁盘块为空闲块\n");
        return;
    }
 
    bitmap[i][j] = 0;//如果指定磁盘块为占用块，回收该块
    cZero++;//空闲磁盘块数量+1
 
    //start 计算物理地址
    int cylinder = blockNum / (4 * 8);
    int temp = blockNum % (4 * 8);
    int head = temp / 8;
    int sector = temp % 8;
    //end 计算物理地址
 
    printf("回收|块地址 %d (柱面:%d 磁头:%d 扇区:%d)\n", blockNum, cylinder, head, sector);
    printf("free block: %d\n", cZero);
}
 
void displayMatrix() {
 
    /*
     *显示当前的位示图
     */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {//遍历位示图
            printf("%d ", bitmap[i][j]);//输出位示图
        }
        printf("\n");
    }
    printf("free block: %d\n", cZero);
}
 
int main() {
    int op;//初始化op变量用于记录用户操作输入
    resetRandom();//执行resetRandom函数随机化设置位示图
 
    while (1) {
        printf("\n=== 选择操作 ===\n");
        printf("0. 显示位示图\n");
        printf("1. 申请块\n");
        printf("2. 回收块\n");
        printf("3. 重置位示图\n");
        printf("请输入操作: ");
        if (scanf("%d", &op) != 1) {
            printf("输入错误\n");
            while (getchar() != '\n'); // 清除输入缓冲区
            continue;
        }
 
        switch (op) {
            case 0://显示位示图
                displayMatrix();
                break;
            case 1: //申请块
                {int n;
                printf("请输入申请块数量: ");
                if (scanf("%d", &n) != 1 || n <= 0) {//判断申请块数量是否合法
                    printf("出错：申请块数非正整数\n");
                    while (getchar() != '\n');
                    break;
                }
                if (n > cZero) {//判断申请块数量是否大于空闲块
                    printf("出错：申请块数 > 空闲块数\n");
                    break;
                }
                allocate(n);
                break;}
 
            case 2: //回收块
                {int addr;
                printf("请输入块地址: ");
                if (scanf("%d", &addr) != 1 || addr < 0 || addr >= TOTAL_BLOCKS) {//判断地址是否合法
                    printf("出错：块地址非法，应在0 ~ 1279 之间\n");
                    while (getchar() != '\n');
                    break;
                }
                reclaim(addr);
                break;}
 
            case 3://重置位示图
                resetRandom();
                break;
            default:
                printf("输入错误，请输入0~3之间的数字\n");
                break;
        }
    }
    return 0;
}
