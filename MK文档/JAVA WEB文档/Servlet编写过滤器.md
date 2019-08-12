# Servlet 编写过滤器

Servlet过滤器可以动态拦截请求和响应，以变换或使用包含在请求或响应中的消息。

可以将一个或多个Servlet过滤器附加到一个Servlet或一组Servlet。Servlet过滤器也可以附加到JavaServer Pages（JSP）文件和HTML页面。调用Servlet前调用所有附加的Servlet过滤器。

Servlet过滤器是可用于Servlet编程的Java类，可以实现以下目的：

* 在客户端请求访问后端资源，拦截这些请求。
* 在服务器响应发送回客户端之前，处理这些响应。

根据规范建议的各种类型的过滤器：

* 身份验证过滤器（Authentication Filters）
* 数据压缩过滤器（Data compression Filters）
* 加密过滤器（Encryption Filters）
* 触发资源访问事件过滤器
* 图像转换过滤器（Image Conversion Filter）
* 日志记录和审核过滤器（Logging and Auditing Filters）
* MIME-TYPE链过滤器（MIME-TYPE Chain Filters）
* 标记化过滤器（Tokenizing Filters）
* XSL/T过滤器（XSL/T Filters） 转换XML内容。

过滤器通过Web部署描述符（web.xml）中的xml标签来声明，然后映射到应用程序的部署描述符中的Servlet名称或URL模式。