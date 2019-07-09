---
layout: post
category: Web前端
title: 关于
tags: BigZCoder, info
keywords: BigZCoder, BigZCoder
excerpt: 我是 BigZCoder 一名刚刚入坑的程序员
redirect_from:
  - /2017/06/about/
---

我是 BigZCoder 刚刚入坑的程序员，学习了GcsSloop的GithubPages搭建博客，现在正在进攻Java Web和前端方向。

******

#### Div + CSS让一个DIV完全居中到另一个DIV

解决方法1

	.parent{
		width:800px;
		height:500px;
		border:2px solid #000;
		position:relative;
        <!-- relative可以让child相对于parent移动 -->
	}

	.child{
        <!-- 水平移动的核心代码 -->
		margin:auto；
		position:absolute;
		top:0;
		left:0;
		bottom:0;
		right:0;
		width:10px;
		height:10px;
		background-color:#066;
	}

解决方法2

	.parent {
            width:500px;
            height:500px;
            border:2px solid #000;
            position:relative;
        }
    .child {
            width:100px;
            height:100px;
            margin:auto;
            position:absolute;
            left:50%;
            top:50%;
            margin-top:-50px;
            margin-left:-50px;
            background-color: red;
    }

以上总结两个从一个`DIV`到另一个`DIV`完全居中的两个方法