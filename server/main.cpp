#include <iostream>
#include <thread>

// #include "./ext/grpcpp/server_builder.h"
#include "./ext/grpc/include/grpc/grpc.h"
#include "./ext/grpc/include/grpc++/grpc++.h"
#include "./service.grpc.pb.h"

class CGrpcService : public GrpcService::CallbackService {
    grpc::ServerWriteReactor<Reply>* GetStream(
        grpc::CallbackServerContext* context, const Empty* request);
};

grpc::ServerWriteReactor<Reply>* CGrpcService::GetStream(
    grpc::CallbackServerContext* context, const Empty* request)
{
    class Lister : public grpc::ServerWriteReactor<Reply>
    {
        Reply response;

        public:
            Lister(const Empty* request)
            {
                NextWrite();
            }

            void OnWriteDone(bool ok) override
            {
                // std::this_thread::sleep_for(std::chrono::milliseconds(10));
                // std::cout << "next write..." << std::endl;
                NextWrite();
            }

            void OnCancel() override
            {
            }

            void OnDone() override
            {
            }

            void NextWrite()
            {
                StartWrite(&response);
            }
        };

    return new Lister(request);
}

int main()
{
    CGrpcService service;
    grpc::ServerBuilder builder;

    builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    server->Wait();
    std::cout << "waiting for flutter RPC call..." << std::endl;
}
