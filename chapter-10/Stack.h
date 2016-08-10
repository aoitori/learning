#ifndef STACK_H
#define STACK_H

struct customer
{
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
    double runTotal;
    void total();
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push (const Item &items);
    bool pop (Item & items);
};

#endif // STACK_H
