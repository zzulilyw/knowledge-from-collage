<div class="show-content-free">
            <p>Hash表也称散列表，也有直接译作哈希表，Hash表是一种特殊的数据结构，它同数组、链表以及二叉排序树等相比较有很明显的区别，它能够快速定位到想要查找的记录，而不是与表中存在的记录的关键字进行比较来进行查找。这个源于Hash表设计的特殊性，它采用了函数映射的思想将记录的存储位置与记录的关键字关联起来，从而能够很快速地进行查找。</p>
<h1>零、Hash表的设计思想</h1>
<p>对于一般的线性表，比如链表，如果要存储联系人信息：</p>
<pre class="hljs undefined"><code>张三 13980593357
李四 15828662334
王五 13409821234
张帅 13890583472
</code></pre>
<p>那么可能会设计一个结构体包含姓名，手机号码这些信息，然后把4个联系人的信息存到一张链表中。当要查找”李四 15828662334“这条记录是否在这张链表中或者想要得到李四的手机号码时，可能会从链表的头结点开始遍历，依次将每个结点中的姓名同”李四“进行比较，直到查找成功或者失败为止，这种做法的时间复杂度为O(n)。即使采用二叉排序树进行存储，也最多为O(logn)。假设能够通过”李四“这个信息直接获取到该记录在表中的存储位置，就能省掉中间关键字比较的这个环节，复杂度直接降到O(1)。Hash表就能够达到这样的效果。</p>
<p>Hash表采用一个映射函数 f :key —&gt; address 将关键字映射到该记录在表中的存储位置，从而在想要查找该记录时，可以直接根据关键字和映射关系计算出该记录在表中的存储位置，通常情况下，这种映射关系称作为Hash函数，而通过Hash函数和关键字计算出来的存储位置(注意这里的存储位置只是表中的存储位置，并不是实际的物理地址)称作为Hash地址。比如上述例子中，假如联系人信息采用Hash表存储，则当想要找到“李四”的信息时，直接根据“李四”和Hash函数计算出Hash地址即可。下面讨论一下Hash表设计中的几个关键问题。</p>
<h1>一、Hash函数的设计</h1>
<p>Hash函数设计的好坏直接影响到对Hash表的操作效率。下面举例说明：</p>
<p>假如对上述的联系人信息进行存储时，采用的Hash函数为：姓名的每个字的拼音开头大写字母的ASCII码之和。</p>
<pre class="hljs undefined"><code>　　    address(张三)=ASCII(Z)+ASCII(S)=90+83=173;
　　　　address(李四)=ASCII(L)+ASCII(S)=76+83=159;
　　　　address(王五)=ASCII(W)+ASCII(W)=87+87=174;
　　　　address(张帅)=ASCII(Z)+ASCII(S)=90+83=173;
</code></pre>
<p>假如只有这4个联系人信息需要进行存储，这个Hash函数设计的很糟糕。</p>
<p>首先，它浪费了大量的存储空间。因为假如采用char型数组存储联系人信息的话，每个人的信息需要12个字节来存储。<br>
（手机号为11位，数值上为100多亿，<code>2^64 =1.844674407371 * 10^19，2^32 = 4294967296</code>，所以需要64位也就是8个字节来存储手机号。<br>
每个汉字占两个字节，两个汉字占四个字节。<br>
所以总共需要8 + 4 = 12Byte）<br>
这样的话，至少需要开辟174*12字节的空间。然而空间利用率只有4/174，不到3%。</p>
<p>另外，根据Hash函数计算结果之后，address(张三)和address(张帅)具有相同的地址，这种现象称作冲突，对于174个存储空间中只需要存储4条记录就发生了冲突，这样的Hash函数设计是很不合理的。所以在构造Hash函数时应尽量考虑关键字的分布特点来设计函数使得Hash地址随机均匀地分布在整个地址空间当中。</p>
<p>通常有以下几种构造Hash函数的方法：</p>
<p>1 直接定址法<br>
　　取关键字或者关键字的某个线性函数为Hash地址，即address(key)=a*key+b;如知道学生的学号从2000开始，最大为4000，则可以将address(key)=key-2000作为Hash地址。</p>
<p>2 平方取中法<br>
　　对关键字进行平方运算，然后取结果的中间几位作为Hash地址。假如有以下关键字序列{421，423，436}，平方之后的结果为{177241，178929，190096}，那么可以取中间的两位数{72，89，00}作为Hash地址。</p>
<p>3 折叠法<br>
　　将关键字拆分成几部分，然后将这几部分组合在一起，以特定的方式进行转化形成Hash地址。假如知道图书的ISBN号为8903-241-23，可以将address(key)=89+03+24+12+3作为Hash地址。</p>
<p>4 除留取余法<br>
　　如果知道Hash表的最大长度为m，可以取不大于m的最大质数p，然后对关键字进行取余运算，address(key)=key%p。</p>
<p>在这里p的选取非常关键，p选择的好的话，能够最大程度地减少冲突，p一般取不大于m的最大质数。</p>
<h1>二、Hash表大小的确定</h1>
<p>Hash表大小的确定也非常关键，如果Hash表的空间远远大于最后实际存储的记录个数，则造成了很大的空间浪费，如果选取小了的话，则容易造成冲突。在实际情况中，一般需要根据最终记录存储个数和关键字的分布特点来确定Hash表的大小。还有一种情况时可能事先不知道最终需要存储的记录个数，则需要动态维护Hash表的容量，此时可能需要重新计算Hash地址。</p>
<h1>三、冲突的解决</h1>
<p>在上述例子中，发生了冲突现象，因此需要办法来解决，否则记录无法进行正确的存储。通常情况下有2种解决办法：</p>
<p>1 开放定址法<br>
　　即当一个关键字和另一个关键字发生冲突时，使用某种探测技术在Hash表中形成一个探测序列，然后沿着这个探测序列依次查找下去，当碰到一个空的单元时，则插入其中。比较常用的探测方法有线性探测法，比如有一组关键字{12，13，25，23，38，34，6，84，91}，Hash表长为14，Hash函数为address(key)=key%11，当插入12，13，25时可以直接插入，而当插入23时，地址1被占用了，因此沿着地址1依次往下探测(探测步长可以根据情况而定)，直到探测到地址4，发现为空，则将23插入其中。</p>
<p>2 链地址法<br>
　　采用数组和链表相结合的办法，将Hash地址相同的记录存储在一张线性表中，而每张表的表头的序号即为计算得到的Hash地址。如上述例子中，采用链地址法形成的Hash表存储表示为：</p>
<div class="image-package">
<div class="image-container" style="max-width: 579px; max-height: 530px;">
<div class="image-container-fill" style="padding-bottom: 91.53999999999999%;"></div>
<div class="image-view" data-width="579" data-height="530"><img data-original-src="//https://upload-images.jianshu.io/upload_images/6946981-697dd755189f9d65.jpg" data-original-width="579" data-original-height="530" data-original-format="" data-original-filesize="28818" style="cursor: zoom-in;" class="image-loading"></div>
</div>
<div class="image-caption">hash.jpg</div>
</div>
<p>虽然能够采用一些办法去减少冲突，但是冲突是无法完全避免的。因此需要根据实际情况选取解决冲突的办法。</p>
<h1>四、Hash表的平均查找长度</h1>
<p>Hash表的平均查找长度包括查找成功时的平均查找长度和查找失败时的平均查找长度。<br>
　　查找成功时的平均查找长度=表中每个元素查找成功时的比较次数之和/表中元素个数；<br>
查找不成功时的平均查找长度相当于在表中查找元素不成功时的平均比较次数，可以理解为向表中插入某个元素，该元素在每个位置都有可能，然后计算出在每个位置能够插入时需要比较的次数，再除以表长即为查找不成功时的平均查找长度。</p>
<p>下面的例子有助于理解。</p>
<h3>例1</h3>
<p>将关键字序列{7, 8, 30, 11, 18, 9, 14}散列存储到散列表中。散列表的存储空间是一个下标从0开始的一维数组，长度为10，即{0, 1,2, 3, 4, 5, 6, 7, 8, 9}。散列函数为： H(key) = (key * 3) % 7，处理冲突采用线性探测再散列法。</p>
<p>求等概率情况下查找成功和查找不成功的平均查找长度。</p>
<p>解：</p>
<h4>1 求散列表</h4>
<pre class="hljs undefined"><code>H(7) = (7 * 3) % 7 = 0
H(8) = (8 * 3) % 7 = 3
H(30) = 6
H(11) = 5
H(18) = 5
H(9) = 6
H(14) = 0
</code></pre>
<p>按关键字序列顺序依次向哈希表中填入，发生冲突后按照“线性探测”探测到第一个空位置填入。<br>
H(7) = 0，key = 7应插在第0个位置，因为第0个位置为空，可以直接插入。<br>
H(8) = 3，key = 8应插在第3个位置，因为第3个位置为空，可以直接插入。<br>
H(30) = 6，key = 30应插在第6个位置，因为第6个位置为空，可以直接插入。<br>
H(11) = 5，key = 11应插在第5个位置，因为第5个位置为空，可以直接插入。<br>
H(18) = 5，key = 18应插在第5个位置，但是第5个位置已经被key=11占据了，所以往后挪一位到第6个位置，但是第6个位置被key=30占据了，再往后挪一位到第7个位置，这个位置是空的，所以key=18就插到这个位置<br>
H(9) = 6，key = 9应插在第6个位置，但是第6个位置已经被key = 30占据，所以需要往后挪一位到第7个位置，但是第7个位置已经被key = 18占据，所以再往后挪移到第8个位置，这个位置是空的，所以key = 9就插到这个位置。<br>
H(14) = 0，key = 14应插在第0个位置，但第0个位置已被key=7占据，所以往后挪移一位到第1个位置，这个位置是空的，所以key=14就插到这个位置。</p>
<p>最终的插入结果如下表所示：</p>
<table>
<thead>
<tr>
<th>address</th>
<th>0</th>
<th>1</th>
<th>2</th>
<th>3</th>
<th>4</th>
<th>5</th>
<th>6</th>
<th>7</th>
<th>8</th>
<th>9</th>
</tr>
</thead>
<tbody>
<tr>
<td>key</td>
<td>7</td>
<td>14</td>
<td></td>
<td>8</td>
<td></td>
<td>11</td>
<td>30</td>
<td>18</td>
<td>9</td>
<td></td>
</tr>
</tbody>
</table>
<h4>2 求查找成功的平均查找长度</h4>
<p>查找7，H(7) = 0，在0的位置，一下子就找到了7，查找长度为1。<br>
查找8，H(8) = 3，在3的位置，一下子就找到了8，查找长度为1。<br>
查找30，H(30) = 6，在6的位置，一下子就找到了30，查找长度为1。<br>
查找11，H(11) = 5，在5的位置，一下子就找到了11，查找长度为1。<br>
查找18，H(18) = 5，第一次在5的位置没有找到18，第二次往后挪移一位到6的位置，仍没有找到，第三次再往后挪移一位到7的位置，找到了，查找长度为3。<br>
查找9，H(9) = 6，第一次在6的位置没找到9，第二次往后挪移一位到7的位置，仍没有找到，第三次再往后挪移一位到8的位置，找到了，查找长度为3.<br>
查找14，H(14) = 0，第一次在0的位置没找到14，第二次往后挪移一位到1的位置，找到了，查找长度为2。</p>
<p>所以，查找成功的平均查找长度为(1 + 1 + 1 + 1 + 3 + 3 + 2) / 7 = 12 / 7。</p>
<h4>3 求查找不成功的平均查找长度</h4>
<p>查找不成功，说明要查找的数字肯定不在上述的散列表中。<br>
因为这里哈希函数的模为7，所以要查找的数的初始地址只可能位于0~6的位置上。<br>
地址0，到第一个关键字为空的地址2需要比较3次，因此查找不成功的次数为3。比如要查找的数为28，H(28) = (28 * 3) % 7 = 0。即28对应的地址是0，由于存放在0位置的数是7，所以往后挪移一位，发现在1位置存放的数是14，继续往后挪一位，发现位置2上没有数。至此就知道28不在这个哈希表里，即查找28失败。<br>
地址1，到第一个关键字为空的地址2需要比较2次，因此查找不成功的次数为2。<br>
地址2，到第一个关键字为空的地址2需要比较1次，因此查找不成功的次数为1。<br>
地址3，到第一个关键字为空的地址4需要比较2次，因此查找不成功的次数为2。<br>
地址4，到第一个关键字为空的地址4需要比较1次，因此查找不成功的次数为1。<br>
地址5，到第一个关键字为空的地址9需要比较5次，因此查找不成功的次数为5。<br>
比如要查找的数为4，H(4) = (4 * 3) % 7 = 5，所以从地址5开始查找，最终发现地址5、地址6、地址7、地址8上存放的数都不是5，并且地址9的位置上没放数据，至此可知5不在这个哈希表里。<br>
地址6，到第一个关键字为空的地址9需要比较4次，因此查找不成功的次数为4。<br>
所以，查找不成功的平均查找长度为（3 + 2 + 1 + 2 + 1 + 5 + 4）/ 7 = 18 / 7。</p>
<h1>五、优缺点</h1>
<p>优点：<br>
不论哈希表中有多少数据，查找、插入、删除（有时包括删除）只需要接近常量的时间即0(1）的时间级。实际上，这只需要几条机器指令。<br>
哈希表运算得非常快，在计算机程序中，如果需要在一秒种内查找上千条记录通常使用哈希表（例如拼写检查器)哈希表的速度明显比树快，树的操作通常需要O(N)的时间级。哈希表不仅速度快，编程实现也相对容易。<br>
如果不需要有序遍历数据，并且可以提前预测数据量的大小。那么哈希表在速度和易用性方面是无与伦比的。</p>
<p>缺点：<br>
它是基于数组的，数组创建后难于扩展，某些哈希表被基本填满时，性能下降得非常严重，所以程序员必须要清楚表中将要存储多少数据，或者准备好定期地把数据转移到更大的哈希表中，这是个费时的过程。</p>
<h1>六、C语言实现</h1>
<pre class="hljs cpp"><code class="cpp"><span class="hljs-comment">/*采用数组实现哈希表*/</span> 

<span class="hljs-meta">#<span class="hljs-meta-keyword">include</span><span class="hljs-meta-string">&lt;stdio.h&gt;</span></span>
<span class="hljs-meta">#<span class="hljs-meta-keyword">define</span> DataType int</span>
<span class="hljs-meta">#<span class="hljs-meta-keyword">define</span> Len 10</span>

<span class="hljs-keyword">typedef</span> <span class="hljs-class"><span class="hljs-keyword">struct</span> <span class="hljs-title">HashNode</span>    
{</span>
    DataType data;    <span class="hljs-comment">//存储值 </span>
    <span class="hljs-keyword">int</span> isNull;       <span class="hljs-comment">//标志该位置是否已被填充 </span>
}HashTable;

HashTable hashTable[Len];

<span class="hljs-function"><span class="hljs-keyword">void</span> <span class="hljs-title">initHashTable</span><span class="hljs-params">()</span>     <span class="hljs-comment">//对hash表进行初始化 </span>
</span>{
    <span class="hljs-keyword">int</span> i;
    <span class="hljs-keyword">for</span>(i = <span class="hljs-number">0</span>; i&lt;Len; i++)
    {
        hashTable[i].isNull = <span class="hljs-number">1</span>;    <span class="hljs-comment">//初始状态为空 </span>
    }
}

<span class="hljs-function"><span class="hljs-keyword">int</span> <span class="hljs-title">getHashAddress</span><span class="hljs-params">(DataType key)</span>    <span class="hljs-comment">//Hash函数 </span>
</span>{
    <span class="hljs-keyword">return</span> key * <span class="hljs-number">3</span> % <span class="hljs-number">7</span>;      
}

<span class="hljs-function"><span class="hljs-keyword">int</span> <span class="hljs-title">insert</span><span class="hljs-params">(DataType key)</span>    
</span>{
    <span class="hljs-keyword">int</span> address = getHashAddress(key);       
    <span class="hljs-keyword">if</span>(hashTable[address].isNull == <span class="hljs-number">1</span>)  <span class="hljs-comment">//没有发生冲突 </span>
    {
        hashTable[address].data = key;
        hashTable[address].isNull = <span class="hljs-number">0</span>;
    }
    <span class="hljs-keyword">else</span>    <span class="hljs-comment">//当发生冲突的时候 </span>
    {
        <span class="hljs-keyword">while</span>(hashTable[address].isNull == <span class="hljs-number">0</span> &amp;&amp; address&lt;Len)
        {
            address++;          <span class="hljs-comment">//采用线性探测法，步长为1 </span>
        }
        <span class="hljs-keyword">if</span>(address == Len)      <span class="hljs-comment">//Hash表发生溢出 </span>
            <span class="hljs-keyword">return</span> <span class="hljs-number">-1</span>;
        hashTable[address].data = key;
        hashTable[address].isNull = <span class="hljs-number">0</span>;
    }
    
    <span class="hljs-keyword">return</span> <span class="hljs-number">0</span>;
}

<span class="hljs-function"><span class="hljs-keyword">int</span> <span class="hljs-title">find</span><span class="hljs-params">(DataType key)</span>       
</span>{
    <span class="hljs-keyword">int</span> address = getHashAddress(key);
    <span class="hljs-keyword">while</span>( !(hashTable[address].isNull == <span class="hljs-number">0</span> &amp;&amp; hashTable[address].data == key &amp;&amp; address&lt;Len))
    {
        address++;
    } 
    
    <span class="hljs-keyword">if</span>( address == Len)
    {
        address = <span class="hljs-number">-1</span>;
    }
    
    <span class="hljs-keyword">return</span> address;
}

<span class="hljs-function"><span class="hljs-keyword">int</span> <span class="hljs-title">main</span><span class="hljs-params">(<span class="hljs-keyword">int</span> argc, <span class="hljs-keyword">char</span> *argv[])</span>
</span>{
    <span class="hljs-keyword">int</span> key[]={<span class="hljs-number">7</span>,<span class="hljs-number">8</span>,<span class="hljs-number">30</span>,<span class="hljs-number">11</span>,<span class="hljs-number">18</span>,<span class="hljs-number">9</span>,<span class="hljs-number">14</span>};
    <span class="hljs-keyword">int</span> i;
    initHashTable();
    

    <span class="hljs-keyword">for</span>(i = <span class="hljs-number">0</span>; i&lt;<span class="hljs-number">7</span>; i++)
    {
        insert(key[i]);
    }
    
    <span class="hljs-keyword">for</span>(i = <span class="hljs-number">0</span>; i&lt;<span class="hljs-number">7</span>; i++)
    {
        <span class="hljs-keyword">int</span> address;
        address = find(key[i]);
        <span class="hljs-built_in">printf</span>(<span class="hljs-string">"key:%d\t address:%d\n"</span>, key[i],address);
    }
    
    <span class="hljs-keyword">return</span> <span class="hljs-number">0</span>;
}

</code></pre>
<p>运行结果：</p>
<pre class="hljs css"><code class="css"><span class="hljs-selector-tag">key</span><span class="hljs-selector-pseudo">:7</span>    <span class="hljs-selector-tag">address</span><span class="hljs-selector-pseudo">:0</span>
<span class="hljs-selector-tag">key</span><span class="hljs-selector-pseudo">:8</span>    <span class="hljs-selector-tag">address</span><span class="hljs-selector-pseudo">:3</span>
<span class="hljs-selector-tag">key</span><span class="hljs-selector-pseudo">:30</span>   <span class="hljs-selector-tag">address</span><span class="hljs-selector-pseudo">:6</span>
<span class="hljs-selector-tag">key</span><span class="hljs-selector-pseudo">:11</span>   <span class="hljs-selector-tag">address</span><span class="hljs-selector-pseudo">:5</span>
<span class="hljs-selector-tag">key</span><span class="hljs-selector-pseudo">:18</span>   <span class="hljs-selector-tag">address</span><span class="hljs-selector-pseudo">:7</span>
<span class="hljs-selector-tag">key</span><span class="hljs-selector-pseudo">:9</span>    <span class="hljs-selector-tag">address</span><span class="hljs-selector-pseudo">:8</span>
<span class="hljs-selector-tag">key</span><span class="hljs-selector-pseudo">:14</span>   <span class="hljs-selector-tag">address</span><span class="hljs-selector-pseudo">:1</span>
</code></pre>
<blockquote>
<p>了解少儿编程、信息学竞赛请加微信307591841或QQ群581357582</p>
<br>
<div class="image-package">
<div class="image-container" style="max-width: 258px; max-height: 258px;">
<div class="image-container-fill" style="padding-bottom: 100.0%;"></div>
<div class="image-view" data-width="258" data-height="258"><img data-original-src="//upload-images.jianshu.io/upload_images/6946981-eab9f779a000b217.jpg" data-original-width="258" data-original-height="258" data-original-format="image/jpeg" data-original-filesize="27484" style="cursor: zoom-in;" class="image-loading"></div>
</div>
<div class="image-caption">信息学竞赛公众号.jpg</div>
</div>
</blockquote>

          </div>