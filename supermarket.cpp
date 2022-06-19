/*
UNITED SUPERMARKET
PASSWORD FOR OWNER IS owner
PASSWORD FOR EMPLOYEE IS admin12
*/

#include<iostream>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include<math.h>
#include<fstream>
#include<cstdio>
#include<windows.h>
using namespace std;
//void view_cart();
int main();
void menu();
void selection();
int owner();

ifstream fin;
ofstream fout;
fstream fio;

class supermart{
	string name,address;
	public:
		void setname(string n){
			name=n;
		}
		void setaddress(string ad){
			address=ad;
		}
		string getname(){
			return name;
		}
		string getaddress(){
			return address;
		}
};
class employee:public supermart
{
    private:
        // Variables for employee details
        char name[30];
        char lname[30];
        char id[10];
        char designation[10];
        int age;
        int salary;
        int experience;
        // Utility functions
        void waitForEnter()
		{
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }

        void listEmployees()
		{
            system("cls");
            FILE *file;
            file= fopen("Employeedata.dat", "r");
            cout<<"\n\t      List of Employees\n";
            cout<<"\n FIRST NAME        |    LAST NAME     |    ID     |     DESIGNATION\n";
            cout<<"----------------------------------------------";
            while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lname[0], &id[0] , &designation[0], &age, &salary, &experience)!= EOF)
                cout<<"\n"<<name<<"\t\t\t"<<lname<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
            waitForEnter();
        }

        void showDetails()
		{ //Displays all details according to Employee's id
            system("cls");
            FILE *file;
            char checkId[5];
            int test=0;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("Employeedata.dat", "r");
            while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lname[0], &id[0] , &designation[0], &age, &salary, &experience)!=EOF)
            {
                if(strcmp(checkId,id)==0)
				{
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nLast Name: "<<lname;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age;
                    cout<<"\n---------------------";
                    cout<<"\nSalary: "<<salary;
                    cout<<"\n---------------------";
                    cout<<"\nExperience: "<<experience;
                    cout<<"\n---------------------";
                    test++;
                }
            }
                if(test==0)
                {
                	cout<<"\n-----------------------------"<<endl;
                	cout<<"RECORD NOT FOUND!";
				}
        
            fclose(file);
            waitForEnter();
        }

        void editExisting(){ //edits Designation and Salary of an employee
            system("cls");
            char checkId[5];
            int test=0;
            char newDesignation[10];
            int newSalary;
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            FILE *file, *tempfile;
            file= fopen("Employeedata.dat", "r");
            tempfile= fopen("temp.dat", "w");
            while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lname[0], &id[0] , &designation[0], &age, &salary, &experience)!=EOF)
			{
			if(strcmp(checkId, id)==0)
			{
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>designation;
            cout<<"------------------------------";
            cout<<"\nEnter new Salary: ";
            cin>>salary;
            cout<<"\t\tEmployee Data has been modified successfully";
            test++;
            
        	}
        	fprintf(tempfile, "%s %s %s %s %d %d %d \n", name,lname, id, designation, age, salary, experience );
        }
            if(test==0)
            {
			cout<<"\n\t\t\t RECORD NOT FOUND!"<<endl;        
        	}
        	
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("Employeedata.dat");
            int isRenamed= rename("temp.dat", "Employeedata.dat");
            waitForEnter();
        }

        void addNewEmployee(){ //adding records
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of Employee: ";
            cin>>name;
            cout<<"\n Enter Last Name of Employee: ";
            cin>>lname;
            cout<<"\n Enter Employee ID : ";
            cin>>id;
           /* if( id[4]!='\0')
            {
            	cout<<"\nPlease enter a valid ID"<<endl;
            	getch();
            	addNewEmployee();
			}*/
            cout<<"\n Enter Designation: ";
            cin>>designation;
            age:
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            if(age>99)
            	{
            		cout<<"\nPlease enter correct age";
            		goto age;
				}
            cout<<"\n Enter Employee Salary: ";
            cin>>salary;
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;
            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y' || ch=='Y'){
                FILE  *file;
                file= fopen("Employeedata.dat","a");
                fprintf(file, "%s %s %s %s %d %d %d \n", name, lname, id, designation, age, salary, experience );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
            waitForEnter();
            options();
        }

        void deleteEmployeeDetails()
		{ //removing records
            system("cls");
            char checkId[5];char ch;
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            int test=0;
            FILE *file, *tempfile;
            file= fopen("Employeedata.dat", "r");
            tempfile= fopen("temp.dat", "w");
            while(fscanf(file, "%s %s %s %s %d %d %d", &name[0], &lname[0], &id[0] , &designation[0], &age, &salary, &experience)!=EOF)
            {
			if(strcmp(checkId, id)==0)
            {
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            	if(ch=='y' || ch=='Y')
            	{
            	   test++;
				  cout<<"\nRecord Removed Successfully\n";
				}
				else{
				deleteEmployeeDetails();
				}
			}
			else
			{
				fprintf(tempfile, "%s %s %s %s %d %d %d \n", name, lname, id, designation, age, salary, experience );
			}
        }
        if(test==0)
            {
			cout<<"\n\t\t\t RECORD NOT FOUND!"<<endl;        
        	}
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("Employeedata.dat");
                int isRenamed= rename("temp.dat", "Employeedata.dat");
                waitForEnter();
            }
         


    public:
        
        void options(void)
		{ 
            while(true){
                system("cls");
                
                // Options to choose an action
                cout<<"\n\t\t\t--------- TOGETHER AT HOME SUPERMARKET  -----------";
				cout<<"\n\t\t\t--------- EMPLOYEE DIRECTORY  -----------";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t  1:   To View List of Employees";
                cout<<"\n\t\t  2:   To View Employee Details";
                cout<<"\n\t\t  3:   To Modify Existing Employee Details";
                cout<<"\n\t\t  4:   To Add New Employee Details";
                cout<<"\n\t\t  5:   To Remove an Employee Details";
                cout<<"\n\t\t  0:   To Return     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                int choice;
                cin>>choice;

                switch (choice) {
                    case 0:
                    	system("CLS");
                    	cout<<"Returning to main menu"<<endl;
                        menu();
                        selection();
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    default:
                        cout<<"\n Please Enter a valid choice \n";
                        break;
                }

            }
        }

};

class stock:public supermart
{
	char name[30];
	int p_id;
	void get();
	void get2();
	float pr; int quant;
	float netamt, covid_disc;


  // static float grossamt;
    void refil(int qty);
    void withd(int qty);
    void addnew();
    static float grossamt;
    
    void deleteitem();
	  
public:
	int stchk(int);
	void withdraw();
	void calculate_bill();
	void printbill();
	void refill();void show(); void disp();
	float getgross()
	{
		return grossamt;
	}
	float getpr()
	{
		return pr;
	}
	float getquant()
	{
		return quant;
	}
	string getName()
	{
		return name;
	}
	int getpid()
	{
		return p_id;
	}
	void inventory()
	{
		system("CLS");
		    cout<<"\n\t\t\t--------- TOGETHER AT HOME SUPERMARKET  -----------";
				cout<<"\n\t\t\t--------- STOCK DIRECTORY  -----------";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t  1:   To View List of Available Items";
                cout<<"\n\t\t  2:   To Refill an Item";
                cout<<"\n\t\t  3:   To Add New Product to the list";
                cout<<"\n\t\t  4:   To Remove an Item";
                cout<<"\n\t\t  0:   To Return     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                int choice;
                cin>>choice;

                switch (choice) {
                    case 0:
                    	system("CLS");
                        owner();
                        Sleep(10);
                        return;
                    case 1:
                        disp();
                        inventory();
                        break;
                    case 2:
                        refill();
                        break;
                    case 3:
                        addnew();
                        break;
                    case 4:
                        deleteitem();
                        break;
                    default:
                        cout<<"\n Please Enter a valid choice \n";
                        break;
                }
	}
}st;
float stock::grossamt=0.0;

void stock:: withd(int qty)
	{
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock updated.\n";
		cout<<"\n\nTotal price to be paid for this item: "<<pr*qty;
		grossamt+=(pr*qty);
    }
	else 
	   cout<<"\n\nInsufficient stock";
	    getch();
		
	
}
void stock::refil(int qty)
{
	
		quant+=qty;
		cout<<"\n\nStock updated.";
	    getch();
		
	
}
int stock::stchk(int nm)
{
    if(nm==p_id)
	 return 0;
	else 
	return 1;
}


void stock::show()
{
	
	cout<<"\n"<<p_id<<"\t\t"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}
void stock::withdraw()
{
	system("cls");
	st.disp();
	//disp();
	billing:
	//stock obj1;
	int temp;int qty;char ch;
	int i=0;
	long pos=0;
		cout<<"\n\nEnter the product's ID \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
	//
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    { 
	    st.withd(qty);
		  //withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		 // 
		  i++;break;
	    }
     }fio.close();
      cout<<"\nDo you wish to add more items to your cart? (Y/N): ";
     cin>>ch;
	if(ch=='Y' || ch=='y')
	{
		withdraw();
	}
	system("PAUSE");
    //cout<<"\n\nTotal bill is: "<<grossamt;
    cout<<"\n\n\tDue to the current situation, we are providing relief packages as follows:\n1. 5% off on orders below 1000\n2. 10% off on orders below 2000\n3. 15% off on orders below 5000\n4. 20% off on orders above 5000 "<<endl;
    //cout<<"\n\nTotal bill is: "<<grossamt;
    //stock b;
   // calculate_bill();
    printbill();
      if(i!=1)
       {
	   cout<<"\n\n!!Record not found!!";
	   system("PAUSE");//cin.get();
	   }
     
    cin.get();
    
	 //disp(); 
	//loggedin();
}	
void stock::addnew()
{
    system("cls");
	disp();
	const int size=1;
	char ch;
	int i=0;
	fout.open("shop.dat",ios::binary|ios::app);
	do
	{
	cout<<"\n\nInput the product id, name, price and the quantity of item respectively\n\n";
	    	cout<<"\nEnter Name:\t";
			cin.ignore();
			cin.getline(st.name, 29);
			cout<<"\nEnter Product ID:\t";
			cin>>st.p_id;
			cout<<"\nEnter Price (in PKR):\t";
			cin>>st.pr;
			cout<<"\nEnter Quantity Avaialble:\t";
			cin>>st.quant;
	fout.write((char*)&st,sizeof(st));
    cout<<"\n\nitem updated";
    cout<<"\nDo you want to add another record? (Y/N)"<<endl;
	cin>>ch;
}	while(ch=='Y'||ch=='y' &&1<3);
    
    cout<<"\n\nStock Updated!!";
    

    fout.close();
    cin.get();
    system("cls");
    
    inventory();


}


void stock::disp()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout<<"\n\n========================================================================\n";
	cout<<"\n\nPRODUCT ID \tPARTICULARS\t\tSTOCK AVAILABLE\t\t PRICE";
	cout<<"\n\n=========================================================================\n";	
	 fin.open("shop.dat",ios::binary);
	 fin.read((char*)&st,sizeof(st));
	 st.show();
     while(true)
     {
	  fin.read((char*)&st,sizeof(st));
	  
	     if(!fin.eof()&&fin.tellg()<0)
	     {	i=0; 
		 break;
		 }
		 if(fin.eof()==true)
		 	break;
	     st.show();
     }
     
     if(i==0)
     {	cout<<"\n\n\t\t\t!!NO RECORD FOUND!!";
	getch();
     }
     fin.close();
    cout<<"\n\n"<<endl;
    system("PAUSE");
}
void stock::refill()
{
	system("cls");
	int temp;
	int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the products ID \n"<<endl;
	cin>>temp;
	
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(!fio.eof())
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  cout<<"\n\nEnter quantity: \n"<<endl;
		cin>>qty;
		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;
		  
	 break;
	    }
     }
     if(i!=1)
       {
	   cout<<"\n\n!!Record not found!!";
	   system("PAUSE");//cin.get();
	   }
     fio.close();
    system("cls");
    cin.get();
	disp();
    inventory();
	
}
void stock::deleteitem()
{

	system("cls");	
	 int i=0;
     int temp;
     disp();
     cout<<"\n\t\t\t\tDelete Record";
     cout<<"\n\nEnter the Product's ID you want to delete:";
     cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
     cout<<"\n\n"<<endl;
     system("PAUSE");
     system("cls");
     inventory();
}



void stock::calculate_bill()
		{
			if(grossamt<=1000)
			{
				covid_disc=0.05*grossamt;
				netamt=grossamt-covid_disc;
			}
			else if(grossamt > 1000 && grossamt<=2000)
			{
				covid_disc=0.10*grossamt;
				netamt=grossamt-covid_disc;
			}
			else if(grossamt>2000&&grossamt<=5000)
			{
				covid_disc=0.15*grossamt;
				netamt=grossamt-covid_disc;
			}
			else if(grossamt>5000)
			{
				covid_disc=0.25*grossamt;
				netamt=grossamt-covid_disc;
			}
		}
void stock::printbill()
		{calculate_bill();
	cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tTotal Bill Calculated     :"<<grossamt;
    cout<<"\n\t\tCOVID RELIEF DISCOUNT       :"<<covid_disc;
    cout<<"\n\n\t\tNET AMOUNT                :Rs."<<netamt;
    cout<<"\n\t\t*********************************************";
    cout<<"\n\t\tPlease keep the amount "<<netamt<<"/- ready. The rider will be at your doorstep in \n\t\t24-48 hours depending upon your residency"<<endl;
    system("PAUSE");
    cout<<"Stay Safe, Stay Home. We are your one stop shopping solution for all your needs"<<endl;
    
	cout<<"\n\n\tLogging you out...."<<endl;
	getch();
	system("cls");
	menu();
	selection();
		}

class custlogin:public supermart
{ 
	string f_name,l_name;
	char phone[11];
    char address[50];
	int  age;
    string reguser,regpass;
    void login()
{
        int count;
        string user,pass,u,p,fn,ln,ph;
        int  age1;
        system("cls");
        cout<<"\n\t\tPlease enter the following details"<<endl;
        cout<<"\t\tUSERNAME :";
        cin>>user;
        cout<<"\t\tPASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>fn>>ln>>ph>>age1>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nWelcome back "<<user<<"\nLOGIN SUCESS\nWe're glad that you chose us.\nThanks for logging in\n";
                cin.get();
                
                loggedin();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                custmenu();
        }
}

void registr()
{ 	
         system("cls");
        cout<<"\nEnter first name: ";
        cin>>f_name;
        cout<<"\nEnter last name: ";
        cin>>l_name;
         cout<<"\nEnter shipping address: ";
        cin.ignore();
		cin.getline(address, 49);
		phone:
        cout<<"\nEnter phone number that we will contact you on (03XXXXXXXXX): ";
        cin>>phone;
        if (phone[11]!='\0')
        	{
			cout<<"Error! Please enter the phone number in valid format"<<endl;
			getch();
        	goto phone;
        }
        age:
        cout<<"\nEnter age: ";
        cin>>age;
        if(age>99)
            	{
            		cout<<"\nPlease enter correct age";
            		goto age;
				}
        cout<<"\nEnter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
		ofstream reg("database.txt",ios::app);
        reg<<f_name<<' '<<l_name<<' '<<phone<<' '<<age<<' '<<reguser<<' '<<regpass<<endl;
        ofstream add("databaseaddress.txt",ios::app);
        add<<address<<endl;
        system("cls");
        cout<<"\nRegistration Successful\n";
        reg.close(); add.close();
        custmenu();
}

void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp,fn,ln,ph;
                        int  age1;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>fn>>ln>>ph>>age1>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                login();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                custmenu();
                        }
                        break;
                }
                
                case 2:
                {
                        cin.get();
                        custmenu();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}
void guest()
{
	int ch;
	system("cls");
    cout<<"\n\tAre you sure you want to login as guest?\nYou will have to provide your shipping address and phone number nevertheless\n";
    cout<<"\n1.Proceed"<<endl;
    cout<<"2.Return"<<endl;
     cout<<"\nEnter your choice :";
    cin>>ch;
    switch(ch)
    {
    	case 1:
            {
            	 cout<<"\nEnter shipping address: ";
       			 cin.ignore();
				 cin.getline(address, 49);
				 cout<<"\nEnter phone number that we will contact you on: ";
        		 cin>>phone;
        		 ofstream gp("guestdatabase_phones.txt",ios::app);
        		gp<<phone<<endl;
        		ofstream ga("guestdatabase_address.txt",ios::app);
        		ga<<address<<endl;
        		cin.get();
        		cout<<"Logged in as Guest"<<endl;
        		
        		ga.close();
        		gp.close();
        		loggedin();
			}    
			case 2:
                {
                    cin.get();
                    custmenu();
                }
            default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        guest();
                	
    
	}
}
public:
	
	void custmenu()
	{
		int choice;
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Welcome to login page                               \n\n";
        cout<<"     Please expect delays in delivery due to the uncertain situation                    \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.LOGIN"<<endl;
        cout<<"2.REGISTER"<<endl;
        cout<<"3.FORGOT PASSWORD"<<endl;
        cout<<"4.Log in as Guest"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        		case 0:
        			cout<<"\n\n\t\tReturning to main menu"<<endl;
        			getch();
        			menu();
        			selection();
                       // Sleep(10);
                        return;
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:
                       guest();
                        break;
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl; 
                        custmenu();
        }
	}
	
	
void loggedin()
{
int i;
customermenu:
	//system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if (i==1)
	{
	stock b;
	b.withdraw();getch();goto customermenu;
	}
	else if(i==2)
	{
		system("cls");
		stock s1;
	s1.disp();getch();goto customermenu;
	}
	
	else 
	{
		system("cls");
		cout<<"\nReturning to main menu"<<endl;
		getch();
	menu();
	selection();	
	
	exit(0);
	}
}
};
void menu()
{
    int j;
    system("color 02");supermart a;a.setname("\t\t<<<<<<<<<<<< UNITED SUPERMARKET >>>>>>>>>>>\t\t\n");a.setaddress("\t\tPlot D, Sharah-e-Sher Shah Suri Road, Block D North Nazimabad Town, Karachi City, Sindh\t\t\n");cout<<a.getname();cout<<a.getaddress(); 
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO UNITED SUPERMART ============|";
	cout<<"\n\n\tLet's fight these crucial times with zeal and vigour that we are known for. In these uncertain times,\n\t  our greatest act of valour is to stay home and take care of ourselves, mentally and physically."<<endl;
    
	getch();
	system("cls");	
	cout<<"=============================================================";
	cout<<"\n\n\t\t   1. Owner Menu\n\n\t\t   2. Customer Menu\n\n\t\t   3. Employee Menu\n\n\t\t   4.Exit";
	cout<<"\n\n=============================================================\n";
	
}
int owner()
{
	int x, i;
	system("cls");
    cout<<"\n\n\nCongrats!!Access Granted!!\n\n";
    getch();
    system("cls");
	
	ownermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    OWNER MENU\n1. Inventory \n2. Employee Details\n0. Exit:";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		stock s;
		s.inventory();
	}
	else if(i==2)
	{
		employee e;
    e.options();
}
	else if(i==0)
	{
	system("cls");
	cout<<"Returning to main menu"<<endl;
	getch();
	menu();
	selection();
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\t\t\tEnter correct number";
	getch();
	goto ownermenu;
   }
}
void selection ()
{ 
  char pass[10],pass2[10];
  int i, j;
  cout<<"\n\nEnter Your Choice:";
  cin>>j;
	if(j==1)
	{
	system("cls");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ";
	for(int z=0;z<5;z++)
	{
		pass[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
	for(int a=1;a<5;a++) 
	{
		Sleep(500);
		cout << "...";
	}
	if(strcmp(pass,"owner")==0)
	{  
	cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";
	owner();
}
else
{
	cout<<"\n\n\nINPUT CORRECT PASSWORD!!!\n\n";
	getch();
    system("cls");
	main();
}
	}
	if(j==2)
	{
	 custlogin obj1;
	 obj1.custmenu();
	}
	

    if(j==3)
	{
	system("cls");
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password: ";
	
	for(int z=0;z<7;z++)
	{
		pass2[z]=getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPlease enter the password : ";
		for(i=1;i<=(z+1);i++)
		{
			cout<<"*";
		}
	}
	if(strcmp(pass2,"admin12")==0)
	{
	empmenu:
	system("cls");
	stock st;
	cout<<"=================================================================";
	cout<<"\n\n\t\t\tEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Exit";
	cout<<"\n\n\n==========================END OF MENU=============================";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
		system("cls");
		
	st.disp();
	getch();
	goto empmenu;
	}
	else if(i==2)
	{
		
		st.refill();
		goto empmenu;
	}
	else 
	{
		system("cls");
	cout<<"\n\n\n\tReturning to main menu";
	getch();
	menu();
	selection();
}
}
if(j==4)
{
	system("CLS");
	cout<<"Leaving the program...."<<endl;
	exit(1);
}
else 
{
	cout<<"\n\nSorry!! Please Provide Valid Password..\n\n";
	getch();
	
	
	main();
}

	}	
	
}
int main()
{
menu();
selection();
getch();
}
