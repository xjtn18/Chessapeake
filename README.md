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
