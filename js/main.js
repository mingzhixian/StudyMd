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
	}).fail(function (xhr, status) {
		console.log("error,can not find article!");
	});
});