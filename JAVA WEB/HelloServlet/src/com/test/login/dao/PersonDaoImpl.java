package com.test.login.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.sun.swing.internal.plaf.basic.resources.basic;
import com.test.login.entity.Person;
import com.test.login.utils.JdbcUtils;

public class PersonDaoImpl extends JdbcUtils implements PersonDao {

	@Override
	public void save(Person person) {
		this.executesql("insert into student values(?,?,?,?,?)", person.getSno(), person.getSname(), person.getSdept(),
				person.getSsex(), person.getTelephone());
	}

	@Override
	public void delete(Integer bookid) {
		this.executesql("Delete from tb_book where bookid=?", bookid);
	}

	@Override
	public void update(Person person) {
		// TODO ¸üÐÂ
	}

	@Override
	public List<Person> getAllPerson() {
		List<Person> list = new ArrayList<Person>();
		Connection conn = null;
		PreparedStatement ps = null;
		ResultSet rSet;
		try {
			conn = getConnection();
			ps = conn.prepareStatement("select * from student");
			rSet = ps.executeQuery();
			while (rSet.next()) {
				Person p = new Person(rSet.getString(1), rSet.getString(2), rSet.getString(4), rSet.getString(3),
						rSet.getString(5));
				System.out.println(p.toString());
				list.add(p);
			}
			return list;
		} catch (RuntimeException | SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return list;
	}
}
