#ifndef AIDL_GENERATED_ANDROID_NET_I_NETD_UNSOLICITED_EVENT_LISTENER_H_
#define AIDL_GENERATED_ANDROID_NET_I_NETD_UNSOLICITED_EVENT_LISTENER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace net {

class INetdUnsolicitedEventListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(NetdUnsolicitedEventListener)
  const int32_t VERSION = 4;
  const std::string HASH = "63adaa5098e4d8621e90c5a84f7cb93505c79311";
  virtual ::android::binder::Status onInterfaceClassActivityChanged(bool isActive, int32_t timerLabel, int64_t timestampNs, int32_t uid) = 0;
  virtual ::android::binder::Status onQuotaLimitReached(const ::std::string& alertName, const ::std::string& ifName) = 0;
  virtual ::android::binder::Status onInterfaceDnsServerInfo(const ::std::string& ifName, int64_t lifetimeS, const ::std::vector<::std::string>& servers) = 0;
  virtual ::android::binder::Status onInterfaceAddressUpdated(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) = 0;
  virtual ::android::binder::Status onInterfaceAddressRemoved(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) = 0;
  virtual ::android::binder::Status onInterfaceAdded(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status onInterfaceRemoved(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status onInterfaceChanged(const ::std::string& ifName, bool up) = 0;
  virtual ::android::binder::Status onInterfaceLinkStateChanged(const ::std::string& ifName, bool up) = 0;
  virtual ::android::binder::Status onRouteChanged(bool updated, const ::std::string& route, const ::std::string& gateway, const ::std::string& ifName) = 0;
  virtual ::android::binder::Status onStrictCleartextDetected(int32_t uid, const ::std::string& hex) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class INetdUnsolicitedEventListener

class INetdUnsolicitedEventListenerDefault : public INetdUnsolicitedEventListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onInterfaceClassActivityChanged(bool, int32_t, int64_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onQuotaLimitReached(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterfaceDnsServerInfo(const ::std::string&, int64_t, const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterfaceAddressUpdated(const ::std::string&, const ::std::string&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterfaceAddressRemoved(const ::std::string&, const ::std::string&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterfaceAdded(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterfaceRemoved(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterfaceChanged(const ::std::string&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterfaceLinkStateChanged(const ::std::string&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onRouteChanged(bool, const ::std::string&, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onStrictCleartextDetected(int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class INetdUnsolicitedEventListenerDefault

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_I_NETD_UNSOLICITED_EVENT_LISTENER_H_
