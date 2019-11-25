/* Name: Carlos Castillo
Class : CIS 161 ME1
Date : 20 October 2019
Program Name : Class Statistics Analyzer 
Program Explanation : This program reads 
student IDs and three quiz scores from a file. 
Then it calculates each students average and 
calculates the average of each quiz. It outputs
all the results to a new file with headers
and proper formatting*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 100; // defined a constant int variable called SIZE
typedef int intarray[SIZE]; // defined a new type called intarray with size declarator
typedef float flarray[SIZE]; // defined a new type called flarray with size declarator

void setdata(intarray, intarray, intarray, intarray, int &); // function prototype
void findstavg(const intarray, const intarray, const intarray, const int &, flarray);
int findhigh(const intarray, const int &);
int findlow(const intarray, const int &);
float findqzavg(const intarray, const int &);
void getdata(const intarray, const intarray, const intarray, const intarray, const flarray, const int &, const int &, const int &, const int &, const int &, const int &, const float &, const float &, const float &, const int &);

int main()
{
	intarray student_ids, quiz1, quiz2, quiz3; // defined four integer arrays
	flarray studentAvg; // defined a float array
	int studentCount,highScore1,highScore2,highScore3,lowScore1,lowScore2,lowScore3;
	float quizAvg1,quizAvg2,quizAvg3;
	
	setdata(student_ids, quiz1, quiz2, quiz3, studentCount); // Called setdata to set values for arrays
	findstavg(quiz1, quiz2, quiz3, studentCount, studentAvg); // called findstavg to calculate each students average
	highScore1 = findhigh(quiz1, studentCount); // called findhigh three times to find high scores
	highScore2 = findhigh(quiz2, studentCount);
	highScore3 = findhigh(quiz3, studentCount);
	lowScore1 = findlow(quiz1, studentCount); // called findlow three times to find low scores
	lowScore2 = findlow(quiz2, studentCount);
	lowScore3 = findlow(quiz3, studentCount);
	quizAvg1 = findqzavg(quiz1, studentCount); //called findqzavg three times to find quiz averages
	quizAvg2 = findqzavg(quiz2, studentCount);
	quizAvg3 = findqzavg(quiz3, studentCount);
	getdata(student_ids,quiz1,quiz2,quiz3,studentAvg,highScore1,highScore2,highScore3,lowScore1,lowScore2,lowScore3, quizAvg1, quizAvg2,quizAvg3, studentCount); // called getdata to write all output to a file
	
	return 0;
}


/* This function is a void type because it returns no values.
It contains five parameters which are all passed by reference.
Four of the parameters are arrays of integer type and one parameter
is an integer type. The function issues an error message if the file 
cannot be opened. Upon opening the file, the function uses a loop 
to read student IDs for each student and three quiz scores for each 
student into arrays. Afterwards, the file is closed.*/
void setdata(intarray id, intarray q1, intarray q2, intarray q3, int &stud_count)
{	
	ifstream iFile("pr2data.txt"); // defined an input file
	
	stud_count = 0; // initializes counter to 0 
	
	if(!iFile) // checks if the file can be opened or not
		cout << "ERROR OPENING FILE!" << endl; // displays error message
	else
 		while(iFile >> id[stud_count])
		 {  
		 	iFile>> q1[stud_count] >> q2[stud_count] >> q3[stud_count]; // reads all the files values into the arrays
			stud_count++; 
		 }
		iFile.close(); // closes the file after it has been used
}


/* This function is a void type because it returns no values.  
It contains five parameters.  The first three parameters are
integer arrays and they are passed by const reference. The fourth 
parameter is an int type and it is passed by const reference. The 
fifth parameter is a float array and it is passed by reference.
This function collects the sum of the three quiz scores
and then calculates the student average for each quiz that
the students took.  It stores each student average in a float array
called stud_avg.*/
void findstavg(const intarray q1, const intarray q2, const intarray q3, const int & stud_count, flarray stud_avg)
{	
	int quiz_total; // defined an int variable called total to collect quiz scores
	
	for(int counter = 0; counter < stud_count; counter++) 
	{
		quiz_total = q1[counter] + q2[counter] + q3[counter]; // stores all three scores inside total
		stud_avg[counter] = (quiz_total / 3.0); // calculates each students average and stores it in the avg array
	}	
}


/* This function is an integer type because it returns an integer 
value.  It contains two parameters.  The first parameter is an integer
array that is passed by const reference.  The second parameter is an 
integer that is passed by const reference.  The function looks for
the highest value in the quiz array and returns it.*/ 
int findhigh(const intarray quiz, const int & stud_count)
{
	int highest; // defined int variable called highest which will hold highest quiz score
	
	highest = quiz[0]; // set initial highest value to the first element of the quiz array

	for(int counter = 1; counter < stud_count; counter++) 
	{
		if (quiz[counter] > highest) // checks if the current quiz score is greater than the current high score
			highest = quiz[counter]; // stores the new quiz value in highest
	}
	
	return highest; 
}


/* This function is an integer type because it returns an integer
value.  It contains two parameters.  The first parameter is an integer
array that is passed by const reference.  The second parameter is
an integer that is passed by const reference.  The function looks
for the lowest value in the quiz array and returns it.*/
int findlow(const intarray quiz, const int & stud_count)
{	
	int lowest; // defined int variable called lowest which will hold lowest quiz score
	
	lowest = quiz[0]; // set initial lowest value to the first element of the quiz array

	for(int counter = 1; counter < stud_count; counter++) 
	{
		if (quiz[counter] < lowest) // checks if the current quiz score is less than the current lowest score
			lowest = quiz[counter]; // stores the new quiz value in lowest
	}	
	
	return lowest;
}


/* This function is a float type that returns a float value.
It contains two parameters.  The first paramter is an integer
array type and it is passed by const reference.  The second
paramter is an integer type that is passed by const reference.
This function gets the sum of the quiz scores and stores it in
a total variable.  It uses the total to calculate the quiz average 
for the three quizzes of the class.  Afterwards it returns the quiz average.*/
float findqzavg(const intarray quiz, const int & stud_count)
{
	float quiz_avg; // defined quiz avg variable to hold the quiz average
	int total; // defined total, an accumulator that holds all the quiz scores
	int counter;
	total = 0; // set total to 0
	
	for(counter = 0; counter < stud_count; counter++)
	{
		total += quiz[counter]; // add up all the quiz scores to total
	}
	
	quiz_avg = (total / static_cast<float>(counter)); // calculate the quiz average
	
	return quiz_avg; 
}


/*This function is a void type because it returns no values.  It contains
15 parameters which are all passed by const reference.  There are four
integer arrays, one float array, seven integers, three float parameters. 
This function outputs headers, student IDs, the three quiz scores for
every student and every student's average. Afterwards, it displays the 
highest scores, lowest scores, and quiz averages.  The file is closed
at the end of the function.*/
void getdata(const intarray id, const intarray q1, const intarray q2, const intarray q3, const flarray studavg, const int &high1, const int &high2, const int &high3, const int &low1, const int &low2, const int &low3, const float &qzavg1, const float &qzavg2, const float &qzavg3, const int &stud_count)
{
	ofstream outFile("quizstats.txt"); // defined output file that will contain all the output data
	
	outFile << "\t\t\tCIS Department - Fall 2018" << endl;  // display header for the file
	outFile << setw(49) << "CIS 161 Class Statistics" << endl;
	outFile << "\nStudent\t\tQuiz 1\t\tQuiz 2\t\tQuiz 3\t\tAverage" << endl;
	outFile << fixed << showpoint << setprecision(2); 
	for (int x = 0; x < stud_count; x++) 
		outFile << id[x] << "\t\t" << q1[x] << "\t\t" <<  q2[x] << "\t\t" <<  q3[x] << "\t\t" << studavg[x] << endl; // displays every id, quiz score, and student average	
	outFile << "\nHigh score\t" << high1 << "\t\t" << high2 << "\t\t" << high3 << endl; // display highest scores
	outFile << "\nLow score\t" << low1 << "\t\t" << low2 << "\t\t" << low3 << endl; // display lowest scores
	outFile << "\nQuiz Average\t" << qzavg1 << "\t\t" << qzavg2 << "\t\t" << qzavg3 << endl; // display quiz averages	
	outFile.close();
}

