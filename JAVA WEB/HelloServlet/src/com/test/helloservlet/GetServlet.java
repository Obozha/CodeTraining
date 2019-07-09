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
