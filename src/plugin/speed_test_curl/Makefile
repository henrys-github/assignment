CC = gcc
CFLAGS = -I$(PROJECT)/opt/include/
LDFLAGS = -L$(PROJECT)/opt/lib/
LDLIBS = -lcurl

EXECS := curl_lib speed_test_curl

all: $(EXECS)

curl_lib:
	cd $(PROJECT)/open_source_pkg/;\
	tar xfvz curl-7.61.1.tar.gz;\
	cd curl-7.61.1/;\
	./configure --prefix=$(PROJECT)/opt/;\
	make;\
	make install;

speed_test_curl: speed_test_curl.c
	$(CC) $(CFLAGS) $(LDFLAGS) -Wall -fPIC -c speed_test_curl.c $(LDLIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -Wl,-soname,libspeed_test_curl.so -o libspeed_test_curl.so *.o $(LDLIBS)
	cp -f libspeed_test_curl.so $(PROJECT)/opt/lib/

clean:
	rm -f *.o *.so*
