#include <stdio.h>
enum Matrixtype{
    z1,
    z2,
    z3,
    z4,
    s1,
    s2,
    s3,
    s4,
    z5,
    z6,
    z7,
    z8,
    s5,
    s6,
    s7,
    s8,
};
const int MatrixTransform[16][2] = {
    {-1,0},{2,0},{2,1},{-1,1},{0,0},{1,0},{1,1},{0,1},{-1,0},{2,0},{2,1},{-1,1},{0,0},{1,0},{0,1},{1,1}
    //z1    z2     z3    z4     s1    s2    s3    s4    z5     z6    z7    z8    s5     s6    s7    s8
};
        

//横转竖通用函数模版
//reverse_situation = -1 无需倒序Z字型
//reverse_situation = 0 偶数行(列)需要倒序   reverse_situation = 1奇数行(列)需要倒序  reverse_situation = 2奇数偶数行(列)都要倒序
//sort_order = 0 正序（从左到右） sort_order = 1倒序(从右到左)
int acrossToVerticalTransform(int num, int row, int column,int identity_reverse_situation,int identity_sort_order,int target_reverse_situation,int target_sort_order){
    int res;
    //获取identity中num坐标
    int num_row = num / column;
    int num_column = (num % column)-1;
    // 处理整除的情况
    if (num % column == 0) // 4%4=0
    {
        // num可被列数整除时纠正行号
        num_row--;
        // num列号纠正为末尾
        num_column = column - 1;
    }
    // identity整体倒序情况
    if(identity_sort_order){
        num_row = row - num_row - 1;
        num_column = column - num_column -1;
    }
    //根据奇数偶数行选择倒序的情况
    if((num_row+1) % 2 == identity_reverse_situation){
        num_column = column - num_column - 1;
    }
    //奇数偶数行都要倒序情况
    else if(identity_reverse_situation == 2){
        num_column = column - num_column - 1;
    }

    //找到target标准图中的坐标位置
    //target根据奇数偶数行选择倒序的情况
    if ((num_column+1) % 2 == target_reverse_situation)
    {
        num_row = row - num_row - 1;
    }
    //target奇数偶数行都要倒序情况
    else if(target_reverse_situation == 2){
        num_row = row - num_row - 1;
    }
    //计算值
    res = num_column * row + num_row + 1;
    // target是整体倒序的情况
    if(target_sort_order){
        res = column * row - res + 1;
    }
    return res;
}

//横转横通用函数模版
//reverse_situation = -1 无需倒序Z字型
//reverse_situation = 0 偶数行（列）需要倒序   reverse_situation = 1奇数行（列）需要倒序  reverse_situation = 2奇数偶数行(列)都要倒序
//target_sort_order = 0 正序（从左到右） target_sort_order = 1倒序(从右到左)
int acrossToAcrossTransform(int num, int row, int column,int identity_reverse_situation,int identity_sort_order,int target_reverse_situation,int target_sort_order){
    int res;
    //获取identity中num坐标
    int num_row = num / column;
    int num_column = (num % column)-1;
    // 处理整除的情况
    if (num % column == 0) // 4%4=0
    {
        // num可被列数整除时纠正行号
        num_row--;
        // num列号纠正为末尾
        num_column = column - 1;
    }
    // identity整体倒序情况
    if(identity_sort_order){
        num_row = row - num_row - 1;
        num_column = column - num_column -1;
    }
    //根据奇数偶数行选择倒序的情况
    if((num_row+1) % 2 == identity_reverse_situation){
        num_column = column - num_column - 1;
    }
    //奇数偶数行都要倒序情况
    else if(identity_reverse_situation == 2){
        num_column = column - num_column - 1;
    }
    //找到target标准图中的坐标位置
    //target根据奇数偶数行选择倒序的情况
    if ((num_row+1) % 2 == target_reverse_situation)
    {
        num_column = column - num_column - 1;
    }
    //target奇数偶数行都要倒序情况
    else if(target_reverse_situation == 2){
        num_column = column - num_column - 1;
    }
    //计算值
    res = num_row * column + num_column + 1;
    // target是整体倒序的情况
    if(target_sort_order){
        res = column * row - res + 1;
    }
    return res;
}
//竖转竖通用函数模版
//reverse_situation = -1 无需倒序Z字型
//reverse_situation = 0 偶数行（列）需要倒序   reverse_situation = 1奇数行（列）需要倒序  reverse_situation = 2奇数偶数行(列)都要倒序
//target_sort_order = 0 正序（从左到右） target_sort_order = 1倒序(从右到左)
int verticalToVerticalTransform(int num, int row, int column,int identity_reverse_situation,int identity_sort_order,int target_reverse_situation,int target_sort_order){
    int res;
    //获取identity中num坐标
    int num_row = (num % row)-1;
    int num_column = num / row;
    // 处理整除的情况
    if (num % row == 0) // 4%4=0
    {
        // num可被列数整除时纠正行号
        num_column--;
        // num列号纠正为末尾
        num_row = row - 1;
    }
    // identity整体倒序情况
    if(identity_sort_order){
        num_row = row - num_row - 1;
        num_column = column - num_column -1;
    }
    //根据奇数偶数行选择倒序的情况
    if((num_column+1) % 2 == identity_reverse_situation){
        num_row = row - num_row - 1;
    }
    //奇数偶数行都要倒序情况
    else if(identity_reverse_situation == 2){
        num_row = row - num_row - 1;
    }
    //找到target标准图中的坐标位置
    //target根据奇数偶数行选择倒序的情况
    if ((num_column+1) % 2 == target_reverse_situation)
    {
        num_row = row - num_row - 1;
    }
    //target奇数偶数行都要倒序情况
    else if(target_reverse_situation == 2){
        num_row = row - num_row - 1;
    }
    //计算值
    res = num_column * row + num_row + 1;
    // target是整体倒序的情况
    if(target_sort_order){
        res = column * row - res + 1;
    }
    return res;
}
//竖转横通用函数模版
//reverse_situation = -1 无需倒序Z字型
//reverse_situation = 0 偶数行（列）需要倒序   reverse_situation = 1奇数行（列）需要倒序  reverse_situation = 2奇数偶数行(列)都要倒序
//target_sort_order = 0 正序（从左到右） target_sort_order = 1倒序(从右到左)
int verticalToAcrossTransform(int num, int row, int column,int identity_reverse_situation,int identity_sort_order,int target_reverse_situation,int target_sort_order){
    int res;
    //获取identity中num坐标
    int num_row = (num % row)-1;
    int num_column = num / row;
    // 处理整除的情况
    if (num % row == 0) // 4%4=0
    {
        // num可被列数整除时纠正行号
        num_column--;
        // num列号纠正为末尾
        num_row = row - 1;
    }
    // identity整体倒序情况
    if(identity_sort_order){
        num_row = row - num_row - 1;
        num_column = column - num_column - 1;
    }

    //根据奇数偶数行选择倒序的情况
    if((num_column+1) % 2 == identity_reverse_situation){
        num_row = row - num_row - 1;
    }
    //奇数偶数行都需要倒序情况
    else if(identity_reverse_situation == 2){
        num_row = row - num_row - 1;
    }


    //找到target标准图中的坐标位置
    //target根据奇数偶数行选择倒序的情况
    if ((num_row+1) % 2 == target_reverse_situation)
    {
        num_column = column - num_column - 1;
    }
    //target奇数偶数行都要倒序情况
    else if(target_reverse_situation == 2){
        num_column = column - num_column - 1;
    }
    //计算值
    res = num_row * column + num_column + 1;
    if(target_sort_order){
        res = column * row - res + 1;
    }
    return res;
}

int transform(int num, int row, int column, int identity,int target){
    int res;
    if(identity < 0 || identity > 15 || target < 0 || target > 15){
        return -1;
    }
    if(identity < 8 && target < 8){
        res = acrossToAcrossTransform(num,row,column,MatrixTransform[identity][0],MatrixTransform[identity][1],MatrixTransform[target][0],MatrixTransform[target][1]);
    }else if(identity < 8 && target >= 8){
        res = acrossToVerticalTransform(num,row,column,MatrixTransform[identity][0],MatrixTransform[identity][1],MatrixTransform[target][0],MatrixTransform[target][1]);
    }else if(identity >= 8 && target < 8){
        res = verticalToAcrossTransform(num,row,column,MatrixTransform[identity][0],MatrixTransform[identity][1],MatrixTransform[target][0],MatrixTransform[target][1]);
    }else if(identity >= 8 && target >= 8){
        res = verticalToVerticalTransform(num,row,column,MatrixTransform[identity][0],MatrixTransform[identity][1],MatrixTransform[target][0],MatrixTransform[target][1]);
    }
    return res;
}

int main()
{
    int i = 1;
    int res;
    for(;i<=12;i++){
        res = transform(i,3,4,z1,s4);
        printf("%d->%d\n",i,res);
    }
    return 0;
}