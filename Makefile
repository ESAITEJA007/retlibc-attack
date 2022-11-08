all: exploit vulnerable

vulnerable: vulnerable.c 
		clear
		sudo sysctl -w kernel.randomize_va_space=0
		gcc -m32 -o vulnerable -z noexecstack -fno-stack-protector -g -ggdb vulnerable.c
		sudo chown root vulnerable
		sudo chmod 4755 vulnerable

vulnerable2: vulnerable2.c 
		clear
		sudo sysctl -w kernel.randomize_va_space=2
		gcc -m32 -o vulnerable2 -z noexecstack -fno-stack-protector -g -ggdb vulnerable2.c
		sudo chown root vulnerable2
		sudo chmod 4755 vulnerable2
	
exploit: exploit.c
		 gcc -o exploit exploit.c
		 ./exploit


shell: 
		export MYSHELL=/bin/sh
		env | grep SHELL
		
