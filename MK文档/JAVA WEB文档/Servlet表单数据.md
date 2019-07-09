# Servlet 表单数据

* [Servlet 表单数据](#servlet-%E8%A1%A8%E5%8D%95%E6%95%B0%E6%8D%AE)
  * [Get](#get)
  * [Post](#post)
  * [使用Servlet读取表单数据](#%E4%BD%BF%E7%94%A8servlet%E8%AF%BB%E5%8F%96%E8%A1%A8%E5%8D%95%E6%95%B0%E6%8D%AE)
  * [使用URL的GET方法实例](#%E4%BD%BF%E7%94%A8url%E7%9A%84get%E6%96%B9%E6%B3%95%E5%AE%9E%E4%BE%8B)
  * [使用表单的GET方法实例](#%E4%BD%BF%E7%94%A8%E8%A1%A8%E5%8D%95%E7%9A%84get%E6%96%B9%E6%B3%95%E5%AE%9E%E4%BE%8B)
  * [使用表单的POST方法实例](#%E4%BD%BF%E7%94%A8%E8%A1%A8%E5%8D%95%E7%9A%84post%E6%96%B9%E6%B3%95%E5%AE%9E%E4%BE%8B)
  * [将复选框数据传递到 Servlet 程序](#%E5%B0%86%E5%A4%8D%E9%80%89%E6%A1%86%E6%95%B0%E6%8D%AE%E4%BC%A0%E9%80%92%E5%88%B0-servlet-%E7%A8%8B%E5%BA%8F)

## Get

Get方法向页面请求发送已编码的用户信息。页面和已编码的信息用?字符分割

    http://www.test.com/hello?key1=value&key2=value

## Post

POST方法打包信息的方式于GET方法基本相同，但是POST方法不是把信息作为URL中?字符后的文本字符串进行发送，而是把这些信息作为单独的消息。消息以标准输出的形式传到后台程序，可以解析和使用这些标准输出，Servlet使用doPost()方法处理这种类型的请求

## 使用Servlet读取表单数据

Servlet处理表单数据，这些数据会根据不同的情况使用不同的方法自动解析：

* getParameter()：您可以调用 request.getParameter() 方法来获取表单参数的值。
* getParameterValues()：如果参数出现一次以上，则调用该方法，并返回多个值，例如复选框。
* getParameterNames()：如果您想要得到当前请求中的所有参数的完整列表，则调用该方法。

## 使用URL的GET方法实例

    package com.test.helloservlet;

    import java.io.IOException;
    import java.io.PrintWriter;

    import javax.servlet.ServletException;
    import javax.servlet.annotation.WebServlet;
    import javax.servlet.http.HttpServlet;
    import javax.servlet.http.HttpServletRequest;
    import javax.servlet.http.HttpServletResponse;

    // Get方法向页面请求发送已编码的用户信息。页面和已编码的信息用?字符分割
    // http://www.test.com/hello?key1=value&key2=value

    // 使用Servlet读取表单数据
    // get

    /**
    * Servlet implementation class GetServlet
    */
    @WebServlet("/GetServlet")
    public class GetServlet extends HttpServlet {
        private static final long serialVersionUID = 1L;

        /**
        * @see HttpServlet#HttpServlet()
        */
        public GetServlet() {
            super();
            // TODO Auto-generated constructor stub
        }

        /**
        * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
        *      response)
        */
        protected void doGet(HttpServletRequest request, HttpServletResponse response)
                throws ServletException, IOException {
            // TODO Auto-generated method stub
            // 设置响应内容系列
            response.setContentType("text/html;charset=UTF-8");

            PrintWriter out = response.getWriter();
            String title = "使用GET方法读取表单数据";
            String name = request.getParameter("name");
            String docType = "<!DOCTYPE html> \n";
            out.println(
                    docType + "<html>\n" + "<head><title>" + title + "</title></head>\n" + "<body bgcolor=\"#f0f0f0\">\n"
                            + "<h1 align=\"center\">" + title + "</h1>\n" + "<ul>\n" + "  <li><b>站点名</b>：" + name + "\n"
                            + "  <li><b>网址</b>：" + request.getParameter("url") + "\n" + "</ul>\n" + "</body></html>");

        }

        /**
        * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
        *      response)
        */
        protected void doPost(HttpServletRequest request, HttpServletResponse response)
                throws ServletException, IOException {
            // TODO Auto-generated method stub
            doGet(request, response);
        }

    }

web.xml

    <servlet>
        <servlet-name>GetServlet</servlet-name>
        <servlet-class>com.test.helloservlet.GetServlet</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>GetServlet</servlet-name>
        <url-pattern>/HelloServlet/GetServlet</url-pattern>
    </servlet-mapping>

乱码问题解决

要解决这个问题，修改tomcat服务器的配置文件。修改tomcat目录下的conf/server.xml文件的第43行：

修改前内容：

    <Connector port="8080" protocol="HTTP/1.1"
     maxThreads="150"   connectionTimeout="200000"
     redirecPort="8443"/>

修改后内容：

    <Connector port="8080" protocol="HTTP/1.1"
     maxThreads="150"   connectionTimeout="200000"
     redirecPort="8443"    URIEncoding="utf-8"/>

## 使用表单的GET方法实例

    <!DOCTYPE html>
    <html>
    <head>
    <meta charset="utf-8">
    <title>菜鸟教程(runoob.com)</title>
    </head>
    <body>
    <form action="GetServlet" method="GET">
    网址名：<input type="text" name="name">
    <br />
    网址：<input type="text" name="url" />
    <input type="submit" value="提交" />
    </form>
    </body>
    </html>

## 使用表单的POST方法实例

    <form action="GetServlet" method="POST">

html的话就是改变一下method

    package com.test.helloservlet;

    import java.io.IOException;
    import java.io.PrintWriter;

    import javax.servlet.ServletException;
    import javax.servlet.annotation.WebServlet;
    import javax.servlet.http.HttpServlet;
    import javax.servlet.http.HttpServletRequest;
    import javax.servlet.http.HttpServletResponse;

    // Get方法向页面请求发送已编码的用户信息。页面和已编码的信息用?字符分割
    // http://www.test.com/hello?key1=value&key2=value

    // 使用Servlet读取表单数据
    // get

    /**
    * Servlet implementation class GetServlet
    */
    @WebServlet("/GetServlet")
    public class GetServlet extends HttpServlet {
        private static final long serialVersionUID = 1L;

        /**
        * @see HttpServlet#HttpServlet()
        */
        public GetServlet() {
            super();
            // TODO Auto-generated constructor stub
        }

        /**
        * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
        *      response)
        */
        protected void doGet(HttpServletRequest request, HttpServletResponse response)
                throws ServletException, IOException {
            // TODO Auto-generated method stub
            // 设置响应内容系列
            response.setContentType("text/html;charset=UTF-8");
            
            // 对post过来的字符编码转换 处理乱码
            //request.setCharacterEncoding("UTF-8");
            
            
            PrintWriter out = response.getWriter();
            String title = "使用GET方法读取表单数据";
            
            // 这种方式也可以给post过来的字符编码转换
            String name =new String(request.getParameter("name").getBytes("ISO8859-1"),"UTF-8");
            
            String docType = "<!DOCTYPE html> \n";
            out.println(
                    docType + "<html>\n" + "<head><title>" + title + "</title></head>\n" + "<body bgcolor=\"#f0f0f0\">\n"
                            + "<h1 align=\"center\">" + title + "</h1>\n" + "<ul>\n" + "  <li><b>站点名</b>：" + name + "\n"
                            + "  <li><b>网址</b>：" + request.getParameter("url") + "\n" + "</ul>\n" + "</body></html>");

        }

        /**
        * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
        *      response)
        */
        protected void doPost(HttpServletRequest request, HttpServletResponse response)
                throws ServletException, IOException {
            // TODO Auto-generated method stub
            doGet(request, response);
        }

    }

代码的话要做一下请求头乱码处理

    request.setCharacterEncoding("UTF-8");

或者

    String name =new String(request.getParameter("name").getBytes("ISO8859-1"),"UTF-8");

## 将复选框数据传递到 Servlet 程序

> 加了新的servlet就需要重启tomcat

    <!DOCTYPE html>
    <html>
    <head>
    <meta charset="utf-8">
    <title>菜鸟教程(runoob.com)</title>
    </head>
    <body>
    <form action="CheckBox" method="POST" target="_blank">
    <input type="checkbox" name="runoob" checked="checked" /> 菜鸟教程
    <input type="checkbox" name="google"  /> Google
    <input type="checkbox" name="taobao" checked="checked" /> 淘宝
    <input type="submit" value="选择站点" />
    </form>
    </body>
    </html>

    package com.test.helloservlet;

    import java.io.IOException;
    import java.io.PrintWriter;

    import javax.servlet.ServletException;
    import javax.servlet.annotation.WebServlet;
    import javax.servlet.http.HttpServlet;
    import javax.servlet.http.HttpServletRequest;
    import javax.servlet.http.HttpServletResponse;

    /**
    * Servlet implementation class ReceiveCheckbox
    */
    @WebServlet("/ReceiveCheckbox")
    public class ReceiveCheckbox extends HttpServlet {
        private static final long serialVersionUID = 1L;
        
        /**
        * @see HttpServlet#HttpServlet()
        */
        public ReceiveCheckbox() {
            super();
            // TODO Auto-generated constructor stub
        }

        /**
        * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
        */
        protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            // 设置响应内容类型
            response.setContentType("text/html;charset=UTF-8");
            
            PrintWriter out=response.getWriter();
            String title= "读取复选框数据";
            String docType = "<!DOCTYPE html> \n";
            out.println(docType +
                "<html>\n" +
                "<head><title>" + title + "</title></head>\n" +
                "<body bgcolor=\"#f0f0f0\">\n" +
                "<h1 align=\"center\">" + title + "</h1>\n" +
                "<ul>\n" +
                "  <li><b>菜鸟按教程标识：</b>: "
                + request.getParameter("runoob") + "\n" +
                "  <li><b>Google 标识：</b>: "
                + request.getParameter("google") + "\n" +
                "  <li><b>淘宝标识：</b>: "
                + request.getParameter("taobao") + "\n" +
                "</ul>\n" +
                "</body></html>");
        }

        /**
        * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
        */
        protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
            // TODO Auto-generated method stub
            doGet(request, response);
        }

    }

设置对应的web.xml

    <servlet>
        <servlet-name>ReceiveCheckbox</servlet-name>
        <servlet-class>com.test.helloservlet.ReceiveCheckbox</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>ReceiveCheckbox</servlet-name>
        <url-pattern>/HelloServlet/ReceiveCheckbox</url-pattern>
    </servlet-mapping>

html的`checkbox`是通过`name="runoob"`来传递值的，所以在后台代码直接通过`request.getParameter("runoob")`获取

