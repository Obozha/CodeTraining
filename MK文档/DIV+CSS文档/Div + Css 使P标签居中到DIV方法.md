# 使P标签居中到DIV方法

## 一 通过填充 + Text-align 来获得垂直居中
代码

                <div id="footer">
                    <p id="fp">COPY RIGHT &copy;&nbsp;&nbsp;&nbsp;&nbsp;中国环宇科技有限公司&nbsp;&nbsp;科技事业部支持 京备XXXXX-342</p>
                </div>

对应CSS
###### p标签
        p{
            padding: 0 auto;
            margin:22px ;
        }
###### footer 尾部
        #footer{
            /*display: table;*/
            clear: both;
            width: 990px;
            height: 60px;
            background: #f7f7f7;
            text-align: center;
            border-top:2px solid #0099ff ;
        }

第一种思路是用p标签的填充**父布局**，利用p标签上下margin相等的特性

## 二 通过table 和table-cell来实现p标签居中

对应CSS
###### id选择器 footer
    #footer{
        display: table;
        clear: both;
        width: 990px;
        height: 60px;
        background: #f7f7f7;
        text-align: center;
        border-top:2px solid #0099ff ;

    }
###### 对应p标签
    #fp{
        padding: 0 auto;
        display: table-cell;
        vertical-align: middle;
        /*margin:22px ;*/
    }

第二种思路是用table和table-cell来控制布局，外布局为table,内部为table-cell来模拟表格，`p`标签设置 `vertical-align: middle;`` display: table;`
`#footer`设置`text-align: center;` `display: table-cell;`
