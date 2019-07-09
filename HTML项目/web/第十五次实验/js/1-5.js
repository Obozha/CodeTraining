var count=0;

function $(id){
	return document.getElementById(id);
}

function judgeEnvironment(){
	if(typeof(Storage)!=="undefined"){
		// 支持 	
		mode=0;
		$("initStat").innerHTML="Yes";
		find();
	}else{
		$("initStat").innerHTML="No";
	}

}
function save(){
	localStorage.setItem($("text_name").value,$("text_num").value);
	find();
}

function find(){
	console.log("find");
	var result="姓名			电话\n";
	for(var i=0;i<localStorage.length;i++){
		result+=localStorage.key(i)+"			"+localStorage.getItem(localStorage.key(i)) + "\n";
	}
	console.log(result);
	$("display").innerHTML=result;
}

function remove_data(){
	for(var i=0;i<localStorage.length;i++){
		if(localStorage.key(i)==$("text_name").value&& localStorage.getItem(localStorage.key(i))==$("text_num").value ){
			localStorage.removeItem(localStorage.key(i));
		}else if(localStorage.key(i)==$("text_name").value&&$("text_num").value==""){
			localStorage.removeItem(localStorage.key(i));
		}else if($("text_name").value==""&&localStorage.getItem(localStorage.key(i))==$("text_num").value){
			localStorage.removeItem(localStorage.key(i));
		}
	}
	find();
}

function query_data(){
	console.log("find");
	var result="姓名			电话\n";
	for(var i=0;i<localStorage.length;i++){
		if(localStorage.key(i)==$("text_name").value&& localStorage.getItem(localStorage.key(i))==$("text_num").value ){
			result+=localStorage.key(i)+"			"+localStorage.getItem(localStorage.key(i)) + "\n";
		}else if(localStorage.key(i)==$("text_name").value&&$("text_num").value==""){
			result+=localStorage.key(i)+"			"+localStorage.getItem(localStorage.key(i)) + "\n";
		}else if($("text_name").value==""&&localStorage.getItem(localStorage.key(i))==$("text_num").value){
			result+=localStorage.key(i)+"			"+localStorage.getItem(localStorage.key(i)) + "\n";
		}else if($("text_name").value==""&&$("text_num").value==""){
			find();
			return;
		}
	}
	console.log(result);
	$("display").innerHTML=result;
}
