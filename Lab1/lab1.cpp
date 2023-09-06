#include<iostream>
#include <vector>
#include<fstream>
#include <string>
#include<exception>
#include<algorithm>
#include<sstream>


using namespace std;

struct Address {
    string Streed;
    int zip;
    string city;
};
struct Person {
    string name;
    string id;
    Address location;
};

size_t find_in_names ( const vector < Person >& haystack , string
name_part ) ;                                      // deklaration
vector < Person > find_person_from_city ( const vector < Person >&
haystack , string city );                          // deklaration
istream & operator >>( istream & in , Person & p); // deklaration
 vector <Person>read_file( string filename );   // deklaration



vector<Person> read_file(string filename){
ifstream txtfile(filename);
string line;

    vector<Person> persons;
  Person p; 

    if(txtfile.is_open()){
        while(txtfile >>p){ 

        persons.push_back(p);
        
        }
    }else{
        cout<<" Unable to open the file"<<endl;
    }
    

 return persons;
}


istream & operator >>( istream &in , Person &p){
    
    try
    {        
        if(in.peek() == -1) //Om filen är vid sitt slut
	    {
		    return in;  //Avbryt
	    }

        string zipA;
        string zipB;
        string zipC;
        string cityA;

        getline(in, p.name);
        getline(in, p.id);
        getline(in,p.location.Streed, ',');

        in >> zipA >> zipB;
        p.location.zip = stoi(zipA+zipB);
        getline(in,p.location.city,' ');
       
        //här läser jag hela raden med alla space och lägger in dem i cityA
        getline(in, cityA);
        // deklarera en space 
        const char* WhiteSpace = " ";
        // hittar jag första bokstäven som inte är space
        size_t start = cityA.find_first_not_of(WhiteSpace);
        // hittar sista bokstäven som inte är space
        size_t end = cityA.find_last_not_of(WhiteSpace);
        // extract a substring from a string cityA och läger den i city
        p.location.city = cityA.substr(start, end - start + 1); 

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return in;
   
}

size_t find_in_names ( const vector < Person >& haystack , string name_part ){
    string temp;
    size_t count = 0;

    for (const auto &p : haystack)
    {
        temp = p.name;

        transform(temp.begin(), temp.end(),temp.begin(),::toupper);
        transform(name_part.begin(), name_part.end(),name_part.begin(), ::toupper);
    
      size_t found = temp.find(name_part ); // Positionen för det första tecknet i den första matchen.
                                           
       if (found != string::npos)   //Om inga matchningar hittades returnerar funktionen strängen::npos.
        {
           
            count++;
        }
     
    }  
    return count;
}
    

vector<Person> find_person_from_city(const vector<Person> & haystack, 
		std::string city)
{  
    vector<Person> result;
	for(const auto & p: haystack)
	{
		string temp = p.location.city;
        transform(city.begin(),city.end(),city.begin(), ::toupper);
        transform(temp.begin(), temp.end(),temp.begin(), ::toupper);
		 
        if (temp == city)
        {
            result.push_back(p);
        }

	}  
return result;
}


int main(){
 vector<Person> list = read_file("names.txt");

    int options;
   
    while(true){
        cout<<"-----------------------------------------"<<endl;
        cout<<"         welcome to the UserList          "<<endl;
        cout<<"-------------------------------------------"<<endl;

        cout<<"1): search with part_name"<<endl;
        cout<<"2): search city"<<endl;
        cout<<"3): exit"<<endl;

        cin>>options;

        // cheking if the input is integer and it return a boolean value;
        while(cin.fail()) 
        {
            cout << "Error" << std::endl;
            cin.clear();
            cin.ignore(256,'\n'); // ignorerar de 256 första character
            cout<<"chose again" <<endl;
            cin >> options;
        }
        
        if (options==1)
        {
            cin.ignore();
            string part_name;
            cout<<" enter the name your looking for"<<endl;
        
            getline(cin, part_name);
            size_t antal_p = find_in_names(list, part_name);  
            cout<<"antal person:"<<antal_p<<endl;

        }
         if(options==2) 
        {
            cin.ignore(); 
            string city;

            cout<<"enter the name of the city"<<endl;
            getline(cin, city);
       
            auto result = find_person_from_city(list, city);
            // itererar igenom och skriver ut data
            for (const auto& p : result)
            {
                 cout << "hittade:" << p.id << " " << p.name << " som bor i : " << p.location.zip << " " << p.location.city << endl;
            }
        }
        if(options==3)
        {
            exit(0);
        }
    }
return 0;

}