#include <android/net/INetdUnsolicitedEventListener.h>
#include <android/net/BpNetdUnsolicitedEventListener.h>

namespace android {

namespace net {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(NetdUnsolicitedEventListener, "android.net.INetdUnsolicitedEventListener")

}  // namespace net

}  // namespace android
#include <android/net/BpNetdUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>
#include <chrono>
#include <functional>
#include <json/value.h>

namespace android {

namespace net {

BpNetdUnsolicitedEventListener::BpNetdUnsolicitedEventListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<INetdUnsolicitedEventListener>(_aidl_impl){
}

std::function<void(const Json::Value&)> BpNetdUnsolicitedEventListener::logFunc;

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceClassActivityChanged(bool isActive, int32_t timerLabel, int64_t timestampNs, int32_t uid) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "isActive";
      _log_arg_element["value"] = Json::Value(isActive? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "timerLabel";
      _log_arg_element["value"] = Json::Value(timerLabel);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "timestampNs";
      _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(timestampNs));
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(isActive);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(timerLabel);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(timestampNs);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onInterfaceClassActivityChanged */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceClassActivityChanged(isActive, timerLabel, timestampNs, uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceClassActivityChanged");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onQuotaLimitReached(const ::std::string& alertName, const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "alertName";
      _log_arg_element["value"] = Json::Value(alertName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(alertName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* onQuotaLimitReached */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onQuotaLimitReached(alertName, ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onQuotaLimitReached");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceDnsServerInfo(const ::std::string& ifName, int64_t lifetimeS, const ::std::vector<::std::string>& servers) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "lifetimeS";
      _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(lifetimeS));
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "servers";
      _log_arg_element["value"] = Json::Value(Json::arrayValue);
      for (const auto& v: servers) _log_arg_element["value"].append(Json::Value(v));
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(lifetimeS);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(servers);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 2 /* onInterfaceDnsServerInfo */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceDnsServerInfo(ifName, lifetimeS, servers);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceDnsServerInfo");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceAddressUpdated(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "addr";
      _log_arg_element["value"] = Json::Value(addr);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "flags";
      _log_arg_element["value"] = Json::Value(flags);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "scope";
      _log_arg_element["value"] = Json::Value(scope);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addr);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(flags);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(scope);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 3 /* onInterfaceAddressUpdated */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceAddressUpdated(addr, ifName, flags, scope);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceAddressUpdated");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceAddressRemoved(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "addr";
      _log_arg_element["value"] = Json::Value(addr);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "flags";
      _log_arg_element["value"] = Json::Value(flags);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "scope";
      _log_arg_element["value"] = Json::Value(scope);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addr);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(flags);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(scope);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 4 /* onInterfaceAddressRemoved */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceAddressRemoved(addr, ifName, flags, scope);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceAddressRemoved");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceAdded(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 5 /* onInterfaceAdded */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceAdded(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceAdded");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceRemoved(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 6 /* onInterfaceRemoved */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceRemoved(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceRemoved");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceChanged(const ::std::string& ifName, bool up) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "up";
      _log_arg_element["value"] = Json::Value(up? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(up);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 7 /* onInterfaceChanged */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceChanged(ifName, up);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceChanged");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceLinkStateChanged(const ::std::string& ifName, bool up) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "up";
      _log_arg_element["value"] = Json::Value(up? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(up);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 8 /* onInterfaceLinkStateChanged */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceLinkStateChanged(ifName, up);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onInterfaceLinkStateChanged");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onRouteChanged(bool updated, const ::std::string& route, const ::std::string& gateway, const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "updated";
      _log_arg_element["value"] = Json::Value(updated? "true" : "false");
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "route";
      _log_arg_element["value"] = Json::Value(route);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "gateway";
      _log_arg_element["value"] = Json::Value(gateway);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "ifName";
      _log_arg_element["value"] = Json::Value(ifName);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(updated);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(route);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(gateway);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 9 /* onRouteChanged */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onRouteChanged(updated, route, gateway, ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onRouteChanged");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onStrictCleartextDetected(int32_t uid, const ::std::string& hex) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  Json::Value _log_input_args(Json::arrayValue);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "uid";
      _log_arg_element["value"] = Json::Value(uid);
      _log_input_args.append(_log_arg_element);
      }
    {
      Json::Value _log_arg_element(Json::objectValue);
      _log_arg_element["name"] = "hex";
      _log_arg_element["value"] = Json::Value(hex);
      _log_input_args.append(_log_arg_element);
      }
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(hex);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 10 /* onStrictCleartextDetected */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onStrictCleartextDetected(uid, hex);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    Json::Value _log_transaction(Json::objectValue);
    _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
    _log_transaction["method_name"] = Json::Value("onStrictCleartextDetected");
    _log_transaction["proxy_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
    _log_transaction["input_args"] = _log_input_args;
    Json::Value _log_output_args(Json::arrayValue);
    Json::Value _log_status(Json::objectValue);
    _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
    _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
    _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
    _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
    _log_transaction["binder_status"] = _log_status;
    _log_transaction["output_args"] = _log_output_args;
    BpNetdUnsolicitedEventListener::logFunc(_log_transaction);
  }
  return _aidl_status;
}

int32_t BpNetdUnsolicitedEventListener::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 16777214 /* getInterfaceVersion */, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        cached_version_ = reply.readInt32();
      }
    }
  }
  return cached_version_;
}

std::string BpNetdUnsolicitedEventListener::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 16777213 /* getInterfaceHash */, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        reply.readUtf8FromUtf16(&cached_hash_);
      }
    }
  }
  return cached_hash_;
}

}  // namespace net

}  // namespace android
#include <android/net/BnNetdUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>
#include <chrono>
#include <functional>
#include <json/value.h>

namespace android {

namespace net {

BnNetdUnsolicitedEventListener::BnNetdUnsolicitedEventListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnNetdUnsolicitedEventListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onInterfaceClassActivityChanged */:
  {
    bool in_isActive;
    int32_t in_timerLabel;
    int64_t in_timestampNs;
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_isActive);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_timerLabel);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_timestampNs);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_isActive";
        _log_arg_element["value"] = Json::Value(in_isActive? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_timerLabel";
        _log_arg_element["value"] = Json::Value(in_timerLabel);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_timestampNs";
        _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(in_timestampNs));
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceClassActivityChanged(in_isActive, in_timerLabel, in_timestampNs, in_uid));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceClassActivityChanged");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* onQuotaLimitReached */:
  {
    ::std::string in_alertName;
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_alertName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_alertName";
        _log_arg_element["value"] = Json::Value(in_alertName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onQuotaLimitReached(in_alertName, in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onQuotaLimitReached");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 2 /* onInterfaceDnsServerInfo */:
  {
    ::std::string in_ifName;
    int64_t in_lifetimeS;
    ::std::vector<::std::string> in_servers;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_lifetimeS);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_servers);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_lifetimeS";
        _log_arg_element["value"] = Json::Value(static_cast<Json::Int64>(in_lifetimeS));
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_servers";
        _log_arg_element["value"] = Json::Value(Json::arrayValue);
        for (const auto& v: in_servers) _log_arg_element["value"].append(Json::Value(v));
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceDnsServerInfo(in_ifName, in_lifetimeS, in_servers));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceDnsServerInfo");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 3 /* onInterfaceAddressUpdated */:
  {
    ::std::string in_addr;
    ::std::string in_ifName;
    int32_t in_flags;
    int32_t in_scope;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addr);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_flags);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_scope);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_addr";
        _log_arg_element["value"] = Json::Value(in_addr);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_flags";
        _log_arg_element["value"] = Json::Value(in_flags);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_scope";
        _log_arg_element["value"] = Json::Value(in_scope);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceAddressUpdated(in_addr, in_ifName, in_flags, in_scope));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceAddressUpdated");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 4 /* onInterfaceAddressRemoved */:
  {
    ::std::string in_addr;
    ::std::string in_ifName;
    int32_t in_flags;
    int32_t in_scope;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addr);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_flags);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_scope);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_addr";
        _log_arg_element["value"] = Json::Value(in_addr);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_flags";
        _log_arg_element["value"] = Json::Value(in_flags);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_scope";
        _log_arg_element["value"] = Json::Value(in_scope);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceAddressRemoved(in_addr, in_ifName, in_flags, in_scope));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceAddressRemoved");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 5 /* onInterfaceAdded */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceAdded(in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceAdded");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 6 /* onInterfaceRemoved */:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceRemoved(in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceRemoved");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 7 /* onInterfaceChanged */:
  {
    ::std::string in_ifName;
    bool in_up;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_up);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_up";
        _log_arg_element["value"] = Json::Value(in_up? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceChanged(in_ifName, in_up));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceChanged");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 8 /* onInterfaceLinkStateChanged */:
  {
    ::std::string in_ifName;
    bool in_up;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_up);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_up";
        _log_arg_element["value"] = Json::Value(in_up? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceLinkStateChanged(in_ifName, in_up));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onInterfaceLinkStateChanged");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 9 /* onRouteChanged */:
  {
    bool in_updated;
    ::std::string in_route;
    ::std::string in_gateway;
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_updated);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_route);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_gateway);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_updated";
        _log_arg_element["value"] = Json::Value(in_updated? "true" : "false");
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_route";
        _log_arg_element["value"] = Json::Value(in_route);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_gateway";
        _log_arg_element["value"] = Json::Value(in_gateway);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_ifName";
        _log_arg_element["value"] = Json::Value(in_ifName);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onRouteChanged(in_updated, in_route, in_gateway, in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onRouteChanged");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 10 /* onStrictCleartextDetected */:
  {
    int32_t in_uid;
    ::std::string in_hex;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_hex);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    Json::Value _log_input_args(Json::arrayValue);
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_uid";
        _log_arg_element["value"] = Json::Value(in_uid);
        _log_input_args.append(_log_arg_element);
        }
      {
        Json::Value _log_arg_element(Json::objectValue);
        _log_arg_element["name"] = "in_hex";
        _log_arg_element["value"] = Json::Value(in_hex);
        _log_input_args.append(_log_arg_element);
        }
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onStrictCleartextDetected(in_uid, in_hex));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      Json::Value _log_transaction(Json::objectValue);
      _log_transaction["duration_ms"] = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _log_transaction["interface_name"] = Json::Value("android.net.INetdUnsolicitedEventListener");
      _log_transaction["method_name"] = Json::Value("onStrictCleartextDetected");
      _log_transaction["stub_address"] = Json::Value((std::ostringstream() << static_cast<const void*>(this)).str());
      _log_transaction["input_args"] = _log_input_args;
      Json::Value _log_output_args(Json::arrayValue);
      Json::Value _log_status(Json::objectValue);
      _log_status["exception_code"] = Json::Value(_aidl_status.exceptionCode());
      _log_status["exception_message"] = Json::Value(_aidl_status.exceptionMessage());
      _log_status["transaction_error"] = Json::Value(_aidl_status.transactionError());
      _log_status["service_specific_error_code"] = Json::Value(_aidl_status.serviceSpecificErrorCode());
      _log_transaction["binder_status"] = _log_status;
      _log_transaction["output_args"] = _log_output_args;
      BnNetdUnsolicitedEventListener::logFunc(_log_transaction);
    }
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214 /* getInterfaceVersion */:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(INetdUnsolicitedEventListener::VERSION);
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213 /* getInterfaceHash */:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(INetdUnsolicitedEventListener::HASH);
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

int32_t BnNetdUnsolicitedEventListener::getInterfaceVersion() {
  return INetdUnsolicitedEventListener::VERSION;
}

std::string BnNetdUnsolicitedEventListener::getInterfaceHash() {
  return INetdUnsolicitedEventListener::HASH;
}

std::function<void(const Json::Value&)> BnNetdUnsolicitedEventListener::logFunc;

}  // namespace net

}  // namespace android
