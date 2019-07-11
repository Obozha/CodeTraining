package com.test.login.service;

import java.sql.Connection;
import java.sql.SQLException;
import com.test.login.dao.UsersDao;
import com.test.login.entity.Users;
import com.test.login.utils.JdbcUtils;

public class UserService {
	public Users login(String name, String pwd) {
		Connection conn = null;
		Users users = null;
		try {
			conn = JdbcUtils.getConnection();
			conn.setAutoCommit(false);
			UsersDao uDao = new UsersDao();
			users = uDao.selectByNameAndPwd(name, pwd);
			conn.commit();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			try {
				conn.rollback();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} finally {
			JdbcUtils.close(null, null, conn);
		}
		return users;
	}
}
