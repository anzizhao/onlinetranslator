CC = g++ 
CFLAGS := -g -W 


json_baidu_t: libjson_baidu.cpp
	${CC} ${CFLAGS} -c  libjson_baidu.cpp    -I ../libjson 
	${CC} libjson_baidu.o ../libjson/libjson.a  -o $@ 