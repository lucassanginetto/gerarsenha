CC = clang

FLAGS = -std=c99 -Wall -Wextra -Wconversion -Werror

gerarsenha: gerarsenha.c
	$(CC) $(FLAGS) $^ -o $@

install: gerarsenha
	mkdir -p /usr/local/bin
	cp -f gerarsenha /usr/local/bin
	chmod 755 /usr/local/bin/gerarsenha
	mkdir -p /usr/local/share/man/man1
	cp -f gerarsenha.1 /usr/local/share/man/man1
	chmod 644 /usr/local/share/man/man1/gerarsenha.1

clean:
	rm -f gerarsenha
