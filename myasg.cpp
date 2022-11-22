#include <iostream>
using namespace std;
class hostel
{
public:
    // constructor destructor
    hostel() {}
    ~hostel() {}
    // virtual function
    virtual void get() = 0;
    virtual float total() = 0;
};
class hostel_1 : virtual public hostel
{ // inheritance used
    int boys, girls;

public:
    // deriving constructor
    hostel_1() : hostel()
    {
        cout << "Constructor called for hostel_1\n"
             << endl;
    }
    void get()
    {
        try
        {
            cout << "Enter no. of boys and girls in the hostel: " << endl;
            cin >> boys >> girls;
            if (boys == girls)
                throw "hostel has same no.of boys and girls";
        }
        catch (...)
        {
            cout << "Exception handled and not valid\n"
                 << endl;
        }
    }
    float total()
    {
        int result = boys + girls;
        cout << "The total no. of student is: " << result << endl;
    }
};
class hostel_2 : virtual public hostel
{
    int teachers, staffs;

public:
    // deriving constructor
    hostel_2() : hostel()
    {
        cout << "Constructor called for hostel_2\n"
             << endl;
    }
    void get()
    {
        cout << "Enter no. of teachers and staff in hostel: " << endl;
        cin >> teachers >> staffs;
    }
    float total()
    {
        int result = teachers + staffs;
        cout << "The total of teachers and staffs is: " << result << endl;
        return result;
    }
    // operator overloading
    hostel_2 operator++()
    {
        hostel_2 x;
        x.teachers = ++teachers;
        x.staffs = ++staffs;
        cout << "total no. of teachers and staff after incrementing " << endl;
    }
};
class hostel_3 : virtual public hostel
{
    int rooms, office;

public:
    // deriving constructor
    hostel_3() : hostel()
    {
        cout << "Constructor called for hostel_3\n"
             << endl;
    }
    void get()
    {
        cout << "Enter no of rooms and office: " << endl;
        cin >> rooms >> office;
    }
    float total()
    {
        float result = rooms + office;
        cout << "The total no. of rooms and office is: " << result << endl;
        return result;
    }
    // template
    template <typename T>
    T increase(T rooms)
    {
        ++rooms;
        ++office;
        return rooms + office;
    }
};
class hostel_4 : virtual public hostel
{
    int adults,childrens;

public:
    // deriving constructor
    hostel_4() : hostel()
    {
        cout << "Constructor called for hostel_4\n"
             << endl;
    }
    void get()
    {
        cout << "Enter the no of adults and children: " << endl;
        cin >> adults>>childrens;
    }
    float total()
    {
        float result = adults + childrens;
        cout << "The total no. of people staying at hostel-4 is: " << result << endl;
        return result;
    }
    // operator overloading using friend
    friend void operator++(hostel_4 &x)
    {
        x.adults = x.adults + 1;
        x.childrens = x.childrens + 1;
        cout << "total no people after incrementing is: " << endl;
    }
};
int main()
{
    hostel *A1, *A2, *A3, *A4, *A5;
    hostel_1 rooms;
    hostel_2 t;
    hostel_3 c;
    hostel_4 adults;
    A1 = &rooms;
    A2 = &t;
    A3 = &c;
    A4 = &adults;
    // exception handling 
    A1->get();
    A1->total();
    A2->get();
    A2->total();
    // operator overloading 
    ++t;
    A2->total();
    A3->get();
    A3->total();
    // using template 
    cout << "The total no. of rooms and offices after increment is: " << c.increase<int>(3) << endl;
    A4->get();
    A4->total();
    // operator overloading using friend function
    ++adults;
    A4->total();
    return 0;
}