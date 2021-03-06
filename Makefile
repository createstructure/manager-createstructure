prefix = /usr/local

all:
	g++ ./bin/manager.cpp -o manager -lcurl -std=c++17

install:
	g++ ./bin/manager.cpp -o manager -lcurl -std=c++17
	echo "DESTDIR: $(DESTDIR)"
	echo "prefix: $(prefix)"
	install manager $(DESTDIR)$(prefix)/bin
	install manager.1 $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f manager
