#include <IXpService.h>

namespace android {

    IMPLEMENT_META_INTERFACE(XpService, "yfve.demo.XPService");

    BpXpService::BpXpService(const sp<IBinder>& impl) :BpInterface<IXpService>(impl)
    {
        printf("construct BpXpService \n");

    }

    void BpXpService::helloWorld() {
        printf("----BpXpService::helloWorld ---------\n");
        Parcel data, reply;
        data.writeInterfaceToken(IXpService::getInterfaceDescriptor());
        remote()->transact(HELLO_WORD, data, &reply);
        printf("----get num from BnXpService: first num %d, ---second num %s \n", reply.readInt32(), reply.readString8().c_str());
    }

    status_t BnXpService::onTransact(uint_t code, const Parcel& data, Parcel* reply, uint32_t flags)
    {
        printf("BnXpService onTransact \n");
        String8 str("I'm a string");
        switch (code )
        {
            case HELLO_WORD:
                CHECK_INTERFACE(IXpService, data,reply);
                helloWorld();
                reply->writeInt32(1000);
                reply->writeString8(str);
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