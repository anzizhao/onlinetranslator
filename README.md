onlnetranslator
===============

this is a online translation library. Through the simple the interface , you can use the powerful online translation 
engine, such as baidu translate engine.






  this sofeware is developed under the Linux system, which is used for translation . It use the baidu translation engine and the google , and now support english
 and chinese translate each other. the library API is very  simple . In detail , you
can refer to the file  named onlinetranslate.cpp.

dependence: 
	    1. use htmlcxx library to parse html file 
	    2. use libjson library to parse json file 
	    in the dep directory, you will find these two sofeware source code. the
	    version of the htmlcxx is 0.7.3, and the libjson is 7.6. you should 
	    compile and install them first . 

compilation:    
		make 

install :
	      sudo  make install 
		
unistall:
	      sudo make uninstall 

useage:
	after  installed  this sofeware into your system, you can use it in the 
terminal.
	1.  ot  -h ( show  help manual ) 
	Usage: 
	 ot -s [language code] -d [language code] -f filename 
	 language code can be the value of  au, en, zh ,Ja
	 au -- auto en -- english zh -- simple chinese ja -- japanese 

	2. ot -s en -d zh ( english to chinese )
	   ot -s zh -d en ( chinese to english )
	   after knock the command, you  will be required to input words, and 
	   finished with Contrl-D.  
	3. use the pipe for input . 
	   echo $sentence | ot -s en -d zh 

install emacs plugin:
	now you can use it in emacs. 
	At first, you should sure  your emacs has install auto-complete plugin.
	and then , use command ' make emacs_plugin' to install the emacs plugin. 
	after that, restart your emacs.  Now you can select area to translate ,
	and press f1 key ( emacs_plugin.png ). 
	note, now this plugin just support the translation of english to chinese.



there are many tests should be done . So welcome to have a try. and  feedback your 
question and advise. you can contract me  with the email. My email is 
anzizhaoit@126.com 


Ok, just for yourself, and have a good time. 
