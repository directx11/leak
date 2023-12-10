#include <iostream>
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
    std::cout << "Hello world!" << std::endl;
}