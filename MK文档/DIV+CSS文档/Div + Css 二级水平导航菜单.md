## 10.2.2 二级水平导航菜单
###实验一

```
		<li><a href="#">首页</a></li>
	    <li><a href="#">jQuery特效</a>
			<ul>
				<li><a href="#">jQuery图片特效</a></li>
				<li><a href="#">jQuery导航特效</a></li>
				<li><a href="#">jQuery选项卡特效</a></li>
				<li><a href="#">jQuery文字特效</a></li>
			</ul>
		</li>
```
#### 123
这里的ul包含一个a标签和一个ul标签

对应css文件




```
ul{
	margin: 0px;
	padding: 0px;	/* 这里来消除无序列表的默认的padding和margin */
}

ul li{
	width: 115px;	/* 这里来设置挤压 */
	height: 30px;
	float: left;
	list-style: none;
	font: 0.9em arial,helvetica,sans-serif;
	background: aliceblue;
	text-align: center;
}

```

设置好`li`的宽，一级标题的第二个`li`包含了一个a标签和ul标签，ul因为宽度排挤到a标签的下方，li也因为宽度挤压一列

```
ul li a {
  color: #FFF;
  width: 113px;
  margin: 0px;
  text-decoration: none;
  display: block;	/* 这里是让a标签变为块标签 接着宽度伸开 进入标准流 */
  background: #808080;
}
```
1)块级元素
- 霸占一行，不能与其他元素并列
- 能接收宽高
- 如果不设置宽高，那么宽度将默认变为父辈的100%
2）行内元素
- 与其他行内元素并列
- 不能设置宽高。默认的宽度就是文字的宽度

贴上代码
```
<!-- edu_10_2_6.html -->
<!doctype html>
<html lang="en">
 <head>
  <meta charset="UTF-8">  
  <title> 下拉导航菜单</title>
  <link rel="stylesheet" href="css/1-1.css" type="text/css">
 </head>
 <body>
	<ul>
		<li><a href="#">首页</a></li>
		<li><a href="#">jQuery特效</a>
			<ul>
				<li><a href="#">jQuery图片特效</a></li>
				<li><a href="#">jQuery导航特效</a></li>
				<li><a href="#">jQuery选项卡特效</a></li>
				<li><a href="#">jQuery文字特效</a></li>
			</ul>
		</li>
			
		<li><a href="#">JavaScript特效</a></li>
		<li><a href="#">Flash特效</a>
			<ul>
				<li><a href="#">Flash图片特效</a></li>
				<li><a href="#">Flash导航特效</a></li>
				<li><a href="#">Flash选项卡特效</a></li>
				<li><a href="#">Flash文字特效</a></li>
			</ul>
		</li>
			
		<li><a href="#">dis+css教程</a></li>
		<li><a href="#">HTML5教程</a></li>
	</ul>
	<p style="clear: both;">hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh</p>
 </body>
</html>

```

```
ul{
	margin: 0px;
	padding: 0px; /* 消除ul默认的padding和margin */
	height: 30px;
}

ul li{
	height: 30px;
	width: 115px;
	float:left;
	list-style: none;
	font: 0.9em arial;
}

ul li a{
	line-height: 29px;
	/* 因为li标签是30px a先转为块，
	 * 宽度填充父布局 高度设为29为底部留一个像素 */
	width: 113px;
	/**
	 * 总共宽度为115px 设置113像素留2个像素
	 */
	text-align: center;
	/**
	 * a 块中的文字居中
	 */
	display: block;
	text-decoration: none;
	border-bottom: 1px solid #ccc;
	/* 1个像素来作下划线 */
	border-right: 1px solid #ccc;
	padding: 0 0 0 1px;
	
	color: #fff;
	background: #808080;
}

ul li ul li{
	height: 25px;
	/* 本来通过继承的是30px 这里单独制定二级标题的高度25px */
}

ul li ul li a{
	height: 24px;
	background: #666;
	/* 相应的也要覆盖原来a继承的高度，原来是29像素，覆盖之后是24px
	 * 背景颜色也做相应改变
	 *  */
}

ul li a:hover{
	background: #666;
	border-bottom: 1px dashed #ff0000;
	/**
	 * a:hover当超链接滑过的时候
	 * 这里的背景颜色与二级标题一直，意味这我要被选中了
	 * 而且当选中的时候出现下划线
	 */
}

ul li ul{
	visibility: hidden;
	/**
	 * 隐藏掉二级菜单
	 */
}

ul li:hover ul{
	visibility: visible;
}

ul li ul li a:hover{
	background: #333;
}


```

line-height是行高，height就是高，通常height是对于某个框架或者图片来弄的，line-height用于文字
如果要实际效果你可以写一段文字，分好几行，然后对它做line-height属性，就会注意到变化了
调整20px这个值，行间距就会发生变化
另外，line-height和height组合到一块儿，还有一种效果，就是如果把它们的值设置的一样了，文字就会在垂直方向居中
比如：
<div style="line-height:20px;">abc<br/>abc<br/>abc<br/>abc<br/>abc<br/></div>

###实验二
HTML代码
```
<!-- edu_10_2_7.html -->
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title></title>
		<link rel="stylesheet" type="text/css" href="css/1-2.css"/>
	</head>
	<body>
		<div id="menu">
			<ul>
				<li><a href="#">首页</a></li>
				<li><a href="#">jQuery特效</a>
					<div class="submenu">
						<ul>
							<li><a href="#">jQuery图片特效</a></li>
							<li><a href="#">jQuery导航特效</a></li>
							<li><a href="#">jQuery选项卡特效</a></li>
							<li><a href="#">jQuery文字特效</a></li>
						</ul>
					</div>
				</li>
				<li><a href="#">JavaScript特效</a></li>
				<li><a href="#">Flash特效</a>
					<div class="submenu">
						<ul>
							<li><a href="#">Flash图片特效</a></li>
							<li><a href="#">Flash导航特效</a></li>
							<li><a href="#">Flash选项卡特效</a></li>
							<li><a href="#">Flash文字特效</a></li>
						</ul>
					</div>
				</li>
				<li><a href="#">div+css教程</a></li>
				<li><a href="#">HTML5教程</a></li>
			</ul>
		</div>
	</body>
</html>

```

CSS设置

第一步设置body和#menu，总共62个px
```
*{
	padding: 0;
	margin: 0;
}

#menu{			/* 定义图层样式 */
	width: 100%;		/* 设置宽度100% */
	height: 60px;		/* 设置高度60px 而高度是两倍的导航栏 这样的话 一级标题的li和二级标题的li都为30px */
	background: #55aaee;	/* 背景色 */
	border: 1px solid #333; /* 变框 */
}

```

接下来设置ul 对于ul不需要刚开始默认的padding和margin 所以自己设置来覆盖默认
同时居中的话设置`margin:0 auto`
```
#menu ul{
	margin: 0 auto;
	padding: 0px;
	width: 700px;
	height: 200px;
}

```
居中完毕以后设置所有的li `float:left`这样所有的li就左浮动，而且 二级标题被一级标题其中两个li所包括
需要设置width和height两项来 让li的宽度限制二级标题的宽度，使每一个li向下排列而且设置了二级li
```
#menu ul li{
	float: left;
	height: 30px;
	width: 115px;
	list-style: none; /* 附带设置所有li居中 字体 一级list-style */
	text-align: center;
	font: 0.9em arial;
}
```

设置完了li 接着设置li里边的a超链接标签 分别设置`color 颜色 line-height display background width border-bottom`
```
ul li a{
	color: #fff; /* 字体颜色 */
	line-height: 29px; /* a标签行高比li少一个像素为了下边的border */
	display: block;  /* 块状 */
	background: #55A0FF;	 /* 背景 */
	text-decoration: none;	 /* 下划线 */
	width: 114px;			 /* 宽度少一个像素	 */
	border-bottom:1px solid #ccc; /* 自定义下划线 */
}
```
a标签设置之后 设置二级标题DIV的宽度
```
.submenu{
	width: 900px;
	height: 28px;
}
```

设置二级标题的样式 `li a`
```
ul li .submenu ul li{
	height: 25px;
}

ul li .submenu ul li a{	
	height: 24px;
	background: #55aaee;
}
```
设置二级标题隐藏和鼠标移动到的时候显示，以及显示的无序列表中的a标签的颜色
```
ul li .submenu{
	display: none;
}

ul li:hover .submenu{
	display: block;
}

ul li .submenu ul li a:hover{
	background: #333;
}
```
###总结
**li限制了所有的宽度 这样使下拉菜单中的li/div也可以排序向下，如果不想让下拉菜单向下排序，设置下拉菜单的div的宽度让横着排列**

[TOC]



# ```![](http://pic19.photophoto.cn/20110630/0017029500306376_b.jpg)

123

```