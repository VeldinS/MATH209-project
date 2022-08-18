#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <limits>

using namespace std;
int main()
{
// READ NAMES AND INSERT THEM INTO ARRAY
/*
 * This part of code is used to read names from the given file that was just saved as "names.txt"
 * All data inside the file remains the same
 */
    string array_names[1500];              //Declaring array which will store data from file
    short loop = 0;                        //Declaring loop which will be used to circle through all names
    string line;                           //Declaring line, which will be used to actually get selected line from file
    ifstream names("names");               //Opening file

    if (names.is_open())                   //Rest of the code is going through file until it is open and storing every line into array
    {
        while (!names.eof())
        {
            getline(names, line);
            array_names[loop] = line;
            //cout << array_names[loop] << endl;    //In case you want to test if code is working, just uncomment this line
            loop++;
        }
        names.close();
    }
    else                                   //In case that file doesnt exist or that something is wrong
    cout << "can't open that file!!!";


// READ SEX AND INSERT THEM INTO ARRAY
/*
 * This part of code is used to read sex of person from the given file that was just saved as "sex.txt"
 * All data inside the file remains the same
 * SAME PROCEDURE AS IN PREVIOUS READING FROM FILE, COMMENTS NOT NEEDED
 */
    string array_sex[1500];
    short loop_sex = 0;
    string line_sex;
    ifstream sex("sex");

    if (sex.is_open())
    {
        while (!sex.eof())
        {
            getline(sex, line_sex);
            array_sex[loop_sex] = line_sex;
            //cout << array_sex[loop_sex] << endl;    //in case you want to test if code is working, just uncomment this line
            loop_sex++;
        }
        sex.close();
    }
    else
    cout << "can't open that file!!!";



// READ CRIMES AND INSERT THEM INTO ARRAY
/*
 * This part of code is used to read appearance of person in some crime and also crime numbers from the given file that was just saved as "crime.txt"
 * All data inside the file remains the same
 * In this part, since we have 2 columns in the file, we need to read the data separately into 2 arrays.
 * That is why I used vectors to store data into them because they have an option push_back which will help us store data separately
 */
    vector<int> arrPersonNr;            //declaring vectors and 2 integers which will represent data from the file for every line separately
    vector<int> arrCriminalNr;
    int i;
    int d;
    ifstream fin("crime");              //opening file

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> i >> d;
            fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            arrPersonNr.push_back(i);         //storing data into vectors
            arrCriminalNr.push_back(d);
            //cout<<arrPersonNr[i]<<endl;     //in case you want to test if code is working, just uncomment this line
        }
    }
    else
    cout << "can't open that file!!!";

// READ ROLES AND INSERT THEM INTO ARRAY
/*
 * This part of code is used to read sex of person from the given file that was just saved as "sex.txt"
 * All data inside the file remains the same
 * SAME PROCEDURE AS IN PREVIOUS READING FROM FILE, COMMENTS NOT NEEDED
 */
    string array_role[1477];
    short loop_role = 0;
    string line_role;
    ifstream role("role");

    if (role.is_open())
    {
        while (!role.eof())
        {
            getline(role, line_role);
            array_role[loop_role] = line_role;
            // cout << array_role[loop_role] << endl;
            loop_role++;
        }
        role.close();
    }
    else
    cout << "can't open that file!!!";

//PROBLEMS FROM THE PROJECT
//PART 1
/*
 * This is the part of code for PART 1 from question 1
 * In this part I wrote code that will circle through 2 for loops and compare values of person and values of appearance of person from "crime.txt"
 * The number of persons appearance will be stored into array which will be used later on to calculate the average
 */
cout<<"------------------------------------------------------"<<endl;
cout<<"PART 1:"<<endl;

double arr[829];

    for(int i=1;i<=829;i++)        //first for loop that will select us person number which will later on be compared with appearances of persons in crimes
    {
        double avg = 0;

        for(int k=0;k<=arrPersonNr.size();k++)     //second for loop to help us find nubmer of occurances of selected person from for loop 1
        {
            if(i == arrPersonNr[k])      //if loop which will collect total number of occurances of some person in all crimes
            {
                //cout<<"The person"<<" "<<array_names[i]<<", appeared in criminal number "<< k+1<<endl;     //in case you want to test the code
                avg++;
            }
        }
        arr[i] = avg;
    }

    double suma = 0;                //for loop to add all those appearances and divide them by total number of persons to get the average

    for(int l = 0;l <= 829; l++)
    {
        suma+=arr[l];
    }
    suma=suma/829;
    cout<<"The average number of crimes a person is involved in is equal to:"<<" "<<suma<<endl;


//PART 2
/*
 * This is the part of code for PART 2 from question 1
 * In this part I wrote code that will circle through 2 for loops again and compare values of crimes and values of appearance of person from "crime.txt"
 * The number of persons appearance will be stored into array which will be used later on to calculate the average
 * The code is pretty much the same as in previous one, just different variables and values
 */
    cout<<"------------------------------------------------------"<<endl;
    cout<<"PART 2:"<<endl;

    double arr2[829];
    int x2;

    cout<<"Enter persons number"<<endl;
    cin>>x2;

    for(int i=1;i<=829;i++)
    {
        double avg = 0;
        for(int k=0;k<=arrPersonNr.size();k++)
        {
            if(i == arrPersonNr[k])
            {
                //cout<<"The person"<<" "<<array_names[i]<<", appeared in criminal number "<< k+1<<endl;
                avg++;
            }
        }
        if(x2 == i)
        {
            cout<<"Number of crimes"<<" "<<array_names[x2-1]<<" "<<" was involved is equal to:"<<" "<<avg<<endl;

        }
        arr2[i] = avg;

    }

//PART 3
/*
 * This is the part of code for PART 3 from question 1
 * In this part I wrote code that will circle through 2 for loops again and compare values of crimes and values of appearance of person from "crime.txt"
 * The number of crimes appearance and persons appearance will be stored into array which will be used later on to calculate the average
 * The code is pretty much the same as in previous one, just different variables and values
 */

/*
 * Also, I inserted a small for loop to find what is the number of crimes in total
 * After removing comments and running for loop below, the program will show result 551,
 * which is actually the total number of crimes that appeared
 */

/*
for(int i = 1;i < arrCriminalNr.size(); ++i)
    {
        // Change < to > if you want to find the smallest element
        if(arrCriminalNr[0] < arrCriminalNr[i])
            arrCriminalNr[0] = arrCriminalNr[i];
    }
    cout<<"Total number of crimes that appeared: "<<arrCriminalNr[0]<<endl;
*/
    cout<<"------------------------------------------------------"<<endl;
    cout<<"PART 3:"<<endl;

    double arr3[1476];

    for(int i=1;i<=551;i++)
    {
        double avg = 0;
        for(int k=0;k<=arrCriminalNr.size();k++)
        {
            if(i == arrCriminalNr[k])
            {
                avg++;
                //cout<<"Criminal with number"<<" "<<i<<"has "<<avg<<"persons"<<endl;
            }
        }
        arr3[i] = avg;
    }

    double suma3 = 0;

    for(int l = 0;l <= 551; l++)
    {
        suma3+=arr3[l];
    }
    suma3=suma3/551;

    cout<<"The average number of people involved in a crime is equal to:"<<" "<<suma3<<endl;



//PART 4
/*
 * This is the part of code for PART 4 from question 1
 * In this part I wrote code that will circle through 2 for loops again and compare values of crimes and values of appearance of crimes from "crime.txt"
 * The number of crimes appearance and persons appearance will be stored into array which will be used later on to calculate the average
 * The code is pretty much the same as in previous one, just different variables and values
 * The output will be the maximum numbmer of people that appeared in selected crime
 */
    cout<<"------------------------------------------------------"<<endl;
    cout<<"PART 4:"<<endl;

    double arr4[551];
    int x4;

    cout << "Enter the criminal number:" << endl;   //In this part, you will get to select which crime you want to check
    cin >> x4;

    for (int i = 1; i <= 551; i++)
    {
        double avg = 0;
        for (int k = 0; k <= arrCriminalNr.size(); k++)
        {
            if (i == arrCriminalNr[k])
            {
                avg++;
                //cout<<"Criminal with number"<<" "<<i<<"has "<<avg<<"persons"<<endl;
            }
        }
        if (x4 == i)
        {
            cout << "Maximum number of people involved in crime number:" << " " << x4<< " " << " was :" << " "<< avg << endl;
            cout<<"------------------------------------------------------"<<endl;
            arr4[i] = avg;
        }
    }
    /*
     * Next lines of code (from line 277 to line 608) is only used to check if the results are correct
     * The method used to check this was very long and it collected all appearances one by one
     * This is not part of the actual code for project, but it will be left here in case you want to check number of occurences
     * YOU CAN JUST EITHER SKIP THOSE LINES OR DELETE THEM
     */

//CHECK FOR PART 1
/*
    double arr[829];
int c1 = 0;
int c2 = 0;
int c3 = 0;
int c4 = 0;

    int c5 = 0;
    int c6 = 0;
    int c7 = 0;
    int c8 = 0;
    int c9 = 0;
    int c10 = 0;
    int c11 = 0;
    int c12 = 0;
    int c13 = 0;
    int c14 = 0;
    int c15 = 0;
    int c16 = 0;
    int c17 = 0;
    int c18 = 0;
    int c19 = 0;
    int c20 = 0;
int c21 = 0;
int c22 = 0;
int c = 0;
    for(int i=1;i<=829;i++){
        double avg = 0;
        for(int k=0;k<=arrPersonNr.size();k++){
            if(i == arrPersonNr[k]){
                //cout<<"The person"<<" "<<array_names[i]<<", appeared in criminal number "<< k+1<<endl;
                avg++;
            }

        }
        if(avg == 1){
            c1++;
        }

        else if(avg == 2){
            c2++;
        }

        else if(avg == 3){
            c3++;
        }

        else if(avg == 4){
            c4++;
        }

        else if(avg == 5){
            c5++;
        }

        else if(avg == 6){
            c6++;
        }

        else if(avg == 7){
            c7++;
        }

        else if(avg == 8){
            c8++;
        }

        else if(avg == 9){
            c9++;
        }

        else if(avg == 10){
            c10++;
        }

        else if(avg == 11){
            c11++;
        }

        else if(avg == 12){
            c12++;
        }

        else if(avg == 13){
            c13++;
        }

        else if(avg == 14){
            c14++;
        }

        else if(avg == 15){
            c15++;
        }

        else if(avg == 16){
            c16++;
        }

        else if(avg == 17){
            c17++;
        }

        else if(avg == 18){
            c18++;
        }

        else if(avg == 19){
            c19++;
        }

        else if(avg == 20){
            c20++;
        }

        else if(avg == 21){
            c21++;
        }

        else if(avg == 22){
            c22++;
        }

        else if(avg == 25){
            c++;
        }
        arr[i] = avg;

    }

    cout<<"Number of 1: "<<c1<<endl;
    cout<<"Number of 2: "<<c2<<endl;
    cout<<"Number of 3: "<<c3<<endl;
    cout<<"Number of 4: "<<c4<<endl;
    cout<<"Number of 5: "<<c5<<endl;
    cout<<"Number of 6: "<<c6<<endl;
    cout<<"Number of 7: "<<c7<<endl;
    cout<<"Number of 8: "<<c8<<endl;
    cout<<"Number of 9: "<<c9<<endl;
    cout<<"Number of 10: "<<c10<<endl;
    cout<<"Number of 11: "<<c11<<endl;
    cout<<"Number of 12: "<<c12<<endl;
    cout<<"Number of 13: "<<c13<<endl;
    cout<<"Number of 14: "<<c14<<endl;
    cout<<"Number of 15: "<<c15<<endl;
    cout<<"Number of 16: "<<c16<<endl;
    cout<<"Number of 17: "<<c17<<endl;
    cout<<"Number of 18: "<<c18<<endl;
    cout<<"Number of 19: "<<c19<<endl;
    cout<<"Number of 20: "<<c20<<endl;
    cout<<"Number of 21: "<<c21<<endl;
    cout<<"Number of 22: "<<c22<<endl;
    cout<<"Number of 25: "<<c<<endl;
    */
//CHECK FOR PART 3
/*
    double arr[829];
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;

    int c5 = 0;
    int c6 = 0;
    int c7 = 0;
    int c8 = 0;
    int c9 = 0;
    int c10 = 0;
    int c11 = 0;
    int c12 = 0;
    int c13 = 0;
    int c14 = 0;
    int c15 = 0;
    int c16 = 0;
    int c17 = 0;
    int c18 = 0;
    int c19 = 0;
    int c20 = 0;
    int c21 = 0;
    int c22 = 0;
    int c = 0;
//TO FIND NUMBER OF CRIMINALS THAT OCCURED IN TOTAL
    for(int i = 1;i < arrCriminalNr.size(); ++i)
    {
        // Change < to > if you want to find the smallest element
        if(arrCriminalNr[0] < arrCriminalNr[i])
            arrCriminalNr[0] = arrCriminalNr[i];
    }
    cout<<arrCriminalNr[0]<<endl;
//

    for(int i=1;i<=551;i++){
        double avg = 0;
        for(int k=0;k<=arrCriminalNr.size();k++){
            if(i == arrCriminalNr[k]){
                avg++;
                //cout<<"Criminal with number"<<" "<<i<<"has "<<avg<<"persons"<<endl;
            }
        }
        arr[i] = avg;
        if(avg == 1){
            c1++;
        }

        else if(avg == 2){
            c2++;
        }

        else if(avg == 3){
            c3++;
        }

        else if(avg == 4){
            c4++;
        }

        else if(avg == 5){
            c5++;
        }

        else if(avg == 6){
            c6++;
        }

        else if(avg == 7){
            c7++;
        }

        else if(avg == 8){
            c8++;
        }

        else if(avg == 9){
            c9++;
        }

        else if(avg == 10){
            c10++;
        }

        else if(avg == 11){
            c11++;
        }

        else if(avg == 12){
            c12++;
        }

        else if(avg == 13){
            c13++;
        }

        else if(avg == 14){
            c14++;
        }

        else if(avg == 15){
            c15++;
        }

        else if(avg == 16){
            c16++;
        }

        else if(avg == 17){
            c17++;
        }

        else if(avg == 18){
            c18++;
        }

        else if(avg == 19){
            c19++;
        }

        else if(avg == 20){
            c20++;
        }

        else if(avg == 21){
            c21++;
        }

        else if(avg == 22){
            c22++;
        }

        else if(avg == 25){
            c++;
        }
        arr[i] = avg;

    }
    cout<<"Number of 1: "<<c1<<endl;
    cout<<"Number of 2: "<<c2<<endl;
    cout<<"Number of 3: "<<c3<<endl;
    cout<<"Number of 4: "<<c4<<endl;
    cout<<"Number of 5: "<<c5<<endl;
    cout<<"Number of 6: "<<c6<<endl;
    cout<<"Number of 7: "<<c7<<endl;
    cout<<"Number of 8: "<<c8<<endl;
    cout<<"Number of 9: "<<c9<<endl;
    cout<<"Number of 10: "<<c10<<endl;
    cout<<"Number of 11: "<<c11<<endl;
    cout<<"Number of 12: "<<c12<<endl;
    cout<<"Number of 13: "<<c13<<endl;
    cout<<"Number of 14: "<<c14<<endl;
    cout<<"Number of 15: "<<c15<<endl;
    cout<<"Number of 16: "<<c16<<endl;
    cout<<"Number of 17: "<<c17<<endl;
    cout<<"Number of 18: "<<c18<<endl;
    cout<<"Number of 19: "<<c19<<endl;
    cout<<"Number of 20: "<<c20<<endl;
    cout<<"Number of 21: "<<c21<<endl;
    cout<<"Number of 22: "<<c22<<endl;
    cout<<"Number of 25: "<<c<<endl;

    double suma = 0;
    for(int l = 0;l <= 551; l++){
        suma+=arr[l];
    }

    suma=suma/551;

    cout<<"The average number of people involved in crime is"<<" "<<suma<<endl;


*/

//PART 5
/*
 * This is the part of code for PART 5 from question 1
 * In this part of code, I worked with read/write to files in c++
 * Since we need to plot the histogram of frquency of average appearances of people in crimes,
 * I firstly calculated how many of them appeared only in one crime, how many of them appeared in two rimes and so on...
 * At the end I got array of numbers which represents their apperances and with ifstream option,
 * I wrote this information from program to a txt file called "part5.txt"
 * That txt file was saved and later on opened with R Studio to examine the data and plot the histogram
 */

    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    int c5 = 0;
    int c6 = 0;
    int c7 = 0;
    int c8 = 0;
    int c9 = 0;
    int c10 = 0;
    int c11 = 0;
    int c12 = 0;
    int c13 = 0;
    int c14 = 0;
    int c15 = 0;
    int c16 = 0;
    int c17 = 0;
    int c18 = 0;
    int c19 = 0;
    int c20 = 0;
    int c21 = 0;
    int c22 = 0;
    int c23 = 0;
    int c24 = 0;
    int c25 = 0;
    for(int i=1;i<=829;i++)
    {
        double avg = 0;
        for(int k=0;k<=arrPersonNr.size();k++)
        {
            if(i == arrPersonNr[k])
            {
                //cout<<"The person"<<" "<<array_names[i]<<", appeared in criminal number "<< k+1<<endl;
                avg++;
            }
        }
        if(avg == 1){
            c1++;
        }

        else if(avg == 2){
            c2++;
        }

        else if(avg == 3){
            c3++;
        }

        else if(avg == 4){
            c4++;
        }

        else if(avg == 5){
            c5++;
        }

        else if(avg == 6){
            c6++;
        }

        else if(avg == 7){
            c7++;
        }

        else if(avg == 8){
            c8++;
        }

        else if(avg == 9){
            c9++;
        }

        else if(avg == 10){
            c10++;
        }

        else if(avg == 11){
            c11++;
        }

        else if(avg == 12){
            c12++;
        }

        else if(avg == 13){
            c13++;
        }

        else if(avg == 14){
            c14++;
        }

        else if(avg == 15){
            c15++;
        }

        else if(avg == 16){
            c16++;
        }

        else if(avg == 17){
            c17++;
        }

        else if(avg == 18){
            c18++;
        }

        else if(avg == 19){
            c19++;
        }

        else if(avg == 20){
            c20++;
        }

        else if(avg == 21){
            c21++;
        }

        else if(avg == 22){
            c22++;
        }

        else if(avg == 23){
            c23++;
        }

        else if(avg == 24){
            c24++;
        }
        else if(avg == 25){
            c25++;
        }
        arr[i] = avg;

    }
    fstream file;
    file.open ("part5", ios::out | ios::in );
    file <<1 << " "<< c1 << endl;
    file <<2 << " "<< c2 << endl;
    file <<3 << " "<< c3 << endl;
    file <<4 << " "<< c4 << endl;
    file <<5 << " "<< c5 << endl;
    file <<6 << " "<< c6 << endl;
    file <<7 << " "<< c7 << endl;
    file <<8 << " "<< c8 << endl;
    file <<9 << " "<< c9 << endl;
    file <<10 << " "<< c10 << endl;
    file <<11 << " "<< c11 << endl;
    file <<12 << " "<< c12 << endl;
    file <<13 << " "<< c13 << endl;
    file <<14 << " "<< c14 << endl;
    file <<15 << " "<< c15 << endl;
    file <<16 << " "<< c16 << endl;
    file <<17 << " "<< c17 << endl;
    file <<18 << " "<< c18 << endl;
    file <<19 << " "<< c19 << endl;
    file <<20 << " "<< c20 << endl;
    file <<21 << " "<< c21 << endl;
    file <<22 << " "<< c22 << endl;
    file <<23 << " "<< c23 << endl;
    file <<24 << " "<< c24 << endl;
    file <<25 << " "<< c25 << endl;

//PART 6
/*
 * Same story as for part 5, only the nubmer of criminals were stored to a txt file called "part6.txt"
 * Then opened in R Studio and exaimed the data
 */

    fstream file1;
    file1.open ("part6", ios::out | ios::in );
    for(int i = 0;i <= arrCriminalNr.size(); i++)
    {
        file1<<arrCriminalNr[i]<<endl;
    }

}