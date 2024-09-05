#ifndef AIDL_GENERATED_ANDROID_NET_BN_NETD_UNSOLICITED_EVENT_LISTENER_H_
#define AIDL_GENERATED_ANDROID_NET_BN_NETD_UNSOLICITED_EVENT_LISTENER_H_

#include <binder/IInterface.h>
#include <android/net/INetdUnsolicitedEventListener.h>
#include <chrono>
#include <functional>
#include <json/value.h>

namespace android {

namespace net {

class BnNetdUnsolicitedEventListener : public ::android::BnInterface<INetdUnsolicitedEventListener> {
public:
  explicit BnNetdUnsolicitedEventListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final override;
  std::string getInterfaceHash();
  static std::function<void(const Json::Value&)> logFunc;
};  // class BnNetdUnsolicitedEventListener

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_BN_NETD_UNSOLICITED_EVENT_LISTENER_H_
