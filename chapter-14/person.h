#ifndef PERSON_H_
#define PERSON_H_
#include <string>
class Person
{
private:
    std::string fname;
    std::string lname;
public:
    Person(const char* fn = "none", const char* ln = "none"):fname(fn), lname(ln){}
    Person(const Person &p){fname = p.fname; lname = p.lname;}
    virtual ~Person(){}
    virtual void Show() const;
    virtual void SET();
};

class Gunslinger : virtual public Person
{
private:
    double dtime;
    int notch;
public:
    Gunslinger(){}
    ~Gunslinger(){}
    Gunslinger(const char* fn, const char* ln, const double dt, const int nt)
    : Person(fn, ln), dtime(dt), notch(nt){}
    Gunslinger(const Person &p, const double dt, const int nt)
    : Person(p), dtime(dt), notch(nt){}
    const double & Draw() const {return dtime;}
    void Show() const;
    void SET();
};

class PokerPlayer : virtual public Person
{
public:
    PokerPlayer(){}
    ~PokerPlayer(){}
    PokerPlayer(const char *fn, const char* ln):Person(fn, ln){}
    PokerPlayer(const Person &p): Person(p){}
    int Draw();
    void Show();
    void SET();
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude(){}
    BadDude(const char* fn, const char* ln, const double dt, const int nt)
    :Person(fn, ln), Gunslinger(fn, ln, dt, nt), PokerPlayer(fn, ln){}
    BadDude(const Person &p, const double dt, const int nt)
    : Person(p), Gunslinger(p, dt, nt), PokerPlayer(p){}
    double Gdraw(){return Gunslinger::Draw();}
    int Cdraw(){return PokerPlayer::Draw();}
    void Show();
    void SET();
    ~BadDude(){}
};
#endif // PERSON_H_
