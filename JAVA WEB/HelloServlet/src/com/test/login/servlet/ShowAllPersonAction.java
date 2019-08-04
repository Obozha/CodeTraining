package com.test.login.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.test.login.dao.PersonDaoImpl;
import com.test.login.entity.Person;

/**
 * Servlet implementation class ShowAllPersonAction
 */
@WebServlet("/ShowAllPersonAction")
public class ShowAllPersonAction extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public ShowAllPersonAction() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		PersonDaoImpl personDaoImpl = new PersonDaoImpl();
		List<Person> list = personDaoImpl.getAllPerson();
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		String html = "<html>\n" + "<head><title>查看数据库</title></head>\n" + "<body bgcolor=\"#f0f0f0\">\n";
		html += "<table>";
		for (Person person : list) {
			html += "<tr>";
			html += "<td>" + person.getSno() + "</td>";
			html += "<td>" + person.getSname() + "</td>";
			html += "<td>" + person.getSsex() + "</td>";
			html += "<td>" + person.getTelephone() + "</td>";
			html += "<td>" + person.getSdept() + "</td>";
			html += "</tr>";
		}
		html += "</table></body></html>";
		response.getWriter().write(html);
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
