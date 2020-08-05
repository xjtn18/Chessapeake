# Chessapeake

### How to build and run
	- cd build/  
	- cmake ..  
	- make  
	- ./out (or out.exe if on Windows)

### Notes
	- If on Windows, you might need to change the #define CLEAROUT in src/main.cpp to 'CLS' if you aren't using cygwin unix commands  

Issues:  
	- switch to unique_ptr's for safer memory cleanup  
	- implement and recognize 'takes' notation  
	- implement clarifying moves (ex. N3d4, Nfg5) and give 'invalid move' when moves are ambiguous (semi rare scenarios) 

