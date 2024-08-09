#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int check_celcius_range(float celcius)
{
    if(celcius >= 0.0)
        return 200;
    else
        return 500;
}

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return check_celcius_range(celcius);
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(10);
    assert(alertFailureCount == 1);
    return 0;
}
