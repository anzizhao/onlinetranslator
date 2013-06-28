# Time-stamp: "2013-06-27 17:48:37 Thursday by anzizhao"

# compilation
CC = g++ 
CFLAGS := -g -W 
LIBDIRS := -L. -Ldep/htmlcxx/html/.libs -Ldep/libjson 
LIBS   := -ltranslate  -lhtmlcxx -ljson  
INCLUDES :=  -Idep/htmlcxx/html/   -Idep/libjson -Iinclude/ 
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

# program  setting 
PROGRAM := ot 
DLIB  := libtranslate.so
SLIB  := libtranslate.a 


all:	debug    

.PHONY:  all test  debug  install uninstall clean cleanshareobj cleanobj lib SHARE



debug:  CFLAGS += -D_DEBUG  	
debug:	${PROGRAM} 



# ${OBJ}:${SOURCE} 


# 	${CC} -c ${CFLAGS}  $< -o $@ 



# SHARE:	${SOURCE}
# 	${foreach sobj, ${SHARE_OBJ}, ${ shell ${CC} ${CFLAGS} -c -fPIC -o ${sobj} ${sobj:%.share.o=%.cpp}}}
# 	for sobj in ${SHARE_OBJ};\
# 	do (${CC} ${CFLAGS} -c -fPIC $${sobj%.share*}.cpp -o $${sobj});\
# 	done ;



${DLIB}:	${SHARE_OBJ}
	${CC} -shared ${SHARE_OBJ} -o $@ 	


${PROGRAM}:	${DLIB}   onlinetranslate.cpp 
	${CC} ${CFLAGS}   onlinetranslate.cpp -o $@ ${INCLUDES} ${LIBDIRS} ${LIBS}


onlinetranslate_a:	${SOURCE} ${OBJ}  onlinetranslate.cpp 
	${CC} ${CFLAGS} ${OBJ}  onlinetranslate.cpp -o $@ ${INCLUDES} ${LIBDIRS} ${LIBS}


lib:	${LIB}


install:	${DLIB}
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
	rm -f  ${PROGRAM}  ${LIB}


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
	${CC} ${CFLAGS} -c $< -o $@    ${INCLUDES}

http/%.o:http/%.cpp ${shell ls http/*.cpp}
	${CC} ${CFLAGS} -c  $< -o $@    ${INCLUDES}

manage/%.o:manage/%.cpp ${shell ls manage/*.cpp}
	${CC} ${CFLAGS} -c  $< -o $@     ${INCLUDES}



# share object 
html/%.share.o:html/%.cpp ${shell ls html/*.cpp}
	${CC} ${CFLAGS} -c -fPIC $< -o $@    ${INCLUDES}

http/%.share.o:http/%.cpp ${shell ls http/*.cpp}
	${CC} ${CFLAGS} -c -fPIC $< -o $@    ${INCLUDES}
manage/%.share.o:manage/%.cpp ${shell ls manage/*.cpp}
	${CC} ${CFLAGS} -c -fPIC $< -o $@    ${INCLUDES}
