$(function() {
	var page = 1;
	$vlist = $(".v_content_list");
	$("span.next").click(function() {
		if (!$vlist.is(":animated")) {
			if (page == 4) {
				$("#navi li:first").addClass("current").siblings().removeClass("current");
				$vlist.animate({
					left: '+=' + $(".v_content").width() * (page - 1)
				});
				page = 1;
			} else {
				page++;
				$("#navi li:eq(" + (page - 1) + ")").addClass("current").siblings().removeClass("current");
				$vlist.animate({
					left: '-=' + $(".v_content").width()
				}, "fast");
				// alert(page);
			}
		}
	});
	$("span.prev").click(function() {
		if (!$vlist.is(":animated")) {
			if (page == 1) {
				$("#navi li:last").addClass("current").siblings().removeClass("current");
				$vlist.animate({
					left: '-=' + $(".v_content").width() * 3
				});
				page = 4;
			} else {
				page--;
				$("#navi li:eq(" + (page - 1) + ")").addClass("current").siblings().removeClass("current");
				$vlist.animate({
					left: '+=' + $(".v_content").width()
				});
			}
		}
	});
})
