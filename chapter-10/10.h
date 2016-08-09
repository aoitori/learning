#include <string>
using std::string;
class BankAccount
{
private:
    string name;
    string acctnum;
    double balance;
public:
    BankAccount();
    BankAccount(const string &client, const string &num, double bal = 0.0);
    ~BankAccount();
    void show(void) const;
    void deposit (double cash);
    void withdraw (double cash);
};
