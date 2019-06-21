# javaweb笔记
## 访问tomcat

http://localhost:8080/

## 常见状态码

- 200：一切正常
- 300/301：页面重定向（跳转）
- 404：资源不存在
- 403：权限不足（如果访问a目录，但是a目录设置不可见）
- 500：服务器内部错误（代码有误）
- 其他...

## jsp:在html中嵌套的代码

- 在项目/WEB-INF/web.xml中设置默认的初始页面

```xml
<welcome-file-list>
		<welcome-file>index2.jsp</welcome-file>
</welcome-file-list>
```

## 虚拟路径

### a.第一种方式（需要把tomcat重启）

将web项目配置到webapps以外的目录

conf/server.xml中配置

host标签中

```xml
<Context docBase="" path="/JspProject"  />
```

- docBase：实际路径

- path：虚拟路径（绝对路径、相对路径【相对于webapps】）

### b.第二种方式

在conf\localhost文件夹中新建一个文件，名称为项目名.xml，新增一行即可

```xml
<Context docBase="" path="/JspProject"  />
```

## 虚拟主机

通过www.jd.com访问本机

- conf/server.xml

  ```xml
  <Engine name="Catalina" defaultHost="www.test.com">
      <Host appBase="D:\study\JspProject" name="www.test.com">
          <Context docBase="D:\study\JspProject" path="\"> </Context>
      </Host>
  </Engine>
  ```

- C:\Windows\System32\drivers\etc\host 增加  IP地址  链接

## Jsp的执行流程

![1560351894355](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1560351894355.png)

第一次访问：服务器将jsp翻译成java(servlet)，再将java编译成class文件

第二次访问：直接访问class文件（如果服务端代码修改，将会在访问时重新翻译和编译）

Jsp和Servlet可以相互转换

## 使用Eclipse开发jsp项目

### 关联服务器

- 在Windows下的perference里面搜索Runtime Environment，可以看到关联的服务器版本设置一下即可（设置Apache版本和jre）
- 在面板里面配置（没有项目直接点finish）

### 创建项目

- 创建项目（Dynamic web project），不管servelight版本，配置tomcat版本，点击next，然后选中创建xml文件（必须选中）
- 在WebContent里面的文件是可以直接访问到的，在WenContent里面的WEB-INF目录下的文件是不能通过客户端直接访问到的，原因是权限比较高，只能通过请求转发访问

**注意：并不是任何的内部跳转都能访问到WEB-INF；原因是 跳转有两种方式：请求转发、重定向**

### 有的版本创建后第一行会报错，解决方案为配置tomcat运行环境

- 第一种方法：将tomcat/lib中的servlet-api.jar加入项目中的构建路径
- 第二种方法：右键项目->Build Path->Add Library->Servert Runtime

### 统一字符集编码

- a.编码分类：
  - 设置jsp文件编码（jsp文件中的pageEncoding属性）：jsp->java
  - 设置浏览器读取jsp文件的编码（jsp文件中的Content属性）
  - 一般将上述设置成一样的一致的编码 utf-8
  - 文本编码：将整个eclipse中的文件统一设置
    - 全局设置：在preference中搜索jsp找到Jsp Files，里面的Encoding改成utf-8
    - 设置某一个项目：