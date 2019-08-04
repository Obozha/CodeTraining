package com.test.login.dao;

import java.util.List;

import com.test.login.entity.Person;

public interface PersonDao {

	// 插入书籍信息
	public void save(Person person);

	// 按照person id删除对应书籍
	public void delete(Integer bookid);

	// 更新书籍信息
	public void update(Person person);

	// 查询所有人信息
	public List<Person> getAllPerson();
}
