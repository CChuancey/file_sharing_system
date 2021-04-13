# 1、基本概念

## .net平台与.net framework

.Net FrameWork框架是.Net平台中不可缺少的一部分，它提供了一个稳定的运行环境来保证我们基于.Net平台开发的各种应用能够正常运.转。.Net FrameWork包括CLR(（Common Language Runtime - CLR）公共语言运行时）和.Net类库等； 

- .net框架  （.Net FrameWork）

  .Net 框架是一个创新的平台，能帮您编写出下面类型的应用程序：

  - Windows 应用程序
  - Web 应用程序
  - Web 服务

## C#程序结构

一个 C# 程序主要包括以下部分：

- 命名空间声明（Namespace declaration）
- 一个 class
- Class 方法
- Class 属性
- 一个 Main 方法
- 语句（Statements）& 表达式（Expressions）
- 注释

> 与 Java 不同的是，文件名可以不同于类的名称。

## 注释

三个`///`可以产生一个摘要

```c#
/// <summary>
/// 说明
/// </summary>
/// <param name="args">参数说明</param>
```

## VS常用快捷键

CTRL+K+D 快速对齐代码

Ctrl+J 快速弹出智能提示

**折叠冗余代码：#Region 和 #endregion** region后面可以不加注释符直接加注释

选中代码 Shift+HOME 、Shift+End

Alt+Shift+F10 导入所需要的命名空间

## 换行符

在Windows中读写**文件**，换行符是`\r\n`



# 2、基础语法

## using 关键字

在任何 C# 程序中的第一条语句都是：

```
using System;
```

**using** 关键字用于在程序中包含命名空间。一个程序可以包含多个 using 语句。

## *class* 关键字

**class** 关键字用于声明一个类。



## 数据类型

> 在 C# 中，变量分为以下几种类型：
>
> - 值类型（Value types）
> - 引用类型（Reference types）
> - 指针类型（Pointer types）

### 值类型

| 类型    | 描述                                 | 范围                                                    | 默认值 |
| :------ | :----------------------------------- | :------------------------------------------------------ | :----- |
| bool    | 布尔值                               | True 或 False                                           | False  |
| byte    | 8 位无符号整数                       | 0 到 255                                                | 0      |
| char    | 16 位 Unicode 字符                   | U +0000 到 U +ffff                                      | '\0'   |
| decimal | 128 位精确的十进制值，28-29 有效位数 | (-7.9 x 1028 到 7.9 x 1028) / 100 到 28                 | 0.0M   |
| double  | 64 位双精度浮点型                    | (+/-)5.0 x 10-324 到 (+/-)1.7 x 10308                   | 0.0D   |
| float   | 32 位单精度浮点型                    | -3.4 x 1038 到 + 3.4 x 1038                             | 0.0F   |
| int     | 32 位有符号整数类型                  | -2,147,483,648 到 2,147,483,647                         | 0      |
| long    | 64 位有符号整数类型                  | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807 | 0L     |
| sbyte   | 8 位有符号整数类型                   | -128 到 127                                             | 0      |
| short   | 16 位有符号整数类型                  | -32,768 到 32,767                                       | 0      |
| uint    | 32 位无符号整数类型                  | 0 到 4,294,967,295                                      | 0      |
| ulong   | 64 位无符号整数类型                  | 0 到 18,446,744,073,709,551,615                         | 0      |
| ushort  | 16 位无符号整数类型                  | 0 到 65,535                                             | 0      |

### 引用类型

> **内置的** 引用类型有：**object**、**dynamic** 和 **string**。

1. Object 类型

   **对象（Object）类型** 是 C# 通用类型系统（Common Type System - CTS）中所有数据类型的终极基类。Object 是 System.Object 类的别名。所以对象（Object）类型可以被分配任何其他类型（值类型、引用类型、预定义类型或用户自定义类型）的值。但是，在分配值之前，需要先进行类型转换。

   当一个值类型转换为对象类型时，则被称为 **装箱**；另一方面，当一个对象类型转换为值类型时，则被称为 **拆箱**。

   ```c#
   object obj;
   obj = 100;   //  装箱
   int x = (int)obj; //  拆箱
   ```

2. dynamic 类型

   自动检查变量的类型

   例如：

   ```c#
   dynamic d = 20;
   d = "12345";
   ```

3. string 类型

   > 字符串（String）类型是 System.String 类的别名。它是从对象（Object）类型派生的。字符串（String）类型的值可以通过两种形式进行分配：引号和 @引号。

   ```c#
   string str = "\\hello";
   
   string str = @"\hello";  //@（称作"逐字字符串"）将转义字符（\）当作普通字符对待
   ```

### 指针类型



## C# 类型转换方法

采用Convert类进行类型转换：

| 序号 | 方法 & 描述                                                  |
| :--- | :----------------------------------------------------------- |
| 1    | **ToBoolean** 如果可能的话，把类型转换为布尔型。             |
| 2    | **ToByte** 把类型转换为字节类型。                            |
| 3    | **ToChar** 如果可能的话，把类型转换为单个 Unicode 字符类型。 |
| 4    | **ToDateTime** 把类型（整数或字符串类型）转换为 日期-时间 结构。 |
| 5    | **ToDecimal** 把浮点型或整数类型转换为十进制类型。           |
| 6    | **ToDouble** 把类型转换为双精度浮点型。                      |
| 7    | **ToInt16** 把类型转换为 16 位整数类型。                     |
| 8    | **ToInt32** 把类型转换为 32 位整数类型。                     |
| 9    | **ToInt64** 把类型转换为 64 位整数类型。                     |
| 10   | **ToSbyte** 把类型转换为有符号字节类型。                     |
| 11   | **ToSingle** 把类型转换为小浮点数类型。                      |
| 12   | **ToString** 把类型转换为字符串类型。                        |
| 13   | **ToType** 把类型转换为指定类型。                            |
| 14   | **ToUInt16** 把类型转换为 16 位无符号整数类型。              |
| 15   | **ToUInt32** 把类型转换为 32 位无符号整数类型。              |
| 16   | **ToUInt64** 把类型转换为 64 位无符号整数类型。              |

```c#
string s = "1123";
double x = Convert.ToDouble(s); //注意异常
```



接受来自用户的值

> **System** 命名空间中的 **Console** 类提供了一个函数 **ReadLine()**，用于接收来自用户的输入，并把它存储到一个变量中。
>
> ```c#
>int num;
> num = Convert.ToInt32(Console.ReadLine());
> ```



## C# 运算符

| 运算符   | 描述                                   | 实例                                                         |
| :------- | :------------------------------------- | :----------------------------------------------------------- |
| typeof() | 返回 class 的类型。                    | typeof(StreamReader);                                        |
| is       | 判断对象是否为某一类型。               | If( Ford is Car) // 检查 Ford 是否是 Car 类的一个对象。      |
| as       | 强制转换，即使转换失败也不会抛出异常。 | Object obj = new StringReader("Hello"); StringReader r = obj as StringReader; |



## 接受用户的输入

```c#
string s = Console.ReadLine(); //用字符串接受用户的输入
```



## `@`符号

1. 取消`\`在字符串中的转义作用
2. 将字符串按原格式输出

## 复制数据类型

### 常量

```c#
const int x = 0x7fffffff;
```

### 枚举

> 用来规范开发过程
>
> 枚举类型默认可以跟int相互转换
>
> 所有的类型都能和string类型相互转换，使用ToString()

```c#
namespace ConsoleApp3
{

    enum Sex
    {
        a = 6,b 
    }
    class Program
    {

        static void Main(string[] args)
        {
            Sex me = Sex.a; 
            Console.WriteLine(me);
            Console.ReadKey();
        }
    }
}
```

使用Parse实现其他类型向enum类型的转换

```c#
string x = "5";
Sex test;
Enum.Parse(typeof(Sex), x);// 需要用到typeof获得枚举类型，反射！！！！！！！！！！
```



## 高级参数

### out参数

在一个方法中返回多个不同类型的值

### ref参数

将方法中的形参和实参都用ref修饰，相当于引用

ref参数要求在方法外必须为其赋值，方法内可以不赋值

### params参数

参数可变长

将实参列表中跟数组元素类型一致的参数当作形参的数组的元素处理

可变长参数必须是函数最后一个参数



## 值类型和引用类型

- 值类型：int、double、char、decimal、struct、enum
- 引用类型：string、自定义类、数组



值类型存储在栈中，引用类型存储在堆中



# 3、面向对象编程

## 封装

- public:任何公有成员可以被外部的类访问。
- private:只有同一个类中的函数可以访问它的私有成员。
- protected:允许子类访问它的基类的成员变量和成员函数
- internal:带有 internal 访问修饰符的任何成员可以被定义在该成员所定义的应用程序内的任何类或方法访问。
- protected internal:允许在本类,派生类或者包含该类的程序集中访问

## C#的可空类型

> 可空类型可以表示其基础值类型正常范围内的值，再加上一个 null 值。
>
> 在处理数据库和其他包含可能未赋值的元素的数据类型时，将 null 赋值给数值类型或布尔型的功能特别有用。例如，数据库中的布尔型字段可以存储值 true 或 false，或者，该字段也可以未定义。

`?` 与`??`

- **?** : 单问号用于对 int,double,bool 等无法直接赋值为 null 的数据类型进行 null 的赋值，意思是这个数据类型是 Nullable 类型的。

  ```c#
  int? i = 3;
  int i;//默认值为0
  int? ii; //默认值为null
  
  int? num1 = null;
  int? num2 = 45;
  double? num3 = new double?();
  double? num4 = 3.1415;
  
  bool? boolval = new bool?();
  ```

- `?？`：双问号 可用于判断一个变量在为 null 时返回一个指定的值

  ```c#
  double? num1 = null;
  double? num2 = 3.1415;
  double num3 = num1 ?? 5.34; //num3不可能为null
  Console.WriteLine(num3); //输出5.34
  Console.WriteLine(num2 ?? 5.34); //输出3.1415
  ```

  > 类似三目运算符 `x==null?y:x` 

## 数组

> 数组是一个引用类型，需要使用 **new** 关键字来创建数组的实例

### 初始化

```c#
double[] balance = new double[10];
double[] balance = { 2340.0, 4523.69, 3421.0};
int [] marks = new int[5]  { 99,  98, 92, 97, 95};
int [] marks = new int[]  { 99,  98, 92, 97, 95};

int [] marks = new int[]  { 99,  98, 92, 97, 95};
int[] score = marks;
```

### 使用for each 循环便利数组

```c#
int[] a = new int[] { 1, 2, 3, 4, 5 };
foreach(int x in a)
{
    Console.WriteLine(x);
}
```

## string 对象

### 创建 String 对象

可以使用以下方法之一来创建 string 对象：

- 通过给 String 变量指定一个字符串
- 通过使用 String 类构造函数 可以传入char数组
- 通过使用字符串串联运算符（ + ）
- 通过检索属性或调用一个返回字符串的方法
- 通过格式化方法来转换一个值或对象为它的字符串表示形式

### string类的方法

| 序号 | 方法名称 & 描述                                              |
| :--- | :----------------------------------------------------------- |
| 1    | **public static int Compare( string strA, string strB )** 比较两个指定的 string 对象，并返回一个表示它们在排列顺序中相对位置的整数。该方法区分大小写。 |
| 2    | **public static int Compare( string strA, string strB, bool ignoreCase )** 比较两个指定的 string 对象，并返回一个表示它们在排列顺序中相对位置的整数。但是，如果布尔参数为真时，该方法不区分大小写。 |
| 3    | **public static string Concat( string str0, string str1 )** 连接两个 string 对象。 |
| 4    | **public static string Concat( string str0, string str1, string str2 )** 连接三个 string 对象。 |
| 5    | **public static string Concat( string str0, string str1, string str2, string str3 )** 连接四个 string 对象。 |
| 6    | **public bool Contains( string value )** 返回一个表示指定 string 对象是否出现在字符串中的值。 |
| 7    | **public static string Copy( string str )** 创建一个与指定字符串具有相同值的新的 String 对象。 |
| 8    | **public void CopyTo( int sourceIndex, char[] destination, int destinationIndex, int count )** 从 string 对象的指定位置开始复制指定数量的字符到 Unicode 字符数组中的指定位置。 |
| 9    | **public bool EndsWith( string value )** 判断 string 对象的结尾是否匹配指定的字符串。 |
| 10   | **public bool Equals( string value )** 判断当前的 string 对象是否与指定的 string 对象具有相同的值。 |
| 11   | **public static bool Equals( string a, string b )** 判断两个指定的 string 对象是否具有相同的值。 |
| 12   | **public static string Format( string format, Object arg0 )** 把指定字符串中一个或多个格式项替换为指定对象的字符串表示形式。 |
| 13   | **public int IndexOf( char value )** 返回指定 Unicode 字符在当前字符串中第一次出现的索引，索引从 0 开始。 |
| 14   | **public int IndexOf( string value )** 返回指定字符串在该实例中第一次出现的索引，索引从 0 开始。 |
| 15   | **public int IndexOf( char value, int startIndex )** 返回指定 Unicode 字符从该字符串中指定字符位置开始搜索第一次出现的索引，索引从 0 开始。 |
| 16   | **public int IndexOf( string value, int startIndex )** 返回指定字符串从该实例中指定字符位置开始搜索第一次出现的索引，索引从 0 开始。 |
| 17   | **public int IndexOfAny( char[] anyOf )** 返回某一个指定的 Unicode 字符数组中任意字符在该实例中第一次出现的索引，索引从 0 开始。 |
| 18   | **public int IndexOfAny( char[] anyOf, int startIndex )** 返回某一个指定的 Unicode 字符数组中任意字符从该实例中指定字符位置开始搜索第一次出现的索引，索引从 0 开始。 |
| 19   | **public string Insert( int startIndex, string value )** 返回一个新的字符串，其中，指定的字符串被插入在当前 string 对象的指定索引位置。 |
| 20   | **public static bool IsNullOrEmpty( string value )** 指示指定的字符串是否为 null 或者是否为一个空的字符串。 |
| 21   | **public static string Join( string separator, string[] value )** 连接一个字符串数组中的所有元素，使用指定的分隔符分隔每个元素。 |
| 22   | **public static string Join( string separator, string[] value, int startIndex, int count )** 连接接一个字符串数组中的指定位置开始的指定元素，使用指定的分隔符分隔每个元素。 |
| 23   | **public int LastIndexOf( char value )** 返回指定 Unicode 字符在当前 string 对象中最后一次出现的索引位置，索引从 0 开始。 |
| 24   | **public int LastIndexOf( string value )** 返回指定字符串在当前 string 对象中最后一次出现的索引位置，索引从 0 开始。 |
| 25   | **public string Remove( int startIndex )** 移除当前实例中的所有字符，从指定位置开始，一直到最后一个位置为止，并返回字符串。 |
| 26   | **public string Remove( int startIndex, int count )** 从当前字符串的指定位置开始移除指定数量的字符，并返回字符串。 |
| 27   | **public string Replace( char oldChar, char newChar )** 把当前 string 对象中，所有指定的 Unicode 字符替换为另一个指定的 Unicode 字符，并返回新的字符串。 |
| 28   | **public string Replace( string oldValue, string newValue )** 把当前 string 对象中，所有指定的字符串替换为另一个指定的字符串，并返回新的字符串。 |
| 29   | **public string[] Split( params char[] separator )** 返回一个字符串数组，包含当前的 string 对象中的子字符串，子字符串是使用指定的 Unicode 字符数组中的元素进行分隔的。 |
| 30   | **public string[] Split( char[] separator, int count )** 返回一个字符串数组，包含当前的 string 对象中的子字符串，子字符串是使用指定的 Unicode 字符数组中的元素进行分隔的。int 参数指定要返回的子字符串的最大数目。 |
| 31   | **public bool StartsWith( string value )** 判断字符串实例的开头是否匹配指定的字符串。 |
| 32   | **public char[] ToCharArray()** 返回一个带有当前 string 对象中所有字符的 Unicode 字符数组。 |
| 33   | **public char[] ToCharArray( int startIndex, int length )** 返回一个带有当前 string 对象中所有字符的 Unicode 字符数组，从指定的索引开始，直到指定的长度为止。 |
| 34   | **public string ToLower()** 把字符串转换为小写并返回。       |
| 35   | **public string ToUpper()** 把字符串转换为大写并返回。       |
| 36   | **public string Trim()** 移除当前 String 对象中的所有前导空白字符和后置空白字符。 |



## 结构体

C#结构体与C++的不同

- 结构可带有方法、字段、索引、属性、运算符方法和事件。
- 结构可定义构造函数，但不能定义析构函数。但是，您不能为结构定义无参构造函数。无参构造函数(默认)是自动定义的，且不能被改变。
- 与类不同，结构不能继承其他的结构或类。
- 结构不能作为其他结构或类的基础结构。
- 结构可实现一个或多个接口。
- 结构成员不能指定为 abstract、virtual 或 protected。
- 当您使用 **New** 操作符创建一个结构对象时，会调用适当的构造函数来创建结构。与类不同，结构可以不使用 New 操作符即可被实例化。
- 如果不使用 New 操作符，只有在所有的字段都被初始化之后，字段才被赋值，对象才被使用。



## 类

> - 类的默认访问标识符是 **internal**，成员的默认访问标识符是 **private**。
> - 构造函数要声明为 **public**，名称与类的名称完全相同，它没有任何返回类型。
> - 析构函数的名称是在类的名称前加上一个波浪形（~）作为前缀，它不返回值，也不带任何参数。
> - 静态成员：关键字 **static** 意味着类中只有一个该成员的实例。

### 属性和字段

属性的作用就是保护字段、对字段的赋值和取值进行预定

属性的本质就是两个方法 get和set

```c#
// vs快捷键生成： 光标放在字段变量名上，Ctrl+R，放开R，按e，自动生成
class Person
{
    private string _name;
    private string _age;
    private string _sex;

    public string Name
    {
        get { return _name; } //也可以对返回值进行限定
        set {
            if (value.Length==0)
            {
                value = "未定义";
            }
            this._name = value; 
        }
    }
}
```

### 构造函数

注意this的用法

```c#
class Program
{
    class Person
    {
        private string _name;
        private string _age;
        private string _sex;

        public string Age { get => _age; set => _age = value; }
        public string Name { get => _name; set => _name = value; }
        public string Sex { get => _sex; set => _sex = value; }

        public Person()
        {

        }

        public Person(string name)
        {
            this.Name = name;
        }

        public Person(string name,string sex):this(name)
        {
            this.Sex = sex;
        }
        public Person(string name,string sex,string age):this(name,sex)
        {
            this.Age = age;
        }
    }
```

对于继承的类，子类会自动调用父类的 **无参构造函数**,但是 如果父类中有有参的构造函数，那无参构造函数会被干掉。

解决方法：

- 在父类中显式的声明无参构造函数
- 子类中用`base`关键字显式的调用父类的构造函数

```c#
class Person
{
    private string _name;
    private string _age;
    private string _sex;

    public string Age { get => _age; set => _age = value; }
    public string Name { get => _name; set => _name = value; }
    public string Sex { get => _sex; set => _sex = value; }

    public Person()
    {

    }

    public Person(string name)
    {
        this.Name = name;
    }

    public Person(string name,string sex):this(name)
    {
        this.Sex = sex;
    }
    public Person(string name,string sex,string age):this(name,sex)
    {
        this.Age = age;
    }
}

class Student:Person
{
    public Student()
    {

    }
    public Student(string name, string age, string sex) :
        base(name, age, sex) //base调用父类的构造函数
    {

     }
}
```



### 继承

- 定义

  ```c#
  <访问修饰符符> class <基类>
  {
   ...
  }
  class <派生类> : <基类>
  {
   ...
  }
  ```

- 初始化

  ```c#
  using System;
  namespace RectangleApplication
  {
     class Rectangle
     {
        // 成员变量
        protected double length;
        protected double width;
        public Rectangle(double l, double w)
        {
           length = l;
           width = w;
        }
        public double GetArea()
        {
           return length * width;
        }
        public void Display()
        {
           Console.WriteLine("长度： {0}", length);
           Console.WriteLine("宽度： {0}", width);
           Console.WriteLine("面积： {0}", GetArea());
        }
     }//end class Rectangle  
     class Tabletop : Rectangle
     {
        private double cost;
        public Tabletop(double l, double w) : base(l, w)
        { }
        public double GetCost()
        {
           double cost;
           cost = GetArea() * 70;
           return cost;
        }
        public void Display()
        {
           base.Display();
           Console.WriteLine("成本： {0}", GetCost());
        }
     }
     class ExecuteRectangle
     {
        static void Main(string[] args)
        {
           Tabletop t = new Tabletop(4.5, 7.5);
           t.Display();
           Console.ReadLine();
        }
     }
  }
  ```

- 多重继承

  与Java类似，C#不支持多重继承，但可以同时实现多个接口



### 多态

多态性可以是静态的或动态的。在**静态多态性**中，函数的响应是在编译时发生的。在**动态多态性**中，函数的响应是在运行时发生的。

在 C# 中，每个类型都是多态的，因为包括用户定义类型在内的所有类型都继承自 Object。

#### 静态多态性

- 函数重载

- 运算符重载

  ```c#
  public static Box operator+ (Box b, Box c)
  {
     Box box = new Box();
     box.length = b.length + c.length;
     box.breadth = b.breadth + c.breadth;
     box.height = b.height + c.height;
     return box;
  }
  ```

  

#### 动态多态性

- C# 允许您使用关键字 **abstract** 创建抽象类，用于提供接口的部分类的实现。当一个派生类继承自该抽象类时，实现即完成。**抽象类**包含抽象方法，抽象方法可被派生类实现。派生类具有更专业的功能。

- 通过在类定义前面放置关键字 **sealed**，可以将类声明为**密封类**。当一个类被声明为 **sealed** 时，它不能被继承。**抽象类不能被声明为 sealed。**

```c#
using System;
namespace PolymorphismApplication
{
   abstract class Shape
   {
       abstract public int area();
   }
   class Rectangle:  Shape
   {
      private int length;
      private int width;
      public Rectangle( int a=0, int b=0)
      {
         length = a;
         width = b;
      }
      public override int area ()
      {
         Console.WriteLine("Rectangle 类的面积：");
         return (width * length);
      }
   }

   class RectangleTester
   {
      static void Main(string[] args)
      {
         Rectangle r = new Rectangle(10, 7);
         double a = r.area();
         Console.WriteLine("面积： {0}",a);
         Console.ReadKey();
      }
   }
}
```

---

虚方法：

当有一个定义在类中的函数需要在继承类中实现时，可以使用**虚方法**。

虚方法可以在不同的继承类中有不同的实现。

对虚方法的调用是在运行时发生的。

动态多态性是通过 **抽象类** 和 **虚方法** 实现的。

```c#
using System;
using System.Collections.Generic;

public class Shape
{
    public int X { get; private set; }
    public int Y { get; private set; }
    public int Height { get; set; }
    public int Width { get; set; }
   
    // 虚方法
    public virtual void Draw()
    {
        Console.WriteLine("执行基类的画图任务");
    }
}

class Circle : Shape
{
    public override void Draw()
    {
        Console.WriteLine("画一个圆形");
        base.Draw();
    }
}
class Rectangle : Shape
{
    public override void Draw()
    {
        Console.WriteLine("画一个长方形");
        base.Draw();
    }
}
class Triangle : Shape
{
    public override void Draw()
    {
        Console.WriteLine("画一个三角形");
        base.Draw();
    }
}

class Program
{
    static void Main(string[] args)
    {
        // 创建一个 List<Shape> 对象，并向该对象添加 Circle、Triangle 和 Rectangle
        var shapes = new List<Shape>
        {
            new Rectangle(),
            new Triangle(),
            new Circle()
        };

        // 使用 foreach 循环对该列表的派生类进行循环访问，并对其中的每个 Shape 对象调用 Draw 方法
        foreach (var shape in shapes)
        {
            shape.Draw();
        }

        Console.WriteLine("按下任意键退出。");
        Console.ReadKey();
    }

}
```

### 接口

> 抽象类在某种程度上与接口类似，但是，它们大多只是用在当只有少数方法由基类声明由派生类实现时。
>
> 接口使得实现接口的类或结构在形式上保持一致。

- 接口的定义

  ```c#
  interface IMyInterface // 默认为public，通常接口命令以 I 字母开头
  {
      void MethodToImplement();
  }
  ```

- 接口的继承

  如果一个接口继承其他接口，那么实现类或结构就需要实现所有接口的成员。

### 里氏转换

1. 子类可以赋值给父类：如果有一个地方需要父类作为参数，可以传一个子类对象
2. 如果父类中装的是子类对象，那么可以将这个父类转换为子类对象（本身是子类对象，被父类引用，可以再转回用子类引用）



### 几个关键字

1. new：还可用于父子类中的成员重名时，两者成员加上new修饰，可以隐藏父类的成员
2. is：表示类型转换，判断能否转换，返回值为bool类型
3. as：表示类型转换，如果能转换则返回对应的对象，否则返回null



## ArryaList 类

> 集合的对象；长度可变，类型不固定

count属性表示集合中实际包含的元素的个数

capacity：表示集合中可以包含的元素的个数；随之集合中的元素个数变大而变大

## HashTable

两个属性

- 键的集合：obj.Keys
- 值的集合：obj.Values



> arraylist与hashtable由于操作类型为object，每次操作都需要拆箱和装箱，浪费时间！！！！

## 泛型集合

```c#
List<int> vs = new List<int>(); //list

Dictionary<int, string> keyValuePairs = new Dictionary<int, string>(); //dictionary
//字典的便利方式
//方式一
foreach (KeyValuePair<int,string> kvp in keyValuePairs)
{
    Console.WriteLine(kvp.Key);
    Console.WriteLine(kvp.Value);
}

//方式二
foreach (int index in keyValuePairs.Keys)
{
    Console.WriteLine(keyValuePairs[index]);
}
```



## 文件类

### Path

```c#
//专门用来操作路径的工具类
string url = @"C:\Program Files\Application Verifier\1.mp3";
Console.WriteLine(Path.GetFileName(url)); //从url得到文件名
Console.WriteLine(Path.GetDirectoryName(url));
Console.WriteLine(Path.GetFileNameWithoutExtension(url));
Console.WriteLine(Path.GetExtension(url));
```

### File

```c#
/**************************   操作文本文件 **************************************/

// 专门用来操作文件的工具类
string url = @"C:\Users\Administrator\Desktop\jdk api 1.8中文\1.mp3";
File.Create(url);

//  文件编码-------------------------------
// 读
string url = @"C:\Users\Administrator\Desktop\1.txt";
byte[] data = File.ReadAllBytes(url); //先读成字节数组
string res = Encoding.UTF8.GetString(data); //编码解析的类：Encoding || 此时getstring为解码，而getbytes为编码，在writebytes的时候就需要先把字符串转成字节数组（getbytes）
Console.WriteLine(res);

//写
string newData = "新加的数据";
byte[] output = Encoding.UTF8.GetBytes(newData);
File.WriteAllBytes(url,output); //写入的是字节数组，写入时会先截断文件
Console.ReadKey();

// 直接指定编码格式读取，只能读文本文件
string[] lines = File.ReadAllLines(url,Encoding.UTF8);
foreach (var line in lines)
{
    Console.WriteLine(line);
}

string[] lines = new string[] { "新写入的第一行", "新写入的第二行" };
File.WriteAllLines(url, lines); //对应的写

// 直接读取文本文件的所有内容
string text = File.ReadAllText(url,Encoding.UTF8);
Console.WriteLine(text);

string text = "新输入的数据";
File.WriteAllText(url, text); //对应的写入


// 以上的写入方式均会截断该文件，可以采用追加的方式写入
File.AppendAllText(url, "hahahah");
```

### 文件流 FileStream

> 两大类
>
> - FileStream ：用来操作字节
> - StreamReader和StreamWriter：用来操作字符
>
> **记得关闭流，释放资源！！！！！**
>
> 也可以将撞见文件流对象的过程写在using中，会自动的释放资源

- FileStream

  ```c#
  
  string url = @"C:\Users\Administrator\Desktop\111.txt";
  FileStream fileStream = new FileStream(url,FileMode.OpenOrCreate,FileAccess.ReadWrite);
  byte[] buffer = new byte[1024 * 1024 * 5];
  
  int r = fileStream.Read(buffer, 0, buffer.Length);
  //string s = Encoding.UTF8.GetString(buffer); //不加修改的直接编码为utf8 会很慢！！ 有5G的缓存
  string s = Encoding.UTF8.GetString(buffer,0,r); //只解码实际的文件大小
  Console.WriteLine(s);
  
  fileStream.Close(); //关闭流
  fileStream.Dispose();//释放流所占用的资源
  
  
  
  /*******************************************************************************/
  //另一种写法
  string url = @"C:\Users\Administrator\Desktop\111.txt";
              
  using (FileStream fileStream = new FileStream(url, FileMode.OpenOrCreate, FileAccess.ReadWrite))
  {
      byte[] buffer = new byte[1024 * 1024 * 5];
  
      int r = fileStream.Read(buffer, 0, buffer.Length);
      string s = Encoding.UTF8.GetString(buffer, 0, r);
      Console.WriteLine(s);
  }
  ```

-  streamreader和streamwriter

  ```c#
  string url = @"C:\Users\Administrator\Desktop\111.txt";
  
  using (StreamReader stream = new StreamReader(url, Encoding.UTF8))
  {
      while (!stream.EndOfStream)
      {
          Console.WriteLine(stream.ReadLine());
      }
  }
  
  using (StreamWriter streamWriter = new StreamWriter(url,true))
  {
      string newMsg = "1234565";
      streamWriter.WriteLine(newMsg);
  }
  ```

  





# 4、特性

## 命名空间

- 定义命名空间

  ```c#
  namespace namespace_name
  {
     // 代码声明
  }
  
  // 命名空间内函数变量的使用
  namespace_name.item_name;
  ```

- using关键字

  **using** 关键字表明程序使用的是给定命名空间中的名称。例如，我们在程序中使用 **System** 命名空间，其中定义了类 Console。我们可以只写：

  ```c#
  Console.WriteLine ("Hello there");
  //我们可以写完全限定名称，如下：
  System.Console.WriteLine("Hello there");
  ```

- 嵌套命名空间

  ```c#
  namespace namespace_name1 
  {
     // 代码声明
     namespace namespace_name2 
     {
       // 代码声明
     }
  }
  ```

## 预处理指令

> 所有的预处理器指令都是以 # 开始。且在一行上，只有空白字符可以出现在预处理器指令之前。预处理器指令不是语句，所以它们不以分号（;）结束。
>
> C# 编译器没有一个单独的预处理器，但是，指令被处理时就像是有一个单独的预处理器一样。在 C# 中，预处理器指令用于在条件编译中起作用。与 C 和 C++ 不同的是，它们不是用来创建宏。一个预处理器指令必须是该行上的唯一指令。

- 预处理指令列表

  | 预处理器指令 | 描述                                                         |
  | :----------- | :----------------------------------------------------------- |
  | #define      | 它用于定义一系列成为符号的字符。                             |
  | #undef       | 它用于取消定义符号。                                         |
  | #if          | 它用于测试符号是否为真。                                     |
  | #else        | 它用于创建复合条件指令，与 #if 一起使用。                    |
  | #elif        | 它用于创建复合条件指令。                                     |
  | #endif       | 指定一个条件指令的结束。                                     |
  | #line        | 它可以让您修改编译器的行数以及（可选地）输出错误和警告的文件名。 |
  | #error       | 它允许从代码的指定位置生成一个错误。                         |
  | #warning     | 它允许从代码的指定位置生成一级警告。                         |
  | #region      | 它可以让您在使用 Visual Studio Code Editor 的大纲特性时，指定一个可展开或折叠的代码块。 |
  | #endregion   | 它标识着 #region 块的结束。                                  |

- #define 预处理器

  \#define 预处理器指令创建符号常量。

  \#define 允许您定义一个符号，这样，通过使用符号作为传递给 #if 指令的表达式，表达式将返回 true。它的语法如下：

  ```c#
  #define symbol
  ```

- 条件指令

  ```c#
  #define DEBUG
  #define VC_V10
  using System;
  public class TestClass
  {
     public static void Main()
     {
  
        #if (DEBUG && !VC_V10)
           Console.WriteLine("DEBUG is defined");
        #elif (!DEBUG && VC_V10)
           Console.WriteLine("VC_V10 is defined");
        #elif (DEBUG && VC_V10)
           Console.WriteLine("DEBUG and VC_V10 are defined");
        #else
           Console.WriteLine("DEBUG and VC_V10 are not defined");
        #endif
        Console.ReadKey();
     }
  }
  
  // 输出结果
  DEBUG and VC_V10 are defined
  ```



## 正则表达式







## 异常处理

异常是在程序执行期间出现的问题。C# 中的异常是对程序运行时出现的特殊情况的一种响应，比如尝试除以零。

异常提供了一种把程序控制权从某个部分转移到另一个部分的方式。C# 异常处理时建立在四个关键词之上的：**try**、**catch**、**finally** 和 **throw**。

- **try**：一个 try 块标识了一个将被激活的特定的异常的代码块。后跟一个或多个 catch 块。
- **catch**：程序通过异常处理程序捕获异常。catch 关键字表示异常的捕获。
- **finally**：finally 块用于执行给定的语句，不管异常是否被抛出都会执行。例如，如果您打开一个文件，不管是否出现异常文件都要被关闭。
- **throw**：当问题出现时，程序抛出一个异常。使用 throw 关键字来完成。

```c#
try
{
   // 引起异常的语句
}
catch( ExceptionName e1 )
{
   // 错误处理代码
}
catch( ExceptionName e2 )
{
   // 错误处理代码
}
catch( ExceptionName eN )
{
   // 错误处理代码
}
finally
{
   // 要执行的语句
}
```

- C#中异常类

  C# 中的异常类主要是直接或间接地派生于 **System.Exception** 类。**System.ApplicationException** 和 **System.SystemException** 类是派生于 System.Exception 类的异常类。

  - **System.ApplicationException** 类支持由应用程序生成的异常。所以程序员定义的异常都应派生自该类。
  - **System.SystemException** 类是所有预定义的系统异常的基类。

  | 异常类                            | 描述                                           |
  | :-------------------------------- | :--------------------------------------------- |
  | System.IO.IOException             | 处理 I/O 错误。                                |
  | System.IndexOutOfRangeException   | 处理当方法指向超出范围的数组索引时生成的错误。 |
  | System.ArrayTypeMismatchException | 处理当数组类型不匹配时生成的错误。             |
  | System.NullReferenceException     | 处理当依从一个空对象时生成的错误。             |
  | System.DivideByZeroException      | 处理当除以零时生成的错误。                     |
  | System.InvalidCastException       | 处理在类型转换期间生成的错误。                 |
  | System.OutOfMemoryException       | 处理空闲内存不足生成的错误。                   |
  | System.StackOverflowException     | 处理栈溢出生成的错误。                         |

- 异常处理

  ```c#
  using System;
  namespace ErrorHandlingApplication
  {
      class DivNumbers
      {
          int result;
          DivNumbers()
          {
              result = 0;
          }
          public void division(int num1, int num2)
          {
              try
              {
                  result = num1 / num2;
              }
              catch (DivideByZeroException e)
              {
                  Console.WriteLine("Exception caught: {0}", e);
              }
              finally
              {
                  Console.WriteLine("Result: {0}", result);
              }
  
          }
          static void Main(string[] args)
          {
              DivNumbers d = new DivNumbers();
              d.division(25, 0);
              Console.ReadKey();
          }
      }
  }
  ```

- 创建用户自定义异常

  ```c#
  using System;
  namespace UserDefinedException
  {
     class TestTemperature
     {
        static void Main(string[] args)
        {
           Temperature temp = new Temperature();
           try
           {
              temp.showTemp();
           }
           catch(TempIsZeroException e)
           {
              Console.WriteLine("TempIsZeroException: {0}", e.Message);
           }
           Console.ReadKey();
        }
     }
  }
  public class TempIsZeroException: ApplicationException
  {
     public TempIsZeroException(string message): base(message) //base和this的用法
     {
     }
  }
  public class Temperature
  {
     int temperature = 0;
     public void showTemp()
     {
        if(temperature == 0)
        {
           throw (new TempIsZeroException("Zero Temperature found"));
        }
        else
        {
           Console.WriteLine("Temperature: {0}", temperature);
        }
     }
  }
  ```

- 抛出对象

  如果异常是直接或间接派生自 **System.Exception** 类，您可以抛出一个对象。您可以在 catch 块中使用 throw 语句来抛出当前的对象，如下所示：

  ```c#
  Catch(Exception e)
  {
     ...
     Throw e
  }
  ```

  

# 5、IO

System.IO 命名空间有各种不同的类，用于执行各种文件操作，如创建和删除文件、读取或写入文件，关闭文件等。

下表列出了一些 System.IO 命名空间中常用的非抽象类：

| I/O 类         | 描述                               |
| :------------- | :--------------------------------- |
| BinaryReader   | 从二进制流读取原始数据。           |
| BinaryWriter   | 以二进制格式写入原始数据。         |
| BufferedStream | 字节流的临时存储。                 |
| Directory      | 有助于操作目录结构。               |
| DirectoryInfo  | 用于对目录执行操作。               |
| DriveInfo      | 提供驱动器的信息。                 |
| File           | 有助于处理文件。                   |
| FileInfo       | 用于对文件执行操作。               |
| FileStream     | 用于文件中任何位置的读写。         |
| MemoryStream   | 用于随机访问存储在内存中的数据流。 |
| Path           | 对路径信息执行操作。               |
| StreamReader   | 用于从字节流中读取字符。           |
| StreamWriter   | 用于向一个流中写入字符。           |
| StringReader   | 用于读取字符串缓冲区。             |
| StringWriter   | 用于写入字符串缓冲区。             |

## FileStream 类

System.IO 命名空间中的 **FileStream** 类有助于文件的读写与关闭。该类派生自抽象类 Stream。

创建一个 FileStream 对象来创建一个新的文件，或打开一个已有的文件。创建 FileStream 对象的语法如下：

```c#
FileStream <object_name> = new FileStream( <file_name>,
				<FileMode Enumerator>, <FileAccess Enumerator>, <FileShare Enumerator>);

//创建一个 FileStream 对象 F 来读取名为 sample.txt 的文件：
FileStream F = new FileStream("sample.txt", FileMode.Open, FileAccess.Read, FileShare.Read);
```

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| FileMode   | **FileMode** 枚举定义了各种打开文件的方法。FileMode 枚举的成员有：**Append**：打开一个已有的文件，并将光标放置在文件的末尾。如果文件不存在，则创建文件。**Create**：创建一个新的文件。如果文件已存在，则删除旧文件，然后创建新文件。**CreateNew**：指定操作系统应创建一个新的文件。如果文件已存在，则抛出异常。**Open**：打开一个已有的文件。如果文件不存在，则抛出异常。**OpenOrCreate**：指定操作系统应打开一个已有的文件。如果文件不存在，则用指定的名称创建一个新的文件打开。**Truncate**：打开一个已有的文件，文件一旦打开，就将被截断为零字节大小。然后我们可以向文件写入全新的数据，但是保留文件的初始创建日期。如果文件不存在，则抛出异常。 |
| FileAccess | **FileAccess** 枚举的成员有：**Read**、**ReadWrite** 和 **Write**。 |
| FileShare  | **FileShare** 枚举的成员有：**Inheritable**：允许文件句柄可由子进程继承。Win32 不直接支持此功能。**None**：谢绝共享当前文件。文件关闭前，打开该文件的任何请求（由此进程或另一进程发出的请求）都将失败。**Read**：允许随后打开文件读取。如果未指定此标志，则文件关闭前，任何打开该文件以进行读取的请求（由此进程或另一进程发出的请求）都将失败。但是，即使指定了此标志，仍可能需要附加权限才能够访问该文件。**ReadWrite**：允许随后打开文件读取或写入。如果未指定此标志，则文件关闭前，任何打开该文件以进行读取或写入的请求（由此进程或另一进程发出）都将失败。但是，即使指定了此标志，仍可能需要附加权限才能够访问该文件。**Write**：允许随后打开文件写入。如果未指定此标志，则文件关闭前，任何打开该文件以进行写入的请求（由此进程或另一进过程发出的请求）都将失败。但是，即使指定了此标志，仍可能需要附加权限才能够访问该文件。**Delete**：允许随后删除文件。 |

## 高级文件操作

| 主题                                                         | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [文本文件的读写](https://www.runoob.com/csharp/csharp-text-files.html) | 它涉及到文本文件的读写。**StreamReader** 和 **StreamWriter** 类有助于完成文本文件的读写。 |
| [二进制文件的读写](https://www.runoob.com/csharp/csharp-binary-files.html) | 它涉及到二进制文件的读写。**BinaryReader** 和 **BinaryWriter** 类有助于完成二进制文件的读写。 |
| [Windows 文件系统的操作](https://www.runoob.com/csharp/csharp-windows-file-system.html) | 它让 C# 程序员能够浏览并定位 Windows 文件和目录。            |

### 文本文件的读写

**StreamReader** 和 **StreamWriter** 类用于文本文件的数据读写。这些类从抽象基类 Stream 继承，Stream 支持文件流的字节读写。

-  **StreamReader 类**

  **StreamReader** 类继承自抽象基类 TextReader，表示阅读器读取一系列字符。

  下表列出了 **StreamReader** 类中一些常用的**方法**：

  | 序号 | 方法 & 描述                                                  |
  | :--- | :----------------------------------------------------------- |
  | 1    | **public override void Close()** 关闭 StreamReader 对象和基础流，并释放任何与读者相关的系统资源。 |
  | 2    | **public override int Peek()** 返回下一个可用的字符，但不使用它。 |
  | 3    | **public override int Read()** 从输入流中读取下一个字符，并把字符位置往前移一个字符。 |

  ```c#
  using System;
  using System.IO;
  
  namespace FileApplication
  {
      class Program
      {
          static void Main(string[] args)
          {
              try
              {
                  // 创建一个 StreamReader 的实例来读取文件 
                  // using 语句也能关闭 StreamReader
                  using (StreamReader sr = new StreamReader("c:/jamaica.txt"))
                  {
                      string line;
                     
                      // 从文件读取并显示行，直到文件的末尾 
                      while ((line = sr.ReadLine()) != null)
                      {
                          Console.WriteLine(line);
                      }
                  }
              }
              catch (Exception e)
              {
                  // 向用户显示出错消息
                  Console.WriteLine("The file could not be read:");
                  Console.WriteLine(e.Message);
              }
              Console.ReadKey();
          }
      }
  }
  ```

- StreamWriter类

  **StreamWriter** 类继承自抽象类 TextWriter，表示编写器写入一系列字符。

  下表列出了 **StreamWriter** 类中一些常用的**方法**：

  | 序号 | 方法 & 描述                                                  |
  | :--- | :----------------------------------------------------------- |
  | 1    | **public override void Close()** 关闭当前的 StreamWriter 对象和基础流。 |
  | 2    | **public override void Flush()** 清理当前编写器的所有缓冲区，使得所有缓冲数据写入基础流。 |
  | 3    | **public virtual void Write(bool value)** 把一个布尔值的文本表示形式写入到文本字符串或流。（继承自 TextWriter。） |
  | 4    | **public override void Write( char value )** 把一个字符写入到流。 |
  | 5    | **public virtual void Write( decimal value )** 把一个十进制值的文本表示形式写入到文本字符串或流。 |
  | 6    | **public virtual void Write( double value )** 把一个 8 字节浮点值的文本表示形式写入到文本字符串或流。 |
  | 7    | **public virtual void Write( int value )** 把一个 4 字节有符号整数的文本表示形式写入到文本字符串或流。 |
  | 8    | **public override void Write( string value )** 把一个字符串写入到流。 |
  | 9    | **public virtual void WriteLine()** 把行结束符写入到文本字符串或流。 |

  ```c#
  using System;
  using System.IO;
  
  namespace FileApplication
  {
      class Program
      {
          static void Main(string[] args)
          {
  
              string[] names = new string[] {"Zara Ali", "Nuha Ali"};
              using (StreamWriter sw = new StreamWriter("names.txt"))
              {
                  foreach (string s in names)
                  {
                      sw.WriteLine(s);
  
                  }
              }
  
              // 从文件中读取并显示每行
              string line = "";
              using (StreamReader sr = new StreamReader("names.txt"))
              {
                  while ((line = sr.ReadLine()) != null)
                  {
                      Console.WriteLine(line);
                  }
              }
              Console.ReadKey();
          }
      }
  }
  ```

### 二进制文件的读写

- BinaryReader类

  **BinaryReader** 类用于从文件读取二进制数据。一个 **BinaryReader** 对象通过向它的构造函数传递 **FileStream** 对象而被创建。

  下表列出了 **BinaryReader** 类中一些常用的**方法**：

  | 序号 | 方法 & 描述                                                  |
  | :--- | :----------------------------------------------------------- |
  | 1    | **public override void Close()** 关闭 BinaryReader 对象和基础流。 |
  | 2    | **public virtual int Read()** 从基础流中读取字符，并把流的当前位置往前移。 |
  | 3    | **public virtual bool ReadBoolean()** 从当前流中读取一个布尔值，并把流的当前位置往前移一个字节。 |
  | 4    | **public virtual byte ReadByte()** 从当前流中读取下一个字节，并把流的当前位置往前移一个字节。 |
  | 5    | **public virtual byte[] ReadBytes( int count )** 从当前流中读取指定数目的字节到一个字节数组中，并把流的当前位置往前移指定数目的字节。 |
  | 6    | **public virtual char ReadChar()** 从当前流中读取下一个字节，并把流的当前位置按照所使用的编码和从流中读取的指定的字符往前移。 |
  | 7    | **public virtual char[] ReadChars( int count )** 从当前流中读取指定数目的字节，在一个字符数组中返回数组，并把流的当前位置按照所使用的编码和从流中读取的指定的字符往前移。 |
  | 8    | **public virtual double ReadDouble()** 从当前流中读取一个 8 字节浮点值，并把流的当前位置往前移八个字节。 |
  | 9    | **public virtual int ReadInt32()** 从当前流中读取一个 4 字节有符号整数，并把流的当前位置往前移四个字节。 |
  | 10   | **public virtual string ReadString()** 从当前流中读取一个字符串。字符串以长度作为前缀，同时编码为一个七位的整数。 |

- BinaryWriter 类

  **BinaryWriter** 类用于向文件写入二进制数据。一个 **BinaryWriter** 对象通过向它的构造函数传递 **FileStream** 对象而被创建。

  下表列出了 **BinaryWriter** 类中一些常用的**方法**：

  | 序号 | 方法 & 描述                                                  |
  | :--- | :----------------------------------------------------------- |
  | 1    | **public override void Close()** 关闭 BinaryWriter 对象和基础流。 |
  | 2    | **public virtual void Flush()** 清理当前编写器的所有缓冲区，使得所有缓冲数据写入基础设备。 |
  | 3    | **public virtual long Seek( int offset, SeekOrigin origin )** 设置当前流内的位置。 |
  | 4    | **public virtual void Write( bool value )** 把一个单字节的布尔值写入到当前流中，0 表示 false，1 表示 true。 |
  | 5    | **public virtual void Write( byte value )** 把一个无符号字节写入到当前流中，并把流的位置往前移一个字节。 |
  | 6    | **public virtual void Write( byte[] buffer )** 把一个字节数组写入到基础流中。 |
  | 7    | **public virtual void Write( char ch )** 把一个 Unicode 字符写入到当前流中，并把流的当前位置按照所使用的编码和要写入到流中的指定的字符往前移。 |
  | 8    | **public virtual void Write( char[] chars )** 把一个字符数组写入到当前流中，并把流的当前位置按照所使用的编码和要写入到流中的指定的字符往前移。 |
  | 9    | **public virtual void Write( double value )** 把一个 8 字节浮点值写入到当前流中，并把流位置往前移八个字节。 |
  | 10   | **public virtual void Write( int value )** 把一个 4 字节有符号整数写入到当前流中，并把流位置往前移四个字节。 |
  | 11   | **public virtual void Write( string value )** 把一个以长度为前缀的字符串写入到 BinaryWriter 的当前编码的流中，并把流的当前位置按照所使用的编码和要写入到流中的指定的字符往前移。 |

```c#
using System;
using System.IO;

namespace BinaryFileApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryWriter bw;
            BinaryReader br;
            int i = 25;
            double d = 3.14157;
            bool b = true;
            string s = "I am happy";
            // 创建文件
            try
            {
                bw = new BinaryWriter(new FileStream("mydata",
                                FileMode.Create));
            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message + "\n Cannot create file.");
                return;
            }
            // 写入文件
            try
            {
                bw.Write(i);
                bw.Write(d);
                bw.Write(b);
                bw.Write(s);
            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message + "\n Cannot write to file.");
                return;
            }

            bw.Close();
            // 读取文件
            try
            {
                br = new BinaryReader(new FileStream("mydata",
                                FileMode.Open));
            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message + "\n Cannot open file.");
                return;
            }
            try
            {
                i = br.ReadInt32();
                Console.WriteLine("Integer data: {0}", i);
                d = br.ReadDouble();
                Console.WriteLine("Double data: {0}", d);
                b = br.ReadBoolean();
                Console.WriteLine("Boolean data: {0}", b);
                s = br.ReadString();
                Console.WriteLine("String data: {0}", s);
            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message + "\n Cannot read from file.");
                return;
            }
            br.Close();
            Console.ReadKey();
        }
    }
}
```



### Windows 文件系统的操作

使用各种目录和文件相关的类来操作目录和文件，比如 **DirectoryInfo** 类和 **FileInfo** 类。

- DirectoryInfo 类

  | 序号 | 属性 & 描述                                             |
  | :--- | :------------------------------------------------------ |
  | 1    | **Attributes** 获取当前文件或目录的属性。               |
  | 2    | **CreationTime** 获取当前文件或目录的创建时间。         |
  | 3    | **Exists** 获取一个表示目录是否存在的布尔值。           |
  | 4    | **Extension** 获取表示文件存在的字符串。                |
  | 5    | **FullName** 获取目录或文件的完整路径。                 |
  | 6    | **LastAccessTime** 获取当前文件或目录最后被访问的时间。 |
  | 7    | **Name** 获取该 DirectoryInfo 实例的名称。              |

  下表列出了 **DirectoryInfo** 类中一些常用的**方法**：

  | 序号 | 方法 & 描述                                                  |
  | :--- | :----------------------------------------------------------- |
  | 1    | **public void Create()** 创建一个目录。                      |
  | 2    | **public DirectoryInfo CreateSubdirectory( string path )** 在指定的路径上创建子目录。指定的路径可以是相对于 DirectoryInfo 类的实例的路径。 |
  | 3    | **public override void Delete()** 如果为空的，则删除该 DirectoryInfo。 |
  | 4    | **public DirectoryInfo[] GetDirectories()** 返回当前目录的子目录。 |
  | 5    | **public FileInfo[] GetFiles()** 从当前目录返回文件列表。    |

- FileInfo 类

  **FileInfo** 类派生自 **FileSystemInfo** 类。它提供了用于创建、复制、删除、移动、打开文件的属性和方法，且有助于 FileStream 对象的创建。该类不能被继承。

  下表列出了 **FileInfo** 类中一些常用的**属性**：

  | 序号 | 属性 & 描述                                       |
  | :--- | :------------------------------------------------ |
  | 1    | **Attributes** 获取当前文件的属性。               |
  | 2    | **CreationTime** 获取当前文件的创建时间。         |
  | 3    | **Directory** 获取文件所属目录的一个实例。        |
  | 4    | **Exists** 获取一个表示文件是否存在的布尔值。     |
  | 5    | **Extension** 获取表示文件存在的字符串。          |
  | 6    | **FullName** 获取文件的完整路径。                 |
  | 7    | **LastAccessTime** 获取当前文件最后被访问的时间。 |
  | 8    | **LastWriteTime** 获取文件最后被写入的时间。      |
  | 9    | **Length** 获取当前文件的大小，以字节为单位。     |
  | 10   | **Name** 获取文件的名称。                         |

  下表列出了 **FileInfo** 类中一些常用的**方法**：

  | 序号 | 方法 & 描述                                                  |
  | :--- | :----------------------------------------------------------- |
  | 1    | **public StreamWriter AppendText()** 创建一个 StreamWriter，追加文本到由 FileInfo 的实例表示的文件中。 |
  | 2    | **public FileStream Create()** 创建一个文件。                |
  | 3    | **public override void Delete()** 永久删除一个文件。         |
  | 4    | **public void MoveTo( string destFileName )** 移动一个指定的文件到一个新的位置，提供选项来指定新的文件名。 |
  | 5    | **public FileStream Open( FileMode mode )** 以指定的模式打开一个文件。 |
  | 6    | **public FileStream Open( FileMode mode, FileAccess access )** 以指定的模式，使用 read、write 或 read/write 访问，来打开一个文件。 |
  | 7    | **public FileStream Open( FileMode mode, FileAccess access, FileShare share )** 以指定的模式，使用 read、write 或 read/write 访问，以及指定的分享选项，来打开一个文件。 |
  | 8    | **public FileStream OpenRead()** 创建一个只读的 FileStream。 |
  | 9    | **public FileStream OpenWrite()** 创建一个只写的 FileStream。 |

```c#
using System;
using System.IO;

namespace WindowsFileApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            // 创建一个 DirectoryInfo 对象
            DirectoryInfo mydir = new DirectoryInfo(@"c:\Windows");

            // 获取目录中的文件以及它们的名称和大小
            FileInfo [] f = mydir.GetFiles();
            foreach (FileInfo file in f)
            {
                Console.WriteLine("File Name: {0} Size: {1}",
                    file.Name, file.Length);
            }
            Console.ReadKey();
        }
    }
}
```

























