## 如何生成 Brainf\*ck 程序
此项目地址为：<a href="https://github.com/wchen0/BF/">仓库地址</a><br>
其中 `var.h var.cpp` 是生成 BF 的库。此项目提供了生成 Brainf\*ck 程序的简单方法。       
`compiler.cpp` 是一个简易的 BF 编译器。      
<a href="https://rextester.com/l/brainfuck_online_compiler">网址</a>是一个比较好的 BF 在线编译器。         

已经实现：

- while(!x) 语句
- if(!x) 和 if(x) 语句
- 整型 +、-、\*、/
- 整型大小比较及其他基本操作
- 部分运算符重载，**部分功能尚未实现**
- ~~数组~~，**尚未实现**，不能通过变量访问数组

## 关于 Brainf\*ck
从维基百科上截取如下内容。
<h4><span class="mw-headline" id="Commands">Commands</span><span class="mw-editsection"><span class="mw-editsection-bracket"></span></span></h4>
<p>The eight language commands each consist of a single character:
</p>
<table class="wikitable">
<tbody><tr>
<th style="text-align:center;">Character
</th>
<th align="left">Meaning
</th></tr>
<tr>
<td style="text-align:center"><code>&gt;</code>
</td>
<td>Increment the <a href="/wiki/Pointer_(computer_programming)" title="Pointer (computer programming)">data pointer</a> (to point to the next cell to the right).
</td></tr>
<tr>
<td style="text-align:center"><code>&lt;</code>
</td>
<td>Decrement the data pointer (to point to the next cell to the left).
</td></tr>
<tr>
<td style="text-align:center"><code>+</code>
</td>
<td>Increment (increase by one) the byte at the data pointer.
</td></tr>
<tr>
<td style="text-align:center"><code>-</code>
</td>
<td>Decrement (decrease by one) the byte at the data pointer.
</td></tr>
<tr>
<td style="text-align:center"><code>.</code>
</td>
<td>Output the byte at the data pointer.
</td></tr>
<tr>
<td style="text-align:center"><code>,</code>
</td>
<td>Accept one byte of input, storing its value in the byte at the data pointer.
</td></tr>
<tr>
<td style="text-align:center"><code>[</code>
</td>
<td>If the byte at the data pointer is zero, then instead of moving the <a href="/wiki/Program_Counter" class="mw-redirect" title="Program Counter">instruction pointer</a> forward to the next command, <a href="/wiki/Branch_(computer_science)" title="Branch (computer science)">jump</a> it <i>forward</i> to the command after the <i>matching</i> <code>]</code> command.
</td></tr>
<tr>
<td style="text-align:center"><code>]</code>
</td>
<td>If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it <i>back</i> to the command after the <i>matching</i> <code>[</code> command.
</td></tr></tbody></table>

<table class="wikitable">
<tbody><tr>
<th style="text-align:center;">brainfuck command
</th>
<th style="text-align:left;"><a href="/wiki/C_(programming_language)" title="C (programming language)">C</a> equivalent
</th></tr>
<tr>
<td style="text-align:center;">(Program Start)</td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="kt">char</span><span class="w"> </span><span class="n">array</span><span class="p">[</span><span class="mi">30000</span><span class="p">]</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="p">{</span><span class="mi">0</span><span class="p">};</span><span class="w"> </span><span class="kt">char</span><span class="w"> </span><span class="o">*</span><span class="n">ptr</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">array</span><span class="p">;</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>&gt;</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="o">++</span><span class="n">ptr</span><span class="p">;</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>&lt;</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="o">--</span><span class="n">ptr</span><span class="p">;</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>+</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="o">++*</span><span class="n">ptr</span><span class="p">;</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>-</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="o">--*</span><span class="n">ptr</span><span class="p">;</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>.</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="n">putchar</span><span class="p">(</span><span class="o">*</span><span class="n">ptr</span><span class="p">);</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>,</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="o">*</span><span class="n">ptr</span><span class="w"> </span><span class="o">=</span><span class="w"> </span><span class="n">getchar</span><span class="p">();</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>[</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="k">while</span><span class="w"> </span><span class="p">(</span><span class="o">*</span><span class="n">ptr</span><span class="p">)</span><span class="w"> </span><span class="p">{</span><span class="w"></span></code>
</td></tr>
<tr>
<td style="text-align:center;"><code>]</code></td>
<td><code class="mw-highlight mw-highlight-lang-c mw-content-ltr" dir="ltr"><span class="p">}</span><span class="w"></span></code>
</td></tr></tbody></table>



## 如何使用（如何按照我的需求，生成BF程序）
#### 调用 var.h 生成 BF 代码
在 `main.cpp` 的 `main` 函数中调用 `var.h` 提供的接口，即可在 `out.bf` 中生成对应的 `bf` 代码。      
`optimize` 函数是对 `tmp.bf` 的优化，它删除冗余的 `<`,`>` 记号，生成 `out.bf`。

```cpp
#include "var.h"

void test() {
    // finish your code here
}

int main(void) {
    freopen("tmp.bf", "w", stdout);
    test();

#ifndef __linux__

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
`var` 类型本质上是 `uint8_t`，也可以被理解为 `char` 或 `int8_t`。下面是一个例子。       
输入一个数(0~9)，判断是否大于 '5'。     
**var 对象在调用构造函数时，会在  BF 机器内存中自动申请空间，且不会从  BF 内存中释放。**
```cpp
var i1('5');                // 实例化对象 '5'
var i2;                     // 实例化对象 0
i2.input();
var ret;
i2.greater(i1, ret);        // ret <- (i2 > i1)
ret.output_ascii();
```

以上代码描述的 BF 代码如下：
```c
++++++++[>++++++<-]>+++++>,>>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-][-]<<<<[-
>>>>+>+<<<<<]>>>>>[-<<<<<+>>>>>][-]<<<[-]>[>>[-]<[->+>+<<]>>[-<<+>>][-
]+>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<[-]>[-]>]>[-]<<[->>+>+<<<]>>
>[-<<<+>>>][-]<[[-]<<<[-]<<<<<<++++++++[-]>>>>>>+>>>]<<[-]>>[-]<<<[->>
>+>+<<<<]>>>>[-<<<<+>>>>][-]<[[-]<<<<<<[-]<<<++++++++[-]>>>+>>>>>>]<<<
<<->-<][-]>[-]>[-]>[-]<<<<[->>>>+>+<<<<<]>>>>>[-<<<<<+>>>>>][-]<<<<<<<
<++++++++[>>>>>>>++++++<<<<<<<-]>>>>>>>.[-]
```

#### if 语句
若 `a - b == 1`，则输出 'Y'；否则输出 'N'。
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

判断输入字符是否为数字，相当于 isdigit(char)
```cpp
var flag;
var val;
val.input();

val.greater_eq('0', flag);      // flag = (val >= '0');
flag.if_begin();                // if(flag == true)
val.greater('9', flag);         // flag = (val > '9);
flag.flip();                    // flag = !flag
flag.if_end();
flag.output_ascii();
```
生成 BF 代码（很长）
```
>>,<<++++++++[>>>>++++++<<<<-]>>>>>[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>][-][-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<<<<[-]>>[>>[-]<[->+>+<<]>>[-<<+>>][-]+>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<[-]>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<[-]<<<<<<<++++++++[-]>>>>>>>+>>>]<<[-]>>[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>][-]<[[-]<<<<<<<[-]<<<++++++++[-]>>>+>>>>>>>]<<<<<->-<][-]>[-]>[-]<<<[-]>>>[-]<<<<[->>>>+>+<<<<<]>>>>>[-<<<<<+>>>>>][-]+>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<[-]>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<[-]<<<<<<<++++++++[-]>>>>>>>+>>>]<<[-]>>[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>][-]<[[-]<<<<<<<<<<++++++++[>>>>>>>>>>>++++++<<<<<<<<<<<-]>>>>>>>>>>>>>>[-]<<<<<<<<<<<<[->>>>>>>>>>>>+>+<<<<<<<<<<<<<]>>>>>>>>>>>>>[-<<<<<<<<<<<<<+>>>>>>>>>>>>>][-][-]<<<<[->>>>+>+<<<<<]>>>>>[-<<<<<+>>>>>][-]<<<<[-]>>[>>[-]<[->+>+<<]>>[-<<+>>][-]+>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<[-]>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<[-]<<<<<<<<<<<<<<<<++++++++[-]>>>>>>>>>>>>>>>>+>>>]<<[-]>>[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>][-]<[[-]<<<<<<<[-]<<<<<<<<<<<<++++++++[-]>>>>>>>>>>>>+>>>>>>>]<<<<<->-<][-]>[-]>[-]>[-]<<<<<<[->>>>>>+>+<<<<<<<]>>>>>>>[-<<<<<<<+>>>>>>>][-][-]<<<<<<<<<<<<<<<<[->>>>>>>>>>>>>>>>+>+<<<<<<<<<<<<<<<<<]>>>>>>>>>>>>>>>>>[-<<<<<<<<<<<<<<<<<+>>>>>>>>>>>>>>>>>][-]<<<<<<[-]>>>>[>>[-]<[->+>+<<]>>[-<<+>>][-]+>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<[-]>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<[-]<<<<<<<<<<<<<<<<<<<++++++++[-]>>>>>>>>>>>>>>>>>>>+>>>]<<[-]>>[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>][-]<[[-]<<<<<<<<<[-]<<<<<<<<<<<<<++++++++[-]>>>>>>>>>>>>>+>>>>>>>>>]<<<<<->-<][-]>[-]>[-]>+>[-]<<<<<<<<<[->>>>>>>>>+>+<<<<<<<<<<]>>>>>>>>>>[-<<<<<<<<<<+>>>>>>>>>>][-]<[[-]<<<<<<<<<[-]>>>>>>>>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<<<<<<<<[-]<<<<<<<<<<<<++++++++[-]>>>>>>>>>>>>+>>>>>>>>>>]<<[-]>>+>[-]<<<<<<<<<<[->>>>>>>>>>+>+<<<<<<<<<<<]>>>>>>>>>>>[-<<<<<<<<<<<+>>>>>>>>>>>][-]<[[-]<<<<<<<<<<[-]>>>>>>>>>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<<<<<<<<<[-]<<<<<<<<<<<<<++++++++[-]>>>>>>>>>>>>>+>>>>>>>>>>>]<<[-]<<<<<<<<<<<<<<<<<<<[-]>>>>>>>>>>>>>>>>>>>>>[-]<<<<<<<<<<<<[->>>>>>>>>>>>+>+<<<<<<<<<<<<<]>>>>>>>>>>>>>[-<<<<<<<<<<<<<+>>>>>>>>>>>>>][-]<[[-]>[-]<<<<<<<<<<<<[->>>>>>>>>>>>+>+<<<<<<<<<<<<<]>>>>>>>>>>>>>[-<<<<<<<<<<<<<+>>>>>>>>>>>>>][-]<[[-]<<<<<<<<<<<<<<<<<<<<<<[-]<<<++++++++[-]>>>+>>>>>>>>>>>>>>>>>>>>>>]<]<<<<<<<<<<<<[-]>[-]<<[-]<]<<<<<<<<<[-]>>[-<<+>>>>>>>>>>>>>>>>>>>>>>+<<<<<<<<<<<<<<<<<<<<]>>>>>>>>>>>>>>>>>>>>[-<<<<<<<<<<<<<<<<<<<<+>>>>>>>>>>>>>>>>>>>>][-]<<<<<<<<<<<<<<<<[-]<<<<[-]>>>>>>>>>>>>>>>>>>>[-]<<<<<<<<<<<<<<<<<<<<<[->>>>>>>>>>>>>>>>>>>>>+>+<<<<<<<<<<<<<<<<<<<<<<]>>>>>>>>>>>>>>>>>>>>>>[-<<<<<<<<<<<<<<<<<<<<<<+>>>>>>>>>>>>>>>>>>>>>>][-]<[[-]<<<<<<<<<<<<<<<<<<<<<<++++++++[>>>>>>>>>>>>>>>>>>>>>>>+++++++<<<<<<<<<<<<<<<<<<<<<<<-]>>>>>>>>>>>>>>>>>>>>>>>+>[-]<<<<<<<<<<<<<<<<<<<<<<[->>>>>>>>>>>>>>>>>>>>>>+>+<<<<<<<<<<<<<<<<<<<<<<<]>>>>>>>>>>>>>>>>>>>>>>>[-<<<<<<<<<<<<<<<<<<<<<<<+>>>>>>>>>>>>>>>>>>>>>>>][-][-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<<<<<<<<<<<<<<<<<<<<<<<<<[-]>>>>>>>>>>>>>>>>>>>>>>>[>>[-]<[->+>+<<]>>[-<<+>>][-]+>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<[-]>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<[-]<<<<<<<<<<<<<<<<<<<<<<<<<<++++++++[-]>>>>>>>>>>>>>>>>>>>>>>>>>>+>>>]<<[-]>>[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>][-]<[[-]<<<<<<<<<<<<<<<<<<<<<<<<<<<<[-]<++++++++[-]>+>>>>>>>>>>>>>>>>>>>>>>>>>>>>]<<<<<->-<][-]>[-]>[-]<<<[-]>>>+>[-]<<<<<<<<<<<<<<<<<<<<<<<<<<[->>>>>>>>>>>>>>>>>>>>>>>>>>+>+<<<<<<<<<<<<<<<<<<<<<<<<<<<]>>>>>>>>>>>>>>>>>>>>>>>>>>>[-<<<<<<<<<<<<<<<<<<<<<<<<<<<+>>>>>>>>>>>>>>>>>>>>>>>>>>>][-]<[[-]<<<<<<<<<<<<<<<<<<<<<<<<<<[-]>>>>>>>>>>>>>>>>>>>>>>>>>[-]>]>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<<<<<<<<<<<<<<<<<<<<<<<<<<[-]<++++++++[-]>+>>>>>>>>>>>>>>>>>>>>>>>>>>>]<<[-]<<<<]>>>>>>[-]<<<<<<<<<<<<<<<<<<<<<<<<<<<[->>>>>>>>>>>>>>>>>>>>>>>>>>>+>+<<<<<<<<<<<<<<<<<<<<<<<<<<<<]>>>>>>>>>>>>>>>>>>>>>>>>>>>>[-<<<<<<<<<<<<<<<<<<<<<<<<<<<<+>>>>>>>>>>>>>>>>>>>>>>>>>>>>][-]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<++++++++[>>>>>>>>>>>>>>>>>>>>>>>>>>>>++++++<<<<<<<<<<<<<<<<<<<<<<<<<<<<-]>>>>>>>>>>>>>>>>>>>>>>>>>>>>.[-]
```

#### while 语句
输出 `x` 个字符 `'5'`，`x` 范围在 0~9。
```cpp
var x, r('5');
x.input();
x.decrement('0');       // 相当于 x -= '0'
x.while_begin();
    x.decrement();
    r.output();
x.while_end();
```
以上代码描述的 BF 代码如下：
```c
++++++++[>>++++++<<-]>>+++++<,<++++++++[>------<-]>[->.<]
```

#### 基本运算
乘法
```cpp
var a, b, ret;
a.input();
b.input();
a.decrement('0');       // 等价于 a -= '0'
b.decrement('0');       // 等价于 b -= '0'
a.multiply(b, ret);         
// 除法：a.divide(b, ret);
// 加法：a.add(b, ret);
// 减法：a.minus(b, ret);
ret.output_ascii();
```

输入 `x` 输出 `2*x+3`   
```cpp
var x;
x.input();
x -= '0';               // 已经重载
x *= 2;                 // 已经重载
x += 3;                 // 已经重载
x.output_ascii();
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
BF 程序如下：
```
++++++++[>+++++++++++++<-]++++++++[>>++++++++++++<<-]
>>+++++<<++++++++[>>>+++++++++++++<<<-]>>>++++<<<++++
++++[>>>>+++++++++++++<<<<-]>>>>+++++++<<<<++++++++[>
>>>>++++<<<<<-]++++++++[>>>>>>++++++++++++++<<<<<<-]>
>>>>>+++++++<<<<<<++++++++[>>>>>>>++++++++++++++<<<<<
<<-]>>>>>>>++<<<<<<<++++++++[>>>>>>>>++++++++++++<<<<
<<<<-]>>>>>>>>++++<<<<<<<.>.>..>.>.>.<<.>>>.<<<<.>>>>>.
```

方法2：
```cpp
std::string s = "brainfuck\n";
for (char c : s) {
    var a(c);
    a.output();
}
```

#### 排序
>随着功能的增加，我们可以使用此程序生成越来越复杂的 BF 代码。     

输入10个字符，输出排序后的10个字符。     
这里，数组的意义在于批量地实例化 `var` 对象。数组元素不能通过 `var` 的值访问。
```cpp
var L[10];
var flag;
for (int i = 0; i < 10; i++) {
    L[i].input();
}

for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
        L[j].greater(L[j + 1], flag);
        flag.if_begin();
            L[j].swap(L[j + 1]);
        flag.if_end();
    }
}

for (int i = 0; i < 10; i++) {
    L[i].output();
}
```

以上代码描述的 BF 代码如下：
```c
++++++++[>++++++<-]>+++++>,>>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-][-]<<<<[-
>>>>+>+<<<<<]>>>>>[-<<<<<+>>>>>][-]<<<[-]>[>>[-]<[->+>+<<]>>[-<<+>>][-
]+>[-]<<[->>+>+<<<]>>>[-<<<+>>>][-]<[[-]<<[-]>[-]>]>[-]<<[->>+>+<<<]>>
>[-<<<+>>>][-]<[[-]<<<[-]<<<<<<++++++++[-]>>>>>>+>>>]<<[-]>>[-]<<<[->>
>+>+<<<<]>>>>[-<<<<+>>>>][-]<[[-]<<<<<<[-]<<<++++++++[-]>>>+>>>>>>]<<<
<<->-<][-]>[-]>[-]>[-]<<<<[->>>>+>+<<<<<]>>>>>[-<<<<<+>>>>>][-]<<<<<<<
<++++++++[>>>>>>>++++++<<<<<<<-]>>>>>>>.[-]
```

## 结语
由于时间有限，写得比较粗糙。      
最终的效果并不完美。极端情况下，BF 代码过于冗长，但此程序可以保证 BF 代码的正确性。     
若要实现一个 BF 程序，比如高级的排序算法，还是有难度的，需要再封装一些数据结构。      
由于部分的重载运算符函数会增加额外的中间变量，故暂时没有实现（把所有对象都理解为引用，是一个更好的新思路）。     


2022-10-24
