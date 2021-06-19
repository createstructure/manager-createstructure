prefix = /usr/local

install:
	apt install libcurl4-openssl-dev libssl-dev -y
	mv ./bin/* ./
	g++ manager.cpp -o manager -lcurl -lcrypto
	echo $(DESTDIR)
	echo $(prefix)
	install manager $(DESTDIR)$(prefix)/bin
	install manager.1 $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f createstructure
