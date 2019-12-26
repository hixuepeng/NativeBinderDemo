#include "IXpService.h"

int main() {
    printf("Xp Server Start.\n");
    sp < IServiceManager > sm = defaultServiceManager();
	sm->addService(String16("service.xpservice"), new BnXpService());

	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();
	return 0;
}