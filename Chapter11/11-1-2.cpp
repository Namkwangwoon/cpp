#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char * title;   // 책의 제목
    char * isbn;    // 국제표준도서번호
    int price;      // 책의 정가
public:
    Book(char * t, char * i, int p) : price(p)
    {
        title = new char[strlen(t)+1];
        isbn = new char[strlen(i)+1];
        strcpy(title, t);
        strcpy(isbn, i);
    }
    Book(const Book& b) : price(b.price)
    {
        title = new char[strlen(b.title)+1];
        isbn = new char[strlen(b.isbn)+1];
        strcpy(title, b.title);
        strcpy(isbn, b.isbn);
    }
    Book& operator=(const Book& b)
    {
        delete []title;
        delete []isbn;

        title = new char[strlen(b.title)+1];
        isbn = new char[strlen(b.isbn)+1];
        strcpy(title, b.title);
        strcpy(isbn, b.isbn);
        price = b.price;

        return *this;
    }
    void ShowBookInfo()
    {
        cout<<"제목: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"가격: "<<price<<endl;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book
{
private:
    char * DRMKey;  // 보안관련 키
public:
    EBook(char * t, char * i, int p, char * D) : Book(t, i, p)
    {
        DRMKey = new char[strlen(D)+1];
        strcpy(DRMKey, D);
    }
    EBook(const EBook& ebook) : Book(ebook)
    {
        DRMKey = new char[strlen(ebook.DRMKey)+1];
        strcpy(DRMKey, ebook.DRMKey);
    }
    EBook& operator=(const EBook& ebook)
    {
        Book::operator=(ebook);

        delete []DRMKey;
        DRMKey = new char[strlen(ebook.DRMKey)+1];
        strcpy(DRMKey, ebook.DRMKey);

        return *this;
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout<<"인증키: "<<DRMKey<<endl;
    }
    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2 = ebook1;  // 복사 생성자의 호출
    ebook2.ShowEBookInfo();
    cout<<endl;
    EBook ebook3("dumy", "dumy", 0, "dumy");
    ebook3 = ebook2;    // 대입 연산자의 호출
    ebook3.ShowEBookInfo();
    return 0;
}