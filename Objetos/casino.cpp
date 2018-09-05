#include<iostream>
#include<time.h>
#include<string>

using namespace std;

void draw_line(int n,char ch);

class Casino{
    Casino(){
        cout<<"\n\n\n\n\t\tCASINO GAME\n\n\n\n";
        cout<<"\n\n\nEnter Your Name  :";
        cin >> this->nombre;
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
        do{
            rules();
            cout<<"\n\nYour current balance is Rs."<<balance;
            do{
                int amt;
                cout<<"\n\n"<< nombre <<" enter money to bet";
                cin>>amt;
                if(amt>balance)
                    cout<<"Your betting amount is more than your current balance\n\nRe-enter data\n ";
                else
                    break;
            }while(1);
            
            do
            {
                int no;
                cout<<"Enter your lucky number to bet between 1 to 12 :";
                cin>>no;
                if(no<=0||no>12)
                    cout<<"Please check the number!! should be between 1 to 12\n\nRe-enter data\n ";
                else
                    break;
            }
            while(1);
            randomize();
            dice=random(12)+1;
            if(dice==no)
            {
                cout<<"\n\nGood Luck!! You won Rs."<<amt*10;
                balanceamt=balanceamt+amt*10;
            }
            else
            {
                cout<<"Bad Luck this time !! You lose Rs."<<amt;
                balanceamt=balanceamt-amt;
            }
            cout<<"\n\nThe winning number was : "<<dice;

            cout<<"\n\n\t"<<playername<<" You have Rs. "<<balanceamt<<endl;
            cout<<"\n\n-->Do you want to play (y/n)? ";
            cin>>ch;
        }
        while(ch=='Y'|| ch=='y');
    }


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

    private:
    int balance
    string nombre;

    void draw_line(int n,char ch)
    {
        for(int i=0; i<n; i++)
            cout<<ch;
    }

};

void main()
{
    int balanceamt,amt,no,dice;
    char playername[80],ch;
    cout << flush;
    Casino cas();
    cas.play();
}