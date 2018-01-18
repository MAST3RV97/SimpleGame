#include <iostream>
#include <string>
#include <sstream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

#define ANSI_COLOR_BRIGHT  "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"


using namespace std;


// Creation function tostr() to convert float to string
template <typename T> string tostr(const T& t) { 
   ostringstream os; 
   os<<t; 
   return os.str(); 
} 
// END


// Global variables
string info = "";
int cash = 0;
int bank = 0;
int snack = 0;
bool debug = false;
// END


// ------------Bank operation----------------------------------------

int getBankMoney() {
    
    return bank;
}

void setBankMoney(int money) {
     
     bank = money;
}

void addBankMoney(int money) {
     
     bank += money;
}

void removeBankMoney(int money) {
     
     bank -= money;
}

void showBankMoney() {
     
     cout<<"BANK:   $"<<getBankMoney()<<endl;
}
// ---------------------------------------------------------------------

// -----------------Log operation---------------------------------------

void setLog(string log) {
     
     info = log;
}

string getLog() {
       
       return info;
}
// ---------------------------------------------------------------------

// -------------------Cash operation------------------------------------

void setCash(int money) {
     
     cash = money;
}

int getCash() {
      
      return cash;
}

void addCash(int money) {
     
     cash += money;
}

void removeCash(int money) {
     
     cash -= money;
}

void showCashMoney() {
     
     //cout<<"CASH:   $"<<getCash()<<endl;
     cout<<ANSI_COLOR_GREEN<<"CASH:   $"<< getCash()<<endl;
}
// ---------------------------------------------------------------------

// -----------------------Snack Operation-------------------------------

int getSnack() {
    
    return snack;
}

void setSnack(int amount) {
     
     snack = amount;
}

void addSnack() {
     
     snack++;
}

void removeSnack() {
     
     snack--;
}

void showSnack() {
     
     cout<<"SNACKS: "<<getSnack()<<endl;
}

// ---------------------------------------------------------------------

// function to clear the screen
void clear() {
     
     system("cls");
}

// --------------------------Menu operation-----------------------------

void showMenu_addMoney() {
     
     int amount;
     showCashMoney();
     cout<<endl;
     cout<<"[DEBUG] MONEY TO ADD: ";
     cin>>amount;
     addCash(amount);
     setLog("YOU'VE ADDED $"+tostr(amount));
}

void showMenu_removeMoney() {
     
     int amount;
     cout<<"[DEBUG] MONEY TO REMOVE: ";
     cin>>amount;
     removeCash(amount);
     setLog("YOU'VE REMOVED $"+tostr(amount));
}

void showMenu_setMoney() {
     
     int amount;
     cout<<"[DEBUG] MONEY TO SET: ";
     cin>>amount;
     setCash(amount);
     setLog("YOU'VE SET THE CASH TO $"+tostr(amount));
}

void showMenu_buySnack() {
     
     if (getCash()-10 >= 0) {
                                     
          removeCash(10);
          addSnack();
          setLog("YOU'VE BOUGHT A SNACK");
     }
     else {
                           
          setLog("[SNACK] TRANSACTION FAILED");
     }
}

void work() {
     
     int money = rand() % 1000 + 500;
     addCash(money);
     setLog("You earned $"+tostr(money)+" from work");
}

void showMenu_balanceOption() {
     
     int scelta;
     cout<<"#########Bank Option##############"<<endl;
     showCashMoney();
     showBankMoney();
     cout<<endl;
     cout<<"-OPERATIONS-"<<endl;
     cout<<"1 - Deposit"<<endl;
     cout<<"2 - Deposit all"<<endl;
     cout<<endl;
     cout<<"3 - Withdraw"<<endl;
     cout<<"4 - Withdraw all"<<endl;
     cout<<endl;
     cout<<">";
     cin>>scelta;
     switch(scelta) {
                    
                    int amount;
                    case 1: 
                         
                         cout<<"How much money do you want to deposit: $";
                         cin>>amount;
                         if (getCash() - amount >= 0 && amount >= 0) {
                                       
                                       removeCash(amount);
                                       addBankMoney(amount);
                                       setLog("You have deposited $"+tostr(amount)+" in the Bank");
                         }
                         else
                         {
                             setLog("[DEPOSIT] TRANSACTION FAILED");
                         }
                         break;
                         
                    case 2:
                         
                         amount = getCash();
                         if (amount >= 0) {
                                    
                                    addBankMoney(amount);
                                    setLog("You have deposited $"+tostr(amount)+" to the Bank");
                                    setCash(0);
                         }
                         break;
                    
                    case 3:
                         
                         cout<<"How much money do you want to withdraw: $";
                         cin>>amount;
                         if (getBankMoney() - amount >=0 && amount >= 0) {
                                            
                                            removeBankMoney(amount);
                                            addCash(amount);
                                            setLog("You have withdrawn $"+tostr(amount)+" from Bank");
                         }
                         else
                         {
                             setLog("[WITHDRAW] TRANSACTION FAILED");
                         }
                         break;
                         
                    case 4:
                         
                         amount = getBankMoney();
                         if (amount >= 0) {
                                    
                                    addCash(amount);
                                    setLog("You have withdrawn "+tostr(amount)+" from the Bank");
                                    setBankMoney(0);
                         }
                         break;
                    default: setLog("OPERATION NOT IN LIST");
     }
}

// -------------------Debug Operation------------------------------

void toggleDebug() {
     
     if (debug) {
        
        debug = false;
     }
     else {
          
          debug = true;
     }
}

bool getDebugStatus() {
     
     return debug;
}
// --------------------------------------------------------------------
     
// ----------------------------MAIN-------------------------------------
int main() {
    
    while (true) {
          
          clear();
          int scelta;
          cout<<"           Menu principale"<<endl;
          showCashMoney();
          showBankMoney();
          showSnack();
          if (debug) {
                     
                     cout<<endl;
                     cout<<endl;
                     cout<<"-DEBUG-"<<endl;
                     cout<<"777 - Add Cash"<<endl;
                     cout<<"778 - Remove Cash"<<endl;
                     cout<<"789 - Set Cash"<<endl;
                     cout<<"-DEBUG-"<<endl;
          }
          cout<<endl;
          cout<<endl;
          cout<<"1 - Buy snack ($10)"<<endl;
          cout<<"2 - Work"<<endl;
          cout<<"3 - Bank Option"<<endl;
          cout<<endl;
          cout<<endl;
          cout<<"LOG: "<<getLog()<<endl;
          cout<<endl;
          cout<<endl;
          cout<<">"; //This is the cursor
          cin>>scelta;
          switch (scelta) {
// ------------------------------Debug Part----------------------------------------------------                 
                 case 6351:
                      
                      if (getDebugStatus()) setLog("DEBUG MODE DEACTIVATED");
                      else setLog("DEBUG MODE ACTIVATED");
                      toggleDebug();
                      break;
                 
                 case 777:
                      
                      if (getDebugStatus()) {
                          
                          clear();
                          showMenu_addMoney();
                      }
                      else {
                           
                          setLog("OPERATION NOT IN LIST");
                      }
                      break;
                      
                 case 778:

                      if (getDebugStatus()) {
                          
                          clear();
                          showMenu_removeMoney();
                      }
                      else {
                           
                          setLog("OPERATION NOT IN LIST");
                      }
                      break;
                      
                 case 789:
                      
                      if (getDebugStatus()) {
                          
                          clear();
                          showMenu_setMoney();
                      }
                      else {
                           
                          setLog("OPERATION NOT IN LIST");
                      }
                      break;
// --------------------------------------------------------------------------------------------                      
                 case 1:
                      
                      clear();
                      showMenu_buySnack();
                      break;
                 
                 case 2:
                      
                      work();
                      break;
                      
                 case 3:
                      
                      clear();
                      showMenu_balanceOption();
                      break;
                        
                 default:
                         setLog("OPERATION NOT IN LIST");
          }
    }
    return 0;
}
    
    
