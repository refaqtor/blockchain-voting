// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: node.proto
// Original file comments:
// protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` node.proto
// protoc --cpp_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` node.proto
//
#ifndef GRPC_node_2eproto__INCLUDED
#define GRPC_node_2eproto__INCLUDED

#include "node.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace onevote {

class Miner GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status BroadcastBlock(::grpc::ClientContext* context, const ::onevote::BlockMsg& request, ::onevote::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>> AsyncBroadcastBlock(::grpc::ClientContext* context, const ::onevote::BlockMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>>(AsyncBroadcastBlockRaw(context, request, cq));
    }
    virtual ::grpc::Status BroadcastTransaction(::grpc::ClientContext* context, const ::onevote::TransactionMsg& request, ::onevote::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>> AsyncBroadcastTransaction(::grpc::ClientContext* context, const ::onevote::TransactionMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>>(AsyncBroadcastTransactionRaw(context, request, cq));
    }
    virtual ::grpc::Status GetAddr(::grpc::ClientContext* context, const ::onevote::AddrRequest& request, ::onevote::AddrResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::AddrResponse>> AsyncGetAddr(::grpc::ClientContext* context, const ::onevote::AddrRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::AddrResponse>>(AsyncGetAddrRaw(context, request, cq));
    }
    virtual ::grpc::Status GetTransaction(::grpc::ClientContext* context, const ::onevote::TransactionRequest& request, ::onevote::TransactionMsg* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::TransactionMsg>> AsyncGetTransaction(::grpc::ClientContext* context, const ::onevote::TransactionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::TransactionMsg>>(AsyncGetTransactionRaw(context, request, cq));
    }
    virtual ::grpc::Status GetBlock(::grpc::ClientContext* context, const ::onevote::BlockRequest& request, ::onevote::BlockMsg* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::BlockMsg>> AsyncGetBlock(::grpc::ClientContext* context, const ::onevote::BlockRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::BlockMsg>>(AsyncGetBlockRaw(context, request, cq));
    }
    virtual ::grpc::Status GetHeartbeat(::grpc::ClientContext* context, const ::onevote::Empty& request, ::onevote::Empty* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>> AsyncGetHeartbeat(::grpc::ClientContext* context, const ::onevote::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>>(AsyncGetHeartbeatRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>* AsyncBroadcastBlockRaw(::grpc::ClientContext* context, const ::onevote::BlockMsg& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>* AsyncBroadcastTransactionRaw(::grpc::ClientContext* context, const ::onevote::TransactionMsg& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onevote::AddrResponse>* AsyncGetAddrRaw(::grpc::ClientContext* context, const ::onevote::AddrRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onevote::TransactionMsg>* AsyncGetTransactionRaw(::grpc::ClientContext* context, const ::onevote::TransactionRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onevote::BlockMsg>* AsyncGetBlockRaw(::grpc::ClientContext* context, const ::onevote::BlockRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::onevote::Empty>* AsyncGetHeartbeatRaw(::grpc::ClientContext* context, const ::onevote::Empty& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status BroadcastBlock(::grpc::ClientContext* context, const ::onevote::BlockMsg& request, ::onevote::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::Empty>> AsyncBroadcastBlock(::grpc::ClientContext* context, const ::onevote::BlockMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::Empty>>(AsyncBroadcastBlockRaw(context, request, cq));
    }
    ::grpc::Status BroadcastTransaction(::grpc::ClientContext* context, const ::onevote::TransactionMsg& request, ::onevote::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::Empty>> AsyncBroadcastTransaction(::grpc::ClientContext* context, const ::onevote::TransactionMsg& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::Empty>>(AsyncBroadcastTransactionRaw(context, request, cq));
    }
    ::grpc::Status GetAddr(::grpc::ClientContext* context, const ::onevote::AddrRequest& request, ::onevote::AddrResponse* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::AddrResponse>> AsyncGetAddr(::grpc::ClientContext* context, const ::onevote::AddrRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::AddrResponse>>(AsyncGetAddrRaw(context, request, cq));
    }
    ::grpc::Status GetTransaction(::grpc::ClientContext* context, const ::onevote::TransactionRequest& request, ::onevote::TransactionMsg* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::TransactionMsg>> AsyncGetTransaction(::grpc::ClientContext* context, const ::onevote::TransactionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::TransactionMsg>>(AsyncGetTransactionRaw(context, request, cq));
    }
    ::grpc::Status GetBlock(::grpc::ClientContext* context, const ::onevote::BlockRequest& request, ::onevote::BlockMsg* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::BlockMsg>> AsyncGetBlock(::grpc::ClientContext* context, const ::onevote::BlockRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::BlockMsg>>(AsyncGetBlockRaw(context, request, cq));
    }
    ::grpc::Status GetHeartbeat(::grpc::ClientContext* context, const ::onevote::Empty& request, ::onevote::Empty* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::Empty>> AsyncGetHeartbeat(::grpc::ClientContext* context, const ::onevote::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::onevote::Empty>>(AsyncGetHeartbeatRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::onevote::Empty>* AsyncBroadcastBlockRaw(::grpc::ClientContext* context, const ::onevote::BlockMsg& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::onevote::Empty>* AsyncBroadcastTransactionRaw(::grpc::ClientContext* context, const ::onevote::TransactionMsg& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::onevote::AddrResponse>* AsyncGetAddrRaw(::grpc::ClientContext* context, const ::onevote::AddrRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::onevote::TransactionMsg>* AsyncGetTransactionRaw(::grpc::ClientContext* context, const ::onevote::TransactionRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::onevote::BlockMsg>* AsyncGetBlockRaw(::grpc::ClientContext* context, const ::onevote::BlockRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    ::grpc::ClientAsyncResponseReader< ::onevote::Empty>* AsyncGetHeartbeatRaw(::grpc::ClientContext* context, const ::onevote::Empty& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_BroadcastBlock_;
    const ::grpc::RpcMethod rpcmethod_BroadcastTransaction_;
    const ::grpc::RpcMethod rpcmethod_GetAddr_;
    const ::grpc::RpcMethod rpcmethod_GetTransaction_;
    const ::grpc::RpcMethod rpcmethod_GetBlock_;
    const ::grpc::RpcMethod rpcmethod_GetHeartbeat_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status BroadcastBlock(::grpc::ServerContext* context, const ::onevote::BlockMsg* request, ::onevote::Empty* response);
    virtual ::grpc::Status BroadcastTransaction(::grpc::ServerContext* context, const ::onevote::TransactionMsg* request, ::onevote::Empty* response);
    virtual ::grpc::Status GetAddr(::grpc::ServerContext* context, const ::onevote::AddrRequest* request, ::onevote::AddrResponse* response);
    virtual ::grpc::Status GetTransaction(::grpc::ServerContext* context, const ::onevote::TransactionRequest* request, ::onevote::TransactionMsg* response);
    virtual ::grpc::Status GetBlock(::grpc::ServerContext* context, const ::onevote::BlockRequest* request, ::onevote::BlockMsg* response);
    virtual ::grpc::Status GetHeartbeat(::grpc::ServerContext* context, const ::onevote::Empty* request, ::onevote::Empty* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_BroadcastBlock : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_BroadcastBlock() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_BroadcastBlock() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BroadcastBlock(::grpc::ServerContext* context, const ::onevote::BlockMsg* request, ::onevote::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBroadcastBlock(::grpc::ServerContext* context, ::onevote::BlockMsg* request, ::grpc::ServerAsyncResponseWriter< ::onevote::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_BroadcastTransaction : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_BroadcastTransaction() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_BroadcastTransaction() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BroadcastTransaction(::grpc::ServerContext* context, const ::onevote::TransactionMsg* request, ::onevote::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestBroadcastTransaction(::grpc::ServerContext* context, ::onevote::TransactionMsg* request, ::grpc::ServerAsyncResponseWriter< ::onevote::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetAddr : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetAddr() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_GetAddr() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetAddr(::grpc::ServerContext* context, const ::onevote::AddrRequest* request, ::onevote::AddrResponse* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetAddr(::grpc::ServerContext* context, ::onevote::AddrRequest* request, ::grpc::ServerAsyncResponseWriter< ::onevote::AddrResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetTransaction : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetTransaction() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_GetTransaction() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTransaction(::grpc::ServerContext* context, const ::onevote::TransactionRequest* request, ::onevote::TransactionMsg* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetTransaction(::grpc::ServerContext* context, ::onevote::TransactionRequest* request, ::grpc::ServerAsyncResponseWriter< ::onevote::TransactionMsg>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(3, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetBlock : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetBlock() {
      ::grpc::Service::MarkMethodAsync(4);
    }
    ~WithAsyncMethod_GetBlock() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetBlock(::grpc::ServerContext* context, const ::onevote::BlockRequest* request, ::onevote::BlockMsg* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetBlock(::grpc::ServerContext* context, ::onevote::BlockRequest* request, ::grpc::ServerAsyncResponseWriter< ::onevote::BlockMsg>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(4, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_GetHeartbeat : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_GetHeartbeat() {
      ::grpc::Service::MarkMethodAsync(5);
    }
    ~WithAsyncMethod_GetHeartbeat() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetHeartbeat(::grpc::ServerContext* context, const ::onevote::Empty* request, ::onevote::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetHeartbeat(::grpc::ServerContext* context, ::onevote::Empty* request, ::grpc::ServerAsyncResponseWriter< ::onevote::Empty>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(5, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_BroadcastBlock<WithAsyncMethod_BroadcastTransaction<WithAsyncMethod_GetAddr<WithAsyncMethod_GetTransaction<WithAsyncMethod_GetBlock<WithAsyncMethod_GetHeartbeat<Service > > > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_BroadcastBlock : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_BroadcastBlock() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_BroadcastBlock() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BroadcastBlock(::grpc::ServerContext* context, const ::onevote::BlockMsg* request, ::onevote::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_BroadcastTransaction : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_BroadcastTransaction() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_BroadcastTransaction() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status BroadcastTransaction(::grpc::ServerContext* context, const ::onevote::TransactionMsg* request, ::onevote::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetAddr : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetAddr() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_GetAddr() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetAddr(::grpc::ServerContext* context, const ::onevote::AddrRequest* request, ::onevote::AddrResponse* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetTransaction : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetTransaction() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_GetTransaction() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetTransaction(::grpc::ServerContext* context, const ::onevote::TransactionRequest* request, ::onevote::TransactionMsg* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetBlock : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetBlock() {
      ::grpc::Service::MarkMethodGeneric(4);
    }
    ~WithGenericMethod_GetBlock() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetBlock(::grpc::ServerContext* context, const ::onevote::BlockRequest* request, ::onevote::BlockMsg* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_GetHeartbeat : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_GetHeartbeat() {
      ::grpc::Service::MarkMethodGeneric(5);
    }
    ~WithGenericMethod_GetHeartbeat() GRPC_OVERRIDE {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetHeartbeat(::grpc::ServerContext* context, const ::onevote::Empty* request, ::onevote::Empty* response) GRPC_FINAL GRPC_OVERRIDE {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
};

}  // namespace onevote


#endif  // GRPC_node_2eproto__INCLUDED
