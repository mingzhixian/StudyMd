//修改网站标题
document.getElementsByTagName("title")[0].innerText = SiteTitle();

//获取url参数
function getQueryVariable(variable) {
	var query = window.location.search.substring(1);
	var vars = query.split("&");
	for (var i = 0; i < vars.length; i++) {
		var pair = vars[i].split("=");
		if (pair[0] == variable) {
			return "./" + pair[1];
		}
	}
	//为空情况
	return ("./README.md");
}

//获取文章名
function getTitle(variable) {
	return variable.substring(variable.lastIndexOf("/") + 1, variable.lastIndexOf(".md"));
}

//获取文章名
var artUrl = decodeURIComponent(getQueryVariable("art"));

//获取文章markdown文件
$.ajax({
	url: artUrl,
	type: "get",
}).done(function (output) {
	//解析文章并填充文章名以及文章
	var converter = new showdown.Converter();
	if (artUrl == "./README.md") {
		$("#articleTitle").html(SiteTitle());
	} else {
		$("#articleTitle").html(getTitle(artUrl));
	}
	$("#articleBody").html(converter.makeHtml(output));
	directory();
	SetImg();
}).fail(function () {
	$.ajax({
		url: "./README.md",
		type: "get",
	}).done(function (output) {
		var converter = new showdown.Converter();
		$("#articleTitle").html(SiteTitle());
		$("#articleBody").html(converter.makeHtml(output));
		directory();
		SetImg();
	}).fail(function () {
		console.log("error,can not find article!");
	});
});

//自动生成目录
function directory() {
	$("#articleBody").find("h1,h2,h3,h4,h5,h6").each(function (i, item) {
		var tag = $(item).get(0).localName;
		$(item).attr("id", "p" + i);
		$("#articleContent").append('<p class = "contentTitle"><a class = "contentTitle-' + tag + '" onclick="GoTo(\'#p' + i + '\')" >' + $(this).text() + '</a></p>');
	});
	$(".contentTitle-h1").css({
		"margin-left": 0,
		"font-size": 16,
		"line-height": 24,
		"height": 24
	});
	$(".contentTitle-h2").css({
		"margin-left": 30,
		"font-size": 13,
		"line-height": 21,
		"height": 21
	});
	$(".contentTitle-h3").css({
		"margin-left": 60,
		"font-size": 10,
		"line-height": 18,
		"height": 18
	});
	$(".contentTitle-h4").css({
		"margin-left": 90,
		"font-size": 9,
		"line-height": 15,
		"height": 15
	});
	$(".contentTitle-h5").css({
		"margin-left": 120,
		"font-size": 6,
		"line-height": 12,
		"height": 12
	});
	$(".contentTitle-h6").css({
		"margin-left": 150,
		"font-size": 3,
		"line-height": 9,
		"height": 9
	});
}

//点击目录滚动到对应位置
function GoTo(link) {
	$("html,body").animate({
		scrollTop: $(link).offset().top
	}, 400);
}

//处理图片显示问题
function SetImg() {
	$("#articleBody").find("img").each(function (i, item) {
		var url = $(item).attr("src");
		if (url.substring(0, 2) == "./") {
			url = artUrl.substring(0, artUrl.lastIndexOf("/") + 1) + url.substring(2);
			$(item).attr("src", url);
		}
	})
}