namespace SALES
{
    class Sales
    {
    private:
        static const int QUARTERS = 4;
        double sales[QUARTERS];
        double average;
        double Max;
        double Min;
    public:
        Sales(){;}
        Sales(const double ar[], int n = 4);
        void setSales ();
        void showSales () const;
    };
}
