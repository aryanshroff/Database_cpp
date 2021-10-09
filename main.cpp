//ARYAN SHROFF 224030(ROLL.NO) 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Database;
void print_vector(vector<Database> vect1);
bool cmp_rollno(Database obj1, Database obj2);
bool cmp_name(Database obj1, Database obj2);
void rollno_sorting(vector <Database> &vect1);
void name_sorting(vector <Database> vect1);
void operator<<(ostream &cout_val , Database &object_val);
void student_search(vector <Database> vect1,int n,int key);
void delete_record(vector<Database> &vect1 , int key);



class Database
{
	public:
	string name;
	int rollno;
	string batch;
	//input parameters will have VAL format

	
	void getdata(string name_val, int rollno_val,string batch_val);
	string r_name();
	int r_rollno();
	string r_batch();
	void print_database();
	
};






int main(){
	int command{0};//0 will be exit button to get out of a function
	Database s[10];
	s[0].getdata("Aryan         ",30,"d2");
	s[1].getdata("Samruddhi ",31,"d2");
	s[2].getdata("Abhinav     ",32,"d2");
	s[3].getdata("Kevin          ",63,"d3");
	s[4].getdata("Anish          ",16,"d1");
	s[5].getdata("Vivek          ",11,"d1");
	s[6].getdata("Ravindra    ",03,"d1");
	s[7].getdata("Tesjaswini  ",49,"d3");
	s[8].getdata("Shardul       ",33,"d2");
	s[9].getdata("Abhijeet     ",40,"d3");
	
	
	vector <Database> vect1;
	vect1.push_back(s[0]);
	vect1.push_back(s[1]);
	vect1.push_back(s[2]);
	vect1.push_back(s[3]);
	vect1.push_back(s[4]);
	vect1.push_back(s[5]);
	vect1.push_back(s[6]);
	vect1.push_back(s[7]);
	vect1.push_back(s[8]);
	vect1.push_back(s[9]);
	cout<<"                                                  DATABASE_DISPALYED                                                                             "<<endl;
	print_vector(vect1);
	int n=size(vect1);
	cout<<endl;
	cout<<endl;
	cout<<"press 1 for sorting the database with respect to names and 0 to bypass "<<endl;
	cin>>command;
	while(command==1){
		cout<<"Sorting the Database with respect to names"<<endl;
		name_sorting(vect1);
		cout<<endl;
		command=0;
	}
	cout<<"press 2 for sorting the database with respect to roll numbers and 0 to bypass "<<endl;
	cin>>command;
	while(command==2){
		cout<<"For sorting the Database with respect to roll numbers"<<endl;
		rollno_sorting(vect1);
		command=0;
		cout<<endl;
	}
	
	cout<<"press 3 for  searching a student 0 to bypass "<<endl;
	cin>>command;
	while(command==3){
		int key{0};
		cout<<"enter the roll number you want to search"<<endl;
		cin>>key;
		student_search(vect1,n,key);
		cout<<"press 3 to continue the search press 0 to terminate "<<endl;
		cin>>command;
		cout<<endl;
	}
	cout<<" press 4 to delete a record "<<endl;
	cin>>command;
	while(command==4){
		int key{0};
		cout<<" Enter the roll number of the student"<<endl;
		cin>>key;
		delete_record(vect1,key);
		
		
		cout<<"press 4  to continue deleteing the records and 0 to terminate "<<endl;
		cin>>command;
	}
	
	
	/*cout<<s[0];
	  cout<<"Student record found with  roll number: "<<key<<" Name: "<<element.name<<" and Batch: "<<element.batch<<" is deleted "<<endl;
	cout<<"n is "<<n<<endl;*/
	return 0;
}
void delete_record(vector<Database> &vect1 , int key){
	for (auto i = vect1.begin(); i != vect1.end(); i++) {
        if (i->rollno==key) {
            vect1.erase(i);
            
        }
	}
	print_vector(vect1);
}

void operator <<(ostream &cout_val , Database &object_val){
	cout_val<<"name is: "<<object_val.name<<endl;
}
void student_search(vector <Database> vect1,int n, int key){
	cout<<endl;
	for(Database element:vect1){
		if(element.rollno==key){
			cout<<"Student with  roll number: "<<key<<" found with name: "<<element.name<<" and belongs to batch: "<<element.batch<<endl;
			return ;
		}
		
	}
	cout<<"Roll number: "<<key<<" not found in Database "<<endl;
	
}
void rollno_sorting(vector <Database> &vect1){
	cout<<"Sorted database wrt Roll Numbers  is "<<endl;
	sort(vect1.begin() , vect1.end() , cmp_rollno);
	print_vector(vect1);
}
void name_sorting(vector <Database> vect1){
	cout<<"Sorted database wrt Student name is"<<endl;
	sort(vect1.begin() , vect1.end() , cmp_name);
	print_vector(vect1);
	
}
bool cmp_rollno(Database obj1, Database obj2){
	if (obj1.rollno<obj2.rollno){
		return true;
	}
	else{
		return false;
	}
}

bool cmp_name(Database obj1, Database obj2){
	if (obj1.name<obj2.name){
		return true;
	}
	else{
		return false;
	}
}

void print_vector(vector<Database> vect1){
	vector<Database>:: iterator it;
		for(it=vect1.begin() ; it!=vect1.end() ; it++){
			(*it).print_database();
		}
}



void Database:: getdata(string name_val, int rollno_val,string batch_val)
{
	name=name_val;
	rollno=rollno_val;
	batch=batch_val;
}
string Database:: r_name()
{
	return name;
}
	int Database:: r_rollno()
	{
		return rollno;
	}
	string Database:: r_batch()
	{
		return batch;
	}
	void Database:: print_database(){
		cout<<"NAME- "<<name<<"		ROLL_NUMBER- "<<rollno<<"		BATCH- "<<batch<<endl;
	}
