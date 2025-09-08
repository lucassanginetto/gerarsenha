CC = clang

FLAGS = -std=c99 -Wall -Wextra -Wconversion -Werror

gerarsenha: gerarsenha.c
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f gerarsenha
