all:
	gcc lic.c -o lic

install:
	make
	sudo cp ./lic /usr/bin/
