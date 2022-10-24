## 如何生成 Brainf\*ck 程序
<a href="https://github.com/wchen0/BF/">仓库地址</a><br>
其中 `var.h var.cpp` 是生成 BF 的库。compiler.cpp 是一个简易的 BF 编译器。     
此程序提供了生成 Brainf\*ck 程序的简单方法。       

已经实现：

- while(!x) 语句
- if(!x) 语句
- 整型加、减、乘、除
- 整型大小比较及其他基本操作
- ~~数组~~ **尚未实现**
- ~~排序~~ **尚未实现**
- ~~运算符重载~~ **尚未实现**

## 如何使用
#### 调用
在 `main` 函数中调用 `var.h` 提供的接口，即可在 `out.bf` 中生成对应的 `bf` 代码。      
`optimize` 函数是对 `tmp.bf` 的优化，它将删除冗余的 `<`,`>` 记号，生成 `out.bf`。

```cpp
#include "var.h"

void test() {
    // finish your code here
}

int main(void) {
    freopen("tmp.bf", "w", stdout);
    test();

#ifndef __linux___
    freopen("CON", "w", stdout);
#else
    freopen("/dev/tty", "w", stdout);
#endif
    FILE* fin = fopen("tmp.bf", "r");
    FILE* fout = fopen("out.bf", "w");
    optimize(fin, fout);
    printf("code is generated in out.bf\n");
    if (remove("tmp.bf") != 0) {
        perror("remove");
    }
    return 0;
}
```

#### var 类型
输入一个数(0~9)，判断是否大于 '5'。     
**var 对象在调用构造函数时，会在  BF 内存中申请空间，且不会从  BF 内存中释放。**
```cpp
var i1('5');
var i2;
i2.input();
var ret;
i2.greater(i1, ret);        // ret <- (i2 > i1)
ret.output_ascii();
```

#### if 语句
若 `a - b == 1`，输出 'Y'；否则输出 'N'。
```cpp
var a, b;
a.input(); 
b.input();

var c('Y'), d;
a.minus(b, d);      // d <- a - b
    
d.decrement();      // d <- d - 1
d.if_begin();       // if (d != 0)
    c.set('N');
d.if_end();
c.output();
```

#### while 语句
输出 `x` 个 '1'，`x` 在 0~9。
```cpp
var x, r('5');
x.input();
x.decrement('0');
x.while_begin();
    x.decrement();
    r.output();
x.while_end();
```

#### 基本运算
乘法
```cpp
var a, b, ret;
a.input();
b.input();
a.decrement('0');
b.decrement('0');
a.multiply(b, ret);         
// 除法：a.divide(b, ret);
// 加法：a.add(b, ret);
// 减法：a.minus(b, ret);
ret.output_ascii();
```

#### 字符打印
方法1：
```cpp
// hello world
var v1('h'), v2('e'), v3('l'), v4('o'), v5(' '), v6('w'), v7('r'), v8('d');
v1.output();v2.output();v3.output();v3.output();
v4.output();v5.output();v6.output();v4.output();
v7.output();v3.output();v8.output();
```

方法2：
```cpp
std::string s = "brainfuck\n";
for (char c : s) {
    var a(c);
    a.output();
}
```

## 结语
由于时间有限，写得比较粗糙。最终的效果也不是很好。     
要实现一个 BF 程序，比如冒泡排序的算法，还是有难度的，需要再封装一些数据结构。      
由于重载运算符函数会增加额外的中间变量，故暂时没有实现重载运算符。     

2022-10-24