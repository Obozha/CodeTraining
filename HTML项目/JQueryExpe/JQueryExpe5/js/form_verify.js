$(function() {
	
	$("input").blur(function() {
		// 验证用户名
		if ($(this).is("#input_username")) {
			// alert();
			if (this.value=="" || (this.value!="" && !/^[a-zA-Z0-9]{6,8}$/.test(this.value))  ) {
				$("#l_username_error").css("display", "block");
			
			} else {
					$("#l_username_error").css("display", "none");
			}
		}
		if ($(this).is("#useremail")) {
			if (this.value == "" || (this.value != "" && !/.+@.+\.[a-zA-Z]{2,4}$/.test(this.value))) {
				$("#l_email_error").css("display", "block");
			} else {
				$("#l_email_error").css("display", "none");
			}
		}
		if ($(this).is("#input_realname")) {
			if (this.value == "" || (this.value != "" && !/^[\u4E00-\u9FA5]{2,4}$/.test(this.value))) {
				$("#l_real_name").css("display", "block");
			} else {
				$("#l_real_name").css("display", "none");
			}
		}
		if ($(this).is("#input_userpwd")) {
			if (this.value.trim() == "") {
				$("#l_pwd_error").css("display", "block");
				$("#input_c_userpwd").blur();
			} else {
				$("#l_pwd_error").css("display", "none");
				$("#input_c_userpwd").blur();
			}

		}
		if ($(this).is("#input_c_userpwd")) {
			if ($(this).val() == "" || $(this).val() != $("#input_userpwd").val()) {
				$("#l_c_pwd_error").css("display", "block");
			} else {
				$("#l_c_pwd_error").css("display", "none");
			}
		}
	});
	$("#btn_submit").click(function(e) {
		$("input").blur();
		if ($("#l_username_error").is(":visible") || $("#l_email_error").is(":visible") || $("#l_real_name").is(
				":visible") || $("#l_pwd_error").is(":visible") || $("#l_c_pwd_error").is(":visible")) {
			$("#myModalLabel").text("验证失败");
			$("#myModal").modal('show');
			$(".modal-body").html(
			"1.用户名需要6位到8位的字母或者数字<br/>"
		+	"2.密码要和验证密码一致<br/>"
		+	"3.E-mail格式要符合规范<br/>"
		+	"4.真实姓名采用2到4个汉字的中文形式<br/>"
		+	"以上符合要求就能通过验证了！亲"
			);
		} else {
			$("#myModalLabel").text("验证成功！");
			$("#myModal").modal('show');
			$(".modal-body").text("全部正确！已经提交表单哦");
		}
	});
	
	$("#btn-reset").click(function(){
		$("label").css("display", "none");
	});
});
