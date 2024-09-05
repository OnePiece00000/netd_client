#ifndef AIDL_GENERATED_ANDROID_NET_TETHER_CONFIG_PARCEL_H_
#define AIDL_GENERATED_ANDROID_NET_TETHER_CONFIG_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <vector>

namespace android {

namespace net {

class TetherConfigParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges)!=std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator<(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges)<std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator<=(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges)<=std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator==(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges)==std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator>(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges)>std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  inline bool operator>=(const TetherConfigParcel& rhs) const {
    return std::tie(usingLegacyDnsProxy, dhcpRanges)>=std::tie(rhs.usingLegacyDnsProxy, rhs.dhcpRanges);
  }
  bool usingLegacyDnsProxy = {};
  ::std::vector<::std::string> dhcpRanges;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class TetherConfigParcel

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_TETHER_CONFIG_PARCEL_H_
