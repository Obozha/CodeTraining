---
layout: post
category: Web前端
title: CSS + DIV 设计网站基础类型框架
tags: BigZCoder, info
keywords: BigZCoder, BigZCoder
excerpt: 我是 BigZCoder 一名刚刚入坑的程序员
redirect_from:
  - /2017/06/about/
---


******



#### CSS + DIV 设计网站基础类型框架


首先，设计各`DIV`的位置。


	<div id="container">
  		<div id="banner">
   			 <p>#banner</p>
  		</div>
  		<div id="content">
    		<p>#content</p>
  		</div>
  		<div id="links">
  	 		<p>#links</p>
  		</div>
  		<div id="footer">
  			<p>#footer</p>
  		</div>
	</div>

第一步 设置`body`和#`container`

    body {
		margin:0px;
		padding:0px;
		text-align:center;
	}

    #container {
		width:1280px;
		height:1000px;
		background:#FFC;
		margin:0 auto;
        <!-- margin:0 auto;使DIV自动水平居中到浏览器 -->
	}

第二步 设置`banner` `content` `links` `footer`

	#banner {
		height:100px;
		background:#FCF;
		position:relative;
		<!-- banner的宽自动和container一致，只用设置高 -->
    }

	#content {
		height:800px;
		width:800px;
		float:left;
		background:#FC9;
		position:relative;
	}

    #links{
		width:480px;
		height:800px;
		float:left;
		background:#6CF;
        position:relative;
   	}
    <!-- content 和 link两个DIV需要设置float:left 而且两个DIV的width加起来要等于container的width，这样就能完全覆盖 -->

    #footer{
		width:1280px;
		height:100px;
		background:#66F;
		position:relative;
		clear:both;
    }
    <!-- footer这里为了不受content和link两个的浮动影响，需要设定clear:both -->

第三步，设置所有的`DIV`中的`P`标签居中

	p {
		top:0px;
		left:0px;
		bottom:0px;
		right:0px;
		margin:auto;
		width:80px;
		height:14px;
		position:absolute;
		font-family:Verdana, Geneva, sans-serif;
		font-size:30px;
        <!-- 盒子设定relative是为了p标签设置absolute后可以指定相对移动的盒子为当前盒子 -->
	}

想要的各块的位置如图所示
![框架Demo](https://github.com/bigzcoder/bigzcoder.github.com/blob/master/img/%E7%AE%80%E5%8D%95%E6%A1%86%E6%9E%B6Demo.jpg)