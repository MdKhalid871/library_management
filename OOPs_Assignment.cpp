#include<iostream>

using namespace std;

class Book{
    int bookid;
    string title;
    string author;
    string publisher;
    double price;
    bool avail;

    public:
        Book(int b = -1, string t = "\0", string a = "\0", string p = "\0", double m = 0.0){
            bookid = b;
            title = t;
            author = a;
            publisher = p;
            price = m;
            avail = true;
        }
        int getbookid(){             //returns book id
            return bookid;
        }
        void changeavailablestatus(bool f){              //changes available status
            avail = f;
        }
        bool available(){                 //returns available status
            return avail;
        }
        void displaybookdetails();        //display book details
};
class BookCopy : public Book{
    int serialnum;

    public:
        BookCopy(int b = -1, int s = -1, string t = "\0", string a = "\0", string p = "\0", double m = 0.0) : Book(b, t, a, p, m) {
            serialnum = s;
        }

        int getserialnum(){       //gets serial number
            return serialnum;
        }
        void displaybookcopydetails();     //display details of book
};
class BookList{
    BookCopy list[200];                     //currently stroring 200 books.
    int count;

    public:
        BookList(){
            count = 0;
        }
        void addbooks(int, int, string, string, string, double);     // adds book
        void showbooks();                                   //shows book
        int checkavailability(int,int);                     //checks availability of a book
        void changestatus(int,int,bool);                    //changes status when a book is issued or returned
};
class Member{
    int memberid;
    string name;
    string email;
    string address;

    public:
        Member(int u = -1, string n = "\0", string e = "\0", string a = "\0"){
            memberid = u;
            name = n;
            email = e;
            address = a;
        }
        int getmemberid(){                         //gets member id
            return memberid;
        }
        void displaymemberdetails(){                 //display details
            cout<<"Member Details are:- \n";
            cout<<"Member id:- "<<memberid<<endl;
            cout<<"Name:- "<<name<<endl;
            cout<<"Email:- "<<email<<endl;
            cout<<"Address:- "<<address<<endl;
        }
};
class Student : public Member{
    public:
        int bookids[2];                   //store books id taken by the student
        int serialnums[2];                //store serial nums of book taken by the student
        int count;

        Student(int u = -1, string n = "\0", string e = "\0", string a = "\0") : Member(u,n,e,a){
            count = 0;
        }
        void displaystudentdetails();    //display all details of student.
        void addBook(int,int,BookList&);           //addsbook.
        void remBook(int,int,BookList&);           //remove books
};
class Faculty : public Member{
    public:
        int bookids[10];                  //store books id taken by the faculty
        int serialnums[10];               //store serial nums of book taken by the facultty
        int count;

    
        Faculty(int u = -1, string n = "\0", string e = "\0", string a = "\0") : Member(u,n,e,a){
            count = 0;
        }
        void displayfacultydetails();    //display all details of student.
        void addBook(int,int,BookList&);           //addsbook.
        void remBook(int,int,BookList&);           //remove book
};
class StudentList{
    Student list[50];                        //currently storing 50 students.
    int count;

    public:
        StudentList(){
            count = 0;
        }
        void addStudent(int,string,string,string);                        //add student
        int addstubooks(int,int,int,BookList&);                           //add books to the student.
        int sturembooks(int,int,int,BookList&);                           //remove book from student record
        int checkStudent(int);                                            //check uniqueness of a student in student set of ids
};
class FacultyList{
    Faculty list[10];                        //currently storing 10 faculty.
    int count;

    public:
        FacultyList(){
            count = 0;
        }
        void addFaculty(int,string,string,string);                         //adds new faculty
        int addfacbooks(int,int,int,BookList&);                           //add books to the faculty.
        int facrembooks(int,int,int,BookList&);                            // remove book from faculty record
        int checkfaculty(int);                                            //check uniqueness of faculty in faulty set of ids
};
class Transaction{
    int memberid;
    int bookid;
    int serialnum;                     
    bool returned;

    public:
        Transaction(int m = -1,int b = -1, int s = -1, string d = "\0"){
            memberid = m;
            bookid = b;
            serialnum = s;
        }
        int getbookid(){                       //gets book id
            return bookid;
        }
        int getserialnum(){                     //gets serial num
            return serialnum;
        }
        int getmemberid(){                     //gets member id
            return memberid;
        }                     
        void returnstatus(bool r){             //changes return status
            returned = r;
        }
        void displaytransaction();             // displays details
};
class Issue : public Transaction{
    string date;           //format(dd/mm/yyyy)
    public:
        Issue(int m = -1,int b = -1, int s = -1, string d = "\0") : Transaction(m,b,s,d){
            date = d;
            returnstatus(false); 
        }
        string getdate(){                 //gets date
            return date;
        }
};
class IssueList{
    Issue list[100];
    int count;

    public:
        IssueList(){
            count = 0;
        }
        void issuebook(int,int,int,string,BookList&,StudentList&,FacultyList&);                   //issue a book
        void displayissuedbooks();                          //display issue books
};
class Return : public Transaction{
    string date;           //format(dd/mm/yyyy)
    public:
        Return(int m = -1,int b = -1, int s = -1, string d = "\0") : Transaction(m,b,s,d){
            date = d;
            returnstatus(true); 
        }
        string getdate(){                 //gets date
            return date;
        }
};
class ReturnList {
    Return list[100];
    int count;

    public:
        ReturnList(){
            count = 0;
        }
        void returnbook(int,int,int,string,BookList&,StudentList&,FacultyList&);            //return a book
        void checkreturnstatus(int,int,int,BookList&,StudentList&,FacultyList&);             //ccheck return status of a book
        void displayreturnedbooks();                                                        //display returned books
};
class Library{            //will perform all the operations upfront.
    BookList bk;
    StudentList st;
    FacultyList fac;
    IssueList iss;
    ReturnList ret;
    public:
    void performoperations();
    void addbooks(int b,int s, string t, string a, string p,double c){   // Adds Book
        bk.addbooks(b,s,t,a,p,c);
    }
    void addStudent(int m,string n,string e,string a){   //Add Student Member
        st.addStudent(m,n,e,a);
    }
    void addFaculty(int m,string n,string e,string a){    //Add Faculty Member
        fac.addFaculty(m,n,e,a);
    }
    void showbooks(){    //Show Books
        bk.showbooks();
    }
    void issuebook(int m,int b,int s,string a){   //Issue Book
        iss.issuebook(m,b,s,a,bk,st,fac);
    }
    void returnbook(int m,int b,int s,string a){    //Return Book
        ret.returnbook(m,b,s,a,bk,st,fac);
    }
    void displayissuedbooks(){      //Check Issued Books
        iss.displayissuedbooks();
    }
    void displayreturnedbooks(){    //Check Returned Book
        ret.displayreturnedbooks();
    }
    void checkreturnstatus(int m, int b,int s){      //Check whether a book is returned or not.
        ret.checkreturnstatus(m,b,s,bk,st,fac);
    }
};

int StudentList::checkStudent(int m){
    if(count == 0){
        return 0;
    }
    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            return 1;
        }
    }
    return 0;
}
int FacultyList::checkfaculty(int m){
    if(count == 0){
        return 0;
    }
    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            return 1;
        }
    }
    return 0;
}
void Book::displaybookdetails(){
    cout<<"Book Details are:- \n";
    cout<<"Book id:- "<<bookid<<endl;
    cout<<"Title:- "<<title<<endl;
    cout<<"Author:- "<<author<<endl;
    cout<<"Publisher:- "<<publisher<<endl;
    cout<<"Price:- "<<price<<endl;
}
void BookCopy::displaybookcopydetails(){
    Book::displaybookdetails();
    cout<<"Serial number:- "<<serialnum<<endl;
}
void Student::addBook(int b,int s,BookList& t){
    if(count >= 2){
        cout<<"Can not issue more than 2 books.\n";
        return;
    }
    int k = t.checkavailability(b,s);

    if(k == 0){
        cout<<"Book not available\n";
    }

    for(int i = 0; i < count; i++){
        if(bookids[i] == b && serialnums[i] == s){
            cout<<"Book already issued.\n";
            return;
        }
    }
    bookids[count] = b;
    serialnums[count] = s;
    t.changestatus(b,s,false);
    count++;
}
void Student::remBook(int b,int s,BookList& t){
    if(count == 0){
        cout<<"No Books found\n";
        return ;
    }
    int k;
    for(int i = 0; i < count; i++){
        if(bookids[i] == b && serialnums[i] == s){
            k = i;
        }
    }
    for(int i = k; i < count-1;i++){
        bookids[i] = bookids[i+1];
        serialnums[i] = serialnums[i+1]; 
    }
    t.changestatus(b,s,true);
    count--;
    return ;
}
void Faculty::remBook(int b,int s,BookList& t){
    if(count == 0){
        cout<<"No Books found\n";
        return;
    }
    int k;
    for(int i = 0; i < count; i++){
        if(bookids[i] == b && serialnums[i] == s){
            k = i;
        }
    }
    for(int i = k; i < count-1;i++){
        bookids[i] = bookids[i+1];
        serialnums[i] = serialnums[i+1]; 
    }
    t.changestatus(b,s,true);
    count--;
}
void Student::displaystudentdetails(){
    displaymemberdetails();
    if(count != 0){
        cout<<"Books-id and its Serial number issued are:- \n";
        for(int i = 0; i < count; i++){
            cout<<bookids[i]<<" "<<serialnums[i]<<endl;
        }
    }
}
void Faculty::addBook(int b,int s,BookList& t){
    if(count >= 10){
        cout<<"Can not issue more than 10 books.\n";
        return;
    }
    int k = t.checkavailability(b,s);
    if(k == 0){
        cout<<"Book not available\n";
    }

    for(int i = 0; i < count; i++){
        if(bookids[i] == b && serialnums[i] == s){
            cout<<"Book already issued.\n";
            return;
        }
    }
    bookids[count] = b;
    serialnums[count] = s;
    t.changestatus(b,s,false);
    count++;
}
void Faculty::displayfacultydetails(){
    displaymemberdetails();
    if(count != 0){
        cout<<"Books-id and its Serial number issued are:- \n";
        for(int i = 0; i < count; i++){
            cout<<bookids[i]<<" "<<serialnums[i]<<endl;
        }
    }
}
void BookList::addbooks(int b, int s, string t, string a, string p, double m){
    BookCopy temp(b,s,t,a,p,m);

    if(count >= 100){
        cout<<"Books exceeded\n";
        return;
    }

    for(int i = 0; i < count; i++){
        if(list[i].getbookid() == b && list[i].getserialnum() == s){
            cout<<"Book already exists\n";
            return;
        }
    }

    list[count] = temp;
    count++;
}
void BookList::showbooks(){
    if(count == 0){
        cout<<"No Books found\n";
        return;
    }

    for(int i = 0; i < count; i++){
        list[i].displaybookcopydetails();
    }
}
void StudentList::addStudent(int m,string n,string e,string a){
    Student temp(m,n,e,a);

    if(count >= 50){
        cout<<"Memberships are full\n";
        return;
    }

    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            cout<<"Already a member\n";
            return;
        }
    }
    list[count] = temp;
    count++;
}
int StudentList::addstubooks(int m,int b,int s,BookList& t){
    if(count == 0){
        cout<<"No Student found\n";
        return 0;
    }
    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            if(list[i].count >= 2){
                cout<<"Maximum books are issued\n";
                return 0;
            }
            list[i].addBook(b,s,t);
        }
    }
    return 1;
}
int StudentList::sturembooks(int m,int b,int s,BookList& t){
    if(count == 0){
        return 0;
    }
    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            list[i].remBook(b,s,t);
            return 1;
        }
    }
    return 0;
}
int FacultyList::facrembooks(int m,int b,int s,BookList& t){
    if(count == 0){
        return 0;
    }
    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            list[i].remBook(b,s, t);
            return 1;
        }
    }
    return 0;
}
void FacultyList::addFaculty(int m,string n,string e,string a){
    Faculty temp(m,n,e,a);

    if(count >= 10){
        cout<<"Memberships are full\n";
        return;
    }

    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            cout<<"Already a member\n";
            return;
        }
    }
    list[count] = temp;
    count++;
}
int FacultyList::addfacbooks(int m,int b,int s,BookList& t){
    if(count == 0){
        cout<<"No Faculty found\n";
        return 0;
    }
    for(int i = 0; i < count; i++){
        if(list[i].getmemberid() == m){
            if(list[i].count >= 10){
                cout<<"Maximum books are issued\n";
                return 0;
            }
            list[i].addBook(b,s,t);
        }
    }
    return 1;
}
void Transaction::displaytransaction(){
    cout<<"Member-id:- "<<memberid<<endl;
    cout<<"Book-id:- "<<bookid<<endl;
    cout<<"Serial Number:- "<<serialnum<<endl;
}
int BookList::checkavailability(int b,int s){
    if(count == 0){
        cout<<"No Book Found\n";
        return 0;
    }

    for(int i = 0; i < count; i++){
        if(list[i].getbookid() == b && list[i].getserialnum() == s){
            if(list[i].available() == true){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    return 0;
}
void BookList::changestatus(int b,int s,bool f){
    if(count == 0){
        return;
    }
    for(int i = 0; i < count; i++){
        if(list[i].getbookid() == b && list[i].getserialnum() == s){
            list[i].changeavailablestatus(f);
        }
    }
}
void IssueList::issuebook(int m,int b,int s,string d,BookList& t,StudentList& st, FacultyList& fac){
    Issue temp(m,b,s,d);
    if(count >= 100){
        cout<<"Can not issue books\n";
        return;
    }
    int k = t.checkavailability(b,s);
    int r = st.checkStudent(m);
    int x = fac.checkfaculty(m);
    if(k == 0){
        cout<<"Book not available\n";
        return;
    }
    if(r == 0 && x == 0){
        cout<<"Member not found\n";
        return;
    }
    if(st.addstubooks(m,b,s,t)||fac.addfacbooks(m,s,b,t)){
        list[count] = temp;
        count++;
        return;
    }
}
void IssueList::displayissuedbooks(){
    if(count == 0){
        cout<<"No books issued\n";
        return;
    }
    cout<<"Issue List:- \n";
    for(int i = 0; i < count; i++){
        cout<<"Member-id:- "<<list[i].getmemberid()<<endl;
        cout<<"Book id:- "<<list[i].getbookid()<<endl;
        cout<<"Serial Number:- "<<list[i].getserialnum()<<endl;
        cout<<"Date:- "<<list[i].getdate()<<endl;
        cout<<"----------------"<<endl;
    }
    return;
}
void ReturnList::returnbook(int m,int b,int s,string d,BookList& t,StudentList& st, FacultyList& fac){
    Return temp(m,b,s,d);
    if(count >= 100){
        cout<<"Book cant be returned now\n";
        return;
    }

    if(t.checkavailability(b,s) == 0){
        cout<<"Book wasnt issued\n";
        return;
    }
    int r = st.checkStudent(m);
    int x = fac.checkfaculty(m);
    if(r == 0 && x == 0){
        cout<<"Member not found\n";
        return;
    }
    if(st.sturembooks(m,b,s,t)||fac.facrembooks(m,b,s,t)){
        list[count] = temp;
        count++;
        return;
    }
}
void ReturnList::checkreturnstatus(int m,int b,int s,BookList& t,StudentList& st, FacultyList& fac){
    if(count == 0){
        cout<<"Not returned\n";
        return;
    }

    for(int i = 0; i < count; i++){
        if(list[i].getserialnum() == s && list[i].getbookid() == b && list[i].getmemberid() == m){
            if(st.sturembooks(m,b,s,t)||fac.facrembooks(m,b,s,t)){
                cout<<"Book Returned\n";
                return;
            }
            else{
                cout<<"Book not returned\n";
                return;
            }
        }
    }
    cout<<"No such book was issued\n";
}
void ReturnList::displayreturnedbooks(){
    if(count == 0){
        cout<<"No books returned\n";
        return;
    }
    cout<<"Return List:- \n";
    for(int i = 0; i < count; i++){
        cout<<"Member-id:- "<<list[i].getmemberid()<<endl;
        cout<<"Book id:- "<<list[i].getbookid()<<endl;
        cout<<"Serial Number:- "<<list[i].getserialnum()<<endl;
        cout<<"Date:- "<<list[i].getdate()<<endl;
        cout<<"----------------"<<endl;
    }
    return;
}
void Library::performoperations(){


    int k;
    do{
        cout<<"Enter number to perform following Operations:- \n";
        cout<<"1 -> Add Book\n";
        cout<<"2 -> Add Student Member\n";
        cout<<"3 -> Add Faculty Member\n";
        cout<<"4 -> Show Books\n";
        cout<<"5 -> Check Availabilty of a book\n";
        cout<<"6 -> Issue Book\n";
        cout<<"7 -> Return Book\n";
        cout<<"8 -> Check Issued Books\n";
        cout<<"9 -> Check Returned Book\n";
        cout<<"10 -> Check whether a book is returned or not.\n";
        cout<<"0 -> Exit\n";
        cin>>k;
        int b,m,s;
        string t,n,p,a,e,d;
        double c;
        switch(k){
        case 1:
            cout<<"Enter the details of Book:- \n"; 
            cout<<"Bookid:- ";cin>>b;
            cout<<"Serial Number:- ";cin>>s;
            cout<<"Title:- ";cin>>t;
            cout<<"Author:- ";cin>>a;
            cout<<"Publisher:- ";cin>>p;
            cout<<"Price:- ";cin>>c;
            addbooks(b,s,t,a,p,c);
            break;
        
        case 2:
            cout<<"Enter the details of member:- \n"; 
            cout<<"Memberid:- ";cin>>m;
            cout<<"Name:- ";cin>>n;
            cout<<"Email:- ";cin>>e;
            cout<<"Address:- ";cin>>a;
            addStudent(m,n,e,a);
            break;
        case 3:
            cout<<"Enter the details of member:- \n"; 
            cout<<"Memberid:- ";cin>>m;
            cout<<"Name:- ";cin>>n;
            cout<<"Email:- ";cin>>e;
            cout<<"Address:- ";cin>>a;
            addFaculty(m,n,e,a);
            break;
        case 4:
            showbooks();
            break;
        case 5:
            cout<<"Enter Details of Book to check:- \n";
            cout<<"Bookid:- ";cin>>b;
            cout<<"Serial Number:- ";cin>>s;
            if(bk.checkavailability(b,s)){
                cout<<"Available\n";
            }
            else{
                cout<<"Not Available\n";
            }
            break;
        case 6:
            cout<<"Enter the details to issue a book:- \n"; 
            cout<<"Memberid:- ";cin>>m;
            cout<<"Bookid:- ";cin>>b;
            cout<<"Serial Number:- ";cin>>s;
            cout<<"Date:- ";cin>>a;
            issuebook(m,b,s,a);
            break;
        case 7:
            cout<<"Enter the details to return a book:- \n"; 
            cout<<"Memberid:- ";cin>>m;
            cout<<"Bookid:- ";cin>>b;
            cout<<"Serial Number:- ";cin>>s;
            cout<<"Date:- ";cin>>a;
            returnbook(m,b,s,a);
            break;
        case 8:
            displayissuedbooks();
            break;
        case 9:
            displayreturnedbooks();
            break;
        case 10:
            cout<<"Enter the details to check whether a book is returned- \n"; 
            cout<<"Memberid:- ";cin>>m;
            cout<<"Bookid:- ";cin>>b;
            cout<<"Serial Number:- ";cin>>s;
            checkreturnstatus(m,b,s);
            break;
        case 0:
            break;
        }
    }while(k != 0);

    return;
}


int main(){
    Library lib;
    lib.performoperations();
    return 0;
}
