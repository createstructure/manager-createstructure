prefix = /usr/local

all:
	g++ ./bin/manager.cpp \
		./bin/local-libraries/help.cpp \
		./bin/local-libraries/login.cpp \
		./bin/local-libraries/memory.cpp \
		./bin/local-libraries/version.cpp \
		./bin/global-libraries/bin/inputs.cpp \
		-o manager -lcurl

install:
	g++ ./bin/manager.cpp \
		./bin/local-libraries/help.cpp \
		./bin/local-libraries/login.cpp \
		./bin/local-libraries/memory.cpp \
		./bin/local-libraries/version.cpp \
		./bin/global-libraries/bin/inputs.cpp \
		-o manager -lcurl
	echo "DESTDIR: $(DESTDIR)"
	echo "prefix: $(prefix)"
	install manager $(DESTDIR)$(prefix)/bin
	install manager.1 $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f manager
