prefix = /usr/local

all:
	g++ ./bin/manager.cpp \
		./bin/local-libreries/help.cpp \
		./bin/local-libreries/login.cpp \
		./bin/local-libreries/memory.cpp \
		./bin/local-libreries/version.cpp \
		./bin/global-libreries/bin/input.cpp \
		-o manager -lcurl

install:
	g++ ./bin/manager.cpp \
		./bin/local-libreries/help.cpp \
		./bin/local-libreries/login.cpp \
		./bin/local-libreries/memory.cpp \
		./bin/local-libreries/version.cpp \
		./bin/global-libreries/bin/input.cpp \
		-o manager -lcurl
	echo "DESTDIR: $(DESTDIR)"
	echo "prefix: $(prefix)"
	install manager $(DESTDIR)$(prefix)/bin
	install manager.1 $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f manager
