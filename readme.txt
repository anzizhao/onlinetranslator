这是在Linux系统下开发的一个在线翻译英语库。它使用百度和谷歌在线翻译引擎，能英汉互译。调用接口简单，具体使用可以参考onlinetranslate.cpp文件。


依赖：
该软件需要htmlcxx库来解释html，所以需要先编译安装htmlcxx库


编译：
	make SHARELIB

编译测试用例：

	运行测试：
	1. ./onlinetranslate  -h 
	Usage: 
	 onlinetranslate -s [language code] -d [language code] -f filename 
	 language code can be the value of  Auto, English, Chinese,Japanese

	2 ./onlinetranslate -s English -d  Chinese
	   输入英文单词， Contrl-D结束

	3 echo 要翻译句子或单词 | ./onlinetranslate -s 源语言 -d 目标语言 
	

安装与卸载：
	sudo make install 
	sudo make uninstall 


emacs插件：
	安装emacs插件，让emacs使用翻译功能（英译汉）.
	安装命令：
	make emacs_plugin 
	   
        重新启动emacs， 使用鼠标选择翻译内容，按f1键，即可得翻译结果。（效果图1）


ok,now then ,just all for yourself, have a good time (:  


如需要帮助可与我联系
邮箱：anzizhaoit@126.com 
