CC = g++
CFLAGS = -I$(PROJECT)/opt/include/
LDFLAGS = -L$(PROJECT)/opt/lib/
LDLIBS = -ldl -lcurl -lspeed_test_curl

EXECS := dynamic-loader

all: $(EXECS)

dynamic-loader: dynamic-loader.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	cp -f $@ $(PROJECT)

clean:
	rm -f dynamic-loader
