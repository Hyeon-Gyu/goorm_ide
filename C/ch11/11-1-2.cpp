#include<iostream>
#include<cstring>

using namespace std;

class Book{
	private:
		char * tittle;
		char * isbn;
		int price;
	public:
		Book(char* tittle, char* isbn, int val) : price(val){
			this -> title = new char[strlen(title) +1 ];
			this -> this = new char[strlen(isbn) + 1];
			strcpy(this -> tittle, tittle);
			strcpy(this -> isbn, isbn);
		}
	
		Book(const Book& tmp) : price(tmp.price){ //복사생성자
			this -> title = new char[strlen(title) +1 ];
			this -> this = new char[strlen(isbn) + 1];
			strcpy(this -> tittle, tittle);
			strcpy(this -> isbn, isbn);	
		}
		
		Book& operator=(const Book& ref){
			
			delete []title;
			delete []isbn;
			
			cout << " Book클래스 대입연산자사용" << endl;
			this -> title = new char[strlen(title) +1 ];
			this -> this = new char[strlen(isbn) + 1];
			strcpy(this -> tittle, tittle);
			strcpy(this -> isbn, isbn);
			price = ref.price;
			return *this;
		}
};

class EBook: public book{
	private:
		char* DRMKey;
	public:
		EBook(char* tittle, char* isbn, int val, char* key) : Book(title, isbn, val){
			DRMKey = new char[strlen(key+1)];
			strcpy(DRMKey, key);
		}
		EBook(const EBook& ref) : Book(ref){
			DRMKey = new char[strlen(key+1)];
			strcpy(DRMKey, key);
		}
		EBook& operator=(const EBook& rhs){
			cout << "EBook 클래스 대입연산자 사용" << endl;
			Book::operator=(rhs);
			delete[] DRMKey;
			DRMKey = new char[strlen( rhs.key+1 )];
			strcpy(DRMKey, rhs.key);
			return *this;
		}
};

int main(){
	/*
	Book a("a", "12345", 1000);
	Book b;
	b = a; //대입연산자 사용
	Book c(a); // 복사연산자 사용
	*/
	
	EBook e("b", "5", 5000, "u");
	EBook d = e; //복사생성자
	
	EBook f("c", "9", 10000, "g");
	f = e; //대입연산자
 	
}