CC=g++ 
CFLAGS=-g -W 
LIBDIRS := -L. -L../dep/htmlcxx/html/.libs -L../dep/libjson 
LIBS   := -ltranslate  -lhtmlcxx -ljson  
INCLUDES :=  -I../dep/htmlcxx/html/   -I../dep/libjson -I../include/ 
SOURCE = ${wildcard *.cpp}

OBJ =  ${SOURCE:%.cpp = *.o }




all:	baidujson
.PHONY:	all clean 



baidujson:   ${SOURCE}  ${OBJ}
	${CC} ${CFLAGS} ${OBJ} testbaidu.cc  -o $@   ${INCLUDES} ${LIBDIRS} ${LIBS}


testjson:   .OBJ
	${CC} ${CFLAGS}  ${OBJ} testjson.cpp -o $@   -L ../lib -l htmlcxx	



clean:
	rm -f *.o  testjson test


%.o:%.cpp	${SOURCE}
	${CC} ${CFLAGS} -c $> -o $@ 