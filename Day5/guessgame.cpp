
#include <iostream>
#include <time.h>

using namespace std;

int lucky_number = time(0) % 10 +1;
int score = 5;

bool play_again(){
    char answer;
    cout<<"__________________________________"<<endl;
    cout<<"Do you want to play again ? (y/n) "<<endl;
    cin>>answer;
    
    switch(answer){
        case 'y':
             cout<<"______________________"<<endl;
             cout<<"Great! Lets Play again"<<endl;
             cout<<"______________________"<<endl;
             if(score == 0){
                 return score =5;
             }else{
                 return score;
             }
             return true;

        case 'n':
            cout<<"______________________"<<endl;
            cout<<"Thanks for playing!"<<endl;
            cout<<"______________________"<<endl;
            cin.get();
            return false;
        
        default:
            cout<<"______________________"<<endl;
            cout<<"Invalid Input! Please try again"<<endl;
            cout<<"______________________"<<endl;
            play_again();
    }
}
bool guessing(){
    int guess;
   cout << "Guess the lucky number: ";
   cin >> guess;
    
   if(guess > 10 || guess < 1){
       cout << "Invalid number. Please enter the number between 1 to 10\n";
       cout <<endl;
       guessing();
   }else{
       if(guess == lucky_number){
           cout << "*********************************"<<endl;
           cout << "You are Guessing the Right Number"<<endl;
           cout << "*********************************"<<endl;
           cout << "Your score is: "<< score<<endl;
           
           bool answer = play_again();
           return answer;
           
       }else{
           
           cout << "Wrong Number. Try again" <<endl;
           score = score -1 ;
           cout << "Chances left: " << score << endl;
           if(score == 0){
               cout << "!!! Game over !!!"<<endl;
               
                bool answer = play_again();
                return answer;
           }else{
               guessing();
           }
           
       }
   }
}

int main()
{
    cout << lucky_number << endl;
   cout << "--------------------------------" << endl;
   cout << "*** Welcome to Guessing Game ***" << endl;
   cout << "--------------------------------" <<endl;
   cout << endl;
   cout << "You have 5 chances to guess the lucky number";
   cout <<endl;
   cout << "Number will be between 1 to 10\n";
   
   bool user_choice = guessing();
   if(user_choice){
       main();
     }else{
         cin.get();
         return 0;
     }

}
