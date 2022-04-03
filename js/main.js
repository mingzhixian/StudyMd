//获取url参数
function getQueryVariable(variable) {
	var query = window.location.search.substring(1);
	var vars = query.split("&");
	for (var i = 0; i < vars.length; i++) {
		var pair = vars[i].split("=");
		if (pair[0] == variable) {
			return "/"+pair[1];
		}
	}
	//为空情况
	return ("/README.md");
}

//获取文章名
var artUrl = decodeURIComponent(getQueryVariable("art"));

//获取文章markdown文件
$.ajax({
	url: SiteUrl() + artUrl,
	type: "get",
}).done(function (output) {
	//解析文章并填充文章名以及文章
	var converter = new showdown.Converter();
	text = output;
	if (artUrl == "/README.md") {
		artUrl = SiteTitle
	};
	$("#articleTitle").html(artUrl);
	$("#articleBody").html(converter.makeHtml(text));
	directory();
}).fail(function () {
	$.ajax({
		url: SiteUrl() + "/README.md",
		type: "get",
	}).done(function (output) {
		//解析文章并填充文章名以及文章
		var converter = new showdown.Converter();
		text = output;
		if (artUrl == "/README.md") {
			artUrl = SiteTitle
		};
		$("#articleTitle").html(artUrl);
		$("#articleBody").html(converter.makeHtml(text));
		directory();
	}).fail(function (xhr, status) {
		console.log("error,can not find article!");
	});
});

//自动生成目录
function directory() {
    $("#articleBody").find("h1,h2,h3,h4,h5,h6").each(function (i, item) {
        var tag = $(item).get(0).localName;
        $(item).attr("id", "p" + i);
        $("#articleContent").append('<p><a class = "title-' + tag + ' anchor-link" onclick="GoTo(\'#p' + i + '\')" >' + $(this).text() + '</a></p>');
    });
    $(".title-h1").css("margin-left", 0);
    $(".title-h2").css("margin-left", 10);
    $(".title-h3").css("margin-left", 20);
    $(".title-h4").css("margin-left", 30);
    $(".title-h5").css("margin-left", 40);
    $(".title-h6").css("margin-left", 50);
}

//点击目录滚动到对应位置
function GoTo(link) {
    $("html,body").animate({scrollTop: $(link).offset().top}, 400);
}