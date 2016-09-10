#include "emp.h"
using namespace std;
abstr_emp::abstr_emp()
{
    fname = lname = job = "none";
}

abstr_emp::~abstr_emp()
{

}

void abstr_emp::ShowAll() const
{
    cout << "Your name: " << fname << " " << lname << endl;
    cout << "Your job: " << job << endl << endl;
}

void abstr_emp::SetAll()
{
    cout << "Enter your first name: ";
    getline(cin, fname);
    cout << "Enter your last name: ";
    getline(cin, lname);
    cout << "Enter your job: ";
    getline(cin, job);
}

ostream & operator<<(ostream &os, const abstr_emp &e)
{
    os << "Your name: " << e.fname << " " << e.lname << endl;
    return os;
}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

manager::manager(const manager &m):abstr_emp(m)
{
    inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Number of abstr_emps managed: " << inchargeof << "\n\n";
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter number of abstr_emps managed: ";
    cin >> inchargeof;
    while (cin.get() != '\n')
        continue;
}

fink::fink(const fink &e):abstr_emp(e)
{
    reportsto = e.reportsto;
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Reports: " << reportsto << "\n\n";
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter reports: ";
    getline(cin, reportsto);
}

highfink::highfink(const highfink &h):abstr_emp(h)
{
    InChargeOf() = h.InChargeOf();
    ReportsTo() = h.ReportsTo();
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter number of abstr_emps managed: ";
    cin >> InChargeOf();
    while (cin.get() != '\n')
        continue;
    cout << "Enter reports: ";
    getline(cin, ReportsTo());
}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Number of abstr_emps managed: " << InChargeOf() << endl;
    cout << "Reports: " << ReportsTo() << "\n\n";
}
