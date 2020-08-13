# C

## 关键词
|   auto   |  extern  |  short   |     while      |
| :------: | :------: | :------: | :------------: |
|  break   |  float   |  signed  |    _Alignas    |
|   case   |   for    |  sizeof  |    _Alignof    |
|   char   |   goto   |  static  |    _Atomic     |
|  const   |    if    |  struct  |     _Bool      |
| continue |  inline  |  switch  |    _Complex    |
| default  |   int    | typedef  |    _Generic    |
|    do    |   long   |  union   |   _Imaginary   |
|  double  | register | unsigned |   _Noreturn    |
|   else   | restrict |   void   | _Static_assert |
|   enum   |  return  | volatile | _Thread_local  |


## 头文件

C允许重复声明变量和函数, 所以可以反复包含**只有声明的头文件**.

### 每组.h文件和.c文件独立成模块的情况

* .c文件include与自己同名的.h文件
* .h文件include所有与自己同名的.c文件需要用的头文件
* .h文件中含有.c文件所有需要被调用函数的函数原型
* define位于.c文件中, 这样可以让define只作用于.c文件

### ~~每组.h文件和.c文件依附于包含main的文件的情况~~(不推荐)

* main文件包含了A, B. B也包含了A, main就不需要包含A
* define位于.h文件中, 这样可以让所有包含此头文件的文件都应用此define



## 存储类别(storage class)

* **对象**(object): C语言中的对象是一块存储一个或多个**值**的**内存**.

* **标识符**(identifier): 一个标识符是一个**名称**, 看上去是**一个英文单词**. 标识符可以用来**指定**(designate)特定对象值.

* **左值**: **标识符**或**可以指定对象**的**表达式**.

* **指定**和**指向**: `左值`**指定**`对象`, 而`地址`**指向**`值`. 

    

`对象`包括`对象的值`和`对象的地址`.能指定`对象`的被称作`左值`. `左值`可以是`标识符`或者`表达式`.

 比如`int ar[10]`中**ar不是左值**. 以为以数组方式声明的数组名只有值, 没有自己的地址, 故不是对象.

但`int *pt = ar`中, pt是左值. pt指定了一个对象 , 对象的值是数组ar的首元素地址, 对象的地址为&pt.



## I/O函数

| 函数名    |                           函数原型                           | 参数数 |                    参数                     | 返回值                      | 间断点 | 间断点有效性 |
| --------- | :----------------------------------------------------------: | ------ | :-----------------------------------------: | --------------------------- | ------ | ------------ |
| getc()    |                  int  getc(FILE* 文件指针)                   | 1      |                  文件指针                   | 输入的字符                  |        |              |
| getchar() |                      int getchar(void)                       | 0      |                     无                      | 输入的字符                  |        |              |
| putc()    |             int putc(int 字符,  FILE* 文件指针)              | 2      |                字符 文件指针                | 输出的字符, 遇到错误返回EOF |        |              |
| putchar() |                    int putchar(int 字符)                     | 1      |                    字符                     | 输出的字符                  |        |              |
| fgets()   | char* fgets(char*  字符串指针,int 最大长度, FILE* 文件指针)  | 3      |        字符串指针 最大长度 文件指针         | 遇到文件结尾或错误返回NULL  |        |              |
| gets()    |                                                              |        |                                             |                             |        |              |
| gets_s()  |      char* gets_s(char*  字符串指针, rsize_t 最大长度)       | 2      |             字符串指针 最大长度             |                             |        |              |
| fputs()   |      int fputs(char const*  字符串指针, FILE* 文件指针)      | 2      |             字符串指针 文件指针             |                             |        |              |
| puts()    |              int puts(char const*  字符串指针)               | 1      |                 字符串指针                  |                             |        |              |
| fscanf()  | int fscanf(FILE*  文件指针, char const* 带格式的字符串指针, 格式化输入变量) | 3      | 文件指针 带格式的字符串指针  格式化输入变量 | 成功输入的个数              |        |              |
| scanf()   | int scanf(char const*  const 带格式的字符串指针, 格式化输入变量) | 2      |      带格式的字符串指针 格式化输入变量      | 成功输入的个数              |        |              |
| fprintf() | int fprintf(FILE*  文件指针, char const* const 带格式的字符串指针, 格式化输出变量) | 3      | 文件指针 带格式的字符串指针  格式化输出变量 | 输出的个数                  |        |              |
| printf()  | int printf(char  const* const 带格式的字符串指针, 格式化输出变量) | 2      |      带格式的字符串指针 格式化输出变量      | 输出的个数                  |        |              |

##  gcc编译器
### gcc工作流程

a.c		**源代码**

  ↓	预处理(cpp)	gcc -E	头文件展开, 宏替换, 去注释

a.i		**C文件**

  ↓	编译器(gcc)	gcc -S	编译成汇编语言

a.s		**汇编文件**

  ↓	汇编器(as)	gcc -c	汇编成机器码

a.o		**二进制文件**

  ↓	链接器(ld)	gcc	将函数库中相应代码组合到目标文件中

a.out	**可执行文件**

### **gcc常用参数**

| 参数        | 用途                         |
| ----------- | ---------------------------- |
| -v          | 查看版本                     |
| -o          | 产生目标文件                 |
| -I+目录     | 指定头文件目录               |
| -D          | 编译时定义宏                 |
| -00/-01/-03 | 没有优化/缺省值/优化级别最高 |
| -Wall       | 提示更多警告信息             |
| -c          | 只编译子程序                 |
| -E          | 生成预处理文件               |
| -g          | 包含调试信息                 |

## 各编程语言产生时间

* 1969 – B
* 1970 – Pascal
* 1972 – C
* 1980 – C++
* 1984 – MATLAB
* 1991 – Python
* 1991 – Visual Basic
* 1993 – Ruby
* 1995 – Java
* 1995 – JavaScript
* 2001 – C#
* 2001 – Visual Basic .NET
* 2016 – Kotlin

## 非阻塞输入

在 Windows 系统中，`conio.h`头文件中的`kbhit()`函数就可以用来实现非阻塞式键盘监听。

用户每按下一个键，都会将对应的字符放到输入缓冲区中，kbhit() 函数会检测缓冲区中是否有数据，如果有的话就返回非 0 值，没有的话就返回 0 值。但是 kbhit() 不会读取数据，数据仍然留在缓冲区，所以一般情况下我们还要结合输入函数将缓冲区种的数据读出。

```C
if(kbhit()) //检测缓冲区中是否有数据
ch = getch(); //将缓冲区中的数据以字符的形式读出
```

