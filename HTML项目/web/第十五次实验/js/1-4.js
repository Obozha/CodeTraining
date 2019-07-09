			var db;
			function initSQL(){
				var request=window.indexedDB.open("db_person","1");
				
				request.onerror=function(event){
					console.log("数据库打开报错");
					$("stat").innerHTML="Error";
					
				}
				
				request.onsuccess=function(event){
					db=request.result;
					console.log("数据库打开成功");
					$("stat").innerHTML="数据库已经连接";
					queryInfo_All();
				}
				
				request.onupgradeneeded=function(event){
					db=event.target.result;
					var objectStore=db.createObjectStore('person',{ autoIncrement: true });
					objectStore.createIndex('name','name',{unique:false});
					objectStore.createIndex('tele','tele',{unique:true});
				}
			}
			
			function insertInfo(){
				var request=db.transaction(['person'],'readwrite').objectStore('person').add({name:$("text_name").value,tele:$("text_num").value});
				request.onsuccess=function(event){
					console.log("数据写入成功");
				}
				request.onerror=function(event){
					console.log("数据写入失败");
				}
				queryInfo_All();
			}
			
			function delete_index(str){
				var objectStore=db.transaction(['person'],"readwrite").objectStore('person');
				var onstat=0;
				objectStore.openCursor().onsuccess=function(event){
				var cursor=event.target.result;
					if(cursor){
						if((cursor.value.name==$("text_name").value)&&(cursor.value.tele==$("text_num").value)){
							cursor.delete();
							alert("删除名字为 ："+cursor.value.name+"   电话为 ："+cursor.value.tele+"的对象");
						}else if((cursor.value.name==$("text_name").value)&&(""==$("text_num").value)){
							cursor.delete();
							alert("删除名字为 ："+cursor.value.name+"   电话为 ："+cursor.value.tele+"的对象");
						}else if((""==$("text_name").value)&&(cursor.value.tele==$("text_num").value)){
							cursor.delete();
							alert("删除名字为 ："+cursor.value.name+"   电话为 ："+cursor.value.tele+"的对象");
						}
						cursor.continue();
					}
				}
				queryInfo_All();
			}
			
			function update_index(){
				var objectStore=db.transaction(['person'],"readwrite").objectStore('person');
				objectStore.openCursor().onsuccess=function(event){
					var cursor=event.target.result;
					if(cursor){
						if(cursor.value.name==$("text_name").value){
							cursor.update({name:$("text_name").value,tele:$("text_num").value});
						}else if(cursor.value.tele==$("text_num").value){
							cursor.update({name:$("text_name").value,tele:$("text_num").value});
						}else{
							console.log("修改失败");
//							alert("修改失败");	
						}
						cursor.continue();
					}
				}
				queryInfo_All();
			}
			
			function queryInfo_All(){
				console.log("查询全部");
				$("display").innerHTML="名字:			电话:\n";
				var objectStore=db.transaction(['person'],"readwrite").objectStore('person');
				var str="";
				objectStore.openCursor().onsuccess=function(event){
					var cursor=event.target.result;
					if(cursor){
						console.log(cursor.value.name);
						console.log(cursor.value.tele);
						cursor.continue();
						$("display").innerHTML+=cursor.value.name+"  ————  "+cursor.value.tele+"\n";
					}
				}
			}
			
			function queryInfo_One(){
				console.log("查询一个");
				var flag=1;
				var initStr="名字:			电话:";
				$("display").innerHTML=initStr+"\n";
				var objectStore=db.transaction(['person'],"readwrite").objectStore('person');
				var str="";
				objectStore.openCursor().onsuccess=function(event){
					var cursor=event.target.result;
					if(cursor){
						console.log(cursor.value.name);
						console.log(cursor.value.tele);
						if( (cursor.value.name==$("text_name").value) && (cursor.value.tele==$("text_num").value) ){
							$("display").innerHTML+=cursor.value.name+"  ————  "+cursor.value.tele+"\n";
						}else if( ( $("text_name")=="" ) && (cursor.value.tele==$("text_num").value) ){
							$("display").innerHTML+=cursor.value.name+"  ————  "+cursor.value.tele+"\n";
						}else if( (cursor.value.name==$("text_name").value) && (""==$("text_num").value ) ){
							$("display").innerHTML+=cursor.value.name+"  ————  "+cursor.value.tele+"\n";
						}else if($("text_name").value=="" && $("text_num").value==""){
							queryInfo_All();
						}	
						cursor.continue();
					}
				}
			}
			
//			function removeInfo(){
//				var request=db.transaction(['person'],'readwrite').objectStore('person').delete($("name"));
//				request.onsuccess=function(event){
//					console.log("数据删除成功");
//				}
//			}
			
			function $(id){
				return document.getElementById(id);
			}