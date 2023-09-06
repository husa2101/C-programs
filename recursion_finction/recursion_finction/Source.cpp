#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm> // för  sort
/*
class MyClass
{
public:
	MyClass(int model_year, std::string model_name)
	{
		this->model_name = model_name;
		this->model_year = model_year;

	}
	int get_modelyear();
	std::string get_modelname();


private:
	int model_year;
	std::string model_name;
};
int MyClass::get_modelyear() { return model_year; }
std::string MyClass::get_modelname() { return model_name; }

int main() {

	MyClass car(2020," volvo");
	std::cout << car.get_modelname() << "    " << car.get_modelyear() << std::endl;

	system("pause>0");
	return 0;
}*/
/*
unsigned int recursive(unsigned int a, unsigned int b)
{
	if (a== b)
	{
		return a;
	}
	else 
	{
		return a + recursive(a+1, b);
	
	}

}

int main()
{
	std::cout << recursive(1, 6) << std::endl;


	return 0;
}
*/
/*class MyClass
{
public:


	MyClass(int model_year, std::string model_name) {
		this->model_year = model_year;
		this->model_name = model_name;
	}
	std::string get_model_name() { return model_name; }
	int get_model_year() { return model_year; }
	void set_modelName(std::string a) { model_name = a; }
	void set_modelYear(int b) { model_year = b; }
private:
	int model_year;
	std::string model_name;
};*/
/*unsigned int fib(unsigned int a) {
	if (a == 1 || a == 0)
	{
		return a;
	}
	else
	{
		return (fib(a-1)+fib(a-2));
	}
}
int main() {
	int x, i = 0;
	std::cout << " antal serie number som du vill att skapas " << std::endl;
	std::cin >> x;
	std::cout << " fibonnaci serier: ";

	while (i<x)
	{
		std::cout << "  " << fib(i);
		i++;
	}


	system("pause>0");
	return 0;
}*/
/*
struct car
{
	int model_year;
	std::string model_name;
	car(int model_year, std::string model_name) {
		this->model_name = model_name;
		this->model_year = model_year;
	}
};
std::ostream& operator<<(std::ostream& out, car& a) {
	out << "model_name is " << a.model_name << "\n" << " and model_year is" << a.model_year << std::endl;
	return out;
}

int main() {
	car hussein = car(20000, "volvo");
	std::cout << hussein;
	

	system("pause>0");
	return 0;
}
*/

/*another way of using struct*/

/*struct ranking
{
	int overall;
	int in_genre;
};*/

/*struct boardGame {
	std::string title;
	std::string genre;
	int player;
	double komplexity;
	ranking rank;
};*/

/*std::ostream& operator<<(std::ostream& COUT, boardGame bg) {
	COUT << bg.title << "\ " << bg.komplexity << "/" << bg.komplexity;


	return COUT;
}
// i den här fallet för istream operatörn det är viktigt att ta in broadGame som reference om inte ta med som ovanstående ostream operatörn då får vi en lokal kopia på boadGame variabler
// och det gör att om jag gör förändringar på broadGame i istream operatörn då kommer att den här bara synas i den här funktionen och inte i broadGme bg4.
// så vi vill skicka en referece från bg4 in i den här funktionen och isådanafall alla förändringar som sker i den här funktionen kommer att synas i bg4 . 
std::istream& operator>>(std::istream& in, boardGame& bg) {
	                                                                //bg.title = " hussein salehi"; // förändring
	std::getline(in, bg.title);
	std::getline(in, bg.genre);
	std::string s;
	std::getline(in, s, ' ');
	if (!s.empty()) {
		bg.player = std::stoi(s);
	}

	std::getline(in, s);
	std::getline(in, s);
	std::getline(in, s);
	                                                                 //std::getline(in, s);

	return in;
}
 // överlagra en + operator
boardGame operator+(const boardGame lhs, const  boardGame rhs) {
	boardGame temp_Game = rhs + lhs;
	return temp_Game;
}


int main() {

	/*boardGame bg;
	bg.title = " puerto Rico";
	bg.genre = "strategy";
	bg.player = 5;
	bg.komplexity = 3.3;
	bg.rank.in_genre = 25;
	bg.rank.overall = 30;*/

	// nedan har vi direkt satt in en del data i vectorn

	//std::vector<boardGame>bg_list; /*= { //std::cout << bg.genre<<"\n" << bg.komplexity<<"\n" << bg.player<<"\n" << bg.title<<"\n" << bg.rank.in_genre<<"\n" << bg.rank.overall<<"\n" << std::endl;

	/*boardGame{"Alak Dolak", " offensive", 5 , 3.3, {23, 30}},      //std::cout << bg.title << " " << bg.player << " :" << bg.genre << std::endl;
	boardGame{ "hussein salehi" ," defensive", 3, 23, {55,6} },
	boardGame{ "rayan salehi", " player", 2, 34,{44, 66} }
	};*/
	                                                                      /*here we need to overload a ostream operator in order to print out */
	                                                                    //std::cout << bg;

	                                                                // we can also save these data in a vector and in that way sent these data to diffrent funktion like search or sorting funktion. 
	
	//bg_list.push_back(bg);
    //bg_list.push_back(bg3);

	/*boardGame bg4;
	std::ifstream file("boardGame.txt");
	                                                                                      //antigen kan man skriva som nedanstående eller while(!file.eof){ file>>bg4;  bg_list.pushback(bg4);}
	while (file >> bg4) {
		                                                             // detta inte går eftsom utsrömningsoperatorn är inte definerad för en object därför en överlagrnings operatör är nödvändigt.
		
		bg_list.push_back(bg4);
	}

	                                                                                                                                          // this for loop calls (for each loop)
	                                                                       // in here we can also use auto instad of boardGame it means that the compiler vill recognize what kind of dta it is.  
	for (boardGame b : bg_list)
	{
		std::cout << b<<"\n";
	}
	                                                                          // det old way of for loop 
	                                                                            /*
	                                                                             for (size_t i = 0; i < bg_list.size(); i++)
	                                                                             {
	                                                                            	std::cout << i;
	                                                                              	i++;
	                                                                              }*/
 
                                                                              	// vi kan också anropa själva overlagringsoperatorn 
	                                                                           //operator<<(std::cout, bg3);
	/*system("pause>0");
	return 0;
}*/


struct ranking {
	int overall;
	int in_genre;
};
struct boardGame{
	std::string title;
	std::string genre;
	int players = 0;
	double complexity = 0;                       // it is better to always initialize all variable
	ranking rank{};                                  // den här kommer att sätta alla medlemar by default till noll
};

// funktionsheader (prototyp eller interface) här kan man vara sparsamt och inte behöva skriva namnet på vector eller namet på parametern. 
std::vector<boardGame> getTopRankedGame(std::vector<boardGame>, int );
 
// funktion som tar emot en vector och söker i genom 
// vi måste självklart ta emot returnerade vector i main() och vi måste ta emot den med en vector för att det är ju en vector som returnerats.  
std::vector<boardGame> getTopRankedGame(const std::vector<boardGame>boardgames, int limit) {
	// när man ska ska skicka som reference och när man ska inte göra om man vill modifiera ett värde som skickas till funktionen då behöver man skicka den som referennce
	std::vector<boardGame>topBoardGame;
	for (size_t i = 0; i < boardgames.size(); i++)
	{
		if (boardgames[i].rank.overall <= limit)
		{
			topBoardGame.push_back(boardgames[i]); // at.(i)
		}
	}
	// från scopet av en boardGame få ut en iterator och döper den till it;
	// i en iterator jobbar man med objekten som finns i vår container automatisk  (  it++ ) använder vi till att jobbar mellan objeckter
	// iterator är en pekare som i c++ man kan räkna en pekare från en till en annan
	std::vector<boardGame>::const_iterator it;
	for (it = boardgames.begin(); it !=boardgames.end(); it++)
	{
		// här man vill inte ha pekaren utan vad pekaren pekar på och därför man bör derefrence the pointer 
		// varför använder vi * och () om vi skriver *it. punkten har högre prencens och därför visar först iteratorns operator och inte derefrensens operatör 
		// därför använder vi () för att komma åt medlemar som finns . men det finns en annan sätt att att komma åt först * medlemar ( it-> ) istället för parantes 
		
		if((*it).rank.overall <= limit)
		{
			topBoardGame.push_back(*it);         // jag vill inte har pekaren i vector utan vad pekaren pekar på därför dereference vi den igen. 
		}
	}

	for (auto bg : boardgames)
	{
		if (bg.rank.overall <= limit)
		{
			topBoardGame.push_back(bg);
		}
	}

	return topBoardGame;
}
// anledningen till att och använder referensen till ostream är att en stream är som en rinnande vatten det kan inte kopieras där bör man alltid referera den till...
// &out den här medlemen kommer att skickas in som en reference
std::ostream& operator<<(std::ostream &out, boardGame g) {
	out << g.title << "\n" << g.genre << "\n" << g.players << "\n"  << g.rank.overall;
	// anledningen till att varför returnerar vi out strömmen är pga operator chaining
	return out;
}  

void printVector(const std::vector<int>& integer) {
	for (std::vector<int>::const_iterator it = integer.begin(); it != integer.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool isHigher(const int i, const int j) {
	return i > j;
}

bool isRankedHigher(const boardGame a, const boardGame b) {
	return a.rank.overall < b.rank.overall;
}

int main() {
	
	std::vector<boardGame>bg_list = {
	boardGame {" settles of Caten", "strategy", 5, 2.0, {150, 156}},
	boardGame {"hussein salehi", " rayan salehi", 2, 8.0, {4, 7}},
	boardGame {" reyhane salehi", " sheyton", 6, 2.3, {4, 9}}
	};

	std::vector<boardGame>cool_boardGame;
	cool_boardGame = getTopRankedGame(bg_list, 100);

	std::sort(cool_boardGame.begin(), cool_boardGame.end(), isRankedHigher);

	


	/*for (size_t i = 0; i < cool_boardGame.size(); i++)
	{
		std::cout << cool_boardGame.at(i);
	}*/
	for (auto bg : cool_boardGame)
	{
		std::cout << bg << "\n";
	}
	// så här kan man komma åt på varje object i en vector eller index. 
	//std::cout << bg_list[0], bg_list[1];

	/*if (bg.players == 0)
	{
		std::cout << " zero players" << std::endl;
	}*/

	std::vector<int> integer = {10 , 30 , 40 , 20, 60 , 50, 90, 80, 70 };


	// det finns två olika sort funktioner en som itererar genom vector from begin() - end() och det andra går igenom vector från begin() - end() + en compare funktion. enligt nedan. 
	// man anropar funktionen i definerade sortfunktionen ( isHigher )
	std::sort(integer.begin(), integer.end());
	printVector(integer);
	std::sort(integer.begin(), integer.end(), isHigher);
	printVector(integer);

	

	system("pause>0");
	return 0;
}
// stdlib - standard library in c++ som vi hämtar hela tiden funktioner 
// STL - Standard template library den innehåller olika typer av algoritmer/ inbyggda funktioner som vi ofta använder tex. sortering




