prefix = /usr/local

install:
	mv ./bin/* ./
	g++ manager.cpp -o manager -lcurl -lcrypto -std=c++17
	echo $(DESTDIR)
	echo $(prefix)
	install manager $(DESTDIR)$(prefix)/bin
	install manager.1 $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f createstructure
