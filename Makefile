files = src/main.c src/ui/ui.c src/include/include.c src/controller/controller.c src/models/model.c
bin = bin/main
cc = gcc -Wall -Werror -fsanitize=address -l sqlite3

db_name = bin/voting_system_db.db
create_tables_path = database/migrations/create-tables.sql

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


create-db:
	@sqlite3 ${db_name} < ${create_tables_path}
	@echo "database created successfully"

drop-db:
	@rm ${db_name}
	@echo "database dropped successfully"	