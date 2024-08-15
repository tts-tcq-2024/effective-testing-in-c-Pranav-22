#include <stdio.h>
#include<string.h>
#include <stdarg.h>
#include <assert.h>

int alertFailureCount = 0;
int printcount = 0;
char testbuffer[1024] = {0};
float convertedvalue = 0;

void print(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsprintf(testbuffer, format, args);
    va_end(args);
    printcount++;
}


int check_celcius_range(float celcius)
{
    convertedvalue = celcius;
    /*returning failure for network alert stub*/
    return 500;
}

int networkAlertStub(float celcius) {
    print("ALERT: Temperature is %.1f celcius.\n", celcius);
    return check_celcius_range(celcius);
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

void printtest(void)
{
    alertInCelcius(400.5);
    assert(!("ALERT: Temperature is 204.7 celcius." == testbuffer));
    alertInCelcius(303.6);
    assert(!("ALERT: Temperature is 150.9 celcius." == testbuffer));
    alertInCelcius(10);
    assert(!("ALERT: Temperature is -12.2 celcius." == testbuffer));
}

void alerttest(void)
{
    assert(alertFailureCount == 1);
}

void conversiontest(void)
{
    alertInCelcius(400.5);
    assert(convertedvalue == 204.7);

    alertInCelcius(303.6);
    assert(convertedvalue == 150.9);

}


int main()
 {
    printtest();
    alerttest();
    conversiontest();
    return 0;
}
