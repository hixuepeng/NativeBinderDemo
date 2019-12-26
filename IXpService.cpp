#include <IXpService.h>

namespace android {

    IMPLEMENT_META_INTERFACE(XpService, "yfve.demo.XPService");

    BpXpService::BpXpService(const sp<IBinder>& impl) :BpInterface<IXpService>(impl)
    {
        printf("construct BpXpService \n");

    }

    void BpXpService::helloWorld() {
        printf("BpXpService::helloWorld\n");
        Parcel data, reply;
        data.writeInterfaceToken(IXpService::getInterfaceDescriptor());
        remote()->transact(HELLO_WORD, data, &reply);
        printf("get num from BnXpService: %d\n", reply.readInt32());
    }

    status_t BnXpService::onTransact(uint_t code, const Parcel& data, Parcel* reply, uint32_t flags)
    {
        printf("BnXpService onTransact \n");
        switch (code )
        {
            case HELLO_WORD:
                CHECK_INTERFACE(IXpService, data,reply);
                helloWorld();
                reply->writeInt32(12345);
                return NO_ERROR;
            default:
                break;
        }

        return NO_ERROR;
    }

    void BnXpService::helloWorld() {
        printf("BnXpService::  hello World\n");
    };

}