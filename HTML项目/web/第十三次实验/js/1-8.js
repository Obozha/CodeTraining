function $(id) {
	return document.getElementById(id);
}

function checkNum() {
	var isRight = true;
	var user = $("user").value;
	var hint_n = $("hint_n");
	if(user.trim() == "") {
		isRight = false;
		hint_n.innerHTML = "卡号不能为空"
	} else if(user.length != 10) {
		isRight = false;
		hint_n.innerHTML = "卡号长度必须为10";
	} else if(!isNaN(user)) {
		isRight = false;
		hint_n.innerHTML = "卡号不全为数字";
	} else if(!user.match("^[A-Za-z0-9]+$")) {
		hint_n.innerHTML = "卡号有非法字符";
	} else {
		hint_n.innerHTML = ""
	}
	return isRight;
}

function checkPwd() {
	var isRight = true;
	var pwd = $("pwd").value;
	var hint_p = $("hint_p");
	if(pwd.trim() == "") {
		isRight = false;
		hint_p.innerHTML = "密码不能为空";
	} else if(!(pwd.length > 8 && pwd.length < 15)) {
		isRight = false;
		hint_p.innerHTML = "密码长度必须大于8小于15";
	} else if(!isNaN(pwd)) {
		isRight = false;
		hint_p.innerHTML = "密码不能全为数字";
	} else if(!pwd.match("^[A-Za-z0-9]+$")) {
		hint_p.innerHTML = "密码格式错误";
	} else {
		hint_p.innerHTML = "";
	}
	return isRight;
}

function checkPwd2() {
	var isRight = true;
	var pwd_ = $("pwd_").value;
	var hint_p = $("hint_p");
	if(pwd_.trim() == "") {
		isRight = false;
		hint_p2.innerHTML = "重置密码不能为空";
	} else if(pwd_ != $("pwd").value) {
		isRight = false;
		hint_p2.innerHTML = "重置密码与密码不一致";
	} else {
		isRight = true;
		hint_p2.innerHTML = "";
	}
	return isRight;
}

function checkqw() {
	var isRight = true;
	var fillqw = $("fillqw").value;
	var hint_qw = $("hint_qw");
	if(fillqw == "") {
		isRight = false;
		hint_qw.innerHTML = "qq微信不能为空";
	} else if(!fillqw.match("^[A-Za-z0-9]+$")) {
		hint_qw.innerHTML = "格式错误！";
	} else {
		hint_qw.innerHTML = "";
	}
	return isRight;
}

function cs() {
	if(checkNum() && checkPwd() && checkPwd2() && checkqw()) {
		alert("卡号：" + $("user").value + "\n" + "密码：" + $("pwd").value + "\n" + "QQ/微信：" + $("fillqw").value)
		return true;
	} else {
		alert("检查输入选项是否错误");
		return false;
	}
}

function form_reset() {
	$("user").value = "";
	$("pwd").value = "";
	$("pwd_").value = "";
	$("fillqw").value = "";
}

function regex() {
	//	var regex = /^(?!(?:\d+|[a-zA-Z]+|[\da-z]+|[\dA-Z])$)[\da-zA-Z]{6,}$/;
	var regex = "^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,15}$ ";
	var hint_n = $("hint_n");
	if($("user").value.match(regex)) {
		console.log("符合规定");
	} else {
		console.log("不符合规定");
	}
}
//[\w!#$%&'*+/=?^_`{|}~-]+(?:\.[\w!#$%&'*+/=?^_`{|}~-]+)*@(?:[\w](?:[\w-]*[\w])?\.)+[\w](?:[\w-]*[\w])?