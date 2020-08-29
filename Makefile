uspm: uspm/main.c uspm/parser.c uspm/iu.c uspm/parser.h
	@mkdir -p "build"
	@gcc -lcjson -lcurl -o build/uspm main.c -lm

clean:
	@rm -rf build

install:
	@mv ./build/uspm /usr/local/bin/

uninstall:
	@rm /usr/local/bin/uspm
