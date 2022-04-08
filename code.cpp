#include<bits/stdc++.h>
using namespace std;

class user{
    protected:
        string password;
    public:
        string name;
        string id;
        string get_pw(){
            return this->password; 
        }
    friend class userdb;
};

class professor:public user{
    public:
        int calculate_fine(){
            int fine=0;
            for(int i=0;i<owned_list.size();i++)
            {
                if(owned_list[i].second>60)
                fine+=5*(60-owned_list[i].second);
            }
            return fine;
        }
        void view_owned_books(){
            for(int i=0;i<owned_list.size();i++)
            {
                cout<<"Title: "<<owned_list[i].first->title<<" "<<"Author: "<<owned_list[i].first->author<<" ";
                cout<<"ISBN No.: "<<owned_list[i].first->ISBN<<" "<<"Publication: "<<owned_list[i].first->publication;
                cout<<"Days since issued"<<" "<<owned_list[i].second<<endl;
            }
        }
    private:
        vector<pair<book*,int> > owned_list;
        int fine_amount;
        void clear_fine_amount(){
            fine_amount=0;
        }
    friend class userdb;
};

class student:public user{
    public:
        int calculate_fine(){
            int fine=0;
            for(int i=0;i<owned_list.size();i++)
            {
                if(owned_list[i].second>30)
                fine+=2*(30-owned_list[i].second);
            }
            return fine;
        }
        void view_owned_books(){
            for(int i=0;i<owned_list.size();i++)
            {
                cout<<"Title: "<<owned_list[i].first->title<<" "<<"Author: "<<owned_list[i].first->author<<" ";
                cout<<"ISBN No.: "<<owned_list[i].first->ISBN<<" "<<"Publication: "<<owned_list[i].first->publication;
                cout<<"Days since issued"<<" "<<owned_list[i].second<<endl;
            }
        }
    private:
        vector<pair<book*,int> > owned_list;
        int fine_amount=0;
        void clear_fine_amount(){
            fine_amount=0;
        }
    friend class userdb;
};

class librarian:public user{

};

class userdb{
    private:
        vector<student> student_list;
        vector<professor> professor_list;
        vector<librarian> librarian_list;
        void add_user(char who, user obj){
            for(int i=0;i<student_list.size();i++)
            {
                if(obj.id==student_list[i].id)
                {
                    cout<<"A student with same id already exists"<<endl;
                    return;
                }
            }
            for(int i=0;i<professor_list.size();i++)
            {
                if(obj.id==professor_list[i].id)
                {
                    cout<<"A professor with same id already exists"<<endl;
                    return;
                }
            }
            for(int i=0;i<librarian_list.size();i++)
            {
                if(obj.id==librarian_list[i].id)
                {
                    cout<<"A librarian with same id already exists"<<endl;
                    return;
                }
            }
            if(who=='s')
            {
                student temp;
                temp.id=obj.id;
                temp.name=obj.name;
                temp.password=obj.password;
                student_list.push_back(temp);
            }
            else if(who=='p')
            {
                professor temp;
                temp.id=obj.id;
                temp.name=obj.name;
                temp.password=obj.password;
                professor_list.push_back(temp);
            }
            else if(who=='l')
            {
                librarian temp;
                temp.id=obj.id;
                temp.name=obj.name;
                temp.password=obj.password;
                librarian_list.push_back(temp);
            }
            else
            cout<<"Error. Can't make a user of "<<who<<" type."<<endl;
        }
        
        void delete_user(string id){
            for(int i=0; i<student_list.size;i++)
            {
                if(student_list[i].id==id)
                {
                    student_list.erase(student_list.begin()+i);
                    cout<<"Deleted student successfully"<<endl;
                    return;
                }
            }
            for(int i=0; i<professor_list.size;i++)
            {
                if(professor_list[i].id==id)
                {
                    professor_list.erase(professor_list.begin()+i);
                    cout<<"Deleted professor successfully"<<endl;
                    return;
                }
            }
            for(int i=0; i<librarian_list.size;i++)
            {
                if(librarian_list[i].id==id)
                {
                    librarian_list.erase(librarian_list.begin()+i);
                    cout<<"Deleted librarian successfully"<<endl;
                    return;
                }
            }
        }
    public:
        int try_login(string id, string pw, login& log_obj){
            int i, flag=0;
            for(i=0;i<student_list.size();i++)
            {
                if(student_list[i].id==id && student_list[i].get_pw()==pw)
                {
                    flag=1;
                    log_obj->whologgedin='s';
                    return 1
                }
            }
            for(i=0;i<professor_list.size();i++)
            {
                if(professor_list[i].id==id && professor_list[i].get_pw()==pw)
                {
                    flag=1;
                    log_obj->whologgedin='s';
                    return 1;
                }
            }
            for(i=0;i<librarian_list.size();i++)
            {
                if(librarian_list[i].id==id && librarian_list[i].get_pw()==pw)
                {
                    flag=1;
                    log_obj->whologgedin='s';
                    return 1;
                }
            }
            return 0;
        }
    friend class book;
        
};
class book{
    private:
        string title;
        string author;
        long long ISBN;
        string publication;
        bool is_issued;
        int issue_date;
        
    public:
        book(){
            is_issued=0;
        }
        void req_book(string id,userdb& obj){
            int i,flag=0;
            if(this->is_issued==1)
            {
                cout<<"Book already issued to someone"<<endl;
                return;
            }
            for(i=0;i<student_list.size();i++)
            {
                if(student_list[i])
            }
            this->is_issued=1;
            this->issue_date=0;

        }
    friend class bookdb;
    friend class student;
    friend class professor;
};

class bookdb{
    private:
        vector<book> book_list;
        void add_book(book obj){
            for(int i=0;i<book_list.size();i++)
            {
                if(book_list[i].ISBN==obj.ISBN)
                {
                    cout<<"A book with same ISBN already exists"<<endl;
                    return;
                }
            }
            book_list.push_back(obj);
        }
        void delete_book(long long isbn){
            for(int i=0;i<book_list.size();i++)
            {
                if(book_list[i].ISBN==isbn)
                {
                    book_list.erase(book_list.begin()+i);
                    cout<<"Deleted book with ISBN "<<isbn<<endl;
                    return;
                }
            }
            cout<<"Book with entered ISBN not found"<<endl;
            return;
        }
    public:
        void view_all_books(){
            for(int i=0;i<book_list.size();i++)
            {
                cout<<"Title: "<<book_list[i].title<<" "<<"Author: "<<book_list[i].author<<" ";
                cout<<"ISBN No.: "<<book_list[i].ISBN<<" "<<"Publication: "<<book_list[i].publication<<"Is issued?: ";
                cout<<(is_issued?"Yes":"NO")<<endl;
            }
        }
        

};

class login{
    private:   
        int isloggedin;
        char whologgedin;
    public:
        login(){
            isloggedin=0;
        }
    friend class userdb;
};

int main(){
    string id,pw;
    login log_obj;
    userdb user_info;
    cout<<"Enter the User id and the Password"<<endl;
    while(1)
    {
        cin>>id>>pw;
        if(user_info.try_login(id,pw,log_obj))
        break;
        else
        {
            cout<<"You entered wrong credentials. Please enter the User id and Password again"<<endl;
            cin>>id>>pw;
        }
    }
    cout<<"Logged in Successfully!"<<endl;

    while(1)
    {
        cout<<"Enter 0 to logout"<<endl<<"If you are a student/professor:"<<endl<<"Enter 1 to see all books";
        cout<<"Enter 2 to see your books"<<endl<<"Enter 3 to check if a book is available"<<endl<<"Enter 4 to issue a book";
        cout<<endl<<"If you are a librarian:"<<endl<<"Enter 1 to ";
        
    }
    
    
    return 0;
}