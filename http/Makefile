CC = g++
CFLAG = -g -W 


# makefile 支持通配符   wildcard 将通配符展开

INCLUDE =   /usr/include/i386-linux-gnu/
SOURCE = ${wildcard *.cpp}
OBJ = ${SOURCE:%.cpp=%.o}




all:	google 

.PHONY:		all clean 






test:	${SOURCE}   ${OBJ} test.cc
	${CC} ${OBJ} test.cc  -o $@


google:	${SOURCE} ${OBJ}  google.cc
	${CC} ${CFLAG} ${OBJ} google.cc  -o $@	



clean:
	rm -f *.o test google 



%.o:%.cpp	${SOURCE}

	${CC} ${CFLAG} -c $< -o $@