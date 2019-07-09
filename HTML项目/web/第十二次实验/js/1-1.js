
var selection=[0,0,0,0,0,0];
var inform_phone=[
	"iPhone 6 32GB 金色  移动联通电信4G",
	"OPPO R11 全网通 黑色版",
	"Apple iPhones 6s plus 32GB 金色 移动联通电信4G手机",
	"小米 红米手机4X 全网通版 2GB内存 16GB 香槟金",
	"小米 红米手机4A 全网通版 2GB内存 16GB 玫瑰金",
	"小米 红米手机4X 全网通版 2GB内存 16GB 樱花粉"
];

var inform_phone_p=[
	2576.00,
	2999.00,
	3898.00,
	699.00,
	599.00,
	699.00
]

function checkbox_sele(i,checkbox){
	if(checkbox.checked==true){
		selection[i-1]=1;
		console.log("您选中了"+i+"，i当前状态:",checkbox.checked);
	}else{
		selection[i-1]=0;
		console.log("您取消了"+i+"，i当前状态:",checkbox.checked);
	}
}

function btn_checkout(){
	var i;
	var msg="";
	for(i=0;i<6;i++){
		if(selection[i]==1){
			msg+=i+1+"-"+inform_phone[i]+",价格=¥"+	inform_phone_p[i]+"\n";
		}
	}
	if(msg!=""){
		alert(msg);
	}else{
		alert("购物车空");
	}
}

function btn_purchase(){
	var i,count=0,result=0;
	for(i=0;i<6;i++){
		if(selection[i]==1){
			result+=inform_phone_p[i];
			count++;
		}
	}
	alert("您一共买了"+count+"件，共"+result+"元")
}

function btn_clear(){
	var i;
	for(i=0;i<6;i++){
		selection[i]=0;
	}
	document.myform.sp1.checked=false;
	document.myform.sp2.checked=false;
	document.myform.sp3.checked=false;
	document.myform.sp4.checked=false;
	document.myform.sp5.checked=false;
	document.myform.sp6.checked=false;
	
}
