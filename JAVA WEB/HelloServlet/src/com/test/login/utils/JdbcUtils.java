package com.test.login.utils;

import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class JdbcUtils {
	// url
	private static String url = null;
	// user
	private static String user = null;
	// password
	private static String password = null;
	// 驱动程序类
	private static String driverClass = null;

	/**
	 * 相对路径： . 这个点代表当前目录。当前目录本质上是java命令运行的目录 java项目： 在ecplise中，当前目录指向项目的根目录。 web项目：
	 * 当前目录指向%tomcat%/bin目录 1)结论： 在web项目不能使用相对路径 web项目中加载配置文件：
	 * ServletContext.getRealPath() / getResourceAsStream()
	 * 这种方式对于jdbcUtil这个工具而言，放到java项目中找不到ServletContext对象，不通用的！
	 * 2)不能使用ServletContext读取文件 3）使用类路径方式读取配置文件
	 */
	// 获取类的对象
	static {
		// 注册驱动程序
		Properties prop = new Properties();
		// 构造输入流
		Class clazz = JdbcUtils.class;
		InputStream in = clazz.getResourceAsStream("/jdbc.properties");
		try {

			// Class.forName 方法的作用，就是初始化给定的类。而我们给定的 MySQL 的 Driver 类中，它在静态代码块中通过 JDBC 的
			// DriverManager 注册了一下驱动。我们也可以直接使用 JDBC 的驱动管理器注册 mysql 驱动，从而代替使用 Class.forName。

			prop.load(in);
			url = prop.getProperty("url");
			user = prop.getProperty("user");
			password = prop.getProperty("password");
			driverClass = prop.getProperty("driverClass");
			Class.forName(driverClass);
			System.out.println(url + " " + user + " " + password + " " + driverClass);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	public static Connection getConnection() throws RuntimeException, SQLException {
		Connection conn = DriverManager.getConnection(url, user, password);
		return conn;
	}

	public static void close(Statement stmt, Connection conn) {
		if (stmt != null) {
			try {
				stmt.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		if (conn != null) {
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public static void close(ResultSet rs, Statement stmt, Connection conn) {
		if (rs != null) {
			try {
				rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		if (stmt != null) {
			try {
				stmt.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		if (conn != null) {
			try {
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		try {
			System.out.println(JdbcUtils.getConnection());

			Connection connection = JdbcUtils.getConnection();
			System.out.println(connection);

		} catch (RuntimeException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
