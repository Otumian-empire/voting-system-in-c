-- sql script for creating the voting system entities

-- Create Voting Processes table
CREATE TABLE voting_processes (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL UNIQUE,
    status INTEGER NOT NULL DEFAULT 0 CHECK(status IN (0, 1))
);

-- Create Registered Voters table
CREATE TABLE registered_voters (
    id INTEGER PRIMARY KEY,
    username TEXT NOT NULL UNIQUE,
    pin TEXT NOT NULL,
    has_voted INTEGER NOT NULL DEFAULT 0 CHECK(has_voted IN (0, 1)),
    voting_process_id INTEGER,
    FOREIGN KEY(voting_process_id) REFERENCES voting_processes(id)
);

-- Create Candidates table
CREATE TABLE candidates (
    id INTEGER PRIMARY KEY,
    username TEXT NOT NULL UNIQUE,
    name TEXT NOT NULL,
    voting_process_id INTEGER,
    FOREIGN KEY(voting_process_id) REFERENCES voting_processes(id)
);

-- Create Ballot table
CREATE TABLE ballots (
    id INTEGER PRIMARY KEY,
    voter_id INTEGER,
    candidate_id INTEGER,
	voting_process_id INTEGER,
    FOREIGN KEY(voter_id) REFERENCES registered_voters(id),
    FOREIGN KEY(candidate_id) REFERENCES candidates(id),
    FOREIGN KEY(voting_process_id) REFERENCES voting_processes(id)
);

-- Create Results table
CREATE TABLE results (
    id INTEGER PRIMARY KEY,
    candidate_id INTEGER,
	voting_process_id INTEGER,
    count INTEGER NOT NULL,
    FOREIGN KEY(candidate_id) REFERENCES candidates(id),
    FOREIGN KEY(voting_process_id) REFERENCES voting_processes(id)
);