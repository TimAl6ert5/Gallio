# LCR Game

## Tasks

- [ ] Represent dice face as enum, rather than assume meaning for values 1, 2, 3... everywhere
- [ ] Implement 'game referee' that observes players chips to determine winner
- [ ] Prevent users with the same name entering the game
- [ ] make sure the minimum players is 3
- [ ] encapsulate game statistics for reporting
- [ ] allow multiple games to be played


## Pseudocode

VARIABLES:
ListOfPlayers
PlayersChipCount


FUNCTION TakeTurn:
	Roll Dice
	FOR each dice rolled, take action
		CASE 'L'
			move chip to player on left
		CASE 'C'
			move chip to the center
		CASE 'R'
			move chip to player on right
		DEFAULT
			no action


FUNCTION PlayGame:
	SET each PlayersChipCount to 3
	DO
		GET next player
		CALL TakeTurn
	WHILE number of players with chips > 1


SET Random generator seed
DISPLAY Welcome message and game rules

WHILE user wants to add more players OR number of players is less than 3
	PROMPT Add player
	ADD player to ListOfPlayers

CALL PlayGame

DISPLAY Winner
