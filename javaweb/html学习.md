```html
<link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet" type="text/css"><!--下载谷歌的字体-->
<!--在style中设置css-->
<style>
.red-text {
color: red;
}

h2 {
font-family: Lobster, Monospace;
}

p {
font-size: 16px;
font-family: Monospace;
}

.thick-green-border {
border-color: green;
border-width: 10px;
border-style: solid;
border-radius: 50%;
}

.smaller-image {
width: 100px;
}

.gray-background {
background-color: gray;
}

#cat-photo-form{
    background-color: green;
}
</style>

<h2 class="red-text">CatPhotoApp</h2>

<p>Click here for <a href="#">cat photos</a>.</p><!--p表示段落，a表示链接-->

<a href="#"><img class="smaller-image thick-green-border" alt="A cute orange cat lying on its back" src="https://www.w3cschool.cn/statics/codecamp/images/relaxing-cat.jpg"></a>

<div class="gray-background"><!--div为区块，为了更方便设置一个区块的统一显示配置(css)-->
<p>Things cats love:</p>
<ul><!--ul表示没有序号的列表-->
<li>cat nip</li><!--li表示列表中的每一条元素-->
<li>laser pointers</li>
<li>lasagna</li>
</ul>
<p>Top 3 things cats hate:</p>
<ol><!--ol表示序号的列表-->
<li>flea treatment</li>
<li>thunder</li>
<li>other cats</li>
</ol>
</div>

<form action="/submit-cat-photo" id="cat-photo-form"><!--form代表表单-->
<label><input type="radio" name="indoor-outdoor" checked> Indoor</label><!--label表示选框，radio是单选框，checkbox是复选框，相同name的radio只能选一个-->
<label><input type="radio" name="indoor-outdoor"> Outdoor</label>
<label><input type="checkbox" name="personality" checked> Loving</label>
<label><input type="checkbox" name="personality"> Lazy</label>
<label><input type="checkbox" name="personality"> Energetic</label>
<input type="text" placeholder="cat photo URL" required><!--required表示必填或者必选-->
<button type="submit">Submit</button><!--button为按钮，当type为submit时提交表单-->
</form>

```

~~~html
<link href="//fonts.gdgdocs.org/css?family=Lobster" rel="stylesheet" type="text/css">
<style>
  h2 {
    font-family: Lobster, Monospace;
  }

  .thick-green-border {
    border-color: green;
    border-width: 10px;
    border-style: solid;
    border-radius: 50%;
  }

</style>

<div class="container-fluid">
  <div class="row">
    <div class="col-xs-8">
      <h2 class="text-primary text-center">CatPhotoApp</h2>
    </div>
    <div class="col-xs-4">
      <a href="#"><img class="img-responsive thick-green-border" src="/images/relaxing-cat.jpg"></a>
    </div>
  </div>
  <img src="/images/running-cat.jpg" class="img-responsive">
  <div class="row">
    <div class="col-xs-4">
      <button class="btn btn-block btn-primary"><i class="fa fa-thumbs-up"></i> Like</button>
    </div>
    <div class="col-xs-4">
      <button class="btn btn-block btn-info"><i class="fa fa-info-circle"></i> Info</button>
    </div>
    <div class="col-xs-4">
      <button class="btn btn-block btn-danger"><i class="fa fa-trash"></i> Delete</button>
    </div>
  </div>
  <p>Things cats <span class="text-danger">love:</span></p>
  <ul>
    <li>cat nip</li>
    <li>laser pointers</li>
    <li>lasagna</li>
  </ul>
  <p>Top 3 things cats hate:</p>
  <ol>
    <li>flea treatment</li>
    <li>thunder</li>
    <li>other cats</li>
  </ol>
  <form action="/submit-cat-photo">
    <div class="row">
      <div class="col-xs-6">
        <label><input type="radio" name="indoor-outdoor"> Indoor</label>
      </div>
      <div class="col-xs-6">
        <label><input type="radio" name="indoor-outdoor"> Outdoor</label>
      </div>
    </div>
    <div class="row">
      <div class="col-xs-4">
        <label><input type="checkbox" name="personality"> Loving</label>
      </div>
      <div class="col-xs-4">
        <label><input type="checkbox" name="personality"> Lazy</label>
      </div>
      <div class="col-xs-4">
        <label><input type="checkbox" name="personality"> Crazy</label>
      </div>
    </div>
    <div class="row">
    <div class="col-xs-7"><input type="text" class="form-control" placeholder="cat photo URL" required></div>
    <div class="col-xs-5"><button type="submit" class="btn btn-primary"><i class="fa fa-paper-plane"></i> Submit</button></div>
    </div>
  </form>
</div>

~~~

