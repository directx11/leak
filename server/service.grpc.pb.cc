// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto

#include "service.pb.h"
#include "service.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* GrpcService_method_names[] = {
  "/GrpcService/GetStream",
};

std::unique_ptr< GrpcService::Stub> GrpcService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< GrpcService::Stub> stub(new GrpcService::Stub(channel, options));
  return stub;
}

GrpcService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetStream_(GrpcService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  {}

::grpc::ClientReader< ::Reply>* GrpcService::Stub::GetStreamRaw(::grpc::ClientContext* context, const ::Empty& request) {
  return ::grpc::internal::ClientReaderFactory< ::Reply>::Create(channel_.get(), rpcmethod_GetStream_, context, request);
}

void GrpcService::Stub::async::GetStream(::grpc::ClientContext* context, const ::Empty* request, ::grpc::ClientReadReactor< ::Reply>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::Reply>::Create(stub_->channel_.get(), stub_->rpcmethod_GetStream_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::Reply>* GrpcService::Stub::AsyncGetStreamRaw(::grpc::ClientContext* context, const ::Empty& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::Reply>::Create(channel_.get(), cq, rpcmethod_GetStream_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::Reply>* GrpcService::Stub::PrepareAsyncGetStreamRaw(::grpc::ClientContext* context, const ::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::Reply>::Create(channel_.get(), cq, rpcmethod_GetStream_, context, request, false, nullptr);
}

GrpcService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcService_method_names[0],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< GrpcService::Service, ::Empty, ::Reply>(
          [](GrpcService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Empty* req,
             ::grpc::ServerWriter<::Reply>* writer) {
               return service->GetStream(ctx, req, writer);
             }, this)));
}

GrpcService::Service::~Service() {
}

::grpc::Status GrpcService::Service::GetStream(::grpc::ServerContext* context, const ::Empty* request, ::grpc::ServerWriter< ::Reply>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

