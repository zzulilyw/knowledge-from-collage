# tomcat笔记
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

