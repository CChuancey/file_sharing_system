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

> 接受来自用户的值
>
> **System** 命名空间中的 **Console** 类提供了一个函数 **ReadLine()**，用于接收来自用户的输入，并把它存储到一个变量中。
>
> ```c#
> int num;
> num = Convert.ToInt32(Console.ReadLine());
> ```



## C# 运算符

| 运算符   | 描述                                   | 实例                                                         |
| :------- | :------------------------------------- | :----------------------------------------------------------- |
| typeof() | 返回 class 的类型。                    | typeof(StreamReader);                                        |
| is       | 判断对象是否为某一类型。               | If( Ford is Car) // 检查 Ford 是否是 Car 类的一个对象。      |
| as       | 强制转换，即使转换失败也不会抛出异常。 | Object obj = new StringReader("Hello"); StringReader r = obj as StringReader; |



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























