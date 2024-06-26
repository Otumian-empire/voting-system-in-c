# Voting System in C

This is a simple tool that helps run elections from the command-line. It's written in C, with SQL. It helps keep track of who can vote, who is running for a position (a candidate), who has voted, and who won. Each person who can vote is unique and can only vote in certain elections. They use a secret code, their pin, to make sure they're who they say they are. Candidates are people who want to be elected or chosen for something. Votes are recorded, and the results show who won each election and by how many votes. This system makes it easier to run elections and keep everything organized and fair.

## Dependencies

-   Database [sqlite3](https://www.sqlite.org/docs.html)

## Resources

-   [gcc](https://developer.fedoraproject.org/tech/languages/c/c_installation.html)
-   [sqlite3](https://www.sqlite.org/docs.html)

    -   ```sh
        # update system
        sudo apt update
        # sudo dfn update

        # install sqlite3
        sudo apt install sqlite3
        # sudo dnf install sqlite3

        ```

-   [vscode](https://code.visualstudio.com/download)
-   [SQLite extension](https://marketplace.visualstudio.com/items?itemName=alexcvzz.vscode-sqlite) by alexcvzz
-   [SQLite C - tutorialspoint](https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm)
-   [gcc-gnu Warning-Options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)

## Installation/Set up

-   Install C compiler, `sudo dnf install make automake gcc`, or install build essentials.
-   Run this command to create the `bin` folder, `mkdir bin` when the `make create-db` gives you an error.
-   Drop the database with `make drop-db`, after a `database` modification. Run, `make create-db`
-   Create Database and migrate the tables, `make create-db`

## Build

## Execution

-   After successful installation
-   run, `make` then use keyboard inputs to choose and enter data

## Limitations

-   There is no admin, the user running the app is the admin
-   The main focus at this moment is to get something working

## Improvements

-   Add bulk voters
-   Hash the voter pin
-   Keep system app running in a loop so that user doesn't have to run `make` all the time
-   Add actual graphics with table views and buttons where user can click to interact with the application
-   Keep activity logs (for both admin and a registered voter)
-   Switch to a MySQL or PostgreSQL (even though SQLite is okay but for the issue of blocking - locking)

## Contribution
