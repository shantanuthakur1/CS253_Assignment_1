#include<bits/stdc++.h>
using namespace std;

class user{
    protected:
        string password;
    public:
        string name;
        string id;
    
};

class professor:public user{
    public:
        int list
        int calculate_fine(){

        }
    private:
        int fine_amount;
        int clear_fine_amount(){

        }
};

class student:public user{
    public:
        int list
        int calculate_fine(){

        }
    private:
        int fine_amount;
        int clear_fine_amount(){

        }
};

class librarian:public user{
    public:

    private:
    int is_logged_in;
};

class userdb{
    private:
        list<student*> student_list;
        list<student*> professor_list;
        list<student*> librarian_list;
    public:
        int try_login(string id,string pw,){
            int i, flag=0;
            for(i=0;i<student_list.size();i++)
            {
                if(student_list[i]->id==id && student_list[i]->get_pw()==pw)
                {
                    flag=1;
                    .whologgedin='s';
                    return 1
                }
            }
            for(i=0;i<professor_list.size();i++)
            {
                if(professor_list[i]->id==id && professor_list[i]->get_pw()==pw)
                {
                    flag=1;
                    return 1;
                }
            }
            for(i=0;i<librarian_list.size();i++)
            {
                if(librarian_list[i]->id==id && librarian_list[i]->get_pw()==pw)
                {
                    flag=1;
                    return 1;
                }
            }
            return 0;
        }
};
class book{
    private:
        string title;
        string author;
        long long ISBN;
        string publication;
};

class bookdb{
    void add()
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

    
    return 0;
}