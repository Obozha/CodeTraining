package com.test.login.entity;

public class Users {
	private String username;
	private String userpwd;
	public Users(String username, String userpwd) {
		super();
		this.username = username;
		this.userpwd = userpwd;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getUserpwd() {
		return userpwd;
	}
	public void setUserpwd(String userpwd) {
		this.userpwd = userpwd;
	}
	
	
}
