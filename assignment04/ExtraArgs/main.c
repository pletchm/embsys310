
int func1(int arg0, int arg1, int arg2, int arg3, int arg4);
void func2();

int main()
{
    func2();
    return 0;
}

int func1(int param0, int param1, int param2, int param3, int param4)
{
    int lvar0;
    int lvar1;
    int lvar2;
    int lvar3;
    int lvar4;
    int sum;
    
    lvar0 = param0;
    lvar1 = param1;
    lvar2 = param2;
    lvar3 = param3;
    lvar4 = param4;
        
    sum = lvar0 + lvar1 + lvar2 + lvar3 + lvar4;
    
    return sum;
}

void func2()
{
    int arg0 = 5;
    int arg1 = 4;
    int arg2 = 3;
    int arg3 = 2;
    int arg4 = 1;
    int val = func1(arg0, arg1, arg2, arg3, arg4);
}
