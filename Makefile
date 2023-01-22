prefix = /usr/local

all:
	make compile

compile:
	g++ -Wall ./bin/manager.cpp \
		./bin/local-libraries/help.cpp \
		./bin/local-libraries/login.cpp \
		./bin/local-libraries/memory.cpp \
		./bin/local-libraries/version.cpp \
		./bin/global-libraries/bin/inputs.cpp \
		./bin/global-libraries/bin/rest.cpp \
		./bin/global-libraries/bin/emoji.cpp \
		-o manager -lcurl

installbin:
	install manager $(DESTDIR)$(prefix)/bin

installman:
	install manager.1 $(DESTDIR)$(prefix)/share/man/man1

precompile:
	g++ -Wall -c ./bin/manager.cpp -o ./bin/manager.o
	g++ -Wall -c ./bin/local-libraries/help.cpp -o ./bin/local-libraries/help.o
	g++ -Wall -c ./bin/local-libraries/login.cpp -o ./bin/local-libraries/login.o
	g++ -Wall -c ./bin/local-libraries/memory.cpp -o ./bin/local-libraries/memory.o
	g++ -Wall -c ./bin/local-libraries/version.cpp -o ./bin/local-libraries/version.o
	g++ -Wall -c ./bin/global-libraries/bin/inputs.cpp -o ./bin/global-libraries/bin/inputs.o
	g++ -Wall -c ./bin/global-libraries/bin/rest.cpp -o ./bin/global-libraries/bin/rest.o
	g++ -Wall -c ./bin/global-libraries/bin/emoji.cpp -o ./bin/global-libraries/bin/emoji.o

link:
	g++ -Wall ./bin/manager.o \
		./bin/local-libraries/help.o \
		./bin/local-libraries/login.o \
		./bin/local-libraries/memory.o \
		./bin/local-libraries/version.o \
		./bin/global-libraries/bin/inputs.o \
		./bin/global-libraries/bin/rest.o \
		./bin/global-libraries/bin/emoji.o \
		-o manager -lcurl

linkinstall:
	make link
	make installbin
	make installman

install:
	make compile
	echo "DESTDIR: $(DESTDIR)"
	echo "prefix: $(prefix)"
	make installbin
	make installman

clean:
	rm -f manager
