package com.test.login.dao;

import java.util.List;

import com.test.login.entity.Person;

public interface PersonDao {

	// �����鼮��Ϣ
	public void save(Person person);

	// ����person idɾ����Ӧ�鼮
	public void delete(Integer bookid);

	// �����鼮��Ϣ
	public void update(Person person);

	// ��ѯ��������Ϣ
	public List<Person> getAllPerson();
}
