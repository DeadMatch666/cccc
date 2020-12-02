//放置所有类的定义
#include <string>
using namespace std;
//股票类
class Stock{
    private:
        string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot(){
            total_val=shares*share_val;
        }
    public:
        Stock();//初始化
        Stock(const string &co,long n=0,double val=0.0);
        ~Stock();
        void Wrting();
        void sell(long num,double price);
        void buy(long num,double price);
        void update(double price);
        void show()const;
        const Stock & topval(const Stock & s) const;

};
//时间类
class Time{
    private:
        int hours;
        int minutes;
    public:
    Time();
    Time(int h,int m);
    ~Time();
    void AddMin(int m);
    void AddHr(int h);
    void Reset();
    Time Sum(const Time & t) const;
    void Show();
};







