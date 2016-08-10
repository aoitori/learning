#include <cstring>
class plorg
{
private:
    enum {MAX = 20};
    char name[MAX];
    int CI;
public:
    plorg(){strcpy(name, "Plorga"); CI = 0;}
    plorg(const char *n, int c = 0);
    ~plorg(){};
    void change (const int &i){CI = i;}
    void showplorg () const;
};
