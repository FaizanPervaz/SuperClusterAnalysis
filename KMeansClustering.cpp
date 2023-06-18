//20I0565_F_Faizan Pervaz
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<math.h>
using namespace std;

class Class1
{
public:

	void Task1()
	{
		//opening the file using ifstream library from the directory
		ifstream myfile;
		myfile.open("driver-data.csv");
		string tempstring;			//making a temmporary string to store data from the csv and then converting it to double and storing it in the dynammic allocated arrays   

		//initializing a 2d array of 40000 rows and 4 coloumns
		double** array = new double* [4000];
		for (int i = 0; i < 4000; i++)
		{
			array[i] = new double[4];
		}

		for (int i = 0; i < 4000; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				array[i][j] = 0.0;
			}
		}

		//skipping the first wholel row ine of id, mean distance and mean over percentage 
		getline(myfile, tempstring);

		//while (myfile.is_open())	//until the file is open the data must read for 4001 entries as i is initiallized to 0 
		//{
		for (int i = 0; i < 4000; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j != 2)
				{
					getline(myfile, tempstring, ',');
					array[i][j] = stod(tempstring);	//stod function to convert string to double or float
					tempstring = "";
				}
				else if (j == 2)
				{
					getline(myfile, tempstring, '\n');
					array[i][j] = stod(tempstring);	//stod function to convert string to double or float
					tempstring = "";
				}
			}
		}
		//}
		myfile.close();	//closing the file after running all 4001 entries

		//checking output of all id's

		//for (int i = 0; i < 4000; i++)
		//{
		//	cout << i << endl;
		//	for (int j = 0; j < 3; j++)
		//	{
		//		//cout << i << endl;
		//		cout << array[i][j] << endl;
		//	}
		//}


		//assigning values to the cluster from the csv file, i have made 4 clusters
		double cluster1[2] = { 71.24,28 };
		double cluster2[2] = { 52.53,25 };
		double cluster3[2] = { 64.54,27 };
		double cluster4[2] = { 55.69,22 };

		//making variables for applying Euclidean Distance formula
		double cmp1 = 0;
		double cmp2 = 0;
		double cmp3 = 0;
		double cmp4 = 0;

		double newcluster1[2] = { 71.24,28 };
		double newcluster2[2] = { 52.53,25 };
		double newcluster3[2] = { 64.54,27 };
		double newcluster4[2] = { 55.69,22 };

		//making a variable to find the nearest cluster
		double smol = 0.00;

		bool check = true;
		//skipping the first four(4) entries as they are already being hard coded with x and y values and getting them cluster numbering
		for (int i = 0; i < 4; i++)
		{
			array[i][3] = i + 1;
		}
		//applying the loop from the 5th value skipping the first 4 entries

		for (int i = 4; i < 4000; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				newcluster1[0] = cluster1[0];
				newcluster2[0] = cluster2[0];
				newcluster3[0] = cluster3[0];
				newcluster4[0] = cluster4[0];
				newcluster1[1] = cluster1[1];
				newcluster2[1] = cluster2[1];
				newcluster3[1] = cluster3[1];
				newcluster4[1] = cluster4[1];

				while (check)
				{
					cmp1 = sqrt((pow(newcluster1[0] - array[i][1], 2) + (pow(newcluster1[1] - array[i][2], 2))));			//finding out euclidean distance from the data and cluster 1
					//cout << cmp1 << "---"<< newcluster1[0] << endl;
					cmp2 = sqrt((pow(newcluster2[0] - array[i][1], 2) + (pow(newcluster2[1] - array[i][2], 2))));			//finding out euclidean distance from the data and cluster 2
					//cout << cmp2 << "---" << newcluster2[0] << endl;
					cmp3 = sqrt((pow(newcluster3[0] - array[i][1], 2) + (pow(newcluster3[1] - array[i][2], 2))));			//finding out euclidean distance from the data and cluster 3
					//cout << cmp3 << "---" << newcluster3[0] << endl;
					cmp4 = sqrt((pow(newcluster4[0] - array[i][1], 2) + (pow(newcluster4[1] - array[i][2], 2))));			//finding out euclidean distance from the data and cluster 4
					//cout << cmp4 << "---" << newcluster4[0] << endl;

			//finding the nearest cluster
					smol = min(cmp1, cmp2);
					smol = min(smol, cmp3);
					smol = min(smol, cmp4);

					//cout << "Smallest Vlaue : " << smol << endl;
					if (smol == cmp1)											//putting conditions to check which cluster does the data belong
					{
						array[i][3] = 1;
					}
					else if (smol == cmp2)
					{
						array[i][3] = 2;
					}
					else if (smol == cmp3)
					{
						array[i][3] = 3;
					}
					else if (smol == cmp4)
					{
						array[i][3] = 4;
					}

					newcluster1[0] = (array[i][1] + newcluster1[0]) / 2;		//finding new centroid
					newcluster1[1] = (array[i][2] + newcluster1[1]) / 2;
					newcluster2[0] = (array[i][1] + newcluster2[0]) / 2;		//finding new centroid
					newcluster2[1] = (array[i][2] + newcluster2[1]) / 2;
					newcluster3[0] = (array[i][1] + newcluster3[0]) / 2;		//finding new centroid
					newcluster3[1] = (array[i][2] + newcluster3[1]) / 2;
					newcluster4[0] = (array[i][1] + newcluster4[0]) / 2;		//finding new centroid
					newcluster4[1] = (array[i][2] + newcluster4[1]) / 2;


					if (smol < 1)
					{
						check = false;
					}
					else
						check = true;
				}
			}
			check = true;
		}
		//checking output of all id's
	//
		/*for (int i = 0; i < 4000; i++)
		{
			cout << i << "  " << array[i][3] << endl;
		}*/

		//	//now writing it into the csv file
		ofstream outputfile;
		outputfile.open("output.csv", ios::out | ios::app);

		tempstring = "";
		outputfile << "id" << "," << "mean_dist_day" << "," << "mean_over_speed_perc" << "," << "output" << "\n";			//hardcoding id, mean dist and mean percentage and output in the first coloumn
		int i = 0;
		//while (outputfile.is_open())		//now opening file to write data into the csv file till 40001 entries
		//{
		for (int i = 0; i < 4000; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (j != 3)
				{
					tempstring = to_string(array[i][j]);	//converting the double data of the id into a temporary string 
					outputfile << tempstring << ",";		//writing into the csv file
					tempstring = "";						//making the string empty
				}
				else if (j == 3)
				{
					tempstring = to_string(array[i][j]);	  //converting the double data of the output into a temporary string 
					outputfile << tempstring << "\n";		 //writing into the csv file
					tempstring = "";						 //making the string empty
				}
			}
		}
		outputfile.close();							//closing and generating the csv file
	}
	void Task2()
	{
		//opening the segmented_customers-1.csv file
		ifstream myfile;
		myfile.open("segmented_customers-1.csv");

		//making a string array for 200 id's
		string* gender = new string[200];
		for (int i = 0; i < 200; i++)
		{
			gender[i] = "\0";
		}

		//making a 3d array for 2000 rows and 5 coloumns all pointing by an array
		double*** array = new double** [1];
		for (int i = 0; i < 1; i++)
		{
			array[i] = new double* [200];

			for (int j = 0; j < 200; j++)
			{
				array[i][j] = new double[5];
			}
		}

		//initiallizing the 3d array
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 200; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					array[i][j][k] = 0.00;
				}
			}
		}

		string temp = "";
		getline(myfile, temp);
		//skipping the first line


		for (int i = 0; i < 1; i++)		//pointing to first array
		{
			for (int j = 0; j < 200; j++)	//pointing to rows of the array
			{
				for (int k = 0; k < 4; k++)		//pointing to the coloumns of the array without the output one
				{
					if (k == 1)
					{
						getline(myfile, temp, ',');		//storing gender 
						gender[j] = temp;
						temp = "";

						getline(myfile, temp, ',');		//storing age
						array[i][j][k] = stod(temp);
						temp = "";
					}
					else if (k == 3)
					{
						getline(myfile, temp, '\n');	//when k==3 storing spending score
						array[i][j][k] = stod(temp);
						temp = "";
					}
					else {								//firstly it will run into k==0 and store id 
						getline(myfile, temp, ',');		//in second iteration storing income
						array[i][j][k] = stod(temp);
						temp = "";
					}
				}
			}
		}
		myfile.close();		//closing the file

		//checking the storing of array 

		/*for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 200; j++)
			{
				cout << gender[i] << " ";
				for (int k = 0; k < 4; k++)
				{
					cout << array[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}*/

		//assigning values to the cluster
		double cluster1[3] = { 19,15,39 };
		double cluster2[3] = { 21,15,81 };
		double cluster3[3] = { 20,16,6 };
		double cluster4[3] = { 23,16,77 };

		double mean_cluster1[3] = {};
		double mean_cluster2[3] = {};
		double mean_cluster3[3] = {};
		double mean_cluster4[3] = {};

		double cmp1 = 0;
		double cmp2 = 0;
		double cmp3 = 0;
		double cmp4 = 0;

		//making a variable to find the nearest cluster
		double smol = 0;

		//skipping the first four(4) entries as they are already being hard coded with x and y values and getting them cluster numbering
		array[0][0][4] = 1;
		array[0][1][4] = 2;
		array[0][2][4] = 3;
		array[0][3][4] = 4;

		bool check = true;
		//applying the loop from the 5th value skipping the first 4 entries

		for (int j = 0; j < 3; j++)
		{
			for (int i = 4; i < 200; i++)
			{
				cmp1 = sqrt((pow(cluster1[0] - array[0][i][1], 2) + (pow(cluster1[1] - array[0][i][2], 2)) + (pow(cluster1[2] - array[0][i][3], 2))));			//finding out euclidean distance from the data and cluster 1
				cmp2 = sqrt((pow(cluster2[0] - array[0][i][1], 2) + (pow(cluster2[1] - array[0][i][2], 2)) + (pow(cluster2[2] - array[0][i][3], 2))));			//finding out euclidean distance from the data and cluster 2
				cmp3 = sqrt((pow(cluster3[0] - array[0][i][1], 2) + (pow(cluster3[1] - array[0][i][2], 2)) + (pow(cluster3[2] - array[0][i][3], 2))));			//finding out euclidean distance from the data and cluster 3
				cmp4 = sqrt((pow(cluster4[0] - array[0][i][1], 2) + (pow(cluster4[1] - array[0][i][2], 2)) + (pow(cluster4[2] - array[0][i][3], 2))));			//finding out euclidean distance from the data and cluster 4

				//finding the nearest cluster
				smol = min(cmp1, cmp2);
				smol = min(smol, cmp3);
				smol = min(smol, cmp4);

				if (smol == cmp1)											//putting conditions to check which cluster does the data belong
				{
					array[0][i][4] = 1;
					mean_cluster1[0] = (array[0][i][1] + cluster1[0]) / 2;		//finding new centroid
					mean_cluster1[1] = (array[0][i][2] + cluster1[1]) / 2;
					mean_cluster1[2] = (array[0][i][3] + cluster1[2]) / 2;
				}
				else if (smol == cmp2)
				{
					array[0][i][4] = 2;
					mean_cluster2[0] = (array[0][i][1] + cluster2[0]) / 2;		//finding new centroid
					mean_cluster2[1] = (array[0][i][2] + cluster2[1]) / 2;
					mean_cluster2[2] = (array[0][i][3] + cluster2[2]) / 2;
				}
				else if (smol == cmp3)
				{
					array[0][i][4] = 3;
					mean_cluster3[0] = (array[0][i][1] + cluster3[0]) / 2;		//finding new centroid
					mean_cluster3[1] = (array[0][i][2] + cluster3[1]) / 2;
					mean_cluster3[2] = (array[0][i][3] + cluster3[2]) / 2;
				}
				else if (smol == cmp4)
				{
					array[0][i][4] = 4;
					mean_cluster4[0] = (array[0][i][1] + cluster4[0]) / 2;		//finding new centroid
					mean_cluster4[1] = (array[0][i][2] + cluster4[1]) / 2;
					mean_cluster4[2] = (array[0][i][3] + cluster4[2]) / 2;
				}
			}
		}
		//checking output 
		/*for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << gender[j]<<" ";
				for (int k = 0; k < 5; k++)
				{
					cout << array[i][j][k]<<" ";
				}
				cout << endl;
			}
			cout << endl;
		}*/

		//writing into the file
		ofstream outputfile;
		outputfile.open("output1.csv", ios::out | ios::app);

		string tempstring = "";
		outputfile << "CustomerID" << "," << "Gender" << "," << "Age" << "," << "Annual Income (k$)" << "," << "Spending Score (1-100)" << "," << " Output " << "\n";
		int i = 0;

		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 200; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (k == 1)
					{
						outputfile << gender[j] << ",";						//writing gender 

						outputfile << to_string(array[i][j][k]) << ",";		//writing age
					}
					else if (k == 4)
					{
						outputfile << to_string(array[i][j][k]) << "\n";	//writing the output

					}
					else {
						outputfile << to_string(array[i][j][k]) << ",";			//writing the id in k==0
						//writing income and score then
					}
				}
			}
		}
		myfile.close();
		//closing the file
	}
};
int main()
{
	Class1 Ass;
	Ass.Task1();
	Ass.Task2();
}