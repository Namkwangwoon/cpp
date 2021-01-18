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
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}