#ifndef LIST_H
#define LIST_H

typedef double Item;

void showlist(Item &x);

class List
{
private:
    enum {Max = 20};
    Item items[Max];
    int index;
public:
    List(){index = 0;}
    ~List(){;}
    List(int n);
    void addlist (Item &l);
    bool isempty() const {return index == 0;}
    bool isfull() const {return index == Max;}
    void visit (void (*pf)(Item &));
};

#endif // LIST_H
