# Documentation

This project implements a simple voting system that manages:

- **Registered Voters**: Individuals who are eligible to participate in the voting process.
- **Voting Processes**: Various elections or decisions to be voted on, such as class presidency or committee membership.
- **Candidates**: Individuals who are nominated and stand a chance to be elected or selected.
- **Voting Results**: The outcomes of the voting process, including who won each election and by how many votes.
- **Ballot**: The votes cast

## Characteristics

- Each voting process is unique.
- Registered voters are unique individuals.
- Registered voters are specific to each voting process, meaning a voter can be qualified to participate in voting process A but not B, even though the voter exists.
- Voting results or outcomes are specific to each voting process.

## Entities

### Voting Processes

> entity name: voting_processes

- id: number, that represents row id
- name: a string of at most 20 characters that uniquely identifies a voting process
- status: a number (0, 1), which indicates the state of the voting , 0 for not done and one for done

### Registered Voters

> entity name: registered_voters

- id: number, that represents row id
- username: a string of 10 characters that uniquely identifies a qualified voter
- has_voted: a number (supposed to be a boolean) by default 0, indicating a voter has yet to vote
- pin: a string of 5 characters that qualified voter would use to access the voting system, as a means of authentication
- voting_processes: number, that represents a voting processes a registered voter is part of

### Candidates

> entity name: candidates

- id: number, that represents row id
- username: a string of 10 characters that uniquely identifies a nominated candidate
- name: a string of characters that is displayed for nominated candidate
- voting_processes: number, that represents a voting processes a candidate is part of

### Ballot

> entity name: ballot

- id: number, that represents row id
- voter_id: number, that represents a voter
- candidate_id: number, that represents a candidate

### Results

- id: number, that represents row id
- candidate_id: number, that represents a candidate
- count: number that represents the number of votes a candidate got

## View

In this context, "view" refers to the interface with which the user of the voting system interacts.

- Some administrator (we don't know or care who this is) creates a voting process.
- This administrator adds voters to the voting process (we have to think about how voters and candidates will be added).
- This administrator adds candidates to the voting process.
- A voter who is part of the voting process casts their vote.
- This voter can view the vote they have cast (the result of their vote, who they voted for to verify).
- This administrator can view the result of the voting process.
- This administrator can end a voting process (This is the only time a result record is created).
