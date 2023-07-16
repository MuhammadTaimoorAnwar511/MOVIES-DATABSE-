#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;


class film
{
public:
    string f_name;//film name//
    film* f_next;// film next//

    film(string n)//constructor//
    {
        f_name = n;
        f_next = NULL;
    }
};

class role
{
public:

    string r_name;//role name//
    role* r_next;//role next//
    film* down;  //role ka down//

    role(string n)//constructor//
    {
        r_name = n;
        r_next = NULL;
        down = NULL;
    }

    void insert_film(string n)//insert films in link//
    {

        film* a = new film(n);//create film//

        if (down == NULL)//insert first film in link
        {
            //   cout << "\nfirst film\n";
            down = a;
            return;
        }

        film* temp = down;//create//

        while (temp->f_next != NULL)//insert new film in link//
        {
            temp = temp->f_next;
        }
        //cout << "\nmore film\n";
        temp->f_next = a;
    }

    void display_film()//display all films// 
    {
        film* temp = down;//role ka down store in temp // //create//
        while (temp != NULL)
        {
            cout << "movie  " << setw(10) << temp->f_name << "  \n";//film name//
            temp = temp->f_next;
        }
        cout << endl;
    }
};

//===============================================//
//===============================================//
//===============================================//
//===============================================//
//===============================================//
//===============================================//
//===============================================//

class actor
{
public:

    string a_name;//actor name//
    actor* a_next;//actor next//

    actor(string n)//constructor//
    {
        a_name = n;
        a_next = NULL;
    }
};

class movie
{
public:

    string m_name;//movie name//
    movie* m_next;// movie next//
    actor* below;//pointer to first actor of each movie//

    movie(string n)//constructor//
    {
        m_name = n;
        m_next = NULL;
        below = NULL;
    }

    void insert_actor(string n)//insert actors in link//
    {

        actor* a = new actor(n);//create actor//

        if (below == NULL)//insert first actors in link
        {

            below = a;

            return;
        }

        actor* temp = below;//create//

        while (temp->a_next != NULL)//insert new actors in link//
        {
            temp = temp->a_next;
        }
        temp->a_next = a;
    }


    void display_actor()//display all actors// 
    {
        actor* temp = below;//create//

        while (temp != NULL)
        {
            cout << "actor " << setw(10) << temp->a_name << "  \n";//actor name//
            temp = temp->a_next;
        }
        cout << endl;
    }

};



class linked
{
public:
    movie* head;//movie head//
    movie* current;//current movie//
    actor* first;//actor head//

    role* HEAD;    //role ka head//
    role* CURRENT;//current role//
    film* FIRST; //film head//

    int a_count;
    int m_count;

    linked()//constructor//
    {
        head = NULL;
        first = NULL;
        current = NULL;

        HEAD = NULL;
        FIRST = NULL;
        CURRENT = NULL;

        a_count = 0;
        m_count = 0;
    }

    void search_by_movie()
    {
        bool found = 0;
        string str;
        movie* temp = head;//create//

        cout << "enter movie name \n =";
  
        cin.ignore();
        getline(cin, str);

        while (temp != NULL)
        {

            if (temp->m_name == str)
            {
                if (found == 0)
                {
                    found = 1;
                    cout << "movie found = " << temp->m_name << endl;
                    temp->display_actor();//actor of specific movies//
                    temp = temp->m_next;
                }
            }
            else
            {
               // cout << "movie not found = ";
                temp = temp->m_next;
            }

        }
        cout << endl;

    }

    void  insert_movie(string n)//insert movies in link//
    {
        movie* m = new movie(n);//create movie//

        if (head == NULL)// insert first movie in list//
        {
            ++m_count;
            head = m;
            current = m;
            return;
        }

        movie* temp = head;//create//

        while (temp->m_next != NULL)// insert new  movies in list//
        {
            temp = temp->m_next;
        }
        temp->m_next = m;
        current = m;
        ++m_count;
    }

    void display_movies()//display all movies// 
    {
        movie* temp = head;//create//

        while (temp != NULL)
        {
            cout << " MOVIE  " << setw(10) << temp->m_name << "  \n";//movie name//

            temp->display_actor();//actor of specific movies//

            temp = temp->m_next;
        }
        cout << endl;

    }
    void  insert_role(string n)//insert role in link//
    {
        bool check = 0;

        if (HEAD == NULL)// insert first role in list//
        {
            //  cout << "\nfirst actor\n";
            ++a_count;
            role* m = new role(n);//create role//

            HEAD = m;
            CURRENT = m;

            return;
        }

        else
        {
            role* temp = HEAD;//create//

            while (temp->r_next != NULL)//whethere to insert new  role in list//
            {
                if (temp->r_name == n)
                {
                    CURRENT = temp;//store adress of existing role//
                    //        cout << "\nactor found\n";
                    check = 1;
                }
                temp = temp->r_next;
            }
            if (check == 0)
            {
                //  cout << "\nnew actor \n";
                role* m = new role(n);//create role//
                while (temp->r_next != NULL)// insert new  role in list//
                {
                    temp = temp->r_next;
                }
                temp->r_next = m;
                CURRENT = m;//store adress of current role//
                ++a_count;
            }
            else
            {
                //cout << "\nnot created\n";
            }
        }
    }

    void display_role()//display all role// 
    {
        role* temp = HEAD;//create//
        while (temp != NULL)
        {
            cout << "ACTOR  " << setw(10) << temp->r_name << "  \n";//role name//

            temp->display_film();//film of specific role//

            temp = temp->r_next;
        }
        cout << endl;
    }
    void search_actor()//display all role// 
    {
        bool found = 0;
        string str;
        cout << "enter actor name \n =";
        cin.ignore();
        getline(cin, str);
        role* temp = HEAD;//create//

        while (temp != NULL)
        {
            if (temp->r_name == str)
            {
                if (found == 0)
                {
                    found = 1;
                    cout << "actor found = " << temp->r_name << endl;
                    temp->display_film();//actor of specific movies//
                    temp = temp->r_next;
                }
            }
            else
            {
                temp = temp->r_next;
            }
        }
        cout << endl;
    }

    void average_of_film()//first
    {
        cout << "number of movies = " << m_count << endl;;
        cout << "number of actors = " << a_count;
        double s = 0;
        s = ((double)m_count / (double)a_count) + 1;

        cout << "\nOn average  " << s << "  films an actor work in\n";
    }
    void average_of_actor()//second
    {
        cout << "number of movies = " << m_count << endl;;
        cout << "number of actors = " << a_count;
        double s = 0;
        s = ((double)a_count / (double)m_count);
        cout << "\nOn average  " << s << "  actors a film has\n";
    }

};


int main()
{
    fstream myfile;
    string line;
    linked l;
    string naam;

    myfile.open("data_base.txt", ios::in);//read mode//

    if (myfile.is_open())
    {
        cout << "\nfile opened\n";
        while (getline(myfile, line))
        {
            l.insert_movie(line);//store movie name//
            naam = line;

            while (line != "#")
            {
                getline(myfile, line);

                if (line != "#")
                {
                    l.current->insert_actor(line);//store actors for each movie//
                    l.insert_role(line); //store role for each movie//
                    l.CURRENT->insert_film(naam);//film done by each actor//

                }
            }
        }

        myfile.close();
    }
    else
    {
        cout << "\nnot open \n";
    }
   

    int opt = 1;

    while (opt != 0)
    {
        do
        {
            cout << "\n1]TO SEARCH BY MOVIE\n2]TO SEARCH BY ACTOR \n3]On average how many films does an actor work in?\n4]On average how many actors does a film typically has?\n5]Display movie as parent\n6]display actor as parent \n = ";

            cout << "\nselect option\n";
            cin >> opt;
        } while (opt <= 0 || opt >= 7);

        switch (opt)
        {
        case 1:
            l.search_by_movie();
            break;
        case 2:
            l.search_actor();
            break;
        case 3:
            l.average_of_actor();
            break;
        case 4:
            l.average_of_film();
            break;
        case 5:
            cout << "\n######################################################################################\n";
            cout << "\n######################################################################################\n";
            l.display_movies();
            break;
        case 6:
            cout << "\n######################################################################################\n";
            cout << "\n######################################################################################\n";

              l.display_role();
            break;
        }

        cout << "press 1 to continue \n Press 0 to exit\n =";
        do
        {
            cin >> opt;
        } while (opt <= -1 || opt >= 2);
    }

    return 0;
}