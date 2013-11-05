CC = gcc
CFLAGS =
TARGETS = bubble select insert quick merge shell

default:
	@for file in ${TARGETS} ; do \
		${CC} -o $$file ${CFLAGS} $$file.c ; \
	done

clean:
	@rm -f ${TARGETS}
