#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
struct Service {
    char name[50];
    int code;
    int price;
    Service * next;
    bool flag;
};
struct Part {
    char name[50];
    int code;
    int price;
    Part * next;
    bool flag;
};
struct Client {
    char name[50];
    char family[50];
    char car_name[50];
    int car_model;
    int total_price;
    Client * next;
    Service * serviceList;
    Part * partlist;
    bool flag;
};
//*******************************************************************************************************************************//
void gotoxy(int x,int y)
 {
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

 }
//*******************************************************************************************************************************//
void serviceDefault ()
{
    cout<<"***************************************************************************"<<endl;
    cout<<"CODE : 1"<<'\t'<<"SERVICE : Axle repair"<<'\t'<<'\t'<<'\t'<<"PRICE : 100T" <<endl<<endl;
    cout<<"CODE : 2"<<'\t'<<"SERVICE : Balancing "<<'\t'<<'\t'<<'\t'<<"PRICE : 200T"<<endl<<endl;
    cout<<"CODE : 3"<<'\t'<<"SERVICE : Booster install"<<'\t'<<'\t'<<"PRICE : 450T"<<endl<<endl;
    cout<<"CODE : 4"<<'\t'<<"SERVICE : Engine tune up"<<'\t'<<'\t'<<"PRICE : 500T"<<endl<<endl;
    cout<<"CODE : 5"<<'\t'<<"SERVICE : Exhaust change"<<'\t'<<'\t'<<"PRICE : 30T"<<endl<<endl;
    cout<<"CODE : 6"<<'\t'<<"SERVICE : Air filter change"<<'\t'<<'\t'<<"PRICE : 20T"<<endl<<endl;
    cout<<"CODE : 7"<<'\t'<<"SERVICE : Generator change "<<'\t'<<'\t'<<"PRICE : 120T"<<endl<<endl;
    cout<<"CODE : 8"<<'\t'<<"SERVICE : Gearbox change "<<'\t'<<'\t'<<"PRICE : 180T"<<endl<<endl;
    cout<<"CODE : 9"<<'\t'<<"SERVICE : Ignition repair "<<'\t'<<'\t'<<"PRICE : 210T"<<endl<<endl;
    cout<<"CODE : 10"<<'\t'<<"SERVICE : Lubrication "<<'\t'<<'\t'<<'\t'<<"PRICE : 80T"<<endl<<endl;
    cout<<"CODE : 11"<<'\t'<<"SERVICE : Piston change " <<'\t'<<'\t'<<"PRICE : 110T"<<endl<<endl;
    cout<<"CODE : 12"<<'\t'<<"SERVICE : Quandary change " <<'\t'<<'\t'<<"PRICE : 300T"<<endl<<endl;
    cout<<"CODE : 13"<<'\t'<<"SERVICE : Suspension change " <<'\t'<<'\t'<<"PRICE : 700T"<<endl<<endl;
    cout<<"CODE : 14"<<'\t'<<"SERVICE : Thermostat change"<<'\t'<<'\t'<<"PRICE : 60T"<<endl<<endl;
    cout<<"CODE : 15"<<'\t'<<"SERVICE : Undercarriage repair"<<'\t'<<'\t'<<"PRICE : 800T"<<endl<<endl;
    cout<<"CODE : 16"<<'\t'<<"SERVICE : Wheels repair"<<'\t'<<'\t'<<'\t'<<"PRICE : 100T"<<endl<<endl;
    cout<<"CODE : 17"<<'\t'<<"SERVICE : Xenon lights install"<<'\t'<<'\t'<<"PRICE : 40T"<<endl<<endl;
    cout<<"CODE : 18"<<'\t'<<"SERVICE : Oil change"<<'\t'<<'\t'<<'\t'<<"PRICE : 30T"<<endl<<endl;
    cout<<"CODE : 19"<<'\t'<<"SERVICE : Fan belt change " <<'\t'<<'\t'<<"PRICE : 10T"<<endl<<endl;
    cout<<"CODE : 20"<<'\t'<<"SERVICE : Battery change  " <<'\t'<<'\t'<<"PRICE : 150T"<<endl;
    cout<<"***************************************************************************"<<endl;

}

void partDefault ()
{
    cout<<"***************************************************************************"<<endl;
    cout<<"CODE : 1"<<'\t'<<"PART : Brake pedal"<<'\t'<<"PRICE : 30"<<endl<<endl;
    cout<<"CODE : 2"<<'\t'<<"PART : Clutch pedal"<<'\t'<<"PRICE : 30"<<endl<<endl;
    cout<<"CODE : 3"<<'\t'<<"PART : Windscreen wiper"<<'\t'<<"PRICE : 20"<<endl<<endl;
    cout<<"CODE : 4"<<'\t'<<"PART : Wing mirror"<<'\t'<<"PRICE : 40"<<endl<<endl;
    cout<<"CODE : 5"<<'\t'<<"PART : Bonnet"<<'\t'<<'\t'<<"PRICE : 100"<<endl<<endl;
    cout<<"CODE : 6"<<'\t'<<"PART : Roof rack"<<'\t'<<"PRICE : 200"<<endl<<endl;
    cout<<"CODE : 7"<<'\t'<<"PART : Engine oil"<<'\t'<<"PRICE : 70"<<endl;
    cout<<"***************************************************************************"<<endl;
}
//*******************************************************************************************************************************//
Client* clientRead()
{
    Client * c = new Client;
    cout<<" NAME : "<<endl;
    cin>>c->name;
    cout<<" FAMILY : "<<endl;
    cin>>c->family;
    cout<<" CAR NAME : "<<endl;
    cin>>c->car_name;
    cout<<" CAR MODEL : "<<endl;
    cin>>c->car_model;
    c->next = NULL;
    c->total_price = 0;
    c->serviceList = NULL;
    c->partlist = NULL;
    c->flag = true;
    return c;
}

Service* serviceRead()
{
    Service * s = new Service;
    cout<<" SERVICE CODE : "<<endl;
    cin>>s->code;
    if(s->code > 20)
    {
        cout<<"This service is not in the default list . "<<endl;
        cout<<"Do you want to add this service ? (y/n) "<<endl;
        char ans;
        cin>>ans;
        if((ans == 'y')||(ans == 'Y'))
        {
            cout<<" SERVICE NAME : "<<endl;
            cin>>s->name;
            cout<< "SERVICE PRICE : "<<endl;
            cin>>s->price;
        }
        else return s;

    }
    switch (s->code)
    {
    case 1 :
        strcpy(s->name , "Axle repair");
        s->price = 100;
        break;
    case 2 :
        strcpy(s->name , "Balancing");
        s->price = 200;
        break;
    case 3 :
        strcpy(s->name , "Booster install");
        s->price = 450;
        break;
    case 4 :
        strcpy(s->name , "Engine tune up");
        s->price = 500;
        break;
    case 5 :
        strcpy(s->name , "Exhaust change");
        s->price = 30;
        break;
    case 6 :
        strcpy(s->name , "Air filter change");
        s->price = 20;
        break;
    case 7 :
        strcpy(s->name , "Generator change ");
        s->price = 120;
        break;
    case 8 :
        strcpy(s->name , "GearBox change ");
        s->price = 180;
        break;
    case 9 :
        strcpy(s->name , "Ignition repair");
        s->price = 210;
        break;
    case 10 :
        strcpy(s->name , "Lubrication");
        s->price = 80;
        break;
    case 11 :
        strcpy(s->name , "Piston change");
        s->price = 110;
        break;
    case 12 :
        strcpy(s->name , "Quandary repair");
        s->price = 300;
        break;
    case 13 :
        strcpy(s->name , "Suspension repair");
        s->price = 700;
        break;
    case 14 :
        strcpy(s->name , "Thermostat change");
        s->price = 60;
        break;
    case 15 :
        strcpy(s->name , "Undercarriage repair");
        s->price = 800;
        break;
    case 16 :
        strcpy(s->name , "Wheels repair");
        s->price = 100;
        break;
    case 17 :
        strcpy(s->name , "Xenon lights install");
        s->price = 40;
        break;
    case 18 :
        strcpy(s->name , "Oil change");
        s->price = 30;
        break;
    case 19 :
        strcpy(s->name , "Fan belt change" );
        s->price = 10;
        break;
    case 20 :
        strcpy(s->name , "Battery change");
        s->price = 150;
        break;
    }
    //cout<<" SERVICE NAME : "<<endl;
    //cin>>s->name;
    s->next = NULL;
    s->flag = true;
    return s;
}

Part* partRead()
{
    Part * p = new Part;
    cout<<"PART CODE :   ";
    cin>>p->code;
    if(p->code > 7)
    {
        cout<<"This part is not in the default list . "<<endl;
        cout<<"Do you want to add this part ? (y/n) "<<endl;
        char ans;
        cin>>ans;
        if((ans == 'y')||(ans == 'Y'))
        {
            cout<<" PART NAME : "<<endl;
            cin>>p->name;
            cout<< "PART PRICE : "<<endl;
            cin>>p->price;
        }
        else return p;
    }

    switch(p->code)
    {
    case 1 :
        strcpy(p->name , "Brake pedal");
        p->price = 30;
        break;
    case 2 :
        strcpy(p->name , "Clutch pedal");
        p->price = 30;
        break;
    case 3 :
        strcpy(p->name , "Windscreen wiper");
        p->price = 20;
        break;
    case 4:
        strcpy(p->name , "Wing mirror");
        p->price = 40;
        break;
    case 5:
        strcpy(p->name , "Bonnet");
        p->price = 100;
        break;
    case 6:
        strcpy(p->name , "Roof rack");
        p->price = 200;
        break;
    case 7:
        strcpy(p->name , "Engine oil");
        p->price = 70;
        break;
    }
    p->next = NULL;
    p->flag = true;
    return p;
}
//*******************************************************************************************************************************//
Client * addClientList ( Client * c , Client * list )
{
    if(list == NULL)
        return  c;
    c->next = list;
    list = c;
}

Service * addServiceList ( Service *s , Service *list)
{
    if(list == NULL)
        return s;
    s->next = list;
    list = s;
}

Part * addPartList ( Part *p , Part * list)
{
    if( list == NULL)
        return p;
    p->next = list;
    list = p;
}
//*******************************************************************************************************************************//
void clientWrite ( Client *list)
{
    cout<<"Client's Name : "<<list->name<<"   "<<list->family<<endl;
    cout<<"Client's Car : "<<list->car_name<<"   "<<list->car_model<<endl;
}

void serviceWrite( Client *c)
{
    clientWrite(c);
    Service * temp = new Service;
     temp = c->serviceList;
    cout<<"******SERVICES******  "<<endl;
    while( c->serviceList != NULL)
    {
        if(c->serviceList->flag == false)
        {
            c->serviceList = c->serviceList->next;
            if(c->serviceList == NULL)
                break;
        }
        if((c->serviceList->code == 6)||(c->serviceList->code == 7)||(c->serviceList->code == 13)||(c->serviceList->code == 14)||(c->serviceList->code == 15)||(c->serviceList->code == 17))
            cout<<"CODE : "<<c->serviceList->code<<'\t'<<"NAME : "<<c->serviceList->name<<'\t'<<"PRICE : "<<c->serviceList->price<<'T'<<endl;
        else
            cout<<"CODE : "<<c->serviceList->code<<'\t'<<"NAME : "<<c->serviceList->name<<'\t'<<'\t'<<"PRICE : "<<c->serviceList->price<<'T'<<endl;
        c->serviceList=c->serviceList->next;
    }
    //cout<<"TOTAL PRICE : "<<c->total_price<<'T'<<endl;
    //cout<<"********************************"<<endl;
    c->serviceList=temp;

}

void partWrite( Client *c)
{
    serviceWrite(c);
    Part * temp = new Part;
    temp = c->partlist;
    cout<<"******PARTS******  "<<endl;
    while ( c->partlist != NULL)
    {
        if(c->partlist->flag == false)
        {
            c->partlist = c->partlist->next;
            if(c->partlist == NULL)
                break;
        }
         if(c->partlist->code == 5)
            cout<<"CODE : "<<c->partlist->code<<'\t'<<"NAME : "<<c->partlist->name<<'\t'<<'\t'<<'\t'<<"PRICE : "<<c->partlist->price<<'T'<<endl;
        else
            cout<<"CODE : "<<c->partlist->code<<'\t'<<"NAME : "<<c->partlist->name<<'\t'<<'\t'<<"PRICE : "<<c->partlist->price<<'T'<<endl;
        c->partlist = c->partlist->next;
    }

    //cout<<"********************************"<<endl;
    cout<<"**********TOTAL PRICE********** : "<<c->total_price<<'T'<<endl;
    char l=205;
    for(int i=0 ; i<70 ; i++)
        cout<<l;
    cout<<endl;
    //cout<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<l<<endl;
    c->partlist = temp;
}
//*******************************************************************************************************************************//
void showClientList ( Client *list)
{
    while(list != NULL)
    {
        if(list->flag == false)
        {
            list = list->next;
            if(list == NULL)
                break;
        }
        partWrite(list);
        list= list->next;
    }
}

void showServiceList ( Service *list)
{
    while( list != NULL)
    {
        if(list->flag == false)
        {
            list=list->next;
            if(list == NULL)
                break;
        }
        cout<<list->code<<"     "<<list->name<<endl;
        list= list->next;
    }
}
//*******************************************************************************************************************************//
Client * findClientByName ( Client * list , char *name)
{
    while(list != NULL)
    {
        if(strcmp(list->name , name)==0)
            return list;
        list=list->next;
    }
    if(list == NULL)
        cout<<"NOT FOUND " <<endl;
}

Client * findClientByFamily ( Client *list , char *family)
{
    while(list != NULL)
    {
        if(strcmp(list->family , family)==0)
            return list;
        list=list->next;
    }
    if( list == NULL)
        cout<<"NOT FOUND"<<endl;
}
//*******************************************************************************************************************************//
void editClientByName ( Client *list , char *name)
{
    while(list != NULL)
    {
        if(strcmp(list->name , name )==0)
        {
            clientWrite(list);
            cout<<endl;
            cout<<"Which part to change ? "<<endl;
            cout<<"( 'n' = Name ---- 'f' = Family ---- 'c' = Car Name ---- 'm' = Car Model ---- 's' = Services ) "<<endl;
            char ans;
            cin>>ans;
            if((ans == 'n')||(ans == 'N'))
            {
                cout<<"Enter new name for this Client :   ";
                char new_name[50];
                cin>>new_name;
                strcpy(list->name , new_name);
                cout<<endl<<" EDITED " <<endl;
            }
            if((ans == 'f')||(ans == 'F'))
            {
                cout<<"Enter new family for this Client :   ";
                char new_family[50];
                cin>>new_family;
                strcpy(list->family , new_family);
                cout<<endl<<" EDITED " <<endl;
            }
            if((ans == 'c')||(ans == 'C'))
            {
                cout<<"Enter new name for this Client's car :   ";
                char new_car[50];
                cin>>new_car;
                strcpy(list->car_name , new_car);
                cout<<endl<<" EDITED" <<endl;
            }
            if((ans == 'm')||(ans == 'M'))
            {
                cout<<"Enter new model for this Client's car :   ";
                int new_model;
                cin>>new_model;
                list->car_model = new_model;
                cout<<endl<<" EDITED "<<endl;
            }

        }
        list = list->next;
    }
}

void editClientByFamily ( Client *list , char *family)
{
    while(list != NULL)
    {
        if(strcmp(list->family , family )==0)
        {
            clientWrite(list);
            cout<<endl;
            cout<<"Which part to change ? "<<endl;
            cout<<"( 'n' = Name ---- 'f' = Family ---- 'c' = Car Name ---- 'm' = Car Model ---- 's' = Services ) "<<endl;
            char ans;
            cin>>ans;
            if((ans == 'n')||(ans == 'N'))
            {
                cout<<"Enter new name for this Client :   ";
                char new_name[50];
                cin>>new_name;
                strcpy(list->name , new_name);
                cout<<endl<<" EDITED " <<endl;
            }
            if((ans == 'f')||(ans == 'F'))
            {
                cout<<"Enter new family for this Client :   ";
                char new_family[50];
                cin>>new_family;
                strcpy(list->family , new_family);
                cout<<endl<<" EDITED " <<endl;
            }
            if((ans == 'c')||(ans == 'C'))
            {
                cout<<"Enter new name for this Client's car :   ";
                char new_car[50];
                cin>>new_car;
                strcpy(list->car_name , new_car);
                cout<<endl<<" EDITED" <<endl;
            }
            if((ans == 'm')||(ans == 'M'))
            {
                cout<<"Enter new model for this Client's car :   ";
                int new_model;
                cin>>new_model;
                list->car_model = new_model;
                cout<<endl<<" EDITED "<<endl;
            }

        }
        list = list->next;
    }
}
//*******************************************************************************************************************************//
void deleteClientByName ( Client *list , char *name)
{
    while( list != NULL)
    {
        if(strcmp(list->name , name)==0)
        {
            clientWrite(list);
            list->flag = false;
            cout<<"DELETED"<<endl;
        }
        list = list->next;
    }
}

void deleteClientByFamily ( Client *list , char *family)
{
    while( list != NULL)
    {
        if(strcmp(list->family , family)==0)
        {
            clientWrite(list);
            list->flag = false;
            cout<<"DELETED"<<endl;
        }
        list = list->next;
    }
}

void deleteServiceByCode ( Client *list , int code)
{
    Service * temp = new Service;
    temp = list->serviceList;
    while(list->serviceList != NULL)
    {
        if(list->serviceList->code == code)
        {
            list->serviceList->flag = false;
            list->total_price -=list->serviceList->price;
            cout<<" SERVICE DELETED " <<endl;
        }
        list->serviceList = list->serviceList->next;
    }
    list->serviceList = temp;
}

void deletePartByCode ( Client * list , int code)
{
    Part * temp = new Part;
    temp = list->partlist;
    while(list->partlist != NULL)
    {
        if(list->partlist->code == code)
        {
            list->partlist->flag = false;
            list->total_price -= list->partlist->price;
            cout<<" PART DELETED"<<endl;
        }
        list->partlist = list->partlist->next;
    }
    list->partlist = temp;
}
//*******************************************************************************************************************************//
void recoverClientByName ( Client *list , char *name)
{
    while(list != NULL)
    {
        if(strcmp(list->name , name) == 0);
        {
            list->flag = true;
            partWrite(list);
            cout<<" CLIENT RECOVERD " <<endl;
        }
        list = list->next;
    }
}

void recoverClientByFamily ( Client *list , char *family)
{
    while ( list != NULL)
    {
        if(strcmp( list->family , family) == 0);
        {
            list->flag = true;
            partWrite(list);
            cout<<" CLIENT RECOVERD "<<endl;
        }
        list = list->next;
    }
}
//*******************************************************************************************************************************//
void saveClientList ( char * filename , Client * list )
{
    fstream file ;
    file.open( filename , ios :: out ) ;
    for( ; list != NULL ; list = list->next )
    {
        file.write((char *)list , sizeof(Client));
        for ( ; list->serviceList != NULL ; list->serviceList = list->serviceList->next)
            file.write((char*)list->serviceList , sizeof(Service));
        for ( ; list->partlist != NULL ; list->partlist = list->partlist->next)
            file.write((char*)list->partlist , sizeof(Part));
    }

    file.close();
}

Client * loadClientList (char *filename)//******just load a file with 3 SERVICES & 2 PARTS for each Client to be loaded correctly******
{
    Client * list = NULL;
    fstream file;
    file.open( filename , ios :: in);
    if(file)
    {
        while (1)
        {
            Client * c = new Client;
            file.read((char *)c , sizeof(Client));
            c->flag = true;
             if(file.eof())
                break;
            c->next=NULL;
            list = addClientList( c , list);
            list->serviceList = NULL;
            for(int i=0 ; i<3 ; i++)
            {
                Service *s = new Service;
                file.read((char*)s, sizeof(Service));
                s->flag = true;
                if(file.eof())
                    break;
                s->next=NULL;
                list->serviceList = addServiceList(s , list->serviceList);
            }
             list->partlist = NULL;
            for(int j=0 ; j<2 ; j++)
            {
                Part *p = new Part;
                file.read((char*)p , sizeof(Part));
                if(file.eof())
                    break;
                p->next=NULL;
                p->flag = true;
                list->partlist = addPartList( p , list->partlist);
            }
        }
    }
    file.close();
    return list;

}
//*******************************************************************************************************************************//
void mainMenu()
{
    char sound = 7 ;
    char point = 175;
    char point2 = 254;
    char h = 205 , v = 186 , edg = 201 , edg2 = 187 , edg3 = 200 , edg4 = 188 , line = 196;
    system("cls");
    cout<<sound;
    gotoxy(20,1);
    for(int h1 = 0 ; h1<40 ; h1++)
        cout<<h;
    gotoxy(20,13);
    for(int h3 = 0 ; h3<40 ; h3++)
        cout<<h;
    gotoxy(20,1);
    cout<<edg;
    gotoxy(60,1);
    cout<<edg2;
    gotoxy(20,13);
    cout<<edg3;
    gotoxy(60,13);
    cout<<edg4;
    for(int h2 = 0 ; h2<11 ; h2++)
    {
        gotoxy(20,2+h2);
        cout<<v;
        gotoxy(60,2+h2);
        cout<<v;
    }
    for(int j=0 ; j<9 ; j+=2)
    {
        gotoxy(21,3+j);
        for(int h4 = 0 ; h4<39 ; h4++)
            cout<<line;
       }
        gotoxy(21,0);
        cout<<"   **********   WELCOME   **********"<<endl;
        gotoxy(30,2);
        cout<<"****  MAIN MENU  **** "<<endl<<endl;
        gotoxy(21,4);
        cout<<"1 "<<point<<" Client settings     ( Press 1 ) "<<endl<<endl;
        gotoxy(21,6);
        cout<<"2 "<<point<<" Service settings    ( Press 2 ) "<<endl<<endl;
        gotoxy(21,8);
        cout<<"3 "<<point<<" Part settings       ( Press 3 ) " <<endl<<endl;
        gotoxy(21,10);
        cout<<"4 "<<point<<" Save informations   ( Press 4 )"<<endl<<endl;
        gotoxy(21,12);
        cout<<"5 "<<point<<" Load informations   ( Press 5 )"<<endl<<endl;
        gotoxy(30,14);
        cout<<"  Press 9 to EXIT "<<endl;
        gotoxy(0,18);
        cout<<"About... ( Press 6 )  "<<endl;
}



int main()
{
   Client * client_list = NULL;
   Part * part_list = NULL;
   Client *c;
   Service *s;
    int sum_price=0;
   Part *p;
   while(1)
   {
       system("color 1f");
       mainMenu();
       char first_ch;
       cin>>first_ch;
       if(first_ch == '1')//client
       {
           char second_ch;
           system("cls");
           cout<<"1) To add Client Press 1 "<<endl<<endl;
           cout<<"2) To delete Client press 2 "<<endl<<endl;
           cout<<"3) To edit Client press 3 " <<endl<<endl;
           cout<<"4) To show all Clients press 4 " <<endl<<endl;
           cout<<"5) To show a Client press 5 "<<endl<<endl;
           cout<<"6) To recover a Client press 6"<<endl<<endl;
           cout<<"Press 0 to go to MAIN MENU "<<endl<<endl;
           cin>>second_ch;
           if(second_ch == '1')//add client
           {
               while(1)
               {
                   sum_price = 0;
                   part_list = NULL;
                   int i=0;
                   cout<<i+1<<"Th Client : "<<endl;
                   c=clientRead();
                   client_list = addClientList(c , client_list);
                   Service * service_list = NULL;
                    cout<<"Do you want to add service(s) to this Client ? (y/n)   ";
                    char ans;
                    cin>>ans;
                    if(ans == 'y')
                    {
                        cout<<"Do you want to see the default services list before adding services ? (y/n)"<<endl;
                        char ans1;
                        cin>>ans1;
                        if(ans1 == 'y')
                        {
                            serviceDefault();
                            cout<<"**********************************************"<<endl;
                        }

                        while(1)
                        {
                            s=serviceRead();
                            sum_price+=s->price;
                            service_list = addServiceList(s , service_list);
                            cout<<"Another service ? (y/n)  ";
                            char ans3;
                            cin>>ans3;
                            if(ans3 == 'n')
                                    break;
                        }
                        c->serviceList = service_list;
                        c->total_price = sum_price;
                    }
                   cout<<"Do you want to add part(s) to this Client ? (y/n)   ";
                   char ans1;
                   cin>>ans1;
                   if(ans1 == 'y')
                   {
                        cout<<"Do you want to see the default parts list before adding parts ? (y/n)"<<endl;
                        char ans2;
                        cin>>ans2;
                        if(ans2 == 'y')
                        {
                            partDefault();
                                cout<<"**********************************************"<<endl;

                        }
                        while(1)
                        {
                            p=partRead();
                            sum_price += p->price;
                            part_list = addPartList(p , part_list);
                            cout<<"Another part ? (y/n)   ";
                            char ans4;
                            cin>>ans4;
                            if(ans4 == 'n')
                                    break;
                        }
                        c->partlist = part_list;
                        c->total_price = sum_price;
                   }
                   cout<<"Another Client ? (y/n)   ";
                   char ans5;
                   cin>>ans5;
                   if(ans5 == 'n')
                        break;

               }
               char ch1;
               cout<<"Want to see the complete list of Clients ? (y/n) " <<endl;
               cin>>ch1;
               if((ch1 == 'y')||(ch1 == 'Y'))
               {
                    system("cls");
                    showClientList(client_list);
                    getch();
               }
               else continue;
           }
           else if(second_ch == '2')//del client
           {
               cout<<"How do yo want to find the Client ? ( 'n' = by name ---- 'f' = by family ) "<<endl;
               char ans;
               cin>>ans;
               if((ans == 'n')||(ans == 'N'))
                {
                      cout<<"Enter name : "<<endl;
                      char name_del[50];
                      cin>>name_del;
                      deleteClientByName(client_list , name_del);
                      getch();
                }
                else if((ans == 'f')||(ans == 'F'))
                {
                    cout<<"Enter family : "<<endl;
                    char family_del[50];
                    cin>>family_del;
                    deleteClientByFamily(client_list , family_del);
                    getch();
                }
           }
           else if(second_ch == '3')//edit client
           {
               cout<<"How do yo want to find the Client ? ( 'n' = by name ---- 'f' = by family ) "<<endl;
               char ans;
               cin>>ans;
               if((ans == 'n')||(ans == 'N'))
                {
                      cout<<"Enter name :   ";
                      char name_edit[50];
                      cin>>name_edit;
                      editClientByName(client_list , name_edit);
                      getch();
                }
                else if((ans == 'f')||(ans == 'F'))
                {
                    cout<<"Enter family :   ";
                    char family_edit[50];
                    cin>>family_edit;
                    editClientByFamily(client_list , family_edit);
                    getch();
                }
           }
           else if(second_ch == '4')//show client
           {
               showClientList(client_list);
               getch();
           }
           else if(second_ch == '5')//show one client
           {
               cout<<"How do yo want to find the Client ? ( 'n' = by name ---- 'f' = by family ) "<<endl;
               char ans;
               cin>>ans;
               if((ans == 'n')||(ans == 'N'))
               {
                   cout<<"Enter name :   ";
                   char name_find[50];
                   cin>>name_find;
                   partWrite(findClientByName(client_list , name_find));
                   getch();
               }
               else if((ans == 'f')||(ans == 'F'))
               {
                   cout<<"Enter family :   ";
                   char family_find[50];
                   cin>>family_find;
                   partWrite(findClientByFamily(client_list , family_find));
                   getch();
               }
           }
            else if(second_ch == '6')//recover client
            {
                cout<<"How do yo want to find the Client ? ( 'n' = by name ---- 'f' = by family ) "<<endl;
                char ans;
                cin>>ans;
                if((ans == 'n')||(ans == 'N'))
                {
                      cout<<"Enter name : "<<endl;
                      char name_del[50];
                      cin>>name_del;
                      recoverClientByName(client_list , name_del);
                      getch();
                }
                else if((ans == 'f')||(ans == 'F'))
                {
                    cout<<"Enter family : "<<endl;
                    char family_del[50];
                    cin>>family_del;
                    recoverClientByFamily(client_list , family_del);
                    getch();
                }
            }
       }
        else if(first_ch == '2')//services
        {
            char second_ch;
            system("cls");
            cout<<"1) To add services to a  Client press 1 "<<endl<<endl;
            cout<<"2) To delete services of a Client list press 2 " <<endl<<endl;
            cout<<"3) To show all available services  press 3 "<<endl<<endl;
            cout<<"Press 0 to go to MAIN MENU "<<endl<<endl;
            cin>>second_ch;
            if(second_ch == '1')//add service
            {
                Client * found = new Client;
                cout<<"How to find the Client ? ( 'n' = Name ---- 'f' = Family ) "<<endl;
                char ans;
                cin>>ans;
                if((ans == 'n')||(ans == 'N'))
                {
                    cout<<"Enter name :   ";
                    char name_srvc[50];
                    cin>>name_srvc;
                    found = findClientByName(client_list , name_srvc);
                    partWrite(found);
                    cout<<"How many services to add ?   ";
                    int srvc_num;
                    cin>>srvc_num;
                    Service * service_list = found->serviceList;
                    cout<<"Do you want to see the default services list before adding services ? (y/n)"<<endl;
                   char ans1;
                   cin>>ans1;
                   if(ans1 == 'y')
                   {
                       serviceDefault();
                       cout<<"**********************************************"<<endl;
                   }
                    for(int i=0 ; i<srvc_num ; i++)
                    {
                        s=serviceRead();
                        service_list = addServiceList(s , service_list );
                        sum_price += s->price;
                    }
                    found->serviceList = service_list;
                    found->total_price = sum_price;
                }
                else if((ans == 'f')||(ans == 'F'))
                {
                    cout<<"Enter family :  ";
                    char family_srvc[50];
                    cin>>family_srvc;
                    found = findClientByFamily(client_list , family_srvc);
                    partWrite(found);
                    cout<<"How many services to add ?   ";
                    int srvc_num;
                    cin>>srvc_num;
                    Service * service_list = found->serviceList;
                    cout<<"Do you want to see the default services list before adding services ? (y/n)"<<endl;
                   char ans1;
                   cin>>ans1;
                   if(ans1 == 'y')
                   {
                       serviceDefault();
                       cout<<"**********************************************"<<endl;
                   }
                    for(int i=0 ; i<srvc_num ; i++)
                    {
                        s=serviceRead();
                        service_list = addServiceList(s , service_list );
                        sum_price += s->price;
                    }
                    found->serviceList = service_list;
                    found->total_price = sum_price;
                }
                cout<<" ADDED";
                getch();
            }
            else if(second_ch == '2')//del service
            {
                Client * found = new Client;
                cout<<"How to find the Client ? ( 'n' = Name ---- 'f' = Family ) "<<endl;
                char ans;
                cin>>ans;
                if((ans == 'n')||(ans == 'N'))
                {
                    cout<<"Enter name :  ";
                    char name_srvc[50];
                    cin>>name_srvc;
                    found = findClientByName(client_list , name_srvc);
                    partWrite(found);
                    cout<<"Enter code of service to delete :  ";
                    int code_del;
                    cin>>code_del;
                    deleteServiceByCode(client_list , code_del);
                    getch();
                }
                else if((ans == 'f')||(ans == 'F'))
                {
                    cout<<"Enter Family :  ";
                    char family_srvc[50];
                    cin>>family_srvc;
                    found = findClientByFamily( client_list , family_srvc);
                    partWrite(found);
                    cout<<"Enter code of service to delete :   ";
                    int code_del;
                    cin>>code_del;
                    deleteServiceByCode(client_list , code_del);
                    getch();
                }
            }
            else if(second_ch == '3')//show all services
            {
                serviceDefault();
                getch();
            }
        }
        else if(first_ch == '3')//parts
        {
            char second_ch;
            system("cls");
            cout<<"1) To add parts to a  Client press 1 "<<endl<<endl;
            cout<<"2) To delete parts of a Client list press 2 " <<endl<<endl;
            cout<<"3) To show all available parts  press 3 "<<endl<<endl;
            cout<<"Press 0 to go to MAIN MENU "<<endl<<endl;
            cin>>second_ch;
            if(second_ch == '1')//add parts
            {
                Client * found = new Client;
                cout<<"How to find the Client ? ( 'n' = Name ---- 'f' = Family ) "<<endl;
                char ans;
                cin>>ans;
                if((ans == 'n')||(ans == 'N'))
                {
                    cout<<"Enter name :   ";
                    char name_srvc[50];
                    cin>>name_srvc;
                    found = findClientByName(client_list , name_srvc);
                    partWrite(found);
                    cout<<"How many parts to add ?   ";
                    int part_num;
                    cin>>part_num;
                    part_list = found->partlist;
                    cout<<"Do you want to see the default parts list before adding parts ? (y/n)"<<endl;
                   char ans1;
                   cin>>ans1;
                   if(ans1 == 'y')
                   {
                       partDefault();
                       cout<<"**********************************************"<<endl;
                   }

                    for(int i=0 ; i<part_num ; i++)
                    {
                        p=partRead();
                        part_list = addPartList(p , part_list);
                        sum_price += p->price;
                    }
                    found->partlist = part_list;
                    found->total_price = sum_price;

                }
                else if((ans == 'f')||(ans == 'F'))
                {
                    cout<<"Enter family :  ";
                    char family_srvc[50];
                    cin>>family_srvc;
                    found = findClientByFamily(client_list , family_srvc);
                    partWrite(found);
                    cout<<"How many parts to add ?   ";
                    int srvc_num;
                    cin>>srvc_num;
                    part_list = found->partlist;
                    cout<<"Do you want to see the default parts list before adding parts ? (y/n)"<<endl;
                   char ans1;
                   cin>>ans1;
                   if(ans1 == 'y')
                   {
                       partDefault();
                       cout<<"**********************************************"<<endl;
                   }
                    for(int i=0 ; i<srvc_num ; i++)
                    {
                        p=partRead();
                        part_list = addPartList(p , part_list);
                        sum_price += p->price;
                    }
                    found->partlist = part_list;
                    found->total_price = sum_price;

                }
                cout<<" ADDED " ;
                getch();
            }
            else if(second_ch == '2')//del parts
            {
                 Client * found = new Client;
                cout<<"How to find the Client ? ( 'n' = Name ---- 'f' = Family ) "<<endl;
                char ans;
                cin>>ans;
                if((ans == 'n')||(ans == 'N'))
                {
                    cout<<"Enter name :  ";
                    char name_srvc[50];
                    cin>>name_srvc;
                    found = findClientByName(client_list , name_srvc);
                    partWrite(found);
                    cout<<"Enter code of part to delete :  ";
                    int code_del;
                    cin>>code_del;
                    deletePartByCode(client_list , code_del);
                    getch();
                }
                else if((ans == 'f')||(ans == 'F'))
                {
                    cout<<"Enter Family :  ";
                    char family_srvc[50];
                    cin>>family_srvc;
                    found = findClientByFamily( client_list , family_srvc);
                    partWrite(found);
                    cout<<"Enter code of part to delete :   ";
                    int code_del;
                    cin>>code_del;
                    deletePartByCode(client_list , code_del);
                    getch();
                }
            }
            else if(second_ch == '3')//show all parts
            {
                partDefault();
                getch();
            }
        }
        else if(first_ch == '4')//save
        {
            Service * service_list = NULL;
            cout<<"Enter a name for the file :   ";
            char * name = new char[50];
            cin>>name;
            saveClientList(name , client_list);
            cout<<"SAVED "<<endl;
            getch();
        }
        else if(first_ch == '5')//load
        {
            cout<<"Enter file name to load :  ";
            char namefile[50];
            cin>>namefile;
            client_list=loadClientList(namefile);
            cout<<"LOADED";
            getch();
        }
        else if(first_ch == '9')//exit
        {
            system("cls");
            gotoxy(10,10);
            cout<<"**********  Thank You For Using This Program  **********";
            gotoxy(10,17);
            cout<<" MADE BY : A.JEY ";
            gotoxy(10,19);
            cout<<" Yazd University - Computer Engineering Faculty ";
            cout<<endl<<endl<<endl;
            getch();
            exit(1);
        }
        else if(first_ch == '6')//about
        {
            system("cls");
            gotoxy(10,10);
            cout<<"This is a program for collecting factors of a Auto repair store " ;
            gotoxy(10,12);
            cout<<"This program is made by Atta Jirofty ";
            gotoxy(10,14);
            cout<<"Created in 1395/10/15 ( 2017/1/4 )";
            gotoxy(10,16);
            cout<<"For farther help please contact us : jey_auto_repair @ gmail.com ";
            getch();
        }

   }
    return 0;
}
