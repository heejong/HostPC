# used to create the example file structure

if [[ "$#" != "1" ]]
then
	echo 'enter 1 mode argument: "oscilloscope", "test1", "test2", "time", "energy", "floodmap", "user"'
	exit 0
fi


# clean up previous attempt
rm -rf "REPORT_data_07172013"


# Specify summary text strings
MBSUMMARYTEXT="# This file contains the summary information necessary for the GUI to 
# display the MB navigation screen (EVENTS and/or ERRORS)

! EVENTS (MB)
0: 123412
1: 151342
T: 274754"

DUCSUMMARYTEXT="# This file contains the summary information necessary for the GUI to 
# display the DUC navigation screen (EVENTS and/or ERRORS)

! EVENTS (DUC)
0: 123412
1: 151342
2: 123213
3: 451341
4: 134134
5: 314135
6: 143155
7: 324123
T: 1791855"

DBSUMMARYTEXT="# This file contains the summary information necessary for the GUI to 
# display the DB navigation screen (EVENTS and/or ERRORS)

! EVENTS (DB)
0: 12341
1: 14334
2: 91342
3: 13413
4: 34134
5: 14135
6: 43155
7: 24123
T: 246977"

TEST1TEXT="1234	1431	1232	897	982	897	1233	923	423	324	1421"

TEST2TEXT="1432	892	314	1234	983	234	897	982	1234	1242	1321"

OSCILLOSCOPETEXT=

ENERGYTEXT=

TIMETEXT=


# create main folder
mkdir "REPORT_data_07172013"
cd "REPORT_data_07172013"

# write Summary text
echo "$MBSUMMARYTEXT" > Summary.txt

# create and fill in folder structure
for i in 0 1
do
	MBfoldername=MB$i
	mkdir $MBfoldername
	cd $MBfoldername
	echo "$DUCSUMMARYTEXT" > Summary.txt
	for j in 0 1 2 3 4 5 6 7	
	do
		DUCfoldername=DUC$j
		mkdir $DUCfoldername
		cd $DUCfoldername
		echo "$DBSUMMARYTEXT" > Summary.txt
		for k in 0 1 2 3 4 5 6 7
		do
			DBfoldername=DB$k
			mkdir $DBfoldername
			cd $DBfoldername
			# create data file
			if [[ $1 == "test1" ]]
			then
				echo "$TEST1TEXT" > TestMode1.txt
			elif [[ $1 == "test2" ]]
			then
				echo "$TEST2TEXT" > TestMode2.txt
			elif [[ $1 == "oscilloscope" ]] 
			then 
				echo "$OSCILLOSCOPETEXT" > TestMode2.txt
			elif  [[ $1 == "time" ]] 
			then 
				echo "$TIMETEXT" > TestMode2.txt
			elif  [[ $1 == "energy" ]] 
			then 
				echo "$ENERGYTEXT" > TestMode2.txt
			elif  [[ $1 == "floodmap" ]] 
			then 
				cp ../../../../FakeData/FloodMap_Block1.txt ./
				cp ../../../../FakeData/FloodMap_Block2.txt ./
				cp ../../../../FakeData/FloodMap_Block3.txt ./
				cp ../../../../FakeData/FloodMap_Block4.txt ./
				cp ../../../../FakeData/FloodMap_Block5.txt ./
				cp ../../../../FakeData/FloodMap_Block6.txt ./
				cp ../../../../FakeData/FloodMap_Block7.txt ./
				cp ../../../../FakeData/FloodMap_Block8.txt ./

			elif  [[ $1 == "user" ]] 
			then 
				cp ../../../../FakeData/UserMode.txt ./
			fi 
			cd ..
	
		done	
		cd ..
	done
	cd ..
done
