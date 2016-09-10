#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j)
    : fname(fn), lname(ln), job(j){}
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream & operator<<(std::ostream &os, const abstr_emp &e);
    //just displays first and last name
    virtual ~abstr_emp() = 0; //virtual base base
};

class employee : public abstr_emp
{
public:
    employee(): abstr_emp(){}
    employee(const std::string &fn, const std::string &ln, const std::string &j)
    : abstr_emp(fn, ln, j){}
    virtual void ShowAll() const;
    virtual void SetAll();
    ~employee(){}
};

class manager: virtual public abstr_emp
{
private:
    int inchargeof; //number of abstr_emps managed
protected:
    int InChargeOf() const {return inchargeof;} //output
    int & InChargeOf() {return inchargeof;} //input
public:
    manager():abstr_emp(), inchargeof(0){}
    manager(const std::string &fn, const std::string &ln, const std::string &j, int ico = 0)
    :abstr_emp(fn, ln, j), inchargeof(ico){}
    manager(const abstr_emp &e, int ico):abstr_emp(e), inchargeof(ico){}
    manager(const manager &m);
    ~manager(){}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink: virtual public abstr_emp
{
private:
    std::string reportsto;// to whom fink reports
protected:
    const std::string ReportsTo() const {return reportsto;}
    std::string & ReportsTo() {return reportsto;}
public:
    fink():abstr_emp(){reportsto = "none";}
    fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo)
    :abstr_emp(fn, ln, j), reportsto(rpo){}
    fink(const abstr_emp &e, const std::string &rpo)
    : abstr_emp(e),reportsto(rpo){}
    fink(const fink &e);
    virtual void ShowAll() const;
    virtual void SetAll();
    ~fink(){}
};

class highfink: public manager, public fink //management fink
{
public:
    highfink():abstr_emp(), manager(), fink(){}
    highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico)
    :abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo){}
    highfink(const abstr_emp &e, const std::string &rpo, int ico)
    :abstr_emp(e), manager(e, ico), fink(e, rpo){}
    highfink(const fink &f, int ico):fink(f){InChargeOf() = ico;}
    highfink(const manager &m, const std::string &rpo):manager(m){ReportsTo() = rpo;}
    highfink(const highfink &h);
    ~highfink(){}
    virtual void ShowAll() const;
    virtual void SetAll();
};
#endif // EMP_H_
