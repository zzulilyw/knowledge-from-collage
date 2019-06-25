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

### JSP页面元素：

- a.脚本Scriptlet

  - i.

    ```jsp
    <%
    	//这里放置java代码，定义局部变量，java语句
    	//如下所示：
    	String name = "zhangsan";
    	out.print("hello..."+name);
    %>
    ```

  - ii.

    ```jsp
    <%!
    	//定义全局变量，定义方法，如下所示：
    	public String bookName;
    	public void init(){
        	bookName = "java书";
    	}
    %>
    ```

  - iii.

    ```jsp
    <%=输出表达式%> // 等同于out.print();
    ```

  一般而言，修改web.xml、配置文件、java 需要重启tomcat服务

  但是如果修改Jsp/html/css/js，不需要重启
  
  用out.print和out.println都不会回车，因为最终会转化为html代码，因此要想回车必须写html代码
  
  ```html
  <br/>
  ```
  
  - b.page指令
  
    ~~~html
    <%@ page ....%>
    ~~~
  
    - page:指定的属性
    - laungage:jsp页面使用的脚本语言
    - import:导入类
    - pageEncoding:jsp自身编码，jsp转java
    - contentType:浏览器解析页面编码
  
  - c.注释
  
    - html注释(可以被客户通过浏览器查看源码看见)
  
      ~~~html
      <!-- -->
      ~~~
  
    - java注释
  
      ~~~java
      //
      ~~~
  
    - jsp注释
  
      ~~~jsp
      <%-- --%>
      ~~~
  
  ### jsp内置对象（自带的， 不需要new也能使用的）
  
  - out：输出对象，向客户端输出内容
  
  - request：请求对象，存储**客户端向服务器端发送的请求信息**
  
    request对象的常见方法：
  
    - String[] getParameter(String name):根据请求的字段名key，返回多个字段值value
    - String getParameterValues(String name):根据请求的字段名key，返回字段值value
    - void setCharacterEncoding("编码格式utf-8"):设置请求编码，tomcat8及以后改为utf-8
    - getRequestDispatcher().forward(request, response);：请求转发的跳转页面  A -> B
    - getServerContext():获取项目的ServletContext对象
  
    提交的数据如下（地址栏提交方式）：
  
    ```link
    http://localhost:8080/MyJspTest/show.jsp?uname=123456&upwd=123456&uage=25&uhobbies=%E5%94%B1&uhobbies=%E8%B7%B3&uhobbies=rap&uhobbies=%E7%AF%AE%E7%90%83
    ```
  
    从uname开始之后的都是提交的数据
  
    get提交方式 :
  
    ![1561481272509](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1561481272509.png)
  
    和地址栏提交方式以及超链接方式都属于get方式
  
    get与post请求方式的区别：
  
    - a.get方式在地址栏上显示请求信息（信息有限4-5kb，如果存在大文件就会出错）； post不会
    - b.文件上传操作：必须是post
  
  - response：响应对象
  
    提供方法：
  
    - void addCookie(Cookie cookie) : 服务端向客户端增加cookie对象
    - void sendRedirect(String location) throws IOException: 重定向，页面跳转的一种方式
    - void setContentType(String type):设置服务端相应编码（设置服务端的contentType类型）
    - 
  
  - session
  
  - application
  
  - config
  
  - page
  
  - exception

