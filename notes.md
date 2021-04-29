# Linux的命令

## bc命令

bc是一个支持大数运算的计算器



## more命令

两种使用方式

```bash
more fileName
command | more # 将别的命令的输出一页一页的看
```



## man命令

搜索man的帮助

```bash
man -k keywords
```



# Linux的快捷键

## Ctrl相关

```bash
Ctrl+c #在命令行下起着终止当前执行程序的作用，

Ctrl+d #相当于exit命令，退出当前shell

Ctrl+s #挂起当前shell（保护作用很明显哦）

Ctrl+q #解冻挂起的shell再不行就重新连接打开一个终端，reboot linux 或 kill 相关进程。

Ctrl+l #清屏
```



# 其他知识

- printf("%m.ns",str);

  %m.ns：输出占m列，但只取字符串中左端n个字符。这n个字符输出在m列的右侧，左补空格。