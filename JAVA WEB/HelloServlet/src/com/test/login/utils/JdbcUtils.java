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
	// ����������
	private static String driverClass = null;

	/**
	 * ���·���� . ��������ǰĿ¼����ǰĿ¼��������java�������е�Ŀ¼ java��Ŀ�� ��ecplise�У���ǰĿ¼ָ����Ŀ�ĸ�Ŀ¼�� web��Ŀ��
	 * ��ǰĿ¼ָ��%tomcat%/binĿ¼ 1)���ۣ� ��web��Ŀ����ʹ�����·�� web��Ŀ�м��������ļ���
	 * ServletContext.getRealPath() / getResourceAsStream()
	 * ���ַ�ʽ����jdbcUtil������߶��ԣ��ŵ�java��Ŀ���Ҳ���ServletContext���󣬲�ͨ�õģ�
	 * 2)����ʹ��ServletContext��ȡ�ļ� 3��ʹ����·����ʽ��ȡ�����ļ�
	 */
	// ��ȡ��Ķ���
	static {
		// ע����������
		Properties prop = new Properties();
		// ����������
		Class clazz = JdbcUtils.class;
		InputStream in = clazz.getResourceAsStream("/jdbc.properties");
		try {

			// Class.forName ���������ã����ǳ�ʼ���������ࡣ�����Ǹ����� MySQL �� Driver ���У����ھ�̬�������ͨ�� JDBC ��
			// DriverManager ע����һ������������Ҳ����ֱ��ʹ�� JDBC ������������ע�� mysql �������Ӷ�����ʹ�� Class.forName��

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
