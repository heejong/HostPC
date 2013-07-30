# used to create the example file structure

if [[ "$#" != "1" ]]
then
	echo 'enter 1 mode argument: "oscilloscope", "test1", "test2", "time", "energy", "floodmap", "user"'
	exit 0
fi

# clean up previous file structure
rm -rf "REPORT_data_07162013"


# Specify summary text strings
MBSUMMARYTEXT="# This file contains the summary information necessary for the GUI to 
# display the MB navigation screen (EVENTS and/or ERRORS)

! EVENTS
0: 123412
1: 151342
2: 134112
3: 112344
T: 521210"

MBSUMMARYERRORS="

! ERRORS
0: 8342
1: 6131
2: 3421
3: 7356
T: 25250"


DUCSUMMARYTEXT="# This file contains the summary information necessary for the GUI to 
# display the DUC navigation screen (EVENTS and/or ERRORS)

! EVENTS
0: 123412
1: 151342
2: 123213
3: 451341
4: 134134
5: 314135
6: 143155
7: 324123
T: 1791855"

DUCSUMMARYERRORS="

! ERRORS
0: 342
1: 131
2: 421
3: 356
4: 143
5: 123
6: 421
7: 354
T: 2291"

DBSUMMARYTEXT="# This file contains the summary information necessary for the GUI to 
# display the DB navigation screen (EVENTS and/or ERRORS)

! EVENTS
0: 12341
1: 14334
2: 91342
3: 13413
4: 34134
5: 14135
6: 43155
7: 24123
T: 246977"

DBSUMMARYERRORS="

! ERRORS
0: 42
1: 31
2: 21
3: 56
4: 43
5: 23
6: 21
7: 54
T: 291"

TEST1TEXT="4	1	2	7	2	7	3	3	3	4	1"

TEST2TEXT="2	2	4	2	3	4	7	2	2	2	3"


# create main folder
mkdir "REPORT_data_07162013"
cd "REPORT_data_07162013"

# determine Summary text
if [[ $1 == "test1" ]]
then
	SUMMARYTEXT="Summary_TestMode1.txt"
elif [[ $1 == "test2" ]]
then
	SUMMARYTEXT="Summary_TestMode2.txt"
elif [[ $1 == "oscilloscope" ]] 
then 					
	SUMMARYTEXT="Summary_OscilloscopeMode.txt"
elif  [[ $1 == "time" ]] 
then 	
	SUMMARYTEXT="Summary_TimeMode.txt"
elif  [[ $1 == "energy" ]] 
then 
	SUMMARYTEXT="Summary_EnergyMode.txt"
elif  [[ $1 == "floodmap" ]] 
then 
	SUMMARYTEXT="Summary_FloodMapMode.txt"
elif  [[ $1 == "user" ]] 
then 
	SUMMARYTEXT="Summary_UserMode.txt"
else
	echo 'Invalid mode argument: "oscilloscope", "test1", "test2", "time", "energy", "floodmap", "user"'
	exit 0
fi 

# write summary text
if [[ $1 == "test1" || $1 == "test2" ]]
then
	# add errors onto end
	echo "$MBSUMMARYTEXT""$MBSUMMARYERRORS" > "$SUMMARYTEXT"
else
	echo "$MBSUMMARYTEXT" > "$SUMMARYTEXT"
fi
	
# create and fill in folder structure
for i in 0 1 2 3 
do
	MBfoldername=MB$i
	mkdir $MBfoldername
	cd $MBfoldername
	if [[ $1 == "test1" || $1 == "test2" ]]
	then
		# add errors onto end
		echo "$DUCSUMMARYTEXT""$DUCSUMMARYERRORS" > "$SUMMARYTEXT"
	else
		echo "$DUCSUMMARYTEXT" > "$SUMMARYTEXT"
	fi
	for j in 0 1 2 3 4 5 6 7	
	do
		DUCfoldername=DUC$j
		mkdir $DUCfoldername
		cd $DUCfoldername
		if [[ $1 == "test1" || $1 == "test2" ]]
		then
			# add errors onto end
			echo "$DBSUMMARYTEXT""$DBSUMMARYERRORS" > "$SUMMARYTEXT"
		else
			echo "$DBSUMMARYTEXT" > "$SUMMARYTEXT"
		fi
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
				cp ../../../../FakeData/OscilloscopeMode_*.txt ./
			elif  [[ $1 == "time" ]] 
			then 
				cp ../../../../FakeData/TimeMode_*.txt ./
			elif  [[ $1 == "energy" ]] 
			then 
				cp ../../../../FakeData/EnergyMode_*.txt ./
			elif  [[ $1 == "floodmap" ]] 
			then 
				cp ../../../../FakeData/FloodMapMode_*.txt ./

			elif  [[ $1 == "user" ]] 
			then 
				cp ../../../../FakeData/UserMode.txt ./
			else
				echo 'Invalid mode argument: "oscilloscope", "test1", "test2", "time", "energy", "floodmap", "user"'
				exit 0
			fi 
			cd ..
	
		done	
		cd ..
	done
	cd ..
done
