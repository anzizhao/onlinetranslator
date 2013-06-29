

	这是在Linux系统下开发的一个在线翻译英语库。它使用百度和谷歌在线翻译引擎，能英汉互译。调用接口简单，具体使用可以参考onlinetranslate.cpp文件。
依赖：
   1. 使用htmlcxx库来解释html页面
   2. 使用libjson库解释json文件
   在dep/目录包含htmlcxx和libjson的源码，htmlcxx的版本是0.7.3， libjson的版本是7.6
   请先自行编译安装. 

编译：
	

编译测试用例：

	运行测试：
	1. ./ot  -h 
	Usage: 
	 ot -s [language code] -d [language code] -f filename 
	 language code can be the value of  au, en, zh ,Ja
	 
	 au -- auto en -- english zh -- simple chinese ja -- japanese 
	2 ./ot  -s en  -d  zh 
	   输入英文单词， Contrl-D结束

	3 echo 要翻译句子或单词 | ot -s 源语言 -d 目标语言 
	

安装与卸载：
	sudo make install 
	sudo make uninstall 


emacs插件：
	依赖： 需要emacs的auto-complete插件
	安装命令：
	make emacs_plugin 
	   
        重新启动emacs， 使用鼠标选择翻译内容，按f1键，即可得翻译结果。（emacs_plugin.png ）


ok,now then ,just all for yourself, have a good time (:  


如需要帮助可与我联系
邮箱：anzizhaoit@126.com 
