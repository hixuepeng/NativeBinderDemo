#include "IXpService.h"

int main() {
    sp < IServiceManager > sm = defaultServiceManager();
    sp < IBinder > binder = sm->getService(String16("service.xpservice"));
    if (binder != NULL)
    {
        printf("get binder\n");
    }
    else
    {
        printf("failed get binder\n");
    }

    sp<IXpService> cs = interface_cast < IXpService > (binder);
    cs->helloWorld();
    return 0;
}