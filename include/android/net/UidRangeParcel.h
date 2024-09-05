#ifndef AIDL_GENERATED_ANDROID_NET_UID_RANGE_PARCEL_H_
#define AIDL_GENERATED_ANDROID_NET_UID_RANGE_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace net {

class UidRangeParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const UidRangeParcel& rhs) const {
    return std::tie(start, stop)!=std::tie(rhs.start, rhs.stop);
  }
  inline bool operator<(const UidRangeParcel& rhs) const {
    return std::tie(start, stop)<std::tie(rhs.start, rhs.stop);
  }
  inline bool operator<=(const UidRangeParcel& rhs) const {
    return std::tie(start, stop)<=std::tie(rhs.start, rhs.stop);
  }
  inline bool operator==(const UidRangeParcel& rhs) const {
    return std::tie(start, stop)==std::tie(rhs.start, rhs.stop);
  }
  inline bool operator>(const UidRangeParcel& rhs) const {
    return std::tie(start, stop)>std::tie(rhs.start, rhs.stop);
  }
  inline bool operator>=(const UidRangeParcel& rhs) const {
    return std::tie(start, stop)>=std::tie(rhs.start, rhs.stop);
  }
  int32_t start = {};
  int32_t stop = {};
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class UidRangeParcel

}  // namespace net

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_NET_UID_RANGE_PARCEL_H_
