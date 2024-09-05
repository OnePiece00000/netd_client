#ifndef AIDL_GENERATED_ANDROID_NET_BN_NETD_H_
#define AIDL_GENERATED_ANDROID_NET_BN_NETD_H_

#include <binder/IInterface.h>
#include <android/net/INetd.h>
#include <chrono>
#include <functional>
#include <json/value.h>

namespace android {

namespace net {

class BnNetd : public ::android::BnInterface<INetd> {
public:
  explicit BnNetd();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final override;
  std::string getInterfaceHash();
  static std::function<void(const Json::Value&)> logFunc;
};  // class BnNetd

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_BN_NETD_H_
