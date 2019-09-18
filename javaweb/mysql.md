# mysql

## 基础操作

### 1.MySQL连接

在命令行下跳转到mysql的bin目录下，然后输入

~~~cmd
> mysql -u root -p
Enterpassword:******
~~~

### 2.MySQL创建数据库

语法：

```mysql
CREATE DATABASE 数据库名;
```

例子：

```mysql
mysql> create DATABASE RUNOOB;
```

### 3.删除数据库

语法：

```mysql
drop database <数据库名>;
```

例子：

```mysql
mysql> drop database RUNOOB;
```

### 4.选择数据库

语法：

```mysql
use <数据库名>
```

例子：

```mysql
mysql> use RUNOOB;
```

### 5.创建数据表

