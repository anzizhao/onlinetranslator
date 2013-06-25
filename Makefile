# Time-stamp: "2013-01-03 11:25:07 Thursday by anzizhao"

CC = g++ 
CFLAGS := -g -W 


SUBDIR :=  html http manage 

# INCLUDE = $(shell ls html/*.hpp   http/*.h http/*.hpp manage/*.hpp)
# INCLUDE = `for f in ${SUBDIR}; do filelist="$${filelist} $(shell ls $$${f}/*.h $$${f}/*.hpp)"; done ; echo $${filelist} `
# INCLUDE = $(foreach f, ${SUBDIR}, $(shell ls  ${f}/*.hpp  ${f}/*.h) )

# SOURCE = html/baiduEngine.cpp html/baiduparser.cpp html/json_array_node.cpp html/jsonparser.cpp  http/sock.cpp   http/httpclient.cpp  manage/baidutranslate.cpp baidu.cpp

#SOURCE = $(shell ls html/*.cpp http/*.cpp manage/*.cpp )
SOURCE =  $(foreach f, ${SUBDIR}, $(shell ls  ${f}/*.cpp ) )


# OBJ = baiduEngine.o baiduparser.o json_array_node.o jsonparser.o   sock.o  baidutranslate.o httpclient.o 

# OBJ =   `for srcfile in ${SOURCE}; do objfiles="$${objfiles} $${srcfile%%.*}.o"; done ; echo $${objfiles}`
OBJ = ${SOURCE:%.cpp=%.o}
SHARE_OBJ = ${SOURCE:%.cpp=%.share.o}
LIB = libtranslate.so








all:	debug    

.PHONY:  all test  debug  install uninstall clean cleanshareobj cleanobj lib SHARE



debug:  CFLAGS += -D_debug 	
debug:	onlinetranslate 



# ${OBJ}:${SOURCE} 


# 	${CC} -c ${CFLAGS}  $< -o $@ 



# SHARE:	${SOURCE}
# 	${foreach sobj, ${SHARE_OBJ}, ${ shell ${CC} ${CFLAGS} -c -fPIC -o ${sobj} ${sobj:%.share.o=%.cpp}}}
# 	for sobj in ${SHARE_OBJ};\
# 	do (${CC} ${CFLAGS} -c -fPIC $${sobj%.share*}.cpp -o $${sobj});\
# 	done ;







${LIB}:	${SHARE_OBJ}
	${CC} -shared ${SHARE_OBJ} -o $@ 	


onlinetranslate:	${LIB}   onlinetranslate.cpp 
	${CC} ${CFLAGS}   onlinetranslate.cpp -o $@ -I include/  -L lib/ -lhtmlcxx  -l${LIB:lib%.so=%}


onlinetranslate_a:	${SOURCE} ${OBJ}  onlinetranslate.cpp 
	${CC} ${CFLAGS} ${OBJ}  onlinetranslate.cpp -o $@ -I include/  -L lib/ -lhtmlcxx 


lib:	${LIB}


install:	${LIB}
	cp ${LIB} /usr/local/lib/${LIB}
	cp onlinetranslate /usr/local/bin/
	ldconfig 



uninstall:
	if [ -e /usr/local/lib/libtranslate.so ] ;\
		then rm -f /usr/local/lib/libtranslate.so ;\
	fi  
	if [ -e /usr/local/bin/onlinetranslate ] ;\
		then rm -f /usr/local/bin/onlinetranslate ;\
	fi  
	ldconfig 



clean:	cleanobj  cleanshareobj 
	rm -f  onlinetranslate  ${LIB}


cleanshareobj:	
	rm -f ${SHARE_OBJ}

cleanobj:
	rm -f ${OBJ}

install_home:	onlinetranslate
	cp onlinetranslate ~/bin

uninstall_home:		~/bin/onlinetranslate
	rm  -f 	~/bin/onlinetranslate


test:
#	echo ${INCLUDE} 
	echo ${SOURCE}
	echo ${OBJ}





# object 
html/%.o:html/%.cpp ${shell ls html/*.cpp}
	${CC} ${CFLAGS} -c $< -o $@

http/%.o:http/%.cpp ${shell ls http/*.cpp}
	${CC} ${CFLAGS} -c  $< -o $@

manage/%.o:manage/%.cpp ${shell ls manage/*.cpp}
	${CC} ${CFLAGS} -c  $< -o $@



# share object 
html/%.share.o:html/%.cpp ${shell ls html/*.cpp}
	${CC} ${CFLAGS} -c -fPIC $< -o $@

http/%.share.o:http/%.cpp ${shell ls http/*.cpp}
	${CC} ${CFLAGS} -c -fPIC $< -o $@
manage/%.share.o:manage/%.cpp ${shell ls manage/*.cpp}
	${CC} ${CFLAGS} -c -fPIC $< -o $@
