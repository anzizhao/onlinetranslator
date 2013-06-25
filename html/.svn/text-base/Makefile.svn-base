CC=g++ 
CFLAGS=-g -W 


SOURCE = ${wildcard *.cpp}

OBJ =  ${SOURCE:%.cpp = *.o }




all:	test
.PHONY:	all clean 



test:   ${SOURCE}  ${OBJ}
	${CC} ${CFLAGS} ${OBJ} testbaidu.cc  -o $@   -L ../lib -l htmlcxx


testjson:   .OBJ
	${CC} ${CFLAGS}  ${OBJ} testjson.cpp -o $@   -L ../lib -l htmlcxx	



clean:
	rm -f *.o  testjson test


%.o:%.cpp	${SOURCE}
	${CC} ${CFLAGS} -c $> -o $@ 