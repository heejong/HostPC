This folder provides an example file structure for OpenPET data. The OpenPET firmware will generate
the data_*.dat and data_*.hdr files. The Host PC is responsible for taking the list mode data 
contained within the binary data_*.dat file and translating it into a REPORT_data_*.dat file structure.
A list mode analysis function will need to be written in order to read this list mode data and generate 
a file structure similar to the one shown here.

A shell script has been included here to automatically generate each of the 7 different file structures.
It can be called from the command line with the sh command and takes 1 argument specifying the data type.
For example, 

	$ sh CreateFileStructure.sh oscilloscope

It will read the data included in the FakeData folder and automatically create the example file structure.

Please note that all file names and folder names must be repeated verbatim in the actual list mode analysis
function. The GUI will search this file tree to properly display data. If file names and folder names do 
not match, it will not perform properly.

