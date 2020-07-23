# ChessLand


Issues:  
	- switch to unique_ptr's for safer memory cleanup  

### How to run

	- cd build/  
	- cmake ..  
	- make  
	- ./out  

### Notes
	- For screen clearing to work on Windows, uncomment the "#define CLEAROUT system('CLS')" in src/main.cpp and comment out the unix defintion (temporary workaround)  
