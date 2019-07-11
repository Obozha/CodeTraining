package com.test.login.entity;

public class Person {

	private String name;
	private String age;
	private String sex;
	private String dept;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAge() {
		return age;
	}

	public void setAge(String age) {
		this.age = age;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getDept() {
		return dept;
	}

	public void setDept(String dept) {
		this.dept = dept;
	}

	public Person(String name, String age, String sex, String dept) {
		super();
		this.name = name;
		this.age = age;
		this.sex = sex;
		this.dept = dept;
	}
}
