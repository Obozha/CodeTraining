package com.test.login.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.test.login.entity.Users;
import com.test.login.utils.JdbcUtils;

public class UsersDao {
	public Users selectByNameAndPwd(String name, String pwd) {
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rs = null;
		Users user = null;

		try {
			conn = JdbcUtils.getConnection();
			String sql = "select * from account where username=? and pwd=?";
			ps = conn.prepareStatement(sql);
			ps.setString(1, name);
			ps.setString(2, pwd);
			rs = ps.executeQuery();
			while (rs.next()) {
				user = new Users(rs.getString(1), rs.getString(2));
			}
		} catch (RuntimeException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return user;
	}

	public static void main(String[] args) {
		UsersDao us=new UsersDao();
		Users users=us.selectByNameAndPwd("zhangsan", "123");
		System.out.println(users.getUsername());
		System.out.println(users.getUserpwd());
	}
}
