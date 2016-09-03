// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

//  Base Class Using DMA
class defDMA
{
private:
    char* label;
    int rating;
public:
    defDMA(const char* l = "null", int r = 0);
    defDMA(const defDMA &rs);
    virtual ~defDMA(){delete [] label;}
    virtual defDMA & operator=(const defDMA & rs);
    virtual void View() const = 0;
    const char* rlabel(void) const {return label;}
    const int rate(void) const {return rating;}

};

class baseDMA : public defDMA
{
private:
    char* food;
public:
    baseDMA(const char * l = "null", const char* f = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    ~baseDMA(){delete [] food;}
    baseDMA & operator=(const baseDMA & rs);
    void View() const;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public defDMA
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const defDMA & rs);
    void View() const;
};

// derived class with DMA
class hasDMA :public defDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const defDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    void View() const;
    hasDMA & operator=(const hasDMA & rs);

};

#endif
