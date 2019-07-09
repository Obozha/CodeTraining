function $(id){
	console.log(id);	
	return document.getElementById(id);
}

function userRegister(){
	// 用户注册
	var userName=$("userName").value; // 注意$("")
	var passWord=$("passWord").value; 
	// 这里的值不放全局变量的原因是，每一次提交的值都不一样
	var confirm=$("CpassWord").value;
	var isRight=true;
	if(userName==""||passWord==""){
		isRight=false;
		alert("用户名或者密码为空");
	}else if(userName.length<6){
		isRight=false;
		alert("用户名长度小于6位");
	}else if(passWord.length<6){
		isRight=false;
		alert("密码长度小于6位");
	}else if(passWord!=confirm){
		isRight=false;
		alert("密码和密码确认不一致");
	}else{
		isRight=true;
	}
	return isRight;
}

function resetForm(){
	var flag=confirm("确定要重置数据吗？");
	if(flag=true){
		$("userName").value="";
		$("passWord").value="";
		$("CpassWord").value="";
	}
	// 重置表单
}
