#ifndef AIDL_GENERATED_ANDROID_NET_BP_NETD_UNSOLICITED_EVENT_LISTENER_H_
#define AIDL_GENERATED_ANDROID_NET_BP_NETD_UNSOLICITED_EVENT_LISTENER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/INetdUnsolicitedEventListener.h>
#include <chrono>
#include <functional>
#include <json/value.h>

namespace android {

namespace net {

class BpNetdUnsolicitedEventListener : public ::android::BpInterface<INetdUnsolicitedEventListener> {
public:
  explicit BpNetdUnsolicitedEventListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpNetdUnsolicitedEventListener() = default;
  ::android::binder::Status onInterfaceClassActivityChanged(bool isActive, int32_t timerLabel, int64_t timestampNs, int32_t uid) override;
  ::android::binder::Status onQuotaLimitReached(const ::std::string& alertName, const ::std::string& ifName) override;
  ::android::binder::Status onInterfaceDnsServerInfo(const ::std::string& ifName, int64_t lifetimeS, const ::std::vector<::std::string>& servers) override;
  ::android::binder::Status onInterfaceAddressUpdated(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) override;
  ::android::binder::Status onInterfaceAddressRemoved(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) override;
  ::android::binder::Status onInterfaceAdded(const ::std::string& ifName) override;
  ::android::binder::Status onInterfaceRemoved(const ::std::string& ifName) override;
  ::android::binder::Status onInterfaceChanged(const ::std::string& ifName, bool up) override;
  ::android::binder::Status onInterfaceLinkStateChanged(const ::std::string& ifName, bool up) override;
  ::android::binder::Status onRouteChanged(bool updated, const ::std::string& route, const ::std::string& gateway, const ::std::string& ifName) override;
  ::android::binder::Status onStrictCleartextDetected(int32_t uid, const ::std::string& hex) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
  static std::function<void(const Json::Value&)> logFunc;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpNetdUnsolicitedEventListener

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_BP_NETD_UNSOLICITED_EVENT_LISTENER_H_
