## DIV+CSS 绝对位置+相对位置实现导航栏

HTML代码如下
```
<!-- edu_10_3_1.hmtl -->
<!doctype html>
<html lang="en">

	<head>
		<meta charset="UTF-8">
		<meta name="keywords" content="中国出版协会">
		<meta name="description" content="中国出版协会">
		<link rel="stylesheet" href="css/1-3.css" type="text/css">
		<title>中国出版协会简化网站</title>
	</head>

	<body>
		<div class="body-top">
			<div class="header">
				<div class="logo">
					<div id="nav_wrap">
						<div id="nav">
							<ul>
								<li><span class="v"><a href="#">首页</a></span><span class="cut_line">|</span></li>
								<li><span class="v"><a href="#">协会概况</a></span><span class="cut_line">|</span>
									<div class="kind_menu">
										<a href="#">协会简介</a><span>|</span>
										<a href="#">大事记</a><span>|</span>
										<a href="#">协会章程</a><span>|</span>
										<a href="#">协会领导</a><span>|</span>
										<a href="#">组织机构</a><span>|</span>
										<a href="#">历史沿革</a><span>|</span>
									</div>
								</li>
								<li><span class="v"><a href="#">新闻公告</a></span><span class="cut_line">|</span>
									<div class="kind_menu">
										<a href="#">协会动态</a><span>|</span>
										<a href="#">行业动态</a><span>|</span>
									</div>
								</li>
								<li><span class="v"><a href="#">领导讲话</a></span><span class="cut_line">|</span></li>
								<li><span class="v"><a href="#">政策法规</a></span><span class="cut_line">|</span>
									<div class="kind_menu">
										<a href="#">政策发布</a><span>|</span>
										<a href="#">法律法规</a><span>|</span>
									</div>
								</li>
								<li><span class="v"><a href="#">工作简报</a></span><span class="cut_line">|</span>
									<div class="kind_menu">
									</div>
								</li>
								<li><span class="v"><a href="#">评奖表彰</a></span><span class="cut_line">|</span>
									<div class="kind_menu">
									</div>
								</li>
								<li><span class="v"><a href="#">会员服务</a></span><span class="cut_line">|</span>
									<div class="kind_menu">
										<a href="#">会员单位</a><span>|</span>
										<a href="#">会员动态</a><span>|</span>
										<a href="#">申请入会</a><span>|</span>
										<a href="#">会员变更</a><span>|</span>
										<a href="#">会员风采</a><span>|</span>
										<a href="#">行业维权</a><span>|</span>
										<a href="#">行业自律</a><span>|</span>
										<a href="#">建言献策</a><span>|</span>
									</div>
								</li>
								<li><span class="v"><a href="#">教育培训</a></span><span class="cut_line">|</span></li>
								<li><span class="v"><a href="#">外事</a></span><span class="cut_line">|</span></li>
								<li><span class="v"><a href="#">专家访谈</a></span><span class="cut_line">|</span></li>
								<li><span class="v"><a href="#">展会</a></span><span class="cut_line">|</span></li>
								<li><span class="v"><a href="#">行业研究</a></span><span class="cut_line">|</span>
									<div class="kind_menu">
										<a href="#">高端视点</a><span>|</span>
										<a href="#">理论专题</a><span>|</span>
										<a href="#">调研报告</a><span>|</span>
										<a href="#">在线调研</a><span>|</span>
									</div>
								</li>
							</ul>
						</div>
					</div>
				</div>
			</div>
		</div>
		<div class="changeDiv"></div>
		<div class="footer"></div>
	</body>

</html>
```

####第一步  设置body样式和.body-top
这点需要设置导航栏的背景图，清空一下默认的浏览器的边距
以及全局文字的样式

```
*{
	margin: 0;
	padding: 0;
}

body,html{
	font: 12px/1.5 tahoma,arial,sans-serif;
}

.body-top{
	height: 297px;
	background: url(../img/b1.jpg);
}
```
####第二步 设置.header,.header .logo宽高以及logo
设置.header,.header .logo的宽高和margin居中 0 auto 以及logo
```
.header,.header .logo{
	width: 960px;
	margin: 0 auto;
	height: 297px;
	background: url(../img/b2.jpg) no-repeat center;
}

```

####第三步 设置nav的位置以及nav需要的position
先设置nav_wrap的padding-top，为了让nav到达图片上导航栏的位置
```
#nav_wrap {
	width: 960px;
	/*overflow: hidden;*/
	padding-top: 223px;
	/* 包裹着nav的盒子用padding-top来把盒子挤兑到对应的位置 */
}
```
接着设置nav，注意一点position需要relative，为了给二级标题提供相对位移 nav的高度是.header的高度297px-223px padding的高度得到74px 正好填满


```
#nav{
	height: 74px;
	width: 960px;
	/*margin: 0 auto; 因为header已经居中过了 nav显然居中没有什么意义 */
	position: relative;
	/* 这里设置的relative 使后边的.kind_menu相对nav来进行移动 */
}
```
#### 第四步 设置nav中的导航栏
#####（1）ul和li的基本属性 实现li左浮动
设置了外边的nav_wrap和nav接着操作nav里边的ul和li
而首先要进行对ul的默认样式清空
````
#nav ul{
	margin: 0;
	padding: 0;
	/* 消除ul默认的样式 */
}

````

接着对ul中的li进行设置样式 对于ul中的li首先考虑的是float和list-style
接着是font-size和font-weight 这样li所有项目就向左浮动了
```
#nav li{	/* nav下所有li的样式 */
	float: left;
	list-style: none;
	/*text-align:center;*/
	font-size:14px;
	font-weight:700;
	/* #nav下所有的字体和样式，以及浮动 */
}
```


#####（2）实现左浮动后，需要设置位置来让二级标题脱离文档流
设置float之后发现二级标题栏的DIV .kind_menu占着li中的位置，使标题栏目前非常畸形
这时候设置.kind_menu的position来脱离标准流 用top和left调位 细微调整padding-top
调整字体，而且暂时不显示

#####（3）实现鼠标盘旋前后出现二级标题的功能

接着设置nav ul li:hover .kind_menu的样式，当鼠标移动到li的时候显示.kind_menu
这样就实现了导航栏功能
```
#nav .kind_menu{
	top: 26px;
	left: 70px;
	position: absolute;
	width: 880px;
	padding-top: 18px;
	font-weight: normal;
	display:none;
	/* 暂时先不显示 */
}

#nav ul li:hover .kind_menu{
	display: block;
	/* 当盘旋到li的时候 kind_menu 显示 */
}
```
#####（3）调整一级标题的一些样式
然后回来再来调整一级标题的a的样式 设置左右padding line-height
一级标题a标签在悬浮的时候颜色和装饰
```
#nav li .v a{ /* 一级标题栏的样式 */
	padding: 0 4px;
	/* 左右padding4px */
	line-height: 33px;
	/*height: 39px;*/
	/* 行高指的是文字的所占的高度，而height是指内容的高度 */
	/*display: block;*/
	/*float: left;*/
	/* span里的a标签变成块就把其他span标签挤下去了 需要左浮动 */
	color: #0d2972;
}

#nav li .v a:hover{ /* 一级标题栏在盘旋的的样式 */
	color: #d62e38;
	text-decoration: none;
}
```
#### 知识点Tips:line-height和height
![hgq.png](\img\hgq.png)
修改之前的line-height
![hgw.png](\img\hgw.png)
修改之后的line-height
**总结：行高指的是文字，height值得是内容**

[TOC]


