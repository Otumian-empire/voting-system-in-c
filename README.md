# Voting System in C

This is a simple tool that helps run elections from the command-line. It's written in C, with SQL. It helps keep track of who can vote, who is running for a position (a candidate), who has voted, and who won. Each person who can vote is unique and can only vote in certain elections. They use a secret code, their pin, to make sure they're who they say they are. Candidates are people who want to be elected or chosen for something. Votes are recorded, and the results show who won each election and by how many votes. This system makes it easier to run elections and keep everything organized and fair.

## Dependencies

- Database (sqlite3)[https://www.sqlite.org/docs.html]

## Resources

- gcc
- (sqlite3)[https://www.sqlite.org/docs.html]

  - ```sh
    # update system
    sudo apt update

    # install sqlite3
    sudo apt install sqlite3

    ```

- vscode
- (SQLite extension)[https://marketplace.visualstudio.com/items?itemName=alexcvzz.vscode-sqlite] by alexcvzz

## Installation/Set up

Create Database and migrate the tables

```sh
make create-db
```

## Build

## Execution

## Contribution

## Improvements

## Limitations
