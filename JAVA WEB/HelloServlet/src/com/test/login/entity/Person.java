package com.test.login.entity;

public class Person {
	private String sno;
	private String sname;
	private String ssex;
	private String sdept;
	private String telephone;

	public String getSno() {
		return sno;
	}

	public void setSno(String sno) {
		this.sno = sno;
	}

	public String getSname() {
		return sname;
	}

	public void setSname(String sname) {
		this.sname = sname;
	}

	public String getSsex() {
		return ssex;
	}

	public void setSsex(String ssex) {
		this.ssex = ssex;
	}

	public String getSdept() {
		return sdept;
	}

	public void setSdept(String sdept) {
		this.sdept = sdept;
	}

	public String getTelephone() {
		return telephone;
	}

	public void setTelephone(String telephone) {
		this.telephone = telephone;
	}

	@Override
	public String toString() {
		return "Person [sno=" + sno + ", sname=" + sname + ", ssex=" + ssex + ", sdept=" + sdept + ", telephone="
				+ telephone + "]";
	}

	public Person(String sno, String sname, String ssex, String sdept, String telephone) {
		super();
		this.sno = sno;
		this.sname = sname;
		this.ssex = ssex;
		this.sdept = sdept;
		this.telephone = telephone;
	}

}
