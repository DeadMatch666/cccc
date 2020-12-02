#include <iostream>//in or out
#include <cmath>//about math
#include <stdlib.h>
#include <string>//string类 字符串
#include <time.h>//random num
#include <fstream>//文件输入输出
#include <cstdlib>
#include "classes.h"
using namespace std;
//函数在main之前不用声明 在之后要声明才能使用
//1.分割线
int Printstar()
{
    cout<<"\n*************\n";
    return 0;
}
//2.输入测试
int getiInOut()
{
    Printstar();
    int money;
    cout<<"How many pens do you have？\n";
    cin>>money;
    cout<<"here are 3 more"<<endl;
    money=money+3;
    cout<<"now i have "<<money<<" pens.";
    Printstar();
    return 0;

}
//3.猜数
int GuessNum()
{
    int i,n;
    srand((unsigned)time(NULL));
    i=rand()%100 + 1;
    do{
        cout<<"输入一个数："<<endl;
        cin>>n;
        if(n==i){
            cout<<"you are right";
            break;
        }
        if(n<i){
            cout<<"the num is smaller"<<endl;
            continue;
        }
        if(n>i){
            cout<<"the num is bigger"<<endl;
            continue;
        }
    }while(n!=i);
    return 0;
}
//4.string类的操作
int STRING(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    string s3;
    s3=s1+s2;
    cout<<s3<<" "<<s3.size()<<endl;
    Printstar();
    return 0;
}
//5.结构体和结构体数组
int TEXTStruct(){
    int i;
    struct PeopleInLib{
        string name;
        int old;
        float heigh;
    };
    PeopleInLib wjw={"王景文",22,183.6};
    PeopleInLib others[4];
    others[0]=wjw;
    for(i=1;i<=3;i++){
        cin>>others[i].name;
        cin>>others[i].old;
        cin>>others[i].heigh;
    }
    for(i=0;i<=3;i++){
        cout<<"my name is "<<others[i].name<<" and i am "
    <<others[i].old<<" years old "<<"and i am "
    <<others[i].heigh<<endl;
    }
    return 0;
}
//6.指针and动态数组
int PDynamicShuzu(){
    int i,size;
    cin>>size;
    int * pt;
    int ph[5]={0,0,0,0,0};
    pt=new int[size];
    for(i=0;i<size;i++){
        cin>>pt[i];
    }
    for(i=0;i<size;i++){
        cout<<"pt["<<i<<"]:"<<pt[i]<<endl;
    }
    int sum1=0,sum2=0;
    for(i=0;i<size;i++){
        cout<<pt+i<<" "<<endl;
        cout<<*(pt+i)<<" "<<endl;
        sum1=sum1+(sizeof(*(pt+i)));
        sum2=sum2+(sizeof(pt+i));
    }
    cout<<"*pt sum:"<<sum1<<endl;
    cout<<"pt sum:"<<sum2<<endl;  
    delete [] pt;
    return 0;
}
//7.指针和动态结构
int PDynamicStruct(){
    struct goods
    {
        string name;
        float price;
    };
    goods *pt=new goods;
    cout<<"input the name of goods:";
    cin>>(pt->name);
    cout<<"\ninput the price of goods:";
    cin>>(*pt).price;
    cout<<"***********"<<endl;
    cout<<(*pt).name<<(*pt).price<<endl;
    cout<<pt->name<<pt->price<<endl;
    delete pt;//new完用完记得删；
    return 0;
}
//8.for循环输出任意数阶乘
int LPJC(){
    cout<<"input a num to make a jiec:"<<endl;
    int size;
    cin>>size;
    long  * pt=new long[size];
    pt[0]=pt[1]=1;
    for(int i=2;i<=size;i++){
        pt[i]=i*pt[i-1];
    }
    for(int i=0;i<=size;i++){
        cout<<i<<"!="<<pt[i]<<endl;
    }
    delete [] pt;
    return 0;
}
//9. 判断空格和字符数
int IFSentence(){
    char cn;
    int space=0,total=0;
    int zimu=0;
    cin.get(cn);
    while(cn!='.')
    {
        if(cn==' ')
        { 
           space++;
        } 
        else
        {
            zimu++;
        }
    total++;
    cin.get(cn);
    }
    cout<<"num.space:"<<space<<endl;
    cout<<"num.zimu:"<<zimu<<endl;
    cout<<"num.total:"<<total<<endl;
    return 0;
}
//10.成绩判定
int JudgeGrade(){
    int size;
    cin>>size;
    int *grade=new int[size];
    for(int i=0;i<size;i++){
        cout<<"input no."<<i+1
        <<"de grade:"<<endl;
        cin>>grade[i];
    }
    for(int i=0;i<size;i++){
        if(grade[i]>=90){
            cout<<"no."<<i+1<<" de class is"
            <<"A"<<endl;
        }
        else if(grade[i]>=80 and grade[i]<90){
            cout<<"no."<<i+1<<" de class is"
            <<"B"<<endl;
        }
        else{
            cout<<"no."<<i+1<<" de class is"
            <<"C"<<endl;
        }
    }
    delete [] grade;
    return 0;
}
//11.写入文件 ofstream 
int FILEWriting(){
    char sh[50];
    int num;
    float Pointnum;
    ofstream woyaoopao;
    woyaoopao.open("file.txt");
    cout<<"input a string:\n";
    cin.getline(sh,50);
    cout<<"input a int num:\n";
    cin>>num;
    cout<<"input a float num:\n";
    cin>>Pointnum;
    Printstar();
    woyaoopao<<"string:"<<sh<<endl;
    woyaoopao<<"int num:"<<num<<endl;
    woyaoopao<<"PointNUm:"<<Pointnum<<endl;
    woyaoopao.close();
    return 0;
}
//12.文件读取
int FileRead(){
    char filename[50];
    cout<<"please input file name."<<endl;
    cin.getline(filename,50);
    char sh[50];
    ifstream fileread;
    fileread.open(filename);
    if(!fileread.is_open()){
        cout<<"can not find"<<endl;
        exit(EXIT_FAILURE);
    }
    fileread.getline(sh,50);
    while(fileread.good()){
        cout<<sh<<endl;
        fileread.getline(sh,50);
    }
    fileread.close();
    return 0;
}
//13.指针常量和常量指针
void PointConst(){
    int wjw=79;
    const int *WJW=&wjw;
    int yn=69;
    cout<<"now wjw="<<wjw<<" &wjw="<<&wjw<<" WJW=:"
    <<WJW<<" *WJW="<<*WJW<<endl;
    wjw=yn;
    cout<<"now wjw="<<wjw<<" &wjw="<<&wjw<<" WJW=:"
    <<WJW<<" *WJW="<<*WJW<<endl; 
}
//14.类公共接口的具体描述***定义在头文件 用""引用
//初始化
Stock::Stock(){
    company="no name";
    share_val=0;
    shares=0;
    total_val=0;
}
//第一次购买 检查买后数量与检测
Stock::Stock(const string &co,long n,double val){
    company=co;
    if(n<0){
        cout<<"你有这么多吗?"<<endl;
        shares=0;
    }
    else{
        shares=n;
    }
    share_val=val;
    set_tot();
}
Stock::~Stock(){}
void Stock::buy(long num,double pr){
    if(num<0){
        cout<<"u buy a jb"<<endl;
    }
    else{
        shares=shares+num;
        share_val=pr;
        set_tot();
    }
}
void Stock::Wrting(){
    cout<<"company name"<<endl;
    cin>>company;
    cout<<"shares:"<<endl;
    cin>>shares;
    cout<<"val:"<<endl;
    cin>>share_val;
    set_tot();
}
void Stock::sell(long num,double price){
    if(num<0){
        cout<<"u sell a jb"<<endl;
    }
    else if(num>shares){
        cout<<"not enough"<<endl;
    }
    else{
        shares-=num;
        share_val=price;
        set_tot();
    }
}
void Stock::update(double price){
    share_val=price;
    set_tot();
}
void Stock::show() const{
    Printstar();
    cout<<"company: "<<company<<endl;
    cout<<"shares: "<<shares<<endl;
    cout<<"share price: "<<share_val<<endl;
    cout<<"total price: "<<total_val;
    Printstar();
}
const Stock & Stock::topval(const Stock & s) const{
    if(s.total_val>total_val){
        return s;
    }
    else{
        return *this;
    }
}
//using Stock class
int UsingStockClass(){
    Stock love[6];
    love[0]=Stock("yangnan",520,13.14);
    love[1]=Stock("lufeng",250,26.13);
    love[2]=Stock("baozi",741,8.41);
    love[3]=Stock("mama",521,13.13);
    love[4].Wrting();
    love[5]=Stock();
    for(int i=0;i<6;i++){
        love[i].show();
    }
    Stock top=love[5];
    for(int i =0;i<6;i++){
        top=top.topval(love[i]);
    }
    top.show();
    return 0;
}
//15.重载运算符
Time::Time(){
    hours=minutes=0;
}
Time::Time(int h,int m){
    hours=h;
    minutes=m;
}
Time::~Time(){}
void Time::AddMin(int m){
    minutes+=m;
    hours+=minutes/60;
    minutes=minutes%60;
}
void Time::AddHr(int h){
    hours+=h;
    if(hours>=24){
            hours-=24;
    }
}
void Time::Reset(){
    hours=0;
    minutes=0;
}
Time Time::Sum(const Time & t)const{
    Time sum;
    sum.minutes=t.minutes+minutes;
    sum.hours=t.hours+hours;
    if(sum.minutes>=60){
        sum.minutes=sum.minutes-60;
        sum.hours++;
    }
    if(sum.hours>24){
        sum.hours-=24;
    }
    return sum;
}
void Time::Show(){
    cout<<hours<<" h: "<<minutes<<" m"<<endl;
}
//using Time class
int UsingTimeClass(){
    Time wjw=Time(13,30);
    Time yangnan=Time(21,40);
    Time luf=Time(23,59);
    wjw.Show();
    yangnan.Show();
    luf.Show();
    wjw.AddHr(1);
    yangnan.AddMin(50);
    luf.AddHr(5);
    Printstar();
    wjw.Show();
    yangnan.Show();
    luf.Show();
    Printstar();
    luf=wjw.Sum(yangnan);
    luf.Show();
    return 0;
}
//主函数
int main()
{
    //Printstar();
    //GuessNum();
    //STRING();
    //TEXTStruct();
    //PDynamicShu();
    //PDynamicStruct();
    //LPJC();
    //IFSentence();zu
    //JudgeGrade();
    //FILEWriting();
    //FileRead();
    //PointConst();
    //UsingClass();

    UsingTimeClass();

    return 0;
}