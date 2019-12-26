#ifndef XP_SERVICE_H
#define XP_SERVICE_H

#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

using namespace android;
namespace android {

    class IXpService : public IInterface
    {
    public:
        DECLARE_META_INTERFACE(XpService);
        virtual void helloWorld() = 0;
    };

    enum
    {
        HELLO_WORD,
    };

    class BpXpService : public BpInterface<IXpService>
    {
    public:
        BpXpService(const sp<IBinder>& impl);
        virtual void helloWorld();
    };

    class BnXpService : public BnInterface<IXpService>
    {
    public:
        virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
        virtual void helloWorld();

    };
}
#endif