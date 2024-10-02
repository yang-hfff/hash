a.exe:*.c
	gcc -finput-charset=UTF-8 -fexec-charset=GB2312 -g -Wall -std=c99 -o $@ $^

	