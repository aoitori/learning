//glof.h--for pe9-1.cpp

class golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    golf(){fullname[0] = '\0'; handicap = 0;}
    golf(const char* fn, int s = 0);
    int setgolf (golf &g);
    void handget (const int hc);
    void showgolf() const;
};
