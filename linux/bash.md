# bash学习笔记

## bash的简介

bash是(Bourne Shell)'sh'的升级版, 这是一个开源的GNU项目,它提供了比bourne shell 更好的功能,适用于编程和交互使用.我们可以这么理解,bash是一个命令处理器,通常运行于文本窗口之中,可以将用户输入的命令解释并执行相应的操作,这样的文件被称作脚本.bash是绝大多数Linux,MAC 及os 默认的Shell 程序,并且Shell Script都大致相同.当您学会一种Shell之后,其他的Shell都能很快上手,而且shell Script 通常在可以在很多Shell上使用,因为此您不必在学习那种Shell的选择上浪费太多时间

### Bash的特点

* Bash与sh兼容,并具有Korn Shell 和 C Shell 的最佳功能特性
* Bash的每个文件都有其特定用途,这些文件集合用于创建环境
* Bash可以通过键位绑定设置自定义的编辑键序列
* Bash包含通过键位绑定设置自定义的编辑键序列
* Bash包含了一维数组,它可以帮助您轻松的引用和操作数据表
* bash的目录堆栈指定了列表中最近访问的目录的历史记录 操作示例:pushed用于将目录添加至堆栈中;popd 用于将目录冲堆栈中删除,dirs 用于显示堆栈中的内容
* bash 包含用于环境的安全受限制模式

### Bash脚本

* bash脚本是用Bash编写的计算机程序,它包含了自定义数量的纯文本文件,用于在Linux系统上自动循环执行重复性命令

### 文件系统及权限

[文件系统的一点介绍](https://blog.csdn.net/lidong576263632/article/details/80793287)
Linux文件系统所有文件都可以被称为目录,这些文件的类别可以分为以下三种:

1. 普通文件
2. 特殊文件
3. 目录文件

ls -l 命令可以被用来列出所有文件和目录

![ls 出来的信息](https://atts.w3cschool.cn/attachments/image/20200616/1592287146504129.png)
代表文件类型及权限，每个文件均以类型开头，接着指定访问权限。以特定字符表示：

1.  
    * 常规文件（-）
    * 特殊档案（c）
    * 命名管道（p）
    * 块设备（b）
    * 套接字（s）
    * 目录（d）
    * 链接（l）

2. 代表存储块的数量。
3. 代表文件的所有者或具有管理权限的超级用户。
4. 代表所有者、超级用户组
5. 代表文件大小
6. 代表文件的最后修改日期（具体到分钟）
7. 代表文件或目录的名称
使用chmod命令可以更改用不同用户类型的文件权限。添加或删除任何用户类型的任何权限的基本形式：

```bash
chmod [class][operator][permission] file_name
chmod [ugoa][+or-][rwx] file_name
```

* class由u（超级用户）,g（用户组）,o（其他用户）,a（所有类型）表示。
* operator（+或-）表示添加或删除权限。
* permission由指示符r（读取）,w（修改）,x（运行）表示

### bash 注释

单行注释 # 
多行注释

```bash
#!/bin/bash
<< BLOCK
This is the basic bash script
This is the basic bash script
BLOCK
echo "Hello World!"
```

```bash
#!/bin/bash
:'
This is the basic bash script
This is the basic bash script
'
echo "Hello World!"
```

### bash 字符串

当您输入的内容为简单的字符串或文本时，单引号和双引号的作用没有任何区别

当您想打印输出一个已定义的变量，则需要使用双引号。这时若使用单引号不会将其视为变量。

```bash
#!/bin/bash
comment="Welcome to W3Cschool!"
echo "$comment"
echo '$comment'
```

执行结果：

```bash
$ ./bash_script.sh
Welcome to W3Cschool!
$comment
```

### bash 命令行参数

在 Bash 中，命令行参数与以下默认参数或特殊变量的引用一同使用。

* $0 ——指定要调用的脚本名称。
* $1-9 ——存储前9个自变量的名称，或可用作自变量的位置。
* $# ——指定传递给脚本的参数总数。
* $* ——将所有命令行参数连接在一起来存储它们。
* $@ ——将参数列表存储为数组。
* $? ——指定当前脚本的进程 ID 。
* $$ ——指定最后一个命令或最近执行过程的推出状态。
* $! ——显示最后一个后台作业的 ID

### bash 用户读入

1.使用read命令从 Bash 脚本中分别读取单个和多个变量。

```bash
#!/bin/bash
echo "Enter the your name: "
read user_name
echo "Your name is $user_name"
echo
echo "Enter your age, phone and email: "
read age phone email
echo "your age is:$age, phone is:$phone, email: $email "
```

2.使用-p PROMPT命令行选项在同一行上输入

```bash
#!/bin/bash
read -p "username:" user_var
echo "The username is: " $user_var
```

3.在静默模式下，使用命令行选项-s,-p来传递用户名并隐藏密码

```bash

#!/bin/bash
read -p "username : " user_var
read -sp "password : " pass_var
echo
echo "username : " $user_var
echo "password : "  $pass_var
```

4.使用-a命令行选项对数组进行多个输入。

```bash
#!/bin/bash
echo "Enter names : "
read -a names
echo "The entered names are : ${names[0]}, ${names[1]}."
```

### bash日期格式化

```bash
date +"%Y-%m-%d %H:%M:%S"
```

### Bash 算术运算

* 双括号的使用

可采用四种大同小异的方法来实现所需的目标运算。

```bash
Num=$((5+3))
echo "Num = $Num
```

```bahs
((Num=5+3))
echo "Num = $Num"
```

```bash
Num1=5
Num2=3
((Num3=Num1+Num2))
echo "Num3 = $Num3"
```

```bash
Num1=5
Num2=3
Num3=((Num1+Num2))
echo "Num3 = $Num3"
```

以上四种方法结果均相同

* 反引号的使用

```bash
echo "Num1=5, Num2=3" echo "Num3 is the value of addition Num3=Num1+Num2" Num1=5 Num2=3 echo "Num3= expr $Num1 + $Num2"
```

结果

```bash
Num1=5,Num2=3
Num3 is the value of addition Num3=Num1+Num2
Num3= 8
```

* let 命令的构建

```bash
Num1=10 Num2=6 Num3=0 echo "W3Cschool" let "Num3 = $(( Num1 + Num2 ))" echo "Num3= $Num3"
```

结果

```bash
W3Cschool
Num3= 16
```

### Bash if语句

基础

```sh
if [ expression ];
then
statements
fi
```

* 结合&&逻辑运算符使用多个条件

```bash
if [ expression_1 ] && [ expression_2 ];
then
statements
fi
```

* || 多个条件

```sh

if [ expression_1 ] || [ expression_2 ];
then
statements
fi
```

* 同时使用&&和||逻辑运算符

```sh
if [[ expression_1 && expression_2 || expression_3 ]];
then
statements
fi
```

if 常用
| 选项  | 描述  | 例子 |
|---|---|---|
| -eq |检查两个数字是否相等|  1 -eq 1 ，返回 true |
| -ne |检查两个数字是否不相等|  1 -ne 2 ，返回 true |
| -gt |检查左边数是否大于右边数|  2 -gt 1 ，返回 true |
| -lt |检查左边数是否小于右边数|  1 -gt 2 ，返回 true |
| -ge |检查左边数是否大于等于右边数|  2 -ge 1 ，返回 true |
| -le |检查左边数是否小于等于右边数|  1 -le 2 ，返回 true |
| ! EXPRESSION|  检查EXPRESSION是否为假。|
| -n STRING|  检查STRING的长度是否大于零。|
| -z STRING|  检查STRING的长度是否为零(即为空)|
| STRING1 == STRING2|  检查STRING1是否等于STRING2。|
| STRING1 != STRING2|  检查STRING1是否不等于STRING2。|
| INTEGER1 -eq INTEGER2|  检查INTEGER1在数值上是否等于INTEGER2。|
| INTEGER1 -gt INTEGER2|  检查INTEGER1在数值上是否大于INTEGER2。|
| INTEGER1 -lt INTEGER2|  检查INTEGER1在数值上是否小于INTEGER2。|
| -d FILE|  检查FILE是否存在并且它是一个目录。|
| -e FILE|  检查FILE是否存在。|
| -r FILE|  检查FILE是否存在，并授予读取权限。|
| -s FILE|  检查FILE是否存在并且其大小大于零(表示它不为空)。|
| -w FILE|  检查FILE是否存在并授予写权限。|
| -x FILE|  检查FILE是否存在并授予执行权限。|

* 嵌套 if 语句

```sh
#!/bin/bash
#Nested if statement


if [ $1 -gt 50 ]
then
  echo "Number is greater than 50."


  if (( $1 % 2 == 0 ))
  then
    echo "and it is an even number."
  fi
fi
```

### Bash if-else语句

if-else 语句同if 用于在代码顺序执行流程的任务中,当判断为true,执行第一组给定的代码语句,当判断为false的时候,执行另一组给定的代码语句

```bash
if [ condition  ];
then 
    <if block commands >
else
    <else block commands>
if
```

示例代码:

```sh
#!/bin/bash
#when the condition is true
if [ 10 -gt 3];
then
    echo '10 is greater than 3.'
else
    echo '10 is not greater than 3.'
fi


# when the condition is false
if[ 3 -gt 10];
then 
    echo '3 is greater than 10.'
else
    echo '3 is  not greater than 10.'
fi
```

结果

```bash
wshg@20:36:48 ~/Desktop $ sh test.sh
10 is greater than 3.
3 is  not greater than 10.
```

* 单行编写
您可以在一行中编写完整的if-else 语句以及命令.需要遵循以下规则
在if 和 else 的语句末尾添加 ';'  
使用空格作为分隔符以此追加其他语句

```bash
#!/bin/bash
read -p 'enter a value:' value
if [ $value -gt 9 ]; then echo 'the value is bigger than 9.';else echo "the value is not greater than 9" ; fi
```

* 嵌套语句
同 if 语句的嵌套一样,if-else 语句也能够嵌套使用,下面是例子

```sh

#!/bin/bash
read -p "Enter a value:" value
if [ $value -gt 9 ];
then
  if [ $value -lt 11 ];
  then
     echo "$value>9, $value<11"
  else
    echo "The value you typed is greater than 9."
  fi
else echo"The value you typed is not greater than 9."
fi
```

### else-if语句

else-if 语句是 if-else 语句的一个补充. else-if 语句中有多个elif,每个elif都有一个布尔表达式.
如果第一个if 判定为 false,则检查第二个if 语句

```sh
if [ condition ];
then <commands>
elif [ condition ];
then <command>
else  <command>
if
```

同if-else 一样 可以使用 && 或者 || 逻辑运算符来连接任意数量的条件

### Bash case语句

case语句通常用于简化具有多种不同条件的复杂条件语句,使得 bash更具有可读性,并易于维护

```sh

case experience in 
    pattern_1)
        statements
        ;;
    pattern_2)
        statements
        ;;
    pattern_3| pattern_4| pattern_5)
    statements
    ;;
    *)
    statement
    ;;
esac
```

case 语句扩展表达式并尝试与每个包含的模式进行匹配。若找到匹配项，将执行与该项连接的语句直至;;结束。
若匹配项成功，case以最后执行的语句的退出状态终止。
若匹配项失败，case的退出状态为零。
若写入了默认的*模式，那么在匹配其他项失败后将执行它。

例子

```sh
echo "which Operation System are you using"
echo "Windows,Android,ChromeOs,Linux,Other?"
read -p 'Type your OS Name:' OS

case $OS in 
    Windows|windows|win|window)
        echo "That's common.You should try something new"
        echo 
        ;;
    Android|android)
        echo "This is my favorits.It has lots of application."
        echo
        ;;
    Chrome|chrome)
        echo "Coll!!! It's for pro user. Amazing choice"
        echo 
        ;;
    Linux|linux)
        echo "You might be serious about security!!"
        echo 
        ;;
    *)
        echo "Sounds interesting. I will try that."
        echo 
        ;;
esac

```

### for循环语句

```sh
for variable in list
do
commands
done

# 或
for (( expression1; expression2; expression3))
do 
command
done
```

例子

```sh
#!/bin/bash
learn="Start learning from W3Cschool.cn"
for learn in $learn
do
echo $learn
done
echo "Thank You."
```

* for 循环读取数组变量

```sh
#!/bin/bash
#Array Declaration 
arr=("Welcom","to","W3Cshool.cn")

for i in "${arr[@]}"
do
echo $i
done
```

* for 循环 — 三表达式

```sh
#!/bin/bash
for ((i=1; i<=10; i++))
do
echo "$i"
done
```

* for 循环 — break语句

```sh
#!/bin/bash
for table in {2..100..2}
do
echo $table
if [ $table == 20 ]; then
break
fi
done
```

* for 循环 — continue语句

```sh
#!/bin/bash
for ((i=1; i<=20; i++));
do
if [[ $i -gt 5 && $i -lt 16 ]];
then
continue
fi
echo $i
done
```

### Bash until循环

与 while 循环相反，until 循环在条件判断为false时，循环执行一组命令。当判断首次为true时，循环才会终止。

```sh
until [ expression ];
do
command1
command2
. . .
. . . .
commandN
done
```

例子

```sh
#!/bin/bash
max=3
a=1
b=0
until [[ $a -gt $max || $b -gt $max ]];
do
echo "a = $a & b = $b."
((a++))
((b++))
done
```

### Bash 查找字符串长度

在某些情况下，您可能需要了解字符串的长度才能对该字符串执行某些操作。由于在 Bash 中没有相关的内置函数，所以需要参考以下几种方法来学习查找字符串的长度

* 方法一
在查找字符串长度的方法中，最简单的是使用#符号

```sh
${#String}
```

例子

```sh
#!/bin/bash
Str="Welcome to W3Cshool.cn"
length=${#Str}
echo "Length of '$Str' is $length"
```

* 方法2

```sh
`expr length "$String"`
```

例子

```sh
#!/bin/bash 
Str="Welcome to W3Cscholl.cn"
length=`expr length "$Str"`
echo "Length of '$Str' is $length"
```

* 方法三
您也可以选择使用expr "$String": ' .*'来查找字符串长度

```sh
expr "$String": ' .*'
```

* 方法四

```sh
#!/bin/bash
Str="Welcome to W3Cscholl.cn"
length=`echo $Str | wc -c`
echo "Length of '$Str' is $length"
```

* 方法五

```sh
#!/bin/bash
Str="Welcome to W3Cscholl.cn"
length=`echo $Str |awk '{print length}'`
echo "Length of '$Str' is $length"
```

### Bash 拆分字符串

在某些情况下，您可能需要先拆分字符串以进行您下一步的操作。由于在 Bash 中不包含类似其他编程语言中的split内置函数，所以需要参考以下几种方法来学习如何拆分字符串

* 内部域分隔符
您可以使用$IFS在 Bash 中将字符串细分。
IFS被称为“内部域分隔符”，是一种 set 变量。
当 bash shell 处理“命令替换”或“参数替换”时，会根据IFS的值来拆解读入的变量，然后对其进行处理。
IFS的默认值为空格符，也可使用\t，\n等值作为分隔符设置给IFS

```sh
#!/bin/bash
read -p "Enter any string separated by space: " str  #读取字符串的值。
IFS=' ' #将空格设置为分隔符。
read -ra strArr <<<"$str" #将字符串读取到数组中，并由 IFS 分配分隔符。
for i in "${strArr[@]}"; #遍历访问数组中的每个元素。
do
echo "$i"
done
```

* readarray 命令

```sh
#!/bin/bash
read -p "Enter any string separated by colon(:) " str #读取字符串的值，并将分隔符设置为 ： 。
readarray -d : -t strArr <<<"$str" #根据设置的分隔符 : 来拆分字符串。
printf "\n"
#遍历打印输出数组中的每一个值
for (( n=0; n < ${#strArr[*]}; n++ ))
do
echo "${strArr[n]}"
done
```

* Trim命令

```sh
#!/bin/bash
str="welcome;to;W3Cschool!" #定界符 ；
arr=($(echo $str | tr ";" "\n"))#将定界符定义给 tr
for i in "${arr[@]}"
do
echo $i
done
```

### Bash 提取子字符串

在 Bash 中可以使用多种方法从字符串中提取子串。子串就是包含在其父字符串中的子字符串

```sh
${variable:offset:length}
```

```sh
#!/bin/bash


echo "String: welcome to W3Cschool."
str="welcome to W3Cschool."
echo "Total characters in a String: ${#str} "
substr="${str:0:10}"
echo "Substring: $substr"
echo "Total characters in Substring: ${#substr} "
```

### Bash 拼接字符串

```sh
str3="${str1}${str2}
```

例子

```sh
#!/bin/bash


str1="welcome to"
str2="tt3Cschool."
str3="${str1}${str2}"
str4="Hello user,${str1}${str2}"
echo $str3
echo $str4
```

* Bash 参数扩展
  * 句法

    ```sh
    ${FOO%suffix}   删除后缀
    ${FOO#prefix}   删除前缀
    ${FOO%%suffix}  去除长后缀
    ${FOO##prefix}  删除长前缀
    ${FOO/from/to}  替换第一场比赛
    ${FOO//from/to} 全部替换
    ${FOO/%from/to} 替换后缀
    ${FOO/#from/to} 替换前缀
    ```

  * 子串

    ```sh
    ${FOO:0:3}  子串（位置，长度）
    ${FOO:(-3):3}   右边的子串
    ```

  * 长度

    ```sh
    ${#FOO} 的长度 $FOO
    ```

  * 默认值

    ```sh
    ${FOO:-val} $FOO, 或者val如果未设置
    ${FOO:=val} 如果未设置$FOO，val则设置为
    ${FOO:+val} val如果$FOO设置
    ${FOO:?message} 如果$FOO未设置，则显示消息并退出
    ```

### Bash 函数

函数可以有效减少您重复编写程序段的工作量，可随时重复调用

1. 

```sh
function_name() {
commands
}
```

2. 

```sh
function function_name() {
commands
}
```

3. 两种格式的单行压缩，请仔细对照。

```sh
function_name() {commands;}
function function_name() {commands;}
```

例子

```sh
#!/bin/bash
W3Cschool(){
 echo "Welcome to W3Cschool"
}
W3Cschool
```

* 变量作用域
在 Bash 中，在默认情况下所有变量都定义为全局变量，即使在函数内部声明也是如此
您可以使用local关键字在函数内部声明局部变量，该变量只能够在该函数内部使用。同其他编程语言一样，这意味着您可以声明相同名称的全局变量。

```sh
#!/bin/bash
str1="abc"
str2="bcd"
fun(){
    local str1="123"
    str2="234"
    echo "Inside function:str1_value is ${str1},str2_value is ${str2}."
}
echo "Before executing function:str1_value is ${str1},str2_value is ${str2}."
fun
echo "After executing function:str1_value is ${str1},str2_value is ${str2}."
```

* 返回值
在 Bash 函数中，其返回值是执行的最后一个语句的状态。1-255（十进制）范围内表示失败，除此之外表示成功

1. 您可以使用return语句指定返回状态，并将其分配给$?。该语句会终止函数的调用。如下所示

```sh
#!/bin/bash


fun(){
    echo "result"
    return 66
}


fun
echo $?
```

* 参数传递

若您想要将任意数量的参数传递给 Bash 函数，只需要将它们放在调用的函数名后面，以空格分隔，以" "将参数转义。

```sh
#!/bin/bash
fun(){
    echo "Welcome to $1"
}
fun "W3Cschool"
```

### Bash 数组

1. 索引数组
使用declare加-a选项，将变量来声明数组，语法如下

```sh
#声明数组
declare -a Array_Name
#创建数组元素
Array_Name[index_1]=value_1
Array_Name[index_2]=value_2
#或
Array_Name=(
    [index_1]=value_1
    [index_2]=value_2
)
```

2. 关联数组

使用declare加-A选项来声明数组，语法如下

```sh
#声明数组
declare -A Array_Name
#创建数组元素
Array_Name[index_1]=value_1
Array_Name[index_2]=value_2
#或
Array_Name=(
    [index_1]=value_1
    [index_2]=value_2
)
```

3. 数组初始化

```sh
 Array_Name=(element_1 element_2 element_3)
```

4. 打印数组

```sh
declare -p Array_Name
```

* 数组运算

1. 访问元素

```sh
  ${Array_Name[index]}
```

```sh
#!/bin/bash
declare -a arr=("welcome" "to" "W3Cschool")
echo "@"
for i in "${arr[@]}"
do
echo "$i"
done
echo "*"
for i in "${arr[*]}"
do
echo "$i"
done
```