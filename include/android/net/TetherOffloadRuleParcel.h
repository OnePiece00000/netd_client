#ifndef AIDL_GENERATED_ANDROID_NET_TETHER_OFFLOAD_RULE_PARCEL_H_
#define AIDL_GENERATED_ANDROID_NET_TETHER_OFFLOAD_RULE_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace net {

class TetherOffloadRuleParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu)!=std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator<(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu)<std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator<=(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu)<=std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator==(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu)==std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator>(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu)>std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  inline bool operator>=(const TetherOffloadRuleParcel& rhs) const {
    return std::tie(inputInterfaceIndex, outputInterfaceIndex, destination, prefixLength, srcL2Address, dstL2Address, pmtu)>=std::tie(rhs.inputInterfaceIndex, rhs.outputInterfaceIndex, rhs.destination, rhs.prefixLength, rhs.srcL2Address, rhs.dstL2Address, rhs.pmtu);
  }
  int32_t inputInterfaceIndex = {};
  int32_t outputInterfaceIndex = {};
  ::std::vector<uint8_t> destination;
  int32_t prefixLength = {};
  ::std::vector<uint8_t> srcL2Address;
  ::std::vector<uint8_t> dstL2Address;
  int32_t pmtu = int32_t(1500);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class TetherOffloadRuleParcel

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_TETHER_OFFLOAD_RULE_PARCEL_H_
