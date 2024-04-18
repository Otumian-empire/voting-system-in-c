files = test.c ../src/include/include.c
bin = bin/test
cc = gcc -Wall -Werror -fsanitize=address -l sqlite3
db_name = bin/test.db
create_tables_path = ../database/migrations/create-tables.sql


test:
	@clear
	@$(cc) $(files) -o $(bin) && make run 

run:
	@./$(bin)

clean:
	@rm $(bin) 
	
create-db:
	@sqlite3 ${db_name} < ${create_tables_path}
	@echo "database created successfully"

drop-db:
	@rm ${db_name}
	@echo "database dropped successfully"	
