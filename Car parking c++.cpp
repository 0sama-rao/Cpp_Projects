#include<iostream>
#include<string>
#include<fstream>	//for read and write
void call(void); //function for read	
using namespace std;
int main()
{
	system("color e");			//For Yellow color
	
string id="bilal",pass="12345";		////////////////////
string id1,pass1;				   ////////////////////

cout<<"\t\t\t\tLOGIN FORM"<<endl;
cout<<"\t\t\t\t~~~~~~~~~~\n"<<endl;
cout<<"LOGIN ID : ";
cin>>id1;
cout<<"PASSWORD : ";
cin>>pass1;

if(id1==id && pass1==pass)		//login id if
{

cout<<"\t\t\t\tWELCOME TO CAR PARKING SYSTEM PROGRAM!"<<endl;
cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<<" CHOOSE WHAT DO YOU WANT !!!\n"<<endl;

char X;						////////////////////

cout<<"---DO YOU WANT TO CREATE NEW RECORD ( Y/N )    : ";
cin>>X;
while(X != 'n')		//start (new record)
{
		call();
		cout<<"---DO YOU WANT TO CREATE NEW RECORD ( Y/N )    : ";	
        cin>>X;	
        cout<<endl;	
}					//End (new record)


cout<<"\n---DO YOU WANT TO VIEW RECORD ( Y/N ) : ";
cin>>X;
if(X=='y' || X=='Y')	//Start if (view record)
{
ifstream read("BILL.txt");
    string line;	
    while(! read.eof())			//read full reord
    {	
    getline(read,line);		//getline use for string value with "space"
    cout<<line<<endl;	
    }	

}						//End if (view record)



cout<<"\n---DO YOU WANT TO DELETE RECORDS ( Y/N ) : ";
cin>>X;
if(X == 'Y'|| X=='y')//start (new record)
{
	
// Start file save

ofstream create("BILL.txt");
create<<""<<endl;

// end file save	

    cout<<"\n\n\t\t\t\tALL DATA REMOVED SUCCESSFULLY!!!"<<endl;	
    cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;		
}
else	
{
cout<<"\n\n\t\t\t\t-----------------------------------------"<<endl;
cout<<"\t\t\t\tTHANK YOU FOR USING OUR SERVICE!"<<endl;
cout<<"\t\t\t\t-----------------------------------------"<<endl;
}
	
}			//end login if
else
{
	cout<<"\n\n\t\t\t\tInvalid id and password!!!"<<endl;
}
return 0;  
}

//***************************************************************************************************

void call(void)
{
int id,time,sum=0;				     ////////////////////
char c;						   		////////////////////
string name,city,nic,car,phone;	   ////////////////////
	
	
cout<<"------------------------------------------------------"<<endl;
cout<<"PLEASE ENTER THE REQUIRED INFORMATION FROM CAR PARKING"<<endl;
cout<<"------------------------------------------------------";

cout<<"\nCUSTOMER ID                      : = ";
cin>>id;

cout<<"\nENTER NAME                       : = ";
cin>>name;

cout<<"\nENTER CNIC NO                    : = ";
cin>>nic;

cout<<"\nENTER CITY                       : = ";
cin>>city;

cout<<"\nENTER PHONE NO                   : = ";
cin>>phone;

cout<<"\nENTER CAR NO                     : = ";
cin>>car;

cout<<"\nENTER CAR PARKING TIME ( hour )  : = ";
cin>>time;
if(time <0)
	{
		cout<<"\t\t\tHOUR IS NOT IN NEGATIVE! DO YOY WANT TO CONTINUE ( Y / N )!!!"<<endl;
		cout<<"\t\t\t**********************************************************\n : ";
		cin>>c;
		if(c=='y'|| c=='Y')
		{
		cout<<"\nENTER CAR PARKING TIME ( hour )"<<endl;
		cin>>time;
		}	
		else if(c =='n'|| c=='Y')
		{
			cout<<"\tTHANK YOU!!"<<endl;
		}
	}
	sum=30*time;

cout<<"\nTOTAL = (CHARGES X HOURS)        : = "<<sum<<" RS"<<endl;
cout<<"\n*************************************************************************************************"<<endl;

// Start file save

ofstream create("BILL.txt", ios::app);
create<<"\n*************************************************************************************************"<<endl;
create<<"\t\t\t\t=====================\n\t\t\t\t.....R.E.C.I.P.T.....\n\t\t\t\t====================="<<endl;
create<<"\nCUSTOMER ID           = "<<id<<"\nNAME                  = "<<name<<"\nCNIC NUMBER           = "<<nic;
create<<"\nCITY                  = "<<city<<"\nPHONE NUMBER          = "<<phone;
create<<"\nCAR NUMBER            = "<<car<<"\nPARKED TIME (hour)    = "<<time<<"\nTOTAL CHARGES         = "<<sum;	
create<<"\n\t\t\t-----------------------------------------\n\t\t\tTHANK YOU FOR USING OUR SERVICE!\n\t\t\t-----------------------------------------\n";	
create<<"\n*************************************************************************************************"<<endl;
// end file save				
}



/*
When ios::ate is set, the initial position will be the end of the file, 
but you are free to seek thereafter.
When ios::app is set, all output operations are performed at the end of the file.	
 */
		
