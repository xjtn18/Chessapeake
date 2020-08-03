# ChessLand



### How to build and run

	- cd build/  
	- cmake ..  
	- make  
	- ./out (or out.exe if on Windows)

### Notes


Issues:  
	- switch to unique_ptr's for safer memory cleanup  
	- implement and recognize 'takes' notation  
	- implement clarifying moves (ex. N3d4, Nfg5) and give 'invalid move' when moves are ambiguous (semi rare scenarios) 
