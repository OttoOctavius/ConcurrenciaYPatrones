#include<iostream>
#include<time.h>
#include<string>
#include<random>

using namespace std;

void draw_line(int n,char ch);

class Casino{
    public:
    Casino(){
        cout<<"\n\n\n\n\t\tCASINO GAME\n\n\n\n";
        cout<<"\n\n\nEnter Your Name  :";
        getline(cin, nombre);
        cout<<"\n\n\Enter Deposit amount to play game :";
        cin>>balance;
    }
    ~Casino(){
        cout<<"\n\n\n";
        draw_line(70,'+');
        cout<<"\n\n\t\THANKS FOR COME TO CASINO YOUR BALANCE AMOUNT IS RS."<<balance<<"\n\n";
        draw_line(70,'+');
        cout<<"\n\nGame developed by ANIKET RAJPUT, changed by Otto\n";
        draw_line(70,'+');
    }

    void play(){
        char ch;
        do{
            rules();
            cout<<"\n\nYour current balance is Rs."<<balance;
            int amt = apuesta();            
            int no = ingresar();
            int dice=(rand()%12)+1;
            if(dice==no)
            {
                cout<<"\n\nGood Luck!! You won Rs."<<amt*10;
                balance=balance+amt*10;
            }
            else
            {
                cout<<"Bad Luck this time !! You lose Rs."<<amt;
                balance=balance-amt;
            }
            cout<<"\n\nThe winning number was : "<<dice;

            cout<<"\n\n\t"<<nombre<<" You have Rs. "<<balance<<endl;
            cout<<"\n\n-->Do you want to play (y/n)? ";
            cin>>ch;
        }
        while(ch=='Y'|| ch=='y');
    }

    int ingresar(){
        int no;
        do{
                cout<<"Enter your lucky number to bet between 1 to 12 :";
                cin>>no;
            }
            while(no<=0||no>12);
        return no;
    }
    int apuesta(){
        int amt;
            do{
                cout<<"\n\n"<< nombre <<" enter money to bet";
                cin>>amt;
                if(amt>balance)
                    cout<<"Your betting amount is more than your current balance\n\nRe-enter data\n ";
                else
                    break;
            }while(1);
        return amt;   
    }

    private:
    void rules()
    {
        cout<<"\n\n";
        draw_line(60,'-');
        cout<<"\n\t\tRULES OF THE GAME\n";
        draw_line(60,'-');
        cout<<"\n\t1. Choose any number between 1 to 12\n\t2. If you win you will get 10 times of money you bet\n\t3. If you bet on wrong number you will lose your betting amount\n\n";
        draw_line(60,'-');
        cout<<endl;
    }


    int balance;
    string nombre;

    void draw_line(int n,char ch)
    {
        for(int i=0; i<n; i++)
            cout<<ch;
    }

};

int main()
{
    int balanceamt,amt,no,dice;
    char playername[80],ch;
    cout << flush;
    Casino cas;
    cas.play();
    return 0;
}d