# ChessLand



### How to build and run

	- cd build/  
	- cmake ..  
	- make  
	- ./out (or out.exe if on Windows)

### Notes


Issues:  
	- switch to unique_ptr's for safer memory cleanup  
	- make an undo stack to hold all move history to undo more than 1 move back  
	- reduce repetition in parseMoveRequest function  
	- implement and recognize 'takes' notation  
	- implement clarifying moves (ex. N3d4, Nfg5) and give 'invalid move' when moves are ambiguous (semi rare scenarios) 
