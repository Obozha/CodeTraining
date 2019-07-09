<%@LANGUAGE="JAVASCRIPT" CODEPAGE="65001"%>
<% 
var x1,x2,x3,x4,x5
	x1=Request("username")
	x2=Request("pwd1")
	x3=Request("email")
	x4=Request("date1")
	x5=Request("salary")
    
with (Response){
  ContentType="text/html"
  Charset="utf-8" 
  Write("<table width='400' border='1'><tr><td>用户名</td>")
  Write("<td>"+x1+"</td></tr>")
  Write("<tr><td>密码</td>")
  Write("<td>"+x2+"</td></tr>")
  Write("<tr><td>电子邮件</td>")
  Write("<td>"+x3+"</td></tr>")
  Write("<tr><td>毕业日期</td>")
  Write("<td>"+x4+"</td></tr>")
  Write("<tr><td>期望月薪</td>")
  Write("<td>"+x5+"</td></tr>")
}
%>