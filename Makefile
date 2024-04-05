files = main.c
bin = main
cc = gcc -Wall -Werror

all: compile run

compile:
	@clear
	@$(cc) $(files) -o $(bin)

run:
	@./$(bin)

clean:
	@rm $(bin) 
	
git-am:
	@git add .
	@git commit

git-push:
	@git push -u origin main
