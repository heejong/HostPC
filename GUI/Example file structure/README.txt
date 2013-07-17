This folder provides an example file structure for OpenPET data. The OpenPET firmware will generate
the data_*.dat and data_*.hdr files. The Host PC is responsible for taking the list mode data 
--- INTRODUCTION ---

contained within the binary data_*.dat file and translating it into a REPORT_data_*.dat file structure.
A list mode analysis function will need to be written in order to read this list mode data and generate 
a file structure similar to the one shown here.


--- HOW TO GENERATE EXAMPLE REPORT STRUCTURES ---

A shell script has been included here to automatically generate each of the 7 different file structures.
It can be called from the command line with the sh command and takes 1 argument specifying the data type.
For example, 

	$ sh CreateFileStructure.sh oscilloscope

It will read the data included in the FakeData folder and automatically create the example file structure.

Please note that all file names and folder names must be repeated verbatim in the actual list mode analysis
function. The GUI will search this file tree to properly display data. If file names and folder names do 
not match, it will not perform properly.


--- DATA FORMAT ---

The data files at the bottom of the REPORT tree must contain only numeric data.
All numeric data must be separated by tabs ('\t').
1D arrays are given in one row. 2D arrays are given in a row-by-row basis with each row describing
a discrete unit (i.e. one row per crystal). Rows must end in a new line character ('\n');

The structure for each is as follows:
  - Test Mode 1 & 2
    + 1 file per DB
    + each file contains a 1D array in 1 row
    + the values in the 1D array correspond to the number of bit errors in that bit position
      - for example, if 1000 11-bit test words are sent and bit 3 is detected incorrectly 200 times
        while all other bits are detected correctly
      - 0	0	0	200	0	0	0	0	0	0	0
  - User Mode
    + 1 file per DB
    + each file contains 1D array in 1 row
    + the values in the 1D array correspond to the count of each payload value
	  - for example, a 10-bit payload has 1024 possible values. The 1D array will have 1024 elements
	    each representing the number of times that payload value was received.
  - Energy Mode
    + 4 or 8 files per DB (1 file per block, 1 block per 4 channels, 16 or 32 channels per DB)
    + each file contains a 2D array describing block energy data with 1 row per crystal
      - for example, a block of 16 x 16 crystals will provide an array of 256 rows
  - Flood Map Mode
    + 4 or 8 files per DB (1 file per block, 1 block per 4 channels, 16 or 32 channels per DB)
    + each file contains a 2D array describing block flood map
      - 2D array corresponds to the number of events in a given (X,Y) position
  - Oscilloscope Mode
    + 16 or 32 files per DB (1 file per channel, 16 or 32 channels per DB)
	+ each file contains a 100 x 64 element 2D array 
      - each of the 100 rows represents a different event 
      - each of the 64 elements in that row represents 1 sampled ADC value 
  - Time Mode
    + 16 or 32 files per DB (1 file per channel, 16 or 32 channels per DB)
	+ each file contains a 1D array of TDC data
  	  