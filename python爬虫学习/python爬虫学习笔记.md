## python爬虫学习笔记

### 1.初级爬虫

~~~ python
import urllib #导入包
url = "http://www.baidu.com" #设定访问网址
file = urllib.request.urlopen(url) #访问该网址并将访问到该网址的值赋值给file
print(file.info())
print(file.getcode()) #得到状态码
print(file.geturl()) #得到链接

print(urllib.request.quote("http://www.sina.com.cn")) #将新浪网址编码
#输出为 http%3A//www.sina.com.cn
print(urllib.request.unquote("http%3A//www.sina.com.cn")) #将其反编码
#输出为 http://www.sina.com.cn
~~~

### 2.浏览器的模拟——Headers 属性

~~~python

~~~



~~~python
#模拟百度搜索
#本次代码并没有模拟浏览器访问，在实际访问中一定要加上表头模拟浏览器访问
#req.add_header('Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36')
import urllib.request
url = "http://www.baidu.com/s?wd="
key = input('请输入你要查找的信息\n')
key = urllib.request.quote(key) #将key进行编码转化 防止程序无法识别utf-8
url_all = url + key;
req = urllib.request.Request(url_all)
data = urllib.request.urlopen(req).read()
#fh = open("","wb")
#fh.write(data)
#fh.close()
~~~



### 3.post方法

~~~python
import urllib.request
import urllib.parse
url = "https://www.iqianyue.com/mypost" #书上提供的是http但是经过实际操作发现https才可以实现post
postdata = urllib.parse.urlencode({
    "name":"ceo@iqianyue.com"
    "pass":"aA123456"
}).encode('utf-8')
req = urllib.request.Request(url,postdata)
req.add_header('Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36')
data = urllib.request.urlopen(req).read()
#fhandle = open("","wd")
#fhandle = write(data)
#fhandle.close()
~~~

### 4.超时设置

~~~python
#书上给的例程
import urllib.request
for i in range(1,100):
    try:
        file = urllib.request.urlopen("http://yum.iqianyue.com",timeout = 1)
        data = file.read()
        print(len(data))
    except Exception as e:
        print("出现异常-->"+str(e))
~~~

~~~python
#自己写的
#其实超时算作一种异常，除了这种异常以外还有很多种异常，通常处理异常使用的是try-catch语句
#不需要每次都进行访问，只需要进行一次即可
#只需要在urlopen()方法的参数中加上timeout=?,就可以定义超时时长，超出这个时长系统就自动判定抛出异常了
req = urllib.request.Request(url,postdata)
data = urllib.request.urlopen(req,timeout = 1).read()
~~~

### 5.异常处理

~~~python
#实例1
import urllib.request
import urllib.error
try:
    urllib.request.urlopen("http://blog.csdn.net")
except urllib.error.URLError as e:
    print(e.code)
    print(e.reason)
~~~

在该实例中，我们对网址"http://blog.csdn.net"进行爬取，CSDN博客是禁止对文章进行爬取的，在这里我们未使用模拟浏览器进行爬取，所以必然会出现403的错误，此时会引发except部分，并通过'urllib.error.URLError as e:' 捕获异常信息e，然后进行相应的异常处理。这里的异常处理会输出对应的异常状态和异常原因。

执行该实例后会产生以下效果：

![1557051185664](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1557051185664.png)

一般来说产生URLError的原因有如下几种可能：

- 连接不上服务器
- 远程URL不存在
- 无网络
- 触发了HTTPError

刚刚产生的URLError异常不属于前三种情况，而是由于触发了HTTPError。所以，以上异常处理我们可以直接用HTTPError代替URLError。

接下来我们总结一下常见的状态码及其含义：

- **200 OK 一切正常**
- **301 MOVED Permanently 重定向到临时的URL,永久性**
- **302 Found 重定向到临时的URL，非永久性**
- **304 Not Modified 请求的资源未更新**
- **400 Bad Request 非法请求**
- **401 Unauthorized 请求未经授权**
- **403 Forbidden 禁止访问**
- **404 Not Found 没有找到对应界面**
- **500 Internal Server Error 服务器出现内部错误**
- **501 Not Implemented 服务器不支持实现请求所需要的功能**

~~~python
#实例2
import urllib.request
import urllib.error
try:
    urllib.request.urlopen("http://blog.baiduusss.net")
#先用子类处理，再用父类处理，对照异常编码可以完美解决所有异常
except urllib.error.HTTPError as e:
    print(e.code)
    print(e.reason)
except urllib.error.URLError as e:
    print(e.reason)
~~~



### 6.正则表达式

#### 6.1 原子

​	原子是正则表达式中最基本的组成单位，每个正则表达式中至少要包含一个原子，常见的原子有以下几类：

- 普通字符作为原子

  ~~~python
  #例程
  import re #导入re模块
  pattern = "yue" #普通字符作为原子
  string = "http://yun.iqianyue.com"
  result1 = re.search(pattern, string)
  print(result1)
  ~~~

  运行结果

  ~~~python
  <_sre.SRE_Match object; span=(16, 19), match='yue'>
  ~~~

- 非打印字符作为原子

  ![1557058111057](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1557058111057.png)

  ~~~python
  #例程
  import re
  pattern = "\n"
  string = '''http://yum.iqianyyue.com
  http://baidu.com'''
  result1 = re.search(pattern, string)
  print(result1)
  ~~~

  程序运行结果

  ~~~python
  <_sre.SRE_Match object; span=(24, 25), match='\n'>
  ~~~

  将程序更改为

  ~~~python
  import re
  pattern = "\n"
  string = '''http://yum.iqianyyue.comhttp://baidu.com'''#将换行符删除
  result1 = re.search(pattern, string)
  print(result1)
  ~~~

  程序运行结果

  ~~~python
  None
  ~~~

- 通用字符作为原子

  ![1557058376158](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1557058376158.png)

- 原子表

  ![1557058445235](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1557058445235.png)

  ~~~python
  import re
  pattern1 = "\w|dpython[xyz]\w"
  pattern2 = "\w\dpython[^xyz]\w"
  pattern3 = "\w\dpython[xyz]\W"
  string = "abcdfphp345pythony_py"
  result1 = re.search(pattern1, string)
  result2 = re.search(pattern2, string)
  result3 = re.search(pattern3, string)
  print(result1)
  print(result2)
  print(result3)
  ~~~

  程序执行结果

  ~~~python
  <_sre.SRE_Match object; span=(0, 1), match='a'>
  None
  None
  ~~~

  #### 6.2 元字符

  ![1557058775940](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1557058775940.png)

- 任意匹配字符

  任意匹配元字符"**.**"，我们可以使用"**.**"去匹配**除换行符以外的任意字符**。

  可以输入以下程序：

  ~~~python
  import re
  pattern = ".python..."
  string = "abcdfphp345pythony_py"
  result = re.search(pattern, string)
  print(result)
  ~~~

  运行结果

  ~~~python
  <_sre.SRE_Match object; span=(10, 20), match='5pythony_p'>
  ~~~

- 边界限制元字符

  可以使用 **^** 匹配字符串的开始，使用 **$** 匹配字符串的结束

  ~~~python
  import re
  pattern1 = "^abd" #限制字符串必须以abd开头
  pattern2 = "^abc" #限制字符串必须以abc开头
  pattern3 = "py$" #限制字符串必须以py结尾
  pattern4 = "ay$" #限制字符串必须以ay结尾
  string = "abcdfphp345pythony_py"
  result1 = re.search(pattern1, string)
  result2 = re.search(pattern2, string)
  result3 = re.search(pattern3, string)
  result4 = re.search(pattern4, string)
  print(result1)
  print(result2)
  print(result3)
  print(result4)
  ~~~

  运行结果

  ~~~python
  None
  <_sre.SRE_Match object; span=(0, 3), match='abc'>
  <_sre.SRE_Match object; span=(19, 21), match='py'>
  None
  ~~~

- 限定符

  限定符也是元字符的一种，常见的限定符包括‘*、？、+、{n}、{n,}、{n, m}

  (具体含义参照表格)

  ~~~python
  import re
  pattern1 = "py.*n"
  pattern2 = "cd{2}"
  pattern3 = "cd{3}"
  pattern4 = "cd{2,}"
  string = "abcdddfphp345pythony_py"
  result1 = re.search(pattern1, string)
  result2 = re.search(pattern2, string)
  result3 = re.search(pattern3, string)
  result4 = re.search(pattern4, string)
  print(result1)
  print(result2)
  print(result3)
  print(result4)
  ~~~

  程序执行结果：

  ~~~python
  <_sre.SRE_Match object; span=(13, 19), match='python'>
  <_sre.SRE_Match object; span=(2, 5), match='cdd'>
  <_sre.SRE_Match object; span=(2, 6), match='cddd'>
  <_sre.SRE_Match object; span=(2, 6), match='cddd'>
  ~~~

  ![1557060298152](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1557060298152.png)

- 模式选择符

  讲解模式选择符 **|** ，使用模式选择符可以设置多个模式，匹配时可以从中选择任意一个模式进行匹配。比如正则表达式 **python|php** 中，字符串 **python** 和 **php** 均满足匹配条件。接下来我们通过实例讲解：

  ~~~python
  import re
  pattern = "python|php"
  string = "abcdfphp345pythony_py"
  result1 = re.search(pattern, string)
  print(result1)
  ~~~

  该程序执行结果：

  ~~~python
  <_sre.SRE_Match object; span=(5, 8), match='php'>
  ~~~

- 模式单元符

  模式单元符 **()** ，可以使用 **()** 将一些原子组合成一个大原子使用，小括号括起来的部分会被当作一个整体去使用。

  ~~~python
  import re
  pattern1 = "(cd){1,}"
  pattern2 = "cd{1,}"
  string = "abcdcdcdcdfphp345pythony_py"
  result1 = re.search(pattern1, string)
  result2 = re.search(pattern2, string)
  print(result1)
  print(result2)
  ~~~

  程序执行结果

  ~~~python
  <_sre.SRE_Match object; span=(2, 10), match='cdcdcdcd'>
  <_sre.SRE_Match object; span=(2, 4), match='cd'>
  ~~~

  ![1557061731780](C:\Users\lyw\AppData\Roaming\Typora\typora-user-images\1557061731780.png)

  

