#define _CRT_SECURE_NO_WARNINGS

#define useio
//#define usetestio

#ifdef useio
#include "IO.hpp"

#elif defined(usetestio)
#include <vector>
#include "TestOtherIO.hpp"
typedef long long ll;
using namespace std;

#endif

#include <ctime>

bool multi = 0;
#ifdef useio
IO io;

#endif // useio

const int N = 1e4 + 5;
vector<int> v;
vector<double> vd;
ll a[N];
double db[N];
char s[N];
int suct;

//#define useio
#define usetestio

void test1()
{
    int len = 5e7, a;
#ifdef useio
    for (int i = 1; i <= len; ++i)
        suct += io(a);

#elif defined(usetestio)
    for (int i = 1; i <= len; ++i)
        suct += 1;

#else
    for (int i = 1; i <= len; ++i)
        scanf("%d", &a);

#endif
}

void test2()
{
    int len = 1e7;
    double a;
#ifdef useio
    for (int i = 1; i <= len; ++i)
        suct += io(a);

#else
    for (int i = 1; i <= len; ++i)
        suct += scanf("%lf", &a);
#endif
}

void test3()
{
    int len = 1e4, sz = 1e3;
#ifdef useio
    for (int i = 1; i <= len; ++i) {
        suct += io(s);
    }

#else
    for (int i = 1; i <= len; ++i) {
        suct += scanf("%s", s);
    }
#endif
}

void test4()
{
    int len = 1e4, sz = 1e3;
#ifdef useio
    for (int i = 1; i <= len; ++i)
        suct += io(IO::make(v, sz));

#else
    for (int i = 1; i <= len; ++i) {
        v.resize(sz);
        for (auto& i : v)
            suct += scanf("%d", &i);
    }
#endif
}

void test5()
{
    int len = 1e4, sz = 1e3;
#ifdef useio
    for (int i = 1; i <= len; ++i)
        suct += io(IO::make(vd, sz));

#else
    for (int i = 1; i <= len; ++i) {
        vd.resize(sz);
        for (auto& i : vd)
            suct += scanf("%lf", &i);
    }
#endif
}

/*void test5()
{
    int len = 1e4, op = 0;
#ifdef useio
    for (int i = 1; i <= len; ++i) {
        io(op);
        if (op == 1) {
            io(a[0]);
        } else if (op == 2) {
            io(db[0]);
        } else if (op == 3) {
            io(s);
        } else if (op == 4) {
            io(len);
            io(IO::make(db, 0, len));
        } else if (op == 5) {
            io(len);
            io(IO::make(a, 0, len));
        } else if (op == 6) {
            io(len);
            io(IO::make(v, len));
        }
    }
#else
    for (int i = 1; i <= len; ++i) {
        int op = 1;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &a[0]);
        } else if (op == 2) {
            scanf("%lf", &db[0]);
        } else if (op == 3) {
            scanf("%s", s);
        } else if (op == 4) {
            int len;
            scanf("%d", &len);
            for (int i = 0; i < len; ++i)
                scanf("%lf", &db[i]);
        } else if (op == 5) {
            int len;
            scanf("%d", &len);
            for (int i = 0; i < len; ++i)
                scanf("%d", &a[i]);
        } else {
            int len;
            scanf("%d", &len);
            v.resize(len);
            for (auto& i : v)
                scanf("%lld", &i);
        }
    }
#endif
}*/

void test() 
{
    freopen("D:\\aa.txt", "r", stdin);
    char s[10];
    io(s);
    return;
}

void solve(int testcase)
{
    clock_t s = clock();
    if (testcase == 1)
        test1();
    else if (testcase == 2)
        test2();
    else if (testcase == 3)
        test3();
    else if (testcase == 4)
        test4();
    else if (testcase == 5)
        test5();
    else
        test();
    printf("time: %d ms\n", clock() - s);
    printf("run function times: %d\n", suct);
#ifdef useio
    printf("use fast io\n");
#else
    printf("use scanf\n");
#endif //  useio
}

const char* path[]  = {
    "",
    "D:\\code\\vs\\C++_code\\FastIO\\data\\in1.txt",
    "D:\\code\\vs\\C++_code\\FastIO\\data\\in2.txt",
    "D:\\code\\vs\\C++_code\\FastIO\\data\\in3.txt",
    "D:\\code\\vs\\C++_code\\FastIO\\data\\in4.txt",
    "D:\\code\\vs\\C++_code\\FastIO\\data\\in5.txt"
};

int main(int argc, char** argv)
{
    /*if (argc != 2)
        return printf("error argc: %d", argc);
    int tsc = atoi(argv[1]);*/
    int tsc = 6;
    if (tsc < 6)
        freopen(path[tsc], "r", stdin);

    int t;
    if (multi)
        io(t);
    else
        t = 1;
    while (t--)
        solve(tsc);
    return 0;
}
